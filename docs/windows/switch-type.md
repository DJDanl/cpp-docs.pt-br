---
title: switch_type | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.switch_type
dev_langs: C++
helpviewer_keywords: switch_type attribute
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2b41a71483bc26d1a28476f24a47395ccd6b35d4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
