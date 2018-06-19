---
title: auto_gcroot::Get | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- msclr::auto_gcroot::get
- msclr.auto_gcroot.get
- auto_gcroot::get
- auto_gcroot.get
dev_langs:
- C++
helpviewer_keywords:
- auto_gcroot::get
ms.assetid: 0e922019-1cf5-4220-b5ab-6c4a2a6b40ec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 266193acdd3d1a47fa17539536c1f8d1e18cf7ee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33105511"
---
# <a name="autogcrootget"></a>auto_gcroot::get
Obtém o objeto contido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_element_type get() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O objeto contido.  
  
## <a name="example"></a>Exemplo  
  
```  
// msl_auto_gcroot_get.cpp  
// compile with: /clr  
#include <msclr\auto_gcroot.h>  
  
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
   auto_gcroot<ClassA^> a = gcnew ClassA( "first" );  
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
 **Arquivo de cabeçalho** \<msclr\auto_gcroot.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [Membros auto_gcroot](../dotnet/auto-gcroot-members.md)