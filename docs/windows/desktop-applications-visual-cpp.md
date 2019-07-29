---
title: Aplicativos da área de C++trabalho (Visual)
ms.date: 07/28/2019
ms.assetid: a020b534-293c-44e2-aa48-516c43ddeb8f
ms.openlocfilehash: a1e302a29e079545f6d12ad544eab4f43e2bd445
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68606515"
---
# <a name="desktop-applications-visual-c"></a>Aplicativos da área de C++trabalho (Visual)

Um *aplicativo* de área C++ de trabalho no é um aplicativo nativo que pode acessar o conjunto completo de APIs do Windows e é executado em uma janela ou no console do sistema. Os aplicativos de C++ área de trabalho no podem ser executados no Windows XP por meio do Windows 10 (embora o Windows XP não seja mais oficialmente suportado e existam muitas APIs do Windows que foram introduzidas desde então). 

Um aplicativo de área de trabalho é diferente de um aplicativo UWP (Plataforma Universal do Windows), que pode ser executado em computadores que executam o Windows 10 e também no XBox, Windows Phone, Surface Hub e outros dispositivos. Para obter mais informações sobre a área de trabalho vs. Aplicativos UWP, consulte [escolher sua tecnologia](/windows/desktop/choose-your-technology).

### <a name="desktop-bridge"></a>Ponte de desktop

No Windows 10, você pode empacotar seu aplicativo de área de trabalho existente ou objeto COM como um aplicativo UWP e adicionar recursos UWP, como toque, ou chamar APIs do conjunto de API do Windows moderno. Você também pode adicionar um aplicativo UWP a uma solução de desktop no Visual Studio e empacotá-los juntos em um único pacote e usar APIs do Windows para se comunicar entre eles.

No Visual Studio 2017 versão 15,4 e posterior, você pode criar um projeto de pacote de aplicativos do Windows para simplificar bastante o trabalho de empacotamento de seu aplicativo de área de trabalho existente. Algumas restrições se aplicam em relação a quais chamadas de registro ou APIs seu aplicativo de desktop usa, mas em muitos casos, você pode criar caminhos de código alternativos para obter uma funcionalidade semelhante durante a execução em um pacote de aplicativo. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

### <a name="terminology"></a>Terminologia

- Um aplicativo *Win32* é um aplicativo de área de C++ trabalho do Windows no que pode usar APIs nativas do [Windows C e/ou APIs com](/windows/desktop/apiindex/windows-api-list) e APIs de biblioteca do CRT e Standard e bibliotecas de terceiros. Um aplicativo Win32 que é executado em uma janela requer que o desenvolvedor trabalhe explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um binário de 32 bits (x86) ou 64 bits (x64). No IDE do Visual Studio, os termos x86 e Win32 são sinônimos.

- O [com (Component Object Model)](/windows/desktop/com/the-component-object-model) é uma especificação que permite que programas escritos em linguagens diferentes se comuniquem uns com os outros. Muitos componentes do Windows são implementados como objetos COM e seguem regras COM padrão para a criação de objetos, descoberta de interface e destruição de objeto.  Usar objetos COM de C++ aplicativos de área de trabalho é relativamente simples, mas escrever seu próprio objeto com é mais avançado. O [Active Template Library (ATL)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento com.

- Um aplicativo MFC é um aplicativo de área de trabalho do Windows que usa o [MFC](../mfc/mfc-desktop-applications.md) para criar a interface do usuário. Um aplicativo MFC também pode usar componentes COM, bem como APIs CRT e de biblioteca padrão. O MFC fornece um C++ wrapper fino orientado a objeto sobre o loop de mensagem de janela e as APIs do Windows. O MFC é a opção padrão para aplicativos, especialmente aplicativos de tipo corporativo, que têm muitos controles de interface do usuário ou controles de usuário personalizados. O MFC fornece classes auxiliares convenientes para gerenciamento de janelas, serialização, manipulação de texto, impressão e elementos de interface do usuário modernos, como a faixa de faixas. Para ser eficaz com o MFC, você deve estar familiarizado com o Win32.

- Um C++aplicativo ou componente/CLI usa extensões para C++ sintaxe (conforme permitido pelo C++ padrão) para habilitar a interação entre o .net e o código nativo C + +.  Um C++aplicativo/CLI pode ter partes que são executadas nativamente e partes que são executadas no .NET Framework com acesso à biblioteca de classes base do .net. C++/CLI é a opção preferida quando você tem código C++ nativo que precisa trabalhar com código escrito no C# ou Visual Basic. Ele é destinado ao uso em DLLs do .NET em vez de no código da interface do usuário. Saiba mais em [Programação do .NET C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Qualquer aplicativo de área C++ de trabalho no pode usar classes e funções de biblioteca padrão e do C Runtime (CRT), objetos com e funções públicas do Windows, que coletivamente são conhecidas como a API do Windows. Para obter uma introdução aos aplicativos de área C++de trabalho do Windows no, consulte Introdução [ao Win32 e C++ ](/windows/desktop/LearnWin32/learn-to-program-for-windows)ao.

## <a name="in-this-section"></a>Nesta seção

|Título|Descrição|
|-----------|-----------------|
|[Aplicativos do Console do Windows em C++](console-applications-in-visual-cpp.md)|Contém informações sobre aplicativos de console. Um aplicativo de console Win32 (ou Win64) não tem nenhuma janela própria e nenhum loop de mensagem. Ele é executado na janela do console e a entrada e a saída são manipuladas por meio da linha de comando.|
|[Passo a passo: como criar aplicativos de área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo de área de trabalho do Windows simples.|
|[Criando um aplicativo da área de trabalho do Windows vazio](creating-an-empty-windows-desktop-application.md)|Como criar um projeto de área de trabalho do Windows que não tem arquivos padrão.|
|[Adicionando arquivos a aplicativos Win32 vazios](adding-files-to-an-empty-win32-applications.md)|Como adicionar arquivos a um projeto vazio.|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de cadeia de caracteres e outros recursos a um aplicativo de área de trabalho.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para a criação de C++jogos no.|
|[Passo a passo: Criando e usando uma biblioteca estática](walkthrough-creating-and-using-a-static-library-cpp.md)|Como criar um arquivo binário. lib.|
|[Como: usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém etapas para configurar seu projeto para criar usando o SDK do Windows 10.|

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Desenvolvimento em Windows](/windows/desktop/index)|Contém informações sobre a API do Windows e COM. (Algumas APIs do Windows e DLLs de terceiros são implementadas como objetos COM.)|
|[Hilo Desenvolvendo C++ aplicativos para o Windows 7](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx)|Descreve como criar um aplicativo de área de trabalho do Windows Rich Client que usa animação do Windows e Direct2D para criar uma interface do usuário baseada em carrossel.  Este tutorial não foi atualizado desde o Windows 7, mas ainda fornece uma introdução completa à programação do Win32.|
|[Visão geral da programação do Windows no C++](overview-of-windows-programming-in-cpp.md)|Descreve os principais recursos da programação da área C++de trabalho do Windows no.|

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)