---
title: _ecvt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _ecvt
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
f1_keywords: _ecvt
dev_langs: C++
helpviewer_keywords:
- _ecvt function
- numbers, converting
- converting double numbers
- ecvt function
ms.assetid: a916eb05-92d1-4b5c-8563-093acdb49dc8
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 237924bce3bb4b659e72cec060738035d91c7cbc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ecvt"></a>_ecvt
Converte um número `double` em uma cadeia de caracteres. Uma versão mais segura dessa função está disponível. Consulte [_ecvt_s](../../c-runtime-library/reference/ecvt-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_ecvt(   
   double value,  
   int count,  
   int *dec,  
   int *sign   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value`  
 Número a ser convertido.  
  
 `count`  
 Número de dígitos armazenados.  
  
 `dec`  
 Posição do ponto decimal armazenada.  
  
 `sign`  
 Sinal do número convertido.  
  
## <a name="return-value"></a>Valor de retorno  
 `_ecvt` retorna um ponteiro para a cadeia de caracteres de dígitos. NULL se ocorreu um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_ecvt` converte um número de ponto flutuante em uma cadeia de caracteres. O parâmetro `value` é o número de ponto flutuante a ser convertido. Essa função armazena até `count` dígitos do `value` como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). Se o número de dígitos em `value` exceder `count`, os dígitos de ordem inferior serão arredondados. Se houver menos de `count` dígitos, a cadeia de caracteres será preenchida com zeros.  
  
 O número total de dígitos retornados por `_ecvt` não deve exceder `_CVTBUFSIZE`.  
  
 Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de `value` podem ser obtidos de `dec` e `sign` após a chamada. O parâmetro `dec` aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de 0 ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro `sign` aponta para um número inteiro que indica o sinal do número convertido. Se o valor inteiro for 0, o número será positivo. Caso contrário, o resultado será negativo.  
  
 A diferença entre `_ecvt` e `_fcvt` está na interpretação do parâmetro `count`. `_ecvt` interpreta `count` como o número total de dígitos na cadeia de saída, enquanto `_fcvt` interpreta `count` como o número de dígitos após o ponto decimal.  
  
 `_ecvt` e `_fcvt` usam um único buffer alocado estaticamente para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.  
  
 Essa função valida seus parâmetros. Se `dec` ou `sign` for NULO ou `count` for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `errno` será definido como `EINVAL` e NULO será retornado.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_ecvt`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
source: 3.1415926535   buffer: '3141592654'  decimal: 1  sign: 0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [_fcvt](../../c-runtime-library/reference/fcvt.md)   
 [_gcvt](../../c-runtime-library/reference/gcvt.md)