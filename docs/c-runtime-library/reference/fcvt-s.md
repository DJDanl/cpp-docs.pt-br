---
title: _fcvt_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _fcvt_s
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
- fcvt_s
- _fcvt_s
dev_langs:
- C++
helpviewer_keywords:
- fcvt_s function
- converting floating point, to strings
- floating-point functions, converting number to string
- _fcvt_s function
ms.assetid: 48671197-1d29-4c2b-a5d8-d2368f5f68a1
caps.latest.revision: 27
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 6b0c6de598b810d80debc280bd60e354b17a8c47
ms.lasthandoff: 02/25/2017

---
# <a name="fcvts"></a>_fcvt_s
Converte um número de ponto flutuante em uma cadeia de caracteres. Trata-se de uma versão de [_fcvt](../../c-runtime-library/reference/fcvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _fcvt_s(   
   char* buffer,  
   size_t sizeInBytes,  
   double value,  
   int count,  
   int *dec,  
   int *sign   
);  
template <size_t size>  
errno_t _fcvt_s(   
   char (&buffer)[size],  
   double value,  
   int count,  
   int *dec,  
   int *sign   
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `buffer`  
 O buffer fornecido que conterá o resultado da conversão.  
  
 [in] `sizeInBytes`  
 O tamanho do buffer em bytes.  
  
 [in] `value`  
 Número a ser convertido.  
  
 [in] `count`  
 O número de dígitos após o ponto decimal.  
  
 [out] `dec`  
 Ponteiro para a posição do ponto decimal armazenada.  
  
 [out] `sign`  
 Ponteiro para o indicador de logon armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 No caso de um parâmetro inválido, conforme listado na tabela a seguir, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EINVAL`.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`buffer`|`sizeInBytes`|Valor |count|dec|sinal|Valor de|Valor em `buffer`|  
|--------------|-------------------|-----------|-----------|---------|----------|------------|-----------------------|  
|`NULL`|qualquer|qualquer|qualquer|qualquer|qualquer|`EINVAL`|Não modificado.|  
|Não é `NULL` (aponta para a memória válida)|<=0|qualquer|qualquer|qualquer|qualquer|`EINVAL`|Não modificado.|  
|qualquer|qualquer|qualquer|qualquer|`NULL`|qualquer|`EINVAL`|Não modificado.|  
|qualquer|qualquer|qualquer|qualquer|qualquer|`NULL`|`EINVAL`|Não modificado.|  
  
 **Problemas de segurança**  
  
 `_fcvt_s` pode gerar uma violação de acesso se `buffer` não apontar para a memória válida e não for `NULL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_fcvt_s` converte um número de ponto flutuante em uma cadeia de caracteres com terminação nula. O parâmetro `value` é o número de ponto flutuante a ser convertido. `_fcvt_s` armazena os dígitos de `value` como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). O parâmetro `count` especifica o número de dígitos a serem armazenados após o ponto decimal. Dígitos em excesso são arredondados para `count` casas. Se houver menos de `count` dígitos de precisão, a cadeia de caracteres será preenchida com zeros.  
  
 Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de `value` podem ser obtidos de `dec` e `sign` após a chamada. O parâmetro `dec` aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro `sign` aponta para um número inteiro indicando o sinal de `value`. O inteiro é definido como 0 se `value` for positivo e é definido como um número diferente de zero se `value` for negativo.  
  
 Um buffer de tamanho `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante.  
  
 A diferença entre `_ecvt_s` e `_fcvt_s` está na interpretação do parâmetro `count`. `_ecvt_s` interpreta `count` como o número total de dígitos na cadeia de saída, enquanto `_fcvt_s` interpreta c`ount` como o número de dígitos após o ponto decimal.  
  
 No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|--------------|---------------------|---------------------|  
|`_fcvt_s`|\<stdlib.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** todas as versões dos [Recursos da Biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// fcvt_s.c  
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
  
int main()  
{  
  char * buf = 0;  
  int decimal;  
  int sign;  
  int err;  
  
  buf = (char*) malloc(_CVTBUFSIZE);  
  err = _fcvt_s(buf, _CVTBUFSIZE, 1.2, 5, &decimal, &sign);  
  
  if (err != 0)  
  {  
     printf("_fcvt_s failed with error code %d\n", err);  
     exit(1);  
  }  
  
  printf("Converted value: %s\n", buf);    
  
}  
```  
  
```Output  
Converted value: 120000  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 <xref:System.Convert.ToString%2A>  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [_ecvt_s](../../c-runtime-library/reference/ecvt-s.md)   
 [_gcvt_s](../../c-runtime-library/reference/gcvt-s.md)   
 [_fcvt](../../c-runtime-library/reference/fcvt.md)
