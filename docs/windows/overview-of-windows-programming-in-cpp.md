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
ms.openlocfilehash: b66d6d3a7da6c9e3084ce2ef6fa18922e015a459
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42604273"
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Você pode usar o Visual C++ para escrever muitos tipos de programas que são executados em um PC Windows (x x86, x64 ou ARM), em um servidor Windows, na nuvem ou no Xbox. Programas bem escritos em C++ têm essas qualidades:
- eficiente para requisitos de memória
- econômicos em consumo de energia 
- capaz de aproveitar ao máximo de dispositivos de vários núcleos e vários núcleos
- capaz de fazer a computação geral na unidade de processamento gráfico GPGPU)  
- é possível tirar proveito de outros avanços recentes no hardware.

Há várias categorias de aplicativos do Windows que você pode desenvolver com o Visual C++. Essas categorias têm modelos de programação diferentes ou modelos de aplicativo, que foram introduzidos ao longo dos anos. Cada modelo usa diferentes bibliotecas e APIs para fornecer acesso à plataforma e criar interfaces do usuário, como janelas e caixas de diálogo. A biblioteca padrão C++, bem como bibliotecas de terceiros podem ser usadas em qualquer uma dessas categorias, com algumas restrições para UWP.

- [Aplicativos universais do Windows](#BK_WindowsUniversal). A terceira categoria de aplicativos do Windows foi introduzida com o Windows 8 e o suporte para essa categoria de aplicativos continua no Windows 10. Esses aplicativos geralmente são chamados apenas como "aplicativos do Windows" e incluem aplicativos de área de trabalho e móveis que se destinam a uma variedade de dispositivos. Você pode escrever esses aplicativos em C + + c++ /CX, um dialeto do C++ que inclui suporte para o desenvolvimento de tempo de execução do Windows ou no C++ padrão com usando a biblioteca de tempo de execução do Windows (WRL). Esses aplicativos foram originalmente criados para executar em tela inteira, embora no Windows 10, os usuários têm a opção de executá-los em uma janela da área de trabalho. Esses aplicativos são orientados a toque, mas é fácil de usar o mouse para operar se os usuários preferem ou se uma tela sensível ao toque não está disponível. Esses aplicativos são distribuídos da Microsoft Store, um fato que levou a eles que está sendo chamado "Store" de aplicativos.

Aplicativos UWP são capazes de executar em todos os dispositivos Windows 10, como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles podem ser executadas como uma janela da área de trabalho, em vez de sempre em execução em tela inteira. Esses aplicativos também podem executar no Xbox e em dispositivos futuros.  Aplicativos UWP são executados no tempo de execução do Windows, que fornece uma interface para os dispositivos de hardware diferentes que têm suporte no Windows, serviços e os elementos de interface do usuário.

Você pode escrever aplicativos UWP no C + + c++ /CLI CX, um dialeto do C++, você pode usar o [C + + c++ /CLI biblioteca WinRT](https://moderncpp.com/)para alguns cenários. Aplicativos UWP compilados para código nativo e tem uma interface do usuário XAML ou usam o DirectX. Componentes de tempo de execução do Windows que são escritos em código nativo que aplicativos UWP escritos em outras linguagens podem consumir. Para obter mais informações, consulte [criar um aplicativo da plataforma Universal do Windows em C++](http://go.microsoft.com/fwlink/?LinkID=534976), [crie seu primeiro jogo UWP usando o DirectX](http://go.microsoft.com/fwlink/p/?LinkId=244656), e [componentes de criação de tempo de execução do Windows em C++](http://go.microsoft.com/fwlink/p/?LinkId=244658).

   Essa categoria também inclui usando C++ para componentes principais e código computacional no contexto do servidor e de programação em nuvem. Às vezes, o código de alto desempenho a essência de um servidor ou aplicativo em nuvem é escrito em C++ para maximizar o desempenho. Você pode compilar esse código em uma DLL e usá-lo no c# ou Visual Basic.

- **Aplicativos do .NET framework**. A maioria dos aplicativos do .NET Framework são escritos em c# ou Visual Basic, mas você também pode C + + c++ CLI (o `/clr` opção de compilador no Visual C++). É recomendável usar C + + c++ CLI para uma camada de interoperabilidade mínimo em um aplicativo maior que inclui o código gerenciado e nativo.

##  <a name="BK_WindowsUniversal"></a> Aplicativos universais do Windows

Com o Windows 10, os aplicativos são capazes de executar em todos os dispositivos Windows 10, como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles podem ser executadas como uma janela da área de trabalho, em vez de sempre em execução em tela inteira. Esses aplicativos também podem executar no Xbox e em dispositivos futuros.  O modelo de programação para os dois tipos de aplicativos é diferente dos aplicativos de desktop do Win32. Esses aplicativos do Windows executados em uma interface e o tempo de execução do Windows, que fornece os elementos de interface do usuário, serviços essenciais para esses aplicativos e fornece, para os dispositivos de hardware diferentes que têm suporte. Esses aplicativos compilados para código nativo e tem uma interface do usuário XAML ou usam o DirectX. Você também pode escrever componentes do Windows Runtime em código nativo que outros aplicativos do Windows podem consumir — isso inclui aplicativos que são escritos em c#, Visual Basic ou JavaScript. Para obter mais informações, consulte [criar um aplicativo "Hello world" da UWP em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp), [criar um jogo UWP simples com o DirectX](/windows/uwp/gaming/tutorial--create-your-first-uwp-directx-game), e [componentes de criação de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

> [!TIP]
> Para Windows 10, você pode usar o Desktop App Converter para empacotar o aplicativo de área de trabalho existente para implantação por meio do Microsoft Store. Para obter mais informações, consulte [Usando o tempo de execução do Visual C++ em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [Traga seu aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) com a Ponte de Desktop](https://msdn.microsoft.com/windows/uwp/porting/desktop-to-uwp-root).

Para obter exemplos de plataforma Universal do Windows, consulte [exemplos Universal do Windows no GitHub](https://github.com/Microsoft/Windows-universal-samples)

Se você tiver um projeto do Windows 8.1 e deseja portá-lo para o Windows 10 existentes, consulte [portabilidade para a plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md). Se você tiver bibliotecas da área de trabalho de Win32 clássicas existentes e código que você deseja integrar um aplicativo UWP, consulte [como: uso de código C++ existente em um aplicativo de plataforma Universal do Windows](../porting/how-to-use-existing-cpp-code-in-a-universal-windows-platform-app.md).

Para obter mais informações sobre a UWP em geral, consulte [o que é um aplicativo de plataforma Universal do Windows (UWP)?](/windows/uwp/get-started/whats-a-uwp).

Para obter mais informações sobre todos esses conceitos, consulte [guia para aplicativos universais do Windows](http://go.microsoft.com/fwlink/p/?linkid=534605).

##  <a name="BK_Native"></a> Aplicativos de área de trabalho e servidor

Para aprender as Noções básicas de criação de aplicativos de cliente do Windows para a área de trabalho, consulte [desenvolvimento de aplicativos do Windows em C++](http://msdn.microsoft.com/vstudio//hh304489) e [Introdução à programação do Windows em C++](http://msdn.microsoft.com/library/windows/desktop/ff381398\(v=vs.85\).aspx).

No Windows 10, você pode usar o Visual C++ para criar vários tipos de programas da área de trabalho:

- Aplicativos e utilitários de linha de comando. Para obter mais informações, consulte [aplicativos de Console](../windows/console-applications-in-visual-cpp.md).

- Aplicativos de consumidor que têm interfaces de usuário gráficas sofisticadas. Para obter mais informações, consulte [Hilo: desenvolvendo aplicativos do C++ para Windows](http://go.microsoft.com/fwlink/p/?LinkId=256417)

- Aplicativos empresariais e de linha de negócios que são executados no .NET Framework. A maioria dos aplicativos do .NET Framework são escritos em c# ou Visual Basic. Você pode usar C + + c++ CLI para criar camadas de interoperabilidade que permitem que o código .NET consumir bibliotecas nativas do C++. Para obter mais informações, consulte [programação do .NET com C + + c++ CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

- Clientes do banco de dados SQL que são executados em código nativo. Para obter mais informações, consulte [SQL Server Native Client](/sql/relational-databases/native-client/odbc/sql-server-native-client-odbc).

- Suplementos para aplicativos Microsoft Office. Para obter mais informações, consulte [criando um Add-in C++ para o Outlook 2010](http://go.microsoft.com/fwlink/p/?LinkId=256420)

- Drivers de dispositivo. Para obter mais informações, consulte [Windows Driver Kit (WDK)](http://go.microsoft.com/fwlink/p/?LinkId=256421)

- Serviços do Windows. Para obter mais informações, consulte [Introdução aos aplicativos de serviço do Windows](/dotnet/framework/windows-services/introduction-to-windows-service-applications).

Você pode usar o Visual C++ para empacotar quase todos os tipos de funcionalidade personalizada de alto desempenho nas DLLs do Win32 ou DLLs COM que podem ser consumidas pelos aplicativos do C++ ou pelos aplicativos que são escritos em outras linguagens, por exemplo, C# ou Visual Basic. Para obter mais informações sobre DLLs do WIn32, consulte [DLLs no Visual C++](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre o desenvolvimento COM, consulte [(COM Component Object Model)](https://msdn.microsoft.com/library/windows/desktop/ms680573).

## <a name="games"></a>Jogos

Jogos do DirectX podem executar no PC ou Xbox. Para obter mais informações, consulte [Central de desenvolvedores do DirectX](http://go.microsoft.com/fwlink/p/?LinkId=256418).

## <a name="sdks-libraries-and-header-files"></a>SDKs, bibliotecas e arquivos de cabeçalho

Visual C++ inclui a biblioteca de tempo de execução C (CRT), a biblioteca padrão C++ e outras bibliotecas específicas da Microsoft. Incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas estão localizadas no diretório de instalação do Visual Studio na pasta \vc\. ou, no caso de CRT, na pasta de instalação do SDK do Windows.

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

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Tópico pai para o conteúdo para desenvolvedores do Visual C++.|