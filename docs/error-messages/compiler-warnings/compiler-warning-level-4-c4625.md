---
title: Compilador aviso (nível 4) C4625
ms.date: 11/04/2016
f1_keywords:
- C4625
helpviewer_keywords:
- C4625
ms.assetid: 4cc99e50-846c-4784-97da-48b977067851
ms.openlocfilehash: edcb43bf11c073e6ce721ba999fd99d28a8df15d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62220488"
---
# <a name="compiler-warning-level-4-c4625"></a>Compilador aviso (nível 4) C4625

'derived class': construtor de cópia foi implicitamente definido como excluído porque um construtor de cópia de classe base está inacessível ou foi excluído

Um construtor de cópia foi excluído ou não está acessível em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de copiar um objeto desse tipo fará com que um erro do compilador.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4625 e mostra como corrigi-lo.

```
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