---
title: Aviso do compilador (nível 4) C4702
ms.date: 11/04/2016
f1_keywords:
- C4702
helpviewer_keywords:
- C4702
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
ms.openlocfilehash: a2d1f6f4bdc20a35638274e2099c00428f4f6ddf
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684281"
---
# <a name="compiler-warning-level-4-c4702"></a>Aviso do compilador (nível 4) C4702

código inacessível

Esse aviso é o resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: código inacessível. Quando o compilador (back-end) detecta o código inacessível, ele gera C4702, um aviso de nível 4.

Para o código que é válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do Visual C++, remova o código inacessível ou garanta que todo o código-fonte possa ser acessado por algum fluxo de execução.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C4702.

```cpp
// C4702.cpp
// compile with: /W4
#include <stdio.h>

int main() {
   return 1;
   printf_s("I won't print.\n");   // C4702 unreachable
}
```

Ao compilar com **/GX**, **/EHc**, **/EHsc**ou **/EHac** e usar as funções do c externo, o código pode ficar inacessível porque as funções externas de c são consideradas não lançadas, portanto, o bloco catch não está acessível.  Se você sentir que esse aviso não é válido porque uma função pode gerar, compile com **/EHA** ou **o/EHS**, dependendo da exceção lançada.

Para obter mais informações, consulte [/eh (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.

O exemplo a seguir gera C4702.

```cpp
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
