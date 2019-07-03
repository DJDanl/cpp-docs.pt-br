---
title: Visão geral de programação do Windows no C++
ms.date: 07/02/2019
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
ms.openlocfilehash: 1f49c9f8f78f83d6ae991b7427b28f7f5cbf7f0c
ms.sourcegitcommit: 9b904e490b1e262293a602bd1291a8f3045e755b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/03/2019
ms.locfileid: "67552314"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Há várias categorias de aplicativos do Windows que você pode criar com o C++. Cada um tem seu próprio modelo de programação e um conjunto de bibliotecas do Windows, mas o C++ biblioteca padrão e terceiros C++ bibliotecas podem ser usadas em qualquer um deles.

## <a name="command-line-console-applications"></a>Aplicativos de linha de comando (console)

Aplicativos de console C++ executar da linha de comando na janela do console e podem exibir a saída de texto apenas. Para obter mais informações, consulte [aplicativos de Console](console-applications-in-visual-cpp.md).

## <a name="native-desktop-client-applications"></a>Aplicativos cliente nativos de área de trabalho

Um *aplicativo cliente de área de trabalho nativo* é um C ou C++ aplicativo em janelas que usa o nativo original [APIs de C do Windows ou COM Component Object Model () APIs](/windows/desktop/apiindex/windows-api-list) para acessar o sistema operacional. Essas APIs são eles próprios escritos principalmente em C. Há mais de uma maneira de criar um aplicativo de área de trabalho nativo: Você pode programar usando as APIs do Win32 diretamente, usando um loop de mensagem do estilo C que processa eventos do sistema operacional. Ou, você pode programar usando *Microsoft Foundation Classes* (MFC), um pouco orientada a objeto C++ biblioteca que encapsula o Win32. Nem a abordagem é considerada "moderna" comparados para Universal Windows Platform (UWP), mas ambos são ainda tem suporte completo e ter milhões de linhas de código em execução no mundo de hoje. Um aplicativo Win32 que é executado em uma janela exige que o desenvolvedor trabalhar explicitamente com mensagens do Windows dentro de uma função de procedimento do Windows. Apesar do nome, um aplicativo Win32 pode ser compilado como um (x86) 32 bits ou 64 bits (x64) binário. No IDE do Visual Studio, os termos x86 e o Win32 são sinônimos.

Para se familiarizar com o tradicional de programação de C++ do Windows, consulte [começar com o C++ e o Win32](/windows/desktop/LearnWin32/learn-to-program-for-windows). Depois de ter alguma compreensão do Win32, será mais fácil saber mais sobre [aplicativos de área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter um exemplo de um aplicativo tradicional da área de trabalho do C++ que usa gráficos sofisticados, consulte [Hilo: Desenvolvimento de aplicativos do C++ para Windows](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx).

### <a name="c-or-net"></a>C++ ou .NET?

Em geral, programação do .NET no C# é menos complexa, propensa a erros e tem uma API orientada a objeto mais moderna que MFC ou Win32. Na maioria dos casos, seu desempenho é mais do que adequado. O Windows Presentation Foundation (WPF) para gráficos sofisticados recursos do .NET, e você pode consumir Win32 e a API de tempo de execução do Windows moderno. Como regra geral, é recomendável usar o C++ para aplicativos da área de trabalho, quando você precisar de:

- controle preciso sobre o uso de memória
- a máxima economia no consumo de energia
- uso da GPU para computação geral
- acesso ao DirectX
- uso intenso de bibliotecas C++ padrão

Também é possível combinar a potência e a eficiência do C++ com a programação do .NET. Você pode criar uma interface do usuário no C# e usar C++/CLI para permitir que o aplicativo consumir nativo C++ bibliotecas. Para obter mais informações, consulte [programação do .NET com o C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

## <a name="com-components"></a>Componentes COM

O [(COM Component Object Model)](/windows/desktop/com/the-component-object-model) é uma especificação que permite que os programas escritos em linguagens diferentes para se comunicar entre si. Muitos componentes do Windows são implementados como objetos COM e seguem as regras COM padrões para criação de objeto, a descoberta de interface e a destruição de objeto.  Usando objetos COM de aplicativos da área de trabalho do C++ é relativamente simples, mas escrever seu próprio objeto COM é mais avançada. O [biblioteca ATL (Active Template)](../atl/atl-com-desktop-components.md) fornece macros e funções auxiliares que simplificam o desenvolvimento de COM. Para obter mais informações, consulte [componentes de área de trabalho COM ATL](../atl/atl-com-desktop-components.md).

## <a name="universal-windows-platform-apps"></a>Aplicativos da Plataforma Universal do Windows

A Universal Windows Platform (UWP) é a API do Windows moderno. Aplicativos UWP executados em qualquer dispositivo Windows 10, usam XAML para a interface do usuário e são totalmente habilitados para toque. Para obter mais informações sobre a UWP, consulte [o que é um aplicativo de plataforma Universal do Windows (UWP)?](/windows/uwp/get-started/whats-a-uwp) e [guia para aplicativos universais do Windows](/windows/uwp/get-started/universal-application-platform-guide).

Original C++ suporte para UWP consistiu em (1) C++/CX, um dialeto do C++ com extensões de sintaxe, ou (2) a biblioteca de tempo de execução do Windows (WRL), que é baseado no padrão de C++ e COM. Ambos C++/CX e WRL ainda são suportados. Para novos projetos, é recomendável [ C++/WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt), que é totalmente baseado no padrão de C++ e fornece um desempenho mais rápido.

## <a name="desktop-bridge"></a>Ponte de desktop

No Windows 10, empacotar seu aplicativo da área de trabalho existente ou um objeto COM como um aplicativo UWP e adicionar recursos UWP, como toque ou chamar as APIs do conjunto de API do Windows moderno. Você também pode adicionar um aplicativo UWP a uma solução de área de trabalho no Visual Studio e o pacote-los juntos em um único pacote e usam as APIs do Windows para se comunicar entre eles.

Visual Studio 2017 versão 15.4 e posterior lhe permite criar um projeto de pacote de aplicativo do Windows para simplificar bastante o trabalho de empacotamento de aplicativo da área de trabalho existente. Algumas restrições se aplicam a chamadas do registro ou APIs que seu aplicativo da área de trabalho pode usar. No entanto, em muitos casos, você pode criar caminhos de código alternativo para obter funcionalidade semelhante durante a execução em um pacote do aplicativo. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="games"></a>Jogos

Jogos do DirectX podem executar no PC ou Xbox. Para obter mais informações, consulte [gráficos e jogos DirectX](/windows/desktop/directx).

## <a name="sql-server-database-clients"></a>Clientes do banco de dados do SQL Server

Para acessar bancos de dados SQL do código nativo, use ODBC ou OLE DB. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

## <a name="windows-device-drivers"></a>Drivers de dispositivos Windows

Drivers são componentes de baixo nível que disponibilizar os dados dos dispositivos de hardware a aplicativos e outros componentes do sistema operacional. Para obter mais informações, consulte [Windows Driver Kit (WDK)](/windows-hardware/drivers/index).

## <a name="windows-services"></a>Serviços Windows

Um Windows *serviço* é um programa que pode ser executados em segundo plano com pouca ou nenhuma interação do usuário. Esses programas são chamados *daemons* em sistemas UNIX. Para obter mais informações, consulte [Services](/windows/desktop/services/services).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

Visual Studio inclui a biblioteca de tempo de execução C (CRT), a biblioteca padrão C++ e outras bibliotecas específicas da Microsoft. A maioria de incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas está localizada no diretório de instalação do Visual Studio na pasta \vc\.. Os arquivos de cabeçalho do Windows e CRT são encontrados na pasta de instalação do SDK do Windows.

O [Gerenciador de pacotes Vcpkg](../build/vcpkg.md) permite que você instale convenientemente centenas de bibliotecas de software livre de terceiros para Windows.

As bibliotecas da Microsoft incluem:

- Microsoft Foundation Classes (MFC): Uma estrutura orientada a objeto para a criação de programas tradicionais do Windows — especialmente aplicativos empresariais — que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [aplicativos de área de trabalho do MFC](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): Uma biblioteca auxiliar potente para a criação de componentes COM. Para obter mais informações, consulte [componentes de área de trabalho COM ATL](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): Uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Tempo de execução de simultaneidade: Uma biblioteca que simplifica o trabalho de programação paralela e assíncrona para dispositivos com vários núcleos e vários núcleos. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o SDK do Windows como um componente da carga de trabalho da área de trabalho do C++, que permite o desenvolvimento de aplicativos Windows Universal. Para desenvolver aplicativos da UWP, você precisa ter a versão do Windows 10 do SDK do Windows. Para obter informações, consulte [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivo Windows SDK](https://developer.microsoft.com/windows/downloads/sdk-archive)).

**Programar arquivos (x86) \Windows Kits** é o local padrão para todas as versões do SDK do Windows que você tenha instalado.

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte [comece a desenvolver com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio), e [desenvolvimento de visão geral do C++ no Visual Studio](../overview/overview-of-cpp-development.md).

## <a name="in-this-section"></a>Nesta seção
|Título|Descrição|
|-----------|-----------------|
|[Passo a passo: como criar um programa C++ padrão](walkthrough-creating-a-standard-cpp-program-cpp.md)| Crie um aplicativo de console do Windows.|
|[Passo a passo: como criar aplicativos de área de trabalho do Windows (C++)](walkthrough-creating-windows-desktop-applications-cpp.md)|Crie um aplicativo da área de trabalho do Windows nativo.|
|[Assistente da Área de Trabalho do Windows](windows-desktop-wizard.md)|Use o Assistente para criar novos projetos do Windows.|
|[ATL (Active Template Library)](../atl/atl-com-desktop-components.md)|Use a biblioteca ATL para criar componentes COM em C++.|
|[MFC (Microsoft Foundation Classes)](../mfc/mfc-desktop-applications.md)|Usar o MFC para criar grandes ou pequenos aplicativos do Windows com caixas de diálogo e controles|
|[Classes compartilhadas da ATL e do MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Use classes como CString que são compartilhadas em ATL e MFC.|
|[Acesso a dados](../data/data-access-in-cpp.md)| OLE DB e ODBC|
|[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)|Vários tipos de cadeia de caracteres no Windows.|
|[Recursos para criar um jogo usando DirectX](resources-for-creating-a-game-using-directx.md)
|[Como: usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|SDK do Windows|
|[Trabalhando com arquivos de recurso](working-with-resource-files.md)|Como adicionar imagens, ícones, tabelas de cadeia de caracteres e outros recursos para um aplicativo de desktop.|
|[Recursos para criar um jogo usando DirectX (C++)](resources-for-creating-a-game-using-directx.md)|Links para conteúdo para a criação de jogos em C++.|
|[Como: usar o SDK do Windows 10 em um aplicativo da área de trabalho do Windows](how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém as etapas para configurar seu projeto compilar usando o SDK do Windows 10.|
|[Como implantar aplicativos da área de trabalho nativos](deploying-native-desktop-applications-visual-cpp.md)|Implante aplicativos nativos no Windows.|

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)|Tópico pai para o conteúdo para desenvolvedores do Visual C++.|
[Desenvolvimento .NET com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|Crie wrappers para bibliotecas de C++ nativas que habilitá-lo para a comunicação com aplicativos .NET e componentes.|
|[Extensões de componentes para .NET e UWP](../extensions/component-extensions-for-runtime-platforms.md)|Referência para elementos de sintaxe compartilhados pelo C++/CX e C++/CLI.|
|[Aplicativos universais do Windows (C++)](../cppcx/universal-windows-apps-cpp.md)|Escrever aplicativos UWP usando C++/CX ou biblioteca de modelos de tempo de execução do Windows (WRL).|
|[Atributos C++ para COM e .NET](attributes/cpp-attributes-com-net.md)|Atributos não padrão para a programação somente para Windows usando o .NET ou COM.|
