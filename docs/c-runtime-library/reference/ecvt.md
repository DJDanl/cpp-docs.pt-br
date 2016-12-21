---
title: "_ecvt | Microsoft Docs"
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
  - "_ecvt"
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
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ecvt"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ecvt"
  - "convertendo números duplos"
  - "Função ecvt"
  - "números, convertendo"
ms.assetid: a916eb05-92d1-4b5c-8563-093acdb49dc8
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ecvt
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um número de `double` a uma cadeia de caracteres.  Uma versão mais segura dessa função está disponível; consulte [\_ecvt\_s](../Topic/_ecvt_s.md).  
  
## Sintaxe  
  
```  
char *_ecvt(   
   double value,  
   int count,  
   int *dec,  
   int *sign   
);  
```  
  
#### Parâmetros  
 `value`  
 Número a ser convertido.  
  
 `count`  
 Número de dígitos armazenados.  
  
 `dec`  
 Posição da vírgula decimal armazenada.  
  
 `sign`  
 Sinal de número convertido.  
  
## Valor de retorno  
 `_ecvt` retorna um ponteiro para a cadeia de caracteres de dígitos; NULL se um erro ocorreu.  
  
## Comentários  
 A função de `_ecvt` converte um número de ponto flutuante como uma cadeia de caracteres.  O parâmetro de `value` é o número de ponto flutuante a ser convertido.  Essa função armazena até `count` dígitos de `value` como uma cadeia de caracteres e anexará um caractere nulo \(\\ “0 "\).  Se o número de dígitos em `value` exceder `count`, o dígito de ordem mais inferior é arredondado.  Se houver menos do que dígitos de `count` , a cadeia de caracteres é preenchida com zeros.  
  
 O número total de dígitos retornados por `_ecvt` não excederá `_CVTBUFSIZE`.  
  
 Somente os dígitos são armazenados na cadeia de caracteres.  A posição do ponto decimal e o sinal de `value` podem ser obtidos de `dec` e de `sign` depois da chamada.  O parâmetro de `dec` a um valor inteiro que fornece a posição do ponto decimal em relação ao início da cadeia de caracteres.  Um 0 ou um valor inteiro negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito.  O parâmetro de `sign` para um inteiro que indica o sinal do número convertido.  Se o valor inteiro é 0, o número for positivo.  Caso contrário, o número for negativo.  
  
 A diferença entre `_ecvt` e `_fcvt` está na interpretação de parâmetro de `count` .  `_ecvt` interpreta `count` como o número total de dígitos na cadeia de caracteres de saída, enquanto que `_fcvt` interpreta `count` como o número de dígitos após o ponto decimal.  
  
 `_ecvt` e `_fcvt` usam um único buffer estaticamente atribuído à conversão.  Cada chamada para uma dessas rotinas destrói o resultado da chamada anterior.  
  
 Essa função valida seus parâmetros.  Se `dec` ou `sign` são NULL, ou `count` é 0, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EINVAL` e NULL será retornado.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ecvt`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_ecvt.c  
// compile with: /W3  
// This program uses _ecvt to convert a  
// floating-point number to a character string.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int     decimal,   sign;  
   char    *buffer;  
   int     precision = 10;  
   double  source = 3.1415926535;  
  
   buffer = _ecvt( source, precision, &decimal, &sign ); // C4996  
   // Note: _ecvt is deprecated; consider using _ecvt_s instead  
   printf( "source: %2.10f   buffer: '%s'  decimal: %d  sign: %d\n",  
           source, buffer, decimal, sign );  
}  
```  
  
  **origem: buffer 3,1415926535: “3141592654 ": decimal 1 sinal: 0**   
## Equivalência do .NET Framework  
 [System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [\_fcvt](../Topic/_fcvt.md)   
 [\_gcvt](../../c-runtime-library/reference/gcvt.md)