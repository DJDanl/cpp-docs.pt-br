---
title: "Compilador (nível 1) de aviso C4530 | Microsoft Docs"
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: adfa006e3b84517601237bbd844ac983115e74ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4530"></a>Compilador C4530 de aviso (nível 1)
Manipulador de exceção de C++ usado, mas semântica de liberação não estão habilitados. Especifique /EHsc  
  
 Tratamento de exceções C++ foi usado, mas [/EHsc](../../build/reference/eh-exception-handling-model.md) não foi selecionado.  
  
 Quando a opção de /EHsc não foi habilitada, um objeto com armazenamento automático no quadro, entre a função fazendo o throw e a função capturando throw, não será destruído. No entanto, um objeto com armazenamento automático criado em uma **tente** ou **catch** bloco será destruído.  
  
 O exemplo a seguir gera C4530:  
  
```  
// C4530.cpp  
// compile with: /W1  
int main() {  
   try{} catch(int*) {}   // C4530  
}  
```  
  
 Compile o exemplo com /EHsc para resolver o aviso.