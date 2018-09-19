---
title: Erro do compilador C3851 | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3851
dev_langs:
- C++
helpviewer_keywords:
- C3851
ms.assetid: da30c21c-33aa-4439-8fb3-2f5021ea4985
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e6d0f6da9c3295aa6a8fad4bf5dfd8e725424739
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032460"
---
# <a name="compiler-error-c3851"></a>Erro do compilador C3851

> '*char*': um-nome de caractere universal não pode designar um caractere no conjunto de caracteres básicas

## <a name="remarks"></a>Comentários

No código compilado c++, você não pode usar um nome de caractere universal que representa um caractere no conjunto de caracteres de origem básicos fora de uma cadeia de caracteres ou literal de caractere. Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md). No código compilado como C, você não pode usar um nome de caractere universal para caracteres no intervalo 0x20 – 0x7f, inclusive, exceto para 0x24 ('$'), 0x40 ('\@'), ou 0x60 ('\`').

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