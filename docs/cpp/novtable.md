---
title: novtable
ms.date: 11/04/2016
f1_keywords:
- novtable_cpp
helpviewer_keywords:
- novtable __declspec keyword
- __declspec keyword [C++], novtable
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
ms.openlocfilehash: ccf544608bcba83af17702767562ef93d775b5a9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227251"
---
# <a name="novtable"></a>novtable

**Específico da Microsoft**

Este é um **`__declspec`** atributo estendido.

Essa forma de **`__declspec`** pode ser aplicada a qualquer declaração de classe, mas só deve ser aplicada a classes de interface pura, ou seja, classes que nunca serão instanciadas por conta própria. O **`__declspec`** interrompe o compilador de gerar código para inicializar o vfptr no (s) Construtor (es) e no destruidor da classe. Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá. O uso dessa forma de **`__declspec`** pode resultar em uma redução significativa no tamanho do código.

Se você tentar criar uma instância de uma classe marcada com **`novtable`** e, em seguida, acessar um membro de classe, receberá uma violação de acesso (AV).

## <a name="example"></a>Exemplo

```cpp
// novtable.cpp
#include <stdio.h>

struct __declspec(novtable) X {
   virtual void mf();
};

struct Y : public X {
   void mf() {
      printf_s("In Y\n");
   }
};

int main() {
   // X *pX = new X();
   // pX->mf();   // Causes a runtime access violation.

   Y *pY = new Y();
   pY->mf();
}
```

```Output
In Y
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[`__declspec`](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
