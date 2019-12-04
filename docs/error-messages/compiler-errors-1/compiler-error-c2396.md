---
title: Erro do compilador C2396
ms.date: 11/04/2016
f1_keywords:
- C2396
helpviewer_keywords:
- C2396
ms.assetid: 1b515ef6-7af4-400f-b4ed-564313ea15f6
ms.openlocfilehash: 5020732ce5186ee1c6e9d2ea13f452fe9988bdfa
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744830"
---
# <a name="compiler-error-c2396"></a>Erro do compilador C2396

' your_type:: operator'type ' ': conversão definida pelo usuário do CLR ou WinRT functionnot válida. É necessário converter ou converter para: ' t ^ ', ' t ^% ', ' t ^ & ', em que T = ' your_type '

Uma função de conversão em um Windows Runtime ou tipo gerenciado não tinha pelo menos um parâmetro cujo tipo é o mesmo que o tipo que contém a função de conversão.

O exemplo a seguir gera C2396 e mostra como corrigi-lo:

```cpp
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
