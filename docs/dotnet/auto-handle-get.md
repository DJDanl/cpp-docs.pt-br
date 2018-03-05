---
title: auto_handle::Get | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- auto_handle::get
- msclr::auto_handle::get
- auto_handle.get
- msclr.auto_handle.get
dev_langs:
- C++
helpviewer_keywords:
- auto_handle::get
ms.assetid: 8c75727b-8f21-44b3-be3e-7eb8858da4f7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8430c7cfbe92fb681b3affb55ec55c3e0b3c2084
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="autohandleget"></a>auto_handle::get
Obtém o objeto contido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_element_type ^ get();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O objeto contido.  
  
## <a name="example"></a>Exemplo  
  
```  
// msl_auto_handle_get.cpp  
// compile with: /clr  
#include "msclr\auto_handle.h"  
  
using namespace System;  
using namespace msclr;  
  
ref class ClassA {  
   String^ m_s;  
public:  
   ClassA( String^ s ) : m_s( s ){  
      Console::WriteLine( "in ClassA constructor:" + m_s );  
   }  
   ~ClassA() {  
      Console::WriteLine( "in ClassA destructor:" + m_s );  
   }  
  
   void PrintHello() {  
      Console::WriteLine( "Hello from {0} A!", m_s );  
   }  
};  
  
void PrintA( ClassA^ a ) {  
   a->PrintHello();  
}  
  
int main() {  
   auto_handle<ClassA> a = gcnew ClassA( "first" );  
   a->PrintHello();  
  
   ClassA^ a2 = a.get();  
   a2->PrintHello();  
  
   PrintA( a.get() );  
}  
```  
  
```Output  
in ClassA constructor:first  
Hello from first A!  
Hello from first A!  
Hello from first A!  
in ClassA destructor:first  
```  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\auto_handle.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [Membros auto_handle](../dotnet/auto-handle-members.md)