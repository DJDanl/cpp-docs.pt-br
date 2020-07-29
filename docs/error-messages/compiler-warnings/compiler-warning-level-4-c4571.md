---
title: Aviso do compilador (nível 4) C4571
ms.date: 11/04/2016
f1_keywords:
- C4571
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
ms.openlocfilehash: 4fe99e12c5d2dfb725e1e4aa0ac2fb0b1ccb4f28
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219879"
---
# <a name="compiler-warning-level-4-c4571"></a>Aviso do compilador (nível 4) C4571

Informação: a semântica catch (...) foi alterada desde Visual C++ 7,1; as exceções estruturadas (SEH) não são mais detectadas

C4571 é gerado para cada bloco catch (...) durante a compilação com **o/EHS**.

Ao compilar com **o/EHS**, um bloco catch (...) não capturará uma exceção estruturada (dividir por zero, ponteiro nulo, por exemplo); um bloco catch (...) irá capturar apenas exceções explicitamente geradas, C++.  Para saber mais, veja [Tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).

Esse aviso está desativado por padrão.  Ative este aviso para garantir que quando você compilar com **o/EHS** seus blocos catch (...) não pretendem capturar exceções estruturadas.  Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Você pode resolver o C4571 de uma das seguintes maneiras:

- Compile com **/EHA** se você ainda quiser que seus blocos catch (...) detectem exceções estruturadas.

- Não habilite C4571 se não quiser que os blocos catch (...) detectem exceções estruturadas, mas você ainda deseja usar blocos catch (...).  Você ainda pode capturar exceções estruturadas usando as palavras-chave de manipulação de exceção estruturada (**__try**, **`__except`** e **`__finally`** ).  Mas lembre-se de que os destruidores **o/EHS** compilados só serão chamados quando uma exceção de C++ for lançada, não quando ocorrer uma exceção SEH.

- Substitua o bloco catch (...) por blocos catch para exceções C++ específicas e, opcionalmente, adicione manipulação de exceção estruturada em volta da manipulação de exceção do C++ (**__try**, **`__except`** e **`__finally`** ).  Consulte [manipulação de exceção estruturada (C/C++)](../../cpp/structured-exception-handling-c-cpp.md) para obter mais informações.

Consulte [/eh (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4571.

```cpp
// C4571.cpp
// compile with: /EHs /W4 /c
#pragma warning(default : 4571)
int main() {
   try {
      int i = 0, j = 1;
      j /= i;   // this will throw a SE (divide by zero)
   }
   catch(...) {}   // C4571 warning
}
```
