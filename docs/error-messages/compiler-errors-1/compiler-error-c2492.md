---
title: C2492 de erro do compilador | Documentos do Microsoft
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4824ec9e7683f35a1caa3122f937ff1a7646c2c9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2492"></a>C2492 de erro do compilador
'variável': dados de 'thread' talvez não tenha interface de dll  
  
 A variável é declarada com o [thread](../../cpp/thread.md) atributo e com a DLL de interface. O endereço do `thread` variável não é conhecida até o tempo de execução, portanto ele não pode ser vinculado a uma DLL de importação ou exportação.  
  
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
