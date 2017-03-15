---
title: "Compilador aviso (nível 4) C4437 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: dc07e350-20eb-474c-a7ad-f841ae7ec339
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 093522350ac996f6157a3e10e63271a0bada2ccc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4437"></a>Compilador C4437 de aviso (nível 4)
dynamic_cast da base virtual 'class1' para 'class2' pode falhar em alguns contextos compilação com /vd2 ou definir 'class2' #pragma vtordisp(2) em vigor  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O compilador encontrou um `dynamic_cast` operação com as seguintes características.  
  
-   É a conversão de um ponteiro de classe base para um ponteiro de classe derivada.  
  
-   Virtualmente, a classe derivada herda da classe base.  
  
-   A classe derivada não tem um `vtordisp` campo base virtual.  
  
-   A conversão não foi encontrada em um construtor ou destruidor da classe derivada ou uma classe que mais herda da classe derivada (caso contrário, aviso do compilador C4436 será emitido).  
  
 O aviso indica que o `dynamic_cast` pode não executar corretamente se estiver funcionando em um objeto parcialmente construído.  Essa situação ocorre quando a função é chamada de um construtor ou destruidor de uma classe que herda da classe derivada chamada no aviso.  Se a classe derivada é chamada no aviso nunca é ainda mais derivado, ou função não é chamada durante a construção de objetos ou destruição, o aviso pode ser ignorado.  
  
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
 [Operador dynamic_cast](../../cpp/dynamic-cast-operator.md)   
 [vtordisp](../../preprocessor/vtordisp.md)   
 [Compilador C4436 de aviso (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md)
