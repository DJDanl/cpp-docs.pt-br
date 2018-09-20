---
title: evento (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event
- event_cpp
dev_langs:
- C++
helpviewer_keywords:
- event keyword [C++]
ms.assetid: c4998e42-883c-4419-bbf4-36cdc979dd27
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f001f61a9425a064d3b899beb6cbb689471da5bf
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46442585"
---
# <a name="event--c-component-extensions"></a>evento (Extensões de Componentes C++)

O **evento** palavra-chave declara uma *evento*, que é uma notificação para os assinantes registrados (*manipuladores de eventos*) que algo interessante ocorreu.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

C + + c++ /CLI CX dá suporte à declaração uma *membro de evento* ou um *bloco evento*. Um membro de evento é uma abreviação para declarar um bloco de eventos. Por padrão, um membro de evento declara a `add()`, `remove()`, e `raise()` funções que são declaradas explicitamente em um bloco de eventos. Para personalizar as funções em um membro de evento, declare um bloco de eventos em vez disso e, em seguida, substituir as funções que você precisa.

### <a name="syntax"></a>Sintaxe

```cpp
// event data member
modifiereventdelegate^ event_name;

// event block
modifiereventdelegate^ event_name
{
   modifierreturn_valueadd(delegate^ name);
   modifier void remove(delegate^ name);
   modifier void raise(parameters);
}
```

### <a name="parameters"></a>Parâmetros

*Modificador*<br/>
Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são **estáticos** e **virtual**.

*delegate*<br/>
O [delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura de manipulador de eventos deve corresponder.

*event_name*<br/>
O nome do evento.

*RETURN_VALUE*<br/>
O valor retornado do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser **void**.

*Parâmetros*<br/>
(opcional) Parâmetros para o `raise` método, que correspondem à assinatura do *delegar* parâmetro.

### <a name="remarks"></a>Comentários

Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao disparo do evento e permite que os clientes de qualquer classe registre os métodos que estão em conformidade com a assinatura e tipo de retorno do delegado subjacente.

Há dois tipos de declaração de eventos:

*membro de dados de evento*<br/>
O compilador automaticamente cria o armazenamento para o evento na forma de um membro do tipo de delegado e cria interno `add()`, `remove()`, e `raise()` funções de membro. Um membro de dados de evento deve ser declarado dentro de uma classe. O tipo de retorno do tipo de retorno do delegado deve corresponder ao tipo de retorno do manipulador de eventos.

*bloco de eventos*<br/>
Um bloco de eventos permite que você declare explicitamente e personalizar o comportamento do `add()`, `remove()`, e `raise()` métodos.

Você pode usar **+ = de operadores** e **operador-=** para adicionar e remover um evento manipulador, ou ligue para o `add()` e `remove()` métodos explicitamente.

**evento** é uma palavra-chave contextual, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [eventos (C + + c++ /CX)](https://msdn.microsoft.com/library/windows/apps/hh755799.aspx).

Se você pretende adicionar e, em seguida, remover um manipulador de eventos, você deve salvar a estrutura de EventRegistrationToken que é retornada pela operação de adição. Em seguida, na operação de remoção, você deve usar a estrutura EventRegistrationToken salva para identificar o manipulador de eventos a ser removido.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O **evento** palavra-chave permite que você declarar um evento. Um evento é uma maneira para uma classe fornecer notificações quando algo interessante acontece.

### <a name="syntax"></a>Sintaxe

```cpp
// event data member
modifiereventdelegate^ event_name;

// event block
modifiereventdelegate^ event_name
{
   modifierreturn_valueadd(delegate^ name);
   modifier void remove(delegate^ name);
   modifier void raise(parameters);
}
```

### <a name="parameters"></a>Parâmetros

*Modificador*<br/>
Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são **estáticos** e **virtual**.

*delegate*<br/>
O [delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura de manipulador de eventos deve corresponder.

*event_name*<br/>
O nome do evento.

*RETURN_VALUE*<br/>
O valor retornado do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser **void**.

*Parâmetros*<br/>
(opcional) Parâmetros para o `raise` método, que correspondem à assinatura do *delegar* parâmetro.

### <a name="remarks"></a>Comentários

Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao disparo do evento e permite que os clientes de qualquer classe registre os métodos que estão em conformidade com a assinatura e tipo de retorno do delegado subjacente.

O delegado pode ter um ou mais métodos associados que serão chamados quando seu código indica que o evento ocorreu. Um evento em um programa pode ser disponibilizado para outros programas que direcionam o .NET Framework common language runtime.

Há dois tipos de declaração de eventos:

*membros de dados de evento*<br/>
Armazenamento para o evento, na forma de um membro do tipo de delegado é criado pelo compilador para eventos de membro de dados.  Um membro de dados de evento deve ser declarado dentro de uma classe. Isso também é conhecido como um evento trivial (consulte o exemplo de código abaixo.)

*blocos de evento*<br/>
Blocos de eventos permitem que você personalize o comportamento da adicionar, remover e métodos de aumento, com a implementação de add, remove e raise métodos. A assinatura do adicionar, remover e métodos de aumento deve corresponder à assinatura do delegado.  Eventos do bloco de eventos não são membros de dados e qualquer uso como um membro de dados irá gerar um erro do compilador.

O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado.

No .NET Framework, você pode tratar um membro de dados como um método (ou seja, o método `Invoke` do delegado correspondente). Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado. Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido.  Veja o exemplo de código no final deste tópico para obter um exemplo.

Ao declarar um evento gerenciado, você pode especificar adicionar e remover acessadores que serão chamados quando manipuladores de eventos são adicionados ou removidos usando os operadores = e -=. Os métodos add, remove e raise podem ser chamados explicitamente.

As etapas a seguir devem ser executadas para criar e usar eventos no Visual C++:

1. Crie ou identifique um delegado. Se você estiver definindo seus próprios eventos, você também deve garantir que haja um delegado a ser usado com o **evento** palavra-chave. Se o evento é predefinido, no .NET Framework, por exemplo, em seguida, os consumidores do evento só precisam saber o nome do delegado.

2. Crie uma classe que contém:

   - Um evento criado do delegado.

   - (Opcional) Um método que verifica se uma instância do delegado declarado com o **evento** palavra-chave existe. Caso contrário, essa lógica deve ser colocada no código que aciona o evento.

   - Métodos que chamam o evento. Esses métodos podem ser substituições de alguma funcionalidade de classe base.

   Essa classe define o evento.

3. Defina uma ou mais classes que se conectam a métodos para o evento. Cada uma dessas classes irá associar um ou mais métodos de evento na classe base.

4. Use o evento:

   - Crie um objeto da classe que contém a declaração de evento.

   - Crie um objeto da classe que contém a definição do evento.

Para obter mais informações sobre C + + / CLI eventos, consulte

- [Eventos em uma Interface](../dotnet/how-to-use-events-in-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra a declaração pares de delegados, eventos e manipuladores de eventos; assinar (Adicionar) os manipuladores de eventos; invocar os manipuladores de eventos; e, em seguida, cancelar a assinatura (remover) os manipuladores de eventos.

```cpp
// mcppv2_events.cpp
// compile with: /clr
using namespace System;

// declare delegates
delegate void ClickEventHandler(int, double);
delegate void DblClickEventHandler(String^);

// class that defines events
ref class EventSource {
public:
   event ClickEventHandler^ OnClick;   // declare the event OnClick
   event DblClickEventHandler^ OnDblClick;   // declare OnDblClick

   void FireEvents() {
      // raises events
      OnClick(7, 3.14159);
      OnDblClick("Hello");
   }
};

// class that defines methods that will called when event occurs
ref class EventReceiver {
public:
   void OnMyClick(int i, double d) {
      Console::WriteLine("OnClick: {0}, {1}", i, d);
   }

   void OnMyDblClick(String^ str) {
      Console::WriteLine("OnDblClick: {0}", str);
   }
};

int main() {
   EventSource ^ MyEventSource = gcnew EventSource();
   EventReceiver^ MyEventReceiver = gcnew EventReceiver();

   // hook handler to event
   MyEventSource->OnClick += gcnew ClickEventHandler(MyEventReceiver, &EventReceiver::OnMyClick);
   MyEventSource->OnDblClick += gcnew DblClickEventHandler(MyEventReceiver, &EventReceiver::OnMyDblClick);

   // invoke events
   MyEventSource->FireEvents();

   // unhook handler to event
   MyEventSource->OnClick -= gcnew ClickEventHandler(MyEventReceiver, &EventReceiver::OnMyClick);
   MyEventSource->OnDblClick -= gcnew DblClickEventHandler(MyEventReceiver, &EventReceiver::OnMyDblClick);
}
```

```Output
OnClick: 7, 3.14159

OnDblClick: Hello
```

O exemplo de código a seguir demonstra a lógica usada para gerar o `raise` método de um evento trivial: se o evento tem um ou mais assinantes, chamando o `raise` método implicitamente ou explicitamente chama o delegado. Se o delegado de retorno do tipo não for **void** e se há zero assinantes do evento, o `raise` método retorna o valor padrão para o tipo de delegado. Se não houver nenhum assinante de evento, chamando o `raise` método simplesmente retorna e nenhuma exceção for gerada. Se o delegado de tipo de retorno **void**, o tipo de delegado é retornado.

```cpp
// trivial_events.cpp
// compile with: /clr /c
using namespace System;
public delegate int Del();
public ref struct C {
   int i;
   event Del^ MyEvent;

   void FireEvent() {
      i = MyEvent();
   }
};

ref struct EventReceiver {
   int OnMyClick() { return 0; }
};

int main() {
   C c;
   c.i = 687;

   c.FireEvent();
   Console::WriteLine(c.i);
   c.i = 688;

   EventReceiver^ MyEventReceiver = gcnew EventReceiver();
   c.MyEvent += gcnew Del(MyEventReceiver, &EventReceiver::OnMyClick);
   Console::WriteLine(c.i);
}
```

```Output
0

688
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)