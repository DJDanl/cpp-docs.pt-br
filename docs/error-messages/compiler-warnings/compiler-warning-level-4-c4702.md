---
title: "Compilador (nível 4) de aviso C4702 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4702
dev_langs: C++
helpviewer_keywords: C4702
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9ef7420f3699363d33d195e2455ab9fddf88de40
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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