---
title: restrito | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.restricted
dev_langs:
- C++
helpviewer_keywords:
- restricted attribute
ms.assetid: 504a96be-b904-4269-8be1-920feba201b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e8d226f508f5f5e8c717bd671413f21377c0ae01
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43202284"
---
# <a name="restricted"></a>restricted

Especifica que um membro de um módulo, interface ou dispinterface não pode ser chamado arbitrariamente.

## <a name="syntax"></a>Sintaxe

```cpp
[ restricted(
   interfaces
) ]
```

### <a name="parameters"></a>Parâmetros

*interfaces*  
Uma ou mais interfaces que não podem ser chamadas arbitrariamente em um objeto COM. Esse parâmetro só é válido quando aplicado a uma classe.

## <a name="remarks"></a>Comentários

O **restrito** atributo C++ tem a mesma funcionalidade que o [restrito](/windows/desktop/Midl/restricted) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **restrito** atributo:

```cpp
// cpp_attr_ref_restricted.cpp
// compile with: /LD
#include "windows.h"
#include "unknwn.h"
[module(name="MyLib")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface a
{
};

[object, uuid("00000000-0000-0000-0000-000000000002")]
__interface b
{
};

[coclass, restricted(a,b), uuid("00000000-0000-0000-0000-000000000003")]
class c : public a, public b
{
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método, de interface **interface**, **classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **classe** ou **struct**)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  