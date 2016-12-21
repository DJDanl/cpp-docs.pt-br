---
title: "custom (C++) | Microsoft Docs"
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
  - "vc-attr.custom"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "custom attributes, defining"
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# custom (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define os metadados para um objeto na biblioteca de tipos.  
  
## Sintaxe  
  
```  
  
      [ custom(  
   uuid,   
   value  
) ];  
```  
  
#### Parâmetros  
 *UUID*  
 Uma ID exclusiva.  
  
 *Valor*  
 Um valor que pode ser colocado em uma variante.  
  
## Comentários  
 O  **personalizado** atributo C\+\+ fará com que informações sejam colocadas em biblioteca de tipos.  Você precisará de uma ferramenta que lê o valor personalizado de biblioteca de tipos.  
  
 O  **personalizado** atributo tem a mesma funcionalidade que o  [personalizado](http://msdn.microsoft.com/library/windows/desktop/aa366766) atributo MIDL.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Non\-COM `interface`,  **classe**, `enum`s, `idl_module` métodos, os membros de interface, parâmetros de interface, `typedef`s,  **união**s, `struct`s|  
|**Reproduzíveis**|Sim|  
|**Atributos obrigatórios**|**coclass** \(quando usado na classe\)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Parameter Attributes](../windows/parameter-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Interface Attributes](../windows/interface-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)