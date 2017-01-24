---
title: "Classe mersenne_twister_engine | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "random/std::tr1::mersenne_twister_engine"
  - "tr1.mersenne_twister_engine"
  - "std.tr1.mersenne_twister_engine"
  - "std::tr1::mersenne_twister_engine"
  - "tr1::mersenne_twister_engine"
  - "mersenne_twister_engine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe mersenne_twister_engine"
ms.assetid: 7ee968fa-a1cc-450f-890f-7305de062685
caps.latest.revision: 23
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe mersenne_twister_engine
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma sequência aleatória de alta qualidade de inteiros com base no algoritmo Mersenne twister.  
  
## Sintaxe  
  
```  
template<class UIntType,   
    size_t W, size_t N, size_t M, size_t R,  
    UIntType A, size_t U, UIntType D, size_t S,  
    UIntType B, size_t T, UIntType C, size_t L, UIntType F>  
class mersenne_twister_engine;  
```  
  
#### Parâmetros  
 `UIntType`  
 O tipo de resultado inteiro sem sinal. Para os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
 `W`  
 **Tamanho da palavra**. Tamanho de cada palavra, em bits, da sequência de estado.**Pré\-condição**: `2u < W ≤ numeric_limits<UIntType>::digits`  
  
 `N`  
 **Tamanho do estado**. O número de elementos \(valores\) na sequência de estado.  
  
 `M`  
 **Tamanho do deslocamento**. O número de elementos a serem ignorados a cada mudança.**Pré\-condição**: `0 < M ≤ N`  
  
 `R`  
 **De máscara de bits**.**Pré\-condição**: `R ≤ W`  
  
 `A`  
 **Máscara XOR**.**Pré\-condição**: `A ≤ (1u<<W) - 1u`  
  
 `U`, `S`, `T`, `L`  
 **Parâmetros de deslocamento Tempering**. Usado como valores de deslocamento durante a codificação \(deformação\). Pré\-requisito: `U,S,T,L ≤ W`  
  
 `D`, `B`, `C`  
 **Os parâmetros da máscara de bits de Tempering**. Usados como valores de máscara de bits durante a codificação \(deformação\). Pré\-requisito: `D,B,C ≤ (1u<<W) - 1u`  
  
 `F`  
 **Multiplicador de inicialização**. Usado para ajudar com a inicialização da sequência. Pré\-requisito: `F ≤ (1u<<W) - 1u`  
  
## Membros  
  
||||  
|-|-|-|  
|`mersenne_twister_engine::mersenne_twister_engine`|`mersenne_twister_engine::min`|`mersenne_twister_engine::discard`|  
|`mersenne_twister_engine::operator()`|`mersenne_twister_engine::max`|`mersenne_twister_engine::seed`|  
  
 `default_seed` é um membro constante, definido como `5489u`, usado como o valor de parâmetro padrão para `mersenne_twister_engine::seed` e construtor de valor único.  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 Essa classe de modelo descreve um mecanismo de números aleatórios, retornando valores no intervalo fechado \[`0`, `2`<sup>W</sup> \- `1`\]. Ele mantém um valor inteiro grande com `W * (N - 1) + R` bits. Ele extrai `W` bits em vez deste valor grande, e quando ele usou todos os bits, ele muda o valor alto mudando e mistura os bits para que ele tenha um novo conjunto de bits para extrair. O estado do mecanismo é o último `N``W`\-bit valores usados se `operator()` foi chamado pelo menos `N` vezes, caso contrário, o `M``W`\-bit de valores que foram usadas e o último `N - M` valores de semente.  
  
 O gerador muda o valor grande usando um registro de deslocamento de comentários generalizados definido pelos valores de deslocamento `N` e `M`, um valor de mudança `R`, e uma máscara XOR condicional `A`. Além disso, os bits de registro de deslocamento bruto são codificados \(deformados\) de acordo com uma matriz de deformação de bits definida pelos valores `U`, `D`, `S`, `B`, `T`, `C`, e `L`.  
  
 O argumento de modelo `UIntType` deve ser grande o suficiente para manter valores até `2`<sup>W</sup> \- `1`. Os valores dos argumentos de modelo devem atender aos seguintes requisitos: `2u < W, 0 < M, M ≤ N, R ≤ W, U ≤ W, S ≤ W, T ≤ W, L ≤ W, W ≤ numeric_limits<UIntType>::digits, A ≤ (1u<<W) - 1u, B ≤ (1u<<W) - 1u, C ≤ (1u<<W) - 1u, D ≤ (1u<<W) - 1u, and F ≤ (1u<<W) - 1u`.  
  
 Embora seja possível construir um gerador do mecanismo diretamente, recomenda\-se que você usar um desses typedefs predefinidos:  
  
 `mt19937`: 32 bits mecanismo Mersenne twister de \(Matsumoto e Nishimura, 1998\).  
  
```  
typedef mersenne_twister_engine<unsigned int, 32, 624, 397,   
    31, 0x9908b0df,   
    11, 0xffffffff,   
    7, 0x9d2c5680,   
    15, 0xefc60000,   
    18, 1812433253> mt19937;  
```  
  
 `mt19937_64`: 64\-bit mecanismo Mersenne twister de \(Matsumoto e Nishimura, 2000\).  
  
```  
typedef mersenne_twister_engine<unsigned long long, 64, 312, 156,   
    31, 0xb5026f5aa96619e9ULL,   
    29, 0x5555555555555555ULL,   
    17, 0x71d67fffeda60000ULL,   
    37, 0xfff7eee000000000ULL,   
    43, 6364136223846793005ULL> mt19937_64;  
```  
  
 Para obter informações detalhadas sobre o algoritmo Mersenne twister, consulte o artigo da Wikipedia [Mersenne twister](http://go.microsoft.com/fwlink/?LinkId=402356).  
  
## Exemplo  
 Para obter um exemplo de código, consulte [\<random\>](../standard-library/random.md).  
  
## Requisitos  
 **Cabeçalho:** \< random \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)