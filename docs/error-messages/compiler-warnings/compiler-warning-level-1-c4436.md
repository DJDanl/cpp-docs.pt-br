---
title: Aviso do compilador (nível 1) C4436
ms.date: 11/04/2016
f1_keywords:
- C4436
helpviewer_keywords:
- C4436
ms.assetid: 2b54a1fc-c9c6-4cc9-90be-faa44fc715d5
ms.openlocfilehash: 6a15220cb02a48fb11936b69e5830412f1221108
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230669"
---
# <a name="compiler-warning-level-1-c4436"></a>Aviso do compilador (nível 1) C4436

dynamic_cast da base virtual ' class1 ' para ' class2 ' no construtor ou destruidor pode falhar com a compilação de objeto parcialmente construída com/vd2 ou definir ' class2 ' com #pragma vtordisp (2) em vigor

O compilador encontrou uma **`dynamic_cast`** operação com as seguintes características.

- A conversão é de um ponteiro de classe base para um ponteiro de classe derivada.

- A classe derivada herda virtualmente a classe base.

- A classe derivada não tem um `vtordisp` campo para a base virtual.

- A conversão é encontrada em um construtor ou destruidor da classe derivada, ou alguma classe que herda mais da classe derivada.

O aviso indica que o **`dynamic_cast`** pode não ser executado corretamente, se estiver operando em um objeto parcialmente construído.  Isso acontece se o construtor/destruidor derivado estiver operando em um subobjeto de um objeto derivado adicional.  Se a classe derivada nomeada no aviso nunca for mais derivada, o aviso poderá ser ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4436 e demonstra o problema de geração de código que ocorre no `vtordisp` campo ausente.

```cpp
// C4436.cpp
// To see the warning and runtime assert, compile with: /W1
// To eliminate the warning and assert, compile with: /W1 /vd2
//       or compile with: /W1 /DFIX
#include <cassert>

struct A
{
public:
    virtual ~A() {}
};

#if defined(FIX)
#pragma vtordisp(push, 2)
#endif
struct B : virtual A
{
    B()
    {
        A* a = static_cast<A*>(this);
        B* b = dynamic_cast<B*>(a);     // C4436
        assert(this == b);              // assert unless compiled with /vd2
    }
};
#if defined(FIX)
#pragma vtordisp(pop)
#endif

struct C : B
{
    int i;
};

int main()
{
    C c;
}
```

## <a name="see-also"></a>Confira também

[Operador de dynamic_cast](../../cpp/dynamic-cast-operator.md)<br/>
[vtordisp](../../preprocessor/vtordisp.md)<br/>
[Aviso do compilador (nível 4) C4437](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)
