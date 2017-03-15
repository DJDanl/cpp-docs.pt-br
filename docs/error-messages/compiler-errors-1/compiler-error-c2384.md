---
title: C2384 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2384
dev_langs:
- C++
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
caps.latest.revision: 15
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
ms.openlocfilehash: 0f44af65c5de565f505aa31eb50fcaecfc09c1e1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2384"></a>C2384 de erro do compilador
'member': não é possível aplicar __declspec(thread) a um membro de um gerenciado ou classe do WinRT  
  
 O [segmento](../../cpp/thread.md) `__declspec` modificador não pode ser usado em um membro de um gerenciado ou classe de tempo de execução do Windows.  
  
 Armazenamento local em código gerenciado só pode ser usado de forma estática de thread estático DLLs carregadas — a DLL deve ser carregada estaticamente quando o processo é iniciado. Tempo de execução do Windows não oferece suporte a armazenamento local de thread.  
  
 A linha a seguir gera C2384 e mostra como corrigi-lo em C + + / código CLI:  
  
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
