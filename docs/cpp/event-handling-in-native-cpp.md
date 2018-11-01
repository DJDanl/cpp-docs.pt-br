---
title: Tratamento de eventos em C++ nativo
ms.date: 11/04/2016
helpviewer_keywords:
- event handling [C++], Visual C++
ms.assetid: e4b9219a-15d8-42fb-83c8-6d2e4e087c8d
ms.openlocfilehash: 210eea760e80814041b4e97f50c4164ef98d75e9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50457545"
---
# <a name="event-handling-in-native-c"></a>Tratamento de eventos em C++ nativo

Manipulação de eventos de C++ nativa, você configura um receptor de origem e o evento de eventos usando o [event_source](../windows/event-source.md) e [event_receiver](../windows/event-receiver.md) atributos, respectivamente, especificando `type` = `native`. Esses atributos as permitem que as classes às quais eles são aplicados disparem eventos e manipulem eventos em um contexto nativo, e não de COM.

## <a name="declaring-events"></a>Declarando eventos

Em uma classe de origem do evento, use o [Event](../cpp/event.md) palavra-chave em uma declaração de método para declarar o método como um evento. Certifique-se de declarar o método, mas não defina-o; fazer isso gerará um erro do compilador, pois o compilador define o método implicitamente quando ele é transformado em um evento. Os eventos nativos podem ser métodos com zero ou mais parâmetros. O tipo de retorno pode ser void ou qualquer tipo integral.

## <a name="defining-event-handlers"></a>Definindo manipuladores de eventos

Em uma classe de receptor de evento, você define manipuladores de eventos, que são métodos com assinaturas (tipos de retorno, convenções de chamada e argumentos) que correspondem ao evento que eles manipularão.

## <a name="hooking-event-handlers-to-events"></a>Vinculando manipuladores de eventos a eventos

Também em uma classe de receptor de evento, use a função intrínseca [hook](../cpp/hook.md) para associar eventos a manipuladores de eventos e [unhook](../cpp/unhook.md) para desassociar eventos de manipuladores de eventos. Você pode vincular diversos eventos a um manipulador ou vincular diversos manipuladores a um evento.

## <a name="firing-events"></a>Acionando eventos

Para disparar um evento, simplesmente chame o método declarado como um evento na classe da origem do evento. Se houver manipuladores vinculados ao evento, eles serão chamados.

### <a name="native-c-event-code"></a>Código nativo do evento C++

O exemplo de código a seguir mostra como disparar um evento no C++ nativo. Para compilar e executar o exemplo, consulte os comentários no código.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```cpp
// evh_native.cpp
#include <stdio.h>

[event_source(native)]
class CSource {
public:
   __event void MyEvent(int nValue);
};

[event_receiver(native)]
class CReceiver {
public:
   void MyHandler1(int nValue) {
      printf_s("MyHandler1 was called with value %d.\n", nValue);
   }

   void MyHandler2(int nValue) {
      printf_s("MyHandler2 was called with value %d.\n", nValue);
   }

   void hookEvent(CSource* pSource) {
      __hook(&CSource::MyEvent, pSource, &CReceiver::MyHandler1);
      __hook(&CSource::MyEvent, pSource, &CReceiver::MyHandler2);
   }

   void unhookEvent(CSource* pSource) {
      __unhook(&CSource::MyEvent, pSource, &CReceiver::MyHandler1);
      __unhook(&CSource::MyEvent, pSource, &CReceiver::MyHandler2);
   }
};

int main() {
   CSource source;
   CReceiver receiver;

   receiver.hookEvent(&source);
   __raise source.MyEvent(123);
   receiver.unhookEvent(&source);
}
```

### <a name="output"></a>Saída

```Output
MyHandler2 was called with value 123.
MyHandler1 was called with value 123.
```

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../cpp/event-handling.md)