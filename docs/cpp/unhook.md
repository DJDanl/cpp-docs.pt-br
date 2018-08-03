---
title: unhook | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __unhook
- __unhook_cpp
dev_langs:
- C++
helpviewer_keywords:
- event handlers [C++], dissociating events
- __unhook keyword [C++]
ms.assetid: 953a14f3-5199-459d-81e5-fcf015a19878
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 020ae54cdaaddc2f05a8c3b6e285bc2fd0403ee8
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39463708"
---
# <a name="unhook"></a>__unhook
Dissocia um método de manipulador de um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp 
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
  
#### <a name="parameters"></a>Parâmetros  
 **&** *SourceClass* `::` *EventMethod*  
 Um ponteiro para o método de evento do qual você desengancha o método do manipulador de eventos:  
  
-   Eventos nativos do C++: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
-   Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um dos seus métodos.  
  
-   Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
 *interface*  
 O nome da interface que está sendo desligado de *receptor*, apenas para os receptores de evento no qual o *layout_dependent* parâmetro do [event_receiver](../windows/event-receiver.md) atributo é **verdadeira**.  
  
 *source*  
 Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado no `event_receiver`, *origem* pode ser uma das seguintes opções:  
  
-   Um ponteiro nativo do objeto de origem do evento.  
  
-   Um `IUnknown`-com base em ponteiro (origem COM).  
  
-   Um ponteiro gerenciado do objeto (para eventos gerenciados).  
  
 **&** *ReceiverClass* `::` `HandlerMethod`  
 Um ponteiro para o método do manipulador de eventos a ser desenganchado de um evento. O manipulador é especificado como um método de uma classe ou uma referência a ela. Se você não especificar o nome de classe **unhook** pressupõe que a classe seja que, no qual ele é chamado.  
  
-   Eventos nativos do C++: *ReceiverClass* é a classe de receptor de evento e `HandlerMethod` é o manipulador.  
  
-   Eventos COM: *ReceiverClass* é a interface do receptor de evento e `HandlerMethod` é um dos manipuladores.  
  
-   Eventos gerenciados: *ReceiverClass* é a classe de receptor de evento e `HandlerMethod` é o manipulador.  
  
 *receptor*(opcional)  
 Um ponteiro para uma instância da classe do receptor de eventos. Se você não especificar um receptor, o padrão é a classe do receptor ou estrutura na qual **unhook** é chamado.  
  
## <a name="usage"></a>Uso  
 Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.  
  
## <a name="remarks"></a>Comentários  
 Use a função intrínseca **unhook** em um receptor de eventos para desassociar ou "desenganchar" um método de manipulador de um método de evento.  
  
 Há três formas de **unhook**. Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos. Você pode usar o segundo formulário (dois argumentos) de **unhook** apenas para um receptor de evento COM; isso desengancha a interface de evento completa. Você pode usar o terceiro formato (um argumento) para desenganchar todos os representantes da origem especificada.  
  
 Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançarão uma exceção).  
  
 Se você chamar **unhook** em um evento e o manipulador de eventos que ainda não estão enganchados, ele não terá efeito.  
  
 Em tempo de compilação, o compilador verifica se o evento existe e faz a verificação do tipo de parâmetro com o manipulador especificado.  
  
 Com exceção dos eventos COM, **hook** e **unhook** pode ser chamado fora do receptor do evento.  
  
 Uma alternativa ao uso **unhook** é usar o operador-=.  
  
 Para obter informações sobre a codificação gerenciada de eventos na nova sintaxe, consulte [evento](../windows/event-cpp-component-extensions.md).  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="example"></a>Exemplo  
 Ver [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos em COM](../cpp/event-handling-in-com.md) para obter exemplos.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [EVENT_SOURCE](../windows/event-source.md)   
 [event_receiver](../windows/event-receiver.md)   
 [Event](../cpp/event.md)   
 [hook](../cpp/hook.md)   
 [__raise](../cpp/raise.md)