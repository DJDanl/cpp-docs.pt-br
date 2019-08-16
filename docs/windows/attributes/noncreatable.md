---
title: Não-cri (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.noncreatable
helpviewer_keywords:
- noncreatable attribute
ms.assetid: 4d17937b-0bff-41af-ba57-53e18b7ab5a9
ms.openlocfilehash: e855497cb6f619ecdaa6aedf16a04f045a60faa7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514566"
---
# <a name="noncreatable"></a>noncreatable

Define um objeto que não pode ser instanciado por si só.

## <a name="syntax"></a>Sintaxe

```cpp
[noncreatable]
```

## <a name="remarks"></a>Comentários

O C++ atributo não-cri tem a mesma funcionalidade que o atributo MIDL não- [cri](/windows/win32/Midl/noncreatable) e é passado automaticamente para o gerado. Arquivo IDL pelo compilador.

Quando esse atributo é usado em um projeto que usa ATL, o comportamento do atributo é alterado. Além do comportamento acima, o atributo também injeta a macro [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) . Essa macro indica ao ATL que o objeto não pode ser criado externamente.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_noncreatable.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[object, uuid("11111111-1111-1111-1111-111111111111")]
__interface A
{
};

[coclass, uuid("11111111-1111-1111-1111-111111111112"), noncreatable]
class CMyClass : public A
{
   HRESULT xx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
