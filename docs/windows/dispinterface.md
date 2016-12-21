---
title: "dispinterface | Microsoft Docs"
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
  - "vc-attr.dispinterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atributo dispinterface"
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# dispinterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Coloca uma interface no arquivo. idl como uma interface de expedição.  
  
## Sintaxe  
  
```  
  
[dispinterface]  
  
```  
  
## Comentários  
 Quando o **dispinterface** atributo C\+\+ precede uma interface, ele faz com que a interface a ser colocado dentro do bloco de biblioteca no arquivo. idl gerado.  
  
 A menos que você especifique uma classe base, uma interface de expedição serão derivados de `IDispatch`. Você deve especificar um [id](../windows/id.md) para os membros de uma interface de expedição.  
  
 O exemplo de uso de [dispinterface](http://msdn.microsoft.com/library/windows/desktop/aa366802) na documentação do MIDL:  
  
```  
dispinterface helloPro   
   { interface hello; };   
```  
  
 não é válido para o **dispinterface** atributo.  
  
## Exemplo  
 Consulte o exemplo para [vinculáveis](../windows/bindable.md) para obter um exemplo de como usar **dispinterface**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Aplica\-se a**|`interface`|  
|**Repetível**|Não|  
|**Atributos necessários**|Nenhum|  
|**Atributos inválidos**|**dual**, **objeto**, **oleautomation**, `local`, **ms\_union**|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Attributes by Usage](../windows/attributes-by-usage.md)   
 [uuid](../windows/uuid-cpp-attributes.md)   
 [dual](../Topic/dual.md)   
 [custom](../windows/custom-cpp.md)   
 [object](../Topic/object%20\(C++\).md)   
 [\_\_interface](../Topic/__interface.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)