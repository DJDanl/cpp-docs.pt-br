---
title: "SetMergeProxySymbol | Microsoft Docs"
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
  - "SetMergeProxySymbol"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetMergeProxySymbol"
ms.assetid: d6a9db59-2d5b-4431-98bc-785675e0eafe
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SetMergeProxySymbol
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta função é chamada pelo Assistente para adicionar o símbolo \_MERGE\_PROXYSTUB, se necessário.  
  
## Sintaxe  
  
```  
  
      function SetMergeProxySymbol(   
   oProj    
);  
```  
  
#### Parâmetros  
 `oProj`  
 Objeto de projeto selecionado  
  
## Comentários  
 Esta função é chamada pelo Assistente para adicionar o símbolo \_MERGE\_PROXYSTUB, se necessário.  
  
## Exemplo  
  
```  
SetMergeProxySymbol (selproj);  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)