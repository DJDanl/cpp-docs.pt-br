---
title: Compilador (nível 1) de aviso C4739 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4739
dev_langs:
- C++
helpviewer_keywords:
- C4739
ms.assetid: 600873b3-7c85-4cd4-944e-cd8e01bfcbb0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c90acdbc8ab32522e8e7cfac079547caaf84398d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33281899"
---
# <a name="compiler-warning-level-1-c4739"></a>Compilador C4739 de aviso (nível 1)
referência à variável 'var' excede seu espaço de armazenamento  
  
 Um valor foi atribuído a uma variável, mas o valor é maior que o tamanho da variável. Memória será gravada além do local de memória da variável e perda de dados.  
  
 Para resolver este aviso, atribua apenas um valor a uma variável cujo tamanho pode acomodar o valor.  
  
 O exemplo a seguir gera C4739:  
  
```  
// C4739.cpp  
// compile with: /RTCs /Zi /W1 /c  
char *pc;  
int main() {  
   char c;  
   *(int *)&c = 1;   // C4739  
  
   // OK  
   *(char *)&c = 1;  
}  
```