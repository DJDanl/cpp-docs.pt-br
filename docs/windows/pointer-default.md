---
title: "pointer_default | Microsoft Docs"
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
  - "vc-attr.pointer_default"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pointer_default attribute"
ms.assetid: 2d0c7bbc-a1e8-4337-9e54-e304523e2735
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# pointer_default
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o atributo de ponteiro padrão para todos os ponteiros, exceto os ponteiros de nível superior que aparecem nas listas de parâmetro.  
  
## Sintaxe  
  
```  
  
      [ pointer_default(  
   value  
) ]  
```  
  
#### Parâmetros  
 *Valor*  
 Um valor que descreve o tipo de ponteiro:  **ptr**, `ref`, ou  **exclusivo**.  
  
## Comentários  
 O  **pointer\_default**  o atributo do C\+\+ tem a mesma funcionalidade que o  [pointer\_default](http://msdn.microsoft.com/library/windows/desktop/aa367141) atributo MIDL.  
  
## Exemplo  
 Consulte o exemplo para  [ValorPadrão](../Topic/defaultvalue.md) para uso do exemplo  **pointer\_default**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|`interface`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Interface Attributes](../windows/interface-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)