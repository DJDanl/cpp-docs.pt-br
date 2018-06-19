---
title: C3850 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: bb2068a283fc54a86b09f2af05b177f2151e940b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33268479"
---
# <a name="compiler-error-c3850"></a>C3850 de erro do compilador
'char': um-nome de caractere universal Especifica um caractere inválido  
  
 Caracteres representados como nomes de caractere universal devem representam pontos de código Unicode válidos no intervalo 0-10FFFF. Um nome de caractere universal não pode conter um valor no intervalo substituto Unicode, D800 DFFF ou um par substituto codificado. O compilador gera o substituto automaticamente do ponto de par de um código válido.  
  
 No código compilado como C, um nome de caractere universal não pode representar um caractere no intervalo 0000-009F, inclusive, com exceção das 0024 ('$'), 0040 (' @') e 0060 (' ').  
  
 No código compilado como C++, um nome de caractere universal pode usar qualquer ponto de código Unicode válido em uma cadeia de caracteres ou um literal de caractere. Fora de um literal, um nome de caractere universal não pode representar um caractere de controle no intervalos 001F 0000 ou 007F-009F, inclusive, ambos ou define um membro do caractere fonte básica.  Para obter mais informações, consulte [conjuntos de caracteres](../../cpp/character-sets.md).  
  
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