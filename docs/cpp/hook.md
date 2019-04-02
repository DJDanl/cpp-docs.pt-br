---
title: __hook
ms.date: 11/04/2016
f1_keywords:
- __hook_cpp
helpviewer_keywords:
- __hook keyword [C++]
- event handlers [C++], connecting events to
ms.assetid: f4cabb10-d293-4c0e-a1d2-4745ef9cc22c
ms.openlocfilehash: c4887d85e01344c171fb0fdfe957f2d8a669ff6a
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58771663"
---
# <a name="hook"></a>__hook

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

### <a name="parameters"></a>Parâmetros

*& SourceClass::EventMethod*<br/>
Um ponteiro para o método de evento ao qual você engancha o método do manipulador de eventos:

- Eventos nativos do C++: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

- Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um dos seus métodos.

- Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

*interface*<br/>
O nome da interface sendo enganchado a *receptor*, apenas para os receptores de evento no qual o *layout_dependent* parâmetro do [event_receiver](../windows/attributes/event-receiver.md) atributo é **verdadeiro**.

*source*<br/>
Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado no `event_receiver`, *origem* pode ser uma das seguintes opções:

- Um ponteiro nativo do objeto de origem do evento.

- Um `IUnknown`-com base em ponteiro (origem COM).

- Um ponteiro gerenciado do objeto (para eventos gerenciados).

*&ReceiverClass::HandlerMethod*<br/>
Um ponteiro para o método do manipulador de eventos a ser enganchado a um evento. O manipulador é especificado como um método de uma classe ou uma referência a ela. Se você não especificar o nome de classe **hook** pressupõe que a classe seja que, no qual ele é chamado.

- Eventos nativos do C++: *ReceiverClass* é a classe de receptor de evento e `HandlerMethod` é o manipulador.

- Eventos COM: *ReceiverClass* é a interface do receptor de evento e `HandlerMethod` é um dos manipuladores.

- Eventos gerenciados: *ReceiverClass* é a classe de receptor de evento e `HandlerMethod` é o manipulador.

*receiver*<br/>
(Opcional) Um ponteiro para uma instância da classe do receptor de evento. Se você não especificar um receptor, o padrão é a classe do receptor ou estrutura na qual **hook** é chamado.

## <a name="usage"></a>Uso

Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.

## <a name="remarks"></a>Comentários

Use a função intrínseca **hook** em um receptor de eventos para associar ou enganchar um método de manipulador com um método de evento. O manipulador especificado é chamado quando a origem gera o evento especificado. Você pode enganchar vários manipuladores a um único evento, ou enganchar vários eventos a um único manipulador.

Há duas formas de **hook**. Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos, especificamente, para os receptores de evento no qual o *layout_dependent* parâmetro do [event_receiver](../windows/attributes/event-receiver.md) atributo é **false** .

Nesses casos você não precisa enganchar todos os métodos em uma interface antes de acionar um evento em um dos métodos; somente a manipulação de método do evento precisa ser enganchado. Você pode usar o segundo formulário (dois argumentos) de **hook** apenas para um receptor de eventos COM no qual *layout_dependent* **= true**.

**hook** retorna um valor longo. Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançam uma exceção).

O compilador verifica a existência de um evento e se a assinatura do evento concorda com a assinatura de delegação.

Com exceção dos eventos COM, **hook** e **unhook** pode ser chamado fora do receptor do evento.

Uma alternativa ao uso **hook** é usar o operador + =.

Para obter informações sobre a codificação gerenciada de eventos na nova sintaxe, consulte [evento](../extensions/event-cpp-component-extensions.md).

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="example"></a>Exemplo

Ver [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos em COM](../cpp/event-handling-in-com.md) para obter exemplos.

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Manipulação de eventos](../cpp/event-handling.md)<br/>
[event_source](../windows/attributes/event-source.md)<br/>
[event_receiver](../windows/attributes/event-receiver.md)<br/>
[__unhook](../cpp/unhook.md)<br/>
[__raise](../cpp/raise.md)<br/>
