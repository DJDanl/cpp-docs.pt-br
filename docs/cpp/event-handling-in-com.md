---
title: "Tratamento de eventos em COM | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "COM, eventos"
  - "declarando eventos"
  - "declarando eventos, tratamento de evento em COM"
  - "declarando eventos, em COM"
  - "manipuladores de eventos"
  - "manipuladores de eventos, COM"
  - "manipulação de eventos"
  - "manipulação de eventos, sobre tratamento de evento"
  - "manipulação de eventos, COM"
  - "receptores de evento, em tratamento de evento"
  - "receptores de evento, correspondência de nome e assinatura"
  - "fontes de evento, em tratamento de evento"
  - "eventos de gancho"
ms.assetid: 6b4617d4-a58e-440c-a8a6-1ad1c715b2bb
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de eventos em COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na manipulação de eventos COM, você configura uma origem de evento e um receptor de evento usando os atributos [event\_source](../windows/event-source.md) e [event\_receiver](../windows/event-receiver.md), respectivamente, especificando `type`\=**com**.  Esses atributos injetam o código apropriado para interfaces personalizadas, duais e de expedição a fim de permitir que as classes às quais são aplicados acionem eventos e manipulem eventos por meio de pontos de conexão COM.  
  
## Declarando eventos  
 Em uma classe de origem de evento, use a palavra\-chave [\_\_event](../cpp/event.md) em uma declaração de interface para declarar os métodos dessa interface como eventos.  Os eventos dessa interface são acionados quando você os chama como métodos da interface.  Os métodos em interfaces de evento podem ter zero ou mais parâmetros \(que devem ser todos parâmetros **in**\).  O tipo de retorno pode ser void ou qualquer tipo integral.  
  
## Definindo manipuladores de eventos  
 Em uma classe de receptor de evento, você define manipuladores de eventos, que são métodos com assinaturas \(tipos de retorno, convenções de chamada e argumentos\) que correspondem ao evento que eles manipularão.  Para eventos COM, as convenções de chamada não precisam ter correspondência; consulte [Eventos COM dependentes do layout](#vcconeventhandlingincomanchorlayoutdependentcomevents), mais adiante, para obter detalhes.  
  
## Vinculando manipuladores de eventos a eventos  
 Também em uma classe de receptor de evento, você usa a função intrínseca [\_\_hook](../cpp/hook.md) para associar eventos a manipuladores de eventos e [\_\_unhook](../cpp/unhook.md) para desassociar eventos de manipuladores de eventos.  Você pode vincular diversos eventos a um manipulador ou vincular diversos manipuladores a um evento.  
  
> [!NOTE]
>  Normalmente, há duas técnicas para permitir que um receptor de evento COM acesse definições de interface de origem de evento.  O primeiro, conforme mostrado abaixo, é compartilhar um arquivo de cabeçalho comum.  O segundo é usar [\#import](../Topic/%23import%20Directive%20\(C++\).md) com o qualificador de importação `embedded_idl`, para que a biblioteca de tipos de origem de evento seja gravada no arquivo .tlh com o código gerado pelo atributo preservado.  
  
## Acionando eventos  
 Para acionar um evento, basta chamar um método na interface declarada com a palavra\-chave `__event` na classe da origem do evento.  Se houver manipuladores vinculados ao evento, eles serão chamados.  
  
### Código de evento COM  
 O exemplo a seguir mostra como acionar um evento em uma classe COM.  Para compilar e executar o exemplo, consulte os comentários no código.  
  
```  
// evh_server.h  
#pragma once  
  
[ dual, uuid("00000000-0000-0000-0000-000000000001") ]  
__interface IEvents {  
   [id(1)] HRESULT MyEvent([in] int value);  
};  
  
[ dual, uuid("00000000-0000-0000-0000-000000000002") ]  
__interface IEventSource {  
   [id(1)] HRESULT FireEvent();  
};  
  
class DECLSPEC_UUID("530DF3AD-6936-3214-A83B-27B63C7997C4") CSource;  
```  
  
 Então o servidor:  
  
```  
// evh_server.cpp  
// compile with: /LD  
// post-build command: Regsvr32.exe /s evh_server.dll  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
#include "evh_server.h"  
  
[ module(dll, name="EventSource", uuid="6E46B59E-89C3-4c15-A6D8-B8A1CEC98830") ];  
  
[coclass, event_source(com), uuid("530DF3AD-6936-3214-A83B-27B63C7997C4")]  
class CSource : public IEventSource {  
public:  
   __event __interface IEvents;   
  
   HRESULT FireEvent() {  
      __raise MyEvent(123);  
      return S_OK;  
   }  
};  
```  
  
 Então o cliente:  
  
```  
// evh_client.cpp  
// compile with: /link /OPT:NOREF  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
#include <stdio.h>  
#include "evh_server.h"  
  
[ module(name="EventReceiver") ];  
  
[ event_receiver(com) ]  
class CReceiver {  
public:  
   HRESULT MyHandler1(int nValue) {  
      printf_s("MyHandler1 was called with value %d.\n", nValue);  
      return S_OK;  
   }  
  
   HRESULT MyHandler2(int nValue) {  
      printf_s("MyHandler2 was called with value %d.\n", nValue);  
      return S_OK;  
   }  
  
   void HookEvent(IEventSource* pSource) {  
      __hook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler1);  
      __hook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler2);  
   }  
  
   void UnhookEvent(IEventSource* pSource) {  
      __unhook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler1);  
      __unhook(&IEvents::MyEvent, pSource, &CReceiver::MyHandler2);  
   }  
};  
  
int main() {  
   // Create COM object  
   CoInitialize(NULL);  
   {  
      IEventSource* pSource = 0;  
      HRESULT hr = CoCreateInstance(__uuidof(CSource), NULL,         CLSCTX_ALL, __uuidof(IEventSource), (void **) &pSource);  
      if (FAILED(hr)) {  
         return -1;  
      }  
  
      // Create receiver and fire event  
      CReceiver receiver;  
      receiver.HookEvent(pSource);  
      pSource->FireEvent();  
      receiver.UnhookEvent(pSource);  
   }  
   CoUninitialize();  
   return 0;  
}  
```  
  
### Saída  
  
```  
MyHandler1 was called with value 123.  
MyHandler2 was called with value 123.  
```  
  
##  <a name="vcconeventhandlingincomanchorlayoutdependentcomevents"></a> Eventos COM dependentes do layout  
 A dependência do layout só é um problema para a programação COM.  Na manipulação de eventos nativos e gerenciados, as assinaturas \(tipo de retorno, convenção de chamada e argumentos\) dos manipuladores devem corresponder aos respectivos eventos, mas os nomes dos manipuladores não precisam corresponder aos respectivos eventos.  
  
 Porém, na manipulação de eventos COM, quando você define o parâmetro *layout\_dependent* de **event\_receiver** como **true**, a correspondência de nomes e assinaturas é imposta.  Isso significa que os nomes e as assinaturas dos manipuladores no receptor de evento devem corresponder exatamente aos nomes e às assinaturas dos eventos aos quais estão vinculados.  
  
 Quando *layout\_dependent* é definido como **false**, a convenção de chamada e a classe de armazenamento \(virtual, estático, etc.\) podem ser misturadas e combinadas entre o método de acionamento de eventos e os métodos de vinculação \(os representantes\).  É um pouco mais eficiente configurar *layout\_dependent*\=**true**.  
  
 Por exemplo, suponha que `IEventSource` esteja definido para ter os seguintes métodos:  
  
```  
[id(1)] HRESULT MyEvent1([in] int value);  
[id(2)] HRESULT MyEvent2([in] int value);  
```  
  
 Pressuponha que a origem do evento tenha o seguinte formato:  
  
```  
[coclass, event_source(com)]  
class CSource : public IEventSource {  
public:  
   __event __interface IEvents;  
  
   HRESULT FireEvent() {  
      MyEvent1(123);  
      MyEvent2(123);  
      return S_OK;  
   }  
};  
```  
  
 Em seguida, no receptor do evento, qualquer manipulador vinculado a um método em `IEventSource` deve corresponder ao nome e à assinatura, como se segue:  
  
```  
[coclass, event_receiver(com, true)]  
class CReceiver {  
public:  
   HRESULT MyEvent1(int nValue) {  // name and signature matches MyEvent1  
      ...  
   }  
   HRESULT MyEvent2(E c, char* pc) {  // signature doesn't match MyEvent2  
      ...  
   }  
   HRESULT MyHandler1(int nValue) {  // name doesn't match MyEvent1 (or 2)  
      ...  
   }  
   void HookEvent(IEventSource* pSource) {  
      __hook(IFace, pSource);  // Hooks up all name-matched events   
                               // under layout_dependent = true  
      __hook(&IFace::MyEvent1, pSource, &CReceive::MyEvent1);   // valid  
      __hook(&IFace::MyEvent2, pSource, &CSink::MyEvent2);   // not valid  
      __hook(&IFace::MyEvent1, pSource, &CSink:: MyHandler1); // not valid  
   }  
};  
```  
  
## Consulte também  
 [Manipulação de eventos](../cpp/event-handling.md)