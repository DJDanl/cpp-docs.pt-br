---
title: Erro do compilador C3850
ms.date: 09/05/2018
f1_keywords:
- C3850
helpviewer_keywords:
- C3850
ms.assetid: 028f3a37-f3ad-4ebc-9168-3cdea47524d4
ms.openlocfilehash: 5de7994e8bf46105e94271ab29bf9e27f1da3e76
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165555"
---
# <a name="compiler-error-c3850"></a>Erro do compilador C3850

> '*Char*': um nome de caractere universal especifica um caractere inválido

## <a name="remarks"></a>Comentários

Os caracteres representados como nomes de caracteres universais devem representar pontos de código Unicode válidos no intervalo de 0 a 10FFFF. Um nome de caractere universal não pode conter um valor no intervalo substituto de Unicode, D800-DFFF ou um par substituto codificado. O compilador gera automaticamente o par substituto a partir de um ponto de código válido.

No código compilado como C, um nome de caractere universal não pode representar um caractere no intervalo 0000-009F, inclusive, com as exceções de 0024 (' $ '), 0040 ('\@') e 0060 (' ' ').

No código compilado como C++, um nome de caractere universal pode usar qualquer ponto de código Unicode válido em uma cadeia de caracteres ou um literal de caractere. Fora de um literal, um nome de caractere universal não pode representar um caractere de controle nos intervalos 0000-001F ou 007F-009F, ambos incluídos ou um membro do conjunto de caracteres de origem básico.  Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md).

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
