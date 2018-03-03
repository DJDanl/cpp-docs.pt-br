---
title: C2712 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2712
dev_langs:
- C++
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ee098890bac40c0c376c7623578c4e95e551a75b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2712"></a>C2712 de erro do compilador
não é possível usar try em funções que exigem a liberação de objeto  
  
 C2712 de erro pode ocorrer se você usar [/EHsc](../../build/reference/eh-exception-handling-model.md), e uma função com tratamento de exceções estruturado também tiver objetos que exigem o desenrolamento (destruição).  
  
 Soluções possíveis:  
  
-   Mova o código que requer SEH para outra função  
  
-   Reescreva funções que usam SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use SEH em construtores ou destrutores  
  
-   Compilar sem /EHsc  
  
 C2712 erro também poderá ocorrer se você chamar um método declarado usando a [Event](../../cpp/event.md) palavra-chave. Como o evento pode ser usado em um ambiente multithreaded, o compilador gera o código que impede a manipulação do objeto de evento subjacente e, em seguida, inclui o código gerado em um SEH [instrução try-finally](../../cpp/try-finally-statement.md). Consequentemente, o erro C2712 ocorrerá se você chamar o método de evento e passa por valor de um argumento cujo tipo tenha um destruidor. Nesse caso, uma solução é passar o argumento como uma referência constante.  
  
## <a name="example"></a>Exemplo  
 C2712 também pode ocorrer se você compilar com **/clr: pure** e declarar uma matriz estática de ponteiros para funções em um `__try` bloco. Um membro estático requer que o compilador para usar a inicialização dinâmica em **/clr: pure**, que implica que o tratamento de exceções C++. No entanto, o tratamento de exceções C++ não é permitido em um `__try` bloco.  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
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