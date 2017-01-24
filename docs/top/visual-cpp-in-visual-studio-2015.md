---
title: "Visual C++ no Visual Studio 2015 | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "visual c++"
  - "visual c"
  - "vc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "código não gerenciado, C++"
  - "ambiente de desenvolvimento do Visual C++"
  - "código não gerenciado"
  - "Visual C++"
  - "Referência do Visual C++"
ms.assetid: e8dcc44c-a3e2-4ffe-887c-fd15b18dc458
caps.latest.revision: 61
caps.handback.revision: 61
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Visual C++ no Visual Studio 2015
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] desenvolvimento e linguagem de programação ferramentas ajudam a desenvolver aplicativos nativos do Windows Universal, área de trabalho nativa e aplicativos de servidor, bibliotecas de plataforma cruzada que são executados no Android e iOS, bem como Windows e aplicativos executados no .NET Framework gerenciados.  
  
 **Quem é esta documentação?**  
  
 Este conteúdo é para desenvolvedores de C\+\+ que estão escrevendo programas.  
  
-   Se você estiver procurando por um pacote redistribuível do C\+\+ e componentes de tempo de execução para que você possa executar um programa, vão para o [Microsoft Download Center](http://www.microsoft.com/en-us/download/) e digite **Visual C\+\+** na caixa de pesquisa.  
  
-   Se você estiver procurando por uma introdução aos conceitos de programação do C\+\+, vá para um dos muitos sites que oferecem esse conteúdo, ou obter uma cópia do [programação – princípios e práticas usando C\+\+ \(segunda edição\)](http://stroustrup.com/Programming/) pelo inventor do C\+\+, Bjarne Stroustrup. O conteúdo do Visual C\+\+ pressupõe que você já tem uma familiaridade básica com C\+\+.  
  
-   Se você estiver procurando o compilador do Visual C\+\+, você precisa baixar uma edição gratuita ou paga do Visual Studio 2015 de [https:\/\/www.visualstudio.com\/](https://www.visualstudio.com/).  
  
> [!WARNING]
>  No Visual Studio 2015, Visual C\+\+ não está instalado por padrão. Durante a instalação, certifique\-se de escolher **personalizado** instalação e, em seguida, escolher os componentes do C\+\+ você precisa. Ou, se já estiver instalado o Visual Studio, escolha **arquivo &#124; Novo &#124; Projeto &#124; C\+\+** e você será solicitado a instalar os componentes necessários.  
  
## Informações gerais sobre o Visual C\+\+  
 [Novidades do Visual C\+\+](../top/what-s-new-for-visual-cpp-in-visual-studio-2015.md)  
 Descubra o que há de novo no Visual C\+\+.  
  
 [Alterações significativas no Visual C\+\+ 2015](../Topic/Visual%20C++%20change%20history%202003%20-%2020151.md)  
 Saiba mais sobre as últimas alterações nesta versão.  
  
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)  
 Saiba mais sobre o C\+\+ moderno, com base no C\+\+ 11 e C\+\+ 14 que permitem escrever rapidamente, de técnicas de programação código seguro e evitar muitas das armadilhas da programação de estilo C.  
  
 [Como relatar um problema com o conjunto de ferramentas do Visual C\+\+](../top/how-to-report-a-problem-with-the-visual-cpp-toolset.md)  
 Aprenda a criar relatórios de erro eficaz contra o conjunto de ferramentas do Visual C\+\+ \(compilador, vinculador e outras ferramentas\) e maneiras de enviar o relatório.  
  
 [Guia de portabilidade e de atualização do Visual C\+\+](../porting/visual-cpp-porting-and-upgrading-guide.md)  
 Diretrizes para portar código e atualizar projetos Visual c\+\+ no [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)], incluindo portabilidade código C\+\+ para Windows 10 e a plataforma Windows Universal.  
  
 [Suporte a recursos do C\+\+11\/14\/17](../Topic/Support%20For%20C++11-14-17%20Features%20\(Modern%20C++\).md)  
 Saiba mais sobre o suporte a recursos do C\+\+ 11 e C \+ \+ 14 no Visual C\+\+.  
  
 [Blog da equipe do Visual C\+\+](http://blogs.msdn.com/b/vcblog/)  
 Saiba mais sobre os novos recursos e as informações mais recentes dos desenvolvedores do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
 [Downloads do Visual Studio](http://go.microsoft.com/fwlink/?LinkId=235233)  
 Baixe o Visual C\+\+.  
  
 [Ferramentas e modelos do Visual C\+\+ em edições do Visual Studio](../ide/visual-cpp-tools-and-templates-in-visual-studio-editions.md)  
 Saiba mais sobre as diferentes edições do Visual Studio.  
  
 [Plataformas com suporte](../top/supported-platforms-visual-cpp.md)  
 Descubra quais plataformas têm suporte.  
  
 [Exemplos do Visual C\+\+](../top/visual-cpp-samples.md)  
 Informações sobre exemplos.  
  
 [Comunidade do Visual Studio](http://go.microsoft.com/fwlink/?LinkId=235296)  
 Saiba como obter ajuda, arquivar bugs e fazer sugestões para Visual Studio.  
  
## Escrevendo aplicativos em C\+\+  
 [Aplicativos universais do Windows](../windows/universal-windows-apps-cpp.md)  
 Encontre guias e conteúdo de referência no Centro de desenvolvedores do Windows. Para obter informações sobre como desenvolver aplicativos da Windows Store, consulte [desenvolver a Windows Store usando o Visual Studio](http://go.microsoft.com/fwlink/p/?LinkId=248364) e [roteiro para a Windows Store usando C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=244654).  
  
 [Aplicativos de área de trabalho do Windows \(Visual C\+\+\)](../windows/desktop-applications-visual-cpp.md)  
 Aprenda a criar aplicativos da área de trabalho que têm um loop de mensagem e retornos de chamada.  
  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)  
 Saiba como usar o Win32, ATL e MFC para criar DLLs de área de trabalho do Windows e fornece informações sobre como compilar e registrar a DLL.  
  
 [Programação paralela](../parallel/parallel-programming-in-visual-cpp.md)  
 Saiba como usar a biblioteca de padrões paralelos, C\+\+ AMP, OpenMP e outros recursos relacionados ao multithreading no Windows.  
  
 [Práticas recomendadas de segurança](../top/security-best-practices-for-cpp.md)  
 Saiba como proteger aplicativos contra código mal\-intencionado e uso não autorizado.  
  
 [Nuvem e programação da Web](../Topic/Cloud%20and%20Web%20Programming%20in%20Visual%20C++.md)  
 No C\+\+, você tem várias opções para se conectar a web e a nuvem.  
  
 [Acesso a dados](../Topic/Data%20Access%20in%20Visual%20C++.md)  
 Conecte\-se a bancos de dados usando ODBC e outras tecnologias de acesso de banco de dados.  
  
 [Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)  
 Saiba mais sobre como trabalhar com texto diferente e formatos de cadeia de caracteres e codificações para desenvolvimento local e internacional.  
  
## Ferramentas de desenvolvimento do C\+\+  
 Para obter informações sobre como criar projetos, trabalhar com arquivos de código fonte, vincular a bibliotecas, compilar, depurar, perfil, implantar e muito mais, consulte [IDE e ferramentas de desenvolvimento](../Topic/IDE%20and%20Tools%20for%20Visual%20C++%20Development.md).  
  
## Referência da linguagem C\+\+  
 Para obter informações sobre a linguagem C\+\+, consulte [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md).  
  
 Para obter informações sobre o pré\-processador C\+\+, consulte [Referência de pré\-processador C\/C\+\+](../preprocessor/c-cpp-preprocessor-reference.md).  
  
## Bibliotecas do C\+\+ no Visual Studio  
 As seções a seguir fornecem informações sobre as bibliotecas C\+\+ diferentes que estão incluídos com o Visual C\+\+.  
  
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)  
 Inclui alternativas aprimoradas de segurança para as funções que são conhecidas por apresentar problemas de segurança.  
  
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)  
 O Standard Template Library \(STL\).  
  
 [Active Template Library \(ATL\)](../atl/atl-com-desktop-components.md)  
 Suporte para aplicativos e componentes COM.  
  
 [Bibliotecas Microsoft Foundation Class \(MFC\)](../mfc/mfc-desktop-applications.md)  
 Suporte para a criação de aplicativos de desktop tradicionais ou interfaces de usuário de estilo do Office.  
  
 [Biblioteca de padrões paralelos \(PPL\)](../parallel/concrt/parallel-patterns-library-ppl.md)  
 Algoritmos paralelos e assíncronos que são executados na CPU.  
  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)  
 Algoritmos totalmente paralelos que são executados na GPU.  
  
 [Biblioteca de modelos de tempo de execução do Windows \(WRL\)](http://msdn.microsoft.com/library/windows/apps/hh438466.aspx)  
 [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] os aplicativos e componentes.  
  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)  
 Programação para o common language runtime \(CLR\).  
  
 Consulte também a documentação do [STL\/CLR](../dotnet/stl-clr-library-reference.md) e [Biblioteca de suporte do C\+\+](../dotnet/cpp-support-library.md).  
  
## Outras bibliotecas do C\+\+  
 Esta seção contém links para bibliotecas que não estão incluídos no Visual Studio, mas podem ser baixadas e usadas com o Visual C\+\+.  
  
 [Aumento](http://www.boost.org/)  
 Uma biblioteca popular e amplamente usado.  
  
 [C\+\+ REST SDK](http://casablanca.codeplex.com).  
 Uma biblioteca da Microsoft para se comunicar com serviços da web via HTTP.  
  
## Mais recursos  
 [Recursos do Visual C\+\+](http://msdn.microsoft.com/vstudio/hh386302.aspx)  
 Mais recursos do Visual C\+\+.  
  
 [C\+\+ Padrão](http://isocpp.org/)  
 Saiba mais sobre o C\+\+, obtenha uma visão geral do C\+\+ moderno e encontre links para livros, artigos, palestras e eventos  
  
 [Aprenda o Visual C\+\+](http://msdn.microsoft.com/vstudio/hh386302.aspx)  
 Comece a aprender o C\+\+.  
  
## Consulte também  
 [Referência de linguagem C](../Topic/C%20Language%20Reference.md)   
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)   
 [Intrínsecos do compilador e linguagem do assembly](../intrinsics/compiler-intrinsics-and-assembly-language.md)