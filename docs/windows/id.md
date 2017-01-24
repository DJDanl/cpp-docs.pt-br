---
title: "id | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.id"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "id attribute"
ms.assetid: a48d2c99-c5d2-4f46-bf96-5ac88dcb5d0c
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# id
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um `dispid` parâmetro de uma função de membro \(uma propriedade ou um método, em uma interface ou um dispinterface\).  
  
## Sintaxe  
  
```  
  
      [ id(  
   dispid  
) ]  
```  
  
#### Parâmetros  
 `dispid`  
 A identificação de expedição para o método de interface.  
  
## Comentários  
 O  **id** o atributo do C\+\+ tem a mesma funcionalidade que o  [id](http://msdn.microsoft.com/library/windows/desktop/aa367040) atributo MIDL.  
  
## Exemplo  
 Consulte o exemplo para  [vinculáveis](../windows/bindable.md) para obter um exemplo de como usar  **id**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Método de interface|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [Data Member Attributes](../windows/data-member-attributes.md)   
 [defaultvalue](../Topic/defaultvalue.md)   
 [in](../Topic/in%20\(C++\).md)   
 [out](../Topic/out%20\(C++\).md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)