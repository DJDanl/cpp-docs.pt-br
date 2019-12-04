---
title: Erro do compilador C3382
ms.date: 11/04/2016
f1_keywords:
- C3382
helpviewer_keywords:
- C3382
ms.assetid: a7603abd-ac4e-4ae6-a02b-3bdc6d1908a6
ms.openlocfilehash: 419577ddd5b5d7d2d21a91f500070cb190c72117
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760459"
---
# <a name="compiler-error-c3382"></a>Erro do compilador C3382

Não há suporte para ' sizeof ' com/CLR: safe

O arquivo de saída de uma compilação **/CLR: safe** é um arquivo que é verificado com segurança, e sizeof não tem suporte porque o valor de retorno do operador sizeof é size_t, cujo tamanho varia dependendo do sistema operacional.

Para obter mais informações, consulte

- [Operador sizeof](../../cpp/sizeof-operator.md)

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3382.

```cpp
// C3382.cpp
// compile with: /clr:safe
int main() {
   sizeof( char );   // C3382
}
```
