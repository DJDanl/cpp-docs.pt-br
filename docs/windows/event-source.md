---
title: EVENT_SOURCE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.event_source
dev_langs:
- C++
helpviewer_keywords:
- event handling, attributes
- event logs, event source
- event sources, creating
- event_source attribute
- event sources
- event handling, creating event source
ms.assetid: 0983e36a-6127-4fbb-8a22-8dfec6564c16
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bd38dcf02de661a063df356b7d915eed9814f192
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652400"
---
# <a name="eventsource"></a>origem do evento
Cria uma origem de evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ event_source(  
   type,  
   optimize=[speed | size],  
   decorate=[true | false]  
) ]  
```  
  
### <a name="parameters"></a>Parâmetros  
 *type*  
 Uma enumeração de um dos seguintes valores:  
  
-   `native` para código C/C++ não gerenciado (padrão para classes não gerenciadas).  
  
-   `com` para o código de COM. Você deve usar `coclass` quando `type` = `com`. Esse valor requer que você inclua os arquivos de cabeçalho a seguir:  
  
    ```cpp  
    #define _ATL_ATTRIBUTES  
    #include <atlbase.h>  
    #include <atlcom.h>  
    ```  
  
 *optimize*  
 Quando *tipo* é `native`, você pode especificar `optimize=size`, para indicar que há 4 bytes de armazenamento (mínimo) para todos os eventos em uma classe ou `optimize=speed` (o padrão) para indicar que há 4 * bytes (n º de eventos) de armazenamento.  
  
 *Decore*  
 Quando *tipo* é `native`, você pode especificar `decorate=false`, para indicar que o nome expandido no arquivo mesclado (. mrg) não deve incluir o nome da classe delimitadora. [/FX](../build/reference/fx-merge-injected-code.md) permite gerar arquivos. mrg. `decorate=false`, que é o padrão, o que resulta em nomes de tipo totalmente qualificado no arquivo mesclado.  
  
## <a name="remarks"></a>Comentários  
 O **event_source** atributo C++ Especifica que a classe ou estrutura à qual ela é aplicada estejam uma origem do evento.  
  
 **EVENT_SOURCE** é usado em conjunto com o [event_receiver](../windows/event-receiver.md) atributo e o [Event](../cpp/event.md) palavra-chave. Use `event_receiver` para criar receptores de evento. Use **Event** nos métodos dentro da fonte de evento para especificar esses métodos como eventos.  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, **struct**|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|**coclass** quando `type`=`com`|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [event_receiver](../windows/event-receiver.md)   
 [Event](../cpp/event.md)   
 [hook](../cpp/hook.md)   
 [unhook](../cpp/unhook.md)   
 [Atributos de classe](../windows/class-attributes.md)   