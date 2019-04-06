---
title: Threading (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.threading
helpviewer_keywords:
- threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
ms.openlocfilehash: cdebf06a62ebbd1d8648b9777fe200bc7a373261
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038272"
---
# <a name="threading-c"></a>threading (C++)

Especifica o modelo de threading para um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ threading(model=enumeration) ]
```

### <a name="parameters"></a>Parâmetros

*modelo*<br/>
(Opcional) Um dos seguintes modelos de threads:

- `apartment` (apartment threading)

- `neutral` (Componentes do .NET framework sem interface do usuário)

- `single` (threading simples)

- `free` (gratuito threading)

- `both` (apartment e threading livre)

O valor padrão é `apartment`.

## <a name="remarks"></a>Comentários

O **threading** atributo C++ não aparece no arquivo. idl gerado, mas será usado na implementação do seu objeto COM.

Em projetos ATL, se o [coclass](coclass.md) atributo também estiver presente, o modelo de threading especificado por *modelo* é passado como o parâmetro de modelo para o [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) classe , inseridos pelo `coclass` atributo.

O **threading** atributo também protege o acesso a um [event_source](event-source.md).

## <a name="example"></a>Exemplo

Consulte a [licenciado](licensed.md) exemplo para uso do exemplo **threading**.

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

[Atributos COM](com-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Suporte multithread para código anterior (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md)<br/>
[Apartments neutros](/windows/desktop/cossdk/neutral-apartments)