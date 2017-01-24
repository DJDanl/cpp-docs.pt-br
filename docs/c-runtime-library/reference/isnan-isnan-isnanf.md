---
title: "isNaN isNaN, _isnanf | Microsoft Docs"
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
  - "_isnan"
  - "_isnanf"
  - "isnan"
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
  - "_isnan"
  - "isnan"
  - "math/isnan"
  - "math/_isnan"
  - "math/_isnanf"
  - "_isnanf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "NAN (não é um número)"
  - "Função _isnan"
  - "representação de ponto flutuante IEEE"
  - "Não é um Número (NANs)"
  - "Função isnan"
ms.assetid: 391fbc5b-89a4-4fba-997e-68f1131caf82
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isNaN isNaN, _isnanf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Testa se um valor de ponto flutuante não é um número \(NAN\).  
  
## Sintaxe  
  
```  
int isnan(  
   /* floating-point */ x   
); /* C-only macro */  
  
int _isnan(  
   double x   
);  
  
int _isnanf(  
   float x  
); /* x64 only */  
  
template <class T>  
bool isnan(  
   T x  
) throw(); /* C++ only */  
```  
  
#### Parâmetros  
 *x*  
 O valor de ponto flutuante para teste.  
  
## Valor de retorno  
 Em C, o `isnan` macro e `_isnan` e `_isnanf` funções retornam um valor diferente de zero se o argumento `x` é um NAN; caso contrário, elas retornam 0.  
  
 No C\+\+, o `isnan` modelo funções retornam `true` se o argumento `x` é um NAN; caso contrário, elas retornam `false`.  
  
## Comentários  
 O C `isnan` macro e `_isnan` e `_isnanf` funções testar o valor de ponto flutuante *x*, retornando um valor diferente de zero se *x* não é um valor de número \(NAN\). Um NAN é gerado quando o resultado de uma operação de ponto flutuante não pode ser representado no formato de ponto flutuante IEEE\-754 para o tipo especificado. Para obter informações sobre como um NAN é representado para saída, consulte [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
 Quando compilado c\+\+, o `isnan` macro não estiver definida e uma `isnan` função modelo é definida em vez disso. Ele retorna um valor do tipo `bool` em vez de um número inteiro.  
  
 O `_isnan` e `_isnanf` funções são específicas da Microsoft. O `_isnanf` função só está disponível quando compilado para x64.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário \(C\)|Cabeçalho necessário \(C\+\+\)|  
|------------|--------------------------------|------------------------------------|  
|`isnan`, `_isnanf`|\< Math \>|\< Math \> ou \< cmath \>|  
|`_isnan`|\< float. h \>|\< float. h \> ou \< cfloat \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Finitas, \_finitef](../../c-runtime-library/reference/finite-finitef.md)   
 [fpclass, \_fpclassf](../../c-runtime-library/reference/fpclass-fpclassf.md)