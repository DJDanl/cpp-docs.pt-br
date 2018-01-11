---
title: _mbsnbcat_s, _mbsnbcat_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsnbcat_s_l
- _mbsnbcat_s
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
- _mbsnbcat_s
- mbsnbcat_s
- _mbsnbcat_s_l
- mbsnbcat_s_l
dev_langs: C++
helpviewer_keywords:
- _tcsncat function
- mbsnbcat_s function
- _mbsnbcat_s function
- _mbsnbcat_s_l function
- _tcsncat_s_l function
- tcsncat_s_l function
- mbsnbcat_s_l function
- tcsncat function
ms.assetid: 2c9e9be7-d979-4a54-8ada-23428b6648a9
caps.latest.revision: "28"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7288c00de4f09175d7fffd816267201011892953
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mbsnbcats-mbsnbcatsl"></a>_mbsnbcat_s, _mbsnbcat_s_l
Acrescenta a uma cadeia de caracteres multibyte, no máximo, os primeiros `n` bytes de outra cadeia de caracteres multibyte. Essas são versões de [_mbsnbcat, _mbsnbcat_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md), mas têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _mbsnbcat_s(  
   unsigned char *dest,  
   size_t sizeInBytes,  
   const unsigned char *src,  
   size_t count   
);  
errno_t _mbsnbcat_s_l(  
   unsigned char *dest,  
   size_t sizeInBytes,  
   const unsigned char *src,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
errno_t _mbsnbcat_s(  
   unsigned char (&dest)[size],  
   const unsigned char *src,  
   size_t count   
); // C++ only  
template <size_t size>  
errno_t _mbsnbcat_s_l(  
   unsigned char (&dest)[size],  
   const unsigned char *src,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dest`  
 Cadeia de caracteres de destino de caractere multibyte terminada em nulo.  
  
 `sizeInBytes`  
 O tamanho do buffer `dest` em bytes.  
  
 `src`  
 Cadeia de caracteres de origem de caractere multibyte terminada em nulo.  
  
 `Count`  
 Número de bytes do `src` para acrescentar a `dest`.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido, caso contrário, um código de erro.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`Dest`|`sizeInBytes`|`src`|Valor retornado|  
|------------|-------------------|-----------|------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|  
|Qualquer|<= 0|qualquer|`EINVAL`|  
|Qualquer|qualquer|`NULL`|`EINVAL`|  
  
 Se qualquer uma das condições de erro ocorrer, a função gerará um erro de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_mbsnbcat_s` acrescenta a `dest`, no máximo, os primeiros `count` bytes de `src`. Se o byte imediatamente antes do caractere nulo em `dest` for um byte inicial, ele será substituído pelo byte inicial de `src`. Caso contrário, o byte inicial de `src` substitui o caractere nulo de terminação de `dest`. Se aparecer um byte nulo no `src` antes de `count` bytes serem acrescentados, `_mbsnbcat_s` acrescentará todos os bytes de `src`, até o caractere nulo. Se `count` for maior que o comprimento de `src`, o comprimento de `src` será usado no lugar de `count`. A cadeia de caracteres resultante é terminada por um caractere nulo. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que aquelas que não têm o sufixo `_l` usam a localidade atual e as com um sufixo `_l` usam o parâmetro de localidade informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 No C++, o uso dessas funções é simplificado por sobrecargas de modelo, as sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem usar automaticamente suas funções mais novas e mais seguras para substituir funções mais antigas e menos seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsncat`|[strncat](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|`_mbsnbcat_s`|[wcsncat](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|  
|`_tcsncat_s_l`|`_strncat_s_l`|`_mbsnbcat_s_l`|`_wcsncat_s_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsnbcat_s`|\<mbstring.h>|  
|`_mbsnbcat_s_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [_mbsnbcmp, _mbsnbcmp_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](../../c-runtime-library/reference/strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)   
 [_mbsnbcpy, _mbsnbcpy_l](../../c-runtime-library/reference/mbsnbcpy-mbsnbcpy-l.md)   
 [_mbsnbcpy_s, _mbsnbcpy_s_l](../../c-runtime-library/reference/mbsnbcpy-s-mbsnbcpy-s-l.md)   
 [_mbsnbset, _mbsnbset_l](../../c-runtime-library/reference/mbsnbset-mbsnbset-l.md)   
 [strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](../../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)