---
title: "evento (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- event
- event_cpp
dev_langs: C++
helpviewer_keywords: event keyword [C++]
ms.assetid: c4998e42-883c-4419-bbf4-36cdc979dd27
caps.latest.revision: "34"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6e821d68fac0467d48a2056e1818c3fd58963581
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="event--c-component-extensions"></a>evento (Extensões de Componentes C++)
O `event` palavra-chave declara um *evento*, que é uma notificação para assinantes registrados (*manipuladores de eventos*) que algo interessante ocorreu.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 C + + CX dá suporte à declaração um *membro de evento* ou um *bloco de evento*. Um membro de evento é abreviado para declarar um bloco de evento. Por padrão, um membro de evento declara o `add()`, `remove()`, e `raise()` funções que são declaradas explicitamente em um bloco de evento. Para personalizar as funções em um membro de evento, declare um bloco de evento em vez disso e, em seguida, substituir as funções que você precisa.  
  
 **Sintaxe**  
  
```  
  
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
  
 **Parâmetros**  
  
 *modificador*  
 Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são `static` e `virtual`.  
  
 *delegate*  
 O [delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura deve corresponder o manipulador de eventos.  
  
 *event_name*  
 O nome do evento.  
  
 *RETURN_VALUE*  
 O valor de retorno do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser `void`.  
  
 *parâmetros*  
 (opcional) Parâmetros para o `raise` método, que corresponda à assinatura do *delegar* parâmetro.  
  
 **Comentários**  
  
 Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao disparo do evento e permite que os clientes de qualquer classe registrar métodos que estão em conformidade com a assinatura e retorna o tipo do delegado subjacente.  
  
 Há dois tipos de declarações de eventos:  
  
 *membro de dados de evento*  
 O compilador automaticamente cria o armazenamento para o evento na forma de um membro do tipo delegado e cria interno `add()`, `remove()`, e `raise()` funções de membro. Um membro de dados de evento deve ser declarado dentro de uma classe. O tipo de retorno do tipo de retorno do delegado deve corresponder ao tipo de retorno do manipulador de eventos.  
  
 *bloco de evento*  
 Um bloco de eventos permite que você declare explicitamente e personalizar o comportamento do `add()`, `remove()`, e `raise()` métodos.  
  
 Você pode usar `operators+=` e `operator-=` para adicionar e remover um evento manipulador ou chamada de `add()` e `remove()` métodos explicitamente.  
  
 `event`é uma palavra-chave contextual; consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [eventos (C + + CX)](http://msdn.microsoft.com/library/windows/apps/hh755799.aspx).  
  
 Se você pretende adicionar e, em seguida, remover um manipulador de eventos, você deve salvar a estrutura de EventRegistrationToken que é retornada pela operação de adição. Em seguida, na operação de remoção, você deve usar a estrutura EventRegistrationToken salva para identificar o manipulador de eventos a ser removido.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 O `event` palavra-chave permite que você declarar um evento. Um evento é uma forma de uma classe fornecer notificações quando algo interessante acontece.  
  
 **Sintaxe**  
  
```  
  
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
  
 **Parâmetros**  
  
 *modificador*  
 Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são `static` e `virtual`.  
  
 *delegate*  
 O [delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura deve corresponder o manipulador de eventos.  
  
 *event_name*  
 O nome do evento.  
  
 *RETURN_VALUE*  
 O valor de retorno do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser `void`.  
  
 *parâmetros*  
 (opcional) Parâmetros para o `raise` método, que corresponda à assinatura do *delegar* parâmetro.  
  
 **Comentários**  
  
 Um evento é uma associação entre um delegado e uma função de membro (manipulador de eventos) que responde ao disparo do evento e permite que os clientes de qualquer classe registrar métodos que estão em conformidade com a assinatura e retorna o tipo do delegado subjacente.  
  
 O representante pode ter um ou mais métodos associados que serão chamados quando o seu código indica que o evento ocorreu. Um evento em um programa pode ser disponibilizado para outros programas que se destinam a common language runtime do .NET Framework.  
  
 Há dois tipos de declarações de eventos:  
  
 *membros de dados de evento*  
 Armazenamento para o evento, na forma de um membro do tipo delegado, é criado pelo compilador para eventos de membro de dados.  Um membro de dados de evento deve ser declarado dentro de uma classe. Isso também é conhecido como um evento trivial (consulte o exemplo de código abaixo).  
  
 *blocos de eventos*  
 Blocos de eventos lhe permitem personalizar o comportamento de métodos de aumento, adicionar e remover Implementando a adicionar, remover e métodos de aumento. A assinatura de métodos de aumento, adicionar e remover deve corresponder à assinatura do delegado.  Eventos de bloqueio de eventos não são membros de dados e qualquer uso como um membro de dados irá gerar um erro do compilador. 
  
 O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado.  
  
 No .NET Framework, você pode tratar um membro de dados como um método (ou seja, o método `Invoke` do delegado correspondente). Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado. Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido.  Consulte o exemplo de código no final deste tópico para obter um exemplo.  
  
 Ao declarar um evento gerenciado, você pode especificar adicionar e remover acessadores que serão chamados quando os manipuladores de eventos são adicionados ou removidos usando + operadores = e-=. Os métodos add, remove e raise podem ser chamados explicitamente.  
  
 As etapas a seguir devem ser executadas para criar e usar os eventos no Visual C++:  
  
1.  Criar ou identificar um representante. Se você estiver definindo seus próprios eventos, você também deve garantir que há um delegado a ser usado com o `event` palavra-chave. Se o evento é predefinido, no .NET Framework, por exemplo, em seguida, os consumidores de evento só precisam saber o nome do representante.  
  
2.  Crie uma classe que contém:  
  
    -   Um evento criado a partir do delegado.  
  
    -   (opcional) Um método que verifica se uma instância do representante declarado com o `event` palavra-chave existe. Caso contrário, essa lógica deve ser colocada no código que aciona o evento.  
  
    -   Métodos que chamam o evento. Esses métodos podem ser substituições de algumas funcionalidades de classe base.  
  
     Essa classe define o evento.  
  
3.  Defina uma ou mais classes que se conectam a métodos para o evento. Cada uma dessas classes irá associar um ou mais métodos de evento na classe base.  
  
4.  Use o evento:  
  
    -   Crie um objeto da classe que contém a declaração de evento.  
  
    -   Crie um objeto da classe que contém a definição do evento.  
  
 Para obter mais informações sobre C + + CLI eventos, consulte  
  
-   [Eventos em uma Interface](../dotnet/how-to-use-events-in-cpp-cli.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra a declaração de pares de delegados, eventos e manipuladores de eventos; Assinando (Adicionar) os manipuladores de eventos; invocar os manipuladores de eventos; e, em seguida, cancelar a assinatura (remover) os manipuladores de eventos.  
  
```  
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
  
 **Saída**  
  
```Output  
OnClick: 7, 3.14159  
  
OnDblClick: Hello  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra a lógica usada para gerar o `raise` método de um evento trivial: se o evento tem um ou mais assinantes, chamar o `raise` método implicitamente ou explicitamente chama o representante. Se o delegado de retorno do tipo não for `void` e se não houver nenhuma assinantes do evento, o `raise` método retorna o valor padrão para o tipo delegado. Se não houver nenhum assinantes do evento, chamar o `raise` método simplesmente retorna e nenhuma exceção é gerada. Se o delegado de tipo de retorno não `void`, será retornado o tipo delegado.  
  
```  
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
  
 **Saída**  
  
```Output  
0  
  
688  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)