---
title: Aplicativos de área de trabalho (Visual C++)
ms.date: 07/28/2019
ms.assetid: a020b534-293c-44e2-aa48-516c43ddeb8f
ms.topic: overview
ms.openlocfilehash: 26448ca65b3162e2adfe6988dfd8c9e85432429c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504439"
---
# <a name="desktop-applications-visual-c"></a>Aplicativos de área de trabalho (Visual C++)

Um *aplicativo de área de trabalho* em C++ é um aplicativo nativo que pode acessar o conjunto completo de APIs do Windows e é executado em uma janela ou no console do sistema. Os aplicativos de área de trabalho em C++ podem ser executados no Windows XP por meio do Windows 10 (embora o Windows XP não seja mais oficialmente suportado e existam muitas APIs do Windows que foram introduzidas desde então).

Um aplicativo de área de trabalho é diferente de um aplicativo UWP (Plataforma Universal do Windows), que pode ser executado em computadores que executam o Windows 10 e também no XBox, Windows Phone, Surface Hub e outros dispositivos. Para obter mais informações sobre aplicativos da área de trabalho vs. UWP, consulte [escolher sua tecnologia](/windows/win32/choose-your-technology).

## <a name="desktop-bridge"></a>Ponte de Desktop

No Windows 10, você pode empacotar seu aplicativo de área de trabalho existente ou objeto COM como um aplicativo UWP e adicionar recursos UWP, como toque, ou chamar APIs do conjunto de API do Windows moderno. Você também pode adicionar um aplicativo UWP a uma solução de desktop no Visual Studio e empacotá-los juntos em um único pacote e usar APIs do Windows para se comunicar entre eles.

No Visual Studio 2017 versão 15,4 e posterior, você pode criar um projeto de pacote de aplicativos do Windows para simplificar bastante o trabalho de empacotamento de seu aplicativo de área de trabalho existente. Algumas restrições se aplicam em relação a quais chamadas de registro ou APIs seu aplicativo de desktop usa, mas em muitos casos, você pode criar caminhos de código alternativos para obter uma funcionalidade semelhante durante a execução em um pacote de aplicativo. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="terminology"></a>Terminologia

- Um aplicativo *Win32* é um aplicativo de área de trabalho do Windows em C++ que pode usar APIs nativas do [Windows C e/ou APIs com](/windows/win32/apiindex/windows-api-list) e APIs de biblioteca do CRT e Standard e bibliotecas de terceiros. Um aplicativo Win32 que é executado em uma janela requer que o desenvolvedor trabalhe explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um binário de 32 bits (x86) ou 64 bits (x64). No IDE do Visual Studio, os termos x86 e Win32 são sinônimos.

- O [com (Component Object Model)](/windows/win32/com/the-component-object-model) é uma especificação que permite que programas escritos em linguagens diferentes se comuniquem uns com os outros. Muitos componentes do Windows são implementados como objetos COM e seguem regras COM padrão para a criação de objetos, descoberta de interface e destruição de objeto.  Usar objetos COM de aplicativos de Desktop C++ é relativamente simples, mas escrever seu próprio objeto COM é mais avançado. O [Active Template Library (ATL)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento com.

- Um aplicativo MFC é um aplicativo de área de trabalho do Windows que usa o [MFC](../mfc/mfc-desktop-applications.md) para criar a interface do usuário. Um aplicativo MFC também pode usar componentes COM, bem como APIs CRT e de biblioteca padrão. O MFC fornece um wrapper fino orientado a objeto C++ sobre o loop de mensagem de janela e as APIs do Windows. O MFC é a opção padrão para aplicativos, especialmente aplicativos de tipo corporativo, que têm muitos controles de interface do usuário ou controles de usuário personalizados. O MFC fornece classes auxiliares convenientes para gerenciamento de janelas, serialização, manipulação de texto, impressão e elementos de interface do usuário modernos, como a faixa de faixas. Para ser eficaz com o MFC, você deve estar familiarizado com o Win32.

- Um aplicativo ou componente C++/CLI usa extensões para a sintaxe do C++ (como permitido pelo padrão C++) para habilitar a interação entre o .NET e o código C + + nativo.  Um aplicativo C++/CLI pode ter partes que são executadas nativamente e partes que são executadas no .NET Framework com acesso à biblioteca de classes base do .NET. C++/CLI é a opção preferida quando você tem código C++ nativo que precisa trabalhar com código escrito em C# ou Visual Basic. Ele é destinado ao uso em DLLs do .NET em vez de no código da interface do usuário. Saiba mais em [Programação do .NET C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

Qualquer aplicativo de área de trabalho em C++ pode usar classes de biblioteca CRT (C Runtime) e padrão e funções, objetos COM e funções públicas do Windows, que coletivamente são conhecidas como a API do Windows. Para obter uma introdução aos aplicativos da área de trabalho do Windows em C++, consulte Introdução [ao Win32 e ao C++](/windows/win32/LearnWin32/learn-to-program-for-windows).

## <a name="in-this-section"></a>Nesta seção

|Título|Descrição|
|-----------|-----------------|
|[Aplicativos do Console do Windows em C++](./overview-of-windows-programming-in-cpp.md)|Contém informações sobre aplicativos de console. Um aplicativo de console Win32 (ou Win64) não tem nenhuma janela própria e nenhum loop de mensagem. Ele é executado na janela do console e a entrada e a saída são manipuladas por meio da linha de comando.|
|[Passo a passo: criando aplicativos da área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo de área de trabalho do Windows simples.|
|[Criando um aplicativo da área de trabalho do Windows vazio](./overview-of-windows-programming-in-cpp.md)|Como criar um projeto de área de trabalho do Windows que não tem arquivos padrão.|
|[Adicionando arquivos a aplicativos Win32 vazios](./overview-of-windows-programming-in-cpp.md)|Como adicionar arquivos a um projeto vazio.|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de cadeia de caracteres e outros recursos a um aplicativo de área de trabalho.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para criar jogos em C++.|
|[Instruções passo a passo: criando e usando uma biblioteca estática](../build/walkthrough-creating-and-using-a-static-library-cpp.md)|Como criar um arquivo binário. lib.|
|[Como: usar o SDK do Windows 10 em um aplicativo de área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém etapas para configurar seu projeto para criar usando o SDK do Windows 10.|

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Desenvolvimento em Windows](/windows/win32/index)|Contém informações sobre a API do Windows e COM. (Algumas APIs do Windows e DLLs de terceiros são implementadas como objetos COM.)|
|[Hilo: desenvolvendo aplicativos C++ para o Windows 7](/previous-versions/msdn10/ff708696(v=msdn.10))|Descreve como criar um aplicativo de área de trabalho do Windows Rich Client que usa animação do Windows e Direct2D para criar uma interface do usuário baseada em carrossel.  Este tutorial não foi atualizado desde o Windows 7, mas ainda fornece uma introdução completa à programação do Win32.|
|[Visão geral da programação do Windows em C++](overview-of-windows-programming-in-cpp.md)|Descreve os principais recursos da programação de área de trabalho do Windows em C++.|

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)
