---
title: defaultvtable (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.defaultvtable
helpviewer_keywords:
- defaultvtable attribute
ms.assetid: 5b3ed483-f69e-44dd-80fc-952028eb9d73
ms.openlocfilehash: 8ab37af4deab516dc01f55f986811668737cf18c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501641"
---
# <a name="defaultvtable"></a>defaultvtable

Define uma interface como a interface vtable padrão para um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ defaultvtable(interface) ]
```

### <a name="parameters"></a>Parâmetros

*interface*<br/>
A interface designada que você deseja ter a vtable padrão para o objeto COM.

## <a name="remarks"></a>Comentários

O atributo **defaultvtable** C++ tem a mesma funcionalidade que o atributo MIDL de [defaultvtable](/windows/win32/Midl/defaultvtable) .

## <a name="example"></a>Exemplo

O código a seguir mostra atributos em uma classe que usa **defaultvtable** para especificar uma interface padrão:

```cpp
// cpp_attr_ref_defaultvtable.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyI1 {
   HRESULT x();
};

[object, uuid("00000000-0000-0000-0000-000000000002")]
__interface IMyI2 {
   HRESULT x();
};

[object, uuid("00000000-0000-0000-0000-000000000003")]
__interface IMyI3 {
   HRESULT x();
};

[coclass, source(IMyI3, IMyI1), default(IMyI3, IMyI2), defaultvtable(IMyI1),
uuid("00000000-0000-0000-0000-000000000004")]
class CMyC3 : public IMyI3 {};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)