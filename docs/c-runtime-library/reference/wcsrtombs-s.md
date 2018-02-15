---
title: wcsrtombs_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- wcsrtombs_s
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
- wcsrtombs_s
dev_langs:
- C++
helpviewer_keywords:
- string conversion, wide characters
- wcsrtombs_s function
- wide characters, strings
ms.assetid: 9dccb766-113c-44bb-9b04-07a634dddec8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0bb43cf628abfabe7b5900579ec6995c95c980b2
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="wcsrtombss"></a>wcsrtombs_s
Converte uma cadeia de caracteres largos em sua representação de cadeia de caracteres multibyte. Uma versão de [wcsrtombs](../../c-runtime-library/reference/wcsrtombs.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t wcsrtombs_s(  
   size_t *pReturnValue,  
   char *mbstr,  
   size_t sizeInBytes,  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
errno_t wcsrtombs_s(  
   size_t *pReturnValue,  
   char (&mbstr)[size],  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 O número de caracteres convertidos.  
  
 [out] `mbstr`  
 O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.  
  
 [out] `sizeInBytes`  
 O tamanho em bytes do buffer `mbstr`.  
  
 [in] `wcstr`  
 Aponta para a cadeia de caracteres largos a ser convertida.  
  
 [in] `count`  
 O número máximo de bytes a ser armazenado no buffer `mbstr` ou em [_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 [in] `mbstate`  
 Um ponteiro para um objeto do estado da conversão `mbstate_t`.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido ou um código de erro em caso de falha.  
  
|Condição de erro|Valor retornado e `errno`|  
|---------------------|------------------------------|  
|`mbstr` é `NULL` e `sizeInBytes` > 0|`EINVAL`|  
|`wcstr` é `NULL`|`EINVAL`|  
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que `count` seja `_TRUNCATE`; consulte Comentários abaixo)|`ERANGE`|  
  
 Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará um código de erro e definirá `errno` conforme indicado na tabela.  
  
## <a name="remarks"></a>Comentários  
 A função `wcsrtombs_s` converte uma cadeia de caracteres largos apontada por `wcstr` em caracteres multibyte armazenados no buffer apontado por `mbstr` usando o estado da conversão contido em `mbstate`. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:  
  
-   Um caractere largo nulo é encontrado  
  
-   Um caractere largo que não pode ser convertido é encontrado  
  
-   O número de bytes armazenados no buffer `mbstr` é igual a `count`.  
  
 A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).  
  
 Se `count` for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), `wcsrtombs_s` converterá o máximo da cadeia de caracteres que caberá no buffer de destino ainda deixando espaço para um terminador nulo.  
  
 Se `wcsrtombs_s` converter com êxito a cadeia de caracteres de origem, ele colocará o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em `*pReturnValue` (desde que `pReturnValue` não seja `NULL`). Isso ocorrerá mesmo se o argumento `mbstr` for `NULL` e fornecerá uma maneira de determinar o tamanho do buffer necessário. Observe que se `mbstr` for `NULL`, `count` será ignorado.  
  
 Se `wcsrtombs_s` encontrar um caractere largo que não seja possível converter em um caractere multibyte, ele colocará –1 em `*pReturnValue`, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá `errno` como `EILSEQ` e retornará `EILSEQ`.  
  
 Se as sequências apontadas por `wcstr` e por `mbstr` se sobrepuserem, o comportamento de `wcsrtombs_s` será indefinido. `wcsrtombs_s` é afetado pela categoria LC_TYPE da localidade atual.  
  
> [!IMPORTANT]
>  Verifique se `wcstr` e `mbstr` não se sobrepõem e se `count` reflete corretamente o número de caracteres largos a ser convertido.  
  
 A função `wcsrtombs_s` difere de [wcstombs_s, wcstombs_s_l](../../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria `wcsrlen` em vez de `wcslen` se uma chamada subsequente a `wcsrtombs_s` fosse usada em vez de `wcstombs_s.`  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `wcsrtombs_s` será multithread-safe contanto que nenhuma função no thread atual chame `setlocale` enquanto essa função estiver em execução e o `mbstate` for nulo.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_wcsrtombs_s.cpp  
//   
// This code example converts a wide  
// character string into a multibyte  
// character string.  
//  
  
#include <stdio.h>  
#include <memory.h>  
#include <wchar.h>  
#include <errno.h>  
  
#define MB_BUFFER_SIZE 100  
  
void main()  
{  
    const wchar_t   wcString[] =   
                    {L"Every good boy does fine."};  
    const wchar_t   *wcsIndirectString = wcString;  
    char            mbString[MB_BUFFER_SIZE];  
    size_t          countConverted;  
    errno_t         err;  
    mbstate_t       mbstate;  
  
    // Reset to initial shift state  
    ::memset((void*)&mbstate, 0, sizeof(mbstate));  
  
    err = wcsrtombs_s(&countConverted, mbString, MB_BUFFER_SIZE,  
                      &wcsIndirectString, MB_BUFFER_SIZE, &mbstate);  
    if (err == EILSEQ)  
    {  
        printf( "An encoding error was detected in the string.\n" );  
    }  
    else   
    {  
        printf( "The string was successfully converted.\n" );  
    }  
}  
```  
  
```Output  
The string was successfully converted.  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcsrtombs_s`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [wcrtomb](../../c-runtime-library/reference/wcrtomb.md)   
 [wcrtomb_s](../../c-runtime-library/reference/wcrtomb-s.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)