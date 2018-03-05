---
title: Valores de retorno (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 53583524-b337-4228-a9c6-c9bf516babe8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cdd02ab9c30e641ba7389923062f46dbbed534ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="return-values-c"></a>Valores de retorno (C++)
Um valor de retorno escalar que pode se ajustar em 64 bits é retornado por meio de RAX — isso inclui tipos de m64. Tipos escalares não incluindo floats, duplicatas e tipos de vetor, como [m128](../cpp/m128.md), [__m128i](../cpp/m128i.md), [__m128d](../cpp/m128d.md) XMM0 são retornados. O estado de bits não utilizados no valor retornado em RAX ou XMM0 é indefinido.  
  
 Tipos definidos pelo usuário podem ser retornados pelo valor de funções globais e funções de membro estático. A ser retornado pelo valor em RAX, tipos definidos pelo usuário devem ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits; Nenhum construtor definido pelo usuário, o destruidor ou o operador de atribuição de cópia; Nenhum membro de dados não estático particulares ou protegidos; Nenhum membro de dados não estático do tipo de referência; Não há classes base; Nenhuma função virtual; e nenhum membro de dados que também não atender a esses requisitos. (Isso é basicamente a definição de C + + 03 tipo POD. Como a definição foi alterado do 11 C++ padrão, não recomendamos o uso `std::is_pod` para este teste.) Caso contrário, o chamador assume a responsabilidade de alocação de memória e transmitindo um ponteiro para o valor de retorno como o primeiro argumento. Argumentos subsequentes são deslocados um argumento para a direita. O mesmo ponteiro deve ser retornado pelo receptor no RAX.  
  
 Estes exemplos mostram como parâmetros e valores de retorno são passados para funções com as declarações especificadas:  
  
## <a name="example-of-return-value-1---64-bit-result"></a>Exemplo de resultado do valor de retorno 1 de 64 bits  
  
```Output  
__int64 func1(int a, float b, int c, int d, int e);  
// Caller passes a in RCX, b in XMM1, c in R8, d in R9, e pushed on stack,  
// callee returns __int64 result in RAX.  
```  
  
## <a name="example-of-return-value-2---128-bit-result"></a>Exemplo de resultado de 2 de 128 bits do valor de retorno  
  
```Output  
__m128 func2(float a, double b, int c, __m64 d);   
// Caller passes a in XMM0, b in XMM1, c in R8, d in R9,   
// callee returns __m128 result in XMM0.  
```  
  
## <a name="example-of-return-value-3---user-type-result-by-pointer"></a>Exemplo de valor de retorno 3 – resultado do tipo de usuário pelo ponteiro  
  
```Output  
struct Struct1 {  
   int j, k, l;    // Struct1 exceeds 64 bits.   
};  
Struct1 func3(int a, double b, int c, float d);   
// Caller allocates memory for Struct1 returned and passes pointer in RCX,   
// a in RDX, b in XMM2, c in R9, d pushed on the stack;   
// callee returns pointer to Struct1 result in RAX.  
```  
  
## <a name="example-of-return-value-4---user-type-result-by-value"></a>Exemplo de valor de retorno 4 - resultado do tipo de usuário por valor  
  
```Output  
struct Struct2 {  
   int j, k;    // Struct2 fits in 64 bits, and meets requirements for return by value.  
};  
Struct2 func4(int a, double b, int c, float d);   
// Caller passes a in RCX, b in XMM1, c in R8, and d in XMM3;   
// callee returns Struct2 result by value in RAX.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)