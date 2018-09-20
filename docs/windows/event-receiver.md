---
title: event_receiver | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.event_receiver
dev_langs:
- C++
helpviewer_keywords:
- event_receiver attribute
- event receivers
- events [C++], event receivers (sinks)
- event handling [C++], attributes
- event handling [C++], creating receiver
- event sinks, creating
- event sinks
ms.assetid: bf8fe770-3ea2-4128-b46b-166222ee4097
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d30ac0d2e1d18b22c6130212503576f5fe343a8d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407525"
---
# <a name="eventreceiver"></a>event_receiver

Cria um receptor de eventos (coletor).

## <a name="syntax"></a>Sintaxe

```cpp
[ event_receiver(
   type
   [, layout_dependent=false]
) ]
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
Uma enumeração de um dos seguintes valores:

- `native` para código C/C++ não gerenciado (padrão para classes nativas).

- `com` para o código de COM. Esse valor requer que você inclua os arquivos de cabeçalho a seguir:

    ```cpp
    #define _ATL_ATTRIBUTES
    #include <atlbase.h>
    #include <atlcom.h>
    ```

*layout_dependent*<br/>
Especificar *layout_dependent* somente se `type` = **com**. *layout_dependent* é um valor booliano:

- **True** significa que a assinatura dos delegados no receptor deve corresponder exatamente a aqueles aos quais estão vinculados no evento origem de evento. Os nomes de manipulador de receptor de evento devem corresponder aos nomes especificados na interface de origem do evento relevante. Você deve usar `coclass` quando *layout_dependent* é **true**. É um pouco mais eficiente para especificar **verdadeira**.

- **False** (padrão) significa que a classe de armazenamento e a convenção de chamada (virtual, estático e outros) não têm que coincidir com o método de evento e os manipuladores; nem os nomes de manipulador precisa coincidir com os nomes de método de interface de origem do evento.

## <a name="remarks"></a>Comentários

O **event_receiver** atributo de C++ Especifica que a classe ou estrutura à qual ela é aplicada será um receptor de eventos, usando o modelo de evento unificado do Visual C++.

**event_receiver** é usado com o [event_source](../windows/event-source.md) atributo e o [hook](../cpp/hook.md) e [unhook](../cpp/unhook.md) palavras-chave. Use `event_source` para criar fontes de evento. Use **hook** dentro de métodos de um receptor evento para associar a métodos de receptor de eventos ("gancho") para os eventos de uma origem do evento. Use **unhook** para desassociá-los.

*layout_dependent* só é especificado para os receptores de evento (`type`=**com**). O padrão para *layout_dependent* é **falso**.

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|`coclass` Quando *layout_dependent*=**true**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](../windows/compiler-attributes.md)<br/>
[event_source](../windows/event-source.md)<br/>
[__event](../cpp/event.md)<br/>
[__hook](../cpp/hook.md)<br/>
[__unhook](../cpp/unhook.md)<br/>
[Atributos de classe](../windows/class-attributes.md)  