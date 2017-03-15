---
title: "InsertIntoFunction | Microsoft Docs"
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
  - "InsertIntoFunction"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método InsertIntoFunction"
ms.assetid: 50500c3c-bee3-4a9c-a403-7dcd752de23c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# InsertIntoFunction
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usado por  [AddATLSupportToProject](../ide/addatlsupporttoproject.md) para inserir o código em  [InitInstance](../Topic/CWinApp::InitInstance.md).  
  
## Sintaxe  
  
```  
  
      function InsertIntoFunction(   
   oFunction,   
   strSearchString,   
   nStartLine,   
   nEndLine,   
   bInsideIfBlock    
);  
```  
  
#### Parâmetros  
 *oFunction*  
 O objeto de função na qual a inserção é feita.  
  
 `strSearchString`  
 A seqüência de caracteres para localizar para determinar o ponto de inserção.  
  
 *nStartLine*  
 A linha inicial para passar para  [GetCodeForInitInstance](../ide/getcodeforinitinstance.md).  
  
 *nEndLine*  
 Final de linha para passar para  [GetCodeForInitInstance](../ide/getcodeforinitinstance.md).  
  
 *bInsideIfBlock*  
 Indica se a inserção está em um bloco de função.  
  
## Valor de retorno  
 **True** se for bem sucedida; Caso contrário,  **false**.  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [GetMemberfunction](../Topic/GetMemberfunction.md)