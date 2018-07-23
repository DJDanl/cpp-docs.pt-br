---
title: Visão geral da programação do Windows em C++ | Microsoft Docs
ms.custom: ''
ms.date: 04/06/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2096c36ec24c1ca7e20c789b8a1eb8c24589ccc1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881657"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Você pode usar o Visual C++ para gravar muitos tipos de programas que são executados em um computador Windows (x 86, x64 ou ARM), em um servidor do Windows, na nuvem ou Xbox. Programas bem escritos em C++ têm essas qualidades:
- requisitos de memória eficiente
- econômico no consumo de energia 
- capaz de aproveitar ao máximo de dispositivos com vários núcleos e vários núcleos
- capaz de executar a computação geral na unidade de processamento de gráficos (GPGPU)   
- é possível tirar proveito das outros recentes avanços de hardware.

Há várias categorias de aplicativos do Windows que você pode desenvolver com o Visual C++. Essas categorias tem modelos de programação diferentes ou modelos de aplicativo, que foram introduzidos ao longo dos anos. Cada modelo usa APIs e bibliotecas diferentes para fornecer acesso à plataforma e criar interfaces de usuário como janelas e caixas de diálogo. Biblioteca padrão C++, bem como bibliotecas de terceiros podem ser usadas em qualquer uma dessas categorias, com algumas restrições para UWP.

- [Aplicativos universais do Windows](#BK_WindowsUniversal). A terceira categoria de aplicativos do Windows foi introduzida com o Windows 8 e continua o suporte para essa categoria de aplicativos no Windows 10. Esses aplicativos são geralmente chamados de apenas como "aplicativos do Windows" e incluem aplicativos de desktop e portáteis que uma variedade de dispositivos de destino. Você pode escrever esses aplicativos em C + + CX, um dialeto do C++ que inclui suporte para o desenvolvimento de tempo de execução do Windows ou em C++ padrão com usando a biblioteca de tempo de execução do Windows (WRL). Esses aplicativos foram originalmente projetados para ser executado em tela inteira, embora no Windows 10, os usuários têm a opção de executá-los em uma janela de área de trabalho. Esses aplicativos são orientados para toque, mas é fácil de usar o mouse para funcionar se você preferir ou se não houver uma tela sensível ao toque. Esses aplicativos são distribuídos da Microsoft Store, um fato que levou a eles que está sendo chamado "Store" aplicativos.

Aplicativos UWP são capazes de executar em todos os dispositivos Windows 10, como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles sejam capazes de executar como uma janela de área de trabalho, em vez de sempre em execução em tela inteira. Esses aplicativos também podem executar o Xbox e em dispositivos futuras.  Aplicativos UWP executados em Windows Runtime, que fornece uma interface para os dispositivos de hardware diferentes que têm suporte no Windows, serviços e elementos de interface do usuário.  

Você pode escrever aplicativos UWP em C + + CX, um dialeto do C++, você pode usar o [C + + biblioteca WinRT](https://moderncpp.com/)para alguns cenários. Aplicativos UWP compilados para código nativo e têm uma interface de usuário XAML ou usam o DirectX. Componentes de tempo de execução do Windows que são escritos em código nativo que UWP aplicativos escritos em outras linguagens podem consumir. Para obter mais informações, consulte [criar um aplicativo de plataforma Universal do Windows em C++](http://go.microsoft.com/fwlink/?LinkID=534976), [criar seu primeiro jogo UWP usando DirectX](http://go.microsoft.com/fwlink/p/?LinkId=244656), e [componentes de criação de tempo de execução do Windows em C++](http://go.microsoft.com/fwlink/p/?LinkId=244658).

   Essa categoria inclui também usar C++ para componentes principais e computacional código no contexto do servidor e a programação de nuvem. Às vezes, o código de alto desempenho no núcleo de um aplicativo em nuvem ou o servidor está escrito em C++ para maximizar o desempenho. Você pode compilar esse código em uma DLL e usá-lo de c# ou Visual Basic.

- **Aplicativos do .NET framework**. A maioria dos aplicativos do .NET Framework são escritos em c# ou Visual Basic, mas você também pode C + + CLI (a opção de compilador /clr no Visual C++). É recomendável usar C + + CLI para uma camada de interoperabilidade mínimo em um aplicativo maior que inclui o código gerenciado e nativo.

##  <a name="BK_WindowsUniversal"></a> Aplicativos universais do Windows

Com o Windows 10, aplicativos são capazes de executar em todos os dispositivos Windows 10, como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles sejam capazes de executar como uma janela de área de trabalho, em vez de sempre em execução em tela inteira. Esses aplicativos também podem executar o Xbox e em dispositivos futuras.  O modelo de programação para os dois tipos de aplicativos é diferente de aplicativos de desktop do Win32. Esses aplicativos do Windows é executado em uma interface e o tempo de execução do Windows, que fornece os elementos de interface do usuário, serviços essenciais para esses aplicativos e fornece, para os dispositivos de hardware diferentes que têm suporte. Esses aplicativos compilados para código nativo e têm uma interface de usuário XAML ou usam DirectX. Você também pode escrever componentes de tempo de execução do Windows em código nativo que outros aplicativos do Windows podem consumir — isso inclui aplicativos que são escritos em c#, Visual Basic ou JavaScript. Para obter mais informações, consulte [criar um aplicativo "Hello world" de UWP em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp), [criar um jogo UWP simple com DirectX](/windows/uwp/gaming/tutorial--create-your-first-uwp-directx-game), e [componentes de criação de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

> [!TIP]
> Para Windows 10, você pode usar o conversor de aplicativo de área de trabalho para empacotar o aplicativo de área de trabalho existente para implantação por meio da Microsoft Store. Para obter mais informações, consulte [Usando o tempo de execução do Visual C++ em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [Traga seu aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) com a Ponte de Desktop](https://msdn.microsoft.com/en-us/windows/uwp/porting/desktop-to-uwp-root).

Para obter exemplos de plataforma Universal do Windows, consulte [exemplos Universal do Windows no GitHub](https://github.com/Microsoft/Windows-universal-samples)

Se você tiver um projeto do Windows 8.1 existentes e não queira a porta para o Windows 10, consulte [portando para a plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md). Se você tiver bibliotecas da área de trabalho de Win32 clássicas existentes e de código que você deseja integrar um aplicativo UWP, consulte [como: uso de código C++ existente em um aplicativo de plataforma Universal do Windows](../porting/how-to-use-existing-cpp-code-in-a-universal-windows-platform-app.md).

Para obter mais informações sobre UWP em geral, consulte [o que é um aplicativo do Windows UWP (plataforma Universal)?](/windows/uwp/get-started/whats-a-uwp).

Para obter mais informações sobre todos esses conceitos, consulte [guia para aplicativos universais do Windows](http://go.microsoft.com/fwlink/p/?linkid=534605).

##  <a name="BK_Native"></a> Aplicativos de desktop e servidor

Para saber as Noções básicas de criação de aplicativos de cliente do Windows para a área de trabalho, consulte [o desenvolvimento de aplicativos do Windows em C++](http://msdn.microsoft.com/vstudio//hh304489) e [Introdução à programação do Windows em C++](http://msdn.microsoft.com/library/windows/desktop/ff381398\(v=vs.85\).aspx).

No Windows 10, você pode usar o Visual C++ para criar vários tipos de programas de área de trabalho:

- Aplicativos e utilitários de linha de comando. Para obter mais informações, consulte [aplicativos de Console](../windows/console-applications-in-visual-cpp.md).

- Aplicativos de consumidor que têm interfaces de usuário gráficas sofisticadas. Para obter mais informações, consulte [Hilo: desenvolvendo aplicativos do C++ para Windows](http://go.microsoft.com/fwlink/p/?LinkId=256417)

- Aplicativos de empresa e a linha de negócios que são executados no .NET Framework. A maioria dos aplicativos do .NET Framework são gravados em c# ou Visual Basic. Você pode usar C + + CLI para criar camadas de interoperabilidade que permitem que o código .NET consumir bibliotecas nativas C++. Para obter mais informações, consulte [programação .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

- Clientes do banco de dados SQL que são executados em código nativo. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

- Suplementos para aplicativos Microsoft Office. Para obter mais informações, consulte [criando um Add-in do C++ para o Outlook 2010](http://go.microsoft.com/fwlink/p/?LinkId=256420)

- Drivers de dispositivo. Para obter mais informações, consulte [Windows Driver Kit (WDK)](http://go.microsoft.com/fwlink/p/?LinkId=256421)

- Serviços do Windows. Para obter mais informações, consulte [Introdução a aplicativos de serviço do Windows](/dotnet/framework/windows-services/introduction-to-windows-service-applications).

Você pode usar o Visual C++ para empacotar quase todos os tipos de funcionalidade personalizada de alto desempenho nas DLLs do Win32 ou DLLs COM que podem ser consumidas pelos aplicativos do C++ ou pelos aplicativos que são escritos em outras linguagens, por exemplo, C# ou Visual Basic. Para obter mais informações sobre as DLLs do WIn32, consulte [DLLs no Visual C++](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre o desenvolvimento COM, consulte [modelo COM (Component Object)](https://msdn.microsoft.com/library/windows/desktop/ms680573).

## <a name="games"></a>Jogos

Jogos do DirectX podem executar no computador ou Xbox. Para obter mais informações, consulte [DirectX Developer Center](http://go.microsoft.com/fwlink/p/?LinkId=256418).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

Visual C++ inclui a biblioteca de tempo de execução do C (CRT), a biblioteca padrão C++ e outras bibliotecas específicas da Microsoft. Incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas estão localizadas no diretório de instalação do Visual Studio na pasta \VC\ ou, no caso de CRT, na pasta de instalação do SDK do Windows.   

Você pode usar o [Gerenciador de pacote Vcpkg](../vcpkg.md) convenientemente instalar centenas de bibliotecas de código-fonte aberto de terceiros para Windows.

As bibliotecas Microsoft incluem:

- Microsoft Foundation Classes (MFC): uma estrutura orientada por objeto para criação de programas tradicionais do Windows (especialmente aplicativos empresariais) que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): uma biblioteca auxiliar potente para criação de componentes COM. Para obter mais informações, consulte [componentes de área de trabalho do ATL COM](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Tempo de Execução de Simultaneidade: uma biblioteca que simplifica o trabalho da programação paralela e assíncrona para dispositivos de vários e muitos núcleos. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o SDK do Windows como um componente da carga de trabalho de área de trabalho do C++ que permite o desenvolvimento de aplicativos Universal do Windows. Para desenvolver aplicativos UWP, é necessário ter a versão do Windows 10 do SDK do Windows. Para obter informações, consulte [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivamento do SDK do Windows](https://developer.microsoft.com/windows/downloads/sdk-archive)). 

**Programa arquivos (x86) \Windows Kits** é o local padrão para todas as versões do SDK do Windows que você instalou.

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte [começar a desenvolver com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio), e [IDE e ferramentas de desenvolvimento](../ide/ide-and-tools-for-visual-cpp-development.md).

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Tópico pai para o conteúdo de desenvolvedor do Visual C++.|
