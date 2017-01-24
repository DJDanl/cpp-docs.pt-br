---
title: "bindable | Microsoft Docs"
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
  - "vc-attr.bindable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bindable attribute"
ms.assetid: a2360f92-927b-4af8-98cc-6eca7f4ec954
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# bindable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica que a propriedade oferece suporte a vinculação de dados.  
  
## Sintaxe  
  
```  
  
[bindable]  
  
```  
  
## Comentários  
 O  **ligáveis** o atributo do C\+\+ tem a mesma funcionalidade que o  [ligáveis](http://msdn.microsoft.com/library/windows/desktop/aa366738) atributo MIDL.  Você pode usá\-lo em propriedades definidas com o  [propget](../windows/propget.md),  [propput](../windows/propput.md), ou  [propputref](../windows/propputref.md) atributos, ou você pode definir um método ligável manualmente.  
  
 Os seguintes exemplos MFC mostram o uso de  **vinculáveis**:  
  
-   [Exemplos de controles: Controles de ActiveX com base em MFC](http://msdn.microsoft.com/pt-br/a44adf86-0ba0-4504-bedb-512b6cba2e63)  
  
-   [CIRC exemplo: Controle ActiveX](http://msdn.microsoft.com/pt-br/9ba34d04-280e-49f4-90ae-41a6be44c95b)  
  
-   [TESTHELP exemplo: Controle de ActiveX com dicas de ferramentas e ajuda](http://msdn.microsoft.com/pt-br/d822861d-c6f0-4d0a-ad11-970eebb1e8cd)  
  
## Exemplo  
 O código a seguir mostra como você pode usar  **vinculáveis** em uma propriedade:  
  
```  
// cpp_attr_ref_bindable.cpp  
// compile with: /LD  
#include <windows.h>  
[  
   uuid("479B29E3-9A2C-11D0-B696-00A0C903487A"),  
   dispinterface,  
   helpstring("property demo Interface")  
]  
__interface IPropDemo : IDispatch {  
  
   [propget, id(1), bindable, displaybind, defaultbind, requestedit] HRESULT P1([out, retval] long *nSize);  
   [propput, id(1), bindable, displaybind, defaultbind, requestedit] HRESULT P1([in] long nSize);  
   [id(3), bindable, propget] HRESULT Object([out, retval] IDispatch **ppObj);  
   [id(3), bindable, propputref] HRESULT Object([in] IDispatch* pObj);     
   [id(-552), helpstring("method AboutBox")] HRESULT AboutBox();  
};  
  
[ module(name="PropDemoLib", uuid="479B29E2-9A2C-11D0-B696-00A0C903487A", version="1.0", helpstring="property demo") ];  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Método de interface|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [defaultbind](../windows/defaultbind.md)   
 [displaybind](../windows/displaybind.md)   
 [immediatebind](../windows/immediatebind.md)   
 [requestedit](../windows/requestedit.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)