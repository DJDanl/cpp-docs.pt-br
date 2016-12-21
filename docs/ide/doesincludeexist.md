---
title: "DoesIncludeExist | Microsoft Docs"
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
  - "DoesIncludeExist"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método DoesIncludeExist"
ms.assetid: 39751a3d-dfe5-423c-bd94-a53771c3e360
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# DoesIncludeExist
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se um `#include` a instrução para um arquivo de cabeçalho especificado existe em um arquivo.  
  
## Sintaxe  
  
```  
  
      function DoesIncludeExist(   
   oProj,   
   strHeaderFile,   
   strInsertIntoFile    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
 *strHeaderFile*  
 O nome do arquivo de cabeçalho para localizar.  
  
 `strInsertIntoFile`  
 O arquivo de origem que contém o `#include` a instrução para o arquivo de cabeçalho \(excluindo o caminho\).  
  
## Valor de retorno  
 **True** se o arquivo de cabeçalho especificado está incluído; Caso contrário,  **false**.  
  
## Comentários  
 Indica se um \# include para um arquivo de cabeçalho específico existe no arquivo especificado por `strInsertIntoFile`.  
  
## Exemplo  
  
```  
// Check to see if #include for atlbase.h   
// is included in the project's stdafx.h.  
// and add it if it is not.  
if (!DoesIncludeExist(selProj, "<atlbase.h>", strSTDAFX))  
   oCM.AddInclude("<atlbase.h>", strSTDAFX, vsCMAddPositionEnd);  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)