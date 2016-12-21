---
title: "event  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "event"
  - "event_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "event keyword [C++]"
ms.assetid: c4998e42-883c-4419-bbf4-36cdc979dd27
caps.latest.revision: 34
caps.handback.revision: 32
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# event  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `event` palavra\-chave declara um *evento*, que é uma notificação para assinantes registrados \(*manipuladores de eventos*\) que ocorreu algo interessante.  
  
## Todos os Tempos de Execução  
 C \+ c\+\+ \/CX dá suporte à declaração um *membro de evento* ou um *Bloco de evento*.  Um membro de evento é a forma abreviada para declarar um bloco de evento.  Por padrão, um membro de evento declara o `add()`, `remove()`, e `raise()` funções que são declaradas explicitamente em um bloco de evento.  Para personalizar as funções em um membro de evento, declare um bloco de evento em vez disso e, em seguida, substituir as funções que você precisa.  
  
 **Sintaxe**  
  
```  
  
// event data member  
modifier event delegate^ event_name;     
  
// event block  
modifier event delegate^ event_name   
{  
   modifier return_value add(delegate^ name);  
   modifier void remove(delegate^ name);  
   modifier void raise(parameters);  
}  
```  
  
 **Parâmetros**  
  
 *modificador*  
 Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são `static` e `virtual`.  
  
 *delegado*  
 O [Delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura deve coincidir com o manipulador de eventos.  
  
 *event\_name*  
 O nome do evento.  
  
 *RETURN\_VALUE*  
 O valor de retorno do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser `void`.  
  
 *parâmetros*  
 \(opcional\) Parâmetros para o `raise` método, que correspondem à assinatura do *Delegar* parâmetro.  
  
 **Observações**  
  
 Um evento é uma associação entre um delegado e uma função de membro \(manipulador de eventos\) que responde ao disparo do evento e permite que os clientes de qualquer classe registrar métodos que estar em conformidade com a assinatura e tipo de retorno do delegate subjacente.  
  
 Há dois tipos de declarações de eventos:  
  
 *membro de dados de evento*  
 O compilador automaticamente cria o armazenamento para o evento na forma de um membro do tipo delegado e cria interno `add()`, `remove()`, e `raise()` funções de membro.  Um membro de dados de evento deve ser declarado dentro de uma classe.  O tipo de retorno do tipo de retorno do delegado deve corresponder ao tipo de retorno do manipulador de eventos.  
  
 *bloco de evento*  
 Um bloco de evento permite que você declare explicitamente e personalizar o comportamento do `add()`, `remove()`, e `raise()` métodos.  
  
 Você pode usar `operators+=` e `operator-=` para adicionar e remover um evento manipulador ou chamada de `add()` e `remove()` métodos explicitamente.  
  
 `event` é uma palavra\-chave contextual; consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
  
### Observações  
 Para obter mais informações, consulte [eventos \(C \+ c\+\+ \/CX\)](http://msdn.microsoft.com/library/windows/apps/hh755799.aspx).  
  
 Se você pretende adicionar e remover um manipulador de eventos, você deve salvar a estrutura de EventRegistrationToken que é retornada pela operação de adicionar.  Em seguida, na operação de remoção, você deve usar a estrutura EventRegistrationToken salva para identificar o manipulador de eventos a ser removido.  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 O `event` palavra\-chave permite declarar um evento.  Um evento é uma forma de uma classe para fornecer notificações quando algo interessante acontece.  
  
 **Sintaxe**  
  
```  
  
// event data member  
modifier event delegate^ event_name;   
  
// event block  
modifier event delegate^ event_name   
{  
   modifier return_value add(delegate^ name);  
   modifier void remove(delegate^ name);  
   modifier void raise(parameters);  
}  
```  
  
 **Parâmetros**  
  
 *modificador*  
 Um modificador que pode ser usado na declaração de evento ou um método de acessador de evento.  Os valores possíveis são `static` e `virtual`.  
  
 *delegado*  
 O [Delegar](../windows/delegate-cpp-component-extensions.md), cuja assinatura deve coincidir com o manipulador de eventos.  
  
 *event\_name*  
 O nome do evento.  
  
 *RETURN\_VALUE*  
 O valor de retorno do método de acessador de evento.  Para que seja verificável, o tipo de retorno deve ser `void`.  
  
 *parâmetros*  
 \(opcional\) Parâmetros para o `raise` método, que correspondem à assinatura do *Delegar* parâmetro.  
  
 **Observações**  
  
 Um evento é uma associação entre um delegado e uma função de membro \(manipulador de eventos\) que responde ao disparo do evento e permite que os clientes de qualquer classe registrar métodos que estar em conformidade com a assinatura e tipo de retorno do delegate subjacente.  
  
 O delegado pode ter um ou mais métodos associados que serão chamados quando seu código indica que o evento ocorreu.  Um evento em um programa pode ser disponibilizado para outros programas que visam o .NET Framework common language runtime.  Consulte [Gerando um evento definido em um Assembly diferente](../misc/how-to-raise-events-defined-in-a-different-assembly.md) para obter um exemplo.  
  
 Há dois tipos de declarações de eventos:  
  
 *membros de dados de evento*  
 Armazenamento para o evento, na forma de um membro do tipo delegado, é criado pelo compilador para eventos de membro de dados.  Um membro de dados de evento deve ser declarado dentro de uma classe.  Isso também é conhecido como um evento trivial \(consulte o exemplo de código abaixo.\)  
  
 *blocos de evento*  
 Blocos de eventos permitem que você personalize o comportamento da adicionar, remover e métodos de aumento, Implementando a adicionar, remover e métodos de aumento.  A assinatura dos métodos de aumento, adicionar e remover deve corresponder à assinatura do delegado.  Eventos de bloqueio não são membros de dados e qualquer uso como um membro de dados irá gerar um erro do compilador.  Consulte [definir métodos de acessador de evento](../misc/how-to-define-event-accessor-methods.md) para obter um exemplo.  
  
 O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado.  
  
 No .NET Framework, você pode tratar um membro de dados como um método \(ou seja, o método `Invoke` do delegado correspondente\).  Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado.  Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido.  Consulte o código de exemplo no final deste tópico para obter um exemplo.  
  
 Ao declarar um evento gerenciado, você poderá adicionar e remover acessadores que serão chamados quando manipuladores de eventos são adicionados ou removidos usando \+ operadores \= e\-\=.  Os métodos add, remove e raise podem ser chamados explicitamente.  
  
 As etapas a seguir devem ser executadas para criar e usar eventos em Visual C\+\+:  
  
1.  Criar ou identificar um delegado.  Se você estiver definindo seus próprios eventos, você também deve garantir que haja um delegado a ser usado com o `event` palavra\-chave.  Se o evento é predefinido, no .NET Framework, por exemplo, em seguida, os consumidores do evento só precisam saber o nome do representante.  
  
2.  Crie uma classe que contém:  
  
    -   Um evento criado a partir do delegado.  
  
    -   \(opcional\) Um método que verifica se uma instância do delegado declarado com o `event` palavra\-chave existe.  Caso contrário, essa lógica deve ser colocada no código que dispara o evento.  
  
    -   Métodos que chamam o evento.  Esses métodos podem ser substituições de alguma funcionalidade da classe base.  
  
     Essa classe define o evento.  
  
3.  Defina uma ou mais classes que se conectam a métodos para o evento.  Cada uma dessas classes irá associar um ou mais métodos de evento na classe base.  
  
4.  Use o evento:  
  
    -   Crie um objeto da classe que contém a declaração de evento.  
  
    -   Crie um objeto da classe que contém a definição do evento.  
  
 Para obter mais informações sobre [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)] eventos, consulte  
  
-   [Eventos em uma Interface](../dotnet/how-to-use-events-in-cpp-cli.md)  
  
-   [Substituindo o acesso padrão de add, remove e raise métodos](../misc/how-to-override-default-access-of-add-remove-and-raise-methods.md)  
  
-   [Vários manipuladores a um evento](../misc/how-to-add-multiple-handlers-to-events.md)  
  
-   [Eventos virtuais gerenciados](../misc/how-to-implement-managed-virtual-events.md)  
  
-   [Métodos de acessador de evento](../misc/how-to-define-event-accessor-methods.md)  
  
-   [Eventos estáticos](../Topic/How%20to:%20Define%20and%20Use%20Static%20Events.md)  
  
-   [Gerando um evento definido em um Assembly diferente](../misc/how-to-raise-events-defined-in-a-different-assembly.md)  
  
-   [Eventos abstratos](../misc/how-to-implement-abstract-events.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra a declaração pares de delegados, eventos e manipuladores de eventos; Assinando \(Adicionar\) os manipuladores de eventos; invocar os manipuladores de eventos; e, em seguida, cancelar a assinatura \(remover\) os manipuladores de eventos.  
  
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
  
  **OnClick: 7, 3,14159**  
 **OnDblClick: Olá** **Exemplo**  
  
 O exemplo de código a seguir demonstra a lógica usada para gerar o `raise` método de um evento trivial: se o evento tem um ou mais assinantes, chamar o `raise` método implícita ou explicitamente chama o delegado.  Se o delegado do retorno tipo não é `void` e se há assinantes zero eventos, o `raise` método retorna o valor padrão para o tipo de delegado.  Se não houver nenhum assinante de evento, chamar o `raise` método simplesmente retorna e nenhuma exceção é gerada.  Se o delegado de retorno tipo `void`, o tipo de delegado é retornado.  
  
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
  
  **0**  
 **688**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)