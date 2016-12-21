---
title: "logb, logbf, logbl, _logb, _logbf | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "logb"
  - "_logb"
  - "_logbl"
  - "logbf"
  - "logbl"
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
  - "logb"
  - "logbl"
  - "_logb"
  - "_logbf"
  - "logbf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _logb"
  - "Função _logbf"
  - "expoente, números de ponto flutuante"
  - "expoentes e mantissas"
  - "funções de ponto flutuante"
  - "funções de ponto flutuante, mantissa e expoente"
  - "Função logb"
  - "Função logbf"
  - "Função logbl"
  - "mantissas, variáveis de ponto flutuante"
ms.assetid: 780c4daa-6fe6-4fbc-9412-4c1ba1a1766f
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# logb, logbf, logbl, _logb, _logbf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Extrai o valor do expoente de um argumento de ponto flutuante.  
  
## Sintaxe  
  
```  
double logb(  
   double x   
);  
float logb(  
   float x   
); // C++ only  
long double logb(  
   long double x   
); // C++ only   
float logbf(  
   float x   
);  
long double logbl(  
   long double x   
);  
double _logb(  
   double x   
);  
float _logbf(  
   float x   
);  
```  
  
#### Parâmetros  
 x  
 Um valor de ponto flutuante.  
  
## Valor de retorno  
 `logb` retorna o valor imparcial do expoente de `x` como um inteiro com sinal representado como um valor de ponto flutuante.  
  
## Comentários  
 As funções `logb` extraem o valor exponencial do argumento de ponto flutuante `x`, como se `x` fosse representado com intervalo infinito.  Se o argumento `x` for desnormalizado, será tratado como se fosse normalizado.  
  
 Como o C\+\+ permite a sobrecarga, você pode chamar as sobrecargas de `logb` que levam e retornam valores `float` ou `long double`.  Em um programa em C, `logb` sempre obterá e retornará um `double`.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± QNAN,IND|Nenhum|\_DOMAIN|  
|± 0|ZERODIVIDE|\_SING|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_logb`|\<float.h\>|  
|`logb`, `logbf`, `logbl`, `_logbf`|\<math.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [frexp](../../c-runtime-library/reference/frexp.md)