---
title: não passível de criação (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.noncreatable
helpviewer_keywords:
- noncreatable attribute
ms.assetid: 4d17937b-0bff-41af-ba57-53e18b7ab5a9
ms.openlocfilehash: a10d93650c0ae564019a09b34c3a604d12327998
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59039985"
---
# <a name="noncreatable"></a>noncreatable

Define um objeto que não pode ser instanciado por si só.

## <a name="syntax"></a>Sintaxe

```cpp
[noncreatable]
```

## <a name="remarks"></a>Comentários

O **noncreatable** atributo C++ tem a mesma funcionalidade que o [noncreatable](/windows/desktop/Midl/noncreatable) atributo MIDL e é passado para o gerado automaticamente. Arquivo IDL pelo compilador.

Quando esse atributo é usado dentro de um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento acima, o atributo também injeta a [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro. Essa macro indica ao ATL que o objeto não pode ser criado externamente.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
