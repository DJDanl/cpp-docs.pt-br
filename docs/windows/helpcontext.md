---
title: "helpcontext | Microsoft Docs"
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
  - "vc-attr.helpcontext"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "helpcontext attribute"
ms.assetid: 6fbb022d-a4b7-4989-a02f-7f18a9b0ad96
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# helpcontext
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica uma identificação de contexto que permite que as informações de modo de exibição do usuário sobre este elemento no arquivo de Ajuda.  
  
## Sintaxe  
  
```  
  
      [ helpcontext(  
   id  
) ]  
```  
  
#### Parâmetros  
 `id`  
 A identificação de contexto do tópico da Ajuda.  Consulte [Ajuda em HTML: ajuda contextual para os programas](../mfc/html-help-context-sensitive-help-for-your-programs.md) para obter mais informações sobre identificações de contexto.  
  
## Comentários  
 O  **helpcontext** o atributo do C\+\+ tem a mesma funcionalidade que o  [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) atributo MIDL.  
  
## Exemplo  
 Consulte o exemplo para  [ValorPadrão](../Topic/defaultvalue.md) para obter um exemplo de como usar  **helpcontext**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|`interface`, `typedef`,  **classe**, método, propriedade|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Interface Attributes](../windows/interface-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [helpfile](../Topic/helpfile.md)   
 [helpstring](../windows/helpstring.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)