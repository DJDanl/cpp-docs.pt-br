---
title: "event_receiver | Microsoft Docs"
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
  - "vc-attr.event_receiver"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "event_receiver attribute"
  - "event receivers"
  - "events [C++], event receivers (sinks)"
  - "event handling [C++], attributes"
  - "event handling [C++], creating receiver"
  - "event sinks, creating"
  - "event sinks"
ms.assetid: bf8fe770-3ea2-4128-b46b-166222ee4097
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# event_receiver
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria um receptor de eventos \(coletor\).  
  
## Sintaxe  
  
```  
  
      [ event_receiver(  
   type   
   [, layout_dependent=false]   
) ]  
```  
  
#### Parâmetros  
 `type`  
 Uma enumeração de um dos seguintes valores:  
  
-   `native`para código C\/C\+\+ não gerenciado \(o padrão para as classes nativas\).  
  
-   `com`para o código de COM.  Esse valor exige que você incluir os seguintes arquivos de cabeçalho:  
  
    ```  
    #define _ATL_ATTRIBUTES  
    #include <atlbase.h>  
    #include <atlcom.h>  
    ```  
  
 **layout\_dependent**  
 Especificar  *layout\_dependent* somente se `type`\=**com**.  *layout\_dependent* é um booleano:  
  
-   **True** significa que a assinatura dos delegados no caso de receptor deve corresponder exatamente àqueles aos quais eles são conectados o fonte.  Os nomes de manipulador do evento receptor devem coincidir com os nomes especificados na interface de origem do evento relevantes.  Você deve usar  **coclass** quando  *layout\_dependent* é  **true**.  É um pouco mais eficiente para especificar  **true**.  
  
-   **False** \(padrão\) significa que a classe de armazenamento e a convenção de chamada \(virtual, estático e outros\) não precisa coincidir com o método de eventos e os manipuladores; nem os nomes de manipulador precisa coincidir com os nomes de método de interface de origem evento.  
  
## Comentários  
 O  **event\_receiver** atributo C\+\+ Especifica que a classe ou estrutura à qual ela é aplicada será um receptor de eventos, usando o modelo de evento unificado do Visual C\+\+.  
  
 **event\_receiver** é usado com o  [event\_source](../windows/event-source.md) atributo e o  [\_\_hook](../cpp/hook.md) e  [\_\_unhook](../cpp/unhook.md) as palavras\-chave.  Use  **event\_source** para criar origens de eventos.  Use `__hook` dentro de métodos de um receptor de eventos para associar os métodos de receptor de eventos \("hook"\) para os eventos de uma fonte de evento.  Use `__unhook` para dissociá\-los.  
  
 *layout\_dependent* é especificada somente para receptores de evento COM \(`type`\=**com**\).  O padrão para  *layout\_dependent* é  **false**.  
  
> [!NOTE]
>  Modelado class ou struct não pode conter eventos.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|**coclass** quando  *layout\_dependent*\=**true**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [origem do evento](../windows/event-source.md)   
 [\_\_event](../cpp/event.md)   
 [\_\_hook](../cpp/hook.md)   
 [\_\_unhook](../cpp/unhook.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)