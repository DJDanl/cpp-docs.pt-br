---
title: Aviso do compilador (níveis 1 e 4) C4112
ms.date: 11/04/2016
f1_keywords:
- C4112
helpviewer_keywords:
- C4112
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
ms.openlocfilehash: f614373e1b96de2c8167d7981c0a87a4e1c58435
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991236"
---
# <a name="compiler-warning-levels-1-and-4-c4112"></a>Aviso do compilador (níveis 1 e 4) C4112

\#linha requer um número inteiro entre 1 e número

A diretiva [#line](../../preprocessor/hash-line-directive-c-cpp.md) especifica um parâmetro inteiro que está fora do intervalo permitido.

Se o parâmetro especificado for menor que 1, o contador de linha será redefinido como 1. Se o parâmetro especificado for maior que o *número*, que é o limite definido pelo compilador, o contador de linha será inalterado. Este é um aviso de nível 1 em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso de nível 4 com o Microsoft Extensions ([/ze](../../build/reference/za-ze-disable-language-extensions.md)).

O exemplo a seguir gera C4112:

```cpp
// C4112.cpp
// compile with: /W4
#line 0   // C4112, value must be between 1 and number

int main() {
}
```
