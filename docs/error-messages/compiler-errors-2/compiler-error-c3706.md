---
title: C3706 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3706
dev_langs:
- C++
helpviewer_keywords:
- C3706
ms.assetid: d20a33eb-d625-46c5-ac87-32075a590d07
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8cb54dfce6a6974fcf09886f2d13047cdab53ced
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33265240"
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