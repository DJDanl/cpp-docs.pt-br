---
title: EVENT_SOURCE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.event_source
dev_langs:
- C++
helpviewer_keywords:
- event handling, attributes
- event logs, event source
- event sources, creating
- event_source attribute
- event sources
- event handling, creating event source
ms.assetid: 0983e36a-6127-4fbb-8a22-8dfec6564c16
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d2dfcf61ced958519e7255bd241d3c0ea911824e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408915"
---
# <a name="eventsource"></a>origem do evento

Cria uma origem de evento.

## <a name="syntax"></a>Sintaxe

```cpp
[ event_source(
   type,
   optimize=[speed | size],
   decorate=[true | false]
) ]
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

*Decore*<br/>
Quando *tipo* é `native`, você pode especificar `decorate=false`, para indicar que o nome expandido no arquivo mesclado (. mrg) não deve incluir o nome da classe delimitadora. [/FX](../build/reference/fx-merge-injected-code.md) permite gerar arquivos. mrg. `decorate=false`, que é o padrão, o que resulta em nomes de tipo totalmente qualificado no arquivo mesclado.

## <a name="remarks"></a>Comentários

O **event_source** atributo C++ Especifica que a classe ou estrutura à qual ela é aplicada estejam uma origem do evento.

**EVENT_SOURCE** é usado em conjunto com o [event_receiver](../windows/event-receiver.md) atributo e o [Event](../cpp/event.md) palavra-chave. Use `event_receiver` para criar receptores de evento. Use **Event** nos métodos dentro da fonte de evento para especificar esses métodos como eventos.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass** quando `type`=`com`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](../windows/compiler-attributes.md)<br/>
[event_receiver](../windows/event-receiver.md)<br/>
[__event](../cpp/event.md)<br/>
[__hook](../cpp/hook.md)<br/>
[__unhook](../cpp/unhook.md)<br/>
[Atributos de classe](../windows/class-attributes.md)  