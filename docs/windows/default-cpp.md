---
title: "padrão (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.default
dev_langs: C++
helpviewer_keywords:
- default attribute
- attributes [C#], default attribute
- defaults, default attribute
ms.assetid: 0cdca716-1ba8-46d7-9399-167e55492870
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6b24b0ed9b8e547a52388b6f93a4955da782331b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="default-c"></a>default (C++)
Indica que o personalizado ou dispinterface definidos em uma coclass representa a interface de programação padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ default(  
   interface1,  
   interface2  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Interface1*  
 A interface padrão que será disponibilizada para os ambientes de script que cria um objeto com base na classe definida com o **padrão** atributo.  
  
 Se nenhuma interface padrão for especificado, a primeira ocorrência de uma interface nonsource é usada como o padrão.  
  
 *Interface2*(opcional)  
 A interface de origem padrão. Você também deve especificar essa interface com o [fonte](../windows/source-cpp.md) atributo.  
  
 Se nenhuma interface de origem padrão for especificado, a primeira interface de origem é usada como o padrão.  
  
## <a name="remarks"></a>Comentários  
 O **padrão** atributo C++ tem a mesma funcionalidade que o [padrão](http://msdn.microsoft.com/library/windows/desktop/aa366787) atributo MIDL. O **padrão** atributo também é usado com o [caso](../windows/case-cpp.md) atributo.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como **padrão** é usado na definição de uma coclass para especificar **ICustomDispatch** como a interface de programação padrão:  
  
```  
// cpp_attr_ref_default.cpp  
// compile with: /LD  
#include "windows.h"  
[module(name="MyLibrary")];  
  
[object, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]  
__interface ICustom {  
   HRESULT Custom([in] long l, [out, retval] long *pLong);  
};  
  
[dual, uuid("9E66A291-4365-11D2-A997-00C04FA37DDB")]   
__interface IDual {  
   HRESULT Dual([in] long l, [out, retval] long *pLong);  
};  
  
[object, uuid("9E66A293-4365-11D2-A997-00C04FA37DDB")]  
__interface ICustomDispatch : public IDispatch {  
   HRESULT Dispatch([in] long l, [out, retval] long *pLong);  
};  
  
[   coclass,  
   default(ICustomDispatch),   
   source(IDual),  
   uuid("9E66A294-4365-11D2-A997-00C04FA37DDB")  
]  
class CClass : public ICustom, public IDual, public ICustomDispatch {  
   HRESULT Custom(long l, long *pLong) { return(S_OK); }  
   HRESULT Dual(long l, long *pLong) { return(S_OK); }  
   HRESULT Dispatch(long l, long *pLong) { return(S_OK); }  
};  
  
int main() {  
#if 0 // Can't instantiate without implementations of IUnknown/IDispatch  
   CClass *pClass = new CClass;  
  
   long llong;  
  
   pClass->custom(1, &llong);  
   pClass->dual(1, &llong);  
   pClass->dispinterface(1, &llong);  
   pClass->dispatch(1, &llong);  
  
   delete pClass;  
#endif  
   return(0);  
}  
```  
  
 O [fonte](../windows/source-cpp.md) atributo também apresenta um exemplo de como usar **padrão**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, membro de dados|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass** (quando aplicado a **classe** ou `struct`)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [coclass](../windows/coclass.md)   
