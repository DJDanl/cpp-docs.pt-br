---
title: ReadOnly (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.readonly
dev_langs:
- C++
helpviewer_keywords:
- readonly attribute
ms.assetid: 1246cadd-5304-43a9-beea-51153d12704d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 93a7adbca8c659a757e0e8fbb05b8fb926b237d2
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210304"
---
# <a name="readonly-c"></a>readonly (C++)

Proíbe a atribuição a um membro de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[readonly]
```

## <a name="remarks"></a>Comentários

O **readonly** atributo C++ tem a mesma funcionalidade que o [readonly](/windows/desktop/Midl/readonly) atributo MIDL.

Se você quiser impedir a modificação de um parâmetro de método, em seguida, use o [em](../windows/in-cpp.md) atributo.

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do **readonly** atributo:

```cpp
// cpp_attr_ref_readonly.cpp
// compile with: /LD
[idl_quote("midl_pragma warning(disable:2461)")];
#include "unknwn.h"
[module(name="ATLFIRELib")];

[dispinterface, uuid(11111111-1111-1111-1111-111111111111)]
__interface IFireTabCtrl
{
   [readonly, id(1)] int i();
};
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

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de membro de dados](../windows/data-member-attributes.md)  