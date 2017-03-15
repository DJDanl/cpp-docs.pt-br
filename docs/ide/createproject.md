---
title: "CreateProject | Microsoft Docs"
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
  - "CreateProject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateProject"
ms.assetid: b5598b46-fe29-4ad0-8bfe-a4dc789aeebd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CreateProject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um projeto de C\+\+.  
  
## Sintaxe  
  
```  
  
      function CreateProject(   
   strProjectName,   
   strProjectPath    
);  
```  
  
#### Parâmetros  
 `strProjectName`  
 Uma string contendo o nome do projeto.  
  
 *strProjectPath*  
 Uma seqüência de caracteres que contém o caminho do projeto.  
  
## Valor de retorno  
 O objeto de projeto.  
  
## Comentários  
 Chame essa função para criar um projeto de C\+\+ que pode ser aberto no Visual Studio.  Se o parâmetro de contexto do assistente  **WizardType** é especificado como  **vsWizardAddSubProject**, o projeto é adicionado como um subprojeto ao projeto existente.  Consulte  [ContextParams Enum](../Topic/Context%20Parameters%20for%20Launching%20Wizards.md) para obter mais informações.  
  
## Exemplo  
 Consulte  [AddFilesToProject](../Topic/AddFilesToProject.md).  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)