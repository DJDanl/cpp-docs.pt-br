---
title: Compilador aviso (nível 4) C4702
ms.date: 11/04/2016
f1_keywords:
- C4702
helpviewer_keywords:
- C4702
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
ms.openlocfilehash: 96ae3a0742db5e3a5006f031ce62beb281c38ccd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607227"
---
# <a name="compiler-warning-level-4-c4702"></a>Compilador aviso (nível 4) C4702

Código inacessível

Esse aviso é o resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: código inacessível. Quando o compilador (back-end) detecta código inacessível, ele irá gerar C4702, um aviso de nível 4.

Para o código que é válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, remova o código inacessível ou garantir que todo código-fonte é acessível por algum fluxo de execução.

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

Ao compilar com **/GX**, **/EHc**, **/EHsc**, ou **/EHac** e usando funções extern do C, código pode se tornar inacessível porque extern C funções são consideradas para não gerar, portanto, o bloco catch não pode ser acessado.  Se você achar que esse aviso não é válido porque uma função pode gerar, compilar com **/EHa** ou **/EHs**, dependendo da exceção gerada.

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