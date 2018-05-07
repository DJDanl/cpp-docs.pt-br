---
title: Compilador (nível 4) de aviso C4702 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4702
dev_langs:
- C++
helpviewer_keywords:
- C4702
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29c2d6b0328fd8dd4cd6f9a226253036b62d03ab
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4702"></a>Compilador C4702 de aviso (nível 4)
Código inacessível  
  
 Esse aviso é o resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: código inacessível. Quando o compilador (back-end) detecta código inacessível, ele irá gerar C4702, um aviso de nível 4.  
  
 Para o código que é válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, remova o código inacessível ou garantir que todo o código fonte é acessível por alguns fluxo de execução.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4702.  
  
```  
// C4702.cpp  
// compile with: /W4  
#include <stdio.h>  
  
int main() {  
   return 1;  
   printf_s("I won't print.\n");   // C4702 unreachable  
}  
```  
  
## <a name="example"></a>Exemplo  
 Ao compilar com **/GX**, **/EHc**, **/EHsc**, ou **/EHac** e usando funções extern do C, código pode se tornar inacessível porque extern do C funções são consideradas não throw, assim, o bloco catch não está acessível.  Se você acha que esse aviso não é válido porque uma função pode gerar, compilar com **/EHa** ou **/EHs**, dependendo da exceção é gerada.  
  
 Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.  
  
 O exemplo a seguir gera C4702.  
  
```  
// C4702b.cpp  
// compile with: /W4 /EHsc  
#include <iostream>  
  
using namespace std;  
extern "C" __declspec(dllexport) void Function2(){}  
  
int main() {  
   try {  
      Function2();  
   }  
   catch (...) {  
      cout << "Exp: Function2!" << endl;   // C4702  
   }  
}  
```