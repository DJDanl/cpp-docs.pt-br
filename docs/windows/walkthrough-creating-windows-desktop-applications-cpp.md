---
title: 'Passo a passo: Crie um aplicativo tradicional do Windows Desktop (C++)'
description: Como criar um aplicativo mínimo e tradicional do Windows Desktop usando o Visual Studio, C++e a API Win32
ms.custom: get-started-article
ms.date: 11/03/2019
helpviewer_keywords:
- Windows applications [C++], Win32
- Windows Desktop applications [C++]
- Windows API [C++]
ms.openlocfilehash: da74778e79a08dd3ed2b5be0675981425264bdc0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351843"
---
# <a name="walkthrough-create-a-traditional-windows-desktop-application-c"></a>Passo a passo: Crie um aplicativo tradicional do Windows Desktop (C++)

Este passo a passo mostra como criar um aplicativo de desktop tradicional do Windows no Visual Studio. O aplicativo de exemplo que você criará usa a API do Windows para exibir "Olá, desktop do Windows!" em uma janela. Você pode usar o código que você desenvolve neste passo a passo como um padrão para criar outros aplicativos de desktop do Windows.

A API do Windows (também conhecida como API Win32, API do Windows Desktop e API clássica do Windows) é uma estrutura baseada em linguagem C para criar aplicativos windows. Ele existe desde a década de 1980 e tem sido usado para criar aplicativos Windows por décadas. Estruturas mais avançadas e mais fáceis de programar foram construídas em cima da API do Windows. Por exemplo, MFC, ATL, os frameworks .NET. Mesmo o código de tempo de execução do Windows mais moderno para aplicativos UWP e Store escrito em C++/WinRT usa a API do Windows por baixo. Para obter mais informações sobre a API do Windows, consulte [O Índice de API do Windows](/windows/win32/apiindex/windows-api-list). Existem muitas maneiras de criar aplicativos windows, mas o processo acima foi o primeiro.

> [!IMPORTANT]
> Por uma questão de brevidade, algumas declarações de código são omitidas no texto. A [seção Construir a](#build-the-code) seção de código no final deste documento mostra o código completo.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para obter a melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio. Para saber mais sobre como fazer o download e instalar o Visual Studio, consulte [Instalar o Visual Studio](/visualstudio/install/install-visual-studio). Quando executar o instalador, certifique-se de que a carga de trabalho de **Desenvolvimento para desktop com C++** esteja marcada. Não se preocupe se não tiver instalado essa carga de trabalho quando instalou o Visual Studio. Você pode executar o instalador novamente e instalá-la agora.

   ![Desenvolvimento para desktop com C++](../build/media/desktop-development-with-cpp.png "Desenvolvimento para desktop com C++")

- Um reconhecimento dos princípios básicos do uso do IDE do Visual Studio. Se já tiver usado aplicativos de desktop do Windows, você provavelmente não terá problemas. Para ver uma introdução, consulte [Tour pelos recursos do IDE do Visual Studio](/visualstudio/ide/visual-studio-ide).

- Um reconhecimento dos princípios básicos da linguagem C++ a seguir. Não se preocupe, não faremos nada muito complicado.

## <a name="create-a-windows-desktop-project"></a>Crie um projeto de desktop do Windows

Siga essas etapas para criar seu primeiro projeto de desktop do Windows. À medida que você vai, você digitará o código para um aplicativo de desktop windows em funcionamento. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2019"></a>Para criar um projeto de desktop do Windows no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**.

1. Na parte superior da caixa de diálogo, defina **o Idioma** como **C++**, defina **a plataforma** para **Windows**e defina o tipo **de projeto** como **desktop**.

1. Na lista filtrada de tipos de projeto, escolha **o Assistente de Desktop do Windows** e escolha **Next**. Na página seguinte, digite um nome para o projeto, por exemplo, *DesktopApp*.

1. Escolha o botão **Criar** para criar o projeto.

1. A caixa de diálogo **do Windows Desktop Project** agora é exibida. Em **Tipo de aplicativo,** selecione **aplicativo desktop (.exe)**. Em **opções adicionais,** **selecione Projeto Vazio**. Escolha **OK** para criar o projeto.

1. No **Solution Explorer,** clique com o botão direito do mouse no projeto **DesktopApp,** escolha **Adicionar**e, em seguida, escolha **Novo Item**.

   ![Adicione novo item ao Projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "Adicione novo item ao Projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**. Na caixa **Nome,** digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo .cpp ao Projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo .cpp ao Projeto DesktopApp")

Seu projeto agora é criado e seu arquivo de origem é aberto no editor. Para continuar, pule adiante para [criar o código](#create-the-code).

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2017"></a>Para criar um projeto de desktop do Windows no Visual Studio 2017

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** no painel esquerdo, expanda o**Visual C++** **instalado** > e selecione **o Windows Desktop**. No painel do meio, selecione **o Assistente de Desktop do Windows**.

   Na caixa **Nome,** digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-153.png "Nomeie o projeto DesktopApp")

1. Na caixa de diálogo Do Projeto de Trabalho do **Windows,** no **tipo de aplicativo,** selecione **o aplicativo do Windows (.exe)**. Em **opções adicionais,** **selecione Projeto Vazio**. Certifique-se de que **o cabeçalho pré-compilado** não esteja selecionado. Escolha **OK** para criar o projeto.

1. No **Solution Explorer,** clique com o botão direito do mouse no projeto **DesktopApp,** escolha **Adicionar**e, em seguida, escolha **Novo Item**.

   ![Adicione novo item ao Projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "Adicione novo item ao Projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**. Na caixa **Nome,** digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo .cpp ao Projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo .cpp ao Projeto DesktopApp")

Seu projeto agora é criado e seu arquivo de origem é aberto no editor. Para continuar, pule adiante para [criar o código](#create-the-code).

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2015"></a>Para criar um projeto de desktop do Windows no Visual Studio 2015

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** no painel esquerdo, expanda**modelos** >  **instalados** > **Visual C++** e selecione **Win32**. No painel do meio, selecione **Projeto Win32**.

   Na caixa **Nome,** digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-150.png "Nomeie o projeto DesktopApp")

1. Na **página Visão geral** do Assistente de **Aplicativo Win32,** escolha **Next**.

   ![Criar desktopApp na visão geral do assistente de aplicativos Do 32 do Win32](../build/media/desktop-app-win32-wizard-overview-150.png "Criar desktopApp na visão geral do assistente de aplicativos Do 32 do Win32")

1. Na página **Configurações** do aplicativo, em **tipo de aplicativo,** selecione **aplicativo do Windows**. Em **Opções adicionais,** desmarque **o cabeçalho pré-compilado**e selecione **'Esvaziar'.** Escolha **Terminar** para criar o projeto.

1. No **Solution Explorer,** clique com o botão direito do mouse no projeto DesktopApp, escolha **Adicionar**e, em seguida, escolha **Novo Item**.

   ![Adicione novo item ao Projeto DesktopApp](../build/media/desktop-app-project-add-new-item-150.gif "Adicione novo item ao Projeto DesktopApp")

1. Na caixa de diálogo **Adicionar novo item,** selecione **Arquivo C++ (.cpp)**. Na caixa **Nome,** digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo .cpp ao Projeto DesktopApp](../build/media/desktop-app-add-cpp-file-150.png "Adicionar arquivo .cpp ao Projeto DesktopApp")

Seu projeto agora é criado e seu arquivo de origem é aberto no editor.

::: moniker-end

## <a name="create-the-code"></a>Criar o código

Em seguida, você aprenderá como criar o código para um aplicativo de desktop do Windows no Visual Studio.

### <a name="to-start-a-windows-desktop-application"></a>Para iniciar um aplicativo de desktop do Windows

1. Assim como todo aplicativo C e aplicativo `main` C++ deve ter uma função `WinMain` como ponto de partida, cada aplicativo de desktop do Windows deve ter uma função. `WinMain`tem a seguinte sintaxe.

   ```cpp
   int CALLBACK WinMain(
      _In_ HINSTANCE hInstance,
      _In_opt_ HINSTANCE hPrevInstance,
      _In_ LPSTR     lpCmdLine,
      _In_ int       nCmdShow
   );
   ```

   Para obter informações sobre os parâmetros e o valor de retorno desta função, consulte [winmain ponto de entrada](/windows/win32/api/winbase/nf-winbase-winmain).

   > [!NOTE]
   > O que são todas essas `CALLBACK`palavras `HINSTANCE`extras, como, ou , ou `_In_`? A API tradicional do Windows usa tipodefs e macros de pré-processador extensivamente para abstrair alguns dos detalhes de tipos e códigos específicos da plataforma, como convenções de chamadas, declarações **de __declspec** e pragmas de compilador. No Visual Studio, você pode usar o recurso IntelliSense [Quick Info](/visualstudio/ide/using-intellisense#quick-info) para ver o que esses typedefs e macros definem. Passe o mouse sobre a palavra de interesse ou selecione-o e pressione **Ctrl**+**K**, **Ctrl**+**I** para uma pequena janela pop-up que contém a definição. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense). Parâmetros e tipos de retorno geralmente usam *anotações SAL* para ajudá-lo a capturar erros de programação. Para obter mais informações, consulte [Usando anotações SAL para reduzir defeitos de código C/C++.](/cpp/code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects)

1. Os programas &lt;de desktop do Windows exigem> windows.h. &lt;tchar.h> define `TCHAR` a macro, que resolve em última instância **wchar_t** se o símbolo UNICODE for definido em seu projeto, caso contrário ele resolve **para char**.  Se você sempre constrói com UNICODE ativado, você não precisa de TCHAR e pode usar **wchar_t** diretamente.

   ```cpp
   #include <windows.h>
   #include <tchar.h>
   ```

1. Junto com `WinMain` a função, todos os aplicativos de desktop do Windows também devem ter uma função de procedimento de janela. Esta função é `WndProc`tipicamente nomeada, mas você pode nomeá-la o que quiser. `WndProc`tem a seguinte sintaxe.

   ```cpp
   LRESULT CALLBACK WndProc(
      _In_ HWND   hWnd,
      _In_ UINT   message,
      _In_ WPARAM wParam,
      _In_ LPARAM lParam
   );
   ```

   Nesta função, você escreve código para lidar com *mensagens* que o aplicativo recebe do Windows quando *eventos* ocorrem. Por exemplo, se um usuário escolher um botão OK em seu aplicativo, o Windows `WndProc` enviará uma mensagem para você e você poderá escrever código dentro de sua função que faça qualquer trabalho apropriado. Chama-se *lidar com* um evento. Você só lida com os eventos que são relevantes para sua aplicação.

   Para obter mais informações, consulte [Procedimentos de janela](/windows/win32/winmsg/window-procedures).

### <a name="to-add-functionality-to-the-winmain-function"></a>Para adicionar funcionalidade à função WinMain

1. Na `WinMain` função, você preenche uma estrutura do tipo [WNDCLASSEX](/windows/win32/api/winuser/ns-winuser-wndclassexw). A estrutura contém informações sobre a janela: o ícone do aplicativo, a cor de fundo da janela, o nome a ser exibido na barra de título, entre outras coisas. É importante ressaltar que ele contém um ponteiro de função para o procedimento da janela. O exemplo a `WNDCLASSEX` seguir mostra uma estrutura típica.

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

1. Registre `WNDCLASSEX` o com o Windows para que ele saiba sobre sua janela e como enviar mensagens para ela. Use a função [RegisterClassEx](/windows/win32/api/winuser/nf-winuser-registerclassexw) e passe a estrutura da classe da janela como argumento. A `_T` macro é usada `TCHAR` porque usamos o tipo.

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

1. Agora você pode criar uma janela. Use a função [CreateWindow.](/windows/win32/api/winuser/nf-winuser-createwindoww)

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

   Esta função `HWND`retorna uma , que é uma alça para uma janela. Uma alça é um pouco como um ponteiro que o Windows usa para manter o controle de janelas abertas. Para obter mais informações, consulte [Os Tipos de Dados do Windows](/windows/win32/WinProg/windows-data-types).

1. Neste ponto, a janela foi criada, mas ainda precisamos dizer ao Windows para torná-la visível. É o que este código faz:

   ```cpp
   // The parameters to ShowWindow explained:
   // hWnd: the value returned from CreateWindow
   // nCmdShow: the fourth parameter from WinMain
   ShowWindow(hWnd,
      nCmdShow);
   UpdateWindow(hWnd);
   ```

   A janela exibida não tem muito conteúdo porque você `WndProc` ainda não implementou a função. Em outras palavras, o aplicativo ainda não está lidando com as mensagens que o Windows está enviando agora para ele.

1. Para lidar com as mensagens, primeiro adicionamos um loop de mensagem para ouvir as mensagens que o Windows envia. Quando o aplicativo recebe uma mensagem, `WndProc` esse loop a envia para sua função a ser tratada. O loop de mensagem se assemelha ao seguinte código.

   ```cpp
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
   ```

   Para obter mais informações sobre as estruturas e funções no loop de mensagem, consulte [MSG](/windows/win32/api/winuser/ns-winuser-msg), [GetMessage,](/windows/win32/api/winuser/nf-winuser-getmessage) [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage)e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage).

   Neste ponto, `WinMain` a função deve se assemelhar ao seguinte código.

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

1. Para habilitar a `WndProc` função para lidar com as mensagens que o aplicativo recebe, implemente uma declaração de switch.

   Uma mensagem importante a ser manuseada é a [mensagem WM_PAINT.](/windows/win32/gdi/wm-paint) O aplicativo `WM_PAINT` recebe a mensagem quando parte de sua janela exibida deve ser atualizada. O evento pode ocorrer quando um usuário move uma janela em frente à sua janela e, em seguida, move-a novamente. Sua aplicação não sabe quando esses eventos ocorrem. Só o Windows sabe, então notifica `WM_PAINT` seu aplicativo com uma mensagem. Quando a janela é exibida pela primeira vez, tudo deve ser atualizado.

   Para lidar `WM_PAINT` com uma mensagem, primeiro ligue para [BeginPaint,](/windows/win32/api/winuser/nf-winuser-beginpaint)depois manuseie toda a lógica para definir o texto, botões e outros controles na janela e, em seguida, chame [EndPaint](/windows/win32/api/winuser/nf-winuser-endpaint). Para o aplicativo, a lógica entre a chamada inicial e a chamada final é exibir a string "Hello, Windows desktop!" na janela. No código a seguir, observe que a função [TextOut](/windows/win32/api/wingdi/nf-wingdi-textoutw) é usada para exibir a seqüência de strings.

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

   `HDC`no código é uma alça para um contexto de dispositivo, que é uma estrutura de dados que o Windows usa para permitir que seu aplicativo se comunique com o subsistema gráfico. As `BeginPaint` `EndPaint` funções fazem com que seu aplicativo se comporte como um bom cidadão e não use o contexto do dispositivo por mais tempo do que precisa. As funções ajudam a tornar o subsistema gráfico disponível para uso por outros aplicativos.

1. Um aplicativo normalmente lida com muitas outras mensagens. Por exemplo, [WM_CREATE](/windows/win32/winmsg/wm-create) quando uma janela é criada pela primeira vez e [WM_DESTROY](/windows/win32/winmsg/wm-destroy) quando a janela é fechada. O código a seguir `WndProc` mostra uma função básica, mas completa.

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

Como prometido, aqui está o código completo para o aplicativo de trabalho.

### <a name="to-build-this-example"></a>Para construir este exemplo

1. Exclua qualquer código inserido no *HelloWindowsDesktop.cpp* no editor. Copie este código de exemplo e cole-o em *HelloWindowsDesktop.cpp:*

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
      _In_opt_ HINSTANCE hPrevInstance,
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

1. No menu **Compilar**, escolha **Compilar Solução**. Os resultados da compilação devem aparecer na janela **Saída** no Visual Studio.

   ![Construa o Projeto DesktopApp](../build/media/desktop-app-project-build-150.gif "Construa o Projeto DesktopApp")

1. Para executar o aplicativo, pressione **F5**. Uma janela que contém o texto "Olá, desktop do Windows!" deve aparecer no canto superior esquerdo do display.

   ![Execute o Projeto DesktopApp](../build/media/desktop-app-project-run-157.PNG "Execute o Projeto DesktopApp")

Parabéns! Você completou este passo a passo e construiu um aplicativo de desktop tradicional do Windows.

## <a name="see-also"></a>Confira também

[Aplicativos para desktop do Windows](../windows/windows-desktop-applications-cpp.md)
