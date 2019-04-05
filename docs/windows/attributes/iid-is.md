---
title: iid_is (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.iid_is
helpviewer_keywords:
- iid_is attribute
ms.assetid: 2f9b42a9-7130-4b08-9b1e-0d5d360e10ff
ms.openlocfilehash: b91fb7937bb0e20f2500eace9695bc0ddba21b26
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038551"
---
# <a name="iidis"></a>iid_is

Especifica o IID da interface COM apontado por um ponteiro de interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ iid_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*expressão*<br/>
Uma expressão de linguagem C que especifica uma IID de uma interface COM apontado por um ponteiro de interface.

## <a name="remarks"></a>Comentários

O **iid_is** atributo C++ tem a mesma funcionalidade que o [iid_is](/windows/desktop/Midl/iid-is) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra o uso de **iid_is**:

```cpp
// cpp_attr_ref_iid_is.cpp
// compile with: /LD
#include "wtypes.h"
#include "unknwn.h"
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface IFireTabCtrl : IDispatch
{
   [id(1)] HRESULT CreateInstance([in] REFIID riid,[out, iid_is("riid")]
   IUnknown ** ppvObject);
};

[module(name="ATLFIRELib")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, membro de dados|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)