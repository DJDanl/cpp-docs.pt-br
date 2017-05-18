---
title: "Compilador aviso (nível 1) C4530 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4530
dev_langs:
- C++
helpviewer_keywords:
- C4530
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
caps.latest.revision: 8
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
ms.openlocfilehash: 883b9f2896f3c6f09c97f38881a5b934a0128124
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4530"></a>Compilador C4530 de aviso (nível 1)
Manipulador de exceção de C++ usado, mas a semântica de desenrolamento não estão habilitados. Especificar /EHsc  
  
 Tratamento de exceções C++ foi usado, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi selecionada.  
  
 Quando a opção de /EHsc não foi habilitada, um objeto com armazenamento automático no quadro, entre a função de fazer o lançamento e a função capturando o lançamento, não será destruído. No entanto, um objeto com armazenamento automático criado em uma **tente** ou **catch** bloco será destruído.  
  
 O exemplo a seguir gera C4530:  
  
```  
// C4530.cpp  
// compile with: /W1  
int main() {  
   try{} catch(int*) {}   // C4530  
}  
```  
  
 Compile o exemplo com /EHsc para resolver o aviso.
