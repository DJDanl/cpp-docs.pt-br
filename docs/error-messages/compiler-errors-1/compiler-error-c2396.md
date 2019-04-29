---
title: Erro do compilador C2396
ms.date: 11/04/2016
f1_keywords:
- C2396
helpviewer_keywords:
- C2396
ms.assetid: 1b515ef6-7af4-400f-b4ed-564313ea15f6
ms.openlocfilehash: d320f78937fc60910bbed4a5b1b89841ea674fb7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303509"
---
# <a name="compiler-error-c2396"></a>Erro do compilador C2396

' your_type::operator'type ': CLR ou WinRT conversão definida pelo usuário functionnot válido. Deve converter de ou converter para: ' T ^', ' t ^ %', ' t ^ &', onde T = 'your_type'

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