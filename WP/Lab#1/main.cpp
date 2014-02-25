#include <windows.h>
#include <tchar.h>
#include <cstdlib>

/*Identifiers for each button*/
#define QUIT_BTN                100
#define BUTTON_ADD_FOOD         101
#define BUTTON_ADD_FOOD         102
#define BUTTON_DISPLAY_FOOD_NR  103
#define INPUT_TEXT_SHOW_FOOD    104
#define INPUT_TEXT_SHOW_FOOD_2  105
#define INPUT_TEXT_ADD_FOOD     106
#define INPUT_TEXT_ADD_FOOD_2   107
#define BUTTON                  108
#define ID_BUTTON0              109

/*Handler variable and variable declarations*/
HWND hInputFood;
HWND hInputFood2;
HWND hFoodList;
HWND button0;

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";
HWND label1;
HINSTANCE g_hInst;
HINSTANCE hInst;

int foodNumber = 0;
char food[500] = "";
char firstText[] = "Food List: ";

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;                        /* This function is called by windows */
    wincl.style = CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;         /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                                   /* No menu */
    wincl.cbClsExtra = 0;                                        /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                                        /* structure or the window instance */

    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                                           /* Extended possibilites for variation */
           szClassName,                                 /* Classname */
           "Cristian Cartofeanu 2014(c)",         /* Title Text */
           WS_OVERLAPPEDWINDOW,                         /* default window */
           CW_USEDEFAULT,                               /* Windows decides the position */
           CW_USEDEFAULT,                               /* where the window ends up on the screen */
           1200,                                        /* The programs width */
           800,                                         /* and height in pixels */
           HWND_DESKTOP,                                /* The window is a child-window to desktop */
           NULL,                                        /* No menu */
           hThisInstance,                               /* Program Instance handler */
           NULL                                         /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    /* Rect structure, used for WM_PAINT message */
    RECT rc;

    switch (message)                       /* handle the messages */
    {
        case WM_DESTROY:
            {
                PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
                break;
            }

        case WM_GETMINMAXINFO:
            {
                SIZE sz;
                HDC hdc = GetDC( hwnd );

                ((MINMAXINFO*)lParam)->ptMinTrackSize.x = 535;
                ((MINMAXINFO*)lParam)->ptMinTrackSize.y = 340;

                //cleanup
                ReleaseDC( hwnd, hdc );
                break;
            }

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint (hwnd, &ps);
                GetClientRect(hwnd, &rc);
                SetBkMode(hdc, TRANSPARENT);
                SetTextColor(hdc, RGB(121, 87.55, 17.14));
                DrawText (hdc, TEXT("Done with Pride and Prejudice by Cartofeanu Cristian!"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_WORDBREAK ) ;
                EndPaint (hwnd, &ps);
                break;
            }

        case WM_CREATE:
            {

                HFONT hFont = CreateFont(30,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,NULL, VARIABLE_PITCH,TEXT("Impact"));

                HWND hButtonAddFood = CreateWindowEx(NULL,
                "BUTTON",
                "Order",
                WS_TABSTOP|WS_VISIBLE|
                WS_CHILD|BS_DEFPUSHBUTTON|BS_TOP,
                10,
                200,
                100,
                25,
                hwnd,
                (HMENU)BUTTON_ADD_FOOD,
                GetModuleHandle(NULL),
                NULL);

                hFoodList = CreateWindowEx(WS_EX_CLIENTEDGE,
                "EDIT",
                "",
                WS_CHILD|WS_VISIBLE|WS_VSCROLL|ES_READONLY|
                ES_MULTILINE,
                10,
                40,
                300,
                100,
                hwnd,
                (HMENU)INPUT_TEXT_SHOW_FOOD ,
                GetModuleHandle(NULL),
                NULL);

                hInputFood = CreateWindowEx(
                (DWORD)NULL,
                TEXT("edit"),
                "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                120,
                200,
                190,
                25,
                hwnd,
                (HMENU)INPUT_TEXT_ADD_FOOD,
                GetModuleHandle(NULL),
                NULL);

                hInputFood2 = CreateWindowEx(
                (DWORD)NULL,
                TEXT("edit"),
                "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                120,
                229,
                190,
                25,
                hwnd,
                (HMENU)INPUT_TEXT_ADD_FOOD_2,
                GetModuleHandle(NULL),
                NULL);

                CreateWindow(TEXT("BUTTON"),
                TEXT("Our Slogan"),
                WS_VISIBLE | WS_CHILD,
                320,
                0,
                200,
                30,
                hwnd, (HMENU) BUTTON,
                NULL, NULL);

                CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Quit"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_OWNERDRAW,
                130, 260, 180, 30,
                hwnd,
                (HMENU)QUIT_BTN,
                NULL,
                NULL);
                button0  = CreateWindow("Button","Generate Food",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE ,329,75,100,50,hwnd,(HMENU)ID_BUTTON0,g_hInst,0);
                label1 = CreateWindow("Static", "Click the button -->",
                WS_CHILD | WS_VISIBLE ,0,0,300,18,hwnd,0, g_hInst,0);
                break;

            }

        case WM_COMMAND:
            {
                switch(LOWORD(wParam))
                {
                    case BUTTON_ADD_FOOD:
                        {
                            char buffer2[256];
                            char buffer[256];
                            SendMessage(hInputFood,
                            WM_GETTEXT,
                            sizeof(buffer)/sizeof(buffer[0]),
                            reinterpret_cast<LPARAM>(buffer));
                            SendMessage(hInputFood2,
                            WM_GETTEXT,
                            sizeof(buffer2)/sizeof(buffer2[0]),
                            reinterpret_cast<LPARAM>(buffer2));

                            if(strlen(buffer) > 0)
                            {
                                char newInput[255] = "";
                                char stat[30];
                                char newInput2[255] = "";
                                char stat2[30];
                                strcat(newInput, itoa((foodNumber+1), stat, 10) );
                                strcat(newInput, " ) ");
                                strcat(newInput, buffer);
                                strcat(newInput, "\r\n");

                                strcat(newInput2, itoa((foodNumber+2), stat2, 10) );
                                strcat(newInput2, " ) ");
                                strcat(newInput2, buffer2);
                                strcat(newInput2, "\r\n");

                                SendMessage(hFoodList, EM_REPLACESEL, FALSE, (LPARAM)newInput);
                                SendMessage(hFoodList, EM_REPLACESEL, FALSE, (LPARAM)newInput2);
                                SendMessage(hInputFood, WM_SETTEXT, NULL, (LPARAM)"");
                                SendMessage(hInputFood2, WM_SETTEXT, NULL, (LPARAM)"");
                                foodNumber++;
                                InvalidateRect(hwnd, &rc, TRUE);
                            }
                            break;
                        }

                    case BUTTON:
                        {
                            int var = rand() % 8;
                            switch(var)
                            {
                                case 0:
                                    {SetWindowText(label1, "Soon, you'll have great success!");}break;
                                case 1:
                                    {SetWindowText(label1, "Tomorrow you'll be happy!");}break;
                                case 2:
                                    {SetWindowText(label1, "Don't give up!");}break;
                                case 3:
                                    {SetWindowText(label1, "Just do it!");}break;
                                case 4:
                                    {SetWindowText(label1, "Impossible is nothing!");}break;
                                case 5:
                                    {SetWindowText(label1, "Practice makes perfect!");}break;
                                case 6:
                                    {SetWindowText(label1, "Never say never!");}break;
                                case 7:
                                    {SetWindowText(label1, "What doesn't kill us, makes us stronger!");}break;
                            }
                        break;
                        }

                    case ID_BUTTON0: {
                    int iter;
                    iter = (rand() % 4 + 1);
                    switch(iter) {

                        case 1: {
                        SetWindowText(hInputFood, "Philli Steak");
						SetWindowText(hInputFood2,"Bacon Cheese Fries");
						break;

                        }

                        case 2: {
                        SetWindowText(hInputFood, "Bacon Cheddar Double ");
						SetWindowText(hInputFood2,"Fried Pickles");
						break;
                            }

                        case 3:{
                        SetWindowText(hInputFood, "Chicken Tenders");
						SetWindowText(hInputFood2,"Smokehouse Double");
						break;
                            }

                        case 4: {
                        SetWindowText(hInputFood, "Onion Rings");
						SetWindowText(hInputFood2,"Mister Pibb");
						break;
                            }

                        }

                        break;
                        }
                        case QUIT_BTN: {

                    if (MessageBox(NULL, TEXT("Are you sure you want to exit?"), TEXT("Exit?"),
                    MB_YESNO | MB_DEFBUTTON2 | MB_ICONWARNING) == IDYES) {

                    SendMessage(hwnd, WM_DESTROY, 0, 0);
                    };

                break;
                }
            }
        }

        case WM_CTLCOLOREDIT:
            {
                HDC hdc = (HDC)wParam;
                HWND hwnd = (HWND)lParam;
                HBRUSH color;

                if (GetDlgCtrlID(hwnd) == INPUT_TEXT_ADD_FOOD)
                {
                    color = CreateSolidBrush(RGB(192.8, 17.520, 225));
                    SetTextColor(hdc, RGB(0, 0, 255));
                    SetBkMode(hdc, TRANSPARENT);
                    SetBkColor(hdc,(LONG)color);
                }

                return (LONG) color;

                break;
            }

        case WM_DRAWITEM:
            {
                if ((UINT)wParam == QUIT_BTN)
                {
                    LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT*)lParam;
                    SIZE size;
                    char szQuitBtnText[20];

                    strcpy(szQuitBtnText, "Have a nice day!");
                    GetTextExtentPoint32(lpdis->hDC, szQuitBtnText, strlen(szQuitBtnText), &size);
                    SetTextColor(lpdis->hDC, RGB(250, 250, 250));
                    SetBkColor(lpdis->hDC, RGB(100, 78.4, 16.9));

                    ExtTextOut(
                        lpdis->hDC,
                        ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,
                        ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,
                        ETO_OPAQUE | ETO_CLIPPED,
                        &lpdis->rcItem,
                        szQuitBtnText,
                        strlen(szQuitBtnText),
                        NULL);

                    DrawEdge(
                        lpdis->hDC,
                        &lpdis->rcItem,
                        (lpdis->itemState & ODS_SELECTED ? EDGE_RAISED : EDGE_SUNKEN ),
                        BF_RECT);
                    return TRUE;
                }

            break;
            }

        case WM_CLOSE:
            {
                  int dummy;
                  dummy = (rand() % 4 + 1);

                  switch(dummy)
                  {
                        case 1:
                            {
                              SetWindowPos(hwnd,HWND_TOP,0,0,200,700,SWP_SHOWWINDOW);

                            break;
                            }

                        case 2:
                            {
                              SetWindowPos(hwnd,HWND_TOP,50,80,400,700,SWP_SHOWWINDOW);

                            break;
                            }

                        case 3:
                            {
                              SetWindowPos(hwnd,HWND_TOP,40,259,600,700,SWP_SHOWWINDOW);

                            break;
                            }

                        case 4:
                            {
                              SetWindowPos(hwnd,HWND_TOP,310,425,800,700,SWP_SHOWWINDOW);

                            break;
                            }
                  }

                break;
            }

        case WM_SYSCOMMAND:
            {
                 switch(wParam)
                 {
                    case SC_MINIMIZE:
                        {
                          DestroyWindow(hwnd);
                        break;
                        }

                    case SC_MAXIMIZE:
                        {
                          MessageBox(hwnd,TEXT("To confirm press OK!"),szClassName,MB_ICONWARNING);
                        break;
                        }

                    default: DefWindowProc (hwnd, message, wParam, lParam);
                 }




            }

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
