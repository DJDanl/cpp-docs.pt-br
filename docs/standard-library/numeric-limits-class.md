---
title: "Classe numeric_limits | Microsoft Docs"
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
  - "std::numeric_limits"
  - "std.numeric_limits"
  - "numeric_limits"
  - "limits/std::numeric_limits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe numeric_limits"
ms.assetid: 9e817177-0e91-48e6-b680-0531c4b26625
caps.latest.revision: 26
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe numeric_limits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve propriedades aritméticas tipos numéricos internos.  
  
## Sintaxe  
  
```  
template<classType> class numeric_limits  
```  
  
#### Parâmetros  
 `Type`  
 O tipo de dados do elemento fundamental cujas propriedades estão sendo testados ou consultadas ou definidas.  
  
## Comentários  
 O cabeçalho define especializações explícitas para os tipos de `wchar_t`, `bool`, `char`, `signed char`, `unsigned char`, `short`, `unsigned short`, `int`, `unsigned int`, `long`, `unsigned long`, `float`, `double`, `long double`**,** `long long`, `unsigned long long`, `char16_t`, e `char32_t`. Para esses especializações explícitas, o membro [numeric\_limits::is\_specialized](../Topic/numeric_limits::is_specialized.md) é `true`, e todos os membros relevantes têm valores significativos. O programa pode fornecer especializações explícitas adicionais. A maioria das funções de membro da classe descrevem ou testar possíveis implementações de `float`.  
  
 Para uma especialização arbitrária, sem membros têm valores significativos. Um objeto de membro que não tem um valor significativo armazena zero \(ou `false`\) e retorna uma função de membro que não retorna um valor significativo `Type(0)`.  
  
### Constantes e funções estáticas  
  
|||  
|-|-|  
|[denorm\_min](../Topic/numeric_limits::denorm_min.md)|Retorna o menor diferente de zero desnormalizados valor.|  
|[dígitos](../Topic/numeric_limits::digits.md)|Retorna o número de dígitos de base que o tipo pode representar sem perda de precisão.|  
|[digits10](../Topic/numeric_limits::digits10.md)|Retorna o número de dígitos decimais que pode representar o tipo sem perda de precisão.|  
|[épsilon](../Topic/numeric_limits::epsilon.md)|Retorna a diferença entre 1 e o menor valor maior que 1, que pode representar o tipo de dados.|  
|[has\_denorm](../Topic/numeric_limits::has_denorm.md)|Testa se um tipo permite desnormalizados valores.|  
|[has\_denorm\_loss](../Topic/numeric_limits::has_denorm_loss.md)|Testa se a perda de precisão é detectada como uma perda de desnormalização em vez de um resultado inexato.|  
|[has\_infinity](../Topic/numeric_limits::has_infinity.md)|Testa se um tipo tem uma representação de infinito positivo.|  
|[has\_quiet\_NaN](../Topic/numeric_limits::has_quiet_NaN.md)|Testa se um tipo tem uma representação de um silencioso não é um número \(NAN\), que é nonsignaling.|  
|[has\_signaling\_NaN](../Topic/numeric_limits::has_signaling_NaN.md)|Testa se um tipo tem uma representação de sinalização não é um número \(NAN\).|  
|[infinito](../Topic/numeric_limits::infinity.md)|A representação de infinito positivo para um tipo, se disponível.|  
|[is\_bounded](../Topic/numeric_limits::is_bounded.md)|Testa se o conjunto de valores que pode representar um tipo é finito.|  
|[is\_exact](../Topic/numeric_limits::is_exact.md)|Testa se os cálculos feitos em um tipo estejam livres de erros de arredondamento.|  
|[is\_iec559](../Topic/numeric_limits::is_iec559.md)|Testa se um tipo está em conformidade com padrões 559 IEC.|  
|[is\_integer](../Topic/numeric_limits::is_integer.md)|Testa se um tipo tem uma representação de inteiro.|  
|[is\_modulo](../Topic/numeric_limits::is_modulo.md)|Testa se um tipo tem uma representação de módulo.|  
|[is\_signed](../Topic/numeric_limits::is_signed.md)|Testa se um tipo tem uma representação assinada.|  
|[is\_specialized](../Topic/numeric_limits::is_specialized.md)|Testa se um tipo tem uma especialização explícita definida na classe modelo `numeric_limits`.|  
|[mais baixo](../Topic/numeric_limits::lowest.md)|Retorna o valor finito mais negativo.|  
|[max](../Topic/numeric_limits::max.md)|Retorna o valor máximo finito para um tipo.|  
|[max\_digits10](../Topic/numeric_limits::max_digits10.md)|Retorna o número de dígitos decimais necessárias para garantir que dois valores distintos do tipo tem diferentes representações decimais.|  
|[max\_exponent](../Topic/numeric_limits::max_exponent.md)|Retorna o expoente inteiro positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é gerada para que a energia.|  
|[max\_exponent10](../Topic/numeric_limits::max_exponent10.md)|Retorna o expoente inteiro positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é gerada para que a energia.|  
|[min](../Topic/numeric_limits::min.md)|Retorna o valor normalizado mínimo para um tipo.|  
|[min\_exponent](../Topic/numeric_limits::min_exponent.md)|Retorna o expoente inteiro negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é gerada para que a energia.|  
|[min\_exponent10](../Topic/numeric_limits::min_exponent10.md)|Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é gerada para que a energia.|  
|[quiet\_NaN](../Topic/numeric_limits::quiet_NaN.md)|Retorna a representação de um silencioso não é um número \(NAN\) para o tipo.|  
|[base](../Topic/numeric_limits::radix.md)|Retorna a base integral, conhecido como base, usada para a representação de um tipo.|  
|[round\_error](../Topic/numeric_limits::round_error.md)|Retorna o erro para o tipo de arredondamento máximo.|  
|[round\_style](../Topic/numeric_limits::round_style.md)|Retorna um valor que descreve os vários métodos que pode escolher uma implementação para o arredondamento de um valor de ponto flutuante para um valor inteiro.|  
|[signaling\_NaN](../Topic/numeric_limits::signaling_NaN.md)|Retorna a representação de um não\-número \(NAN\) de sinalização para o tipo.|  
|[tinyness\_before](../Topic/numeric_limits::tinyness_before.md)|Testa se um tipo pode determinar que um valor é muito pequeno para representar como um valor normalizado antes de arredondamento\-lo.|  
|[interceptações](../Topic/numeric_limits::traps.md)|Testa se trapping que relata exceções aritméticas é implementado para um tipo.|  
  
## Requisitos  
 **Cabeçalho:** \< limites \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)