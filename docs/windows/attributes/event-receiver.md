---
title: event_receiver (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.event_receiver
helpviewer_keywords:
- event_receiver attribute
- event receivers
- events [C++], event receivers (sinks)
- event handling [C++], attributes
- event handling [C++], creating receiver
- event sinks, creating
- event sinks
ms.assetid: bf8fe770-3ea2-4128-b46b-166222ee4097
ms.openlocfilehash: 7280729a9ae3a054468e1f11bdcc4a563b32effe
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845283"
---
# <a name="event_receiver"></a>event_receiver

Cria um receptor de eventos (coletor).

## <a name="syntax"></a>Sintaxe

```cpp
[ event_receiver(type
   [, layout_dependent=false]) ]
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
Uma enumeração de um dos seguintes valores:

- `native` para código C/C++ não gerenciado (padrão para classes nativas).

- `com` para o código COM. Esse valor requer que você inclua os seguintes arquivos de cabeçalho:

    ```cpp
    #define _ATL_ATTRIBUTES
    #include <atlbase.h>
    #include <atlcom.h>
    ```

*layout_dependent*<br/>
Especifique *layout_dependent* somente se `type` = **com**. *layout_dependent* é um booliano:

- **`true`** significa que a assinatura dos delegados no receptor de eventos deve corresponder exatamente àqueles aos quais eles são conectados na origem do evento. Os nomes do manipulador do receptor de eventos devem corresponder aos nomes especificados na interface de origem do evento relevante. Você deve usar `coclass` quando *layout_dependent* é **`true`** . É um pouco mais eficiente especificar **`true`** .

- **`false`** (padrão) significa que a Convenção de chamada e a classe de armazenamento (virtual, estática e outras) não precisam corresponder ao método de evento e aos manipuladores; Nem os nomes dos manipuladores precisam corresponder aos nomes do método de interface de origem do evento.

## <a name="remarks"></a>Comentários

O atributo **event_receiver** C++ especifica que a classe ou estrutura à qual ele é aplicado será um receptor de eventos, usando o modelo de evento Visual C++ Unified.

**event_receiver** é usado com o atributo [EVENT_SOURCE](event-source.md) e as palavras-chave [__hook](../../cpp/hook.md) e [__unhook](../../cpp/unhook.md) . Use `event_source` para criar origens de eventos. Use **`__hook`** nos métodos de um receptor de evento para associar os métodos do receptor de evento ("Hook") aos eventos de uma origem de evento. Use **`__unhook`** para dissocia-los.

*layout_dependent* é especificado somente para receptores de evento com ( `type` = **com**). O padrão para *layout_dependent* é **`false`** .

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|`coclass` Quando *layout_dependent*=**`true`**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[event_source](event-source.md)<br/>
[__event](../../cpp/event.md)<br/>
[__hook](../../cpp/hook.md)<br/>
[__unhook](../../cpp/unhook.md)<br/>
[Atributos de classe](class-attributes.md)
