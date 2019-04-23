---
title: dispinterface (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.dispinterface
helpviewer_keywords:
- dispinterface attribute
ms.assetid: 61c5a4a1-ae92-47e9-8ee4-f847be90172b
ms.openlocfilehash: 6fd5010dc20d03c518206d81919e3beafbcaa9a9
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038454"
---
# <a name="dispinterface"></a>dispinterface

Coloca uma interface no arquivo. idl como uma interface de expedição.

## <a name="syntax"></a>Sintaxe

```cpp
[dispinterface]
```

## <a name="remarks"></a>Comentários

Quando o **dispinterface** atributo C++ precede uma interface, ele faz com que a interface a ser colocado dentro do bloco de biblioteca no arquivo. idl gerado.

A menos que você especifique uma classe base, uma interface de expedição será derivado `IDispatch`. Você deve especificar um [id](id.md) para os membros de uma interface de expedição.

O exemplo de uso de [dispinterface](/windows/desktop/Midl/dispinterface) na documentação do MIDL:

```cpp
dispinterface helloPro
   { interface hello; };
```

não é válido para o **dispinterface** atributo.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para obter um exemplo de como usar **dispinterface**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`dual`, `object`, `oleautomation`, `local`, `ms_union`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[uuid](uuid-cpp-attributes.md)<br/>
[dual](dual.md)<br/>
[custom](custom-cpp.md)<br/>
[object](object-cpp.md)<br/>
[__interface](../../cpp/interface.md)