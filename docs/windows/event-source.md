---
title: "origem do evento | Microsoft Docs"
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
  - "vc-attr.event_source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "manipulação de eventos, atributos"
  - "logs de evento, origem do evento"
  - "fontes de evento, criando"
  - "Atributo event_source"
  - "fontes de evento"
  - "eventos de manipulação, criar a origem do evento"
ms.assetid: 0983e36a-6127-4fbb-8a22-8dfec6564c16
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# origem do evento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma fonte de evento.  
  
## Sintaxe  
  
```  
  
       [ event_source(  
       type,  
optimize=[speed | size],  
decorate=[true | false]) ]  
```  
  
#### Parâmetros  
 `type`  
 Uma enumeração de um dos seguintes valores:  
  
-   `native` para código C\/C\+\+ não gerenciado \(padrão para classes não gerenciadas\).  
  
-   `com` para o código de COM. Você deve usar `coclass` quando `type`\=`com`. Esse valor exige que você incluir os seguintes arquivos de cabeçalho:  
  
    ```  
    #define _ATL_ATTRIBUTES  
    #include <atlbase.h>  
    #include <atlcom.h>  
    ```  
  
 **optimize**  
 Quando `type` é **nativo**, você pode especificar **otimizar \= tamanho**, para indicar que há 4 bytes de armazenamento \(mínimo\) para todos os eventos em uma classe ou **otimizar \= velocidade** \(o padrão\) para indicar que há 4 \* bytes \(n º de eventos\) de armazenamento.  
  
 **Decore**  
 Quando `type` é **nativo**, você pode especificar **decorar \= false**, para indicar que o nome expandido do arquivo mesclado \(. mrg\) não deve incluir o nome da classe delimitadora.[\/Fx](../build/reference/fx-merge-injected-code.md) permite gerar arquivos. mrg.**decorar \= false**, que é o padrão, o que resulta em nomes de tipo totalmente qualificado no arquivo mesclado.  
  
## Comentários  
 O **event\_source** atributo C\+\+ Especifica que a classe ou estrutura ao qual ela é aplicada será uma fonte de evento.  
  
 **event\_source** é usado em conjunto com o [event\_receiver](../windows/event-receiver.md) atributo e o [Event](../cpp/event.md) palavra\-chave. Use **event\_receiver** criar receptores de evento. Use `__event` em métodos dentro da fonte de evento para especificar esses métodos como eventos.  
  
> [!NOTE]
>  Uma classe de modelo ou struct não pode conter eventos.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Aplica\-se a**|**class**, `struct`|  
|**Repetível**|Não|  
|**Atributos necessários**|**coclass** quando `type`\=**com**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [event\_receiver](../windows/event-receiver.md)   
 [\_\_event](../cpp/event.md)   
 [\_\_hook](../cpp/hook.md)   
 [\_\_unhook](../cpp/unhook.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)