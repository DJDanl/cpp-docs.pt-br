---
title: 'Passo a passo: Criar um aplicativo de área de trabalhoC++do Windows tradicional ()'
ms.custom: get-started-article
ms.date: 04/23/2019
helpviewer_keywords:
- Windows applications [C++], Win32
- Windows Desktop applications [C++]
- Windows API [C++]
ms.openlocfilehash: 8bc2a42c5a9006065e2f0f4ecb70911e0055823e
ms.sourcegitcommit: bf724dfc639b16d5410fab72183f8e6b781338bc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2019
ms.locfileid: "71062067"
---
# <a name="walkthrough-create-a-traditional-windows-desktop-application-c"></a>Passo a passo: Criar um aplicativo de área de trabalhoC++do Windows tradicional ()

Este tutorial mostra como criar um aplicativo de área de trabalho tradicional do Windows no Visual Studio. O aplicativo de exemplo que você criará usa a API do Windows para exibir "Olá, Windows Desktop!" em uma janela. Você pode usar o código que você desenvolve neste passo a passos como um padrão para criar outros aplicativos da área de trabalho do Windows.

A API do Windows (também conhecida como API do Win32, API de área de trabalho do Windows e Windows API Clássica) é uma estrutura baseada em linguagem C para a criação de aplicativos do Windows. Ele já existe desde o 80 e foi usado para criar aplicativos do Windows há décadas. Estruturas mais avançadas e mais fáceis de programa foram criadas com base na API do Windows, como MFC, ATL e .NET Frameworks. Até mesmo o código mais moderno para os aplicativos UWP e Store C++escritos em/WinRT usa a API do Windows abaixo. Para obter mais informações sobre a API do Windows, consulte [índice da API do Windows](/windows/win32/apiindex/windows-api-list). Há várias maneiras de criar aplicativos do Windows, mas o processo acima foi o primeiro.

> [!IMPORTANT]
> Para fins de brevidade, algumas instruções de código são omitidas no texto. A seção [criar o código](#build-the-code) no final deste documento mostra o código completo.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para obter a melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio. Para saber mais sobre como fazer o download e instalar o Visual Studio, consulte [Instalar o Visual Studio](/visualstudio/install/install-visual-studio). Quando executar o instalador, certifique-se de que a carga de trabalho de **Desenvolvimento para desktop com C++** esteja marcada. Não se preocupe se não tiver instalado essa carga de trabalho quando instalou o Visual Studio. Você pode executar o instalador novamente e instalá-la agora.

   ![Desenvolvimento para desktop com C++](../build/media/desktop-development-with-cpp.png "Desenvolvimento para desktop com C++")

- Um reconhecimento dos princípios básicos do uso do IDE do Visual Studio. Se já tiver usado aplicativos de desktop do Windows, você provavelmente não terá problemas. Para ver uma introdução, consulte [Tour pelos recursos do IDE do Visual Studio](/visualstudio/ide/visual-studio-ide).

- Um reconhecimento dos princípios básicos da linguagem C++ a seguir. Não se preocupe, não faremos nada muito complicado.

## <a name="create-a-windows-desktop-project"></a>Criar um projeto de área de trabalho do Windows

Siga estas etapas para criar seu primeiro projeto de área de trabalho do Windows e insira o código para um aplicativo de área de trabalho do Windows em funcionamento. Verifique se o seletor de versão no canto superior esquerdo desta página está definido como a versão correta do Visual Studio que você está usando.

::: moniker range="vs-2019"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2019"></a>Para criar um projeto de área de trabalho do Windows no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**.

1. Na parte superior da caixa de diálogo, defina idioma **C++** como, defina **plataforma** para **Windows**e defina **tipo de projeto** como **área de trabalho**. 

1. Na lista filtrada de tipos de projeto, escolha **Assistente de área de trabalho do Windows** e escolha **Avançar**. Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

1. A caixa de diálogo **projeto de área de trabalho do Windows** agora é exibida. Em **tipo de aplicativo**, selecione **aplicativo do Windows (. exe)** . Em **Opções adicionais**, selecione **projeto vazio**. Escolha **OK** para criar o projeto.

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no projeto **DesktopApp** , escolha **Adicionar**e, em seguida, escolha **novo item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "Adicionar novo item ao projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item** , selecione  **C++ arquivo (. cpp)** . Na caixa **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop. cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp ao projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo. cpp ao projeto DesktopApp")

Seu projeto agora é criado e o arquivo de origem é aberto no editor. Para continuar, pule para [criar o código](#create-the-code).

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2017"></a>Para criar um projeto de área de trabalho do Windows no Visual Studio 2017

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. Na caixa de diálogo **novo projeto** , no painel esquerdo, expanda o**Visual C++**  **instalado** > e selecione **área de trabalho do Windows**. No painel central, selecione **Assistente de área de trabalho do Windows**.

   Na caixa **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-153.png "Nomeie o projeto DesktopApp")

1. Na caixa de diálogo **projeto de área de trabalho do Windows** , em tipo de **aplicativo**, selecione **aplicativo do Windows (. exe)** . Em **Opções adicionais**, selecione **projeto vazio**. Escolha **OK** para criar o projeto.

   ![Criar DesktopApp no assistente de projeto de área de trabalho do Windows](../build/media/desktop-app-new-project-wizard-153.png "Criar DesktopApp no assistente de projeto de área de trabalho do Windows")

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no projeto **DesktopApp** , escolha **Adicionar**e, em seguida, escolha **novo item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "Adicionar novo item ao projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item** , selecione  **C++ arquivo (. cpp)** . Na caixa **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop. cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp ao projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo. cpp ao projeto DesktopApp")

Seu projeto agora é criado e o arquivo de origem é aberto no editor. Para continuar, pule para [criar o código](#create-the-code).

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2015"></a>Para criar um projeto de área de trabalho do Windows no Visual Studio 2015

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. Na caixa de diálogo **novo projeto** , no painel esquerdo, expanda > o**C++Visual** **modelos** > instalados e selecione **Win32**. No painel central, selecione **projeto Win32**.

   Na caixa **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-150.png "Nomeie o projeto DesktopApp")

1. Na página **visão geral** do **Assistente de aplicativo Win32**, escolha **Avançar**.

   ![Visão geral do assistente para criar DesktopApp no aplicativo Win32](../build/media/desktop-app-win32-wizard-overview-150.png "Visão geral do assistente para criar DesktopApp no aplicativo Win32")

1. Na página **configurações do aplicativo** , em **tipo de aplicativo**, selecione **aplicativo do Windows**. Em **Opções adicionais**, selecione **projeto vazio**. Escolha **concluir** para criar o projeto.

   ![Criar DesktopApp nas configurações do assistente de aplicativo Win32](../build/media/desktop-app-win32-wizard-settings-150.png "Criar DesktopApp nas configurações do assistente de aplicativo Win32")

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no projeto DesktopApp, escolha **Adicionar**e, em seguida, escolha **novo item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-150.gif "Adicionar novo item ao projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item** , selecione  **C++ arquivo (. cpp)** . Na caixa **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop. cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp ao projeto DesktopApp](../build/media/desktop-app-add-cpp-file-150.png "Adicionar arquivo. cpp ao projeto DesktopApp")

Seu projeto agora é criado e o arquivo de origem é aberto no editor.

::: moniker-end

## <a name="create-the-code"></a>Criar o código

Em seguida, você aprenderá a criar o código para um aplicativo de área de trabalho do Windows no Visual Studio.

### <a name="to-start-a-windows-desktop-application"></a>Para iniciar um aplicativo da área de trabalho do Windows

1. Assim como todos os aplicativos e C++ aplicativos do C devem `main` ter uma função como ponto de partida, todos os aplicativos da área `WinMain` de trabalho do Windows devem ter uma função. `WinMain`tem a sintaxe a seguir.

   ```cpp
   int CALLBACK WinMain(
      _In_ HINSTANCE hInstance,
      _In_ HINSTANCE hPrevInstance,
      _In_ LPSTR     lpCmdLine,
      _In_ int       nCmdShow
   );
   ```

   Para obter informações sobre os parâmetros e o valor de retorno dessa função, consulte [ponto de entrada WinMain](/windows/win32/api/winbase/nf-winbase-winmain).

   > [!NOTE]
   > Quais são as palavras adicionais, `CALLBACK`como, ou `HINSTANCE` `_In_`ou? A API tradicional do Windows usa TYPEDEFs e macros de pré-processador extensivamente para abstrair alguns dos detalhes dos tipos e do código específico da plataforma, como convenções de chamada, declarações **_ declspec** e pragmas do compilador. No Visual Studio, você pode usar o recurso de [informações rápidas](/visualstudio/ide/using-intellisense#quick-info) do IntelliSense para ver o que esses TYPEDEFs e macros definem. Passe o mouse sobre a palavra de interesse ou selecione-o e pressione **Ctrl**+**K**, **Ctrl**+**I** para uma pequena janela pop-up que contém a definição. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense). Os parâmetros e os tipos de retorno geralmente usam *anotações sal* para ajudá-lo a detectar erros de programação. Para obter mais informações, consulte [usando anotações de sal para reduzir osC++ defeitos de C/código](/visualstudio/code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects).

1. Os programas da área &lt;de trabalho do Windows exigem o Windows. h >. &lt;TCHAR. h > define a `TCHAR` macro, que resolve, por fim, o **wchar_t** se o símbolo Unicode for definido em seu projeto, caso contrário, ele será resolvido para **Char**.  Se você sempre criar com UNICODE habilitado, não precisará de TCHAR e poderá simplesmente usar **wchar_t** diretamente.

   ```cpp
   #include <windows.h>
   #include <tchar.h>
   ```

1. Além da função, `WinMain` todos os aplicativos da área de trabalho do Windows também devem ter uma função de procedimento de janela. Essa função normalmente é chamada `WndProc` , mas você pode nomeá-la como desejar. `WndProc`tem a sintaxe a seguir.

   ```cpp
   LRESULT CALLBACK WndProc(
      _In_ HWND   hWnd,
      _In_ UINT   message,
      _In_ WPARAM wParam,
      _In_ LPARAM lParam
   );
   ```

   Nessa função, você escreve o código para tratar *as mensagens* que o aplicativo recebe do Windows quando ocorrem *eventos* . Por exemplo, se um usuário escolher um botão OK em seu aplicativo, o Windows enviará uma mensagem para você e você poderá escrever código dentro `WndProc` de sua função que faz qualquer trabalho apropriado. Ele é chamado de *tratamento* de um evento. Você só lida com os eventos que são relevantes para seu aplicativo.

   Para obter mais informações, consulte [procedimentos de janela](/windows/win32/winmsg/window-procedures).

### <a name="to-add-functionality-to-the-winmain-function"></a>Para adicionar funcionalidade à função WinMain

1. Na função, você preenche uma estrutura do tipo [WNDCLASSEX.](/windows/win32/api/winuser/ns-winuser-wndclassexw) `WinMain` A estrutura contém informações sobre a janela, por exemplo, o ícone do aplicativo, a cor da tela de fundo da janela, o nome a ser exibido na barra de título e, mais importante, um ponteiro de função para o procedimento de janela. O exemplo a seguir mostra uma `WNDCLASSEX` estrutura típica.

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

   Para obter informações sobre os campos da estrutura acima, consulte [WNDCLASSEX](/windows/win32/api/winuser/ns-winuser-wndclassexw).

1. Registre o `WNDCLASSEX` com o Windows para que ele saiba sobre sua janela e como enviar mensagens para ela. Use a função [RegisterClassEx](/windows/win32/api/winuser/nf-winuser-registerclassexw) e passe a estrutura da classe Window como um argumento. A `_T` macro é usada porque usamos o `TCHAR` tipo.

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

1. Agora você pode criar uma janela. Use a função [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) .

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

   Essa função retorna um `HWND`, que é um identificador para uma janela. Um identificador é, de certa forma, semelhante a um ponteiro que o Windows usa para manter o controle das janelas abertas. Para obter mais informações, consulte [tipos de dados do Windows](/windows/win32/WinProg/windows-data-types).

1. Neste ponto, a janela foi criada, mas ainda precisamos dizer ao Windows para torná-la visível. Isso é o que esse código faz:

   ```cpp
   // The parameters to ShowWindow explained:
   // hWnd: the value returned from CreateWindow
   // nCmdShow: the fourth parameter from WinMain
   ShowWindow(hWnd,
      nCmdShow);
   UpdateWindow(hWnd);
   ```

   A janela exibida não tem muito conteúdo porque você ainda não implementou `WndProc` a função. Em outras palavras, o aplicativo ainda não está manipulando as mensagens que o Windows está enviando agora para ele.

1. Para lidar com as mensagens, primeiro adicionamos um loop de mensagem para escutar as mensagens que o Windows envia. Quando o aplicativo recebe uma mensagem, esse loop a envia para `WndProc` a função a ser manipulada. O loop de mensagem é semelhante ao código a seguir.

   ```cpp
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
   ```

   Para obter mais informações sobre as estruturas e funções no loop de mensagem, consulte [msg](/windows/win32/api/winuser/ns-winuser-msg), [GetMessage](/windows/win32/api/winuser/nf-winuser-getmessage), [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage)e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).

   Neste ponto, a `WinMain` função deve ser semelhante ao código a seguir.

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

1. Para habilitar a `WndProc` função para manipular as mensagens que o aplicativo recebe, implemente uma instrução switch.

   Uma mensagem importante a ser tratada é a mensagem [WM_PAINT](/windows/win32/gdi/wm-paint) . O aplicativo recebe a `WM_PAINT` mensagem quando parte de sua janela exibida deve ser atualizada. O evento pode ocorrer quando um usuário move uma janela na frente da janela, move-a para fora e o aplicativo não sabe quando esses eventos ocorrem. Somente o Windows sabe, para que ele o notifique `WM_PAINT`. Quando a janela é exibida pela primeira vez, todas elas devem ser atualizadas.

   Para manipular uma `WM_PAINT` mensagem, primeiro chame [BeginPaint](/windows/win32/api/winuser/nf-winuser-beginpaint), em seguida, manipule toda a lógica para dispor o texto, os botões e outros controles na janela e, em seguida, chame [EndPaint](/windows/win32/api/winuser/nf-winuser-endpaint). Para o aplicativo, a lógica entre a chamada inicial e a chamada final é exibir a cadeia de caracteres "Olá, Windows Desktop!" na janela. No código a seguir, observe que a função [TextOut](/windows/win32/api/wingdi/nf-wingdi-textoutw) é usada para exibir a cadeia de caracteres.

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

   `HDC`no código, há um identificador para um contexto de dispositivo, que é uma estrutura de dados que o Windows usa para permitir que seu aplicativo se comunique com o subsistema de gráficos. As `BeginPaint` funções `EndPaint` e fazem com que seu aplicativo se comporte como um bom cidadão e não use o contexto do dispositivo por mais tempo do que o necessário. As funções ajudam a tornar o subsistema de gráficos disponível para uso por outros aplicativos.

1. Um aplicativo normalmente lida com muitas outras mensagens, por exemplo, [WM_CREATE](/windows/win32/winmsg/wm-create) quando uma janela é criada pela primeira vez e [WM_DESTROY](/windows/win32/winmsg/wm-destroy) quando a janela é fechada. O código a seguir mostra uma função básica `WndProc` , mas completa.

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

Como prometido, aqui está o código completo do aplicativo de trabalho.

### <a name="to-build-this-example"></a>Para criar este exemplo

1. Exclua qualquer código que você tenha inserido em *HelloWindowsDesktop. cpp* no editor. Copie este código de exemplo e cole-o em *HelloWindowsDesktop. cpp*:

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

1. No menu **Compilar**, escolha **Compilar Solução**. Os resultados da compilação devem aparecer na janela de **saída** no Visual Studio.

   ![Compilar o projeto DesktopApp](../build/media/desktop-app-project-build-150.gif "Compilar o projeto DesktopApp")

1. Para executar o aplicativo, pressione **F5**. Uma janela que contém o texto "Olá, Windows Desktop!" deve aparecer no canto superior esquerdo da tela.

   ![Executar o projeto DesktopApp](../build/media/desktop-app-project-run-157.PNG "Executar o projeto DesktopApp")

Parabéns! Você concluiu este passo a passo e criou um aplicativo de área de trabalho tradicional do Windows.

## <a name="see-also"></a>Consulte também

[Aplicativos da área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md)
