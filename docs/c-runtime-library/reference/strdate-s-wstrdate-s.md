---
title: _strdate_s, _wstrdate_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _strdate_s
- _wstrdate_s
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _strdate_s
- wstrdate_s
- _wstrdate_s
- strdate_s
- _tstrdate_s
dev_langs:
- C++
helpviewer_keywords:
- dates, copying
- tstrdate_s function
- wstrdate_s function
- _tstrdate_s function
- strdate_s function
- copying dates
- _strdate_s function
- _wstrdate_s function
ms.assetid: d41d8ea9-e5ce-40d4-864e-1ac29b455991
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 5b1701f41b2f66ccbc2601763c09a4db0523c2ed
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="strdates-wstrdates"></a>_strdate_s, _wstrdate_s
Copie a data atual do sistema para um buffer. Estas são versões de [_strdate, _wstrdate](../../c-runtime-library/reference/strdate-wstrdate.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _strdate_s(  
   char *buffer,  
   size_t numberOfElements  
);  
errno_t _wstrdate_s(  
   wchar_t *buffer,  
   size_t numberOfElements  
);  
template <size_t size>  
errno_t _strdate_s(  
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
errno_t _wstrdate_s(  
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `buffer`  
 Um ponteiro para um buffer que será preenchido com a cadeia de caracteres de data formatada.  
  
 [in] `numberOfElements`  
 O tamanho do buffer.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em ERRNO.H; consulte a tabela abaixo para os erros exatos gerados por esta função. Para obter mais informações sobre códigos de erro, consulte [errno](../../c-runtime-library/errno-constants.md).  
  
## <a name="error-conditions"></a>Condições de Erro  
  
|`buffer`|`numberOfElements`|Valor de|Conteúdo de `buffer`|  
|--------------|------------------------|------------|--------------------------|  
|`NULL`|(qualquer)|`EINVAL`|Não modificado|  
|Não `NULL` (apontando para o buffer válido)|0|`EINVAL`|Não modificado|  
|Não `NULL` (apontando para o buffer válido)|0 < `numberOfElements` < 9|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL` (apontando para o buffer válido)|`numberOfElements` >= 9|0|Data atual formatada conforme especificado nos comentários|  
  
## <a name="security-issues"></a>Problemas de segurança  
 Passar um valor não `NULL` inválido para o buffer resultará em uma violação de acesso se o parâmetro `numberOfElements` for maior do que 9.  
  
 Passar valores de tamanho maiores do que o tamanho real do `buffer` resultará em estouro de buffer.  
  
## <a name="remarks"></a>Comentários  
 Estas funções fornecem versões mais seguras de `_strdate` e `_wstrdate`. A função `_strdate_s` copia a data atual do sistema para o buffer apontado por `buffer`, formatado como `mm`/`dd`/`yy`, em que `mm` são dois dígitos que representam o mês, `dd` são dois dígitos que representam o dia e `yy` são os dois últimos dígitos do ano. Por exemplo, a cadeia de caracteres `12/05/99` representa 5 de dezembro de 1999. O buffer deve ter, no mínimo, 9 caracteres de comprimento.  
  
 `_wstrdate_s` é uma versão de caractere largo de `_strdate_s`; o argumento e o valor retornado de `_wstrdate_s` são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.  
  
 Se `buffer` for um ponteiro `NULL` ou se `numberOfElements` for menor que 9 caracteres, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` para `EINVAL` se o buffer for `NULL` ou se `numberOfElements` for menor ou igual a 0, sendo que essas funções definirão `errno` para `ERANGE` se `numberOfElements` for menor que 9.  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tstrdate_s`|`_strdate_s`|`_strdate_s`|`_wstrdate_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strdate`|\<time.h>|  
|`_wstrdate`|\<time.h> ou \<wchar.h>|  
|`_strdate_s`|\<time.h>|  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [time](../../c-runtime-library/reference/time-time32-time64.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [mktime, _mktime32, _mktime64](../../c-runtime-library/reference/mktime-mktime32-mktime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [_tzset](../../c-runtime-library/reference/tzset.md)
