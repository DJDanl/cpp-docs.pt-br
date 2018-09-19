---
title: Erro do compilador C2513 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2513
dev_langs:
- C++
helpviewer_keywords:
- C2513
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 82df537e49ca17140d70977486314f43a072022d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045426"
---
# <a name="compiler-error-c2513"></a>Erro do compilador C2513

'type': nenhuma variável declarada antes de '='

O especificador de tipo aparece na declaração sem nenhum identificador de variável.

O exemplo a seguir gera C2513:

```
// C2513.cpp
int main() {
   int = 9;   // C2513
   int i = 9;   // OK
}
```

Esse erro também pode ser gerado como resultado de um trabalho de conformidade do compilador feito para o Visual Studio .NET 2003: inicialização de um typedef não é mais permitido. A inicialização de um typedef não é permitida pelo padrão e agora gera um erro do compilador.

```
// C2513b.cpp
// compile with: /c
typedef struct S {
   int m_i;
} S = { 1 };   // C2513
// try the following line instead
// } S;
```

Uma alternativa seria excluir `typedef` definir uma variável com a lista de inicializador agregado, mas isso não é recomendado porque ele será criar uma variável com o mesmo nome que o tipo e ocultar o nome do tipo.