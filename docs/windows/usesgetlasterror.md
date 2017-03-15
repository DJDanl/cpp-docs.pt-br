---
title: "usesgetlasterror | Microsoft Docs"
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
  - "vc-attr.usesgetlasterror"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "usesgetlasterror attribute"
ms.assetid: d149e33d-35a7-46cb-9137-ae6883d86122
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# usesgetlasterror
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Informa ao chamador que se houver um erro ao chamar essa função, em seguida, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.  
  
## Sintaxe  
  
```  
  
[usesgetlasterror]  
  
```  
  
## Comentários  
 O  **usesgetlasterror** o atributo do C\+\+ tem a mesma funcionalidade que o  [usesgetlasterror](http://msdn.microsoft.com/library/windows/desktop/aa367297) atributo MIDL.  
  
## Exemplo  
 Consulte o  [idl\_module](../windows/idl-module.md) exemplo, para obter um exemplo de como usar o  **usesgetlasterror**.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**módulo** atributo|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)