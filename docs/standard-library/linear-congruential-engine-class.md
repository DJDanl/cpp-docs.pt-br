---
title: "Classe linear_congruential_engine | Microsoft Docs"
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
  - "std.tr1.linear_congruential_engine"
  - "random/std::tr1::linear_congruential_engine"
  - "linear_congruential_engine"
  - "std::tr1::linear_congruential_engine"
  - "tr1.linear_congruential_engine"
  - "tr1::linear_congruential_engine"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe linear_congruential_engine"
ms.assetid: 30e00ca6-1933-4701-9561-54f3e810a5a1
caps.latest.revision: 21
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe linear_congruential_engine
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gera uma sequência aleatória pelo algoritmo Congruente linear.  
  
## Sintaxe  
  
```  
template<class UIntType, UIntType A, UIntType C, UIntType M>  
class linear_congruential_engine{  
public:  
    // types  
    typedef UIntType result_type;  
  
    // engine characteristics  
    static constexpr result_type multiplier = a;  
    static constexpr result_type increment = c;  
    static constexpr result_type modulus = m;  
    static constexpr result_type min() { return c == 0u ? 1u: 0u; }  
    static constexpr result_type max() { return m - 1u; }  
    static constexpr result_type default_seed = 1u;  
  
    // constructors and seeding functions  
    explicit linear_congruential_engine(result_type s = default_seed);  
    template<class Sseq> explicit linear_congruential_engine(Sseq& q);  
    void seed(result_type s = default_seed);  
    template<class Sseq> void seed(Sseq& q);  
  
    // generating functions  
    result_type operator()();  
    void discard(unsigned long long z);  
};  
```  
  
#### Parâmetros  
 `UIntType`  
 O tipo de resultado inteiro sem sinal. Para os tipos possíveis, consulte [\<random\>](../standard-library/random.md).  
  
 `A`  
 **Multiplicador**.**Pré\-condição**: seção Consulte comentários.  
  
 `C`  
 **Incremento**.**Pré\-condição**: seção Consulte comentários.  
  
 `M`  
 **Módulo**.**Pré\-condição**: consulte comentários.  
  
## Membros  
  
||||  
|-|-|-|  
|`linear_congruential_engine::linear_congruential_engine`|`linear_congruential_engine::min`|`linear_congruential_engine::discard`|  
|`linear_congruential_engine::operator()`|`linear_congruential_engine::max`|`linear_congruential_engine::seed`|  
  
 `default_seed` é um membro constante, definido como `1u`, usado como o valor de parâmetro padrão para `linear_congruential_engine::seed` e construtor de valor único.  
  
 Para obter mais informações sobre membros do mecanismo, consulte [\<random\>](../standard-library/random.md).  
  
## Comentários  
 O `linear_congruential_engine` classe de modelo é o mecanismo gerador mais simples, mas não a qualidade mais alta ou mais rápida. Uma melhoria em relação esse mecanismo é o [substract\_with\_carry\_engine](../Topic/subtract_with_carry_engine%20Class.md). Nenhum desses mecanismos é tão rápido nem como resultados de alta qualidade como o [mersenne\_twister\_engine](../standard-library/mersenne-twister-engine-class.md).  
  
 Esse mecanismo produz valores de um tipo especificado pelo usuário não assinado integral usando a relação de recorrência \(*período*\) `x(i) = (A * x(i-1) + C) mod M`.  
  
 Se `M` for zero, o valor usado para essa operação de módulo é `numeric_limits<result_type>::max() + 1`. O estado do mecanismo é o último valor retornado ou o valor de semente, se nenhuma chamada foi feita para `operator()`.  
  
 Se `M` for diferente de zero, os valores dos argumentos de modelo `A` e `C` deve ser menor que `M`.  
  
 Embora seja possível construir um gerador do mecanismo diretamente, você também pode usar um desses typedefs predefinidos.  
  
 `minstd_rand0`: 1988 mecanismo padrão mínimo \(Lewis, Goodman e Miller, 1969\).  
  
```  
typedef linear_congruential_engine<unsigned int, 16807, 0, 2147483647> minstd_rand0;  
```  
  
 `minstd_rand`: Mecanismo padrão mínimo atualizado `minstd_rand0` \(Park, Miller e Stockmeyer, 1993\).  
  
```  
typedef linear_congruential_engine<unsigned int, 48271, 0, 2147483647> minstd_rand;  
```  
  
 Para obter informações detalhadas sobre o algoritmo de mecanismo Congruente linear, consulte o artigo da Wikipedia [gerador Congruente Linear](http://go.microsoft.com/fwlink/?LinkId=402446).  
  
## Requisitos  
 **Cabeçalho:** \< random \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)