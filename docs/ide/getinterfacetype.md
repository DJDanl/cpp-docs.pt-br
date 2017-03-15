---
title: "GetInterfaceType | Microsoft Docs"
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
  - "GetInterfaceType"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetInterfaceType"
ms.assetid: cc6403a8-0c2b-47f7-a8f7-9db95df87d5a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# GetInterfaceType
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o tipo de interface.  
  
## Sintaxe  
  
```  
  
      function GetInterfaceType(   
   oInterface    
);  
```  
  
#### Parâmetros  
 *oInterface*  
 A <xref:Microsoft.VisualStudio.VCCodeModel.VCCodeInterface> object.  
  
## Valor de retorno  
 A seqüência de caracteres indicando o tipo de interface, como, por exemplo, oleautomation, dual, dispinterface ou personalizada.  
  
## Comentários  
 Chame essa função para obter o tipo de interface.  
  
## Exemplo  
 Consulte  [GetMaxID](../ide/getmaxid.md).  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [GetInterfaceClasses](../Topic/GetInterfaceClasses.md)