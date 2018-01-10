---
title: "Página de propriedades NMake (Windows C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCNMakeTool.ReBuildCommandLine
- VC.Project.VCNMakeTool.CleanCommandLine
- VC.Project.VCNMakeTool.Output
- VC.Project.VCNMakeTool.BuildCommandLine
dev_langs: C++
helpviewer_keywords: NMake property page
ms.assetid: bd20cb52-9f1d-4240-b4fc-4f43205ac94b
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7cc9f6dc7c5fec4a184ed189cfaae230df3f1e9e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-property-page"></a>Página de propriedades NMake
O **NMake** página de propriedade permite que você especifique configurações de compilação para projetos de NMake.  
  
 Para obter mais informações sobre projetos de NMake, consulte [criando um projeto Makefile](../ide/creating-a-makefile-project.md). Para non_Windows projetos MakeFile, consulte [propriedades de projeto MakeFile (C++ Linux)](../linux/prop-pages/makefile-linux.md), [propriedades do projeto geral (Android C++ Makefile)](/visualstudio/cross-platform/general-makefile-android-prop-page) ou [NMake propriedades (C++ Android)](/visualstudio/cross-platform/nmake-android-prop-page).
  
 O **NMake** página de propriedades contém as seguintes propriedades.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Criar linha de comando**  
 Especifica o comando a ser executado quando **criar** é clicado no **criar** menu.  
  
 **Recompilar toda a linha de comando**  
 Especifica o comando a ser executado quando **recriar todos** é clicado no **criar** menu.  
  
 **Limpar linha de comando**  
 Especifica o comando a ser executado quando **limpar** é clicado no **criar** menu.  
  
 **Saída**  
 Especifica o nome do arquivo que conterá a saída da linha de comando. Por padrão, esse nome de arquivo com base no nome do projeto.  
  
 **Definições de pré-processador**  
 Especifica qualquer fonte de arquivos usam as definições de pré-processador. O valor padrão é determinado pela configuração e plataforma atual.  
  
 **Caminho de pesquisa de inclusão**  
 Especifica os diretórios em que o compilador procura por arquivos de inclusão.  
  
 **Forçado inclui**  
 Especifica os arquivos que o pré-processador processa automaticamente mesmo se elas não são incluídas nos arquivos de projeto.  
  
 **Caminho de pesquisa de assembly**  
 Especifica os diretórios em que o .NET Framework pesquisa quando ele tenta resolver assemblies .NET.  
  
 **Assemblies de uso forçado**  
 Especifica os assemblies do .NET Framework processa automaticamente.  
  
 **Opções adicionais**  
 Especifica quaisquer opções de compilador adicionais para o IntelliSense usar ao analisar arquivos C++.  
  
 Para obter informações sobre como acessar o **NMake** página de propriedades, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
 Para obter informações sobre como acessar programaticamente os membros do objeto, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCNMakeTool>.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [Como habilitar o IntelliSense para projetos makefile](../ide/how-to-enable-intellisense-for-makefile-projects.md)