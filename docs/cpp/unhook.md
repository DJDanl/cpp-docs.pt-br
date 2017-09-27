---
title: unhook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __unhook
- __unhook_cpp
dev_langs:
- C++
helpviewer_keywords:
- event handlers, dissociating events
- __unhook keyword [C++]
ms.assetid: 953a14f3-5199-459d-81e5-fcf015a19878
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 2b1909cf5d7bde440d434bb44ff2276e68679e78
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="unhook"></a>__unhook
Dissocia um método de manipulador de um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 **&***SourceClass* `::` *EventMethod*  
 Um ponteiro para o método de evento do qual você desengancha o método do manipulador de eventos:  
  
-   Eventos nativos do C++: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
-   Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um de seus métodos.  
  
-   Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
 `interface`  
 O nome da interface que está sendo desligado de `receiver`, apenas para receptores de evento COM no qual o *layout_dependent* parâmetro o [event_receiver](../windows/event-receiver.md) atributo é **true**.  
  
 *código-fonte*  
 Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado em **event_receiver**, *fonte* pode ser um dos seguintes:  
  
-   Um ponteiro nativo do objeto de origem do evento.  
  
-   Um **IUnknown**-com base em ponteiro (fonte COM).  
  
-   Um ponteiro gerenciado do objeto (para eventos gerenciados).  
  
 **&***ReceiverClass* `::``HandlerMethod`  
 Um ponteiro para o método do manipulador de eventos a ser desenganchado de um evento. O manipulador é especificado como um método de uma classe ou uma referência a ela. Se você não especificar o nome da classe, `__unhook` assumirá a classe como sendo a chamada.  
  
-   Eventos nativos do C++: *ReceiverClass* é a classe do receptor de evento e `HandlerMethod` é o manipulador.  
  
-   Eventos COM: *ReceiverClass* é a interface de receptor de evento e `HandlerMethod` é um dos seus manipuladores.  
  
-   Eventos gerenciados: *ReceiverClass* é a classe do receptor de evento e `HandlerMethod` é o manipulador.  
  
 `receiver`(opcional)  
 Um ponteiro para uma instância da classe do receptor de eventos. Se você não especificar um receptor, o padrão será a classe ou a estrutura receptora na qual `__unhook` é chamado.  
  
## <a name="usage"></a>Uso  
 Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.  
  
## <a name="remarks"></a>Comentários  
 Use a função intrínseca `__unhook` em um receptor de eventos para desassociar ou "desenganchar" um método de manipulador de um método de evento.  
  
 Há três formas de `__unhook`. Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos. Você pode usar o segundo formulário (dois argumentos) de `__unhook` apenas para um receptor de eventos COM. Isso desengancha toda a interface de eventos. Você pode usar o terceiro formato (um argumento) para desenganchar todos os representantes da origem especificada.  
  
 Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançarão uma exceção).  
  
 Se você chamar `__unhook` em um evento e o manipulador de eventos que ainda não estão enganchados, a chamada não terá nenhum efeito.  
  
 Em tempo de compilação, o compilador verifica se o evento existe e faz a verificação do tipo de parâmetro com o manipulador especificado.  
  
 Com a exceção de eventos COM, `__hook` e `__unhook` podem ser chamadas fora do receptor de eventos.  
  
 Uma alternativa ao uso de `__unhook` é usar o operador - =.  
  
 Para obter informações sobre eventos gerenciados na nova sintaxe de codificação, consulte [evento](../windows/event-cpp-component-extensions.md).  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="example"></a>Exemplo  
 Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos COM](../cpp/event-handling-in-com.md) para obter exemplos.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [origem do evento](../windows/event-source.md)   
 [event_receiver](../windows/event-receiver.md)   
 [Event](../cpp/event.md)   
 [hook](../cpp/hook.md)   
 [__raise](../cpp/raise.md)
