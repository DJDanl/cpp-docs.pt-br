---
title: "Compilador aviso (nível 4) C4516 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4516
dev_langs:
- C++
helpviewer_keywords:
- C4516
ms.assetid: 6677bb1f-d26e-4ab9-8644-6b5a2a8f4ff8
caps.latest.revision: 7
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
ms.openlocfilehash: 2837f23e414d4f6ee58020375851c0874faf1e07
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4516"></a>Compilador C4516 de aviso (nível 4)
'class::symbol': acesso declarações são preteridas; declarações usando membros fornecem uma alternativa melhor  
  
 O Comitê de C++ ANSI declarou declarações de acesso (alterando o acesso de um membro em uma classe derivada sem a [usando](../../cpp/using-declaration.md) palavra-chave) fiquem desatualizados. Declarações de acesso podem não ser compatível com versões futuras do C++.  
  
 O exemplo a seguir gera C4516:  
  
```  
// C4516.cpp  
// compile with: /W4  
class A  
{  
public:  
   void x(char);  
};  
  
class B : protected A  
{  
public:  
   A::x;  // C4516 on access-declaration  
   // use the following line instead  
   // using A::x; // using-declaration, ok  
};  
  
int main()  
{  
}  
```
