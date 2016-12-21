---
title: "__hook | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__hook_cpp"
  - "__hook"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __hook [C++]"
  - "manipuladores de eventos, conectando eventos a"
ms.assetid: f4cabb10-d293-4c0e-a1d2-4745ef9cc22c
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __hook
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Associa um método de manipulador a um evento.  
  
## Sintaxe  
  
```  
  
      long __hook(  
   &SourceClass::EventMethod,  
   source,  
   &ReceiverClass::HandlerMethod  
   [, receiver = this]  
);  
long __hook(  
   interface,  
   source  
);  
```  
  
#### Parâmetros  
 **&** *SourceClass* `::` *EventMethod*  
 Um ponteiro para o método de evento ao qual você engancha o método do manipulador de eventos:  
  
-   Eventos nativos do C\+\+: *SourceClass* é a classe da origem do evento e *EventMethod* é o evento.  
  
-   Eventos COM: *SourceClass* é a interface da origem do evento e *EventMethod* é um dos métodos.  
  
-   Eventos gerenciados: *SourceClass* é a classe da origem do evento e *EventMethod* é o evento.  
  
 `interface`  
 O nome da interface sendo enganchado a `receiver`, apenas para os receptores do evento COM, nos quais o parâmetro *layout\_dependent* do atributo de [event\_receiver](../windows/event-receiver.md) é **true**.  
  
 *origem*  
 Um ponteiro para uma instância da origem do evento.  Dependendo do código `type` especificado em **event\_receiver**, *a origem* pode ser uma das seguintes:  
  
-   Um ponteiro nativo do objeto de origem do evento.  
  
-   Um ponteiro baseado em **IUnknown** \(origem COM\).  
  
-   Um ponteiro gerenciado do objeto \(para eventos gerenciados\).  
  
 **&** *ReceiverClass* `::` `HandlerMethod`  
 Um ponteiro para o método do manipulador de eventos a ser enganchado a um evento.  O manipulador é especificado como um método de uma classe ou uma referência à mesma; se você não especificar o nome da classe, `__hook` assume a classe como sendo a chamada.  
  
-   Eventos nativos de C\+\+: *ReceiverClass* é a classe do receptor de eventos e `HandlerMethod` é o manipulador.  
  
-   Eventos COM: *ReceiverClass* é a interface do receptor de eventos e `HandlerMethod` é um dos manipuladores.  
  
-   Eventos gerenciados: *ReceiverClass* é a classe do receptor de eventos e `HandlerMethod` é o manipulador.  
  
 `receiver`\(opcional\)  
 Um ponteiro para uma instância da classe do receptor de eventos.  Se você não especificar um receptor, o padrão será a classe ou a estrutura receptora na qual que `__hook` é chamado.  
  
## Uso  
 Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.  
  
## Comentários  
 Use a função intrínseca `__hook` em um receptor de eventos para associar ou enganchar um método de manipulador com um método de evento.  O manipulador especificado é chamado quando a origem gera o evento especificado.  Você pode enganchar vários manipuladores a um único evento, ou enganchar vários eventos a um único manipulador.  
  
 Há duas formas de `__hook`.  Você pode usar o primeiro formulário \(quatro argumentos\) na maioria dos casos, especificamente, para os receptores de eventos COM nos quais o parâmetro *layout\_dependent* do atributo [event\_receiver](../windows/event-receiver.md) é **false**.  
  
 Nesses casos você não precisa enganchar todos os métodos em uma interface antes de acionar um evento em um dos métodos; somente a manipulação de método do evento precisa ser enganchado.  Você pode usar o segundo formulário \(dois argumentos\) de `__hook` apenas para um receptor de eventos COM no qual *layout\_dependent***\=true**.  
  
 `__hook` retorna um valor longo.  Um valor de retorno diferente de zero indica que ocorreu um erro \(eventos gerenciados lançam uma exceção\).  
  
 O compilador verifica a existência de um evento e se a assinatura do evento concorda com a assinatura de delegação.  
  
 Com a exceção de eventos COM, `__hook` e `__unhook` podem ser chamadas fora do receptor de eventos.  
  
 Uma alternativa ao uso de `__hook` é usar o operador \+ \=.  
  
 Para obter informações sobre a codificação gerenciada de eventos na nova sintaxe, consulte [event](../windows/event-cpp-component-extensions.md).  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## Exemplo  
 Consulte [Tratamento de eventos em C\+\+ nativo](../Topic/Event%20Handling%20in%20Native%20C++.md) e [Tratamento de eventos em COM](../cpp/event-handling-in-com.md) para ver exemplos.  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Manipulação de eventos](../cpp/event-handling.md)   
 [origem do evento](../windows/event-source.md)   
 [event\_receiver](../windows/event-receiver.md)   
 [\_\_unhook](../cpp/unhook.md)   
 [\_\_raise](../cpp/raise.md)