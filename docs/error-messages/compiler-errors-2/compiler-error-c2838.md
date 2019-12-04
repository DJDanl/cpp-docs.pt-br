---
title: Erro do compilador C2838
ms.date: 11/04/2016
f1_keywords:
- C2838
helpviewer_keywords:
- C2838
ms.assetid: 176b2ad6-7a84-4019-b97e-328866054457
ms.openlocfilehash: 168f45a8cca8591d4780d056403de70440d25bec
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757833"
---
# <a name="compiler-error-c2838"></a>Erro do compilador C2838

' member ': nome qualificado inválido em declaração de membro

Uma classe, estrutura ou União usa um nome totalmente qualificado para redeclarar um membro de outra classe, estrutura ou União.

O exemplo a seguir gera C2838:

```cpp
// C2838.cpp
// compile with: /c
class Bellini {
public:
    void Norma();
};

class Bottesini {
   Bellini::Norma();  // C2838
};
```
