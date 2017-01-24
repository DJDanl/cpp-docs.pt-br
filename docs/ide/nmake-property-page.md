---
title: "P&#225;gina de propriedades NMake | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCNMakeTool.ReBuildCommandLine"
  - "VC.Project.VCNMakeTool.CleanCommandLine"
  - "VC.Project.VCNMakeTool.Output"
  - "VC.Project.VCNMakeTool.BuildCommandLine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Página de propriedades NMake"
ms.assetid: bd20cb52-9f1d-4240-b4fc-4f43205ac94b
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;gina de propriedades NMake
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O  **NMake** página de propriedades permite especificar configurações de compilação para projetos de NMake.  
  
 Para obter mais informações sobre os projetos de NMake, consulte [Criando um projeto de makefile](../ide/creating-a-makefile-project.md).  
  
 O  **NMake** página de propriedades contém as propriedades a seguir.  
  
## Lista UIElement  
 **Criar linha de comando**  
 Especifica o comando a ser executado quando  **Build** é clicado na  **Build** menu.  
  
 **Recriar todos os de linha de comando**  
 Especifica o comando a ser executado quando  **Recriar todos os** é clicado na  **Build** menu.  
  
 **Limpar linha de comando**  
 Especifica o comando a ser executado quando  **Clean** é clicado na  **Build** menu.  
  
 **Saída**  
 Especifica o nome do arquivo que conterá a saída da linha de comando.  Por padrão, este nome de arquivo é baseado no nome do projeto.  
  
 **Definições do pré\-processador**  
 Especifica quaisquer definições de pré\-processador que uso de arquivos de origem.  O valor padrão é determinado pela configuração e plataforma atual.  
  
 **Incluir o caminho de pesquisa**  
 Especifica os diretórios no qual o compilador procura por arquivos de inclusão.  
  
 **Forçado inclui**  
 Especifica os arquivos que o pré\-processador processa automaticamente, mesmo se eles não são incluídos nos arquivos do projeto.  
  
 **Caminho de pesquisa de assembly**  
 Especifica as pastas onde o.NET Framework procura quando ele tenta resolver.NET assemblies.  
  
 **Assemblies de uso forçado**  
 Especifica os módulos \(assemblies\) que o.NET Framework processa automaticamente.  
  
 **Additional Options**  
 Especifica opções adicionais do compilador para IntelliSense usar quando ele analisa arquivos C\+\+.  
  
 Para obter informações sobre como acessar o  **NMake** página de propriedades, consulte [Como especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
 Para obter informações sobre como membros de acesso através de programação deste objeto, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCNMakeTool>.  
  
## Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [Como habilitar o IntelliSense para projetos de makefile](../ide/how-to-enable-intellisense-for-makefile-projects.md)