---
title: Visão geral de programação do Windows no C++
ms.date: 09/17/2019
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
ms.openlocfilehash: cd95332721f51ed2d17c3205cba5f1456a1037b9
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075494"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Há várias categorias amplas de aplicativos do Windows que você pode criar C++com o. Cada uma tem seu próprio modelo de programação e conjunto de bibliotecas específicas do Windows, C++ mas a biblioteca padrão e as C++ bibliotecas de terceiros podem ser usadas em qualquer uma delas.

Esta seção discute como usar o Visual Studio e as bibliotecas de wrapper MFC/ATL para criar programas do Windows. Para obter a documentação sobre a própria plataforma Windows, consulte a [documentação do Windows](/windows/index).

## <a name="command-line-console-applications"></a>Aplicativos de linha de comando (console)

C++os aplicativos de console são executados na linha de comando em uma janela de console e podem exibir apenas a saída de texto. Para obter mais informações, consulte [criar C++ um projeto de aplicativo de console](../get-started/tutorial-console-cpp.md).

## <a name="native-desktop-client-applications"></a>Aplicativos cliente de desktop nativos

Um *aplicativo cliente da área de trabalho nativa* é C++ um aplicativo com janela ou c que usa as APIs nativas originais do [Windows c ou as APIs de Component Object Model (com)](/windows/win32/apiindex/windows-api-list) para acessar o sistema operacional. Essas APIs são escritas em grande parte em C. Há mais de uma maneira de criar um aplicativo de área de trabalho nativo: você pode programar usando as APIs do Win32 diretamente, usando um loop de mensagem em estilo C que processa eventos do sistema operacional. Ou, você pode programar usando *MFC* (MFC), uma biblioteca orientada C++ por objeto levemente que encapsula o Win32. Nenhuma abordagem é considerada "moderna" em comparação com a Plataforma Universal do Windows (UWP), mas ambas ainda têm suporte total e têm milhões de linhas de código em execução no mundo hoje. Um aplicativo Win32 que é executado em uma janela requer que o desenvolvedor trabalhe explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um binário de 32 bits (x86) ou 64 bits (x64). No IDE do Visual Studio, os termos x86 e Win32 são sinônimos.

Para começar a usar a programação C++ tradicional do Windows, consulte Introdução [ao Win32 C++e ](/windows/win32/LearnWin32/learn-to-program-for-windows)ao. Depois de obter alguma compreensão do Win32, será mais fácil aprender sobre [os aplicativos da área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter um exemplo de um C++ aplicativo de área de trabalho tradicional que usa gráficos sofisticados, consulte [Hilo: desenvolvendo C++ aplicativos para o Windows](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx).

### <a name="c-or-net"></a>C++ou .NET?

Em geral, a programação do C# .net no é menos complexa, menos propenso a erros e tem uma API orientada a objeto mais moderna do que o Win32 ou o MFC. Na maioria dos casos, seu desempenho é mais do que adequado. O .NET apresenta o Windows Presentation Foundation (WPF) para gráficos avançados e você pode consumir o Win32 e a API moderna do Windows Runtime. Como regra geral, é recomendável usar C++ para aplicativos de área de trabalho quando você precisar:

- controle preciso sobre o uso de memória
- a economia máxima no consumo de energia
- uso da GPU para computação geral
- acesso ao DirectX
- uso intensivo de bibliotecas C++ padrão

Também é possível combinar o poder e a eficiência do C++ com programação .net. Você pode criar uma interface do usuário C# no e C++usar o/CLI para permitir que o aplicativo C++ consuma bibliotecas nativas. Para obter mais informações, consulte [programação .NET C++com/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

## <a name="com-components"></a>Componentes COM

O [com (Component Object Model)](/windows/win32/com/the-component-object-model) é uma especificação que permite que programas escritos em linguagens diferentes se comuniquem uns com os outros. Muitos componentes do Windows são implementados como objetos COM e seguem regras COM padrão para criação de objetos, descoberta de interface e destruição de objeto.  Usar objetos COM de C++ aplicativos de área de trabalho é relativamente simples, mas escrever seu próprio objeto com é mais avançado. O [Active Template Library (ATL)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento com. Para obter mais informações, consulte [ATL com desktop Components](../atl/atl-com-desktop-components.md).

## <a name="universal-windows-platform-apps"></a>Aplicativos da Plataforma Universal do Windows

O Plataforma Universal do Windows (UWP) é a API moderna do Windows. Os aplicativos UWP são executados em qualquer dispositivo Windows 10, usam XAML para a interface do usuário e são totalmente habilitados para toque. Para obter mais informações sobre a UWP, consulte [o que é um aplicativo UWP (plataforma universal do Windows)?](/windows/uwp/get-started/whats-a-uwp) e [guia para aplicativos universais do Windows](/windows/uwp/get-started/universal-application-platform-guide).

O suporte C++ original para UWP consistiu em (1) C++/CX, um dialeto de C++ com extensões de sintaxe ou (2) a biblioteca de Windows Runtime (WRL), que se baseia em C++ Standard e com. O C++/CX e o WRL ainda têm suporte. Para novos projetos, recomendamos [ C++o/WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt), que é totalmente baseado no C++ padrão e fornece um desempenho mais rápido.

## <a name="desktop-bridge"></a>Ponte de desktop

No Windows 10, você pode empacotar seu aplicativo de área de trabalho existente ou objeto COM como um aplicativo UWP e adicionar recursos UWP, como toque, ou chamar APIs do conjunto de API do Windows moderno. Você também pode adicionar um aplicativo UWP a uma solução de desktop no Visual Studio e empacotá-los juntos em um único pacote e usar APIs do Windows para se comunicar entre eles.

O Visual Studio 2017 versão 15,4 e posterior permite que você crie um projeto de pacote de aplicativos do Windows para simplificar bastante o trabalho de empacotamento de seu aplicativo de área de trabalho existente. Algumas restrições se aplicam às chamadas de registro ou APIs que seu aplicativo de desktop pode usar. No entanto, em muitos casos, você pode criar caminhos de código alternativos para obter uma funcionalidade semelhante durante a execução em um pacote de aplicativo. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="games"></a>Jogos

Os jogos do DirectX podem ser executados no PC ou no Xbox. Para obter mais informações, consulte [elementos gráficos do DirectX e jogos](/windows/win32/directx).

## <a name="sql-server-database-clients"></a>Clientes de banco de dados SQL Server

Para acessar bancos de dados SQL Server de código nativo, use ODBC ou OLE DB. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

## <a name="windows-device-drivers"></a>Drivers de dispositivos Windows

Os drivers são componentes de nível baixo que tornam os dados de dispositivos de hardware acessíveis a aplicativos e outros componentes do sistema operacional. Para obter mais informações, consulte [Windows Driver Kit (WDK)](/windows-hardware/drivers/index).

## <a name="windows-services"></a>Serviços do Windows

Um *serviço* do Windows é um programa que pode ser executado em segundo plano com pouca ou nenhuma interação do usuário. Esses programas são chamados de *daemons* em sistemas UNIX. Para obter mais informações, consulte [Serviços](/windows/win32/services/services).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

O Visual Studio inclui a biblioteca de tempo de execução C ( C++ CRT), a biblioteca padrão e outras bibliotecas específicas da Microsoft. A maioria das pastas de inclusão que contêm arquivos de cabeçalho para essas bibliotecas está localizada no diretório de instalação do Visual Studio, na pasta \VC Os arquivos de cabeçalho do Windows e do CRT são encontrados na pasta de instalação do SDK do Windows.

O [Gerenciador de pacotes do Vcpkg](../build/vcpkg.md) permite que você instale facilmente centenas de bibliotecas de software livre de terceiros para o Windows.

As bibliotecas da Microsoft incluem:

- Microsoft Foundation Classes (MFC): uma estrutura orientada por objeto para criação de programas tradicionais do Windows (especialmente aplicativos empresariais) que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [aplicativos de área de trabalho do MFC](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): uma biblioteca auxiliar potente para criação de componentes COM. Para obter mais informações, consulte [ATL com desktop Components](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [ C++ ampC++ (grande paralelismo acelerado)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Runtime de Simultaneidade: uma biblioteca que simplifica o trabalho da programação paralela e assíncrona para dispositivos de vários e muitos núcleos. Para obter mais informações, consulte [Runtime de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o SDK do Windows como um componente da C++ carga de trabalho de desktop, que permite o desenvolvimento de aplicativos universais do Windows. Para desenvolver aplicativos UWP, você precisa da versão do Windows 10 do SDK do Windows. Para obter informações, consulte [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivo de SDK do Windows](https://developer.microsoft.com/windows/downloads/sdk-archive)).

Os **arquivos de programas (x86) \Windows kits** é o local padrão para todas as versões do SDK do Windows que você instalou.

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte Introdução [ao desenvolvimento com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio)e [visão C++ geral do desenvolvimento no Visual Studio](../overview/overview-of-cpp-development.md).

## <a name="in-this-section"></a>Nesta seção
|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Walkthrough: Criando um programa C++ padrão](walkthrough-creating-a-standard-cpp-program-cpp.md)| Crie um aplicativo de console do Windows.|
|[Passo a passo: criando aplicativos da área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo de área de trabalho do Windows nativo.|
|[Assistente da Área de Trabalho do Windows](windows-desktop-wizard.md)|Use o assistente para criar novos projetos do Windows.|
|[ATL (Active Template Library)](../atl/atl-com-desktop-components.md)|Use a biblioteca do ATL para criar componentes COM C++no.|
|[MFC (Microsoft Foundation Classes)](../mfc/mfc-desktop-applications.md)|Use o MFC para criar aplicativos grandes ou pequenos do Windows com caixas de diálogo e controles|
|[Classes compartilhadas da ATL e do MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Use classes como CString que são compartilhadas em ATL e MFC.|
|[Acesso a dados](../data/data-access-in-cpp.md)| OLE DB e ODBC|
|[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)|Vários tipos de cadeia de caracteres no Windows.|
|[Recursos para criar um jogo usando DirectX](resources-for-creating-a-game-using-directx.md)
|[Como usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|SDK do Windows|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de cadeia de caracteres e outros recursos a um aplicativo de área de trabalho.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para a criação de C++jogos no.|
|[Como usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém etapas para configurar seu projeto para criar usando o SDK do Windows 10.|
|[Como implantar aplicativos da área de trabalho nativos](deploying-native-desktop-applications-visual-cpp.md)|Implante aplicativos nativos no Windows.|

## <a name="related-articles"></a>Artigos relacionados

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)|Tópico pai para conteúdo C++ do desenvolvedor Visual.|
[Desenvolvimento .NET com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|Crie wrappers para bibliotecas C++ nativas que permitem a comunicação com aplicativos e componentes .net.|
|[Extensões de componentes para .NET e UWP](../extensions/component-extensions-for-runtime-platforms.md)|Referência para elementos de sintaxe compartilhados C++por/CX C++e/CLI.|
|[Aplicativos universais do Windows (C++)](../cppcx/universal-windows-apps-cpp.md)|Grave aplicativos UWP usando C++a WRL (biblioteca de modelos/cx ou Windows Runtime).|
|[Atributos C++ para COM e .NET](attributes/cpp-attributes-com-net.md)|Atributos não padrão para programação somente do Windows usando .NET ou COM.|
