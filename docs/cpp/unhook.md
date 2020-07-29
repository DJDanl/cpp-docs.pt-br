---
title: __unhook
ms.date: 11/04/2016
f1_keywords:
- __unhook
- __unhook_cpp
helpviewer_keywords:
- event handlers [C++], dissociating events
- __unhook keyword [C++]
ms.assetid: 953a14f3-5199-459d-81e5-fcf015a19878
ms.openlocfilehash: 84df5ad0ff27e6b09134b0f92f14f8e9b6fdc817
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233568"
---
# <a name="__unhook"></a>__unhook

Dissocia um método de manipulador de um evento.

## <a name="syntax"></a>Sintaxe

```cpp
long  __unhook(
   &SourceClass::EventMethod,
   source,
   &ReceiverClass::HandlerMethod
   [, receiver = this]
);
long  __unhook(
   interface,
   source
);
long  __unhook(
   source
);
```

#### <a name="parameters"></a>parâmetros

**&***SourceClass* `::` *EventMethod* Um ponteiro para o método de evento do qual você desengancha o método do manipulador de eventos:

- Eventos C++ nativos: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

- Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um dos seus métodos.

- Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

*interface*<br/>
O nome da interface que está sendo desconectado do *receptor*, somente para receptores de eventos com nos quais o parâmetro *layout_dependent* do atributo [event_receiver](../windows/attributes/event-receiver.md) é **`true`** .

*source*<br/>
Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado em `event_receiver` , a *origem* pode ser uma das seguintes:

- Um ponteiro nativo do objeto de origem do evento.

- Um `IUnknown` ponteiro baseado em (fonte com).

- Um ponteiro gerenciado do objeto (para eventos gerenciados).

**&***ReceiverClass* `::` `HandlerMethod`Um ponteiro para o método manipulador de eventos a ser desvinculado de um evento. O manipulador é especificado como um método de uma classe ou uma referência para o mesmo; Se você não especificar o nome da classe, **`__unhook`** o assumirá que a classe é a qual ela será chamada.

- Eventos C++ nativos: *ReceiverClass* é a classe receptora de evento e `HandlerMethod` é o manipulador.

- Eventos COM: *ReceiverClass* é a interface do receptor de eventos e `HandlerMethod` é um de seus manipuladores.

- Eventos gerenciados: *ReceiverClass* é a classe receptora de evento e `HandlerMethod` é o manipulador.

*Receiver*(opcional) um ponteiro para uma instância da classe receptor do evento. Se você não especificar um destinatário, o padrão será a classe ou a estrutura do receptor em que **`__unhook`** é chamada.

## <a name="usage"></a>Uso

Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.

## <a name="remarks"></a>Comentários

Use a função intrínseca **`__unhook`** em um receptor de eventos para dissociar ou "desvincular" um método de manipulador de um método de evento.

Há três formas de **`__unhook`** . Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos. Você pode usar a segunda forma (de dois argumentos) **`__unhook`** apenas para um receptor de evento com; isso desvincula toda a interface de evento. Você pode usar o terceiro formato (um argumento) para desenganchar todos os representantes da origem especificada.

Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançarão uma exceção).

Se você chamar **`__unhook`** em um evento e manipulador de eventos que ainda não foram conectados, ele não terá nenhum efeito.

Em tempo de compilação, o compilador verifica se o evento existe e faz a verificação do tipo de parâmetro com o manipulador especificado.

Com exceção de eventos COM, **`__hook`** e **`__unhook`** pode ser chamado fora do receptor de eventos.

Uma alternativa ao uso **`__unhook`** do é usar o operador-=.

Para obter informações sobre como codificar eventos gerenciados na nova sintaxe, consulte [evento](../extensions/event-cpp-component-extensions.md).

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="example"></a>Exemplo

Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos em com](../cpp/event-handling-in-com.md) para obter exemplos.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[event_source](../windows/attributes/event-source.md)<br/>
[event_receiver](../windows/attributes/event-receiver.md)<br/>
[__event](../cpp/event.md)<br/>
[__hook](../cpp/hook.md)<br/>
[__raise](../cpp/raise.md)
