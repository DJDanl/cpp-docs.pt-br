---
title: "Aviso do compilador (n&#237;vel 1) C4436 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
ms.assetid: 2b54a1fc-c9c6-4cc9-90be-faa44fc715d5
caps.latest.revision: 2
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4436
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o dynamic\_cast de base virtual “class1” a “class2” no ou no construtor destruidor pode falhar com o objeto parcialmente construído compile com \/vd2 ou define “class2” com vtordisp de \#pragma \(2\) aplicado  
  
 O compilador encontrou uma operação de `dynamic_cast` com as seguintes características.  
  
-   A conversão for de um ponteiro da classe base para um ponteiro da classe derivada.  
  
-   A classe herda derivada a inclusão da classe base.  
  
-   A classe derivada não tiver um campo de `vtordisp` para a base virtual.  
  
-   A conversão for localizada em um construtor ou em um destruidor da classe derivada, ou em uma determinada classe que herda mais da classe derivada.  
  
 O aviso indicar que `dynamic_cast` não pode ser executado corretamente, se o estiver operando em um objeto parcialmente construído.  Isso acontecer se o construtor\/destruidor derivadas está operando em um novo objeto de qualquer objeto derivado adicional.  Se a classe derivada chamada no aviso nunca é uma coluna adicional, o aviso pode ser ignorado.  
  
## Exemplo  
 O exemplo C4436 gerencia e demonstra o problema de geração de código que ocorre do campo ausente de `vtordisp` .  
  
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
  
## Consulte também  
 [Operador dynamic\_cast](../../cpp/dynamic-cast-operator.md)   
 [vtordisp](../Topic/vtordisp.md)   
 [Aviso do compilador \(nível 4\) C4437](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)