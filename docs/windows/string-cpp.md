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
ms.openlocfilehash: 86a6437e7a30fb92d2af66c3d657150549273cd3
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208443"
---
# <a name="string-c"></a>string (C++)

Indica que o unidimensional **char**, **wchar_t**, `byte` (ou equivalente) matriz ou o ponteiro para essa matriz deve ser tratado como uma cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
[string]
```

## <a name="remarks"></a>Comentários

O **cadeia de caracteres** atributo C++ tem a mesma funcionalidade que o [cadeia de caracteres](/windows/desktop/Midl/string) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar **cadeia de caracteres** em uma interface e em um typedef:

```cpp
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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Matriz ou ponteiro para uma matriz, o parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de matriz](../windows/array-attributes.md)  
[export](../windows/export.md)  