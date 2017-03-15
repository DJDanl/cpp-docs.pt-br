---
title: "pragma | Microsoft Docs"
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
  - "vc-attr.pragma"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pragma attribute"
ms.assetid: 3f90d023-b8b5-4007-8311-008bb72cbea1
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# pragma
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Emite a seqüência de caracteres especificada no arquivo. idl gerado sem o uso de aspas.  .  
  
## Sintaxe  
  
```  
  
      [ pragma(  
   pragma_statement  
) ];  
```  
  
#### Parâmetros  
 *pragma\_statement*  
 O pragma que você deseja ir para o arquivo. idl gerado.  
  
## Comentários  
 O  **pragma** o atributo do C\+\+ tem a mesma funcionalidade que o  [pragma](http://msdn.microsoft.com/library/windows/desktop/aa367143) atributo MIDL.  
  
## Exemplo  
  
```  
// cpp_attr_ref_pragma.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="MyLib")];  
[pragma(pack(4))];  
  
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]  
__interface A  
{  
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Em qualquer lugar|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [pack](../preprocessor/pack.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)