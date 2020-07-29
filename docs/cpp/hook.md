---
title: __hook
ms.date: 11/04/2016
f1_keywords:
- __hook_cpp
helpviewer_keywords:
- __hook keyword [C++]
- event handlers [C++], connecting events to
ms.assetid: f4cabb10-d293-4c0e-a1d2-4745ef9cc22c
ms.openlocfilehash: 5a0eaf0a3bc0617dbcd1f43805af8a95291e7e47
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87188161"
---
# <a name="__hook"></a>__hook

Associa um método de manipulador a um evento.

## <a name="syntax"></a>Sintaxe

```
long __hook(
    &SourceClass::EventMethod,
    source,
    &ReceiverClass::HandlerMethod
    [, receiver = this]
);
long __hook(
    interface,
    source
);
```

### <a name="parameters"></a>parâmetros

*&SourceClass:: EventMethod*<br/>
Um ponteiro para o método de evento ao qual você engancha o método do manipulador de eventos:

- Eventos C++ nativos: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

- Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um dos seus métodos.

- Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

*interface*<br/>
O nome da interface que está sendo conectada ao *receptor*, somente para receptores de eventos com nos quais o parâmetro *layout_dependent* do atributo [event_receiver](../windows/attributes/event-receiver.md) é **`true`** .

*source*<br/>
Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado em `event_receiver` , a *origem* pode ser uma das seguintes:

- Um ponteiro nativo do objeto de origem do evento.

- Um `IUnknown` ponteiro baseado em (fonte com).

- Um ponteiro gerenciado do objeto (para eventos gerenciados).

*&ReceiverClass:: HandlerMethod*<br/>
Um ponteiro para o método do manipulador de eventos a ser enganchado a um evento. O manipulador é especificado como um método de uma classe ou uma referência para o mesmo; Se você não especificar o nome da classe, **`__hook`** o assumirá que a classe é a qual ela será chamada.

- Eventos C++ nativos: *ReceiverClass* é a classe receptora de evento e `HandlerMethod` é o manipulador.

- Eventos COM: *ReceiverClass* é a interface do receptor de eventos e `HandlerMethod` é um de seus manipuladores.

- Eventos gerenciados: *ReceiverClass* é a classe receptora de evento e `HandlerMethod` é o manipulador.

*distância*<br/>
Adicional Um ponteiro para uma instância da classe receptor do evento. Se você não especificar um destinatário, o padrão será a classe ou a estrutura do receptor em que **`__hook`** é chamada.

## <a name="usage"></a>Uso

Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.

## <a name="remarks"></a>Comentários

Use a função intrínseca **`__hook`** em um receptor de eventos para associar ou vincular um método de manipulador a um método de evento. O manipulador especificado é chamado quando a origem gera o evento especificado. Você pode enganchar vários manipuladores a um único evento, ou enganchar vários eventos a um único manipulador.

Há duas formas de **`__hook`** . Você pode usar o primeiro formulário (quatro argumentos) na maioria dos casos, especificamente, para receptores de eventos COM, nos quais o parâmetro *layout_dependent* do atributo [event_receiver](../windows/attributes/event-receiver.md) é **`false`** .

Nesses casos você não precisa enganchar todos os métodos em uma interface antes de acionar um evento em um dos métodos; somente a manipulação de método do evento precisa ser enganchado. Você pode usar a segunda forma (de dois argumentos) **`__hook`** somente para um receptor de evento com no qual *layout_dependent* **= true**.

**`__hook`** Retorna um valor longo. Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançam uma exceção).

O compilador verifica a existência de um evento e se a assinatura do evento concorda com a assinatura de delegação.

Com exceção de eventos COM, **`__hook`** e **`__unhook`** pode ser chamado fora do receptor de eventos.

Uma alternativa ao uso **`__hook`** do é usar o operador + =.

Para obter informações sobre como codificar eventos gerenciados na nova sintaxe, consulte [evento](../extensions/event-cpp-component-extensions.md).

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="example"></a>Exemplo

Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos em com](../cpp/event-handling-in-com.md) para obter exemplos.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Manipulação de eventos](../cpp/event-handling.md)<br/>
[event_source](../windows/attributes/event-source.md)<br/>
[event_receiver](../windows/attributes/event-receiver.md)<br/>
[__unhook](../cpp/unhook.md)<br/>
[__raise](../cpp/raise.md)<br/>
