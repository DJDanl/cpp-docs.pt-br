---
title: "Compilador aviso (nível 1) C4436 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: 2b54a1fc-c9c6-4cc9-90be-faa44fc715d5
caps.latest.revision: 2
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: cb4e56a7455a4b3f76578d335c8cfca5a7ca36eb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4436"></a>Compilador C4436 de aviso (nível 1)
dynamic_cast da base virtual 'class1' para 'class2' no construtor ou destruidor pode falhar com compilação de objeto parcialmente construído com /vd2 ou definir 'class2' #pragma vtordisp(2) em vigor  
  
 O compilador encontrou um `dynamic_cast` operação com as seguintes características.  
  
-   É a conversão de um ponteiro de classe base para um ponteiro de classe derivada.  
  
-   Virtualmente, a classe derivada herda da classe base.  
  
-   A classe derivada não tem um `vtordisp` campo base virtual.  
  
-   A conversão foi encontrada em um construtor ou destruidor da classe derivada ou uma classe que mais herda da classe derivada.  
  
 O aviso indica o `dynamic_cast` pode não executar corretamente, se ela estiver operando em um objeto parcialmente construído.  Isso acontece se o construtor/destruidor derivado estiver operando em um objeto de subsistema de algum objeto mais derivado.  Se a classe derivada chamada no aviso nunca é ainda mais derivado, o aviso pode ser ignorado.  
  
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
 [Compilador C4437 de aviso (nível 4)](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)
