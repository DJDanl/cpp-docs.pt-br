---
title: hook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __hook_cpp
- __hook
dev_langs:
- C++
helpviewer_keywords:
- __hook keyword [C++]
- event handlers, connecting events to
ms.assetid: f4cabb10-d293-4c0e-a1d2-4745ef9cc22c
caps.latest.revision: 10
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
ms.openlocfilehash: 21bb75853d8664ad46bc48fc907946ae5a147f9a
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="hook"></a>__hook
Associa um método de manipulador a um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 **&***SourceClass* `::` *EventMethod*  
 Um ponteiro para o método de evento ao qual você engancha o método do manipulador de eventos:  
  
-   Eventos nativos do C++: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
-   Eventos COM: *SourceClass* é a interface de origem do evento e *EventMethod* é um de seus métodos.  
  
-   Eventos gerenciados: *SourceClass* é a classe de origem do evento e *EventMethod* é o evento.  
  
 `interface`  
 O nome da interface que está sendo vinculado para `receiver`, apenas para receptores de evento COM no qual o *layout_dependent* parâmetro do [event_receiver](../windows/event-receiver.md) atributo é **true**.  
  
 *código-fonte*  
 Um ponteiro para uma instância da origem do evento. Dependendo do código `type` especificado em **event_receiver**, *fonte* pode ser um dos seguintes:  
  
-   Um ponteiro nativo do objeto de origem do evento.  
  
-   Um **IUnknown**-com base em ponteiro (fonte COM).  
  
-   Um ponteiro gerenciado do objeto (para eventos gerenciados).  
  
 **&***ReceiverClass* `::``HandlerMethod`  
 Um ponteiro para o método do manipulador de eventos a ser enganchado a um evento. O manipulador é especificado como um método de uma classe ou uma referência a ela. Se você não especificar o nome da classe, `__hook` assumirá a classe como sendo a chamada.  
  
-   Eventos nativos do C++: *ReceiverClass* é a classe do receptor de evento e `HandlerMethod` é o manipulador.  
  
-   Eventos COM: *ReceiverClass* é a interface de receptor de evento e `HandlerMethod` é um dos seus manipuladores.  
  
-   Eventos gerenciados: *ReceiverClass* é a classe do receptor de evento e `HandlerMethod` é o manipulador.  
  
 `receiver`(opcional)  
 Um ponteiro para uma instância da classe do receptor de eventos. Se você não especificar um receptor, o padrão será a classe ou a estrutura receptora na qual `__hook` é chamado.  
  
## <a name="usage"></a>Uso  
 Pode ser o uso em qualquer escopo da função, incluindo o principal, fora da classe do receptor de eventos.  
  
## <a name="remarks"></a>Comentários  
 Use a função intrínseca `__hook` em um receptor de eventos para associar ou enganchar um método de manipulador com um método de evento. O manipulador especificado é chamado quando a origem gera o evento especificado. Você pode enganchar vários manipuladores a um único evento, ou enganchar vários eventos a um único manipulador.  
  
 Há duas formas de `__hook`. Você pode usar o primeiro formulário (quatro argumento) na maioria dos casos, especificamente, para receptores de evento COM no qual o *layout_dependent* parâmetro o [event_receiver](../windows/event-receiver.md) atributo é **false **.  
  
 Nesses casos você não precisa enganchar todos os métodos em uma interface antes de acionar um evento em um dos métodos; somente a manipulação de método do evento precisa ser enganchado. Você pode usar a segunda forma de (dois argumentos) de `__hook` somente para um receptor de evento COM no qual *layout_dependent***= true**.  
  
 `__hook` retorna um valor longo. Um valor de retorno diferente de zero indica que ocorreu um erro (eventos gerenciados lançam uma exceção).  
  
 O compilador verifica a existência de um evento e se a assinatura do evento concorda com a assinatura de delegação.  
  
 Com a exceção de eventos COM, `__hook` e `__unhook` podem ser chamadas fora do receptor de eventos.  
  
 Uma alternativa ao uso de `__hook` é usar o operador + =.  
  
 Para obter informações sobre eventos gerenciados na nova sintaxe de codificação, consulte [evento](../windows/event-cpp-component-extensions.md).  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="example"></a>Exemplo  
 Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) e [manipulação de eventos COM](../cpp/event-handling-in-com.md) para obter exemplos.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Manipulação de eventos](../cpp/event-handling.md)   
 [origem do evento](../windows/event-source.md)   
 [event_receiver](../windows/event-receiver.md)   
 [unhook](../cpp/unhook.md)   
 [__raise](../cpp/raise.md)
