---
title: controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.control
dev_langs: C++
helpviewer_keywords: Control attribute
ms.assetid: 3d046bb2-4afe-4cb8-a762-233b296e1975
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 72326b5ce7aedfd03f93688e7890fdfab9b827f0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="control"></a>Controle 
Especifica que o tipo definido pelo usuário é um controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[control]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **controle** atributo implica o [coclass](../windows/coclass.md) atributo. O **controle** atributo C++ tem a mesma funcionalidade que o [controle](http://msdn.microsoft.com/library/windows/desktop/aa366764) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_control.cpp  
// compile with: /LD  
#include <windows.h>  
[module(name="Test", control=true)];  
  
[object, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb")]  
__interface ICustom {  
   HRESULT Custom([in] long l, [out, retval] long *pLong);  
};  
  
[coclass, control, appobject, uuid("9e66a294-4365-11d2-a997-00c04fa37ddb")]  
class CTest : public ICustom {};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)   
