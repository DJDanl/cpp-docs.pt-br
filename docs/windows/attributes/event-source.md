---
title: EVENT_SOURCE (C++ COM atributo)
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
ms.openlocfilehash: 81eba3c032a3556d1c69ad02652455ebc07ab6be
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62409623"
---
# <a name="eventsource"></a>origem do evento

Cria uma origem de evento.

## <a name="syntax"></a>Sintaxe

```cpp
[ event_source(type, optimize=[speed | size], decorate=[true | false]) ]
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
Uma enumeração de um dos seguintes valores:

- `native` para código C/C++ não gerenciado (padrão para classes não gerenciadas).

- `com` para o código de COM. Você deve usar `coclass` quando `type` = `com`. Esse valor requer que você inclua os arquivos de cabeçalho a seguir:

    ```cpp
    #define _ATL_ATTRIBUTES
    #include <atlbase.h>
    #include <atlcom.h>
    ```

*optimize*<br/>
Quando *tipo* é `native`, você pode especificar `optimize=size`, para indicar que há 4 bytes de armazenamento (mínimo) para todos os eventos em uma classe ou `optimize=speed` (o padrão) para indicar que há 4 * bytes (n º de eventos) de armazenamento.

*decorate*<br/>
Quando *tipo* é `native`, você pode especificar `decorate=false`, para indicar que o nome expandido no arquivo mesclado (. mrg) não deve incluir o nome da classe delimitadora. [/FX](../../build/reference/fx-merge-injected-code.md) permite gerar arquivos. mrg. `decorate=false`, que é o padrão, o que resulta em nomes de tipo totalmente qualificado no arquivo mesclado.

## <a name="remarks"></a>Comentários

O **event_source** C++ atributo especifica que a classe ou estrutura à qual ela é aplicada será uma origem do evento.

**EVENT_SOURCE** é usado em conjunto com o [event_receiver](event-receiver.md) atributo e o [Event](../../cpp/event.md) palavra-chave. Use `event_receiver` para criar receptores de evento. Use **Event** nos métodos dentro da fonte de evento para especificar esses métodos como eventos.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** quando `type`=`com`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[event_receiver](event-receiver.md)<br/>
[__event](../../cpp/event.md)<br/>
[__hook](../../cpp/hook.md)<br/>
[__unhook](../../cpp/unhook.md)<br/>
[Atributos de classe](class-attributes.md)