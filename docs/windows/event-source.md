---
title: origem do evento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.event_source
dev_langs: C++
helpviewer_keywords:
- event handling, attributes
- event logs, event source
- event sources, creating
- event_source attribute
- event sources
- event handling, creating event source
ms.assetid: 0983e36a-6127-4fbb-8a22-8dfec6564c16
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 05371b5c2d9acd091adcbdf81d2994f205e36ef7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventsource"></a>origem do evento
Cria uma origem de evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ event_source(  
   type,  
   optimize=[speed | size],  
   decorate=[true | false]  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 Uma enumeração de um dos seguintes valores:  
  
-   `native`para código C/C++ não gerenciado (padrão para classes não gerenciadas).  
  
-   `com`para o código de COM. Você deve usar `coclass` quando `type` = `com`. Esse valor requer que você inclua os arquivos de cabeçalho a seguir:  
  
    ```  
    #define _ATL_ATTRIBUTES  
    #include <atlbase.h>  
    #include <atlcom.h>  
    ```  
  
 **optimize**  
 Quando `type` é **nativo**, você pode especificar **otimizar = tamanho**, para indicar que há 4 bytes de armazenamento (mínimo) para todos os eventos em uma classe ou **otimizar = velocidade** (o padrão) para indicar que há 4 * bytes (número de eventos) de armazenamento.  
  
 **Decore**  
 Quando `type` é **nativo**, você pode especificar **decorar = false**, para indicar que o nome expandido no arquivo mesclado (. mrg) não deve incluir o nome da classe delimitador. [/FX](../build/reference/fx-merge-injected-code.md) permite a geração de arquivos. mrg. **Decore = false**, que é o padrão, o que resulta em nomes de tipo totalmente qualificado no arquivo mesclado.  
  
## <a name="remarks"></a>Comentários  
 O **event_source** atributo C++ Especifica que a classe ou estrutura ao qual ela é aplicada será uma fonte de evento.  
  
 **origem do evento** é usada em conjunto com o [event_receiver](../windows/event-receiver.md) atributo e o [Event](../cpp/event.md) palavra-chave. Use **event_receiver** criar receptores de evento. Use `__event` em métodos dentro da fonte de evento para especificar os métodos de eventos.  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass** quando `type` = **com**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [event_receiver](../windows/event-receiver.md)   
 [Event](../cpp/event.md)   
 [hook](../cpp/hook.md)   
 [unhook](../cpp/unhook.md)   
 [Atributos de classe](../windows/class-attributes.md)   
