---
title: C2492 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2492
dev_langs:
- C++
helpviewer_keywords:
- C2492
ms.assetid: 8c44c9bb-c366-4fe5-a0ab-882e38608aaa
caps.latest.revision: 10
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
ms.sourcegitcommit: 4bac7b2942f9d72674b8092dc7bf64174dd3c349
ms.openlocfilehash: 54a650e967acb2ee0b6864780823111b4db9414c
ms.lasthandoff: 04/24/2017

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
