---
title: Erro do compilador C2390 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2390
dev_langs:
- C++
helpviewer_keywords:
- C2390
ms.assetid: 06b749ee-d072-4db1-b229-715f2c0728b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5de5a9af8f8aa04219f0a7d61162336745fd4bfa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098206"
---
# <a name="compiler-error-c2390"></a>Erro do compilador C2390

'identifier': classe de armazenamento incorreta 'especificador'

A classe de armazenamento não é válida para o identificador de escopo global. A classe de armazenamento padrão é usada no lugar de classe inválida.

Possíveis resoluções:

- Se o identificador é uma função, declare-o com `extern` armazenamento.

- Se o identificador é um parâmetro formal ou uma variável local, declare-o com o armazenamento automático.

- Se o identificador é uma variável global, declare-o com nenhuma classe de armazenamento (armazenamento automático).

## <a name="example"></a>Exemplo

- O exemplo a seguir gera C2390:

```
// C2390.cpp
register int i;   // C2390

int main() {
   register int j;   // OK
}
```