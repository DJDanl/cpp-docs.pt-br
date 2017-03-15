---
title: "SetFilters | Microsoft Docs"
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
  - "SetFilters"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetFilters"
ms.assetid: ae934e1b-8ead-4c1d-a0f8-e9c80d182340
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SetFilters
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona origem, e incluir e filtros de recursos para as pastas de projeto.  
  
## Sintaxe  
  
```  
  
      function SetFilters(   
   oProj    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
## Comentários  
 Chame esta função para adicionar o código\-fonte, incluir e filtros de recursos para as pastas de projeto.  Esta função localiza os seguintes símbolos no projeto:  
  
-   SOURCE\_FILTER  
  
-   INCLUDE\_FILTER  
  
-   RESOURCE\_FILTER  
  
 Esses símbolos contêm as extensões de arquivo usadas na filtragem.  
  
## Exemplo  
  
```  
// Create and set the project name and path.  
selProj = CreateProject(strProjectName, strProjectPath);  
// Add the previously-identified configurations to the project.  
AddConfigurations(selProj, strProjectName);  
// Set filters for the project.  
SetFilters (selproj);  
// Indicate that the project is an ATL project.  
selProj.Object.keyword = "AtlProj";  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)