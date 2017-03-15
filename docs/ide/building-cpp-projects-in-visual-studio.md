---
title: "Compilando projetos do C++ no Visual Studio | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilações [C++], sobre compilação no Visual Studio"
  - "projetos [C++], compilando"
  - "Projetos Visual C++, compilando"
ms.assetid: 9e8bc1a2-bb17-4951-937a-c757ed88d2d1
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando projetos do C++ no Visual Studio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No IDE \(ambiente de desenvolvimento integrado\) do Visual Studio há diversas formas de compilar uma solução completa ou apenas um projeto em uma solução.  Você também pode modificar as definições de compilação e especificar etapas de compilação especificadas para aumentar a eficiência do seu processo de desenvolvimento.  
  
 Para compilar uma solução que está aberta no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e selecionada no **Gerenciador de Soluções**, execute uma destas ações:  
  
-   Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
-   Abra o menu de atalho da solução no **Gerenciador de Soluções** e clique em **Compilar Solução**.  
  
-   Ou pressione F7.  \(esse é o atalho padrão do teclado para as definições de desenvolvimento em C\/C\+\+\).  
  
-   Na [Janela Comando](../Topic/Command%20Window.md) \(na barra de menus, clique em **Exibição**, **Outras Janelas**, **Janela Comando**\), digite `Build.BuildSolution`.  
  
-   Na caixa [Início Rápido](../Topic/Quick%20Launch,%20Environment,%20Options%20Dialog%20Box.md), digite `build build solution`.  
  
 Para compilar um projeto selecionado no **Gerenciador de Soluções**, execute uma destas ações:  
  
-   Na barra de menus, clique em **Compilar**, **Compilar \<Nome do projeto\>**.  
  
-   No **Gerenciador de Soluções**, abra um menu de atalho para o projeto e clique em **Compilar**.  
  
-   Na Janela de Comando \(na barra de menus, clique em **Exibição**, **Outras Janelas**, **Janela Comando**\), digite `Build.BuildOnlyProject`.  
  
-   Na caixa Início rápido, digite `build project only build only <nome do projeto>`.  
  
 Ao compilar um aplicativo em Visual C\+\+ no Visual Studio, você pode modificar diversas definições da compilação na caixa de diálogo Páginas de Propriedades do projeto.  Para saber mais sobre como definir propriedades de projetos, consulte [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).  
  
 Para ver um exemplo de como usar o IDE para criar, compilar e depurar um projeto em C\+\+, consulte [Passo a passo: explore o IDE do Visual Studio com o C\+\+](../Topic/Getting%20Started%20with%20C++%20in%20Visual%20Studio.md).  Para ver um exemplo de como usar o IDE para compilar um projeto em C\+\+\/CLR, consulte [Instruções passo a passo: compilando um programa C\+\+ que se destina ao CLR no Visual Studio](../ide/walkthrough-compiling-a-cpp-program-that-targets-the-clr-in-visual-studio.md).  Para ver um exemplo de como usar o IDE para criar um aplicativo de tempo de execução do Windows, consulte [Criar seu primeiro aplicativo do tempo de execução do Windows em C\+\+](http://msdn.microsoft.com/library/windows/apps/hh974580.aspx).  
  
 Para saber mais sobre como compilar, modificar definições de compilação e especificar etapas de compilação personalizadas, consulte os artigos mencionados a seguir.  
  
## Nesta seção  
 [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md)  
 Descreve como personalizar o processo de compilação no ambiente de desenvolvimento integrado.  
  
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)  
 Lista as macros que você pode usar onde as sequências de caracteres são aceitas.  
  
 [Compilando projetos externos](../ide/building-external-projects.md)  
 Fala sobre projetos de compilação que usam instalações externas ao ambiente de desenvolvimento integrado.  
  
 [Arquivos de projeto](../ide/project-files.md)  
 Apresenta a estrutura XML de um arquivo .vcxproj.  
  
## Seções relacionadas  
 [VC\+\+ Directories, Projects, Options Dialog Box](http://msdn.microsoft.com/pt-br/e027448b-c811-4c3d-8531-4325ad3f6e02)  
 Fala sobre como modificar um caminho de pesquisa de arquivos executáveis, arquivos de inclusão, arquivos de biblioteca e arquivos de código\-fonte durante uma compilação.  
  
 [Compilando aplicativos no Visual Studio](../Topic/Compiling%20and%20Building%20in%20Visual%20Studio.md)  
 Fornece informações sobre como compilar no Visual Studio.  
  
 [Compilando programas do C\/C\+\+](../build/building-c-cpp-programs.md)  
 Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.  
  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)  
 Fornece links para uma visão geral sobre os programas de compilação em C\+\+, opções de compilador e vinculador, e outras ferramentas de compilação.  
  
 [Atualizando projetos a partir de versões anteriores do Visual C\+\+](../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md)  
 Fornece links para tópicos sobre problemas com a atualização para o Visual C\+\+ 6.0 e projetos posteriores ao Visual C\+\+ .NET.  
  
 [Porting and Upgrading Programs](http://msdn.microsoft.com/pt-br/c36c44b3-5a9b-4bb4-9b7a-469aa770ed00)  
 Fornece detalhes sobre como fazer a portabilidade de aplicativos e fala sobre makefiles.  
  
## Consulte também  
 [Roadmap for Windows Store apps using C\+\+](http://msdn.microsoft.com/pt-br/0b71e4a4-5d8a-4a20-b2ec-e40062675ec1)