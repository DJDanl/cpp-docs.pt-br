---
title: iid_is (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.iid_is
helpviewer_keywords:
- iid_is attribute
ms.assetid: 2f9b42a9-7130-4b08-9b1e-0d5d360e10ff
ms.openlocfilehash: 627ecff4835386dc70a9f3dfac0500404a84eefe
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167986"
---
# <a name="iid_is"></a>iid_is

Especifica o IID da interface COM apontada por um ponteiro de interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ iid_is("expression") ]
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
Uma expressão de linguagem C que especifica um IID de uma interface COM apontada por um ponteiro de interface.

## <a name="remarks"></a>Comentários

O atributo **iid_is** C++ tem a mesma funcionalidade que o atributo MIDL [iid_is](/windows/win32/Midl/iid-is) .

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, membro de dados|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)
