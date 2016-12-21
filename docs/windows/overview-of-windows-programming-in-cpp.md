---
title: "Vis&#227;o geral de programa&#231;&#227;o do Windows no C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: efc691d7-21f3-47ae-ae56-cab999ccf59d
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral de programa&#231;&#227;o do Windows no C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar o Visual C\+\+ para escrever uma grande variedade de programas que são executados em um PC Windows \(x86, x64 ou ARM\), em um servidor Windows, na nuvem ou no Xbox. Programas do C\+\+ bem escritos são rápidos, eficientes, econômicos em consumo de energia e capaz de tirar proveito dos dispositivos de vários núcleos e muitos núcleos, computação gerais na unidade \(GPGPU\) e outros avanços recentes em hardware de processamento.  
  
 Há várias categorias de aplicativos do Windows que você pode desenvolver com o Visual C\+\+. Essas categorias têm modelos de programação diferentes ou modelos de aplicativo, o que significa que eles usam diferentes bibliotecas e APIs que fornecem acesso à plataforma e fornecem a interface do usuário.  
  
-   [Aplicativos do Windows Universal](#BK_WindowsUniversal). A terceira categoria de aplicativos do Windows foi introduzida com o Windows 8 e continua o suporte para essa categoria de aplicativos no Windows 10. Esses aplicativos são geralmente chamados apenas como "aplicativos do Windows" e incluem aplicativos de desktop e portáteis que uma variedade de dispositivos de destino. Você pode escrever esses aplicativos em C \+ \+ \/ CX, um dialeto do C\+\+ que inclui suporte para o desenvolvimento de tempo de execução do Windows ou no C\+\+ padrão com usando a biblioteca de tempo de execução do Windows \(WRL\). Esses aplicativos foram originalmente criados para executar em tela inteira, embora no Windows 10 usuários terão a opção de executá\-los em uma janela da área de trabalho. Esses aplicativos são orientados a toque, mas é fácil usar o mouse para operar se você preferir ou se não houver uma tela sensível ao toque. Esses aplicativos são distribuídos da Windows Store, um fato que levou a eles que está sendo chamado "Aplicativos da Windows Store".  
  
-   [Desktop, servidor, aplicativos de nuvem e jogos](#BK_Native). Esta categoria inclui aplicativos de área de trabalho do Windows, chamados aplicativos Win32, já que esses aplicativos estavam usando a API do Win32 no antes do Windows 8, todos os aplicativos do Windows foram nesta categoria. Aplicativos nessa categoria podem usar MFC para uma interface de usuário e ATL para interagir com os componentes do Windows, que normalmente não são objetos COM.  
  
     Aplicativos, componentes ou bibliotecas escritas com C\+\+ padrão também se encaixa nesta categoria.  
  
     Esta categoria inclui também usando C\+\+ para componentes principais e computacional código no contexto do servidor e a programação de nuvem. Às vezes, o código de alto desempenho no núcleo de um servidor ou aplicativo em nuvem é escrito em C\+\+ para maximizar o desempenho. Você pode compilar esse código em uma DLL e usá\-lo de c\# ou Visual Basic.  
  
-   **Aplicativos do .NET framework**. A maioria dos aplicativos do .NET Framework são escritos em c\# ou Visual Basic, mas você também pode C \+ \+ \/ CLI \(a opção de compilador \/clr no Visual C\+\+\). É recomendável usar C \+ \+ \/ CLI para uma camada de interoperabilidade mínimo em um aplicativo maior que inclui o código gerenciado e nativo.  
  
##  <a name="BK_WindowsUniversal"></a> Aplicativos do Windows Universal  
 Com o Windows 10, os aplicativos são capazes de executar em todos os dispositivos Windows 10 como tablets e celulares, bem como na área de trabalho. Na área de trabalho, eles são capazes de executar como uma janela da área de trabalho, em vez de sempre executando tela inteira. Esses aplicativos também podem executar o Xbox e em dispositivos futuras.  O modelo de programação para os dois tipos de aplicativos é diferente de aplicativos de desktop do Win32. Esses aplicativos do Windows executados em uma interface e o tempo de execução do Windows, que fornece os elementos de interface do usuário, serviços essenciais para esses aplicativos e fornece, para os dispositivos de hardware diferentes que têm suporte. Esses aplicativos compilados para código nativo e têm uma interface do usuário XAML ou usam o DirectX. Você também pode escrever [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] componentes nativos que outras janelas de aplicativos podem consumir de código — isso inclui aplicativos que são escritos em c\#, Visual Basic ou JavaScript. Para obter mais informações, consulte [criar seu primeiro aplicativo da Windows Store usando C\+\+](http://go.microsoft.com/fwlink/?LinkID=534976), [criar seu primeiro jogo da Windows Store usando DirectX](http://go.microsoft.com/fwlink/p/?LinkId=244656), e [componentes de criação de tempo de execução do Windows em C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=244658).  
  
 Para obter exemplos de plataforma Universal do Windows, consulte [Windows Universal exemplos no GitHub](https://github.com/Microsoft/Windows-universal-samples)  
  
 Se você tiver um projeto existente do Windows 8.1 e quiser a porta para o Windows 10, consulte [Portando para a Plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md). Se você tiver bibliotecas da área de trabalho existentes de clássico Win32 e de código que você deseja integrar em um aplicativo UWP, consulte [Como usar o código C\+\+ existente em um aplicativo da Plataforma Universal do Windows](../Topic/How%20to:%20Use%20Existing%20C++%20Code%20in%20a%20Universal%20Windows%20Platform%20App.md).  
  
 Você também pode escrever aplicativos, jogos e componentes universais do Windows sem usar o [!INCLUDE[cppwrt](../build/reference/includes/cppwrt_md.md)] \([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]\); em vez disso, você pode usar o [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\). Para obter mais informações, consulte [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md).  
  
 Com [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], você pode desenvolver aplicativos universais do Windows que são executados no Windows 10 desktops e dispositivos móveis. Você também pode desenvolver aplicativos do Windows 8.1 e Windows Phone 8.1 no [!INCLUDE[cpp_dev14_long](../porting/includes/cpp_dev14_long_md.md)], mas para fazer isso, você deve primeiro instalar o Visual Studio 2013 no mesmo computador e, em seguida, configurar seu projeto para usar o **Visual Studio 2013 \(v120\)** conjunto de ferramentas. Para configurar essa configuração em seu projeto, abra as propriedades do projeto e no **geral** seção, defina o **conjunto de ferramentas de plataforma** para **Visual Studio 2013 \(v120\)**.  
  
 Se você instalar as ferramentas de Phone 8.0 na instalação do Visual Studio, você também pode direcionar o Windows Phone 8.0.  
  
 Um novo conceito apresentado no Windows 10 chamado contratos de API substitui a antiga prática de direcionamento versões específicas do Windows. Em vez disso, você pode escolher quais contratos de API do seu aplicativo às necessidades e ela serão executada em qualquer dispositivo do Windows que oferece suporte a esses contratos. Um contrato de API é um conjunto de APIs estável que fornece acesso aos recursos da plataforma ou dispositivo. Contratos de API pode ser incluídos como referências no sistema de projeto. Em um projeto do Visual Studio, se você adicionar uma referência para um determinado SDK de extensão, o Visual Studio adiciona os contratos de API apropriado.  
  
 Para obter mais informações sobre todos esses conceitos, consulte [guia para aplicativos do Windows Universal](http://go.microsoft.com/fwlink/?LinkId=534605).  
  
##  <a name="BK_Win32"></a> Área de trabalho, servidor e aplicativos de nuvem e jogos  
 Na nuvem, você pode escrever assemblies de código nativo do Azure em C\+\+ e chamá\-los de funções da Web que são criados em c\#. Para obter mais informações, consulte [SDK do Azure](http://go.microsoft.com/fwlink/p/?LinkId=256416).  
  
 Para aprender os conceitos básicos de como escrever aplicativos de cliente do Windows para a área de trabalho, consulte [o desenvolvimento de aplicativos do Windows em C\+\+](http://msdn.microsoft.com/vstudio//hh304489) e [Introdução à programação do Windows em C\+\+](http://msdn.microsoft.com/library/windows/desktop/ff381398\(v=vs.85\).aspx).  
  
 No Windows 10, você pode usar o Visual C\+\+ para criar vários tipos de programas:  
  
-   Utilitários e aplicativos de linha de comando. Para obter mais informações, consulte [Aplicativos de console](../Topic/Console%20Applications%20in%20Visual%20C++.md).  
  
-   Jogos do DirectX que são executados no PC ou Xbox. Para obter mais informações, consulte [DirectX Developer Center](http://go.microsoft.com/fwlink/p/?LinkId=256418).  
  
-   Aplicativos de consumidor que tenham sofisticadas interfaces gráficas do usuário. Para obter mais informações, consulte [Hilo: desenvolvendo aplicativos do C\+\+ para Windows](http://go.microsoft.com/fwlink/p/?LinkId=256417)  
  
-   Aplicativos corporativos e de linha de negócios executados no .NET Framework, ou servem como uma ponte entre o .NET Framework aplicativos e aplicativos ou componentes que são escritos em código nativo. Para obter mais informações, consulte [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).  
  
-   Clientes de banco de dados SQL que são executados em código nativo. Para obter mais informações, consulte [SQL Server Native Client](http://go.microsoft.com/fwlink/p/?LinkId=256419).  
  
-   Suplementos para aplicativos do Microsoft Office. Para obter mais informações, consulte [Criando um Add\-in C\+\+ para Outlook 2010](http://go.microsoft.com/fwlink/p/?LinkId=256420)  
  
-   Drivers de dispositivo. Para obter mais informações, consulte [Windows Driver Kit \(WDK\)](http://go.microsoft.com/fwlink/p/?LinkId=256421)  
  
-   Serviços do Windows. Para obter mais informações, consulte [Introduction to Windows Service Applications](../Topic/Introduction%20to%20Windows%20Service%20Applications.md).  
  
 Você pode usar o Visual C\+\+ para empacotar quase qualquer tipo de funcionalidade personalizada de alto desempenho nas DLLs do Win32 ou DLLs COM que podem ser consumidos por aplicativos C\+\+ ou aplicativos que são escritos em outras linguagens — por exemplo, c\# ou Visual Basic. Para obter mais informações sobre as DLLs do WIn32, consulte [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre o desenvolvimento COM, consulte [Component Object Model \(COM\)](http://msdn.microsoft.com/pt-br/375d29a7-a1f3-4bd8-8621-bad7a049b2aa).  
  
## SDKs e arquivos de cabeçalho  
 Visual C\+\+ inclui bibliotecas padrão C e C\+\+, o modelo Biblioteca STL \(Standard\) e outras bibliotecas específicas da Microsoft. Incluir pastas que contêm arquivos de cabeçalho para essas bibliotecas são que seja localizado no diretório de instalação do Visual Studio na pasta \\vc\\. ou, no caso da biblioteca C Runtime \(CRT\), pasta de instalação do SDK do Windows, por exemplo, Windows Kits\\10 na pasta arquivos de programa para o SDK do Windows 10.  As bibliotecas da Microsoft incluem:  
  
-   Microsoft Foundation Classes \(MFC\): Uma estrutura orientada para a criação de programas tradicionais do Windows — especialmente aplicativos empresariais — que têm interfaces de usuário avançadas que apresentam botões, caixas de listagem, modos de exibição de árvore e outros controles. Para obter mais informações, consulte [Aplicativos para desktop do MFC](../mfc/mfc-desktop-applications.md).  
  
-   Active Template Library \(ATL\): Uma biblioteca auxiliar potente para criar componentes COM. Para obter mais informações, consulte [Componentes da área de trabalho COM ATL](../atl/atl-com-desktop-components.md).  
  
-   C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\): Uma biblioteca que permite trabalho computacional geral de alto desempenho na GPU. Para obter mais informações, consulte [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).  
  
-   Tempo de execução de simultaneidade: Uma biblioteca que simplifica o trabalho de programação paralela e assíncrona para dispositivos com vários núcleos e vários núcleos. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).  
  
 Muitos cenários de programação do Windows também exigem o SDK do Windows, que inclui os arquivos de cabeçalho que permitem o acesso aos componentes do sistema operacional Windows. Por padrão, todas as edições do [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)] instalar o SDK do Windows, que permite o desenvolvimento de aplicativos universais do Windows. Para desenvolver aplicativos do Windows Universal para Windows 10, você precisará da versão do Windows 10 do SDK do Windows. Para obter informações sobre o SDK do Windows 10, consulte [SDK do Windows 10](http://go.microsoft.com/fwlink/p/?LinkId=534603). \(Para obter mais informações sobre os SDKs do Windows para versões anteriores do Windows, consulte [Visão geral do Windows SDK](../Topic/Overview%20of%20the%20Windows%20SDK.md)\).  
  
 Outras plataformas, como Xbox e Azure têm seus próprios SDKs que talvez você precise instalar. Para obter mais informações, consulte o Centro de desenvolvedores do DirectX e o Azure Developer Center.  
  
## Ferramentas de desenvolvimento  
 O Visual Studio inclui um depurador potente para código nativo, ferramentas de análise estática, ferramentas de depuração de gráficos, um editor de códigos completo, suporte para testes de unidade e muitas outras ferramentas e utilitários. Para obter mais informações, consulte [desenvolvimento de aplicativos no Visual Studio](http://msdn.microsoft.com/pt-br/97490c1b-a247-41fb-8f2c-bc4c201eff68), e [IDE e ferramentas de desenvolvimento](../Topic/IDE%20and%20Tools%20for%20Visual%20C++%20Development.md).  
  
## Artigos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Visual C\+\+](../top/visual-cpp-in-visual-studio-2015.md)|Tópico pai para o conteúdo da biblioteca do MSDN sobre o C\+\+.|