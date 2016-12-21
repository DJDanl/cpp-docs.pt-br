---
title: "IncludeCodeElementDeclaration | Microsoft Docs"
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
  - "IncludeCodeElementDeclaration"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método IncludeCodeElementDeclaration"
ms.assetid: 714e76e4-76bc-439a-982a-cf9d4ada7677
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IncludeCodeElementDeclaration
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona a instrução include para `strInFile`, incluindo o cabeçalho onde `strCodeElemName` é implementado, se tal um cabeçalho encontrado na `oProj`.  
  
## Sintaxe  
  
```  
  
      function IncludeCodeElementDeclaration(   
   oProj,   
   strCodeElemName,   
   strInFile    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
 `strCodeElemName`  
 O nome completo do elemento do código que você está pesquisando o cabeçalho de definição.  
  
 `strInFile`  
 O arquivo que incluirão o cabeçalho de definição, se encontrado.  
  
## Comentários  
 Adiciona a instrução include para `strInFile`, incluindo o cabeçalho onde `strCodeElemName` é implementado, se tal um cabeçalho encontrado em `oProj`.  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)