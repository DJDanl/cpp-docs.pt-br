---
title: Compilador (nível 1) de aviso C4436 | Microsoft Docs
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
ms.openlocfilehash: a1da06a329a9c0bdfcff6877ce69c8e3672619bb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33281636"
---
# <a name="compiler-warning-level-1-c4436"></a>Compilador C4436 de aviso (nível 1)
dynamic_cast da base virtual 'class1' para class2 no construtor ou destruidor poderia falhar com o objeto parcialmente construído Compile com /vd2 ou defina class2 com vtordisp (2) #pragma em vigor  
  
 O compilador encontrou um `dynamic_cast` operação com as seguintes características.  
  
-   A conversão é de um ponteiro de classe base para um ponteiro de classe derivada.  
  
-   A classe derivada praticamente herda da classe base.  
  
-   A classe derivada não tem um `vtordisp` campo para a base virtual.  
  
-   A conversão é encontrada em um construtor ou destruidor da classe derivada ou qualquer classe que mais herda da classe derivada.  
  
 O aviso indica que o `dynamic_cast` pode não executar corretamente, se ele estiver funcionando em um objeto parcialmente construído.  Isso acontece se o construtor/destruidor derivado está operando em um objeto de subsistema de algum objeto mais derivado.  Se a classe derivada chamada no aviso nunca seja mais derivado, o aviso pode ser ignorado.  
  
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
 [Operador dynamic_cast](../../cpp/dynamic-cast-operator.md)   
 [vtordisp](../../preprocessor/vtordisp.md)   
 [Aviso do compilador (nível 4) C4437](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)