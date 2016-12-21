---
title: "Como implementar a palavra-chave do C# de bloqueio (C++/CLI) | Microsoft Docs"
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
  - "Palavra-chave lock C# [C++]"
  - "instrução lock"
ms.assetid: 436fe544-ffb7-49b9-9798-90794e9974de
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como implementar a palavra-chave do C# de bloqueio (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como implementar a palavra\-chave C\# `lock` no Visual C\+\+.  Para obter mais informações, consulte [Instrução lock](../Topic/lock%20Statement%20\(C%23%20Reference\).md).  
  
 Você também pode usar a classe de `lock` na biblioteca de suporte C\+\+.  Consulte [Sincronização \(classe lock\)](../dotnet/synchronization-lock-class.md) para maiores informações.  
  
## Exemplo  
  
```  
// CS_lock_in_CPP.cpp  
// compile with: /clr  
using namespace System::Threading;  
ref class Lock {  
   Object^ m_pObject;  
public:  
   Lock( Object ^ pObject ) : m_pObject( pObject ) {  
      Monitor::Enter( m_pObject );  
   }  
   ~Lock() {  
      Monitor::Exit( m_pObject );  
   }  
};  
  
ref struct LockHelper {  
   void DoSomething();  
};  
  
void LockHelper::DoSomething() {  
   // Note: Reference type with stack allocation semantics to provide   
   // deterministic finalization  
  
   Lock lock( this );     
   // LockHelper instance is locked  
}  
  
int main()  
{  
   LockHelper lockHelper;  
   lockHelper.DoSomething();  
   return 0;  
}  
```  
  
## Consulte também  
 [Interoperabilidade com outras linguagens .NET](../dotnet/interoperability-with-other-dotnet-languages-cpp-cli.md)