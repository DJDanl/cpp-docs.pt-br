---
title: _fcvt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _fcvt
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
- _fcvt
dev_langs:
- C++
helpviewer_keywords:
- converting floating point, to strings
- _fcvt function
- floating-point functions, converting number to string
- fcvt function
- floating-point functions
ms.assetid: 74584c88-f0dd-4907-8fca-52da5df583f5
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 0e2bad41f044046fd0f75a30989c1f39adb69560
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="fcvt"></a>_fcvt
Converte um número de ponto flutuante em uma cadeia de caracteres. Uma versão mais segura dessa função está disponível. Consulte [_fcvt_s](../../c-runtime-library/reference/fcvt-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_fcvt(   
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
 O número de dígitos após o ponto decimal.  
  
 `dec`  
 Ponteiro para a posição do ponto decimal armazenada.  
  
 `sign`  
 Ponteiro para o indicador de logon armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 `_fcvt` retorna um ponteiro para a cadeia de caracteres de dígitos. NULO se ocorreu um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_fcvt` converte um número de ponto flutuante em uma cadeia de caracteres com terminação nula. O parâmetro `value` é o número de ponto flutuante a ser convertido. `_fcvt` armazena os dígitos de `value` como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). O parâmetro `count` especifica o número de dígitos a serem armazenados após o ponto decimal. Dígitos em excesso são arredondados para `count` casas. Se houver menos de `count` dígitos de precisão, a cadeia de caracteres será preenchida com zeros.  
  
 O número total de dígitos retornados por `_fcvt` não deve exceder `_CVTBUFSIZE`.  
  
 Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de `value` podem ser obtidos de `dec` após a chamada. O parâmetro `dec` aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro `sign` aponta para um número inteiro indicando o sinal de `value`. O inteiro é definido como 0 se `value` for positivo e é definido como um número diferente de zero se `value` for negativo.  
  
 A diferença entre `_ecvt` e `_fcvt` está na interpretação do parâmetro `count`. `_ecvt` interpreta `count` como o número total de dígitos na cadeia de saída, enquanto `_fcvt` interpreta `count` como o número de dígitos após o ponto decimal.  
  
 `_ecvt` e `_fcvt` usam um único buffer alocado estaticamente para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.  
  
 Essa função valida seus parâmetros. Se `dec` ou `sign` for NULO ou `count` for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `errno` será definido como `EINVAL` e NULO será retornado.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fcvt`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fcvt.c  
// compile with: /W3  
// This program converts the constant  
// 3.1415926535 to a string and sets the pointer  
// buffer to point to that string.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int  decimal, sign;  
   char *buffer;  
   double source = 3.1415926535;  
  
   buffer = _fcvt( source, 7, &decimal, &sign ); // C4996  
   // Note: _fcvt is deprecated; consider using _fcvt_s instead  
   printf( "source: %2.10f   buffer: '%s'   decimal: %d   sign: %d\n",  
            source, buffer, decimal, sign );  
}  
```  
  
```Output  
source: 3.1415926535   buffer: '31415927'   decimal: 1   sign: 0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [_gcvt](../../c-runtime-library/reference/gcvt.md)
