---
title: C2384 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2384
dev_langs:
- C++
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce139166e2378a26a91bc66db134ec6098aedbdc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33194925"
---
# <a name="compiler-error-c2384"></a>C2384 de erro do compilador
'member': não é possível aplicar __declspec(thread) a um membro de um gerenciado ou classe WinRT  
  
 O [thread](../../cpp/thread.md) `__declspec` modificador não pode ser usado em uma classe de tempo de execução do Windows ou um membro de um gerenciado.  
  
 DLLs carregadas de thread estático armazenamento local no código gerenciado só pode ser usado para estaticamente — a DLL deve ser carregada estaticamente ao iniciar o processo. Tempo de execução do Windows não oferece suporte a armazenamento local de thread.  
  
 A linha a seguir gera C2384 e mostra como corrigi-lo em C + + código:  
  
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