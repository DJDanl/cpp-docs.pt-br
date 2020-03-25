---
title: event (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- event
- event_cpp
helpviewer_keywords:
- event keyword [C++]
ms.assetid: c4998e42-883c-4419-bbf4-36cdc979dd27
ms.openlocfilehash: 90682ba699f6316cb6b38a3b78c44e853cd5473f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172380"
---
# <a name="event--ccli-and-ccx"></a>event (C++/CLI e C++/CX)

A palavra-chave **event** declara um *evento*, que é uma notificação a assinantes registrados (*manipuladores de eventos*) de que ocorreu algo de interesse.

## <a name="all-runtimes"></a>Todos os Runtimes

O C++/CX é compatível com a declaração de um *membro de evento* ou um *bloco de eventos*. Um membro de evento é uma forma abreviada de declarar um bloco de eventos. Por padrão, um membro de evento declara as funções `add()`, `remove()` e `raise()` que são declaradas explicitamente em um bloco de eventos. Para personalizar as funções em um membro de evento, declare um bloco de eventos e, em seguida, substitua as funções necessárias.

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

### <a name="parameters"></a>parâmetros

*modifier*<br/>
Um modificador que pode ser usado na declaração de evento ou em um método de acessador de evento.  Os valores possíveis são **static** e **virtual**.

*delegate*<br/>
O [delegate](delegate-cpp-component-extensions.md), cuja assinatura o manipulador de eventos deve corresponder.

*event_name*<br/>
O nome do evento.

*return_value*<br/>
O valor retornado do método do acessador de eventos.  Para que seja verificável, o tipo de retorno deve ser **void**.

*parameters*<br/>
(opcional) Parâmetros para o método `raise`, que correspondem à assinatura do parâmetro *delegate*.

### <a name="remarks"></a>Comentários

Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao acionamento do evento e permite que clientes de qualquer classe registrem métodos que estão em conformidade com a assinatura e o tipo de retorno do delegado subjacente.

Há dois tipos de declarações de eventos:

*membro de dados de evento*<br/>
O compilador cria automaticamente o armazenamento para o evento na forma de um membro do tipo delegado e cria funções de membro `add()`, `remove()` e `raise()` internas. Um membro de dados de evento deve ser declarado dentro de uma classe. O tipo de retorno do delegado deve corresponder ao tipo de retorno do manipulador de eventos.

*bloco de eventos*<br/>
Um bloco de eventos permite declarar e personalizar explicitamente o comportamento dos métodos `add()`, `remove()` e `raise()`.

Use os operadores **+=** e **-=** para adicionar e remover um manipulador de eventos ou chamar os métodos `add()` e `remove()` explicitamente.

**event** é uma palavra-chave contextual; veja mais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

Saiba mais em [Eventos (C++/CX)](../cppcx/events-c-cx.md).

Se você pretende adicionar e remover um manipulador de eventos, salve a estrutura EventRegistrationToken que é retornada pela operação add. Em seguida, na operação remove, você deve usar a estrutura EventRegistrationToken salva para identificar o manipulador de eventos a remover.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

A palavra-chave **event** possibilita declarar um evento. Um evento é uma maneira de uma classe fornecer notificações quando algo de interesse acontece.

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

### <a name="parameters"></a>parâmetros

*modifier*<br/>
Um modificador que pode ser usado na declaração de evento ou em um método de acessador de evento.  Os valores possíveis são **static** e **virtual**.

*delegate*<br/>
O [delegate](delegate-cpp-component-extensions.md), cuja assinatura o manipulador de eventos deve corresponder.

*event_name*<br/>
O nome do evento.

*return_value*<br/>
O valor retornado do método do acessador de eventos.  Para que seja verificável, o tipo de retorno deve ser **void**.

*parameters*<br/>
(opcional) Parâmetros para o método `raise`, que correspondem à assinatura do parâmetro *delegate*.

### <a name="remarks"></a>Comentários

Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao acionamento do evento e permite que clientes de qualquer classe registrem métodos que estão em conformidade com a assinatura e o tipo de retorno do delegado subjacente.

O delegado pode ter um ou mais métodos associados que serão chamados quando seu código indicar que o evento ocorreu. Um evento em um programa pode ser disponibilizado para outros programas que visam o Common Language Runtime do .NET Framework.

Há dois tipos de declarações de eventos:

*membros de dados de evento*<br/>
O armazenamento para o evento, na forma de um membro do tipo delegado, é criado pelo compilador para eventos de membro de dados.  Um membro de dados de evento deve ser declarado dentro de uma classe. Também é conhecido como um evento trivial (consulte o exemplo de código abaixo).

*blocos de evento*<br/>
Os blocos de eventos facilitam a personalização do comportamento dos métodos de adição, remoção e geração implementando métodos de adição, remoção e geração. A assinatura dos métodos de adição, remoção e geração deve corresponder à assinatura do delegado.  Eventos de bloco de eventos não são membros de dados e qualquer uso como um membro de dados gerará um erro do compilador.

O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado.

No .NET Framework, você pode tratar um membro de dados como um método (ou seja, o método `Invoke` do delegado correspondente). Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado. Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido.  Consulte o exemplo de código no final deste tópico.

Ao declarar um evento gerenciado, você pode especificar acessadores add e remove que serão chamados quando os manipuladores de eventos forem adicionados ou removidos usando os operadores += e -=. Os métodos add, remove e raise podem ser chamados explicitamente.

As seguintes etapas devem ser executadas para criar e usar eventos no Visual C++:

1. Criar ou identificar um delegado. Se você está definindo seu próprio evento, também deve garantir que haja um delegado a ser usado com a palavra-chave **event**. Se o evento é predefinido, no .NET Framework, por exemplo, os consumidores do evento só precisam saber o nome do delegado.

2. Criar uma classe que contém:

   - Um evento criado a partir do delegado.

   - (Opcional) Um método que verifica a existência de uma instância do delegado declarado com a palavra-chave **event**. Caso contrário, essa lógica deve ser colocada no código que aciona o evento.

   - Métodos que chamam o evento. Esses métodos podem ser substituições de alguma funcionalidade de classe base.

   Esta classe define o evento.

3. Definir uma ou mais classes que conectem métodos ao evento. Cada uma dessas classes associará um ou mais métodos ao evento na classe base.

4. Usar o evento:

   - Criação de um objeto da classe que contém a declaração de evento.

   - Criação de um objeto da classe que contém a definição de evento.

Saiba mais sobre eventos C++/CLI em

- [Eventos em uma interface](../dotnet/how-to-use-events-in-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra a declaração de pares de delegados, eventos e manipuladores de eventos; a inscrição (adição) de manipuladores de eventos; a chamada de manipuladores de eventos; e, em seguida, o cancelamento da inscrição (remoção) de manipuladores de eventos.

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

O exemplo de código a seguir demonstra a lógica usada para gerar o método `raise` de um evento trivial: se o evento tiver um ou mais assinantes, chamar o método `raise` implicitamente ou chamar explicitamente o delegado. Se o tipo de retorno do delegado não for **void** e se houver zero assinantes de evento, o método `raise` retornará o valor padrão para o tipo de delegado. Se não houver qualquer assinante de evento, chamar o método `raise` simplesmente retorna e não gera nenhuma exceção. Se o tipo de retorno delegado não for **void**, o tipo de delegado será retornado.

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

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
