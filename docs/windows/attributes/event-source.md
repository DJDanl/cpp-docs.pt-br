---
title: event_source (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.event_source
helpviewer_keywords:
- event handling, attributes
- event logs, event source
- event sources, creating
- event_source attribute
- event sources
- event handling, creating event source
ms.assetid: 0983e36a-6127-4fbb-8a22-8dfec6564c16
ms.openlocfilehash: bea90020c3ec570149e11db95ff6d6f8fd0a5507
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845296"
---
# <a name="event_source"></a>origem do evento

Cria uma origem de evento.

## <a name="syntax"></a>Sintaxe

```cpp
[ event_source(type, optimize=[speed | size], decorate=[true | false]) ]
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
Uma enumeração de um dos seguintes valores:

- `native` para código C/C++ não gerenciado (padrão para classes não gerenciadas).

- `com` para o código COM. Você deve usar `coclass` quando `type` = `com` . Esse valor requer que você inclua os seguintes arquivos de cabeçalho:

    ```cpp
    #define _ATL_ATTRIBUTES
    #include <atlbase.h>
    #include <atlcom.h>
    ```

*formato*<br/>
Quando *Type* é `native` , você pode especificar `optimize=size` , para indicar que há 4 bytes de armazenamento (mínimo) para todos os eventos em uma classe ou `optimize=speed` (o padrão) para indicar que há 4 * (n º de eventos) bytes de armazenamento.

*festa*<br/>
Quando *Type* é `native` , você pode especificar `decorate=false` , para indicar que o nome expandido no arquivo mesclado (. mrg) não deve incluir o nome da classe de circunscrição. O [/FX](../../build/reference/fx-merge-injected-code.md) permite gerar arquivos. mrg. `decorate=false`, que é o padrão, resulta em nomes de tipo totalmente qualificados no arquivo mesclado.

## <a name="remarks"></a>Comentários

O atributo **EVENT_SOURCE** C++ especifica que a classe ou estrutura à qual ele é aplicado será uma origem de evento.

**EVENT_SOURCE** é usado em conjunto com o atributo [event_receiver](event-receiver.md) e a palavra-chave [__event](../../cpp/event.md) . Use `event_receiver` para criar receptores de eventos. Use **`__event`** métodos on na origem do evento para especificar esses métodos como eventos.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** quando `type`=`com`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[event_receiver](event-receiver.md)<br/>
[__event](../../cpp/event.md)<br/>
[__hook](../../cpp/hook.md)<br/>
[__unhook](../../cpp/unhook.md)<br/>
[Atributos de classe](class-attributes.md)
