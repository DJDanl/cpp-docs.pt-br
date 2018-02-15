---
title: _gcvt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _gcvt
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _gcvt
dev_langs:
- C++
helpviewer_keywords:
- _gcvt function
- _CVTBUFSIZE
- gcvt function
- floating-point functions, converting number to string
- numbers, converting to strings
- conversions, floating point to strings
- strings [C++], converting from floating point
- CVTBUFSIZE
ms.assetid: 5761411e-c06b-409a-912f-810fe7f4bcb5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 97f1487b770ac761a2555985a69069155e51cf74
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="gcvt"></a>_gcvt
Converte um valor de ponto flutuante em uma cadeia de caracteres que é armazenada um buffer. Uma versão mais segura dessa função está disponível, consulte [_gcvt_s](../../c-runtime-library/reference/gcvt-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_gcvt(   
   double value,  
   int digits,  
   char *buffer   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value`  
 Valor a ser convertido.  
  
 `digits`  
 Número de dígitos significativos armazenados.  
  
 `buffer`  
 Local de armazenamento para o resultado.  
  
## <a name="return-value"></a>Valor de retorno  
 `_gcvt` retorna um ponteiro para a cadeia de caracteres de dígitos.  
  
## <a name="remarks"></a>Comentários  
 A função `_gcvt` converte um `value` de ponto flutuante em uma cadeia de caracteres (que inclui um ponto decimal e um possível byte de sinal) e armazena a cadeia de caracteres em `buffer`. `buffer` deve ser grande o suficiente para acomodar o valor convertido e um caractere nulo de terminação, que é acrescentado automaticamente. Se um tamanho do buffer de `digits` + 1 for usado, a função substituirá o final do buffer. Isso ocorre porque a cadeia de caracteres convertida inclui um ponto decimal e pode conter informações expoente e sinal. Não há nenhuma provisão para estouros. `_gcvt` tenta gerar dígitos `digits` no formato decimal. Se não for possível, ele produzirá dígitos `digits` no formato exponencial. Zeros à direita podem ser suprimidos na conversão.  
  
 Um `buffer` de tamanho `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante.  
  
 Essa função valida seus parâmetros. Se `buffer` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_gcvt`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
The following numbers were converted by _gcvt(value,12,buffer):  
buffer: '-1234567890.12' (14 chars)  
buffer: '-12345678901.2' (14 chars)  
buffer: '-123456789012' (13 chars)  
buffer: '-1.23456789012e+012' (19 chars)  
  
buffer: '-12.3456789012' (14 chars)  
buffer: '-1.23456789012' (14 chars)  
buffer: '-0.123456789012' (15 chars)  
buffer: '-1.23456789012e-002' (19 chars)  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [_fcvt](../../c-runtime-library/reference/fcvt.md)