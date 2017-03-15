---
title: C2712 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2712
dev_langs:
- C++
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
caps.latest.revision: 15
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
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 89b7d0ad3c7e175db1525c2f3fb8407240ce943c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2712"></a>C2712 de erro do compilador
não é possível usar try em funções que exigem o desenrolamento de objeto  
  
 C2712 de erro pode ocorrer se você usar [/EHsc](../../build/reference/eh-exception-handling-model.md), e uma função com tratamento de exceções estruturada também tem objetos que exigem desenrolamento (destruição).  
  
 Possíveis soluções:  
  
-   Mova o código que requer SEH para outra função  
  
-   Reescreva funções que utilizam o SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use o SEH em construtores ou destruidores  
  
-   Compilar sem /EHsc  
  
 C2712 de erro também pode ocorrer se você chamar um método declarado usando o [Event](../../cpp/event.md) palavra-chave. Como os eventos podem ser usados em um ambiente multithreaded, o compilador gera código que impede a manipulação do objeto de evento subjacente e, em seguida, coloca o código gerado um SEH [instrução try-finally](../../cpp/try-finally-statement.md). Consequentemente, C2712 erro ocorrerá se você chamar o método de evento e passa por valor de um argumento cujo tipo tem um destruidor. Nesse caso, uma solução é passar o argumento como uma referência constante.  
  
## <a name="example"></a>Exemplo  
 C2712 também pode ocorrer se você compilar com **/clr: puro** e declarar uma matriz estática de ponteiros para funções em um `__try` bloco. Um membro estático exige que o compilador para usar inicialização dinâmica em **/clr: puro**, que significa que o tratamento de exceções C++. No entanto, o tratamento de exceções C++ não é permitido em um `__try` bloco.  
  
 O **/clr: puro** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015.  
  
 O exemplo a seguir gera C2712 e mostra como corrigi-lo.  
  
```  
// C2712.cpp  
// compile with: /clr:pure /c  
struct S1 {  
   static int smf();  
   void fnc();  
};  
  
void S1::fnc() {  
   __try {  
      static int (*array_1[])() = {smf,};   // C2712  
  
      // OK  
      static int (*array_2[2])();  
      array_2[0] = smf;  
    }  
    __except(0) {}  
}  
```
