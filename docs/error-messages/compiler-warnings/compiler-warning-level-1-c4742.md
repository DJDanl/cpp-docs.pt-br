---
title: Compilador aviso (nível 1) C4742 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4742
dev_langs:
- C++
helpviewer_keywords:
- C4742
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 622a1b1cd62024da58191ce1312c391dd39e0d28
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088586"
---
# <a name="compiler-warning-level-1-c4742"></a>Compilador aviso (nível 1) C4742

'var' possui alinhamento diferente em 'file1' e 'file2': número e número

Uma variável externa que foi referenciada ou definida em dois arquivos possui alinhamento diferente nesses arquivos. Esse aviso é emitido quando o compilador encontra que `__alignof` para a variável na *file1* difere `__alignof` para a variável na *arquivo2*. Isso pode ser causado por meio de tipos incompatíveis ao declarar a variável em arquivos diferentes, ou usando a correspondência não `#pragma pack` em arquivos diferentes.

Para resolver este aviso, use a mesma definição de tipo ou usar nomes diferentes para as variáveis.

Para obter mais informações, consulte [pack](../../preprocessor/pack.md) e [operador de alignof](../../cpp/alignof-operator.md).

## <a name="example"></a>Exemplo

Isso é o primeiro arquivo que define o tipo.

```
// C4742a.c
// compile with: /c
struct X {
   char x, y, z, w;
} global;
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4742.

```
// C4742b.c
// compile with: C4742a.c /W1 /GL
// C4742 expected
extern struct X {
   int a;
} global;

int main() {
   global.a = 0;
}
```