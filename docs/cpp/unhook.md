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
ms.openlocfilehash: 221ffc30a9b8a40c44f8009dfa511b72aa160e01
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337557"
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

#### <a name="parameters"></a>Parâmetros

**&***SourceClass* `::` *EventMethod* Um ponteiro para o método de evento a partir do qual você desengaque o método manipulador de eventos:

- Eventos Nativos C++: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

- Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um de seus métodos.

- Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.

*interface*<br/>
O nome da interface sendo desconectado do *receptor,* apenas para receptores de evento COM nos quais o parâmetro *layout_dependent* do atributo [event_receiver](../windows/attributes/event-receiver.md) é **verdadeiro**.

*Fonte*<br/>
Um ponteiro para uma instância da origem do evento. Dependendo do `type` código especificado em `event_receiver`, a *fonte* pode ser uma das seguintes:

- Um ponteiro nativo do objeto de origem do evento.

- Um `IUnknown`ponteiro baseado em (fonte COM).

- Um ponteiro gerenciado do objeto (para eventos gerenciados).

**&***ReceptorClasse* `::` `HandlerMethod` Classe A ponteiro para o método manipulador de eventos a ser desenganado de um evento. O manipulador é especificado como um método de uma classe ou uma referência à mesma; se você não especificar o nome da classe, **__unhook** assume que a classe seja aquela em que ela é chamada.

- Eventos C++ nativos: *ReceiverClass* é `HandlerMethod` a classe receptora de eventos e é o manipulador.

- Eventos COM: *ReceiverClass* é a `HandlerMethod` interface do receptor de eventos e é um de seus manipuladores.

- Eventos gerenciados: *ReceiverClass* é a `HandlerMethod` classe receptora de eventos e é o manipulador.

*receptor*(opcional) Um ponteiro para uma instância da classe receptora de evento. Se você não especificar um receptor, o padrão é a classe ou estrutura do receptor em que **__unhook** é chamado.

## <a name="usage"></a>Uso

Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.

## <a name="remarks"></a>Comentários

Use a função intrínseca **__unhook** em um receptor de eventos para dissociar ou "desengaquear" um método de manipulador de um método de evento.

Há três formas de **__unhook.** Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos. Você pode usar a forma de segunda (dois argumentos) de **__unhook** apenas para um receptor de evento COM; isso desprende toda a interface de evento. Você pode usar o terceiro formato (um argumento) para desenganchar todos os representantes da origem especificada.

Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançarão uma exceção).

Se você chamar **__unhook** em um manipulador de eventos e eventos que ainda não estão viciados, não terá efeito.

Em tempo de compilação, o compilador verifica se o evento existe e faz a verificação do tipo de parâmetro com o manipulador especificado.

Com exceção dos eventos COM, **__hook** e **__unhook** podem ser chamados fora do receptor do evento.

Uma alternativa para usar **__unhook** é usar o operador -=

Para obter informações sobre codificação de eventos gerenciados na nova sintaxe, consulte [o evento](../extensions/event-cpp-component-extensions.md).

> [!NOTE]
> Uma classe ou um struct modelo não podem conter eventos.

## <a name="example"></a>Exemplo

Consulte [O Manuseio de Eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e o manuseio de eventos em [COM](../cpp/event-handling-in-com.md) para obter amostras.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Event_source](../windows/attributes/event-source.md)<br/>
[event_receiver](../windows/attributes/event-receiver.md)<br/>
[__event](../cpp/event.md)<br/>
[__hook](../cpp/hook.md)<br/>
[__raise](../cpp/raise.md)
