---
title: Compilador aviso (nível 1) C4436 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: 2b54a1fc-c9c6-4cc9-90be-faa44fc715d5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2484b5420347f49a74d8eb3cdf65a8221741cc63
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076496"
---
# <a name="compiler-warning-level-1-c4436"></a>Compilador aviso (nível 1) C4436

dynamic_cast da base virtual 'class1' para 'class2' no construtor ou destruidor poderia falhar com o objeto parcialmente construído Compile com/vd2 ou defina 'class2' #pragma vtordisp(2) em vigor

O compilador encontrou uma `dynamic_cast` operação com as seguintes características.

- A conversão é de um ponteiro de classe base para um ponteiro de classe derivada.

- Virtualmente, a classe derivada herda a classe base.

- A classe derivada não tem um `vtordisp` campo para a base virtual.

- A conversão for encontrada em um construtor ou destruidor da classe derivada, ou alguma classe que ainda mais herda da classe derivada.

O aviso indica a `dynamic_cast` pode não executar corretamente, se ele está operando em um objeto parcialmente construído.  Isso acontece se o construtor/destruidor derivado está operando em um Subobjeto do algum objeto mais derivado.  Se a classe derivada chamada no aviso nunca é ainda mais derivado, o aviso pode ser ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4436 e demonstra o problema de geração de código que surge da ausentes `vtordisp` campo.

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

## <a name="see-also"></a>Consulte também

[Operador dynamic_cast](../../cpp/dynamic-cast-operator.md)<br/>
[vtordisp](../../preprocessor/vtordisp.md)<br/>
[Aviso do compilador (nível 4) C4437](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)