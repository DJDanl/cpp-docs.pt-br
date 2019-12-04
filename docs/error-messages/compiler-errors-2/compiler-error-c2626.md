---
title: Erro do compilador C2626
ms.date: 11/04/2016
f1_keywords:
- C2626
helpviewer_keywords:
- C2626
ms.assetid: 4c283ad0-251b-4571-bc18-468b9836746f
ms.openlocfilehash: 339d48265bdc1f68ea4e18fadfde48fca956dd1f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754739"
---
# <a name="compiler-error-c2626"></a>Erro do compilador C2626

' identifier ': um membro de dados privado ou protegido não é permitido em um struct ou Union anônima

Um membro de uma struct ou União anônima deve ter acesso público.

O exemplo a seguir gera C2626:

```cpp
// C2626.cpp
int main() {
   union {
   protected:
      int j;     // C2626, j is protected
   private:
      int k;     // C2626, k is private
   };
}
```

Para corrigir esse problema, remova todas as marcas privadas ou protegidas:

```cpp
// C2626b.cpp
int main() {
   union {
   public:
      int i;   // OK, i is public
   };
}
```
