---
title: cadeia de caracteres (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.string
dev_langs:
- C++
helpviewer_keywords:
- string attribute
ms.assetid: ddde900a-2e99-4fcd-86e8-57e1bdba7c93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6bdcdc6557253f8be9c6ecb20300f2338ab35d07
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889014"
---
# <a name="string-c"></a>string (C++)
Indica que o unidimensional `char`, `wchar_t`, **bytes** (ou equivalente) array ou ponteiro para essa matriz deve ser tratado como uma cadeia de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[string]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **cadeia de caracteres** atributo C++ tem a mesma funcionalidade que o [cadeia de caracteres](http://msdn.microsoft.com/library/windows/desktop/aa367270) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar **cadeia de caracteres** em uma interface e em um typedef:  
  
```  
// cpp_attr_ref_string.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="ATLFIRELib")];  
[export, string] typedef char a[21];  
[dispinterface, restricted, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IFireTabCtrl  
{  
   [id(1)] HRESULT Method3([in, string] char *pC);  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Matriz ou ponteiro para uma matriz, o parâmetro de interface, o método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de matriz](../windows/array-attributes.md)   
 [export](../windows/export.md)   
