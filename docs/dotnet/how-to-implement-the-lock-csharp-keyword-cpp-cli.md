---
title: 'Como: implementar a palavra-chave c# de bloqueio (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- lock statement
- lock C# keyword [C++]
ms.assetid: 436fe544-ffb7-49b9-9798-90794e9974de
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: e016a0f481063711cb5daafe45110a1d53b16253
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-implement-the-lock-c-keyword-ccli"></a>Como implementar a palavra-chave do C# de bloqueio (C++/CLI)
Este tópico mostra como implementar o c# `lock` palavra-chave no Visual C++. 
  
 Você também pode usar o `lock` classe na biblioteca de suporte do C++. Consulte [sincronização (classe lock)](../dotnet/synchronization-lock-class.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Interoperabilidade com outras linguagens .NET (C++/CLI)](../dotnet/interoperability-with-other-dotnet-languages-cpp-cli.md)