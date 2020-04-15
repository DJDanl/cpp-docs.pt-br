---
title: Visão geral de programação do Windows no C++
ms.date: 09/17/2019
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
ms.openlocfilehash: 8ab7fbf7c955b1c828ef583aa639eda7409cf167
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359938"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Existem várias categorias amplas de aplicativos Windows que você pode criar com C++. Cada uma tem seu próprio modelo de programação e conjunto de bibliotecas específicas do Windows, mas a biblioteca padrão C++ e bibliotecas C++ de terceiros podem ser usadas em qualquer uma delas.

Esta seção discute como usar o Visual Studio e as bibliotecas de invólucros MFC/ATL para criar programas do Windows. Para obter documentação na própria plataforma Windows, consulte a [documentação do Windows](/windows/index).

## <a name="command-line-console-applications"></a>Aplicativos de linha de comando (console)

Os aplicativos do console C++ são executados a partir da linha de comando em uma janela do console e podem exibir apenas a saída de texto. Para obter mais informações, consulte [Criar um projeto de aplicativo de console C++.](../get-started/tutorial-console-cpp.md)

## <a name="native-desktop-client-applications"></a>Aplicativos nativos de clientes de desktop

Um *aplicativo cliente nativo da área de trabalho* é um aplicativo com janela C ou C++ que usa as APIs nativas originais do Windows C ou [ASTs (Component Object Model, modelo de objeto componente) nativo para](/windows/win32/apiindex/windows-api-list) acessar o sistema operacional. Essas APIs são escritas principalmente em C. Há mais de uma maneira de criar um aplicativo de desktop nativo: você pode programar usando diretamente as APIs do Win32, usando um loop de mensagem no estilo C que processa eventos do sistema operacional. Ou, você pode programar usando *o Microsoft Foundation Classes* (MFC), uma biblioteca C++ levemente orientada a objetos que envolve o Win32. Nenhuma das duas abordagem é considerada "moderna" em comparação com a Universal Windows Platform (UWP), mas ambas ainda são totalmente suportadas e têm milhões de linhas de código em execução no mundo atualmente. Um aplicativo Win32 que é executado em uma janela exige que o desenvolvedor trabalhe explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um binário de 32 bits (x86) ou 64 bits (x64). No Visual Studio IDE, os termos x86 e Win32 são sinônimos.

Para começar com a programação tradicional do Windows C++, consulte [Get Started com Win32 e C++](/windows/win32/LearnWin32/learn-to-program-for-windows). Depois de entender o Win32, será mais fácil aprender sobre [mfc desktop applications](../mfc/mfc-desktop-applications.md). Para um exemplo de um aplicativo de desktop C++ tradicional que usa gráficos sofisticados, consulte [Hilo: Desenvolvendo aplicativos C++ para Windows](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx).

### <a name="c-or-net"></a>C++ ou .NET?

Em geral, a programação .NET em C# é menos complexa, menos propensa a erros e tem uma API mais moderna orientada a objetos do que o Win32 ou MFC. Na maioria dos casos, seu desempenho é mais do que adequado. .NET apresenta o Windows Presentation Foundation (WPF) para gráficos ricos, e você pode consumir tanto o Win32 quanto a Moderna API do Windows Runtime. Como regra geral, recomendamos o uso de C++ para aplicativos de desktop quando você precisar:

- controle preciso sobre o uso da memória
- a maior economia no consumo de energia
- uso da GPU para computação geral
- acesso ao DirectX
- uso pesado de bibliotecas C++ padrão

Também é possível combinar a potência e eficiência do C++ com a programação .NET. Você pode criar uma interface de usuário em C# e usar C++/CLI para permitir que o aplicativo consuma bibliotecas C++ nativas. Para obter mais informações, consulte [.NET Programação com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

## <a name="com-components"></a>Componentes COM

O [Component Object Model (COM)](/windows/win32/com/the-component-object-model) é uma especificação que permite que programas escritos em diferentes idiomas se comuniquem entre si. Muitos componentes do Windows são implementados como objetos COM e seguem as regras padrão do COM para criação de objetos, detecção de interface e destruição de objetos.  O uso de objetos COM de aplicativos de desktop C++ é relativamente simples, mas escrever seu próprio objeto COM é mais avançado. A [Active Template Library (ATL)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento do COM. Para obter mais informações, consulte [os componentes de desktop ATL COM](../atl/atl-com-desktop-components.md).

## <a name="universal-windows-platform-apps"></a>Aplicativos da Plataforma Universal do Windows

A Universal Windows Platform (UWP) é a API moderna do Windows. Os aplicativos UWP são executados em qualquer dispositivo Windows 10, usam XAML para a interface do usuário e são totalmente ativados por toque. Para obter mais informações sobre o UWP, consulte [O que é um aplicativo universal da Plataforma Windows (UWP) e](/windows/uwp/get-started/whats-a-uwp) Guia para Aplicativos [Universais do Windows](/windows/uwp/get-started/universal-application-platform-guide).

O suporte original c++ para UWP consistia em (1) C++/CX, um dialeto de C++ com extensões de sintaxe, ou (2) a Biblioteca de Tempo de Execução do Windows (WRL), que é baseada no Padrão C++ e COM. Tanto C++/CX quanto WRL ainda são suportados. Para novos projetos, recomendamos [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt), que é inteiramente baseado no C++ padrão e fornece desempenho mais rápido.

## <a name="desktop-bridge"></a>Ponte de Desktop

No Windows 10, você pode empacotar seu aplicativo de desktop ou objeto COM existente como um aplicativo UWP e adicionar recursos de UWP, como toque, ou chamar APIs do conjunto moderno de API do Windows. Você também pode adicionar um aplicativo UWP a uma solução de desktop no Visual Studio, e empacotá-los juntos em um único pacote e usar APIs do Windows para se comunicar entre eles.

Visual Studio 2017 versão 15.4 e posteriorpermite que você crie um Projeto de Pacote de Aplicativos do Windows para simplificar muito o trabalho de embalagem do seu aplicativo de desktop existente. Algumas restrições se aplicam às chamadas de registro ou APIs que seu aplicativo de desktop pode usar. No entanto, em muitos casos, você pode criar caminhos de código alternativos para obter funcionalidadesemelhante durante a execução em um pacote de aplicativos. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="games"></a>Jogos

Os jogos DirectX podem ser executados no PC ou Xbox. Para obter mais informações, consulte [DirectX Graphics and Gaming](/windows/win32/directx).

## <a name="sql-server-database-clients"></a>Clientes de banco de dados SQL Server

Para acessar os bancos de dados SQL Server a partir de código nativo, use ODBC ou OLE DB. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

## <a name="windows-device-drivers"></a>Drivers de dispositivos Windows

Os drivers são componentes de baixo nível que tornam os dados de dispositivos de hardware acessíveis a aplicativos e outros componentes do sistema operacional. Para obter mais informações, consulte [O Kit de Driver do Windows (WDK)](/windows-hardware/drivers/index).

## <a name="windows-services"></a>Serviços do Windows

Um *serviço* do Windows é um programa que pode ser executado em segundo plano com pouca ou nenhuma interação do usuário. Esses programas são chamados *de daemons* em sistemas UNIX. Para obter mais informações, consulte [Serviços](/windows/win32/services/services).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

O Visual Studio inclui a C Runtime Library (CRT), a C++ Standard Library e outras bibliotecas específicas da Microsoft. A maioria das pastas que contêm arquivos de cabeçalho para essas bibliotecas estão localizadas no diretório de instalação do Visual Studio sob a pasta \VC\. Os arquivos de cabeçalho do Windows e CRT são encontrados na pasta de instalação do Windows SDK.

O [gerenciador de pacotes Vcpkg](../build/vcpkg.md) permite que você instale convenientemente centenas de bibliotecas de código aberto de terceiros para windows.

As bibliotecas da Microsoft incluem:

- Microsoft Foundation Classes (MFC): uma estrutura orientada por objeto para criação de programas tradicionais do Windows (especialmente aplicativos empresariais) que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [MFC Desktop Applications](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): uma biblioteca auxiliar potente para criação de componentes COM. Para obter mais informações, consulte [ATL COM Desktop Components](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Runtime de Simultaneidade: uma biblioteca que simplifica o trabalho da programação paralela e assíncrona para dispositivos de vários e muitos núcleos. Para obter mais informações, consulte [Runtime de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o Windows SDK como um componente da carga de trabalho C++ Desktop, que permite o desenvolvimento de aplicativos Universais do Windows. Para desenvolver aplicativos UWP, você precisa da versão do Windows 10 do Windows SDK. Para obter informações, consulte [O SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivo Windows SDK](https://developer.microsoft.com/windows/downloads/sdk-archive)).

**Arquivos de programa (x86)\Windows Kits** é o local padrão para todas as versões do Windows SDK que você instalou.

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte [Começar a desenvolver com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio)e Visão Geral do desenvolvimento [c++ no Visual Studio](../overview/overview-of-cpp-development.md).

## <a name="in-this-section"></a>Nesta seção

|Title|Descrição|
|-----------|-----------------|
|[Passo a passo: Criando um programa C++ padrão](walkthrough-creating-a-standard-cpp-program-cpp.md)| Crie um aplicativo de console do Windows.|
|[Passo a passo: criando aplicativos da área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo de desktop nativo do Windows.|
|[Assistente da Área de Trabalho do Windows](windows-desktop-wizard.md)|Use o assistente para criar novos projetos do Windows.|
|[ATL (Active Template Library)](../atl/atl-com-desktop-components.md)|Use a biblioteca ATL para criar componentes COM em C++.|
|[MFC (Microsoft Foundation Classes)](../mfc/mfc-desktop-applications.md)|Use mfc para criar aplicativos Windows grandes ou pequenos com diálogos e controles|
|[Classes Compartilhadas ATL e MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Use classes como CString que são compartilhadas em ATL e MFC.|
|[Acesso a dados](../data/data-access-in-cpp.md)| OLE DB e ODBC|
|[Texto e Cordas](../text/text-and-strings-in-visual-cpp.md)|Vários tipos de strings no Windows.|
|[Recursos para criar um jogo usando directx](resources-for-creating-a-game-using-directx.md)
|[Como usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|SDK do Windows|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de strings e outros recursos a um aplicativo de desktop.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para criação de jogos em C++.|
|[Como usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém etapas para configurar seu projeto para construir usando o SDK do Windows 10.|
|[Como implantar aplicativos da área de trabalho nativos](deploying-native-desktop-applications-visual-cpp.md)|Implantar aplicativos nativos no Windows.|

## <a name="related-articles"></a>Artigos relacionados

|Title|Descrição|
|-----------|-----------------|
|[C++ em Visual Studio](../overview/visual-cpp-in-visual-studio.md)|Tópico pai para conteúdo de desenvolvedor Visual C++.|
[.NET Desenvolvimento com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|Crie invólucros para bibliotecas C++ nativas que o permitam a comunicação com aplicativos e componentes .NET.|
|[Extensões de componentes para .NET e UWP](../extensions/component-extensions-for-runtime-platforms.md)|Referência para elementos de sintaxe compartilhados por C++/CX e C++/CLI.|
|[Aplicativos universais do Windows (C++)](../cppcx/universal-windows-apps-cpp.md)|Escreva aplicativos UWP usando C++/CX ou Windows Runtime Template Library (WRL).|
|[Atributos C++ para COM e .NET](attributes/cpp-attributes-com-net.md)|Atributos não padrão para programação somente do Windows usando .NET ou COM.|
