---
title: Tratamento de eventos em COM
ms.date: 11/04/2016
helpviewer_keywords:
- event handling [C++], COM
- event handling [C++], about event handling
- declaring events
- event handlers [C++], COM
- event handlers
- COM, events
- event receivers, in event handling
- event handling [C++]
- hooking events
- event receivers, name and signature matching
- event sources, in event handling
- declaring events, in COM
- declaring events, event handling in COM
ms.assetid: 6b4617d4-a58e-440c-a8a6-1ad1c715b2bb
ms.openlocfilehash: be71bd9eac44c51a2e6a7cdeb925a1ca0b8b5dfb
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231202"
---
# <a name="event-handling-in-com"></a>Tratamento de eventos em COM

Na manipulação de eventos COM, você configura uma origem de evento e um receptor de evento usando os atributos [EVENT_SOURCE](../windows/attributes/event-source.md) e [event_receiver](../windows/attributes/event-receiver.md) , respectivamente, especificando `type` = `com` . Esses atributos injetam o código apropriado para interfaces personalizadas, duais e de expedição a fim de permitir que as classes às quais são aplicados acionem eventos e manipulem eventos por meio de pontos de conexão COM.

## <a name="declaring-events"></a>Declarando eventos

Em uma classe de origem de evento, use a palavra-chave [__event](../cpp/event.md) em uma declaração de interface para declarar os métodos da interface como eventos. Os eventos dessa interface são acionados quando você os chama como métodos da interface. Métodos em interfaces de evento podem ter zero ou mais parâmetros (que devem estar todos *em* parâmetros). O tipo de retorno pode ser void ou qualquer tipo integral.

## <a name="defining-event-handlers"></a>Definindo manipuladores de eventos

Em uma classe de receptor de evento, você define manipuladores de eventos, que são métodos com assinaturas (tipos de retorno, convenções de chamada e argumentos) que correspondem ao evento que eles manipularão. Para eventos COM, as convenções de chamada não precisam corresponder; consulte [eventos com dependentes de layout](#vcconeventhandlingincomanchorlayoutdependentcomevents) abaixo para obter detalhes.

## <a name="hooking-event-handlers-to-events"></a>Vinculando manipuladores de eventos a eventos

Também em uma classe receptora de eventos, você usa a função intrínseca [__hook](../cpp/hook.md) para associar eventos a manipuladores de eventos e [__unhook](../cpp/unhook.md) para dissociar eventos de manipuladores de eventos. Você pode vincular diversos eventos a um manipulador ou vincular diversos manipuladores a um evento.

> [!NOTE]
> Normalmente, há duas técnicas para permitir que um receptor de evento COM acesse definições de interface de origem de evento. O primeiro, conforme mostrado abaixo, é compartilhar um arquivo de cabeçalho comum. A segunda é usar [#import](../preprocessor/hash-import-directive-cpp.md) com o `embedded_idl` qualificador de importação, para que a biblioteca do tipo de origem do evento seja gravada no arquivo. tlh com o código gerado pelo atributo preservado.

## <a name="firing-events"></a>Acionando eventos

Para acionar um evento, basta chamar um método na interface declarada com a **`__event`** palavra-chave na classe de origem do evento. Se houver manipuladores vinculados ao evento, eles serão chamados.

### <a name="com-event-code"></a>Código de evento COM

O exemplo a seguir mostra como acionar um evento em uma classe COM. Para compilar e executar o exemplo, consulte os comentários no código.

```cpp
// evh_server.h
#pragma once

[ dual, uuid("00000000-0000-0000-0000-000000000001") ]
__interface IEvents {
   [id(1)] HRESULT MyEvent([in] int value);
};

[ dual, uuid("00000000-0000-0000-0000-000000000002") ]
__interface IEventSource {
   [id(1)] HRESULT FireEvent();
};

class DECLSPEC_UUID("530DF3AD-6936-3214-A83B-27B63C7997C4") CSource;
```

Então o servidor:

```cpp
// evh_server.cpp
// compile with: /LD
// post-build command: Regsvr32.exe /s evh_server.dll
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
#include "evh_server.h"

[ module(dll, name="EventSource", uuid="6E46B59E-89C3-4c15-A6D8-B8A1CEC98830") ];

[coclass, event_source(com), uuid("530DF3AD-6936-3214-A83B-27B63C7997C4")]
class CSource : public IEventSource {
public:
   __event __interface IEvents;

   HRESULT FireEvent() {
      __raise MyEvent(123);
      return S_OK;
   }
};
```

Então o cliente:

```cpp
// evh_client.cpp
// compile with: /link /OPT:NOREF
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
#include <stdio.h>
#include "evh_server.h"

[ module(name="EventReceiver") ];

[ event_receiver(com) ]
class CReceiver {
public:
   HRESULT MyHandler1(int nValue) {
      printf_s("MyHandler1 was called with value %d.\n", nValue);
      return S_OK;
   }

   HRESULT MyHandler2(int nValue) {
      printf_s("MyHandler2 was called with value %d.\n", nValue);
      return S_OK;
   }

   void HookEvent(IEventSource* pSource) {
      __hook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler1);
      __hook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler2);
   }

   void UnhookEvent(IEventSource* pSource) {
      __unhook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler1);
      __unhook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler2);
   }
};

int main() {
   // Create COM object
   CoInitialize(NULL);
   {
      IEventSource* pSource = 0;
      HRESULT hr = CoCreateInstance(__uuidof(CSource), NULL,         CLSCTX_ALL, __uuidof(IEventSource), (void **) &pSource);
      if (FAILED(hr)) {
         return -1;
      }

      // Create receiver and fire event
      CReceiver receiver;
      receiver.HookEvent(pSource);
      pSource->FireEvent();
      receiver.UnhookEvent(pSource);
   }
   CoUninitialize();
   return 0;
}
```

### <a name="output"></a>Saída

```Output
MyHandler1 was called with value 123.
MyHandler2 was called with value 123.
```

## <a name="layout-dependent-com-events"></a><a name="vcconeventhandlingincomanchorlayoutdependentcomevents"></a>Eventos COM dependentes de layout

A dependência do layout só é um problema para a programação COM. Na manipulação de eventos nativos e gerenciados, as assinaturas (tipo de retorno, convenção de chamada e argumentos) dos manipuladores devem corresponder aos respectivos eventos, mas os nomes dos manipuladores não precisam corresponder aos respectivos eventos.

No entanto, na manipulação de eventos COM, quando você define o parâmetro *layout_dependent* de `event_receiver` como **`true`** , a correspondência de nome e assinatura é imposta. Isso significa que os nomes e as assinaturas dos manipuladores no receptor de evento devem corresponder exatamente aos nomes e às assinaturas dos eventos aos quais estão vinculados.

Quando *layout_dependent* é definido como **`false`** , a Convenção de chamada e a classe de armazenamento (virtual, estática e assim por diante) podem ser misturadas e correspondidas entre o método de acionamento de evento e os métodos de conexão (seus delegados). É um pouco mais eficiente ter *layout_dependent* = **`true`** .

Por exemplo, suponha que `IEventSource` esteja definido para ter os seguintes métodos:

```cpp
[id(1)] HRESULT MyEvent1([in] int value);
[id(2)] HRESULT MyEvent2([in] int value);
```

Pressuponha que a origem do evento tenha o seguinte formato:

```cpp
[coclass, event_source(com)]
class CSource : public IEventSource {
public:
   __event __interface IEvents;

   HRESULT FireEvent() {
      MyEvent1(123);
      MyEvent2(123);
      return S_OK;
   }
};
```

Em seguida, no receptor do evento, qualquer manipulador vinculado a um método em `IEventSource` deve corresponder ao nome e à assinatura, como se segue:

```cpp
[coclass, event_receiver(com, true)]
class CReceiver {
public:
   HRESULT MyEvent1(int nValue) {  // name and signature matches MyEvent1
      ...
   }
   HRESULT MyEvent2(E c, char* pc) {  // signature doesn't match MyEvent2
      ...
   }
   HRESULT MyHandler1(int nValue) {  // name doesn't match MyEvent1 (or 2)
      ...
   }
   void HookEvent(IEventSource* pSource) {
      __hook(IFace, pSource);  // Hooks up all name-matched events
                               // under layout_dependent = true
      __hook(&IFace::MyEvent1, pSource, &CReceive::MyEvent1);   // valid
      __hook(&IFace::MyEvent2, pSource, &CSink::MyEvent2);   // not valid
      __hook(&IFace::MyEvent1, pSource, &CSink:: MyHandler1); // not valid
   }
};
```

## <a name="see-also"></a>Confira também

[Manipulação de eventos](../cpp/event-handling.md)
