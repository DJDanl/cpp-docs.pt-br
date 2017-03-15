---
title: C3706 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 080298796a97d6b983b7ff731f6c25ec11722b1b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3706"></a>C3706 de erro do compilador
'function': deve ser uma interface COM para acionar eventos COM  
  
 A interface de eventos que você usa para acionar eventos COM deve ser uma interface COM. Nessa situação, a interface devem ser definida usando um atributo de Visual C++ ou importados usando [#import](../../preprocessor/hash-import-directive-cpp.md) de uma biblioteca de tipos com atributo de embedded_idl do #import.  
  
 Observe que o `#include` linhas dos arquivos de cabeçalho ATL mostrados no exemplo a seguir são necessárias para o uso de eventos COM. Para corrigir esse erro, verifique `IEvents` (a interface de eventos) uma interface COM aplicando um dos seguintes atributos à definição de interface: [objeto](../../windows/object-cpp.md), [dual](../../windows/dual.md), ou [dispinterface](../../windows/dispinterface.md).  
  
 Se uma interface for de um arquivo de cabeçalho gerado pelo MIDL, o compilador não a reconhecerá como uma interface COM.  
  
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
