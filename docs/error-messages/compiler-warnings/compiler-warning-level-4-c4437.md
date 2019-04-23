---
title: Compilador aviso (nível 4) C4437
ms.date: 11/04/2016
ms.assetid: dc07e350-20eb-474c-a7ad-f841ae7ec339
ms.openlocfilehash: 9ff52ae6d10f7d4ba429bbf3457a2a6b969998d4
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037812"
---
# <a name="compiler-warning-level-4-c4437"></a>Compilador aviso (nível 4) C4437

dynamic_cast da base virtual 'class1' para 'class2' pode falhar em alguns contextos de compilação com/vd2 ou defina 'class2' #pragma vtordisp(2) em vigor

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O compilador encontrou uma `dynamic_cast` operação com as seguintes características.

- A conversão é de um ponteiro de classe base para um ponteiro de classe derivada.

- Virtualmente, a classe derivada herda a classe base.

- A classe derivada não tem um `vtordisp` campo para a base virtual.

- A conversão não for encontrada em um construtor ou destruidor da classe derivada, ou alguma classe que ainda mais herda da classe derivada (caso contrário, aviso do compilador C4436 será emitido).

O aviso indica que o `dynamic_cast` pode não executar corretamente se estiver funcionando em um objeto parcialmente construído.  Essa situação ocorre quando a função é chamada de um construtor ou destruidor de uma classe que herda da classe derivada que é chamada no aviso.  Se a classe derivada que é chamada no aviso nunca é ainda mais derivado, ou função não é chamada durante a construção de objeto ou destruição, o aviso pode ser ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4437 e demonstra o problema de geração de código que surge da ausentes `vtordisp` campo.

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