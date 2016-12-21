---
title: "nextafter, nextafterf, nextafterl, nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "nextafterf"
  - "_nextafterf"
  - "nextafter"
  - "nextafterl"
  - "_nextafter"
  - "nexttoward"
  - "nexttowardf"
  - "nexttowardl"
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
  - "nextafter"
  - "_nextafter"
  - "nextafterf"
  - "nextafterl"
  - "_nextafterf"
  - "math/nextafter"
  - "math/nextafterf"
  - "math/nextafterl"
  - "nexttoward"
  - "nexttowardf"
  - "nexttowardl"
  - "math/nexttoward"
  - "math/nexttowardf"
  - "math/nexttowardl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _nextafter"
  - "Função nextafter"
  - "função _nextafterf"
  - "Função nextafterf"
  - "função nextafterl"
  - "função nexttoward"
  - "função nexttowardf"
  - "função nexttowardl"
ms.assetid: 9785bfb9-de53-4bd0-9637-f05fa0c1f6ab
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# nextafter, nextafterf, nextafterl, nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o próximo valor de ponto flutuante representável.  
  
## Sintaxe  
  
```  
double nextafter(  
   double x,  
   double y   
);  
  
float nextafter(  
   float x,  
   float y   
); /* C++ only, requires <cmath> */  
  
long double nextafter(  
   long double x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
float nextafterf(  
   float x,  
   float y   
);   
  
long double nextafterl(  
   long double x,  
   long double y   
);  
  
double _nextafter(  
   double x,  
   double y   
);  
  
float _nextafterf(  
   float x,  
   float y   
); /* x64 only */  
  
double nexttoward(  
   double x,  
   long double y   
);  
  
float nexttoward(  
   float x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
long double nexttoward(  
   long double x,  
   long double y   
); /* C++ only, requires <cmath> */  
  
float nexttowardf(  
   float x,  
   long double y   
);   
  
long double nexttowardl(  
   long double x,  
   long double y   
);  
```  
  
#### Parâmetros  
 `x`  
 O valor de ponto flutuante para iniciar a partir de.  
  
 `y`  
 O valor de ponto flutuante para ir para.  
  
## Valor de retorno  
 Retorna o próximo valor de ponto flutuante representável do tipo de retorno após `x` na direção da `y`. Se `x`\=`y`, a função retorna `y`, convertida para o tipo de retorno, nenhuma exceção acionada. Se `x` não é igual a `y`, e o resultado é um denormal ou zero, os estados de exceção de ponto flutuante FE\_UNDERFLOW e FE\_INEXACT são definidos, e o resultado correto é retornado. Se `x` ou `y` é um NAN, em seguida, o valor de retorno é um dos NANs de entrada. Se `x` é finito e o resultado é infinito ou não representável no tipo, um corretamente assinado infinito ou NAN é retornado, os estados de exceção de ponto flutuante FE\_OVERFLOW e FE\_INEXACT são definidos, e `errno` é definido como ERANGE.  
  
## Comentários  
 O `nextafter` e `nexttoward` famílias de função são equivalentes, exceto o tipo de parâmetro `y`. Se `x` e `y` são iguais, o valor retornado é `y` convertido para o tipo de retorno.  
  
 Como C\+\+ permite sobrecargas, se você incluir \< cmath \> é possível chamar sobrecargas de `nextafter` e `nexttoward` que retornam `float` e `long double` tipos. Em um programa C, `nextafter` e `nexttoward` sempre retornará `double`.  
  
 O `_nextafter` e `_nextafterf` funções são específicas da Microsoft. O `_nextafterf` função só está disponível durante a compilação para x64.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário \(C\)|Cabeçalho necessário \(C\+\+\)|  
|------------|--------------------------------|------------------------------------|  
|`nextafter`, `nextafterf`, `nextafterl`, `_nextafterf`, `nexttoward`, `nexttowardf`, `nexttowardl`|\< Math \>|\< Math \> ou \< cmath \>|  
|`_nextafter`|\< float. h \>|\< float. h \> ou \< cfloat \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isNaN isNaN, \_isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)