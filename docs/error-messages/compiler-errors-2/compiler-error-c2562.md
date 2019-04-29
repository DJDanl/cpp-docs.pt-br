---
title: Erro do compilador C2562
ms.date: 11/04/2016
f1_keywords:
- C2562
helpviewer_keywords:
- C2562
ms.assetid: 2c41e511-9952-4b98-9976-6b1523613e1b
ms.openlocfilehash: c665c4ed82fefaf0ee724defb8c205f86fc06dd0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62228874"
---
# <a name="compiler-error-c2562"></a>Erro do compilador C2562

'identifier': função 'void' retornando um valor

A função é declarada como `void` , mas retorna um valor.

Esse erro pode ser causado por um protótipo de função incorreta.

Esse erro pode ser corrigido se você especificar o tipo de retorno na declaração da função.

O exemplo a seguir gera C2562:

```
// C2562.cpp
// compile with: /c
void testfunc() {
   int i;
   return i;   // C2562 delete the return to resolve
}
```