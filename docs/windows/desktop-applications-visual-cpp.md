---
title: Aplicativos da área de trabalho (Visual C++)
ms.date: 11/04/2016
ms.assetid: a020b534-293c-44e2-aa48-516c43ddeb8f
ms.openlocfilehash: 4576f77f7806787c4ab2a16cc279107ec9af32e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345351"
---
# <a name="desktop-applications-visual-c"></a>Aplicativos da área de trabalho (Visual C++)

Um *aplicativo de desktop* em C++ é um aplicativo nativo que pode acessar o conjunto completo de APIs do Windows e será executado em uma janela ou no console do sistema. Aplicativos da área de trabalho em C++ podem ser executados no Windows XP por meio do Windows 10 (embora o Windows XP não é mais oficialmente é suportado e há muitas APIs do Windows que foram introduzidos desde então).

Um aplicativo da área de trabalho é diferente de um aplicativo de plataforma Universal do Windows (UWP), que pode ser executados em computadores que executam o Windows 10 e também no XBox, Windows Phone, Surface Hub e outros dispositivos. Para obter mais informações sobre a área de trabalho vs. Aplicativos UWP, consulte [escolha sua tecnologia](/windows/desktop/choose-your-technology).

### <a name="desktop-bridge"></a>Ponte de desktop

No Windows 10, você pode empacotar seu aplicativo da área de trabalho existente ou um objeto COM como um aplicativo UWP e adicionar recursos UWP, como toque ou chamar as APIs do conjunto de API do Windows moderno. Você também pode adicionar um aplicativo UWP a uma solução de área de trabalho no Visual Studio e o pacote-los juntos em um único pacote e usam as APIs do Windows para se comunicar entre eles.

No Visual Studio 2017 versão 15.4 e posteriores, você pode criar um projeto de pacote de aplicativo do Windows para simplificar bastante o trabalho de empacotamento de aplicativo da área de trabalho existente. Algumas restrições se aplicam em relação a quais registro chama ou usa as APIs de seu aplicativo da área de trabalho, mas em muitos casos, você pode criar caminhos de código alternativo para obter funcionalidade semelhante durante a execução em um pacote do aplicativo. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

### <a name="terminology"></a>Terminologia

- Um *Win32* aplicativo é um aplicativo da área de trabalho em C++ que pode fazer usar nativas de Windows [APIs de C do Windows e/ou APIs COM](/windows/desktop/apiindex/windows-api-list) CRT e APIs da biblioteca padrão e 3ª bibliotecas de terceiros. Um aplicativo Win32 que é executado em uma janela exige que o desenvolvedor trabalhar explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um (x86) 32 bits ou 64 bits (x64) binário. No IDE do Visual Studio, os termos x86 e o Win32 são sinônimos.

- O [(COM Component Object Model)](/windows/desktop/com/the-component-object-model) é uma especificação que permite que os programas escritos em linguagens diferentes para se comunicar entre si. Windows de muitos componentes são implementados como objetos COM e seguem regras padrão de COM para a criação de objeto, destruição de objeto e descoberta de interface.  Usando objetos COM de aplicativos da área de trabalho do C++ é relativamente simples, mas escrever seu próprio objeto COM é mais avançada. O [biblioteca ATL (Active Template)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento de COM.

- Um aplicativo MFC é um aplicativo de desktop do Windows que usam o [Microsoft Foundation Classes](../mfc/mfc-desktop-applications.md) para criar a interface do usuário. Um aplicativo MFC também pode usar componentes COM, bem como o CRT e APIs da biblioteca padrão. O MFC fornece um thin wrapper orientado a objeto C++ sobre as APIs de Windows e o loop de mensagem de janela. O MFC é a opção padrão para aplicativos — especialmente os aplicativos de tipo de empresa — que têm muitos controles de interface do usuário ou controles de usuário personalizados. MFC fornece classes auxiliares convenientes para gerenciamento de janelas, serialização, manipulação de texto, impressão e elementos de interface do usuário moderna, como a faixa de opções. Para ser eficiente com o MFC, você deve estar familiarizado com o Win32.

- Um C++/CLI aplicativo ou componente usa extensões para C++ sintaxe (conforme permitido pelo C++ especificação) para permitir a interação entre o .NET e o código C++ nativo.  Um C++/aplicativo CLI pode ter partes que são executados nativamente e partes que são executados no .NET Framework com acesso à biblioteca de classe Base do .NET. C++/ CLI é a opção preferencial quando você tem nativo C++ código que precisa para trabalhar com código escrito em C# ou Visual Basic. Ele serve basicamente para uso em DLLs do .NET em vez de no código de interface do usuário. Para obter mais informações, consulte [programação do .NET com o C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Qualquer aplicativo da área de trabalho em C++ pode usar classes de tempo de execução C (CRT) e a biblioteca padrão e funções, objetos COM e as funções públicas do Windows, que são conhecidas coletivamente como a API do Windows. Para obter uma introdução aos aplicativos da área de trabalho do Windows em C++, consulte [começar com o C++ e o Win32](/windows/desktop/LearnWin32/learn-to-program-for-windows).

## <a name="in-this-section"></a>Nesta seção

|Título|Descrição|
|-----------|-----------------|
|[Aplicativos do Console do Windows em C++](console-applications-in-visual-cpp.md)|Contém informações sobre aplicativos de console. Um aplicativo de console Win32 (ou Win64) tem nenhuma janela de seu próprio e nenhum loop de mensagem. Ele é executado na janela do console e de entrada e saída são manipuladas por meio da linha de comando.|
|[Passo a passo: como criar aplicativos de área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo da área de trabalho do Windows simples.|
|[Criando um aplicativo da área de trabalho do Windows vazio](creating-an-empty-windows-desktop-application.md)|Como criar um projeto de área de trabalho do Windows que não tem nenhum arquivo padrão.|
|[Adicionando arquivos a aplicativos Win32 vazios](adding-files-to-an-empty-win32-applications.md)|Como adicionar arquivos a um projeto vazio.|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de cadeia de caracteres e outros recursos para um aplicativo de desktop.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para a criação de jogos em C++.|
|[Passo a passo: Criando e usando uma biblioteca estática](walkthrough-creating-and-using-a-static-library-cpp.md)|Como criar um arquivo binário.|
|[Como: usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém as etapas para configurar seu projeto compilar usando o SDK do Windows 10.|

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Desenvolvimento em Windows](/windows/desktop/index)|Contém informações sobre a API do Windows e COM. (Algumas APIs do Windows e DLLs de terceiros são implementadas como objetos COM).|
|[Hilo: Desenvolvimento de aplicativos do C++ para Windows 7](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx)|Descreve como criar um aplicativo de desktop Windows cliente rico que usa a animação do Windows e do Direct2D para criar uma interface do usuário baseada em carousel.  Este tutorial não foi atualizado desde o Windows 7, mas ainda fornece uma introdução abrangente à programação do Win32.|
|[Visão geral da programação do Windows no C++](overview-of-windows-programming-in-cpp.md)|Descreve os principais recursos da área de trabalho do Windows de programação em C++.|

## <a name="see-also"></a>Consulte também

[Visual C++](../overview/visual-cpp-in-visual-studio.md)