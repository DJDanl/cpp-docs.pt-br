---
title: "LineBeginsWith | Microsoft Docs"
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
  - "LineBeginsWith"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método LineBeginsWith"
ms.assetid: cbdd08ad-7309-4504-9f23-1c22bb3e4bd0
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# LineBeginsWith
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado por  [InsertIntoFunction](../ide/insertintofunction.md) para determinar se uma linha começa com a seqüência de caracteres especificada.  
  
## Sintaxe  
  
```  
  
      function LineBeginsWith(   
   strBody,   
   strSearchString,   
   nStartPos    
);  
```  
  
#### Parâmetros  
 *strBody*  
 O corpo da função.  
  
 `strSearchString`  
 A seqüência de caracteres para localizar.  
  
 *nStartPos*  
 A posição inicial para a pesquisa.  
  
## Valor de retorno  
 **True** se a seqüência de caracteres for encontrada; Caso contrário,  **false**.  
  
## Comentários  
 Esta função é chamada `InsertIntoFunction` para determinar se a linha especificada começa com a seqüência de caracteres especificada.  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [OffsetToLineNumber](../ide/offsettolinenumber.md)