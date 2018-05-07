---
title: Criando e gerenciando projetos do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vcprojects
- creatingmanagingVC
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, creating
- Visual C++ projects, creating
- projects [C++], creating
- Visual C++ projects
- ATL projects
ms.assetid: 11003cd8-9046-4630-a189-a32bf3b88047
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b3afbd2019965d859895462cfdad57292bc2e0b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="creating-and-managing-msbuild-based-visual-c-projects"></a>Criando e gerenciando projetos do Visual C++ com base em MSBuild
MSBuild é o sistema de compilação nativa para Visual C++ e geralmente é que melhor criar o sistema a ser usado para aplicativos UWP, bem como aplicativos de área de trabalho que usam bibliotecas MFC ou do ATL. MSBuild está totalmente integrado com o Visual Studio IDE e o sistema de projeto, mas você também pode usá-lo na linha de comando. A partir do Visual Studio de 2017, Visual C++ dá suporte a [CMake e outros sistemas de MSBuild não por meio do recurso Abrir pasta](non-msbuild-projects.md).

Um projeto do MSBuild tem um arquivo de projeto em formato XML (. vcxproj) que especifica todos os arquivos e recursos necessários para compilar o programa, bem como outras configurações, por exemplo, a plataforma de destino (x 86, x64 ou ARM) e se você estiver criando um versão da liberação ou versão de depuração do programa. Um projeto (ou vários projetos) estão contidos em um *solução*; por exemplo, uma solução pode conter vários projetos de DLL Win32 e um único aplicativo de console Win32 que usa as DLLs. Quando você compila o projeto, o mecanismo MSBuild consome o arquivo de projeto e produz o arquivo executável e/ou outra saída de personalizado que você especificou.

Você pode criar projetos do Visual C++, escolhendo **arquivo &#124; novo &#124; projeto**, garantindo que o Visual C++ está selecionado no painel esquerdo e, em seguida, escolhendo na lista de modelos de projeto no painel central. Quando você clica em um modelo, em muitos casos um assistente será exibida que permite que você defina várias propriedades de projeto para que o projeto é criado. Você pode exibir e modificar as propriedades mais tarde usando as páginas de propriedades do projeto (**projeto &#124; propriedades**).  
  
 Você também pode criar novos projetos por:  
  
-   escolhendo **arquivo &#124; novo &#124; projeto de código existente** e seguir as instruções para adicionar arquivos de código fonte existente. Essa opção funciona melhor para projetos relativamente pequenos e simples, talvez 25 arquivos códigos-fonte ou menos, com poucas ou nenhuma dependências complexas.  
  
-   começando com um makefile e escolha o modelo de projeto Makefile na guia Geral.  
  
-   Criando um projeto vazio (sob o **geral** guia) e adicionar manualmente os arquivos de código fonte clicando duas vezes no nó do projeto no Gerenciador de soluções e escolha **adicionar &#124; Item existente**.  
  
-   usando o [Assistente de aplicativo Win32](../windows/win32-application-wizard.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)  
 Descreve os tipos de projeto com base em MSBuild estão disponíveis no Visual C++.  
  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)  
 Descreve os tipos de arquivos que são usados com vários tipos de projeto do MSBuild.  
  
 [Criando projetos para área de trabalho com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)  
 Como usar os assistentes para criar projetos com o Visual C++.  
  
 [Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)  
 Descreve como usar as Páginas de Propriedades e as Folhas de Propriedades para especificar as configurações do projeto.  
  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)  
 Descreve como adicionar classes, métodos, variáveis e outros elementos ao seu projeto para adicionar funcionalidade.  
  
 [Como organizar arquivos de saída do projeto para compilações](../ide/how-to-organize-project-output-files-for-builds.md)  
 Descreve como organizar arquivos de saída do projeto.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)  
 Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.  
  
 [Referência do Visual C++](http://msdn.microsoft.com/en-us/1ba03b5c-8229-4f63-b08c-6c12141d6ab1)  
 Fornece links aos tópicos que descrevem as referências de linguagem C e C++, as bibliotecas fornecidas com o Visual C++, o modelo de objeto de extensibilidade do Visual C++ e o MASM (Microsoft Macro Assembler).  
  
## <a name="see-also"></a>Consulte também  
 [SDK do Visual Studio](http://msdn.microsoft.com/vstudio/extend)
