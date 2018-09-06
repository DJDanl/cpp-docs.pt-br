---
title: Erro do compilador C3850 | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3850
dev_langs:
- C++
helpviewer_keywords:
- C3850
ms.assetid: 028f3a37-f3ad-4ebc-9168-3cdea47524d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: daa4b6128672b47891c563acfd4399952a17e7e6
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894532"
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