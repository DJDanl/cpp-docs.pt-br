---
title: _get_tzname | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _get_tzname
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
- _get_tzname
- get_tzname
dev_langs:
- C++
helpviewer_keywords:
- _get_tzname function
- time zones
- get_tzname function
ms.assetid: df0065ff-095f-4237-832c-2fe9ab913875
caps.latest.revision: 18
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
ms.openlocfilehash: 2a7712c311c5007b2d50578d78452d6c989a7ad1
ms.lasthandoff: 02/25/2017

---
# <a name="gettzname"></a>_get_tzname
Recupera a representação da cadeia de caracteres do nome do fuso horário ou do nome do fuso horário com horário de verão (DST).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _get_tzname(  
    size_t* pReturnValue,  
    char* timeZoneName,  
    size_t sizeInBytes,  
    int index      
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 O tamanho da cadeia de caracteres de `timeZoneName`, incluindo um terminador NULL.  
  
 [out] `timeZoneName`  
 O endereço de uma cadeia de caracteres para a representação do nome do fuso horário ou do nome do fuso horário com horário de verão (DST), dependendo de `index`.  
  
 [in] `sizeInBytes`  
 O tamanho da cadeia de caracteres de `timeZoneName` em bytes.  
  
 [in] `index`  
 O índice de um dos dois nomes de fuso horário a serem recuperados.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; caso contrário, um valor de tipo `errno`.  
  
 Se `timeZoneName` for `NULL` ou se `sizeInBytes` for zero ou menos que zero (mas não ambos), o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EINVAL`.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`pReturnValue`|`timeZoneName`|`sizeInBytes`|`index`|Valor retornado|Conteúdo de `timeZoneName`|  
|--------------------|--------------------|-------------------|-------------|------------------|--------------------------------|  
|tamanho do nome do FH|`NULL`|0|0 ou 1|0|não modificado|  
|tamanho do nome do FH|qualquer|> 0|0 ou 1|0|Nome do FH|  
|não modificado|`NULL`|> 0|qualquer|`EINVAL`|não modificado|  
|não modificado|qualquer|zero|qualquer|`EINVAL`|não modificado|  
|não modificado|qualquer|> 0|> 1|`EINVAL`|não modificado|  
  
## <a name="remarks"></a>Comentários  
 A função `_get_tzname` recupera a representação da cadeia de caracteres do nome do fuso horário ou do nome do fuso horário com horário de verão (DST) no endereço de `timeZoneName` dependendo do valor do índice, juntamente com o tamanho da cadeia de caracteres em `pReturnValue`. Se `timeZoneName` for `NULL` e `sizeInBytes` for zero, apenas o tamanho da cadeia de caracteres de um dos fusos horários em bytes será retornado em `pReturnValue`. Os valores de índice devem ser 0 para o fuso horário padrão ou 1 para o fuso horário com horário de verão; todos os outros valores de índice têm resultados indeterminados.  
  
### <a name="index-values"></a>Valores de índice  
  
|`index`|Conteúdo de `timeZoneName`|Valor padrão `timeZoneName`|  
|-------------|--------------------------------|----------------------------------|  
|0|Nome do fuso horário|"PST"|  
|1|O nome do fuso horário com horário de verão|"PDT"|  
|> 1 ou < 0|`errno` definido como `EINVAL`|não modificado|  
  
 A menos que os valores sejam alterados explicitamente durante o tempo de execução, os valores padrão serão "PST" e "PDT" respectivamente.  Os tamanhos dessas matrizes de caracteres são governados pelo valor `TZNAME_MAX`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_tzname`|\<time.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)   
 [_get_daylight](../../c-runtime-library/reference/get-daylight.md)   
 [_get_dstbias](../../c-runtime-library/reference/get-dstbias.md)   
 [_get_timezone](../../c-runtime-library/reference/get-timezone.md)   
 [TZNAME_MAX](../../c-runtime-library/tzname-max.md)
