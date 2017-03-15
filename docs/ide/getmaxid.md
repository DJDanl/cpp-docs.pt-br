---
title: "GetMaxID | Microsoft Docs"
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
  - "GetMaxID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetMaxID"
ms.assetid: a155ec2e-6132-4e40-9b85-d710538778a1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# GetMaxID
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o dispid mais alto de membros nesta interface e todas as suas bases.  
  
## Sintaxe  
  
```  
  
      function GetMaxID(   
   ointerface    
);  
```  
  
#### Parâmetros  
 *ointerface*  
 A <xref:Microsoft.VisualStudio.VCCodeModel.VCCodeInterface> object.  
  
## Valor de retorno  
 O mais alto dispid partir dos membros do  *oInterface* e todas as suas bases.  
  
## Comentários  
 Chame essa função para obter o mais alto dispid dos membros de interface especificada e todas as suas bases.  
  
## Exemplo  
  
```  
if (strInterfaceType == "custom")  
      window.external.AddSymbol("DISPID_DISABLED", true);  
   else  
   {  
      var nDispID = window.external.FindSymbol("DISPID");  
      if (!nDispID.length)  
      {  
         nDispID = GetMaxID(oInterface) + 1;  
         window.external.AddSymbol("DISPID", nDispID);  
      }  
   }  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)