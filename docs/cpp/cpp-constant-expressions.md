---
title: Expressões de constante C++
ms.date: 11/04/2016
helpviewer_keywords:
- constant expressions, syntax
- constant expressions
- expressions [C++], constant
ms.assetid: b07245a5-4c21-4589-b503-e6ffd631996f
ms.openlocfilehash: 32d14650450d8047a5bc0e6cf7bb06788c9b3d81
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221751"
---
# <a name="c-constant-expressions"></a>Expressões de constante C++

Um valor *constante* é aquele que não é alterado. O C++ fornece duas palavras-chave para permitir que você expresse a intenção de que um objeto não se destina a ser modificado e para impor essa intenção.

O C++ requer expressões constantes — expressões que são avaliadas como uma constante — para declarações de:

- Limites de matriz

- Seletores em instruções case

- Especificação de comprimento do campo de bits

- Inicializadores de enumeração

Os únicos operandos que são válidos em expressões constantes são:

- Literais

- Constantes de enumeração

- Valores declarados como const que são inicializados com expressões constantes

- **`sizeof`** expressões

As constantes não integral devem ser convertidas (explicitamente ou implicitamente) em tipos integrais para serem válidas em uma expressão constante. Portanto, o código a seguir é válido:

```cpp
const double Size = 11.0;
char chArray[(int)Size];
```

Conversões explícitas para tipos integrais são expressões de constantes legais; todos os outros tipos e tipos derivados são ilegais, exceto quando usados como operandos para o **`sizeof`** operador.

O operador vírgula e os operadores de atribuição não podem ser usados em expressões constantes.

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
