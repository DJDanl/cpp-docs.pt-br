---
title: "__event | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__event_cpp"
  - "__event"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __event [C++]"
  - "eventos [C++], __event"
ms.assetid: d3019b3e-722e-48df-8536-c05878461f9e
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __event
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara um evento.  
  
## Sintaxe  
  
```  
  
      __event   
      method-declarator  
      ;  
__event __interface interface-specifier;  
__event member-declarator;  
```  
  
## Comentários  
 A palavra\-chave `__event` pode ser aplicada a uma declaração de método, uma declaração da interface ou uma declaração de membro de dados.  Porém, você não pode usar a palavra\-chave `__event` para qualificar um membro de uma classe aninhada.  
  
 Dependendo se sua fonte de evento e receptor são C\+\+ Nativo, COM ou gerenciados \(.NET Framework\), você pode usar as seguintes construções como eventos:  
  
|C\+\+ Nativo|COM|Gerenciado \(.NET Framework\)|  
|------------------|---------|-----------------------------------|  
|Método|—|method|  
|—|interface|—|  
|—|—|membros de dados|  
  
 Use [\_\_hook](../cpp/hook.md) em um receptor de eventos para associar um método de manipulador com um método de evento.  Observe que depois que você cria um evento com a palavra\-chave `__event`, subsequentemente, todos os manipuladores vinculados a esse evento serão chamados quando o evento for chamado.  
  
 Uma declaração de método `__event` não pode ter uma definição; uma definição é gerada implicitamente, para que o método de evento possa ser chamado como se fosse um método comum.  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## Eventos nativos  
 Os eventos nativos são métodos.  O tipo de retorno normalmente é `HRESULT` ou `void`, mas pode ser qualquer tipo completo, incluindo `enum`.  Quando um evento usa um tipo de retorno integral, uma condição de erro é definida quando um manipulador de eventos retorna um valor diferente de zero. Nesse caso, o evento sendo gerado chama os outros delegados.  
  
```  
// Examples of native C++ events:  
__event void OnDblClick();  
__event HRESULT OnClick(int* b, char* s);  
```  
  
 Consulte [Manipulação de eventos em C\+\+ Nativo](../Topic/Event%20Handling%20in%20Native%20C++.md) para obter o código de exemplo.  
  
## Eventos COM  
 Os eventos COM são interfaces.  Os parâmetros de um método em uma interface da origem do evento devem ser parâmetros **in** \(mas isso não é rigorosamente imposto\), pois um parâmetro **out** não é útil para o multicasting.  Um aviso de nível 1 será emitido se você utilizar um parâmetro **out**.  
  
 O tipo de retorno normalmente é `HRESULT` ou `void`, mas pode ser qualquer tipo completo, incluindo `enum`.  Quando um evento usa um tipo de retorno integral e um manipulador de eventos retorna uma condição de erro, nesse caso, o evento sendo gerado aborta as chamadas para outros delegados.  Observe que o compilador marcará automaticamente uma interface de origem do evento como [source](../Topic/source%20\(C++\).md) em um IDL gerado.  
  
 A palavra\-chave [\_\_interface](../Topic/__interface.md) sempre é necessária após `__event` para uma origem de evento COM.  
  
```  
// Example of a COM event:  
__event __interface IEvent1;  
```  
  
 Consulte [Manipulação de eventos em COM](../cpp/event-handling-in-com.md) para obter o código de exemplo.  
  
## Eventos gerenciadas  
 Para obter informações sobre a codificação de eventos na nova sintaxe, consulte [event](../windows/event-cpp-component-extensions.md).  
  
 Os eventos gerenciados são membros de dados ou métodos.  Quando usado com um evento, o tipo de retorno de um delegado deve ser compatível com a [CLS](../Topic/Language%20Independence%20and%20Language-Independent%20Components.md).  O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado.  Para obter mais informações sobre delegados, consulte [\_\_delegate](../Topic/__delegate.md).  Se um evento gerenciado for um membro de dados, seu tipo deve ser um ponteiro para um delegado.  
  
 No .NET Framework, você pode tratar um membro de dados como um método \(ou seja, o método `Invoke` do delegado correspondente\).  Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado.  Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido.  Por exemplo, você pode declarar um valor do evento como `OnClick` como um evento a seguir:  
  
```  
// Examples of managed events:  
__event ClickEventHandler* OnClick;  // data member as event  
__event void OnClick(String* s);  // method as event  
```  
  
 Ao declarar implicitamente um evento gerenciado, você pode especificamente adicionar e remover acessadores que serão chamados quando manipuladores de eventos forem adicionados ou removidos.  Você também pode definir o método que chama \(gera\) o evento de fora da classe.  
  
## Exemplo: eventos nativos  
  
```  
// EventHandling_Native_Event.cpp  
// compile with: /c  
[event_source(native)]  
class CSource {  
public:  
   __event void MyEvent(int nValue);  
};  
```  
  
## Exemplo: eventos COM  
  
```  
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
  
## Exemplo: eventos gerenciados  
  
```  
// EventHandling_Managed_Event.cpp  
// compile with: /clr:oldSyntax /c  
using namespace System;  
[event_source(managed)]  
public __gc class CPSource {  
  
public:  
   __event void MyEvent(Int16 nValue);  
};  
```  
  
 Ao aplicar um atributo a um evento, você pode especificar se o atributo se aplica aos métodos gerados o método ou ao método invocado do delegado gerado.  O padrão \(`event:`\) é aplicar o atributo ao evento.  
  
```  
// EventHandling_Managed_Event_2.cpp  
// compile with: /clr:oldSyntax /c  
using namespace System;  
[attribute(All, AllowMultiple=true)]  
public __gc class Attr {};  
  
public __delegate void D();  
  
public __gc class X {  
public:  
   [method:Attr] __event D* E;  
   [returnvalue:Attr] __event void noE();  
};  
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Manipulação de eventos](../cpp/event-handling.md)   
 [origem do evento](../windows/event-source.md)   
 [event\_receiver](../windows/event-receiver.md)   
 [\_\_hook](../cpp/hook.md)   
 [\_\_unhook](../cpp/unhook.md)   
 [\_\_raise](../cpp/raise.md)