---
title: Erro do compilador C3850
ms.date: 09/05/2018
f1_keywords:
- C3850
helpviewer_keywords:
- C3850
ms.assetid: 028f3a37-f3ad-4ebc-9168-3cdea47524d4
ms.openlocfilehash: 9cd0428726f92c7347b162f74b46035f99cc2d3c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50572660"
---
# <a name="compiler-error-c3850"></a>Erro do compilador C3850

> '*char*': um-nome de caractere universal Especifica um caractere inválido

## <a name="remarks"></a>Comentários

Caracteres representados como nomes de caracteres universais devem representar pontos de código Unicode válidos no intervalo 0-10FFFF. Um nome de caractere universal não pode conter um valor no intervalo substituto Unicode, DFFF u+D800 ou um par de substitutos codificados. O compilador gera o substituto automaticamente, o ponto de par de um código válido.

No código compilado como C, um nome de caractere universal não pode representar um caractere no intervalo 0000-009F, inclusive, com exceção da 0024 ('$'), 0040 ('\@') e 0060 (' ').

No código compilado c++, um nome de caractere universal pode usar qualquer ponto de código Unicode válido em uma cadeia de caracteres ou literal de caractere. Fora de um literal, um nome de caractere universal não pode representar um caractere de controle no intervalos 0000 001F ou 007F-009F, ambos incluídos, ou definir um membro do caractere de origem básicos.  Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3850 e mostra como corrigi-lo:

```cpp
// C3850.cpp
int main() {
   int \u0019 = 0;   // C3850, not in allowed range for an identifier
   const wchar_t * wstr_bad  = L"\UD840DC8A"; // C3850, UCN is surrogate pair
   const wchar_t * wstr_good = L"\U0002008A"; // Okay, UCN is valid code point
}
```