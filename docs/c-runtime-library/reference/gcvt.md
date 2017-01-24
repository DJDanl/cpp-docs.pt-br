---
title: "_gcvt | Microsoft Docs"
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
  - "_gcvt"
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
  - "_gcvt"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "_CVTBUFSIZE"
  - "Função _gcvt"
  - "conversões, ponto flutuante para cadeias de caracteres"
  - "CVTBUFSIZE"
  - "funções de ponto flutuante, convertendo número em cadeia de caracteres"
  - "Função gcvt"
  - "números, convertendo em cadeias de caracteres"
  - "cadeias de caracteres [C++], convertendo de ponto flutuante"
ms.assetid: 5761411e-c06b-409a-912f-810fe7f4bcb5
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _gcvt
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um valor de ponto flutuante como uma cadeia de caracteres, que armazena em um buffer.  Uma versão mais segura dessa função está disponível; consulte [\_gcvt\_s](../../c-runtime-library/reference/gcvt-s.md).  
  
## Sintaxe  
  
```  
char *_gcvt(   
   double value,  
   int digits,  
   char *buffer   
);  
```  
  
#### Parâmetros  
 `value`  
 Valor a ser convertido.  
  
 `digits`  
 Número de dígitos significativos armazenados.  
  
 `buffer`  
 Local de armazenamento do resultado.  
  
## Valor de retorno  
 `_gcvt` retorna um ponteiro para a cadeia de caracteres de dígitos.  
  
## Comentários  
 A função de `_gcvt` converte `value` de ponto flutuante como uma cadeia de caracteres \(que inclui um ponto decimal opcional e um byte que o sinal\) e armazena a cadeia de caracteres em `buffer`.  `buffer` deve ser grande o suficiente para acomodar o valor convertido mais um caractere terminador nulo, que é acrescentado automaticamente.  Se um tamanho do buffer de `digits` \+ 1 for usado, a função substitui a extremidade do buffer.  Isso ocorre porque a cadeia de caracteres convertida inclui um ponto decimal opcional e pode conter informações de sinal e do expoente.  Não há provisão para o estouro.  `_gcvt` tenta gerar dígitos de `digits` em formato decimal.  Se não puder, gerencia dígitos de `digits` no formato exponencialmente.  Zeros à direita sejam suprimidos na conversão.  
  
 `buffer` de comprimento `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante.  
  
 Essa função valida seus parâmetros.  Se `buffer` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_gcvt`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_gcvt.c  
// compile with: /W3  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
  
int main( void )  
{  
   char buffer[_CVTBUFSIZE];  
   double value = -1234567890.123;  
   printf( "The following numbers were converted by _gcvt(value,12,buffer):\n" );  
   _gcvt( value, 12, buffer ); // C4996  
   // Note: _gcvt is deprecated; consider using _gcvt_s instead  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value *= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value *= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value *= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
  
   printf( "\n" );  
   value = -12.34567890123;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value /= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value /= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
   value /= 10;  
   _gcvt( value, 12, buffer ); // C4996  
   printf( "buffer: '%s' (%d chars)\n", buffer, strlen(buffer) );  
}  
```  
  
  **Estes números são convertidos por \_gcvt \(valor, 12, buffer\):**  
**buffer: “\- 1234567890,12 " \(14 caracteres\)**  
**buffer: “\- 12345678901,2 " \(14 caracteres\)**  
**buffer: “\- 123456789012 " \(13 caracteres\)**  
**buffer: “\- 1.23456789012e\+012” \(19 caracteres\)**  
**buffer: “\- 12,3456789012 " \(14 caracteres\)**  
**buffer: “\- 1,23456789012 " \(14 caracteres\)**  
**buffer: “\- 0,123456789012 " \(15 caracteres\)**  
**buffer: “\- 1.23456789012e\-002” \(19 caracteres\)**   
## Equivalência do .NET Framework  
 [System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [\_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [\_fcvt](../Topic/_fcvt.md)