---
title: "Passagem de par&#226;metro | Microsoft Docs"
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
ms.assetid: e838ee5f-c2fe-40b0-9a23-8023c949c820
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Passagem de par&#226;metro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os primeiros quatro argumentos inteiros são passados em registros.  Os valores inteiros são passados \(na ordem esquerda para a direita\) em RCX, em RDX, em R8, e em R9.  Os argumentos e cinco mais alto são passados na pilha.  Todos os argumentos box são justificados os registros.  Isso é feito para que o receptor pode ignorar os bits superior do registro se necessário e pode acessar somente a parte do registro necessário.  
  
 Os argumentos e de ponto flutuante de precisão dupla são passados em XMM0 – XMM3 até \(4\) com o encaixe de inteiro \(RCX, RDX, R8, e R9\) que seria normalmente usado para o slot cardinal que está sendo ignorado \(consulte o exemplo\) e vice\-versa.  
  
 os tipos , matrizes e as cadeias de caracteres de[\_\_m128](../Topic/__m128.md) nunca são passados pelo valor imediato mas um ponteiro é passado em vez na memória atribuída pelo chamador.  Estruturas\/uniões de \_\_m64 de tamanho 8, 16, 32, ou 64 bits e é passado como se fosse inteiros do mesmo tamanho.  Estruturas\/uniões diferentes desses tamanhos é passado como um ponteiro para a memória alocada pelo chamador.  Para esses tipos agregados passados como um ponteiro \(incluindo \_\_m128\), a memória temporária chamador\- atribuída será o byte 16 alinhado.  
  
 As funções intrínsecas que não usa o espaço de pilha e não chamam outras funções podem usar outros registros temporários para passar argumentos adicionais do registro porque há uma associação apertado entre o compilador e a implementação de função intrínseca.  Esta é uma oportunidade adicional para melhorar o desempenho.  
  
 O receptor tem a responsabilidade de despejar os parâmetros do registro no espaço de sombra se necessário.  
  
 A tabela a seguir resume como os parâmetros são passados:  
  
|Tipo de parâmetro|Como passado|  
|-----------------------|------------------|  
|Ponto flutuante|Primeiros 4 – parâmetros XMM0 com XMM3.  Outro passados na pilha.|  
|Integer|Primeiros 4 – parâmetros RCX, RDX, R8, R9.  Outro passados na pilha.|  
|Bit das agregações \(8, 16, 32 ou 64\), e o \_\_m64|Primeiros 4 – parâmetros RCX, RDX, R8, R9.  Outro passados na pilha.|  
|Agregados \(outro\)|O ponteiro.  Primeiros 4 parâmetros passados como ponteiros em RCX, em RDX, em R8, e em R9|  
|\_\_m128|O ponteiro.  Primeiros 4 parâmetros passados como ponteiros em RCX, em RDX, em R8, e em R9|  
  
## Exemplo do argumento que passa 1 – todos os números inteiros  
  
```  
func1(int a, int b, int c, int d, int e);    
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack  
```  
  
## Exemplo do argumento que passa 2 – tudo flutua  
  
```  
func2(float a, double b, float c, double d, float e);    
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack  
```  
  
## Exemplo do argumento que passa 3 – ints e flutuadores mistos  
  
```  
func3(int a, double b, int c, float d);    
// a in RCX, b in XMM1, c in R8, d in XMM3  
```  
  
## Exemplo do argumento que passa 4 – \_\_m64, \_\_m128, e agregados  
  
```  
func4(__m64 a, _m128 b, struct c, float d);  
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3  
```  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)