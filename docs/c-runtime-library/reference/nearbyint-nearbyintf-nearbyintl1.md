---
title: "nearbyint, nearbyintf, nearbyintl | Microsoft Docs"
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
  - "nearbyint"
  - "nearbyintf"
  - "nerabyintl"
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
  - "nearbyint"
  - "nearbyintf"
  - "nearbyintl"
  - "math/nearbyint"
  - "math/narbyintf"
  - "math/narbyintl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função nearbyint"
  - "Função nearbyintf"
  - "função nearbyintl"
ms.assetid: dd39cb68-96b0-434b-820f-6ff2ea65584f
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# nearbyint, nearbyintf, nearbyintl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Arredonda o valor especificado de ponto flutuante para um inteiro e retorna esse valor em um formato de ponto flutuante.  
  
## Sintaxe  
  
```  
double nearbyint(  
   double x  
);  
  
float nearbyint(  
   float x  
); //C++ only  
  
long double nearbyint(  
   long double x  
); //C++ only  
  
float nearbyintf(  
   float x  
);  
  
long double nearbyintl(  
   long double x  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O valor a ser arredondado.  
  
## Valor de retorno  
 Se for bem\-sucedido, retornará `x`, arredondado para o inteiro mais próximo, usando o formato de arredondamento atual conforme definido pela fegetround. Caso contrário, a função pode retornar um dos seguintes valores:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \= ±INFINITY|±INFINITY, sem modificações|  
|`x` \= ±0|±0, sem modificações|  
|`x` \= NaN|NaN|  
  
 Erros não são reportados através de [\_matherr](../../c-runtime-library/reference/matherr.md); especificamente, essa função não relata todas as exceções FE\_INEXACT.  
  
## Comentários  
 A principal diferença entre essa função e `rint` é que essa função não gera a exceção de ponto flutuante inexato.  
  
 Como os valores máximos de ponto flutuantes são inteiros exatos, essa função nunca estourar sozinho. em vez disso, a saída pode estourar o valor de retorno, dependendo da versão da função que você usar.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`nearbyint`, `nearbyintf`,  `nearbyintl`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)