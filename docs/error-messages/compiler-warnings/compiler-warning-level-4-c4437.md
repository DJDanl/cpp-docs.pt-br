---
title: "Aviso do compilador (n&#237;vel 4) C4437 | Microsoft Docs"
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
ms.assetid: dc07e350-20eb-474c-a7ad-f841ae7ec339
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4437
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o dynamic\_cast de base virtual “class1” a “class2” poderia falhar em alguns contextos compile com \/vd2 ou define “class2” com vtordisp de \#pragma \(2\) aplicado  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.  
  
 O compilador encontrou uma operação de `dynamic_cast` com as seguintes características.  
  
-   A conversão for de um ponteiro da classe base para um ponteiro da classe derivada.  
  
-   A classe herda derivada a inclusão da classe base.  
  
-   A classe derivada não tiver um campo de `vtordisp` para a base virtual.  
  
-   A conversão não é encontrada em um construtor ou em um destruidor da classe derivada, ou em uma determinada classe que herda mais da classe derivada \(caso contrário, o compilador que C4436 aviso será emitido\).  
  
 O aviso indicar que `dynamic_cast` não pode ser executado corretamente se está operando em um objeto parcialmente construído.  Essa situação acontece quando a função é chamada incluindo de um construtor ou de um destruidor de uma classe que herde da classe derivada denominada no prompt do.  Se a classe derivada que é denominada no aviso nunca é uma coluna adicional, ou a função inclusive não é chamada durante a criação ou a destruição do objeto, o aviso pode ser ignorado.  
  
## Exemplo  
 O exemplo C4437 gerencia e demonstra o problema de geração de código que ocorre do campo ausente de `vtordisp` .  
  
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
  
## Consulte também  
 [Operador dynamic\_cast](../../cpp/dynamic-cast-operator.md)   
 [vtordisp](../Topic/vtordisp.md)   
 [Aviso do compilador \(nível 1\) C4436](../../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md)