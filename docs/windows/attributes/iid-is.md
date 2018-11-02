---
title: iid_is (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.iid_is
helpviewer_keywords:
- iid_is attribute
ms.assetid: 2f9b42a9-7130-4b08-9b1e-0d5d360e10ff
ms.openlocfilehash: 176ab83bfae18ff7f43fe0860591f2d1ac50d7eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50535324"
---
# <a name="iidis"></a>iid_is

Especifica o IID da interface COM apontado por um ponteiro de interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ iid_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
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

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)