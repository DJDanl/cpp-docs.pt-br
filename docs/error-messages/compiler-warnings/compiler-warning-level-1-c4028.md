---
title: Compilador (nível 1) de aviso C4028 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4028
dev_langs:
- C++
helpviewer_keywords:
- C4028
ms.assetid: c3e8b70b-e870-416c-a285-bba5f71dbfc6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c96abd732a00e5b37b48be8c3053cbfbb8c37c37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33274353"
---
# <a name="compiler-warning-level-1-c4028"></a>Compilador C4028 de aviso (nível 1)
'número' diferente da declaração de parâmetro formal  
  
 O tipo do parâmetro formal não concorda com o parâmetro correspondente na declaração. O tipo de declaração original é usado.  
  
 Este aviso só é válido para o código-fonte C.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4028.  
  
```  
// C4028.c  
// compile with: /W1 /Za  
void f(int , ...);  
void f(int i, int j) {}   // C4028  
  
void g(int , int);  
void g(int i, int j) {}   // OK  
  
int main() {}  
```