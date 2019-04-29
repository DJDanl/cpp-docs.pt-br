---
title: Erro do compilador C2395
ms.date: 11/04/2016
f1_keywords:
- C2395
helpviewer_keywords:
- C2395
ms.assetid: 2d9e3b28-8c2c-4f41-a57f-61ef88fc2af0
ms.openlocfilehash: dd3bd922e2bfa61da2da87d368bb4b28237161f9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303644"
---
# <a name="compiler-error-c2395"></a>Erro do compilador C2395

' your_type::operator'op ': CLR ou WinRT operador não é válido. Pelo menos um parâmetro deve ser um destes tipos: ' T ', ' t %', ' t &', ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'

Um operador em um tempo de execução do Windows ou um tipo gerenciado não tinha pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.

O exemplo a seguir gera C2395 e mostra como corrigi-lo:

```
// C2395.cpp
// compile with: /clr /c
value struct V {
   static V operator *(int i, char c);   // C2395

   // OK
   static V operator *(V v, char c);
   // or
   static V operator *(int i, V& rv);
};
```