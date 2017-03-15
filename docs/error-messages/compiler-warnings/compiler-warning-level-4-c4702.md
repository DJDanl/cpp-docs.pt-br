---
title: "Compilador aviso (nível 4) C4702 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4702
dev_langs:
- C++
helpviewer_keywords:
- C4702
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9f10a279a57399f70e65287ba8bf4ecf21b7bbcc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4702"></a>Compilador C4702 de aviso (nível 4)
código inacessível  
  
 Esse aviso é o resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: código inacessível. Quando o compilador (back-end) detecta código inacessível, ele irá gerar C4702, um aviso de nível 4.  
  
 Para código que seja válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, remova o código inacessível ou garantir que todo o código fonte é acessível por um fluxo de execução.  
  
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
 Ao compilar com **/GX**, **/EHc**, **/EHsc**, ou **/EHac** e usando funções extern C, código pode ficar inacessível porque funções extern C são consideradas não throw, assim, o bloco catch não está acessível.  Se você achar que esse aviso não é válido porque uma função pode gerar, compilar com **/EHa** ou **/EHs**, dependendo da exceção gerada.  
  
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
