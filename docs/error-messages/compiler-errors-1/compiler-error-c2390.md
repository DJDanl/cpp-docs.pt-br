---
title: Erro do compilador C2390
ms.date: 11/04/2016
f1_keywords:
- C2390
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
ms.openlocfilehash: 515e2e151d27dd2eb84fc1dc71b9197b36b14cbb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745038"
---
# <a name="compiler-error-c2390"></a>Erro do compilador C2390

' identifier ': classe de armazenamento incorreta ' especificador '

A classe de armazenamento não é válida para o identificador de escopo global. A classe de armazenamento padrão é usada no lugar da classe inválida.

Possíveis resoluções:

- Se o identificador for uma função, declare-o com `extern` armazenamento.

- Se o identificador for um parâmetro formal ou uma variável local, declare-o com o armazenamento automático.

- Se o identificador for uma variável global, declare-o sem nenhuma classe de armazenamento (armazenamento automático).

## <a name="example"></a>Exemplo

- O exemplo a seguir gera C2390:

```cpp
// C2390.cpp
register int i;   // C2390

int main() {
   register int j;   // OK
}
```
