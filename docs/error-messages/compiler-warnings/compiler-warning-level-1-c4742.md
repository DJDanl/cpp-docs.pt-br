---
title: Aviso do compilador (nível 1) C4742
ms.date: 11/04/2016
f1_keywords:
- C4742
helpviewer_keywords:
- C4742
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
ms.openlocfilehash: 11663a9b8672e2f91feb59e275181dbe645484e9
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051304"
---
# <a name="compiler-warning-level-1-c4742"></a>Aviso do compilador (nível 1) C4742

' var ' tem alinhamento diferente em ' arquivo1 ' e ' arquivo2 ': número e número

Uma variável externa que foi referenciada ou definida em dois arquivos tem alinhamento diferente nesses arquivos. Esse aviso é emitido quando o compilador descobre que `__alignof` para a variável em *arquivo1* difere de `__alignof` para a variável em *file2*. Isso pode ser causado pelo uso de tipos incompatíveis ao declarar a variável em arquivos diferentes ou pelo uso de `#pragma pack` não correspondentes em arquivos diferentes.

Para resolver esse aviso, use a mesma definição de tipo ou use nomes diferentes para as variáveis.

Para obter mais informações, consulte [pacote](../../preprocessor/pack.md) e [operador de __alignof](../../cpp/alignof-operator.md).

## <a name="example"></a>Exemplo

Esse é o primeiro arquivo que define o tipo.

```c
// C4742a.c
// compile with: /c
struct X {
   char x, y, z, w;
} global;
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4742.

```c
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