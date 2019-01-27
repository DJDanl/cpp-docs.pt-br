---
title: 'Passo a passo: Criar um aplicativo tradicional de área de trabalho do Windows (C++)'
ms.custom: get-started-article
ms.date: 09/18/2018
helpviewer_keywords:
- Windows applications [C++], Win32
- Windows Desktop applications [C++]
- Windows API [C++]
ms.openlocfilehash: 07da91ea092b4e7bee974b0387e72ea0cacaec8e
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54893893"
---
# <a name="walkthrough-create-a-traditional-windows-desktop-application-c"></a>Passo a passo: Criar um aplicativo tradicional de área de trabalho do Windows (C++)

Este passo a passo mostra como criar um aplicativo de área de trabalho tradicional do Windows no Visual Studio. O aplicativo de exemplo, você criará usa a API do Windows para exibir "Hello, área de trabalho do Windows!" em uma janela. Você pode usar o código que você desenvolve neste passo a passo como um padrão para criar outros aplicativos da área de trabalho do Windows.

A API do Windows (também conhecido como a API do Win32, API de área de trabalho do Windows e API clássica do Windows) é uma estrutura com base em linguagem C para a criação de aplicativos do Windows. Ele já existe desde a década de 1980 e foi usado para criar aplicativos do Windows há décadas. Mais estruturas avançadas e mais fácil para programa foram criadas sobre a API do Windows, como MFC, ATL e os .NET frameworks. Até mesmo os mais moderno código para aplicativos UWP e Store escrito em C + + c++ /CLI WinRT usa a API do Windows abaixo. Para obter mais informações sobre a API do Windows, consulte [índice de API do Windows](/windows/desktop/apiindex/windows-api-list). Há muitas maneiras de criar aplicativos do Windows, mas o processo acima foi a primeira.

> [!IMPORTANT]
> Por questão de brevidade, algumas instruções de código são omitidas no texto. O [compilar o código](#build-the-code) seção no final deste documento mostra o código completo.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para uma melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio 2017. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio). Ao executar o instalador, certifique-se de que o **desenvolvimento para Desktop com C++** carga de trabalho está marcada. Não se preocupe se você não instalou essa carga de trabalho quando você instalou o Visual Studio. Você pode executar o instalador novamente e instale-o agora.

   ![Desenvolvimento para desktop com C++](../build/media/desktop-development-with-cpp.png "desenvolvimento para Desktop com C++")

- Um entendimento dos fundamentos de como usar o IDE do Visual Studio. Se você já usou os aplicativos da área de trabalho do Windows antes, você provavelmente pode manter-se. Para obter uma introdução, consulte [tour pelos recursos do IDE do Visual Studio](/visualstudio/ide/visual-studio-ide).

- Uma compreensão de suficiente dos fundamentos da linguagem C++ acompanhá-los. Não se preocupe, não fazemos nada muito complicado.

## <a name="create-a-windows-desktop-project"></a>Crie um projeto para desktops Windows

Siga estas etapas para criar seu primeiro projeto da área de trabalho do Windows e insira o código para um aplicativo de área de trabalho do Windows em funcionamento. Se você estiver usando uma versão do Visual Studio mais antigo que o Visual Studio 2017 versão 15.3, pule para [para criar um projeto de área de trabalho do Windows no Visual Studio 2017 RTM](#create-in-vs2017-rtm).

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2017-update-153-and-later"></a>Para criar um projeto da área de trabalho do Windows no Visual Studio 2017 atualização 15.3 e posterior

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, expanda **instalado** > **Visual C++**, em seguida, selecione **área de trabalho do Windows**. No painel central, selecione **Assistente de área de trabalho do Windows**.

   No **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-153.png "Nomeie o projeto DesktopApp")

1. No **projeto de área de trabalho do Windows** caixa de diálogo, em **tipo de aplicativo**, selecione **aplicativo Windows (.exe)**. Sob **opções adicionais**, selecione **projeto vazio**. Escolher **Okey** para criar o projeto.

   ![Criar DesktopApp no Assistente de projeto da área de trabalho do Windows](../build/media/desktop-app-new-project-wizard-153.png "criar DesktopApp no Assistente de projeto para desktops Windows")

1. No **Gerenciador de soluções**, com o botão direito do **DesktopApp** do projeto, escolha **Add**e, em seguida, escolha **Novo Item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "adicionar novo item ao projeto DesktopApp")

1. No **Adicionar Novo Item** caixa de diálogo, selecione **arquivo do C++ (. cpp)**. No **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp ao projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo. cpp ao projeto DesktopApp")

Seu projeto foi criado e seu arquivo de origem é aberto no editor. Para continuar, pule para [criar o código](#create-the-code).

### <a id="create-in-vs2017-rtm"></a> Para criar um projeto de área de trabalho do Windows no Visual Studio 2017 RTM

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, expanda **instalado** > **modelos** > **Visual C++** e, em seguida, selecione **Win32**. No painel central, selecione **projeto Win32**.

   No **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-150.png "Nomeie o projeto DesktopApp")

1. No **visão geral** página do **Assistente de aplicativo Win32**, escolha **próxima**.

   ![Criar DesktopApp na visão geral do Assistente de aplicativo Win32](../build/media/desktop-app-win32-wizard-overview-150.png "criar DesktopApp na visão geral do Assistente de aplicativo Win32")

1. Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo do Windows**. Sob **opções adicionais**, selecione **projeto vazio**. Escolher **concluir** para criar o projeto.

   ![Criar DesktopApp nas configurações do Assistente de aplicativo Win32](../build/media/desktop-app-win32-wizard-settings-150.png "criar DesktopApp nas configurações do Assistente de aplicativo Win32")

1. Na **Gerenciador de soluções**, clique com botão direito no projeto DesktopApp, escolha **Add**e, em seguida, escolha **Novo Item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-150.gif "adicionar novo item ao projeto DesktopApp")

1. No **Adicionar Novo Item** caixa de diálogo, selecione **arquivo do C++ (. cpp)**. No **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp ao projeto DesktopApp](../build/media/desktop-app-add-cpp-file-150.png "Adicionar arquivo. cpp ao projeto DesktopApp")

Seu projeto foi criado e seu arquivo de origem é aberto no editor.

## <a name="create-the-code"></a>Criar o código

Em seguida, você aprenderá a criar o código para um aplicativo de desktop do Windows no Visual Studio.

### <a name="to-start-a-windows-desktop-application"></a>Para iniciar um aplicativo de desktop do Windows

1. Assim como cada C do aplicativo e aplicativo C++ devem ter uma `main` funcionar como ponto de partida, cada Windows aplicativo da área de trabalho deve ter um `WinMain` função. `WinMain` tem a seguinte sintaxe.

   ```cpp
   int CALLBACK WinMain(
      _In_ HINSTANCE hInstance,
      _In_ HINSTANCE hPrevInstance,
      _In_ LPSTR     lpCmdLine,
      _In_ int       nCmdShow
   );
   ```

   Para obter informações sobre os parâmetros e o valor de retorno dessa função, consulte [ponto de entrada WinMain](/windows/desktop/api/winbase/nf-winbase-winmain).

   > [!NOTE]
   > Quais são todas essas palavras extras, como `CALLBACK`, ou `HINSTANCE`, ou `_In_`? A API do Windows tradicional usa typedefs e macros de pré-processador extensivamente para abstrair alguns dos detalhes de tipos e específicos da plataforma código, como convenções de chamada, **declspec** declarações e pragmas do compilador. No Visual Studio, você pode usar o IntelliSense [informações rápidas](/visualstudio/ide/using-intellisense#quick-info) recurso para ver o que definem essas typedefs e macros. Passe o mouse sobre a palavra de interesse, ou selecione-o e pressione **Ctrl**+**K**, **Ctrl**+**eu** para um pequena janela pop-up que contém a definição. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense). Geralmente usam parâmetros e tipos de retorno *anotações de SAL* para ajudá-lo catch erros de programação. Para obter mais informações, consulte [usando as anotações de SAL para reduzir defeitos de código C/C++](/visualstudio/code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects).

1. Programas de desktop do Windows exigem &lt;Windows. h >. &lt;TCHAR. h > define a `TCHAR` macro, que é resolvida, por fim, para **wchar_t** se o símbolo UNICODE é definido em seu projeto, caso contrário, ele resolve para **char**.  Se você compilar sempre com habilitado para UNICODE, você não precisa TCHAR e podem usar apenas **wchar_t** diretamente.

   ```cpp
   #include <windows.h>
   #include <tchar.h>
   ```

1. Além de `WinMain` função, todos os aplicativos de área de trabalho do Windows também devem ter uma função de procedimento de janela. Essa função é tipicamente nomeada `WndProc` , mas você pode chamá-lo que você quiser. `WndProc` tem a seguinte sintaxe.

   ```cpp
   LRESULT CALLBACK WndProc(
      _In_ HWND   hwnd,
      _In_ UINT   uMsg,
      _In_ WPARAM wParam,
      _In_ LPARAM lParam
   );
   ```

   Nessa função, você pode escrever código para manipular *mensagens* que o aplicativo recebe do Windows quando *eventos* ocorrer. Por exemplo, se um usuário escolhe um botão Okey em seu aplicativo, Windows enviará uma mensagem para você e você pode escrever código dentro de seu `WndProc` função que faz qualquer trabalho que seja apropriado. Ele é chamado *tratamento* um evento. Você só manipulam os eventos que são relevantes para seu aplicativo.

   Para obter mais informações, consulte [procedimentos de janela](/windows/desktop/winmsg/window-procedures).

### <a name="to-add-functionality-to-the-winmain-function"></a>Para adicionar funcionalidade à função WinMain

1. No `WinMain` função, você preencher uma estrutura do tipo [WNDCLASSEX](/windows/desktop/api/winuser/ns-winuser-tagwndclassexa). A estrutura contém informações sobre a janela, por exemplo, o ícone do aplicativo, a cor do plano de fundo da janela, o nome a ser exibido na barra de título e importante, um ponteiro de função para seu procedimento de janela. O exemplo a seguir mostra um típico `WNDCLASSEX` estrutura.

   ```cpp
   WNDCLASSEX wcex;

   wcex.cbSize         = sizeof(WNDCLASSEX);
   wcex.style          = CS_HREDRAW | CS_VREDRAW;
   wcex.lpfnWndProc    = WndProc;
   wcex.cbClsExtra     = 0;
   wcex.cbWndExtra     = 0;
   wcex.hInstance      = hInstance;
   wcex.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
   wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
   wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
   wcex.lpszMenuName   = NULL;
   wcex.lpszClassName  = szWindowClass;
   wcex.hIconSm        = LoadIcon(wcex.hInstance, IDI_APPLICATION);
   ```

   Para obter informações sobre os campos da estrutura acima, consulte [WNDCLASSEX](/windows/desktop/api/winuser/ns-winuser-tagwndclassexa).

1. Registrar o `WNDCLASSEX` com Windows para que ele saiba sobre sua janela e como enviar mensagens para ela. Use o [RegisterClassEx](/windows/desktop/api/winuser/nf-winuser-registerclassexa) de função e passar a estrutura de classe de janela como um argumento. O `_T` macro é usada como usamos o `TCHAR` tipo.

   ```cpp
   if (!RegisterClassEx(&wcex))
   {
      MessageBox(NULL,
         _T("Call to RegisterClassEx failed!"),
         _T("Windows Desktop Guided Tour"),
         NULL);

      return 1;
   }
   ```

1. Agora você pode criar uma janela. Use o [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) função.

   ```cpp
   static TCHAR szWindowClass[] = _T("DesktopApp");
   static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

   // The parameters to CreateWindow explained:
   // szWindowClass: the name of the application
   // szTitle: the text that appears in the title bar
   // WS_OVERLAPPEDWINDOW: the type of window to create
   // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
   // 500, 100: initial size (width, length)
   // NULL: the parent of this window
   // NULL: this application does not have a menu bar
   // hInstance: the first parameter from WinMain
   // NULL: not used in this application
   HWND hWnd = CreateWindow(
      szWindowClass,
      szTitle,
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT,
      500, 100,
      NULL,
      NULL,
      hInstance,
      NULL
   );
   if (!hWnd)
   {
      MessageBox(NULL,
         _T("Call to CreateWindow failed!"),
         _T("Windows Desktop Guided Tour"),
         NULL);

      return 1;
   }
   ```

   Essa função retorna um `HWND`, que é um identificador para uma janela. Um identificador é um pouco como um ponteiro que o Windows usa para controlar as janelas abertas. Para obter mais informações, consulte [tipos de dados do Windows](/windows/desktop/WinProg/windows-data-types).

1. Neste ponto, a janela foi criada, mas ainda assim será preciso informar ao Windows para torná-la visível. É o que esse código faz:

   ```cpp
   // The parameters to ShowWindow explained:
   // hWnd: the value returned from CreateWindow
   // nCmdShow: the fourth parameter from WinMain
   ShowWindow(hWnd,
      nCmdShow);
   UpdateWindow(hWnd);
   ```

   A janela exibida não tem muito conteúdo porque você ainda não tiver implementado o `WndProc` função. Em outras palavras, o aplicativo ainda não está manipulando as mensagens que o Windows agora está enviando para ele.

1. Para lidar com as mensagens, primeiro adicionamos um loop de mensagem para escutar as mensagens que o Windows envia. Quando o aplicativo recebe uma mensagem, este loop a envia para seu `WndProc` função a ser manipulado. O loop de mensagem se parece com o código a seguir.

   ```cpp
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
   ```

   Para obter mais informações sobre as estruturas e funções no loop de mensagem, consulte [MSG](/windows/desktop/api/winuser/ns-winuser-msg), [GetMessage](/windows/desktop/api/winuser/nf-winuser-getmessage), [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage), e [DispatchMessage ](/windows/desktop/api/winuser/nf-winuser-dispatchmessage).

   Neste ponto, o `WinMain` função deve se parecer com o código a seguir.

   ```cpp
   int WINAPI WinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR lpCmdLine,
                      int nCmdShow)
   {
      WNDCLASSEX wcex;

      wcex.cbSize = sizeof(WNDCLASSEX);
      wcex.style          = CS_HREDRAW | CS_VREDRAW;
      wcex.lpfnWndProc    = WndProc;
      wcex.cbClsExtra     = 0;
      wcex.cbWndExtra     = 0;
      wcex.hInstance      = hInstance;
      wcex.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
      wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
      wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
      wcex.lpszMenuName   = NULL;
      wcex.lpszClassName  = szWindowClass;
      wcex.hIconSm        = LoadIcon(wcex.hInstance, IDI_APPLICATION);

      if (!RegisterClassEx(&wcex))
      {
         MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

         return 1;
      }

      // Store instance handle in our global variable
      hInst = hInstance;

      // The parameters to CreateWindow explained:
      // szWindowClass: the name of the application
      // szTitle: the text that appears in the title bar
      // WS_OVERLAPPEDWINDOW: the type of window to create
      // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
      // 500, 100: initial size (width, length)
      // NULL: the parent of this window
      // NULL: this application dows not have a menu bar
      // hInstance: the first parameter from WinMain
      // NULL: not used in this application
      HWND hWnd = CreateWindow(
         szWindowClass,
         szTitle,
         WS_OVERLAPPEDWINDOW,
         CW_USEDEFAULT, CW_USEDEFAULT,
         500, 100,
         NULL,
         NULL,
         hInstance,
         NULL
      );

      if (!hWnd)
      {
         MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

         return 1;
      }

      // The parameters to ShowWindow explained:
      // hWnd: the value returned from CreateWindow
      // nCmdShow: the fourth parameter from WinMain
      ShowWindow(hWnd,
         nCmdShow);
      UpdateWindow(hWnd);

      // Main message loop:
      MSG msg;
      while (GetMessage(&msg, NULL, 0, 0))
      {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
      }

      return (int) msg.wParam;
   }
   ```

### <a name="to-add-functionality-to-the-wndproc-function"></a>Para adicionar funcionalidade à função WndProc

1. Para habilitar o `WndProc` função para manipular as mensagens que o aplicativo recebe, implemente uma instrução switch.

   É uma mensagem importante para lidar com o [WM_PAINT](/windows/desktop/gdi/wm-paint) mensagem. O aplicativo recebe o `WM_PAINT` mensagem quando parte de sua janela exibida deve ser atualizada. O evento pode ocorrer quando um usuário move uma janela na frente de sua janela, em seguida, se ele afasta novamente e seu aplicativo não sabe quando esses eventos ocorrerem. Somente Windows sabe, para que ele o notificará com `WM_PAINT`. Quando a janela é exibida pela primeira vez, tudo isso deve ser atualizado.

   Para lidar com uma `WM_PAINT` da mensagem, primeira chamada [BeginPaint](/windows/desktop/api/winuser/nf-winuser-beginpaint), em seguida, lidar com toda a lógica para dispor o texto, botões e outros controles na janela e, em seguida, chamar [EndPaint](/windows/desktop/api/winuser/nf-winuser-endpaint). Para o aplicativo, a lógica entre a chamada inicial e a chamada final é exibir a cadeia de caracteres "Olá, área de trabalho do Windows!" Na janela. No código a seguir, observe que o [TextOut](/windows/desktop/api/wingdi/nf-wingdi-textouta) função é usada para exibir a cadeia de caracteres.

   ```cpp
   PAINTSTRUCT ps;
   HDC hdc;
   TCHAR greeting[] = _T("Hello, Windows desktop!");

   switch (message)
   {
   case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);

      // Here your application is laid out.
      // For this introduction, we just print out "Hello, Windows desktop!"
      // in the top left corner.
      TextOut(hdc,
         5, 5,
         greeting, _tcslen(greeting));
      // End application-specific layout section.

      EndPaint(hWnd, &ps);
      break;
   }
   ```

   `HDC` no código é um identificador para um contexto de dispositivo, que é uma estrutura de dados que usa o Windows para permitir que seu aplicativo para se comunicar com o subsistema de gráficos. O `BeginPaint` e `EndPaint` funções tornar seu aplicativo se comportam como um bom cidadão e não usa o contexto de dispositivo por mais tempo do que o necessário. As funções Ajude a tornar o subsistema de gráficos está disponível para uso por outros aplicativos.

1. Um aplicativo normalmente trata muitas outras mensagens, por exemplo, [WM_CREATE](/windows/desktop/winmsg/wm-create) quando uma janela é criada, e [WM_DESTROY](/windows/desktop/winmsg/wm-destroy) quando a janela é fechada. O código a seguir mostra um arquivo mas concluir `WndProc` função.

   ```cpp
   LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
   {
      PAINTSTRUCT ps;
      HDC hdc;
      TCHAR greeting[] = _T("Hello, Windows desktop!");

      switch (message)
      {
      case WM_PAINT:
         hdc = BeginPaint(hWnd, &ps);

         // Here your application is laid out.
         // For this introduction, we just print out "Hello, Windows desktop!"
         // in the top left corner.
         TextOut(hdc,
            5, 5,
            greeting, _tcslen(greeting));
         // End application specific layout section.

         EndPaint(hWnd, &ps);
         break;
      case WM_DESTROY:
         PostQuitMessage(0);
         break;
      default:
         return DefWindowProc(hWnd, message, wParam, lParam);
         break;
      }

      return 0;
   }
   ```

## <a name="build-the-code"></a>Compilar o código

Como prometido, aqui está o código completo para o aplicativo em funcionamento.

### <a name="to-build-this-example"></a>Para compilar este exemplo

1. Exclua qualquer código que você digitou em *HelloWindowsDesktop.cpp* no editor. Copie este código de exemplo e, em seguida, cole-o na *HelloWindowsDesktop.cpp*:

   ```cpp
   // HelloWindowsDesktop.cpp
   // compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

   #include <windows.h>
   #include <stdlib.h>
   #include <string.h>
   #include <tchar.h>

   // Global variables

   // The main window class name.
   static TCHAR szWindowClass[] = _T("DesktopApp");

   // The string that appears in the application's title bar.
   static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

   HINSTANCE hInst;

   // Forward declarations of functions included in this code module:
   LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

   int CALLBACK WinMain(
      _In_ HINSTANCE hInstance,
      _In_ HINSTANCE hPrevInstance,
      _In_ LPSTR     lpCmdLine,
      _In_ int       nCmdShow
   )
   {
      WNDCLASSEX wcex;

      wcex.cbSize = sizeof(WNDCLASSEX);
      wcex.style          = CS_HREDRAW | CS_VREDRAW;
      wcex.lpfnWndProc    = WndProc;
      wcex.cbClsExtra     = 0;
      wcex.cbWndExtra     = 0;
      wcex.hInstance      = hInstance;
      wcex.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
      wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
      wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
      wcex.lpszMenuName   = NULL;
      wcex.lpszClassName  = szWindowClass;
      wcex.hIconSm        = LoadIcon(wcex.hInstance, IDI_APPLICATION);

      if (!RegisterClassEx(&wcex))
      {
         MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

         return 1;
      }

      // Store instance handle in our global variable
      hInst = hInstance;

      // The parameters to CreateWindow explained:
      // szWindowClass: the name of the application
      // szTitle: the text that appears in the title bar
      // WS_OVERLAPPEDWINDOW: the type of window to create
      // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
      // 500, 100: initial size (width, length)
      // NULL: the parent of this window
      // NULL: this application does not have a menu bar
      // hInstance: the first parameter from WinMain
      // NULL: not used in this application
      HWND hWnd = CreateWindow(
         szWindowClass,
         szTitle,
         WS_OVERLAPPEDWINDOW,
         CW_USEDEFAULT, CW_USEDEFAULT,
         500, 100,
         NULL,
         NULL,
         hInstance,
         NULL
      );

      if (!hWnd)
      {
         MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

         return 1;
      }

      // The parameters to ShowWindow explained:
      // hWnd: the value returned from CreateWindow
      // nCmdShow: the fourth parameter from WinMain
      ShowWindow(hWnd,
         nCmdShow);
      UpdateWindow(hWnd);

      // Main message loop:
      MSG msg;
      while (GetMessage(&msg, NULL, 0, 0))
      {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
      }

      return (int) msg.wParam;
   }

   //  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
   //
   //  PURPOSE:  Processes messages for the main window.
   //
   //  WM_PAINT    - Paint the main window
   //  WM_DESTROY  - post a quit message and return
   LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
   {
      PAINTSTRUCT ps;
      HDC hdc;
      TCHAR greeting[] = _T("Hello, Windows desktop!");

      switch (message)
      {
      case WM_PAINT:
         hdc = BeginPaint(hWnd, &ps);

         // Here your application is laid out.
         // For this introduction, we just print out "Hello, Windows desktop!"
         // in the top left corner.
         TextOut(hdc,
            5, 5,
            greeting, _tcslen(greeting));
         // End application-specific layout section.

         EndPaint(hWnd, &ps);
         break;
      case WM_DESTROY:
         PostQuitMessage(0);
         break;
      default:
         return DefWindowProc(hWnd, message, wParam, lParam);
         break;
      }

      return 0;
   }
   ```

1. No menu **Compilar**, escolha **Compilar Solução**. Os resultados da compilação devem aparecer na **saída** janela no Visual Studio.

   ![Compile o projeto DesktopApp](../build/media/desktop-app-project-build-150.gif "compilar o projeto DesktopApp")

1. Para executar o aplicativo, pressione **F5**. Uma janela que contém o texto "Olá, área de trabalho do Windows!" deve aparecer no canto superior esquerdo da tela.

   ![Execute o projeto DesktopApp](../build/media/desktop-app-project-run-157.png "executar o projeto DesktopApp")

Parabéns! Concluir este passo a passo e criado um aplicativo de área de trabalho tradicional do Windows.

## <a name="see-also"></a>Consulte também

[Aplicativos de área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md)