---
title: associável | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.bindable
dev_langs:
- C++
helpviewer_keywords:
- bindable attribute
ms.assetid: a2360f92-927b-4af8-98cc-6eca7f4ec954
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ece97ee2709cd16acc4625c11667fd2c43e9dee8
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643089"
---
# <a name="bindable"></a>bindable
Indica que a propriedade dá suporte à associação de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[bindable]  
```  
  
## <a name="remarks"></a>Comentários  
 O **associável** atributo C++ tem a mesma funcionalidade que o [associável](http://msdn.microsoft.com/library/windows/desktop/aa366738) atributo MIDL. Você pode usá-lo nas propriedades definidas com o [propget](../windows/propget.md), [propput](../windows/propput.md), ou [propputref](../windows/propputref.md) atributos, ou você pode definir um método associável manualmente.  
  
 Os exemplos MFC a seguir mostram o uso do **associável**:  
  
-   [Exemplos de controles: Controles do ActiveX do MFC com base](http://msdn.microsoft.com/a44adf86-0ba0-4504-bedb-512b6cba2e63)  
  
-   [Exemplo c: Controle ActiveX](http://msdn.microsoft.com/9ba34d04-280e-49f4-90ae-41a6be44c95b)  
  
-   [TESTHELP exemplo: Controle de ActiveX com dicas de ferramenta e a Ajuda](http://msdn.microsoft.com/d822861d-c6f0-4d0a-ad11-970eebb1e8cd)  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como você pode usar **associável** em uma propriedade:  
  
```cpp  
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
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Método de interface|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [defaultbind](../windows/defaultbind.md)   
 [displaybind](../windows/displaybind.md)   
 [immediatebind](../windows/immediatebind.md)   
 [requestedit](../windows/requestedit.md)   