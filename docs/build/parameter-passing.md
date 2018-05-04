---
title: Passagem de parâmetro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e838ee5f-c2fe-40b0-9a23-8023c949c820
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ec0c5b6fe00430c8b08fefdd8781b677004085e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="parameter-passing"></a>Passagem de parâmetro
Os argumentos de inteiro de quatro primeiro são passados em registros. Valores inteiros são passados (na ordem da esquerda para a direita) em RCX, RDX, R8 e R9. Argumentos de 5 e superior são passados na pilha. Todos os argumentos forem justificado à direita nos registros. Isso é feito para o receptor pode ignorar os bits superiores do registro se necessário e pode acessar apenas a parte do Registro necessários.  
  
 Argumentos de ponto flutuantes e precisão dupla são passados em XMM0 - XMM3 (até 4) com o slot de inteiro (RCX, RDX, R8 e R9) que normalmente seria usado para esse slot cardeal que está sendo ignorado (veja o exemplo) e vice-versa.  
  
 [m128](../cpp/m128.md) cadeias de caracteres, matrizes e tipos nunca são transmitidas por valor imediato, mas em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Estruturas/uniões de tamanho 8, 16, 32 ou 64 bits e o m64 são passados como se fossem inteiros do mesmo tamanho. Estruturas/uniões diferente esses tamanhos são passados como um ponteiro para a memória alocada pelo chamador. Para esses tipos de agregação passado como um ponteiro (incluindo \__m128), a memória alocada pelo chamador para temporária será alinhada de 16 bytes.  
  
 Funções intrínsecas que não pode alocar espaço de pilha e não chamam outras funções podem usar outros registros volátil para passar argumentos adicionais de registro porque há uma associação forte entre o compilador e a implementação da função intrínseca. Esta é uma oportunidade adicional para melhorar o desempenho.  
  
 O receptor tem a responsabilidade de despejar os parâmetros de registro em seu espaço de sombra se necessário.  
  
 A tabela a seguir resume como os parâmetros são passados:  
  
|Tipo de parâmetro|Como passado|  
|--------------------|----------------|  
|Ponto flutuante|Primeiro 4 parâmetros - XMM0 por meio de XMM3. Outros passado na pilha.|  
|Inteiro|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outros passado na pilha.|  
|Agregações (8, 16, 32 ou 64 bits) e m64|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outros passado na pilha.|  
|Agregações (outro)|Pelo ponteiro. Primeiro 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|  
|__m128|Pelo ponteiro. Primeiro 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|  
  
## <a name="example-of-argument-passing-1---all-integers"></a>Exemplo 1 - todos os números inteiros de transmissão de argumentos  
  
```  
func1(int a, int b, int c, int d, int e);    
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack  
```  
  
## <a name="example-of-argument-passing-2---all-floats"></a>Exemplo 2 - todas as flutuações de transmissão de argumentos  
  
```  
func2(float a, double b, float c, double d, float e);    
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack  
```  
  
## <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de 3 - ints misto e flutuações de transmissão de argumentos  
  
```  
func3(int a, double b, int c, float d);    
// a in RCX, b in XMM1, c in R8, d in XMM3  
```  
  
## <a name="example-of-argument-passing-4--m64-m128-and-aggregates"></a>Exemplo de argumento passando 4- m64, \__m128 e agregações  
  
```  
func4(__m64 a, _m128 b, struct c, float d);  
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3  
```  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)