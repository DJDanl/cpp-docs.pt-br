---
title: Event | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __event_cpp
- __event
dev_langs:
- C++
helpviewer_keywords:
- __event keyword [C++]
- events [C++], __event
ms.assetid: d3019b3e-722e-48df-8536-c05878461f9e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4750d156ef4f0f817e1eecec1f4a0842fc229046
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="event"></a>__event
Declara um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      __event   
      method-declarator  
      ;  
__event __interface interface-specifier;  
__event member-declarator;  
```  
  
## <a name="remarks"></a>Comentários  
 A palavra-chave `__event` pode ser aplicada a uma declaração de método, uma declaração da interface ou uma declaração de membro de dados. Porém, você não pode usar a palavra-chave `__event` para qualificar um membro de uma classe aninhada.  
  
 Dependendo se sua fonte de evento e receptor são C++ Nativo, COM ou gerenciados (.NET Framework), você pode usar as seguintes construções como eventos:  
  
|C++ Nativo|COM|Gerenciado (.NET Framework)|  
|------------------|---------|--------------------------------|  
|Método|—|method|  
|—|interface|—|  
|—|—|membros de dados|  
  
 Use [hook](../cpp/hook.md) em um receptor de eventos para associar um método manipulador de um método de evento. Observe que depois que você cria um evento com a palavra-chave `__event`, subsequentemente, todos os manipuladores vinculados a esse evento serão chamados quando o evento for chamado.  
  
 Uma declaração de método `__event` não pode ter uma definição; uma definição é gerada implicitamente, para que o método de evento possa ser chamado como se fosse um método comum.  
  
> [!NOTE]
>  Uma classe ou um struct modelo não podem conter eventos.  
  
## <a name="native-events"></a>Eventos nativos  
 Os eventos nativos são métodos. O tipo de retorno normalmente é `HRESULT` ou `void`, mas pode ser qualquer tipo completo, incluindo `enum`. Quando um evento usa um tipo de retorno integral, uma condição de erro é definida quando um manipulador de eventos retorna um valor diferente de zero. Nesse caso, o evento sendo gerado chama os outros delegados.  
  
```  
// Examples of native C++ events:  
__event void OnDblClick();  
__event HRESULT OnClick(int* b, char* s);  
```  
  
 Consulte [manipulação de eventos em C++ nativo](../cpp/event-handling-in-native-cpp.md) para exemplo de código.  
  
## <a name="com-events"></a>Eventos COM  
 Os eventos COM são interfaces. Os parâmetros de um método em uma interface de origem do evento devem ser **na** parâmetros (mas isso não é imposto rigorosamente), porque um **out** parâmetro não é útil quando o multicast. Será emitido um aviso de nível 1, se você usar um **out** parâmetro.  
  
 O tipo de retorno normalmente é `HRESULT` ou `void`, mas pode ser qualquer tipo completo, incluindo `enum`. Quando um evento usa um tipo de retorno integral e um manipulador de eventos retorna uma condição de erro, nesse caso, o evento sendo gerado aborta as chamadas para outros delegados. Observe que o compilador automaticamente marcará uma interface de origem do evento como um [fonte](../windows/source-cpp.md) em IDL gerado.  
  
 O [interface](../cpp/interface.md) palavra-chave é sempre necessário depois `__event` para uma fonte de evento de COM.  
  
```  
// Example of a COM event:  
__event __interface IEvent1;  
```  
  
 Consulte [manipulação de eventos COM](../cpp/event-handling-in-com.md) para exemplo de código.  
  
## <a name="managed-events"></a>Eventos gerenciadas  
 Para obter informações sobre eventos em que a nova sintaxe de codificação, consulte [evento](../windows/event-cpp-component-extensions.md).  
  
 Os eventos gerenciados são membros de dados ou métodos. Quando usado com um evento, o tipo de retorno de um delegado deve ser compatível com o [Common Language Specification](/dotnet/standard/language-independence-and-language-independent-components). O tipo de retorno do manipulador de eventos deve corresponder ao tipo de retorno do delegado. Para obter mais informações sobre delegados, consulte [representantes e eventos](../dotnet/delegates-and-events.md). Se um evento gerenciado for um membro de dados, seu tipo deve ser um ponteiro para um delegado.  
  
 No .NET Framework, você pode tratar um membro de dados como um método (ou seja, o método `Invoke` do delegado correspondente). Você deve predefinir o tipo de delegado para declarar um membro de dados do evento gerenciado. Por outro lado, um método de evento gerenciado define implicitamente o delegado gerenciado correspondente, se ele ainda não tiver sido definido. Por exemplo, você pode declarar um valor do evento como `OnClick` como um evento a seguir:  
  
```  
// Examples of managed events:  
__event ClickEventHandler* OnClick;  // data member as event  
__event void OnClick(String* s);  // method as event  
```  
  
 Ao declarar implicitamente um evento gerenciado, você pode especificamente adicionar e remover acessadores que serão chamados quando manipuladores de eventos forem adicionados ou removidos. Você também pode definir o método que chama (gera) o evento de fora da classe.  
  
## <a name="example-native-events"></a>Exemplo: eventos nativos  
  
```  
// EventHandling_Native_Event.cpp  
// compile with: /c  
[event_source(native)]  
class CSource {  
public:  
   __event void MyEvent(int nValue);  
};  
```  
  
## <a name="example-com-events"></a>Exemplo: eventos COM  
  
```  
// EventHandling_COM_Event.cpp  
// compile with: /c  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
  
[ module(dll, name="EventSource", uuid="6E46B59E-89C3-4c15-A6D8-B8A1CEC98830") ];  
  
[ dual, uuid("00000000-0000-0000-0000-000000000002") ]  
__interface IEventSource {  
   [id(1)] HRESULT MyEvent();  
};  
 [ coclass, uuid("00000000-0000-0000-0000-000000000003"),  event_source(com) ]  
class CSource : public IEventSource {  
public:  
   __event __interface IEventSource;  
   HRESULT FireEvent() {  
      __raise MyEvent();  
      return S_OK;  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Manipulação de eventos](../cpp/event-handling.md)   
 [origem do evento](../windows/event-source.md)   
 [event_receiver](../windows/event-receiver.md)   
 [hook](../cpp/hook.md)   
 [unhook](../cpp/unhook.md)   
 [__raise](../cpp/raise.md)