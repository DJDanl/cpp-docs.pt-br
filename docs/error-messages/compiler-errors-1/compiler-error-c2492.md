---
title: C2492 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2492
dev_langs:
- C++
helpviewer_keywords:
- C2492
ms.assetid: 8c44c9bb-c366-4fe5-a0ab-882e38608aaa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 68b3d769c5b86be172a0a27828fb1dc3905959d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33197358"
---
# <a name="compiler-error-c2492"></a>C2492 de erro do compilador
'*variável*': dados com duração de armazenamento de thread não podem possuir dll interface    
  
 A variável é declarada com o [thread](../../cpp/thread.md) atributo e com a DLL de interface. O endereço do `thread` variável não é conhecida até o tempo de execução, para que ele não pode ser vinculado a uma DLL de importação ou exportação.  
  
 O exemplo a seguir gera C2492:  
  
```  
// C2492.cpp  
// compile with: /c  
class C {  
public:  
   char   ch;  
};  
  
__declspec(dllexport) __declspec(thread) C c_1;   // C2492  
__declspec(thread) C c_1;   // OK  
```