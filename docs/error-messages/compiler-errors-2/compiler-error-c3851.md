---
title: Erro do compilador C3851
ms.date: 09/05/2018
f1_keywords:
- C3851
helpviewer_keywords:
- C3851
ms.assetid: da30c21c-33aa-4439-8fb3-2f5021ea4985
ms.openlocfilehash: 97d9ef1eeeffa0e5a63d2c8ae2428a3fad0ff238
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165561"
---
# <a name="compiler-error-c3851"></a>Erro do compilador C3851

> '*Char*': um nome de caractere universal não pode designar um caractere no conjunto de caracteres básico

## <a name="remarks"></a>Comentários

No código compilado como C++, você não pode usar um nome de caractere universal que representa um caractere no conjunto de caracteres de origem básico fora de uma cadeia de caracteres ou um literal de caractere. Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md). No código compilado como C, você não pode usar um nome de caractere universal para caracteres no intervalo 0x20-0x7f, inclusive, exceto para 0x24 (' $ '), 0x40 ('\@') ou 0x60 ('\`').

## <a name="example"></a>Exemplo

Os exemplos a seguir geram C3851 e mostram como corrigi-lo:

```cpp
// C3851.cpp
int main()
{
   int test1_\u0041 = 0;   // C3851, \u0041 = 'A' in basic character set
   int test2_A = 0;        // OK
}
```
