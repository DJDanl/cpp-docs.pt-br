---
title: Restricted (atributo COM do C++)
ms.date: 10/03/2018
f1_keywords:
- vc-attr.restricted
helpviewer_keywords:
- restricted attribute
ms.assetid: 504a96be-b904-4269-8be1-920feba201b4
ms.openlocfilehash: a1f543c4d8edac751195d37414c030dfe2df94fa
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846349"
---
# <a name="restricted"></a>restricted

Especifica que um membro de um módulo, interface ou Dispinterface não pode ser chamado arbitrariamente.

## <a name="syntax"></a>Sintaxe

```cpp
[ restricted(
   interfaces
) ]
```

### <a name="parameters"></a>parâmetros

*interfaces*<br/>
Uma ou mais interfaces que podem não ser chamadas arbitrariamente em um objeto COM. Esse parâmetro só é válido quando aplicado a uma classe.

## <a name="remarks"></a>Comentários

O atributo C++ **restrito** tem a mesma funcionalidade que o atributo MIDL [restrito](/windows/win32/Midl/restricted) .

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o atributo **restrito** :

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de interface, **interface**, **`class`** , **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **`class`** or **`struct`** )|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos do método](method-attributes.md)
