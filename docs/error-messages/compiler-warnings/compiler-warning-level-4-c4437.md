---
title: Aviso do compilador (nível 4) C4437
ms.date: 11/04/2016
f1_keywords:
- C4437
helpviewer_keywords:
- C4437
ms.assetid: dc07e350-20eb-474c-a7ad-f841ae7ec339
ms.openlocfilehash: 6cd50d5c4d79b82c135ab4e84ec390dee9e906ef
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810649"
---
# <a name="compiler-warning-level-4-c4437"></a>Aviso do compilador (nível 4) C4437

dynamic_cast da base virtual ' class1 ' para ' class2 ' poderia falhar em alguns contextos compilados com/vd2 ou definir ' class2 ' com #pragma vtordisp (2) em vigor

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O compilador encontrou uma operação de `dynamic_cast` com as seguintes características.

- A conversão é de um ponteiro de classe base para um ponteiro de classe derivada.

- A classe derivada herda virtualmente a classe base.

- A classe derivada não tem um campo `vtordisp` para a base virtual.

- A conversão não é encontrada em um construtor ou destruidor da classe derivada, ou alguma classe que herda mais da classe derivada (caso contrário, o aviso do compilador C4436 será emitido).

O aviso indica que a `dynamic_cast` pode não ser executada corretamente se estiver operando em um objeto parcialmente construído.  Essa situação ocorre quando a função delimitadora é chamada de um construtor ou destruidor de uma classe que herda a classe derivada nomeada no aviso.  Se a classe derivada nomeada no aviso nunca for mais derivada ou se a função de circunscrição não for chamada durante a construção ou destruição do objeto, o aviso poderá ser ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4437 e demonstra o problema de geração de código que ocorre no campo `vtordisp` ausente.

```cpp
// C4437.cpp
// To see the warning and runtime assert, compile with: /W4
// To eliminate the warning and assert, compile with: /W4 /vd2
//       or compile with: /W4 /DFIX
#pragma warning(default : 4437)
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
        func();
    }

    void func()
    {
        A* a = static_cast<A*>(this);
        B* b = dynamic_cast<B*>(a);     // C4437
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

## <a name="see-also"></a>Consulte também

[Operador dynamic_cast](../../cpp/dynamic-cast-operator.md)<br/>
[vtordisp](../../preprocessor/vtordisp.md)<br/>
[Aviso do compilador (nível 1) C4436](../../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md)