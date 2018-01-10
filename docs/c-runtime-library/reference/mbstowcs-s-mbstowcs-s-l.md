---
title: mbstowcs_s, _mbstowcs_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbstowcs_s_l
- mbstowcs_s
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
- _mbstowcs_s_l
- mbstowcs_s
dev_langs: C++
helpviewer_keywords:
- _mbstowcs_s_l function
- mbstowcs_s function
- mbstowcs_s_l function
ms.assetid: 2fbda953-6918-498f-b440-3e7b21ed65a4
caps.latest.revision: "31"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 822a7058afd6588be6f953c5c2b89d41ec02c87f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mbstowcss-mbstowcssl"></a>mbstowcs_s, _mbstowcs_s_l
Converte uma sequência de caracteres multibyte em uma sequência de caracteres largos correspondente. As versões de [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t mbstowcs_s(  
   size_t *pReturnValue,  
   wchar_t *wcstr,  
   size_t sizeInWords,  
   const char *mbstr,  
   size_t count   
);  
errno_t _mbstowcs_s_l(  
   size_t *pReturnValue,  
   wchar_t *wcstr,  
   size_t sizeInWords,  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
errno_t mbstowcs_s(  
   size_t *pReturnValue,  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count   
); // C++ only  
template <size_t size>  
errno_t _mbstowcs_s_l(  
   size_t *pReturnValue,  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 O número de caracteres convertidos.  
  
 [out] `wcstr`  
 Endereço do buffer para a cadeia de caracteres largos convertida resultante.  
  
 [in] `sizeInWords`  
 O tamanho do buffer `wcstr` em palavras.  
  
 [in]`mbstr`  
 O endereço de uma sequência de caracteres multibyte terminadas por nulo.  
  
 [in] `count`  
 O número máximo de caracteres largos a serem armazenados no buffer `wcstr`, não incluindo o caractere nulo de terminação ou [_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 [in] `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido ou um código de erro em caso de falha.  
  
|Condição de erro|Valor retornado e `errno`|  
|---------------------|------------------------------|  
|`wcstr` é `NULL` e `sizeInWords` > 0|`EINVAL`|  
|`mbstr` é `NULL`|`EINVAL`|  
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que `count` seja `_TRUNCATE`; consulte Comentários abaixo)|`ERANGE`|  
|`wcstr` não é `NULL` e `sizeInWords` == 0|`EINVAL`|  
  
 Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará um código de erro e definirá `errno` conforme indicado na tabela.  
  
## <a name="remarks"></a>Comentários  
 A função `mbstowcs_s` converte uma cadeia de caracteres multibyte apontada por `mbstr` em caracteres largos armazenados no buffer apontado por `wcstr`. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:  
  
-   Um caractere nulo multibyte é encontrado  
  
-   Um caractere multibyte inválido é encontrado  
  
-   O número de caracteres largos armazenados no buffer `wcstr` é igual a `count`.  
  
 A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).  
  
 Se `count` for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), `mbstowcs_s` converterá o máximo da cadeia de caracteres que caberá no buffer de destino ainda deixando espaço para um terminador nulo.  
  
 Se `mbstowcs_s` converter com êxito a cadeia de caracteres de origem, ele colocará o tamanho em caracteres largos da cadeia de caracteres convertida, incluindo o terminador nulo, em `*pReturnValue` (desde que `pReturnValue` não seja `NULL`). Isso ocorrerá mesmo se o argumento `wcstr` for `NULL` e fornecerá uma maneira de determinar o tamanho do buffer necessário. Observe que se `wcstr` for `NULL`, `count` será ignorado e `sizeInWords` deve ser 0.  
  
 Se `mbstowcs_s` encontrar um caractere multibyte inválido, ele colocará 0 em `*pReturnValue`, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá `errno` como `EILSEQ`e retornará `EILSEQ`.  
  
 Se as sequências apontadas por `mbstr` e por `wcstr` se sobrepuserem, o comportamento de `mbstowcs_s` será indefinido.  
  
> [!IMPORTANT]
>  Verifique se `wcstr` e `mbstr` não se sobrepõem e se `count` reflete corretamente o número de caracteres multibyte a ser convertido.  
  
 `mbstowcs_s` usa a localidade atual de qualquer comportamento dependente da localidade; `_mbstowcs_s_l` é idêntico, exceto pelo fato de que ele usa a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`mbstowcs_s`|\<stdlib.h>|  
|`_mbstowcs_s_l`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)