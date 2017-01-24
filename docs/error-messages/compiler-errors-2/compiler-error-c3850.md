---
title: "C3850 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3850"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3850"
ms.assetid: 028f3a37-f3ad-4ebc-9168-3cdea47524d4
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3850 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'char': nome universal\-caracteres Especifica um caractere inválido  
  
 Caracteres representados como nomes de caracteres universais devem representar os pontos de código Unicode válidos no intervalo 0\-10FFFF. Um nome de caracteres universais não pode conter um valor no intervalo substituto Unicode, D800 DFFF ou um par substituto codificado. O compilador gera o substituto par de um código válido aponte automaticamente.  
  
 No código compilado como C, um nome de caractere universais pode não representar um caractere no intervalo 0000\-009F, inclusive, com exceção das 0024 \('$'\), 0040 \(' @'\) e 0060 \(' '\).  
  
 No código compilado c\+\+, um nome de caracteres universais pode usar qualquer ponto de código Unicode válido em uma cadeia de caracteres ou literal de caractere. Fora de um literal, um nome de caractere universais pode não representar um caractere de controle no intervalos 0000\-001F ou 007F\-009F, inclusive, ambos ou definir um membro do caractere fonte básica.  Para obter mais informações, consulte [Conjuntos de caracteres](../../cpp/character-sets2.md).  
  
## Exemplo  
 O exemplo a seguir gera C3850 e mostra como corrigi\-lo:  
  
```cpp  
// C3850.cpp  
int main() {  
   int \u0019 = 0;   // C3850, not in allowed range for an identifier  
   const wchar_t * wstr_bad  = L"\UD840DC8A"; // C3850, UCN is surrogate pair  
   const wchar_t * wstr_good = L"\U0002008A"; // Okay, UCN is valid code point  
}  
```