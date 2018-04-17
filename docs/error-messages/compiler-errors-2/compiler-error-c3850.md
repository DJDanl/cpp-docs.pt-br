---
title: C3850 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- C3850
dev_langs:
- C++
helpviewer_keywords:
- C3850
ms.assetid: 028f3a37-f3ad-4ebc-9168-3cdea47524d4
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f5c79f1ab90348ea234e006ae6838d5e80e46c3e
ms.sourcegitcommit: 770f6c4a57200aaa9e8ac6e08a3631a4b4bdca05
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/16/2018
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