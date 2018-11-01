---
title: Erro do compilador C2396
ms.date: 11/04/2016
f1_keywords:
- C2396
helpviewer_keywords:
- C2396
ms.assetid: 1b515ef6-7af4-400f-b4ed-564313ea15f6
ms.openlocfilehash: d320f78937fc60910bbed4a5b1b89841ea674fb7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438072"
---
# <a name="compiler-error-c2396"></a>Erro do compilador C2396

' your_type::operator'type ': CLR ou WinRT functionnot de conversão definida pelo usuário válido. Deve converter de ou converter em: ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'

Uma função de conversão em um tempo de execução do Windows ou um tipo gerenciado não tinha pelo menos um parâmetro cujo tipo é o mesmo que o tipo que contém a função de conversão.

O exemplo a seguir gera C2396 e mostra como corrigi-lo:

```
// C2396.cpp
// compile with: /clr /c

ref struct Y {
   static operator int(char c);   // C2396

   // OK
   static operator int(Y^ hY);
   // or
   static operator Y^(char c);
};
```