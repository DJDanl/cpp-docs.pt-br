---
title: novtable
ms.date: 11/04/2016
f1_keywords:
- novtable_cpp
helpviewer_keywords:
- novtable __declspec keyword
- __declspec keyword [C++], novtable
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
ms.openlocfilehash: 9dcca6ec07a19d53da238020805299b652cbf919
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630237"
---
# <a name="novtable"></a>novtable

## <a name="microsoft-specific"></a>Específico da Microsoft

Esse é um **declspec** atributo estendido.

Essa forma de **declspec** podem ser aplicadas a qualquer declaração de classe, mas só deve ser aplicado a classes puras da interface, ou seja, classes que nunca serão instanciadas por conta própria. O **declspec** interrompe o compilador gere código para inicializar vfptr nos construtores e destruidores da classe. Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá. Usando essa forma de **declspec** pode resultar em uma redução significativa no tamanho do código.

Se você tentar instanciar uma classe marcada com **novtable** e, em seguida, acessar um membro de classe, você receberá uma violação de acesso (AV).

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)