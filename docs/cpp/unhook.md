---
title: "__unhook | Microsoft Docs"
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
  - "__unhook"
  - "__unhook_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __unhook [C++]"
  - "manipuladores de eventos, dissociando eventos"
ms.assetid: 953a14f3-5199-459d-81e5-fcf015a19878
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __unhook
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dissocia um método de manipulador de um evento.  
  
## Sintaxe  
  
```  
  
      long  __unhook(  
   &SourceClass::EventMethod,  
   source,  
   &ReceiverClass::HandlerMethod  
   [, receiver = this]   
);  
long  __unhook(   
   interface,  
   source  
);  
long  __unhook(  
   source   
);  
```  
  
#### Parâmetros  
 **&** *SourceClass* `::` *EventMethod*  
 Um ponteiro para o método de evento do qual você desengancha o método do manipulador de eventos:  
  
-   Eventos nativos do C\+\+: *SourceClass* é a classe da origem do evento e *EventMethod* é o evento.  
  
-   Eventos COM: *SourceClass* é a interface da origem do evento e *EventMethod* é um dos métodos.  
  
-   Eventos gerenciados: *SourceClass* é a classe da origem do evento e *EventMethod* é o evento.  
  
 `interface`  
 O nome da interface que está sendo desenganchada de `receiver`, apenas para os receptores de evento COM nos quais o parâmetro *layout\_dependent* do atributo [event\_receiver](../windows/event-receiver.md) é **true**.  
  
 *origem*  
 Um ponteiro para uma instância da origem do evento.  Dependendo do código `type` especificado em **event\_receiver**, *a origem* pode ser uma das seguintes:  
  
-   Um ponteiro nativo do objeto de origem do evento.  
  
-   Um ponteiro baseado em **IUnknown** \(origem COM\).  
  
-   Um ponteiro gerenciado do objeto \(para eventos gerenciados\).  
  
 **&** *ReceiverClass* `::` `HandlerMethod`  
 Um ponteiro para o método do manipulador de eventos a ser desenganchado de um evento.  O manipulador é especificado como um método de uma classe ou uma referência a ela. Se você não especificar o nome da classe, `__unhook` assumirá a classe como sendo a chamada.  
  
-   Eventos nativos de C\+\+: *ReceiverClass* é a classe do receptor de eventos e `HandlerMethod` é o manipulador.  
  
-   Eventos COM: *ReceiverClass* é a interface do receptor de eventos e `HandlerMethod` é um dos manipuladores.  
  
-   Eventos gerenciados: *ReceiverClass* é a classe do receptor de eventos e `HandlerMethod` é o manipulador.  
  
 `receiver`\(opcional\)  
 Um ponteiro para uma instância da classe do receptor de eventos.  Se você não especificar um receptor, o padrão será a classe ou a estrutura receptora na qual `__unhook` é chamado.  
  
## Uso  
 Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.  
  
## Comentários  
 Use a função intrínseca `__unhook` em um receptor de eventos para desassociar ou "desenganchar" um método de manipulador de um método de evento.  
  
 Há três formas de `__unhook`.  Você pode usar o primeiro formulário \(quatro argumento\) na maioria dos casos.  Você pode usar o segundo formulário \(dois argumentos\) de `__unhook` apenas para um receptor de eventos COM. Isso desengancha toda a interface de eventos.  Você pode usar o terceiro formato \(um argumento\) para desenganchar todos os representantes da origem especificada.  
  
 Um valor de retorno diferente de zero indica que ocorreu um erro \(eventos gerenciados lançarão uma exceção\).  
  
 Se você chamar `__unhook` em um evento e o manipulador de eventos que ainda não estão enganchados, a chamada não terá nenhum efeito.  
  
 Em tempo de compilação, o compilador verifica se o evento existe e faz a verificação do tipo de parâmetro com o manipulador especificado.  
  
 Com a exceção de eventos COM, `__hook` e `__unhook` podem ser chamadas fora do receptor de eventos.  
  
 Uma alternativa ao uso de `__unhook` é usar o operador \- \=.  
  
 Para obter informações sobre a codificação gerenciada de eventos na nova sintaxe, consulte [event](../windows/event-cpp-component-extensions.md).  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## Exemplo  
 Consulte [Tratamento de eventos em C\+\+ nativo](../Topic/Event%20Handling%20in%20Native%20C++.md) e [Tratamento de eventos em COM](../cpp/event-handling-in-com.md) para ver exemplos.  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [origem do evento](../windows/event-source.md)   
 [event\_receiver](../windows/event-receiver.md)   
 [\_\_event](../cpp/event.md)   
 [\_\_hook](../cpp/hook.md)   
 [\_\_raise](../cpp/raise.md)