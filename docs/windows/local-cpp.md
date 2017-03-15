---
title: "local (C++) | Microsoft Docs"
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
  - "vc-attr.local"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "local attribute"
ms.assetid: 35cdd668-bd8e-492a-b7b8-263e7b662437
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# local (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando usado no cabeçalho da interface, permite que você use o compilador MIDL como um gerador de cabeçalho.  Quando usado em uma função individual, designa um procedimento de local para o qual nenhum fragmento de código é gerados.  
  
## Sintaxe  
  
```  
  
[local]  
  
```  
  
## Comentários  
 O `local` o atributo do C\+\+ tem a mesma funcionalidade que o  [local](http://msdn.microsoft.com/library/windows/desktop/aa367071) atributo MIDL.  
  
## Exemplo  
 Consulte  [call\_as](../windows/call-as.md) para obter um exemplo de como usar `local`.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|`interface`, método de interface|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|**dispinterface**|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Interface Attributes](../windows/interface-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [call\_as](../windows/call-as.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)