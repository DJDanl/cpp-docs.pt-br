---
title: "Valores de retorno (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 53583524-b337-4228-a9c6-c9bf516babe8
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Valores de retorno (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um valor de retorno escalar que se encaixa em 64 bits é retornado por RAX — isso inclui tipos de m64.  Tipos não escalares incluindo floats, duplicatas e tipos de vetor, como [\_\_m128](../Topic/__m128.md), [\_\_m128i](../Topic/__m128i.md), [\_\_m128d](../cpp/m128d.md) são retornados em XMM0.  O estado de bits não utilizados no valor retornado em RAX ou XMM0 é indefinido.  
  
 Tipos definidos pelo usuário podem ser retornados pelo valor de funções globais e funções de membro estático.  A serem retornadas pelo valor em RAX, tipos definidos pelo usuário devem ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits; Nenhum construtor definido pelo usuário, o destruidor ou o operador de atribuição de cópia; Não há membros de dados de não estático particular ou protegido; Nenhum membro de dados não estático do tipo de referência; Nenhuma classe base; Nenhuma função virtual; e há membros de dados que também não atender a esses requisitos.  \(Isso é essencialmente a definição de C\+\+ 03 tipo POD.  Como a definição foi alterada no C\+\+ 11 standard, não recomendamos usar `std::is_pod` para esse teste.\) Caso contrário, o chamador assume a responsabilidade de alocação de memória e transmitindo um ponteiro para o valor de retorno como o primeiro argumento.  Os argumentos subsequentes são deslocados um argumento para a direita.  O mesmo ponteiro deve ser retornado pelo receptor em RAX.  
  
 Estes exemplos mostram como parâmetros e valores de retorno são passados para as funções com as declarações especificadas:  
  
## Exemplo de resultado do valor de retorno 1 – 64 bits  
  **Int64 func1 \(int um float b, c int, int d, int e\);**  
**Chamador passa uma em RCX, b em XMM1, c em R8, d em R9, e empurrado na pilha,**  
**receptor retorna o resultado de Int64 em RAX.**   
## Exemplo de resultado do valor de retorno 2 – 128 bits  
  **m128 func2 \(float a, b duplo, int c, d m64\);**   
**Chamador passa uma em XMM0, b em XMM1, c em R8, d em R9,**   
**receptor retorna o resultado de m128 em XMM0.**   
## Exemplo de valor de retorno 3 – resultado do tipo de usuário pelo ponteiro  
  **struct Struct1 {**  
 **int j, k, l;    Struct1 exceder 64 bits.  };**  
**Func3 Struct1 \(int um duplo b, c int, float d\);**   
**Chamador aloca memória para Struct1 retornado e passa o ponteiro em RCX,**   
**um em RDX, b em XMM2, c em R9, d empurrado na pilha;**   
**receptor retorna um ponteiro ao resultado Struct1 em RAX.**    
## Exemplo de valor de retorno 4 – resultado do tipo de usuário por valor  
  **struct {Struct2**  
 **int j, k;    Struct2 se encaixa em 64 bits e atende aos requisitos de retorno do valor.  };**  
**Struct2 func4 \(int um duplo b, c int, float d\);**   
**Chamador passa uma em RCX, b em XMM1, c em R8 e d em XMM3;**   
**receptor retorna resultados Struct2 pelo valor em RAX.**    
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)