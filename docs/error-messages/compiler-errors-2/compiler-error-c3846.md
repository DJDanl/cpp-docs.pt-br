---
title: Erro do compilador C3846
ms.date: 11/04/2016
f1_keywords:
- C3846
helpviewer_keywords:
- C3846
ms.assetid: c470f8a5-106b-4efb-b8dc-e1319e04130f
ms.openlocfilehash: a4c51ccfc724cf8309044812b287677f0f1a2ff0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754895"
---
# <a name="compiler-error-c3846"></a>Erro do compilador C3846

' Symbol ': não é possível importar o símbolo de ' Assembly2 ': como ' Symbol ' já foi importado de outro assembly ' Assembly1 '

Um símbolo não pôde ser importado de um assembly referenciado porque foi importado anteriormente de um assembly referenciado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3846:

```cpp
// C3846a.cpp
// compile with: /LD /clr
public ref struct G
{
};
```

E, em seguida, compile:

```cpp
// C3846b.cpp
// compile with: /clr
#using "c3846a.dll"
#using "c3846a.obj"   // C3846

int main()
{
}
```
