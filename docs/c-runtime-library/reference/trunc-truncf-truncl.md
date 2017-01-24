---
title: "trunc, truncf, truncl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "trunc"
  - "truncf"
  - "truncl"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-math-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "trunc"
  - "truncf"
  - "truncl"
  - "math/trunc"
  - "math/truncf"
  - "math/truncl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função trunc"
  - "Função truncf"
  - "função truncl"
ms.assetid: de2038ac-ac0b-483e-870c-e8992dcd4fd0
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# trunc, truncf, truncl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina o inteiro mais próximo que é menor ou igual ao valor de ponto flutuante especificado.  
  
## Sintaxe  
  
```  
double trunc(  
   double x  
);  
  
float trunc(  
   float x  
); //C++ only  
  
long double trunc(  
   long double x  
); //C++ only  
  
float trunc(  
   float x  
); //C++ only  
  
long double truncl(  
   long double x  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O valor para truncar.  
  
## Valor de retorno  
 Se for bem\-sucedido, retorna um valor inteiro de `x`, arredondado em direção a zero.  
  
 Caso contrário, pode retornar um dos seguintes:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \= ±INFINITY|x|  
|`x` \=  ±0|x|  
|`x` \= NaN|NaN|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `trunc` que tomam e retornam tipos float e double longo. Em um programa C, `trunc` sempre toma e retorna um double.  
  
 Como os maiores valores de ponto flutuantes são inteiros exatos, essa função não estourar por conta própria. No entanto, você pode causar a estouro, retornando um valor em um tipo inteiro da função.  
  
 Você também pode arredondar para baixo pela conversão implícita de ponto flutuante para integral; No entanto, fazer isso é limitado aos valores que podem ser armazenados no tipo de destino.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`trunc`, `truncf`,  `truncl`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [floor, floorf, floorl](../../c-runtime-library/reference/floor-floorf-floorl.md)   
 [ceil, ceilf, ceill](../../c-runtime-library/reference/ceil-ceilf-ceill.md)   
 [round, roundf, roundl](../../c-runtime-library/reference/round-roundf-roundl.md)