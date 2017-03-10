---
title: _gcvt_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _gcvt_s
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
- _gcvt_s
- gcvt_s
dev_langs:
- C++
helpviewer_keywords:
- _gcvt_s function
- _CVTBUFSIZE
- floating-point functions, converting number to string
- gcvt_s function
- numbers, converting to strings
- conversions, floating point to strings
- strings [C++], converting from floating point
- CVTBUFSIZE
ms.assetid: 0a8d8a26-5940-4ae3-835e-0aa6ec1b0744
caps.latest.revision: 30
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
ms.openlocfilehash: fc877f908befaef3daa004e9d9fbc475ff95212d
ms.lasthandoff: 02/25/2017

---
# <a name="gcvts"></a>_gcvt_s
Converte um valor de ponto flutuante em uma cadeia de caracteres. Trata-se de uma versão de [_gcvt](../../c-runtime-library/reference/gcvt.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _gcvt_s(   
   char *buffer,  
   size_t sizeInBytes,  
   double value,  
   int digits   
);  
template <size_t cchStr>  
errno_t _gcvt_s(   
   char (&buffer)[cchStr],  
   double value,  
   int digits   
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `buffer`  
 Buffer para armazenar o resultado da conversão.  
  
 [in] `sizeInBytes`  
 O tamanho do buffer.  
  
 [in] `value`  
 Valor a ser convertido.  
  
 [in] `digits`  
 Número de dígitos significativos armazenados.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido. Se ocorrer uma falha devido a um parâmetro inválido (consulte na tabela a seguir os valores inválidos), o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, um código de erro será retornado. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`buffer`|`sizeInBytes`|`value`|`digits`|Valor de|Valor em `buffer`|  
|--------------|-------------------|-------------|--------------|------------|-----------------------|  
|`NULL`|qualquer|qualquer|qualquer|`EINVAL`|Não modificado.|  
|Não é `NULL` (aponta para a memória válida)|zero|qualquer|qualquer|`EINVAL`|Não modificado.|  
|Não é `NULL` (aponta para a memória válida)|qualquer|qualquer|>= `sizeInBytes`|`EINVAL`|Não modificado.|  
  
 **Problemas de segurança**  
  
 `_gcvt_s` pode gerar uma violação de acesso se `buffer` não apontar para memória válida e não for `NULL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_gcvt_s` converte um `value` de ponto flutuante em uma cadeia de caracteres (que inclui um ponto decimal e um possível byte de sinal) e armazena a cadeia de caracteres em `buffer`. `buffer` deve ser grande o suficiente para acomodar o valor convertido e um caractere nulo de terminação, que é acrescentado automaticamente. Um buffer de tamanho `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante. Se um tamanho do buffer de `digits` + 1 for usado, a função não substituirá o fim do buffer, sendo assim, forneça um buffer suficiente para esta operação. `_gcvt_s` tenta gerar dígitos `digits` no formato decimal. Se não for possível, ele produzirá dígitos `digits` no formato exponencial. Zeros à direita podem ser suprimidos na conversão.  
  
 No C++, o uso dessa função é simplificado por uma sobrecarga de modelo. A sobrecarga pode inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 A versão de depuração dessa função preenche primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_gcvt_s`|\<stdlib.h>|\<error.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_gcvt_s.c  
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
  
int main()  
{  
  char buf[_CVTBUFSIZE];  
  int decimal;  
  int sign;  
  int err;  
  
  err = _gcvt_s(buf, _CVTBUFSIZE, 1.2, 5);  
  
  if (err != 0)  
  {  
     printf("_gcvt_s failed with error code %d\n", err);  
     exit(1);  
  }  
  
  printf("Converted value: %s\n", buf);    
  
}  
```  
  
```Output  
Converted value: 1.2  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 <xref:System.Convert.ToString%2A>  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, _atof_l, _wtof, _wtof_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [_ecvt_s](../../c-runtime-library/reference/ecvt-s.md)   
 [_fcvt_s](../../c-runtime-library/reference/fcvt-s.md)   
 [_gcvt](../../c-runtime-library/reference/gcvt.md)
