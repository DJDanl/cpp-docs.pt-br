---
title: "Compiler Error C2384 | Microsoft Docs"
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
  - "C2384"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2384"
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compiler Error C2384
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'member': não é possível aplicar \_\_declspec\(thread\) a um membro de um gerenciado ou classe do WinRT  
  
 O [segmento](../../cpp/thread.md) `__declspec` modificador não pode ser usado em uma classe de tempo de execução do Windows ou um membro de um gerenciado.  
  
 Armazenamento local em código gerenciado só pode ser usado de forma estática de thread estático DLLs carregadas — a DLL deve ser carregada estaticamente quando o processo é iniciado.  Tempo de execução do Windows não oferece suporte a armazenamento local de thread.  
  
 A linha a seguir gera C2384 e mostra como corrigi\-lo em C\+\+ \/CLI código CLI:  
  
```  
// C2384.cpp  
// compile with: /clr /c  
public ref class B {  
public:  
   __declspec( thread ) static int tls_i = 1;   // C2384  
  
   // OK - declare with attribute instead  
   [System::ThreadStaticAttribute]  
   static int tls_j;  
};  
```