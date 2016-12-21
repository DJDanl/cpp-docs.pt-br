---
title: "Erro do Compilador C3706 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3706"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3706"
ms.assetid: d20a33eb-d625-46c5-ac87-32075a590d07
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3706
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: deve ser uma interface COM de eventos acionados COM  
  
 A interface de eventos que você usa para disparar eventos COM deve ser uma interface COM.  Nessa situação, a interface deve ser definida usando um atributo do Visual C\+\+, ou ser importada com [\#import](../Topic/%23import%20Directive%20\(C++\).md) de uma biblioteca de tipos com o atributo de embedded\_idl de \#import.  
  
 Observe que as linhas de `#include` dos arquivos de cabeçalho de ATL mostrados no exemplo a seguir são necessárias usando eventos COM.  Para corrigir esse erro, siga a `IEvents` \(a interface de eventos\) uma interface COM aplicando um dos seguintes atributos à definição da: [objeto](../Topic/object%20\(C++\).md), [double](../Topic/dual.md), ou [dispinterface](../../windows/dispinterface.md).  
  
 Se uma interface é de um arquivo de cabeçalho gerado por MIDL, o compilador não o reconhecerá como uma interface COM.  
  
 O seguinte exemplo gera C3706:  
  
```  
// C3706.cpp  
// compile with: /c  
// C3706 expected  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
#include <atlctl.h>  
  
[module(dll, name="idid", uuid="12341234-1234-1234-1234-123412341234")];  
  
// Uncomment the following line to resolve.  
// [object, uuid="12341234-1234-1234-1234-123412341237"]  
__interface IEvents : IUnknown {  
   HRESULT event1(/*[in]*/ int i);   // uncomment [in]  
};  
  
[dual, uuid="12341234-1234-1234-1234-123412341235"]  
__interface IBase {  
   HRESULT fireEvents();  
};  
  
[coclass, event_source(com), uuid="12341234-1234-1234-1234-123412341236"]  
class CEventSrc : public IBase {  
   public:  
   __event __interface IEvents;  
  
   HRESULT fireEvents() {  
      HRESULT hr = IEvents_event1(123);  
      return hr;  
   }  
};  
```