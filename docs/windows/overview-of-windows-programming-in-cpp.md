---
title: "Visão geral da programação do Windows em C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/27/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9bf25d8f3653d2146774efd333daff74a5fb33e2
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="overview-of-windows-programming-in-c"></a>Visão geral de programação do Windows no C++

Você pode usar o Visual C++ para escrever uma ampla variedade de programas que são executados em um PC Windows (x86, x64 ou ARM), em um servidor Windows, na nuvem ou no Xbox. Os programas do C++ bem escritos são rápidos, eficientes, econômicos em consumo de energia, além de serem capazes de aproveitar todas as vantagens de dispositivos com vários e muitos núcleos, GPGPU (computação geral na unidade de processamento gráfico) e outros avanços recentes em hardware.

Há várias categorias de aplicativos do Windows que você pode desenvolver com o Visual C++. Essas categorias tem modelos de programação diferentes ou modelos de aplicativo, o que significa que eles usam bibliotecas diferentes e APIs que fornecem acesso à plataforma e fornecem a interface do usuário.

- [Aplicativos universais do Windows](#BK_WindowsUniversal). A terceira categoria de aplicativos do Windows foi introduzida com o Windows 8 e continua o suporte para essa categoria de aplicativos no Windows 10. Esses aplicativos são geralmente chamados de apenas como "aplicativos do Windows" e incluem aplicativos de desktop e portáteis que uma variedade de dispositivos de destino. Você pode escrever esses aplicativos em C + + CX, um dialeto do C++ que inclui suporte para o desenvolvimento de tempo de execução do Windows ou em C++ padrão com usando a biblioteca de tempo de execução do Windows (WRL). Esses aplicativos foram originalmente projetados para ser executado em tela inteira, embora no Windows 10, os usuários têm a opção de executá-los em uma janela de área de trabalho. Esses aplicativos são orientados para toque, mas é fácil de usar o mouse para funcionar se você preferir ou se não houver uma tela sensível ao toque. Esses aplicativos são distribuídos da Windows Store, um fato que levou a eles que está sendo chamado "Aplicativos da Windows Store".

- [Área de trabalho, servidor e aplicativos de nuvem e jogos](#BK_Native). Essa categoria inclui aplicativos de área de trabalho do Windows, às vezes chamados de aplicativos Win32 desde que esses aplicativos estavam usando a API do Win32 no antes do Windows 8, todos os aplicativos do Windows foram nessa categoria. Aplicativos nesta categoria podem usar MFC para uma interface de usuário e ATL para interagir com componentes do Windows, que geralmente são objetos COM.

   Aplicativos, componentes ou bibliotecas escritas com C++ padrão também se encaixam nesta categoria.

   Essa categoria inclui também usar C++ para componentes principais e computacional código no contexto do servidor e a programação de nuvem. Às vezes, o código de alto desempenho no núcleo de um aplicativo em nuvem ou o servidor está escrito em C++ para maximizar o desempenho. Você pode compilar esse código em uma DLL e usá-lo de c# ou Visual Basic.

- **Aplicativos do .NET framework**. A maioria dos aplicativos do .NET Framework são escritos em c# ou Visual Basic, mas você também pode C + + CLI (a opção de compilador /clr no Visual C++). É recomendável usar C + + CLI para uma camada de interoperabilidade mínimo em um aplicativo maior que inclui o código gerenciado e nativo.

##  <a name="BK_WindowsUniversal"></a>Aplicativos universais do Windows

Com o Windows 10, aplicativos são capazes de executar em todos os dispositivos Windows 10, como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles sejam capazes de executar como uma janela de área de trabalho, em vez de sempre em execução em tela inteira. Esses aplicativos também podem executar o Xbox e em dispositivos futuras.  O modelo de programação para os dois tipos de aplicativos é diferente de aplicativos de desktop do Win32. Esses aplicativos do Windows é executado em uma interface e o tempo de execução do Windows, que fornece os elementos de interface do usuário, serviços essenciais para esses aplicativos e fornece, para os dispositivos de hardware diferentes que têm suporte. Esses aplicativos compilados para código nativo e têm uma interface de usuário XAML ou usam DirectX. Você também pode escrever componentes de tempo de execução do Windows em código nativo que outros aplicativos do Windows podem consumir — isso inclui aplicativos que são escritos em c#, Visual Basic ou JavaScript. Para obter mais informações, consulte [criar um aplicativo de plataforma Universal do Windows em C++](http://go.microsoft.com/fwlink/p/?linkid=534976), [criar seu primeiro jogo UWP usando DirectX](http://go.microsoft.com/fwlink/p/?LinkId=244656), e [componentes de criação de tempo de execução do Windows em C++](http://go.microsoft.com/fwlink/p/?LinkId=244658).

> [!TIP]
> Para Windows 10, você pode usar o conversor de aplicativo de área de trabalho para empacotar o aplicativo de área de trabalho existente para implantação por meio da Windows Store. Para obter mais informações, consulte [Usando o tempo de execução do Visual C++ em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [Traga seu aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) com a Ponte de Desktop](https://msdn.microsoft.com/en-us/windows/uwp/porting/desktop-to-uwp-root).

Para obter exemplos de plataforma Universal do Windows, consulte [exemplos Universal do Windows no GitHub](https://github.com/Microsoft/Windows-universal-samples)

Se você tiver um projeto do Windows 8.1 existentes e não queira a porta para o Windows 10, consulte [portando para a plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md). Se você tiver bibliotecas da área de trabalho de Win32 clássicas existentes e de código que você deseja integrar um aplicativo UWP, consulte [como: uso de código C++ existente em um aplicativo de plataforma Universal do Windows](../porting/how-to-use-existing-cpp-code-in-a-universal-windows-platform-app.md).

Você também pode escrever componentes, jogos e aplicativos Universal do Windows sem usar C + + CX; em vez disso, você pode usar a biblioteca de modelos do C++ do Windows Runtime (biblioteca de modelos do C++ de tempo de execução do Windows). Para obter mais informações, consulte [biblioteca de modelo em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

Com [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], você pode desenvolver aplicativos universais do Windows que executam o Windows 10 desktop e dispositivos móveis. Você também pode desenvolver aplicativos do Windows 8.1 e Windows Phone 8.1 no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], mas para fazer isso, você deve primeiro instalar o Visual Studio 2013 no mesmo computador e, em seguida, configurar seu projeto para usar o **Visual Studio 2013 (v120)** conjunto de ferramentas . Para configurar essa configuração em seu projeto, abra as propriedades do projeto e, no **geral** seção, defina o **conjunto de ferramentas de plataforma** para **Visual Studio 2013 (v120)**.

Se você instalar as ferramentas de Phone 8.0 na instalação do Visual Studio, você também pode direcionar o Windows Phone 8.0.

Um novo conceito introduzido no Windows 10 chamadas API contratos substitui a antiga prática de destinados a versões específicas do Windows. Em vez disso, você pode escolher quais contratos de API do seu aplicativo necessidades e, em seguida, serão executado em qualquer dispositivo do Windows que oferece suporte a esses contratos. Um contrato de API é um conjunto de APIs estáveis que fornecem acesso aos recursos de plataforma ou dispositivo. Contratos de API pode ser incluídos como referência no sistema de projeto. Em um projeto do Visual Studio, se você adicionar uma referência a um SDK de extensão específica, o Visual Studio adiciona os contratos de API apropriada.

Para obter mais informações sobre todos esses conceitos, consulte [guia para aplicativos universais do Windows](http://go.microsoft.com/fwlink/p/?linkid=534605).

##  <a name="BK_Native"></a>Área de trabalho, servidor e aplicativos de nuvem e jogos

Na nuvem, você pode escrever assemblies de código nativo do Azure em C++ e chamá-los funções da Web que são criados em c#. Para obter mais informações, consulte [SDK do Azure](http://go.microsoft.com/fwlink/p/?LinkId=256416).

Para saber as Noções básicas de criação de aplicativos de cliente do Windows para a área de trabalho, consulte [o desenvolvimento de aplicativos do Windows em C++](http://msdn.microsoft.com/vstudio//hh304489) e [Introdução à programação do Windows em C++](http://msdn.microsoft.com/library/windows/desktop/ff381398\(v=vs.85\).aspx).

No Windows 10, você pode usar o Visual C++ para criar vários tipos de programas:

- Aplicativos e utilitários de linha de comando. Para obter mais informações, consulte [aplicativos de Console](../windows/console-applications-in-visual-cpp.md).

- Jogos do DirectX que são executados no PC ou Xbox. Para obter mais informações, consulte [DirectX Developer Center](http://go.microsoft.com/fwlink/p/?LinkId=256418).

- Aplicativos de consumidor que têm interfaces de usuário gráficas sofisticadas. Para obter mais informações, consulte [Hilo: desenvolvendo aplicativos do C++ para Windows](http://go.microsoft.com/fwlink/p/?LinkId=256417)

- Aplicativos empresariais e de linha de negócios que são executados no .NET Framework, ou servem como uma ponte entre os aplicativos do .NET Framework e aplicativos ou componentes que são escritos em código nativo. Para obter mais informações, consulte [programação .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

- Clientes do banco de dados SQL que são executados em código nativo. Para obter mais informações, consulte [SQL Server Native Client](http://go.microsoft.com/fwlink/p/?LinkId=256419).

- Suplementos para aplicativos Microsoft Office. Para obter mais informações, consulte [criando um Add-in do C++ para o Outlook 2010](http://go.microsoft.com/fwlink/p/?LinkId=256420)

- Drivers de dispositivo. Para obter mais informações, consulte [Windows Driver Kit (WDK)](http://go.microsoft.com/fwlink/p/?LinkId=256421)

- Serviços do Windows. Para obter mais informações, consulte [Introdução a aplicativos de serviço do Windows](/dotnet/framework/windows-services/introduction-to-windows-service-applications).

Você pode usar o Visual C++ para empacotar quase todos os tipos de funcionalidade personalizada de alto desempenho nas DLLs do Win32 ou DLLs COM que podem ser consumidas pelos aplicativos do C++ ou pelos aplicativos que são escritos em outras linguagens, por exemplo, C# ou Visual Basic. Para obter mais informações sobre as DLLs do WIn32, consulte [DLLs no Visual C++](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre o desenvolvimento COM, consulte [modelo COM (Component Object)](https://msdn.microsoft.com/library/windows/desktop/ms680573).

## <a name="sdks-and-header-files"></a>SDKs e arquivos de cabeçalho

Visual C++ inclui a biblioteca de tempo de execução do C (CRT), a biblioteca padrão C++ e outras bibliotecas específicas da Microsoft. Incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas são localizado no diretório de instalação do Visual Studio na pasta \VC\ ou, no caso de CRT, pasta de instalação do SDK do Windows, por exemplo, Windows Kits\10 nos arquivos de programa pasta para o SDK do Windows 10.  As bibliotecas Microsoft incluem:

- Microsoft Foundation Classes (MFC): uma estrutura orientada por objeto para criação de programas tradicionais do Windows (especialmente aplicativos empresariais) que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md).

- Active Template Library (ATL): uma biblioteca auxiliar potente para criação de componentes COM. Para obter mais informações, consulte [componentes de área de trabalho do ATL COM](../atl/atl-com-desktop-components.md).

- C++ AMP (C++ Accelerated Massive Parallelism): uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).

- Tempo de Execução de Simultaneidade: uma biblioteca que simplifica o trabalho da programação paralela e assíncrona para dispositivos de vários e muitos núcleos. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).

Muitos cenários de programação do Windows também exigem o Windows SDK, que inclui os arquivos de cabeçalho que permitem acesso aos componentes do sistema operacional Windows. Por padrão, o Visual Studio instala o SDK do Windows, que permite o desenvolvimento de aplicativos Universal do Windows. Para desenvolver aplicativos universais do Windows para Windows 10, é necessário ter a versão do Windows 10 do SDK do Windows. Para obter informações sobre o SDK do Windows 10, consulte [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk). (Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte o [arquivamento do SDK do Windows](https://developer.microsoft.com/windows/downloads/sdk-archive)).

Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte Centro de desenvolvedores do DirectX e o Centro de desenvolvedores do Azure.

## <a name="development-tools"></a>Ferramentas de desenvolvimento

O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração gráfica, um editor de código com recursos completos, suporte para testes de unidade e muitos outros utilitários e ferramentas. Para obter mais informações, consulte [começar a desenvolver com o Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio), e [IDE e ferramentas de desenvolvimento](../ide/ide-and-tools-for-visual-cpp-development.md).

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Tópico pai para o conteúdo de desenvolvedor do Visual C++.|