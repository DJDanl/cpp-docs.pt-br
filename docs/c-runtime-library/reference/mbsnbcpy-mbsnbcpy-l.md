---
title: _mbsnbcpy, _mbsnbcpy_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsnbcpy
- _mbsnbcpy_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- mbsnbcpy
- _ftcsncpy
- _mbsnbcpy
- mbsnbcpy_l
- _mbsnbcpy_l
dev_langs:
- C++
helpviewer_keywords:
- mbsnbcpy function
- _mbsnbcpy_l function
- _mbsnbcpy function
- _tcsncpy function
- tcsncpy_l function
- _tcsncpy_l function
- mbsnbcpy_l function
- tcsncpy function
ms.assetid: 83d17b50-3cbf-4df9-bce8-3b6d52f85d04
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
ms.openlocfilehash: c5587c8a87c8d6759d974e7f2844ea00040e7e43
ms.lasthandoff: 02/25/2017

---
# <a name="mbsnbcpy-mbsnbcpyl"></a>_mbsnbcpy, _mbsnbcpy_l
Copia `n` bytes de uma cadeia de caracteres para uma cadeia de caracteres de destino. Versões mais seguras dessas funções estão disponíveis, consulte [_mbsnbcpy_s, _mbsnbcpy_s_l](../../c-runtime-library/reference/mbsnbcpy-s-mbsnbcpy-s-l.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/en-us/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char * _mbsnbcpy(  
   unsigned char * strDest,  
   const unsigned char * strSource,  
   size_t count  
);  
unsigned char * _mbsnbcpy_l(  
   unsigned char * strDest,  
   const unsigned char * strSource,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
unsigned char * _mbsnbcpy(  
   unsigned char (&strDest)[size],  
   const unsigned char * strSource,  
   size_t count  
); // C++ only  
template <size_t size>  
unsigned char * _mbsnbcpy_l(  
   unsigned char (&strDest)[size],  
   const unsigned char * strSource,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strDest`  
 Destino para a cadeia de caracteres a ser copiada.  
  
 `strSource`  
 Cadeia de caracteres a ser copiada.  
  
 `count`  
 Número de bytes a serem copiados.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 `_mbsnbcpy` retorna um ponteiro para a cadeia de caracteres de destino. Nenhum valor retornado é reservado para indicar um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_mbsnbcpy` copia `count` bytes de `strSource` para `strDest`. Se `count` excede o tamanho de `strDest` ou as cadeias de caracteres de origem e de destino se sobrepõem, o comportamento de `_mbsnbcpy` é indefinido.  
  
 Se `strSource` ou `strDest` for um ponteiro nulo, a função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que aquelas que não têm o sufixo `_l` usam a localidade atual e as versões com um sufixo `_l` usam o parâmetro de localidade informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
> [!IMPORTANT]
>  Essas funções podem ser vulneráveis a ameaças de estouro de buffer. As saturações de buffer podem ser usadas para executar código arbitrário do invasor, que pode resultar na elevação de privilégio sem garantia e comprometer o sistema. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
 Em C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais recentes e mais seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsncpy`|[strncpy](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)|`_mbsnbcpy`|[wcsncpy](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)|  
|`_tcsncpy_l`|`_strncpy_l`|`_mbsnbcp_l`|`_wcsncpy_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsnbcpy`|\<mbstring.h>|  
|`_mbsnbcpy_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [_mbsnbcat, _mbsnbcat_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [_mbsnbcmp, _mbsnbcmp_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](../../c-runtime-library/reference/strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)   
 [_mbsnbset, _mbsnbset_l](../../c-runtime-library/reference/mbsnbset-mbsnbset-l.md)   
 [strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)
