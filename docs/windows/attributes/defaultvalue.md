---
title: DefaultValue (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.defaultvalue
helpviewer_keywords:
- defaultvalue attribute
ms.assetid: efa5d050-b2cc-4d9e-9b8e-79954f218d3a
ms.openlocfilehash: 53b6a50bd7156eb9d6873e5ef08f6d75508fa3e1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841682"
---
# <a name="defaultvalue"></a>defaultvalue

Permite a especificação de um valor padrão para um parâmetro opcional tipado.

## <a name="syntax"></a>Sintaxe

```cpp
[ defaultvalue= value ]
```

### <a name="parameters"></a>parâmetros

*value*<br/>
O valor padrão do parâmetro.

## <a name="remarks"></a>Comentários

O atributo **DefaultValue** C++ tem a mesma funcionalidade que o atributo MIDL de [DefaultValue](/windows/win32/Midl/defaultvalue) .

## <a name="example"></a>Exemplo

O código a seguir mostra um método de interface usando o atributo **DefaultValue** :

```cpp
// cpp_attr_ref_defaultvalue.cpp
// compile with: /LD
#include <windows.h>

[export] typedef long HRESULT;
[export, ptr, string] typedef unsigned char * MY_STRING_TYPE;

[  uuid("479B29EE-9A2C-11D0-B696-00A0C903487A"), dual, oleautomation, helpstring("IFireTabCtrl Interface"), helpcontext(122), pointer_default(unique) ]

__interface IFireTabCtrl : IDispatch {
   [bindable, propget] HRESULT get_Size([out, retval, defaultvalue("33")] long *nSize);
   [bindable, propput] HRESULT put_Size([in] int nSize);
};

[ module(name="ATLFIRELib", uuid="479B29E1-9A2C-11D0-B696-00A0C903487A",    version="1.0", helpstring="ATLFire 1.0 Type Library") ];
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[fora](out-cpp.md)<br/>
[retval](retval.md)<br/>
[Em](in-cpp.md)<br/>
[pointer_default](pointer-default.md)<br/>
[unique](unique-cpp.md)
