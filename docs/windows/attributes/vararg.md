---
title: vararg (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.vararg
helpviewer_keywords:
- vararg attribute
ms.assetid: 20fc3244-18e9-411c-990e-d5b4fa29a570
ms.openlocfilehash: edfcfdb32abeaff487134eac35033117b470d7d2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832965"
---
# <a name="vararg"></a>vararg

Especifica que a função usa um número variável de argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
[vararg]
```

## <a name="remarks"></a>Comentários

O atributo **vararg** C++ tem a mesma funcionalidade que o atributo MIDL de [vararg](/windows/win32/Midl/vararg) .

## <a name="example"></a>Exemplo

O código a seguir mostra um uso de **vararg**:

```cpp
// cpp_attr_ref_vararg.cpp
// compile with: /LD
#include "unknwn.h"
#include "oaidl.h"
[module(name="MyLibrary")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface X : public IUnknown
{
   [vararg] HRESULT Button([in, satype(VARIANT)]SAFEARRAY *psa);
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos do método](method-attributes.md)
