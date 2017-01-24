---
title: "Namespace Concurrency::fast_math | Microsoft Docs"
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
  - "amp_math/Concurrency::fast_math"
dev_langs: 
  - "C++"
ms.assetid: 54fed939-9902-49db-9f29-e98fd9821508
caps.latest.revision: 9
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Concurrency::fast_math
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Funções no namespace `fast_math` têm uma menor precisão, suportam apenas precisão simples \(`float`\), e chamam os intrínsecos do DirectX.  Há duas versões de cada função, por exemplo `cos` e `cosf`.  Ambas as versões recebem e retornam um `float`, mas cada uma chama o mesmo intrínseco do DirectX.  
  
## Sintaxe  
  
```  
namespace fast_math;  
```  
  
## Membros  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[CoS função \(fast\_math\)](../Topic/cos%20Function%20%20\(fast_math\).md)|Calcula o arco cosseno do argumento|  
|[Função cosf \(fast\_math\)](../Topic/cosf%20Function%20\(fast_math\).md)|Calcula o arco cosseno do argumento|  
|[Função asin \(fast\_math\)](../Topic/asin%20Function%20\(fast_math\).md)|Calcula o arco seno do argumento|  
|[Função asinf \(fast\_math\)](../Topic/asinf%20Function%20\(fast_math\).md)|Calcula o arco seno do argumento|  
|[Função atan \(fast\_math\)](../Topic/atan%20Function%20\(fast_math\).md)|Calcula o arco tangente do argumento|  
|[Função atan2 \(fast\_math\)](../Topic/atan2%20Function%20\(fast_math\).md)|Calcula o arco tangente de \_Y\/\_X|  
|[Função atan2f \(fast\_math\)](../Topic/atan2f%20Function%20\(fast_math\).md)|Calcula o arco tangente de \_Y\/\_X|  
|[Função atanf \(fast\_math\)](../Topic/atanf%20Function%20\(fast_math\).md)|Calcula o arco tangente do argumento|  
|[Função ceil \(fast\_math\)](../Topic/ceil%20Function%20\(fast_math\).md)|Calcula o teto do argumento|  
|[Função ceilf \(fast\_math\)](../Topic/ceilf%20Function%20\(fast_math\).md)|Calcula o teto do argumento|  
|[CoS função \(fast\_math\)](../Topic/cos%20Function%20%20\(fast_math\).md)|Calcula o cosseno do argumento|  
|[Função cosf \(fast\_math\)](../Topic/cosf%20Function%20\(fast_math\).md)|Calcula o cosseno do argumento|  
|[Função cosh \(fast\_math\)](../Topic/cosh%20Function%20\(fast_math\).md)|Calcula o valor do cosseno hiperbólico do argumento|  
|[Função coshf \(fast\_math\)](../Topic/coshf%20Function%20\(fast_math\).md)|Calcula o valor do cosseno hiperbólico do argumento|  
|[Função exp \(fast\_math\)](../Topic/exp%20Function%20\(fast_math\).md)|Calcula o exponencial na base e do argumento|  
|[Função exp2 \(fast\_math\)](../Topic/exp2%20Function%20\(fast_math\).md)|Calcula o exponencial na base 2 do argumento|  
|[Função exp2f \(fast\_math\)](../Topic/exp2f%20Function%20\(fast_math\).md)|Calcula o exponencial na base 2 do argumento|  
|[Função expf \(fast\_math\)](../Topic/expf%20Function%20\(fast_math\).md)|Calcula o exponencial na base e do argumento|  
|[Função fabs \(fast\_math\)](../Topic/fabs%20Function%20\(fast_math\).md)|Retorna o valor absoluto do argumento|  
|[Função fabsf \(fast\_math\)](../Topic/fabsf%20Function%20\(fast_math\).md)|Retorna o valor absoluto do argumento|  
|[Função floor \(fast\_math\)](../Topic/floor%20Function%20\(fast_math\).md)|Calcula o piso do argumento|  
|[Função floorf \(fast\_math\)](../Topic/floorf%20Function%20\(fast_math\).md)|Calcula o piso do argumento|  
|[Função fmax \(fast\_math\)](../Topic/fmax%20Function%20\(fast_math\).md)|Determinar o valor numérico máximo dos argumentos|  
|[Função fmaxf \(fast\_math\)](../Topic/fmaxf%20Function%20\(fast_math\).md)|Determinar o valor numérico máximo dos argumentos|  
|[Função fmin \(fast\_math\)](../Topic/fmin%20Function%20\(fast_math\).md)|Determinar o valor numérico mínimo dos argumentos|  
|[Função fminf \(fast\_math\)](../Topic/fminf%20Function%20\(fast_math\).md)|Determinar o valor numérico mínimo dos argumentos|  
|[Função fmod \(fast\_math\)](../Topic/fmod%20Function%20\(fast_math\).md)|Calcula o ponto flutuante restante de \_X\/\_Y|  
|[Função fmodf \(fast\_math\)](../Topic/fmodf%20Function%20\(fast_math\).md)|Calcula o ponto flutuante restante de \_X\/\_Y|  
|[Função frexp \(fast\_math\)](../Topic/frexp%20Function%20\(fast_math\).md)|Obtém a mantissa e o expoente de \_X|  
|[Função frexpf \(fast\_math\)](../Topic/frexpf%20Function%20\(fast_math\).md)|Obtém a mantissa e o expoente de \_X|  
|[Função isfinite \(fast\_math\)](../Topic/isfinite%20Function%20\(fast_math\).md)|Determina se o argumento tem um valor finito|  
|[Função isinf \(fast\_math\)](../Topic/isinf%20Function%20\(fast_math\).md)|Determina se o argumento é infinito|  
|[Função isnan \(fast\_math\)](../Topic/isnan%20Function%20\(fast_math\).md)|Determina se o argumento é um NaN|  
|[Função ldexp \(fast\_math\)](../Topic/ldexp%20Function%20\(fast_math\).md)|Calcula um número real da mantissa e expoente|  
|[Função ldexpf \(fast\_math\)](../Topic/ldexpf%20Function%20\(fast_math\).md)|Calcula um número real da mantissa e expoente|  
|[Função log \(fast\_math\)](../Topic/log%20Function%20\(fast_math\).md)|Calcula o logaritmo na base e do argumento|  
|[Função log10 \(fast\_math\)](../Topic/log10%20Function%20\(fast_math\).md)|Calcula o logaritmo na base 10 do argumento|  
|[Função log10f \(fast\_math\)](../Topic/log10f%20Function%20\(fast_math\).md)|Calcula o logaritmo na base 10 do argumento|  
|[Função log2 \(fast\_math\)](../Topic/log2%20Function%20\(fast_math\).md)|Calcula o logaritmo na base 2 do argumento|  
|[Função log2f \(fast\_math\)](../Topic/log2f%20Function%20\(fast_math\).md)|Calcula o logaritmo na base 2 do argumento|  
|[Função logf \(fast\_math\)](../Topic/logf%20Function%20\(fast_math\).md)|Calcula o logaritmo na base e do argumento|  
|[Função modf \(fast\_math\)](../Topic/modf%20Function%20\(fast_math\).md)|Divide \_X em partes fracionárias e inteira.|  
|[Função modff \(fast\_math\)](../Topic/modff%20Function%20\(fast_math\).md)|Divide \_X em partes fracionárias e inteira.|  
|[Função pow \(fast\_math\)](../Topic/pow%20Function%20\(fast_math\).md)|Calcula o \_X elevado à potência de \_Y|  
|[Função powf \(fast\_math\)](../Topic/powf%20Function%20\(fast_math\).md)|Calcula o \_X elevado à potência de \_Y|  
|[Função round \(fast\_math\)](../Topic/round%20Function%20\(fast_math\).md)|Arredonda o \_X para o inteiro mais próximo|  
|[Função roundf \(fast\_math\)](../Topic/roundf%20Function%20\(fast_math\).md)|Arredonda o \_X para o inteiro mais próximo|  
|[Função rsqrt \(fast\_math\)](../Topic/rsqrt%20Function%20\(fast_math\).md)|Retorna o recíproco da raiz quadrada do argumento|  
|[Função rsqrtf \(fast\_math\)](../Topic/rsqrtf%20Function%20\(fast_math\).md)|Retorna o recíproco da raiz quadrada do argumento|  
|[Função signbit \(fast\_math\)](../Topic/signbit%20Function%20\(fast_math\).md)|Retorna o sinal do argumento|  
|[Função signbitf \(fast\_math\)](../Topic/signbitf%20Function%20\(fast_math\).md)|Retorna o sinal do argumento|  
|[Função sin \(fast\_math\)](../Topic/sin%20Function%20\(fast_math\).md)|Calcula o valor do seno do argumento|  
|[Função sincos \(fast\_math\)](../Topic/sincos%20Function%20\(fast_math\).md)|Calcula o valor do seno e cosseno de \_X|  
|[Função sincosf \(fast\_math\)](../Topic/sincosf%20Function%20\(fast_math\).md)|Calcula o valor do seno e cosseno de \_X|  
|[Função sinf \(fast\_math\)](../Topic/sinf%20Function%20\(fast_math\).md)|Calcula o valor do seno do argumento|  
|[Função sinh \(fast\_math\)](../Topic/sinh%20Function%20\(fast_math\).md)|Calcula o valor do seno hiperbólico do argumento|  
|[Função sinhf \(fast\_math\)](../Topic/sinhf%20Function%20\(fast_math\).md)|Calcula o valor do seno hiperbólico do argumento|  
|[Função sqrt \(fast\_math\)](../Topic/sqrt%20Function%20\(fast_math\).md)|Calcula a raiz quadrada do argumento|  
|[Função sqrtf \(fast\_math\)](../Topic/sqrtf%20Function%20\(fast_math\).md)|Calcula a raiz quadrada do argumento|  
|[Função tan \(fast\_math\)](../Topic/tan%20Function%20\(fast_math\).md)|Calcula o valor da tangente do argumento|  
|[Função tanf \(fast\_math\)](../Topic/tanf%20Function%20\(fast_math\).md)|Calcula o valor da tangente do argumento|  
|[Função tanh \(fast\_math\)](../Topic/tanh%20Function%20\(fast_math\).md)|Calcula o valor da tangente hiperbólica do argumento|  
|[Função tanhf \(fast\_math\)](../Topic/tanhf%20Function%20\(fast_math\).md)|Calcula o valor da tangente hiperbólica do argumento|  
|[Função trunc \(fast\_math\)](../Topic/trunc%20Function%20\(fast_math\).md)|Trunca o argumento para o componente inteiro|  
|[Função truncf \(fast\_math\)](../Topic/truncf%20Function%20\(fast_math\).md)|Trunca o argumento para o componente inteiro|  
  
## Requisitos  
 **Cabeçalho:** amp\_math.h  
  
 **Namespace:** Concurrency::fast\_math  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)