---
title: Visão geral de programação do Windows no C++
ms.date: 11/15/2018
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
ms.openlocfilehash: b33236df6e4c7f679ff1dd9f9f8bc409c86e011a
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693849"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Há várias categorias de aplicativos do Windows que você pode criar com o C++. Cada um tem seu próprio modelo de programação e o conjunto de bibliotecas específicas do Windows, mas a biblioteca padrão C++, bem como bibliotecas de C++ de terceiros podem ser usadas em qualquer um deles. 

## <a name="command-line-console-applications"></a>Aplicativos de linha de comando (console)

Aplicativos de console C++ executar da linha de comando na janela do console e podem exibir a saída de texto apenas. Para obter mais informações, consulte [aplicativos de Console](console-applications-in-visual-cpp.md).
 
## <a name="native-desktop-client-applications"></a>Aplicativos cliente nativos de área de trabalho

O termo *aplicativo cliente de área de trabalho nativo* refere-se a um aplicativo C ou C++ em janelas que usa as APIs de Win32 original do Windows para acessar o sistema operacional. Essas APIs são eles próprios escritos principalmente em C. Ao criar esse tipo de aplicativo, você tem a opção de programar diretamente em um loop de mensagem do estilo C que processa eventos do sistema operacional ou usando *Microsoft Foundation Classes* (MFC), uma biblioteca C++ que encapsula o Win32 de forma que seja um pouco orientada a objeto. Uma abordagem não é considerada "moderno" em comparação com a plataforma Universal do Windows (veja abaixo), mas ambos ainda são totalmente suportados e ter milhões de linhas de código em execução no mundo de hoje.

Para se familiarizar com o tradicional de programação de C++ do Windows, consulte [começar com o C++ e o Win32](/windows/desktop/LearnWin32/learn-to-program-for-windows). Depois de ter alguma compreensão do Win32, será mais fácil saber mais sobre [aplicativos de área de trabalho do MFC](/mfc/mfc-desktop-applications). Para obter um exemplo de um aplicativo tradicional da área de trabalho do C++ que usa gráficos sofisticados, consulte [Hilo: desenvolvendo aplicativos do C++ para Windows](https://msdn.microsoft.com/library/windows/desktop/ff708696.aspx).

### <a name="c-or-net"></a>C++ ou .NET? 

Para cenários de aplicativos da área de trabalho máximo (em outras palavras, não direcionamento UWP), considere o uso de C# e do .NET. Isso ocorre porque a programação do .NET é geralmente menos complexa, propensa a erros e tem uma API orientada a objeto mais moderna que MFC ou Win32. Na maioria dos casos, seu desempenho é mais do que adequado. O Windows Presentation Foundation (WPF) para gráficos sofisticados recursos do .NET, e você pode consumir Win32, bem como o Windows moderna API do tempo de execução (consulte UWP abaixo). Como regra geral, é recomendável usar o C++ para aplicativos da área de trabalho, quando você precisar de:

- controle preciso sobre o uso de memória
- a máxima economia no consumo de energia
- uso da GPU para computação geral
- acesso ao DirectX
- uso intenso de bibliotecas C++ padrão

## <a name="com-components"></a>Componentes COM

Muitas partes do sistema operacional Windows são baseados na COM Component Object Model () que define um padrão binário que permite que o componente a ser consumido de aplicativos cliente escritos em qualquer linguagem de computador. No C++, você pode usar a biblioteca ATL (Active Template) para simplificar o trabalho de criar seus próprios componentes COM. Para obter mais informações, consulte [modelo de COM (Component Object)](/windows/desktop/com/component-object-model--com--portal) e [componentes de área de trabalho COM ATL](../atl/atl-com-desktop-components.md).

## <a name="windows-universal-apps"></a>Aplicativos Universais para Windows

A Universal Windows Platform (UWP) é a API do Windows moderno. Aplicativos UWP executados em qualquer dispositivo Windows 10, usam XAML para a interface do usuário e são totalmente habilitados para toque. Para obter mais informações sobre a UWP, consulte [o que é um aplicativo de plataforma Universal do Windows (UWP)?](/windows/uwp/get-started/whats-a-uwp) e [guia para aplicativos universais do Windows](/windows/uwp/get-started/universal-application-platform-guide).

O suporte de C++ original para a UWP é formada por de (1) C + + c++ /CX, um dialeto do C++ com extensões de sintaxe ou (2) o Windows Runtime Library (WRL) que se baseia no padrão C++ e COM. Ambos os C + + c++ /CLI CX e WRL ainda são suportados. Para novos projetos, recomendamos [C + + c++ /CLI WinRT](/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt) que se baseia inteiramente no C++ padrão e fornece um desempenho mais rápido. 

Para Windows 10, você pode empacotar seu aplicativo da área de trabalho do C++ existente como-é para implantação por meio do Microsoft Store. Para obter mais informações, consulte [empacotar aplicativos da área de trabalho (ponte de Desktop)](/windows/uwp/porting/desktop-to-uwp-root).

## <a name="games"></a>Jogos

Jogos do DirectX podem executar no PC ou Xbox. Para obter mais informações, consulte [gráficos e jogos DirectX](/windows/desktop/directx).

## <a name="net-wrappers-for-c-libraries"></a>Wrappers do .NET para bibliotecas do C++

Você pode usar C + + c++ CLI para criar uma camada de interoperabilidade que permite que o código .NET consumir bibliotecas nativas do C++. Para obter mais informações, consulte [programação do .NET com C + + c++ CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

## <a name="sql-server-database-clients"></a>Clientes do banco de dados do SQL Server

Para acessar bancos de dados SQL do código nativo, use ODBC ou OLE DB. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

## <a name="windows-device-drivers"></a>Drivers de dispositivos Windows

Drivers são componentes de baixo nível que disponibilizar os dados dos dispositivos de hardware a aplicativos e outros componentes do sistema operacional. Para obter mais informações, consulte [Windows Driver Kit (WDK)](/windows-hardware/drivers/index).

## <a name="windows-services"></a>Serviços Windows

Um Windows *serviço* é um programa que pode ser executados em segundo plano com pouca ou nenhuma interação do usuário. No UNIX, eles são chamados *daemons*. Para obter mais informações, consulte [Services](/windows/desktop/services/services).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

Visual Studio inclui a biblioteca de tempo de execução C (CRT), a biblioteca padrão C++ e outras bibliotecas específicas da Microsoft. Incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas estão localizadas no diretório de instalação do Visual Studio na pasta \vc\. ou, no caso de CRT, na pasta de instalação do SDK do Windows.

Você pode usar o [Gerenciador de pacotes Vcpkg](../vcpkg.md) convenientemente instalar centenas de bibliotecas de software livre de terceiros para Windows.

As bibliotecas da Microsoft incluem:

- Microsoft Foundation Classes (MFC): uma estrutura orientada por objeto para criação de programas tradicionais do Windows (especialmente aplicativos empresariais) que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [aplicativos de área de trabalho do MFC](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): uma biblioteca auxiliar potente para criação de componentes COM. Para obter mais informações, consulte [componentes de área de trabalho COM ATL](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Tempo de Execução de Simultaneidade: uma biblioteca que simplifica o trabalho da programação paralela e assíncrona para dispositivos de vários e muitos núcleos. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o SDK do Windows como um componente da carga de trabalho da área de trabalho do C++, que permite o desenvolvimento de aplicativos Windows Universal. Para desenvolver aplicativos da UWP, você precisa ter a versão do Windows 10 do SDK do Windows. Para obter informações, consulte [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivo Windows SDK](https://developer.microsoft.com/windows/downloads/sdk-archive)).

**Programar arquivos (x86) \Windows Kits** é o local padrão para todas as versões do SDK do Windows que você instalou.

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte [comece a desenvolver com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio), e [IDE e ferramentas de desenvolvimento](../ide/ide-and-tools-for-visual-cpp-development.md).

## <a name="in-this-section"></a>Nesta seção
|Título|Descrição|
|-----------|-----------------|
|[Aplicativos da área de trabalho do Windows em C++](desktop-applications-visual-cpp.md)| Como criar aplicativos de desktop tradicionais.|
|[ATL (Active Template Library)](../atl/TOC.md)|Use a biblioteca ATL para criar componentes COM em C++.|
|[MFC (Microsoft Foundation Classes)](../mfc/TOC.md)|Usar o MFC para criar grandes ou pequenos aplicativos do Windows com caixas de diálogo e controles|
|[Classes compartilhadas da ATL e do MFC](../atl-mfc-shared/TOC.md)|Use classes como CString que são compartilhadas em ATL e MFC.|
|[Desenvolvimento .NET com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|Crie wrappers para bibliotecas de C++ nativas que habilitá-lo para a comunicação com aplicativos .NET e componentes.|
|[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)|Referência para elementos de sintaxe compartilhados pelo C + + c++ /CLI CX e C + + / CLI.|
|[Aplicativos universais do Windows (C++)](universal-windows-apps-cpp.md)|Escrever aplicativos UWP usando C + + c++ /CX ou biblioteca de modelos de tempo de execução do Windows (WRL).|
|[Atributos C++ para COM e .NET](attributes/cpp-attributes-com-net.md)|Atributos não padrão para a programação somente para Windows usando o .NET ou COM.|

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Tópico pai para o conteúdo para desenvolvedores do Visual C++.|
