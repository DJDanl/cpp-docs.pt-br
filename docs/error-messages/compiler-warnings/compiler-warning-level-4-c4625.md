---
title: Aviso do compilador (nível 4) C4625
ms.date: 11/04/2016
f1_keywords:
- C4625
helpviewer_keywords:
- C4625
ms.assetid: 4cc99e50-846c-4784-97da-48b977067851
ms.openlocfilehash: d98e295a9a48da16b58202bc172e112b5c0287d9
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990716"
---
# <a name="compiler-warning-level-4-c4625"></a>Aviso do compilador (nível 4) C4625

' classe derivada ': o construtor de cópia foi implicitamente definido como excluído porque um construtor de cópia de classe base é inacessível ou excluído

Um construtor de cópia foi excluído ou não está acessível em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de copiar um objeto desse tipo causará um erro do compilador.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4625 e mostra como corrigi-lo.

```cpp
// C4625.cpp
// compile with: /W4 /c
#pragma warning(default : 4625)

struct A {
   A() {}

private:
   A(const A&) {}
};

struct C : private virtual A {};
struct B :  C {};   // C4625 no copy constructor

struct D : A {};
struct E :  D {};   // OK
```
