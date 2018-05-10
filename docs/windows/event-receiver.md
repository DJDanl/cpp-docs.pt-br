---
title: event_receiver | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.event_receiver
dev_langs:
- C++
helpviewer_keywords:
- event_receiver attribute
- event receivers
- events [C++], event receivers (sinks)
- event handling [C++], attributes
- event handling [C++], creating receiver
- event sinks, creating
- event sinks
ms.assetid: bf8fe770-3ea2-4128-b46b-166222ee4097
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 01ab5aeee7d706da7016cb1ea1f01ff7367de888
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="eventreceiver"></a>event_receiver
Cria um receptor de eventos (coletor).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ event_receiver(  
   type   
   [, layout_dependent=false]   
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 Uma enumeração de um dos seguintes valores:  
  
-   `native` para código C/C++ não gerenciado (padrão para as classes nativas).  
  
-   `com` para o código de COM. Esse valor requer que você inclua os arquivos de cabeçalho a seguir:  
  
    ```  
    #define _ATL_ATTRIBUTES  
    #include <atlbase.h>  
    #include <atlcom.h>  
    ```  
  
 **layout_dependent**  
 Especifique *layout_dependent* somente se `type` = **com**. *layout_dependent* é um valor booliano:  
  
-   **True** significa que a assinatura delegados no destinatário deve corresponder exatamente ao qual eles estão conectados no evento origem de eventos. Os nomes de manipulador de receptor de evento devem corresponder aos nomes especificados na interface de origem do evento relevantes. Você deve usar **coclass** quando *layout_dependent* é **true**. É um pouco mais eficiente especificar **true**.  
  
-   **False** (padrão) significa que a classe de armazenamento e a convenção de chamada (virtual, estático e outros) não precisa coincidir com o método de evento e os manipuladores; nem os nomes de manipulador precisam coincidir com os nomes de método de interface de origem do evento.  
  
## <a name="remarks"></a>Comentários  
 O **event_receiver** atributo C++ Especifica que a classe ou estrutura ao qual ela é aplicada será um receptor de evento, usando o modelo de evento unificado do Visual C++.  
  
 **event_receiver** é usado com o [event_source](../windows/event-source.md) atributo e o [hook](../cpp/hook.md) e [unhook](../cpp/unhook.md) palavras-chave. Use **event_source** para criar fontes de evento. Use `__hook` em métodos de um receptor evento para associar os métodos de receptor de evento ("gancho") para os eventos de uma origem de evento. Use `__unhook` para dissociá-los.  
  
 *layout_dependent* só é especificado para receptores de evento COM (`type`=**com**). O padrão para *layout_dependent* é **false**.  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**class**, `struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass** quando *layout_dependent*=**true**|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [origem do evento](../windows/event-source.md)   
 [Event](../cpp/event.md)   
 [hook](../cpp/hook.md)   
 [unhook](../cpp/unhook.md)   
 [Atributos de classe](../windows/class-attributes.md)   
