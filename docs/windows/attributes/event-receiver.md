---
title: event_receiver (C++ atributo com)
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
ms.openlocfilehash: 9653a0b5c756857d92914496b9c5c6f8aee56ebb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167076"
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

- `native` para C/C++ Code não gerenciado (padrão para classes nativas).

- `com` para o código COM. Esse valor requer que você inclua os seguintes arquivos de cabeçalho:

    ```cpp
    #define _ATL_ATTRIBUTES
    #include <atlbase.h>
    #include <atlcom.h>
    ```

*layout_dependent*<br/>
Especifique *layout_dependent* somente se `type`=**com**. *layout_dependent* é um booliano:

- **verdadeiro** significa que a assinatura dos delegados no receptor de eventos deve corresponder exatamente àqueles aos quais eles são conectados na origem do evento. Os nomes do manipulador do receptor de eventos devem corresponder aos nomes especificados na interface de origem do evento relevante. Você deve usar `coclass` quando *layout_dependent* for **true**. É um pouco mais eficiente especificar **true**.

- **false** (padrão) significa que a Convenção de chamada e a classe de armazenamento (virtual, estática e outras) não precisam corresponder ao método de evento e aos manipuladores; Nem os nomes dos manipuladores precisam corresponder aos nomes do método de interface de origem do evento.

## <a name="remarks"></a>Comentários

O atributo **event_receiver** C++ especifica que a classe ou estrutura à qual ele é aplicado será um receptor de eventos, usando o modelo C++ de evento unificado Visual.

**event_receiver** é usado com o atributo [EVENT_SOURCE](event-source.md) e as palavras-chave [__hook](../../cpp/hook.md) e [__unhook](../../cpp/unhook.md) . Use `event_source` para criar fontes de evento. Use **__hook** nos métodos de um receptor de evento para associar os métodos do receptor de evento ("Hook") aos eventos de uma origem de evento. Use **__unhook** para dissocia-los.

*layout_dependent* só é especificado para receptores de evento COM (`type`=**com**). O padrão para *layout_dependent* é **false**.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|`coclass` quando *layout_dependent*=**true**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de compilador](compiler-attributes.md)<br/>
[event_source](event-source.md)<br/>
[__event](../../cpp/event.md)<br/>
[__hook](../../cpp/hook.md)<br/>
[__unhook](../../cpp/unhook.md)<br/>
[Atributos de classe](class-attributes.md)
