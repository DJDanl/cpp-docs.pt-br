---
title: Aviso do compilador (nível 1) C4835
ms.date: 11/04/2016
f1_keywords:
- C4835
helpviewer_keywords:
- C4835
ms.assetid: d2e44c62-7b0e-4a45-943d-97903e27ed9d
ms.openlocfilehash: e59c8a7c9cdd9b892155a7d8ee8c8259324c2045
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052315"
---
# <a name="compiler-warning-level-1-c4835"></a>Aviso do compilador (nível 1) C4835

' Variable ': o inicializador para dados exportados não será executado até que o código gerenciado seja executado pela primeira vez no assembly do host

Ao acessar dados entre componentes gerenciados, é recomendável que você não use C++ mecanismos de importação e exportação nativos. Em vez disso, declare os membros de dados dentro de um tipo gerenciado e referencie os metadados com `#using` no cliente. Para obter mais informações, confira [Diretiva #using](../../preprocessor/hash-using-directive-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4835.

```cpp
// C4835.cpp
// compile with: /W1 /clr /LD
int f() { return 1; }
int n = 9;

__declspec(dllexport) int m = f();   // C4835
__declspec(dllexport) int *p = &n;   // C4835
```

## <a name="example"></a>Exemplo

O exemplo a seguir consome o componente criado no exemplo anterior, mostrando que o valor das variáveis não é o esperado.

```cpp
// C4835_b.cpp
// compile with: /clr C4835.lib
#include <stdio.h>
__declspec(dllimport) int m;
__declspec(dllimport) int *p;

int main() {
   printf("%d\n", m);
   printf("%d\n", p);
}
```

```Output
0
268456008
```