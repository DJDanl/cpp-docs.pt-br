---
title: padrão (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.default
helpviewer_keywords:
- default attribute
- attributes [C#], default attribute
- defaults, default attribute
ms.assetid: 0cdca716-1ba8-46d7-9399-167e55492870
ms.openlocfilehash: b53420d721b43f9a51b19c4cc8e4a83fc8b94ed4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842436"
---
# <a name="default-c"></a>default (C++)

Indica que a dispinterface ou personalizada definida em uma coclass representa a interface de programação padrão.

## <a name="syntax"></a>Sintaxe

```cpp
[ default(interface1, interface2) ]
```

### <a name="parameters"></a>parâmetros

*interface1*<br/>
A interface padrão que será disponibilizada para os ambientes de script que criam um objeto com base na classe definida com o **`default`** atributo.

Se nenhuma interface padrão for especificada, a primeira ocorrência de uma interface não-de-fonte será usada como padrão.

*interface2*<br/>
Adicional A interface de origem padrão. Você também deve especificar essa interface com o atributo de [origem](source-cpp.md) .

Se nenhuma interface de origem padrão for especificada, a primeira interface de origem será usada como padrão.

## <a name="remarks"></a>Comentários

O **`default`** atributo C++ tem a mesma funcionalidade que o atributo MIDL [padrão](/windows/win32/Midl/default) . O **`default`** atributo também é usado com o atributo [Case](case-cpp.md) .

## <a name="example"></a>Exemplo

O código a seguir mostra como o **`default`** é usado na definição de uma coclass para especificar `ICustomDispatch` como a interface de programação padrão:

```cpp
// cpp_attr_ref_default.cpp
// compile with: /LD
#include "windows.h"
[module(name="MyLibrary")];

[object, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]
__interface ICustom {
   HRESULT Custom([in] long l, [out, retval] long *pLong);
};

[dual, uuid("9E66A291-4365-11D2-A997-00C04FA37DDB")]
__interface IDual {
   HRESULT Dual([in] long l, [out, retval] long *pLong);
};

[object, uuid("9E66A293-4365-11D2-A997-00C04FA37DDB")]
__interface ICustomDispatch : public IDispatch {
   HRESULT Dispatch([in] long l, [out, retval] long *pLong);
};

[   coclass, default(ICustomDispatch), source(IDual), uuid("9E66A294-4365-11D2-A997-00C04FA37DDB")
]
class CClass : public ICustom, public IDual, public ICustomDispatch {
   HRESULT Custom(long l, long *pLong) { return(S_OK); }
   HRESULT Dual(long l, long *pLong) { return(S_OK); }
   HRESULT Dispatch(long l, long *pLong) { return(S_OK); }
};

int main() {
#if 0 // Can't instantiate without implementations of IUnknown/IDispatch
   CClass *pClass = new CClass;

   long llong;

   pClass->custom(1, &llong);
   pClass->dual(1, &llong);
   pClass->dispinterface(1, &llong);
   pClass->dispatch(1, &llong);

   delete pClass;
#endif
   return(0);
}
```

O atributo de [origem](source-cpp.md) também tem um exemplo de como usar **`default`** .

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`** , membro de dados|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** (quando aplicado a **`class`** or **`struct`** )|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[coclass](coclass.md)
