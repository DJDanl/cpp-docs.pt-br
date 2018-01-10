---
title: "Passo a passo: Criar um aplicativo de área de trabalho do Windows tradicional (C++) | Microsoft Docs"
ms.custom: 
ms.date: 10/09/2017
ms.reviewer: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- Windows applications [C++], Win32
- Windows Desktop applications [C++]
- Windows API [C++]
ms.assetid: a247a9af-aff1-4899-9577-5f8104a0afbb
caps.latest.revision: "27"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8926e5e2432dea0e366698346df1d4b708517553
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-create-a-traditional-windows-desktop-application-c"></a>Passo a passo: Criar um aplicativo de área de trabalho do Windows tradicional (C++)

Este passo a passo mostra como criar um aplicativo de área de trabalho tradicional do Windows no Visual Studio. O aplicativo de exemplo, você criará usa a API do Windows para exibir "Olá, área de trabalho do Windows!" em uma janela. Você pode usar o código que você desenvolve neste passo a passo como um padrão para criar outros aplicativos de área de trabalho do Windows.

A API do Windows (também conhecido como a API do Win32, API de área de trabalho do Windows e API clássica do Windows) é uma estrutura de linguagem C com base para a criação de aplicativos do Windows. Ele já existe desde a década de 1980 e foi usado para criar aplicativos do Windows para décadas. Estruturas mais avançadas e mais fácil para programa foram criadas sobre essa API, como os .NET frameworks, ATL e MFC. Até mesmo os mais moderno código para aplicativos UWP e Store escritos em C + + WinRT usa essa API abaixo. Para obter mais informações sobre a API do Windows, consulte [índice de API do Windows](https://msdn.microsoft.com/library/windows/desktop/ff818516.aspx). Há muitas maneiras de criar aplicativos do Windows, mas isso foi a primeira.

> [!IMPORTANT]
> Por razões de brevidade, algumas instruções de código são omitidas do texto. O [compilar o código](#build-the-code) seção no final deste documento mostra o código completo.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. É recomendável Windows 10 para a melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio de 2017. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [instalar o Visual Studio 2017](/visualstudio/install/install-visual-studio). Quando você executar a instalação, verifique se o **desenvolvimento de área de trabalho com C++** é verificada cargas de trabalho. Não se preocupe se você não instalar essa carga de trabalho quando você instalou o Visual Studio. Você pode executar o instalador novamente e instale-o agora.

   ![Desenvolvimento de área de trabalho com C++](../build/media/desktop-development-with-cpp.png "desenvolvimento de área de trabalho com C++")

- Um entendimento dos fundamentos de como usar o Visual Studio IDE. Se você tiver usado a aplicativos de área de trabalho do Windows antes, você provavelmente pode acompanhar. Para obter uma introdução, consulte [tour pelos recursos do Visual Studio IDE](/visualstudio/ide/visual-studio-ide).

- Um entendimento de suficiente os conceitos básicos da linguagem C++ para acompanhar. Não se preocupe, nós não fazer nada muito complicado.

## <a name="create-a-windows-desktop-project"></a>Criar um projeto de área de trabalho do Windows

Siga estas etapas para criar seu primeiro projeto de área de trabalho do Windows e digite o código de um aplicativo de área de trabalho do Windows em funcionamento. Se você estiver usando uma versão do Visual Studio anteriores à versão 15,3 2017 de Visual Studio, vá para [para criar um projeto de área de trabalho do Windows no Visual Studio 2017 RTM](#create-in-vs2017-rtm).

### <a name="to-create-a-windows-desktop-project-in-visual-studio-2017-update-153-and-later"></a>Para criar um projeto de área de trabalho do Windows no Visual Studio 2017 atualização 15,3 e posterior

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, expanda **instalado**, **Visual C++**, em seguida, selecione **Windows Desktop**. No painel central, selecione **Assistente de área de trabalho do Windows**.

   No **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-153.png "Nomeie o projeto DesktopApp")

1. No **projeto de área de trabalho do Windows** caixa de diálogo, em **tipo de aplicativo**, selecione **aplicativo do Windows (.exe)**. Em **opções adicionais**, selecione **projeto vazio**. Escolha **Okey** para criar o projeto.

   ![Criar DesktopApp no Assistente de projeto de área de trabalho do Windows](../build/media/desktop-app-new-project-wizard-153.png "criar DesktopApp no Assistente de projeto de área de trabalho do Windows")

1. Em **Solution Explorer**, com o botão direito do **DesktopApp** de projeto, escolha **adicionar**e, em seguida, escolha **Novo Item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-153.gif "adicionar novo item ao projeto DesktopApp")

1. No **Adicionar Novo Item** caixa de diálogo, selecione **C++ arquivo (. cpp)**. No **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp para projeto DesktopApp](../build/media/desktop-app-add-cpp-file-153.png "Adicionar arquivo. cpp DesktopApp projeto")

O projeto é criado e seu arquivo de origem é aberto no editor. Para continuar, vá para [criar o código](#create-the-code).

### <a id="create-in-vs2017-rtm"></a>Para criar um projeto de área de trabalho do Windows no Visual Studio 2017 RTM

1. No menu **Arquivo**, escolha **Novo** e, em seguida, clique em **Projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, expanda **instalado**, **modelos**, **Visual C++**e, em seguida, selecione **Win32**. No painel central, selecione **projeto Win32**.

   No **nome** , digite um nome para o projeto, por exemplo, *DesktopApp*. Escolha **OK**.

   ![Nomeie o projeto DesktopApp](../build/media/desktop-app-new-project-name-150.png "Nomeie o projeto DesktopApp")

1. No **visão geral** página do **Assistente de aplicativo Win32**, escolha **próximo**.

   ![Criar DesktopApp na visão geral do Assistente de aplicativo Win32](../build/media/desktop-app-win32-wizard-overview-150.png "criar DesktopApp na visão geral do Assistente de aplicativo Win32")

1. Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo do Windows**. Em **opções adicionais**, selecione **projeto vazio**. Escolha **concluir** para criar o projeto.

   ![Criar DesktopApp nas configurações do Assistente de aplicativo Win32](../build/media/desktop-app-win32-wizard-settings-150.png "criar DesktopApp nas configurações do Assistente de aplicativo Win32")

1. Em **Solution Explorer**, com o botão direito no projeto DesktopApp, escolha **adicionar**e, em seguida, escolha **Novo Item**.

   ![Adicionar novo item ao projeto DesktopApp](../build/media/desktop-app-project-add-new-item-150.gif "adicionar novo item ao projeto DesktopApp")

1. No **Adicionar Novo Item** caixa de diálogo, selecione **C++ arquivo (. cpp)**. No **nome** , digite um nome para o arquivo, por exemplo, *HelloWindowsDesktop.cpp*. Escolha **Adicionar**.

   ![Adicionar arquivo. cpp para projeto DesktopApp](../build/media/desktop-app-add-cpp-file-150.png "Adicionar arquivo. cpp DesktopApp projeto")

O projeto é criado e seu arquivo de origem é aberto no editor.

## <a name="create-the-code"></a>Criar o código

Em seguida, você aprenderá a criar o código para um aplicativo de área de trabalho do Windows no Visual Studio.

### <a name="to-start-a-windows-desktop-application"></a>Para iniciar um aplicativo de área de trabalho do Windows

1. Assim como cada C aplicativo e o aplicativo C++ devem ter uma `main` funciona como ponto de partida, cada Windows aplicativo de área de trabalho deve ter um `WinMain` função. `WinMain`tem a seguinte sintaxe.

   ```cpp
   int CALLBACK WinMain(
      _In_ HINSTANCE hInstance,
      _In_ HINSTANCE hPrevInstance,
      _In_ LPSTR     lpCmdLine,
      _In_ int       nCmdShow
   );
   ```

   Para obter informações sobre os parâmetros e o valor de retorno dessa função, consulte [WinMain ponto de entrada](https://msdn.microsoft.com/library/windows/desktop/ms633559).

   > [!NOTE]
   > Quais são todas essas palavras extras, como **retorno de chamada**, ou **HINSTANCE**, ou  **\_na\_**? A API do Windows tradicional usa definições de tipo e macros de pré-processador extensivamente para abstrair alguns dos detalhes de tipos e específica de plataforma código, como chamar convenções, **declspec** pragmas de compilador e declarações. No Visual Studio, você pode usar o IntelliSense [informações rápidas](/visualstudio/ide/using-intellisense#quick-info) recurso para ver o que definem essas macros e definições de tipo. Passe o mouse sobre a palavra de interesse, ou selecione-o e pressione ctrl-K, ctrl-I para uma pequena janela pop-up que contém a definição. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense). Parâmetros e tipos de retorno normalmente usam *anotações SAL* para ajudá-lo catch erros de programação. Para obter mais informações, consulte [usando anotações de SAL para reduzir defeitos de código C/C++](/visualstudio/code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects).

1. Programas de área de trabalho do Windows exigem &lt;Windows. h >. &lt;TCHAR. h > define o `TCHAR` macro, que, por fim, é resolvido para `wchar_t` se o símbolo UNICODE é definido em seu projeto, caso contrário, ele resolve para `char`.  Se sempre que você compilar com UNICODE habilitado, você não precisa TCHAR e pode usar apenas wchar_t diretamente.

   ```cpp
   #include <windows.h>
   #include <tchar.h>
   ```

1. Além de `WinMain` função, todos os aplicativos de área de trabalho do Windows também devem ter uma função de procedimento de janela. Essa função é geralmente nomeada `WndProc` , mas você poderá nomeá-lo como desejar. `WndProc`tem a seguinte sintaxe.

   ```cpp
   LRESULT CALLBACK WndProc(
      _In_ HWND   hwnd,
      _In_ UINT   uMsg,
      _In_ WPARAM wParam,
      _In_ LPARAM lParam
   );
   ```

   Essa função você escrever código para tratar *mensagens* que recebe o aplicativo do Windows quando *eventos* ocorrer. Por exemplo, se um usuário escolhe um botão Okey em seu aplicativo, Windows enviará uma mensagem para você e você pode escrever código dentro de sua `WndProc` função que executa o trabalho for apropriado. Isso é chamado de *tratamento* um evento. Você só manipular os eventos que são relevantes para seu aplicativo.

   Para obter mais informações, consulte [procedimentos de janela](https://msdn.microsoft.com/library/windows/desktop/ms632593).

### <a name="to-add-functionality-to-the-winmain-function"></a>Para adicionar funcionalidade à função WinMain

1. No `WinMain` função, preencher uma estrutura de tipo [WNDCLASSEX](https://msdn.microsoft.com/library/windows/desktop/ms633577). Essa estrutura contém informações sobre a janela, por exemplo, o ícone do aplicativo, a cor de plano de fundo da janela, o nome a ser exibido na barra de título e muito importante, um ponteiro de função para o procedimento de janela. O exemplo a seguir mostra um típico `WNDCLASSEX` estrutura.

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

   Para obter informações sobre os campos dessa estrutura, consulte [WNDCLASSEX](https://msdn.microsoft.com/library/windows/desktop/ms633577).

1. Você deve registrar o `WNDCLASSEX` com o Windows para que ele saiba sobre a janela e como enviar mensagens para ela. Use o [RegisterClassEx](https://msdn.microsoft.com/library/windows/desktop/ms633587) de função e passar a estrutura de classe de janela como um argumento. O `_T` macro é usada porque usamos o `TCHAR` tipo.

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

1. Agora você pode criar uma janela. Use o [CreateWindow](https://msdn.microsoft.com/library/windows/desktop/ms632679) função.

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

   Essa função retorna um `HWND`, que é um identificador para uma janela. Um identificador é um pouco como um ponteiro que o Windows usa para acompanhar as janelas abertas. Para obter mais informações, consulte [tipos de dados do Windows](https://msdn.microsoft.com/library/windows/desktop/aa383751).

1. Agora a janela foi criada, mas ainda precisamos dizer ao Windows para torná-lo visível. É o que faz esse código:

   ```cpp
   // The parameters to ShowWindow explained:
   // hWnd: the value returned from CreateWindow
   // nCmdShow: the fourth parameter from WinMain
   ShowWindow(hWnd,
      nCmdShow);
   UpdateWindow(hWnd);
   ```

   A janela exibida não tem muito conteúdo porque ainda não foi implementado o `WndProc` função. Em outras palavras, o aplicativo não está ainda tratando as mensagens que o Windows agora está enviando a ele.

1. Para lidar com as mensagens, primeiro adicionamos um loop de mensagem para escutar mensagens que o Windows envia. Quando o aplicativo recebe uma mensagem, este loop envia para seu `WndProc` função devem ser tratados. O loop de mensagem se parece com o código a seguir.

   ```cpp
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
   ```

   Para obter mais informações sobre as estruturas e funções no loop de mensagem, consulte [MSG](https://msdn.microsoft.com/library/windows/desktop/ms644958), [GetMessage](https://msdn.microsoft.com/library/windows/desktop/ms644936), [TranslateMessage](https://msdn.microsoft.com/library/windows/desktop/ms644955), e [DispatchMessage ](https://msdn.microsoft.com/library/windows/desktop/ms644934).

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

1. Para habilitar o `WndProc` função para tratar as mensagens que o aplicativo recebe, implemente uma instrução switch.

   É uma mensagem importante para lidar com o [WM_PAINT](https://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem. O aplicativo recebe esta mensagem quando parte de sua janela exibida deve ser atualizado. Esse evento pode ocorrer quando um usuário move uma janela na frente de sua janela, em seguida, movê-lo imediatamente novamente. Seu aplicativo não sabe quando ocorrem os eventos como isso; somente Windows sabe, para que ele o notificará com `WM_PAINT`. Quando a janela é exibida pela primeira vez, todos eles devem ser atualizados.

   Para tratar um `WM_PAINT` mensagem, a primeira chamada [BeginPaint](https://msdn.microsoft.com/library/windows/desktop/dd183362), em seguida, manipular toda a lógica para formatar o texto, botões e outros controles na janela e, em seguida, chamar [EndPaint](https://msdn.microsoft.com/library/windows/desktop/dd162598). Para este aplicativo, a lógica entre a chamada de início e a chamada final é exibir a cadeia de caracteres "Olá, área de trabalho do Windows!" Na janela. No código a seguir, observe que o [TextOut](https://msdn.microsoft.com/library/windows/desktop/dd145133) função é usada para exibir a cadeia de caracteres.

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

   `HDC`Esse código é um identificador para um contexto de dispositivo, que é uma estrutura de dados que o Windows usa para habilitar seu aplicativo para se comunicar com o subsistema de gráficos. O `BeginPaint` e `EndPaint` funções Certifique-se de que seu aplicativo se comporta como um bom cidadão e não usa o contexto de dispositivo por mais tempo do que o necessário. Isso ajuda a garantir que o subsistema de elementos gráficos está disponível para uso por outros aplicativos.

1. Um aplicativo normalmente manipula muitas outras mensagens, por exemplo, [WM_CREATE](https://msdn.microsoft.com/library/windows/desktop/ms632619) quando uma janela é criada, e [WM_DESTROY](https://msdn.microsoft.com/library/windows/desktop/ms632620) quando a janela for fechada. O código a seguir mostra um arquivo mas concluir `WndProc` função.

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

## <a name="build-the-code"></a>Compile o código

Como prometido, aqui está o código completo para o aplicativo de trabalho.

### <a name="to-build-this-example"></a>Para criar este exemplo

1. Exclua qualquer código que você digitou em HelloWindowsDesktop.cpp no editor. Copie este código de exemplo e, em seguida, cole-o em HelloWindowsDesktop.cpp:

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

1. No menu **Compilar**, escolha **Compilar Solução**. Os resultados da compilação devem aparecer no **saída** janela no Visual Studio.

   ![Compilar o projeto DesktopApp](../build/media/desktop-app-project-build-150.gif "compilar o projeto DesktopApp")

1. Para executar o aplicativo, pressione **F5**. Uma janela que contém o texto "Olá, área de trabalho do Windows!" deve aparecer no canto superior esquerdo da tela.

   ![Execute o projeto DesktopApp](../build/media/desktop-app-project-run-150.gif "executar o projeto DesktopApp")

Parabéns! Concluir este passo a passo e criado um aplicativo de área de trabalho tradicional do Windows.

## <a name="see-also"></a>Consulte também

[Aplicativos de área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md)
