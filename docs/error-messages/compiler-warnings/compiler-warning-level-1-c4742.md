---
title: Aviso do compilador (nível 1) C4742
ms.date: 07/22/2020
f1_keywords:
- C4742
helpviewer_keywords:
- C4742
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
ms.openlocfilehash: e6ecd082a9f6d690414761d11d3a0adf101f87c2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233230"
---
# <a name="compiler-warning-level-1-c4742"></a>Aviso do compilador (nível 1) C4742

> '*Variable*' tem alinhamento diferente em '*arquivo1*' e '*arquivo2*': *Número1* e *núm2*

Uma variável externa que foi referenciada ou definida em dois arquivos tem alinhamento diferente nesses arquivos.

## <a name="remarks"></a>Comentários

Esse aviso é emitido quando o compilador descobre que **`alignof`** a variável em *arquivo1* difere de **`alignof`** para a variável em *arquivo2*. Isso pode ser causado pelo uso de tipos incompatíveis ao declarar a variável em arquivos diferentes ou usando não correspondência `#pragma pack` em arquivos diferentes.

Para resolver esse aviso, use a mesma definição de tipo ou use nomes diferentes para as variáveis.

Para obter mais informações, [`pack`](../../preprocessor/pack.md) consulte [ `alignof` operador](../../cpp/alignof-operator.md)and.

## <a name="example"></a>Exemplo

Esse é o primeiro arquivo que define o tipo.

```c
// C4742a.c
// compile with: /c
struct X {
   char x, y, z, w;
} global;
```

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
