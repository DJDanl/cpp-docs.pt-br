---
title: C2589 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2589
dev_langs:
- C++
helpviewer_keywords:
- C2589
ms.assetid: 1d7942c7-8a81-4bb4-b272-76a0019e8513
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6470a86eec00f0e1913e9947f2767af3d9e85298
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2589"></a>C2589 de erro do compilador
'identifier': token ilegal no lado direito de ': '  
  
 Se uma classe, estrutura ou união nome aparece à esquerda do operador de resolução de escopo (dois-pontos duplo), o token à direita deve ser uma classe, estrutura ou membro de união. Caso contrário, qualquer identificador global pode aparecer à direita.  
  
 O operador de resolução de escopo não pode ser sobrecarregado.  
  
 O exemplo a seguir gera C2589:  
  
```  
// C2589.cpp  
void Test(){}  
class A {};  
void operator :: ();   // C2589  
  
int main() {  
   ::Test();  
}  
```
