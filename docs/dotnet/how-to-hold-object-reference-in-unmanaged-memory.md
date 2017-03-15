---
title: "Como manter refer&#234;ncia de objeto na mem&#243;ria n&#227;o gerenciada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave gcroot [C++], referência de objeto na função nativa"
  - "referências de objeto, em funções nativas"
  - "objetos [C++], referência em funções nativas"
  - "referências, a objetos em funções nativas"
ms.assetid: a61eb8ce-3982-477d-8d3d-2173fd57166d
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como manter refer&#234;ncia de objeto na mem&#243;ria n&#227;o gerenciada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar gcroot.h, que envolve <xref:System.Runtime.InteropServices.GCHandle>, para manter uma referência de objeto CLR na memória não gerenciado.  Como alternativa, você pode usar `GCHandle` diretamente.  
  
## Exemplo  
  
```  
// hold_object_reference.cpp  
// compile with: /clr  
#include "gcroot.h"  
using namespace System;  
  
#pragma managed  
class StringWrapper {  
  
private:  
   gcroot<String ^ > x;  
  
public:  
   StringWrapper() {  
      String ^ str = gcnew String("ManagedString");  
      x = str;  
   }  
  
   void PrintString() {  
      String ^ targetStr = x;  
      Console::WriteLine("StringWrapper::x == {0}", targetStr);  
   }  
};  
#pragma unmanaged  
int main() {  
   StringWrapper s;  
   s.PrintString();  
}  
```  
  
  **\=\= ManagedString de StringWrapper::x**   
## Exemplo  
 `GCHandle` isso significa manter uma referência de objeto na memória não gerenciado.  Você usa o método de <xref:System.Runtime.InteropServices.GCHandle.Alloc%2A> para criar um identificador opaca em um objeto gerenciado e a <xref:System.Runtime.InteropServices.GCHandle.Free%2A> para solte.  Além disso, o método de <xref:System.Runtime.InteropServices.GCHandle.Target%2A> permite que você obtenha a parte da referência de objeto de identificador em código gerenciado.  
  
```  
// hold_object_reference_2.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma managed  
class StringWrapper {  
   IntPtr m_handle;  
public:  
   StringWrapper() {  
      String ^ str = gcnew String("ManagedString");  
      m_handle = static_cast<IntPtr>(GCHandle::Alloc(str));  
   }  
   ~StringWrapper() {  
      static_cast<GCHandle>(m_handle).Free();  
   }  
  
   void PrintString() {  
      String ^ targetStr = safe_cast< String ^ >(static_cast<GCHandle>(m_handle).Target);  
      Console::WriteLine("StringWrapper::m_handle == {0}", targetStr);  
   }  
};  
  
#pragma unmanaged  
int main() {  
   StringWrapper s;   
   s.PrintString();  
}  
```  
  
  **\=\= ManagedString de StringWrapper::m\_handle**   
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)