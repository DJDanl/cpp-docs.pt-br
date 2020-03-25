---
title: Erro do compilador C2383
ms.date: 11/04/2016
f1_keywords:
- C2383
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
ms.openlocfilehash: 2aa922ebeadb374a7eac73a0f452376472b00984
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80206022"
---
# <a name="compiler-error-c2383"></a>Erro do compilador C2383

'*Symbol*': argumentos padrão não são permitidos neste símbolo

O C++ compilador não permite argumentos padrão em ponteiros para funções.

Esse código foi aceito pelo compilador da C++ Microsoft em versões anteriores ao Visual Studio 2005, mas agora apresenta um erro. Para o código que funciona em todas as versões C++do Visual, não atribua um valor padrão a um argumento de ponteiro para função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2383 e mostra uma possível solução:

```cpp
// C2383.cpp
// compile with: /c
void (*pf)(int = 0);   // C2383
void (*pf)(int);   // OK
```
