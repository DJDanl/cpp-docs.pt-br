---
title: novtable
ms.date: 11/04/2016
f1_keywords:
- novtable_cpp
helpviewer_keywords:
- novtable __declspec keyword
- __declspec keyword [C++], novtable
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
ms.openlocfilehash: d101e73f2f8d476c50b1b80b8daa7994151d43af
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177827"
---
# <a name="novtable"></a>novtable

**Seção específica da Microsoft**

Este é um **__declspec** atributo estendido.

Essa forma de **__declspec** pode ser aplicada a qualquer declaração de classe, mas só deve ser aplicada a classes de interface pura, ou seja, classes que nunca serão instanciadas por conta própria. O **__declspec** interrompe o compilador de gerar código para inicializar o vfptr no (s) Construtor (es) e no destruidor da classe. Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá. O uso dessa forma de **__declspec** pode resultar em uma redução significativa no tamanho do código.

Se você tentar criar uma instância de uma classe marcada com **novtable** e, em seguida, acessar um membro de classe, você receberá uma violação de acesso (AV).

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

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
