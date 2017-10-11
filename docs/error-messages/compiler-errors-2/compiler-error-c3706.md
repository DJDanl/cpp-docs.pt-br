---
title: C3706 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3706
dev_langs:
- C++
helpviewer_keywords:
- C3706
ms.assetid: d20a33eb-d625-46c5-ac87-32075a590d07
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 20f7e14d22e1994213624d88ccab098844aa6ac4
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3706"></a>C3706 de erro do compilador
'function': deve ser uma interface COM para disparar eventos COM  
  
 A interface de eventos que você pode usar para disparar eventos COM deve ser uma interface COM. Nessa situação, a interface devem ser definida usando um atributo de Visual C++ ou importados usando [#import](../../preprocessor/hash-import-directive-cpp.md) de uma biblioteca de tipo com atributo de embedded_idl do #import.  
  
 Observe que o `#include` linhas dos arquivos de cabeçalho de ATL mostrados no exemplo a seguir são necessárias para usar COM os eventos. Para corrigir esse erro, verifique `IEvents` (a interface de eventos) uma interface COM aplicando um dos seguintes atributos à definição da interface: [objeto](../../windows/object-cpp.md), [dual](../../windows/dual.md), ou [ dispinterface](../../windows/dispinterface.md).  
  
 Se uma interface for de um arquivo de cabeçalho gerado pelo MIDL, o compilador não o reconhecerão como uma interface COM.  
  
 O exemplo a seguir gera C3706:  
  
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
