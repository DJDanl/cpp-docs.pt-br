---
title: "defaultvtable | Microsoft Docs"
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
  - "vc-attr.defaultvtable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "defaultvtable attribute"
ms.assetid: 5b3ed483-f69e-44dd-80fc-952028eb9d73
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# defaultvtable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define uma interface como interface padrão vtable para um objeto COM.  
  
## Sintaxe  
  
```  
  
      [ defaultvtable(  
   interface  
) ]  
```  
  
#### Parâmetros  
 `interface`  
 A interface designada que você deseja ter o vtable padrão do objeto COM.  
  
## Comentários  
 O  **defaultvtable** o atributo do C\+\+ tem a mesma funcionalidade que o  [defaultvtable](http://msdn.microsoft.com/library/windows/desktop/aa366795) atributo MIDL.  
  
## Exemplo  
 O código a seguir mostra os atributos em uma classe que usam  **defaultvtable** para especificar uma interface padrão:  
  
```  
// cpp_attr_ref_defaultvtable.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLib")];  
  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IMyI1 {  
   HRESULT x();  
};  
  
[object, uuid("00000000-0000-0000-0000-000000000002")]  
__interface IMyI2 {  
   HRESULT x();  
};  
  
[object, uuid("00000000-0000-0000-0000-000000000003")]  
__interface IMyI3 {  
   HRESULT x();  
};  
  
[coclass, source(IMyI3, IMyI1), default(IMyI3, IMyI2), defaultvtable(IMyI1),  
uuid("00000000-0000-0000-0000-000000000004")]  
class CMyC3 : public IMyI3 {};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|**coclass**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)