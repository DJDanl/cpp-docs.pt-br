---
title: Erro do compilador C2753
ms.date: 11/04/2016
f1_keywords:
- C2753
helpviewer_keywords:
- C2753
ms.assetid: 92bfeeac-524a-4a8e-9a4f-fb8269055826
ms.openlocfilehash: ea2901c998ac1a44ad142779e7ce48bfffff66c2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202130"
---
# <a name="compiler-error-c2753"></a>Erro do compilador C2753

'*Template*': a especialização parcial não pode corresponder à lista de argumentos para o modelo primário

Se a lista de argumentos de modelo corresponder à lista de parâmetros, o compilador a tratará como o mesmo modelo. Não é permitido definir o mesmo modelo duas vezes.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2753 e mostra uma maneira de corrigi-lo:

```cpp
// C2753.cpp
// compile with: cl /c C2753.cpp
template<class T>
struct A {};

template<class T>
struct A<T> {};   // C2753
// try the following line instead
// struct A<int> {};

template<class T, class U, class V, class W, class X>
struct B {};
```
