---
title: Erro do compilador C3087
ms.date: 11/04/2016
f1_keywords:
- C3087
helpviewer_keywords:
- C3087
ms.assetid: 4f5bdd52-a853-4f02-b160-6868e9190b9d
ms.openlocfilehash: 6b9ae71ebfbcfcd5936a2fc3ca666aa51e59bfb5
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751411"
---
# <a name="compiler-error-c3087"></a>Erro do compilador C3087

' named_argument ': a chamada de ' attribute ' já inicializa este membro

Um argumento nomeado foi especificado no mesmo bloco de atributo que um argumento sem nome para o mesmo valor. Especifique apenas um argumento nomeado ou sem nome.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3087.

```cpp
// C3087.cpp
// compile with: /c
[idl_quote("quote1", text="quote2")];   // C3087
[idl_quote(text="quote3")];   // OK
[idl_quote("quote4")];   // OK
```
