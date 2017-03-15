---
title: wcstombs_s, _wcstombs_s_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wcstombs_s_l
- wcstombs_s
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
- wcstombs_s
- _wcstombs_s_l
dev_langs:
- C++
helpviewer_keywords:
- wcstombs_s function
- string conversion, wide characters
- wide characters, converting
- _wcstombs_s_l function
- wcstombs_s_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 105f2d33-221a-4f6d-864c-23c1865c42af
caps.latest.revision: 31
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.openlocfilehash: 41775d158213a79debbdb4245fc468694df8646e
ms.lasthandoff: 02/25/2017

---
# <a name="wcstombss-wcstombssl"></a>wcstombs_s, _wcstombs_s_l
Converte uma sequência de caracteres largos em uma sequência de caracteres multibyte correspondente. Uma versão de [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t wcstombs_s(  
   size_t *pReturnValue,  
   char *mbstr,  
   size_t sizeInBytes,  
   const wchar_t *wcstr,  
   size_t count   
);  
errno_t _wcstombs_s_l(  
   size_t *pReturnValue,  
   char *mbstr,  
   size_t sizeInBytes,  
   const wchar_t *wcstr,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
errno_t wcstombs_s(  
   size_t *pReturnValue,  
   char (&mbstr)[size],  
   const wchar_t *wcstr,  
   size_t count   
); // C++ only  
template <size_t size>  
errno_t _wcstombs_s_l(  
   size_t *pReturnValue,  
   char (&mbstr)[size],  
   const wchar_t *wcstr,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 O número de caracteres convertidos.  
  
 [out] `mbstr`  
 O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.  
  
 [in]`sizeInBytes`  
 O tamanho em bytes do buffer `mbstr`.  
  
 [in] `wcstr`  
 Aponta para a cadeia de caracteres largos a ser convertida.  
  
 [in] `count`  
 O número máximo de bytes a ser armazenado no buffer `mbstr`, não incluindo o caractere nulo de terminação ou em [_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 [in] `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido ou um código de erro em caso de falha.  
  
|Condição de erro|Valor retornado e `errno`|  
|---------------------|------------------------------|  
|`mbstr` é `NULL` e `sizeInBytes` > 0|`EINVAL`|  
|`wcstr` é `NULL`|`EINVAL`|  
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que `count` seja `_TRUNCATE`; consulte Comentários abaixo)|`ERANGE`|  
  
 Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará um código de erro e definirá `errno` conforme indicado na tabela.  
  
## <a name="remarks"></a>Comentários  
 A função `wcstombs_s` converte uma cadeia de caracteres largos apontada por `wcstr` em caracteres multibyte armazenados no buffer apontado por `mbstr`. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:  
  
-   Um caractere largo nulo é encontrado  
  
-   Um caractere largo que não pode ser convertido é encontrado  
  
-   O número de bytes armazenados no buffer `mbstr` é igual a `count`.  
  
 A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).  
  
 Se `count` for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), `wcstombs_s` converterá o máximo da cadeia de caracteres que caberá no buffer de destino ainda deixando espaço para um terminador nulo.  
  
 Se `wcstombs_s` converter com êxito a cadeia de caracteres de origem, ele colocará o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em `*``pReturnValue` (desde que `pReturnValue` não seja `NULL`). Isso ocorrerá mesmo se o argumento `mbstr` for `NULL` e fornecerá uma maneira de determinar o tamanho do buffer necessário. Observe que se `mbstr` for `NULL`, `count` será ignorado.  
  
 Se `wcstombs_s` encontrar um caractere largo que não seja possível converter em um caractere multibyte, ele colocará 0 em `*``pReturnValue`, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá `errno` como `EILSEQ` e retornará `EILSEQ`.  
  
 Se as sequências apontadas por `wcstr` e por `mbstr` se sobrepuserem, o comportamento de `wcstombs_s` será indefinido.  
  
> [!IMPORTANT]
>  Verifique se `wcstr` e `mbstr` não se sobrepõem e se `count` reflete corretamente o número de caracteres largos a ser convertido.  
  
 `wcstombs_s` usa a localidade atual de qualquer comportamento dependente da localidade; `_wcstombs_s_l` é idêntico a `wcstombs`, exceto que, em vez disso, ele usa a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcstombs_s`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Este programa ilustra o comportamento da função `wcstombs_s`.  
  
```  
// crt_wcstombs_s.c  
// This example converts a wide character  
// string to a multibyte character string.  
#include <stdio.h>  
#include <stdlib.h>  
#include <assert.h>  
  
#define BUFFER_SIZE 100  
  
int main( void )  
{  
    size_t   i;  
    char      *pMBBuffer = (char *)malloc( BUFFER_SIZE );  
    wchar_t*pWCBuffer = L"Hello, world.";  
  
    printf( "Convert wide-character string:\n" );  
  
    // Conversion  
    wcstombs_s(&i, pMBBuffer, (size_t)BUFFER_SIZE,   
               pWCBuffer, (size_t)BUFFER_SIZE );  
  
    // Output  
    printf("   Characters converted: %u\n", i);  
    printf("    Multibyte character: %s\n\n",  
     pMBBuffer );  
  
    // Free multibyte character buffer  
    if (pMBBuffer)  
    {  
    free(pMBBuffer);  
    }  
}  
```  
  
```Output  
Convert wide-character string:  
   Characters converted: 14  
    Multibyte character: Hello, world.  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [wctomb_s, _wctomb_s_l](../../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)   
 [WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)
