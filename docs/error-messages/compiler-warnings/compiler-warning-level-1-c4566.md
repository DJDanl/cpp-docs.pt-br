---
title: Compilador aviso (nível 1) C4566
ms.date: 11/04/2016
f1_keywords:
- C4566
helpviewer_keywords:
- C4566
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
ms.openlocfilehash: c864feb2478e9f99ad6e4c0087dcef72b55de601
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397257"
---
# <a name="compiler-warning-level-1-c4566"></a>Compilador aviso (nível 1) C4566

caractere representado pela nome de caractere universal 'char' não pode ser representado na página de código atual (página)

Não, todos os caracteres Unicode podem ser representados na página de código ANSI atual.

Cadeias de caracteres estreitas (caracteres de um byte) são convertidas em caracteres multibyte, enquanto não são de cadeias de caracteres largas (dois bytes de caracteres).

O exemplo a seguir gera C4566:

```
// C4566.cpp
// compile with: /W1
int main() {
   char c1 = '\u03a0';   // C4566
   char c2 = '\u0642';   // C4566

   wchar_t c3 = L'\u03a0';   // OK
   wchar_t c4 = L'\u0642';   // OK
}
```