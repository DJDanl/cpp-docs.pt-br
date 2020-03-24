---
title: Tratamento de eventos em C++ nativo
ms.date: 05/07/2019
helpviewer_keywords:
- event handling [C++]
ms.assetid: e4b9219a-15d8-42fb-83c8-6d2e4e087c8d
ms.openlocfilehash: cc9265cd3f9f400e2880405019e4d2c9a934f10a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180076"
---
# <a name="event-handling-in-native-c"></a>Tratamento de eventos em C++ nativo

Na manipulação C++ de eventos nativos, você configura uma origem de evento e um receptor de evento usando os atributos [EVENT_SOURCE](../windows/attributes/event-source.md) e [event_receiver](../windows/attributes/event-receiver.md) , respectivamente, especificando `type`=`native`. Esses atributos as permitem que as classes às quais eles são aplicados disparem eventos e manipulem eventos em um contexto nativo, e não de COM.

## <a name="declaring-events"></a>Declarando eventos

Em uma classe de origem de evento, use a palavra-chave [__event](../cpp/event.md) em uma declaração de método para declarar o método como um evento. Certifique-se de declarar o método, mas não defina-o; fazer isso gerará um erro do compilador, pois o compilador define o método implicitamente quando ele é transformado em um evento. Os eventos nativos podem ser métodos com zero ou mais parâmetros. O tipo de retorno pode ser void ou qualquer tipo integral.

## <a name="defining-event-handlers"></a>Definindo manipuladores de eventos

Em uma classe de receptor de evento, você define manipuladores de eventos, que são métodos com assinaturas (tipos de retorno, convenções de chamada e argumentos) que correspondem ao evento que eles manipularão.

## <a name="hooking-event-handlers-to-events"></a>Vinculando manipuladores de eventos a eventos

Também em uma classe receptora de eventos, você usa a função intrínseca [__hook](../cpp/hook.md) para associar eventos a manipuladores de eventos e [__unhook](../cpp/unhook.md) para dissociar eventos de manipuladores de eventos. Você pode vincular diversos eventos a um manipulador ou vincular diversos manipuladores a um evento.

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

## <a name="see-also"></a>Confira também

[Manipulação de eventos](../cpp/event-handling.md)
