---
title: __event
ms.date: 11/04/2016
f1_keywords:
- __event_cpp
- __event
helpviewer_keywords:
- __event keyword [C++]
- events [C++], __event
ms.assetid: d3019b3e-722e-48df-8536-c05878461f9e
ms.openlocfilehash: d0d6d3570662cba36a606002263559246e22da57
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180050"
---
# <a name="__event"></a>__event

Declara um evento.

## <a name="syntax"></a>Sintaxe

```
__event method-declarator;
__event __interface interface-specifier;
__event member-declarator;
```

## <a name="remarks"></a>Comentários

A palavra-chave **__event** pode ser aplicada a uma declaração de método, uma declaração de interface ou uma declaração de membro de dados. No entanto, você não pode usar a palavra-chave **__event** para qualificar um membro de uma classe aninhada.

Dependendo se sua fonte de evento e receptor são C++ Nativo, COM ou gerenciados (.NET Framework), você pode usar as seguintes construções como eventos:

|C++ nativo|COM|Gerenciado (.NET Framework)|
|------------------|---------|--------------------------------|
|Método|—|method|
|—|interface|—|
|—|—|membro de dados|

Use [__hook](../cpp/hook.md) em um receptor de eventos para associar um método de manipulador a um método de evento. Observe que, depois de criar um evento com a palavra-chave **__event** , todos os manipuladores de eventos posteriormente conectados a esse evento serão chamados quando o evento for chamado.

Uma declaração de método de **__event** não pode ter uma definição; uma definição é gerada implicitamente, portanto, o método de evento pode ser chamado como se fosse um método comum.

> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.

## <a name="native-events"></a>Eventos nativos

Os eventos nativos são métodos. O tipo de retorno é normalmente HRESULT ou **void**, mas pode ser qualquer tipo integral, incluindo uma **Enumeração**. Quando um evento usa um tipo de retorno integral, uma condição de erro é definida quando um manipulador de eventos retorna um valor diferente de zero. Nesse caso, o evento sendo gerado chama os outros delegados.

```cpp
// Examples of native C++ events:
__event void OnDblClick();
__event HRESULT OnClick(int* b, char* s);
```

Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) para obter o código de exemplo.

## <a name="com-events"></a>Eventos COM

Os eventos COM são interfaces. Os parâmetros de um método em uma interface de origem de evento devem estar *em* parâmetros (mas isso não é rigorosamente imposto), pois um parâmetro *out* não é útil quando o multicast. Um aviso de nível 1 será emitido se você usar um parâmetro *out* .

O tipo de retorno é normalmente HRESULT ou **void**, mas pode ser qualquer tipo integral, incluindo **enum**. Quando um evento usa um tipo de retorno integral e um manipulador de eventos retorna uma condição de erro, nesse caso, o evento sendo gerado aborta as chamadas para outros delegados. Observe que o compilador marcará automaticamente uma interface de origem de evento como uma [origem](../windows/attributes/source-cpp.md) na IDL gerada.

A palavra-chave [__interface](../cpp/interface.md) sempre é necessária após **__event** para uma origem de evento com.

```cpp
// Example of a COM event:
__event __interface IEvent1;
```

Consulte [manipulação de eventos em com](../cpp/event-handling-in-com.md) para obter o código de exemplo.

## <a name="managed-events"></a>Eventos gerenciadas

Para obter informações sobre eventos de codificação na nova sintaxe, consulte [evento](../extensions/event-cpp-component-extensions.md).

Os eventos gerenciados são membros de dados ou métodos. Quando usado com um evento, o tipo de retorno de um delegado deve ser compatível com o [Common Language Specification](/dotnet/standard/language-independence-and-language-independent-components). O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado. Para obter mais informações sobre delegados, consulte [delegados e eventos](../dotnet/delegates-and-events.md). Se um evento gerenciado for um membro de dados, seu tipo deve ser um ponteiro para um delegado.

No .NET Framework, você pode tratar um membro de dados como um método (ou seja, o método `Invoke` do delegado correspondente). Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado. Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido. Por exemplo, você pode declarar um valor do evento como `OnClick` como um evento a seguir:

```cpp
// Examples of managed events:
__event ClickEventHandler* OnClick;  // data member as event
__event void OnClick(String* s);  // method as event
```

Ao declarar implicitamente um evento gerenciado, você pode especificamente adicionar e remover acessadores que serão chamados quando manipuladores de eventos forem adicionados ou removidos. Você também pode definir o método que chama (gera) o evento de fora da classe.

## <a name="example-native-events"></a>Exemplo: eventos nativos

```cpp
// EventHandling_Native_Event.cpp
// compile with: /c
[event_source(native)]
class CSource {
public:
   __event void MyEvent(int nValue);
};
```

## <a name="example-com-events"></a>Exemplo: eventos COM

```cpp
// EventHandling_COM_Event.cpp
// compile with: /c
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>

[ module(dll, name="EventSource", uuid="6E46B59E-89C3-4c15-A6D8-B8A1CEC98830") ];

[ dual, uuid("00000000-0000-0000-0000-000000000002") ]
__interface IEventSource {
   [id(1)] HRESULT MyEvent();
};
[ coclass, uuid("00000000-0000-0000-0000-000000000003"),  event_source(com) ]
class CSource : public IEventSource {
public:
   __event __interface IEventSource;
   HRESULT FireEvent() {
      __raise MyEvent();
      return S_OK;
   }
};
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Manipulação de eventos](../cpp/event-handling.md)<br/>
[event_source](../windows/attributes/event-source.md)<br/>
[event_receiver](../windows/attributes/event-receiver.md)<br/>
[__hook](../cpp/hook.md)<br/>
[__unhook](../cpp/unhook.md)<br/>
[__raise](../cpp/raise.md)
