---
title: Erro do compilador C3382
ms.date: 11/04/2016
f1_keywords:
- C3382
helpviewer_keywords:
- C3382
ms.assetid: a7603abd-ac4e-4ae6-a02b-3bdc6d1908a6
ms.openlocfilehash: c262ea963ae739fbb76211aae2622e98d5a9b6f7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462745"
---
# <a name="compiler-error-c3382"></a>Erro do compilador C3382

'sizeof' não é suportado com /CLR: safe

O arquivo de saída de um **/CLR: safe** compilação é um arquivo que é comprovadamente fortemente tipado e sizeof não tem suporte porque o valor de retorno do operador sizeof é size_t, cujo tamanho varia dependendo do sistema operacional.

Para obter mais informações, consulte

- [Operador sizeof](../../cpp/sizeof-operator.md)

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3382.

```
// C3382.cpp
// compile with: /clr:safe
int main() {
   sizeof( char );   // C3382
}
```