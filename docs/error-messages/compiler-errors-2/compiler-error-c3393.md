---
title: Erro do compilador C3393
ms.date: 11/04/2016
f1_keywords:
- C3393
helpviewer_keywords:
- C3393
ms.assetid: d57f7c69-0a02-4fe3-9e45-bc62644fd77c
ms.openlocfilehash: 0f6952de20c27a811b85694ae13892eff9231f83
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757534"
---
# <a name="compiler-error-c3393"></a>Erro do compilador C3393

erro de sintaxe na cláusula de restrição: ' identifier ' não é um tipo

O identificador passado para uma restrição, que deve ser um tipo, não era um tipo.  Confira mais informações em [Restrições em parâmetros de tipo genérico (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3393:

```cpp
// C3393.cpp
// compile with: /clr /c
void MyInterface() {}
interface class MyInterface2 {};

generic<typename T>
where T : MyInterface   // C3393
// try the following line instead
// where T : MyInterface2
ref class R {};
```
