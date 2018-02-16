---
title: Compilando projetos do C++ no Visual Studio | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Visual C++ projects, building
- projects [C++], building
- builds [C++], about building in Visual Studio
ms.assetid: 9e8bc1a2-bb17-4951-937a-c757ed88d2d1
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 074b43619d307d4d6ffeec1a057c9c27a4f9d05f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="building-c-projects-in-visual-studio"></a>Compilando projetos do C++ no Visual Studio
No IDE (ambiente de desenvolvimento integrado) do Visual Studio há diversas formas de compilar uma solução completa ou apenas um projeto em uma solução. Você também pode modificar as definições de compilação e especificar etapas de compilação especificadas para aumentar a eficiência do seu processo de desenvolvimento.  
  
 Para criar uma solução que é aberto no Visual Studio e selecionado na **Solution Explorer**, você pode:  
  
-   Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
-   Ou, no **Solution Explorer**, abra o menu de atalho para a solução e, em seguida, escolha **compilar solução**.  
  
-   Ou pressione F7. (esse é o atalho padrão do teclado para as definições de desenvolvimento em C/C++).  
  
-   Ou, no [janela comando](/visualstudio/ide/reference/command-window) (na barra de menus, escolha **exibição**, **outras janelas**, **janela comando**), digite `Build.BuildSolution`.  
  
-   Ou, no [início rápido](/visualstudio/ide/reference/quick-launch-environment-options-dialog-box) , digite `build build solution`.  
  
 Para criar um projeto que está selecionado no **Solution Explorer**, você pode:  
  
-   Na barra de menus, escolha **criar**, **criar \<nome do projeto >**.  
  
-   Ou, no **Solution Explorer**, abra o menu de atalho para o projeto e, em seguida, escolha **criar**.  
  
-   Ou, na janela de comando (na barra de menus, escolha **exibição**, **outras janelas**, **janela comando**), digite `Build.BuildOnlyProject`.  
  
-   Ou, na caixa de início rápido, digite `build project only build only <project name>`.  
  
 Ao compilar um aplicativo em Visual C++ no Visual Studio, você pode modificar diversas definições da compilação na caixa de diálogo Páginas de Propriedades do projeto. Para obter informações sobre como definir propriedades do projeto, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
 Para obter um exemplo sobre como usar o IDE para criar, compilar e depurar um projeto do C++, consulte [passo a passo: explorar o IDE do Visual Studio com C++](/visualstudio/ide/getting-started-with-cpp-in-visual-studio). Para obter um exemplo sobre como usar o IDE para criar um C + + projeto CLR, consulte [passo a passo: compilando um programa C++ que tem como alvo o CLR no Visual Studio](../ide/walkthrough-compiling-a-cpp-program-that-targets-the-clr-in-visual-studio.md). Para obter um exemplo sobre como usar o IDE para criar um aplicativo de tempo de execução do Windows, consulte [criar seu primeiro aplicativo de tempo de execução do Windows usando C++](http://msdn.microsoft.com/library/windows/apps/hh974580.aspx).  
  
 Para saber mais sobre como compilar, modificar definições de compilação e especificar etapas de compilação personalizadas, consulte os artigos mencionados a seguir.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Noções básicas sobre etapas e eventos compilação personalizada](../ide/understanding-custom-build-steps-and-build-events.md)  
 Descreve como personalizar o processo de compilação no ambiente de desenvolvimento integrado.  
  
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)  
 Lista as macros que você pode usar onde as sequências de caracteres são aceitas.  
  
 [Compilando projetos externos](../ide/building-external-projects.md)  
 Fala sobre projetos de compilação que usam instalações externas ao ambiente de desenvolvimento integrado.  
  
 [Arquivos de projeto](../ide/project-files.md)  
 Apresenta a estrutura XML de um arquivo .vcxproj.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [VC + + caixa de diálogo Opções de diretórios, projetos,](vcpp-directories-property-page.md)  
 (Somente para projetos de MSBuild) Descreve como modificar o caminho de pesquisa de arquivos executáveis, incluem arquivos, arquivos de biblioteca e arquivos de código fonte durante uma compilação.  
  
 [Compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio)  
 Fornece informações sobre como compilar no Visual Studio.  
  
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)  
 Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.  
  
 [Referência de build C/C++](../build/reference/c-cpp-building-reference.md)  
 Fornece links para uma visão geral sobre os programas de compilação em C++, opções de compilador e vinculador, e outras ferramentas de compilação.  
  
 [Atualizando projetos de versões anteriores do Visual C++](../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md)  
 Fornece links para tópicos que abrangem os problemas na atualização de seu projeto de C++ para versões mais recentes do conjunto de ferramentas de compilador.  
  
[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)  
  Informações detalhadas sobre como atualizar aplicativos C++ que foram criados em versões anteriores do Visual Studio e também como migrar aplicativos que foram criados usando ferramentas que não sejam o Visual Studio.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos universais do Windows (C++)](../windows/universal-windows-apps-cpp.md)