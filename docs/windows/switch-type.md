---
title: switch_type | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.switch_type
dev_langs:
- C++
helpviewer_keywords:
- switch_type attribute
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1870e1ee623d8495e9f19dd8f32ea9382070bc14
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890171"
---
# <a name="switchtype"></a>switch_type
Identifica o tipo da variável usado como o discriminador de união.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[switch_type(  
type  
}]  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 O tipo de comutador, pode ser um tipo de caractere, inteiro, booliano ou enumeração.  
  
## <a name="remarks"></a>Comentários  
 O **switch_type** atributo C++ tem a mesma funcionalidade que o [switch_type](http://msdn.microsoft.com/library/windows/desktop/aa367276) atributo MIDL.  
  
 Não oferecem suporte a atributos C++ [encapsulado uniões](http://msdn.microsoft.com/library/windows/desktop/aa366811). [Uniões nonencapsulated](http://msdn.microsoft.com/library/windows/desktop/aa367119) têm suporte apenas no seguinte formato:  
  
```  
// cpp_attr_ref_switch_type.cpp  
// compile with: /LD  
#include <windows.h>  
[module(name="MyLibrary")];  
[ export ]  
struct SizedValue2 {  
   [switch_type("char"), switch_is(kind)] union {  
      [case(1), string]  
         wchar_t* wval;  
      [default, string]  
         char* val;  
   };  
   char kind;  
};  
```  
  
## <a name="example"></a>Exemplo  
 Consulte o [caso](../windows/case-cpp.md) exemplo para uso do exemplo **switch_type**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`typedef`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [export](../windows/export.md)   
