---
title: Restricted (C++ atributo com)
ms.date: 10/03/2018
f1_keywords:
- vc-attr.restricted
helpviewer_keywords:
- restricted attribute
ms.assetid: 504a96be-b904-4269-8be1-920feba201b4
ms.openlocfilehash: 01dabcd15eb1a14734c16b9e54c0ab2e030d0479
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514067"
---
# <a name="restricted"></a>restricted

Especifica que um membro de um módulo, interface ou Dispinterface não pode ser chamado arbitrariamente.

## <a name="syntax"></a>Sintaxe

```cpp
[ restricted(
   interfaces
) ]
```

### <a name="parameters"></a>Parâmetros

*interfaces*<br/>
Uma ou mais interfaces que podem não ser chamadas arbitrariamente em um objeto COM. Esse parâmetro só é válido quando aplicado a uma classe.

## <a name="remarks"></a>Comentários

O atributo **restrito** C++ tem a mesma funcionalidade que o atributo MIDL [restrito](/windows/win32/Midl/restricted) .

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método de interface, **interface**, **classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|**coclass** (quando aplicado à **classe** ou **estrutura**)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de método](method-attributes.md)