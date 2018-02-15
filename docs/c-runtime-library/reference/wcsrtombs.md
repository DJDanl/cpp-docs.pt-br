---
title: wcsrtombs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- wcsrtombs
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
- wcsrtombs
dev_langs:
- C++
helpviewer_keywords:
- wcsrtombs function
- string conversion, wide characters
- wide characters, strings
ms.assetid: a8d21fec-0d36-4085-9d81-9b1c61c7259d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 45dd47ed3c6136c4aff860efd51de18e120803ec
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="wcsrtombs"></a>wcsrtombs
Converte uma cadeia de caracteres largos em sua representação de cadeia de caracteres multibyte. Uma versão mais segura dessa função está disponível; consulte [wcsrtombs_s](../../c-runtime-library/reference/wcsrtombs-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t wcsrtombs(  
   char *mbstr,  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t wcsrtombs(  
   char (&mbstr)[size],  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `mbstr`  
 O local do endereço da cadeia de caracteres multibyte convertida resultante.  
  
 [in] `wcstr`  
 Aponta indiretamente para o local da cadeia de caracteres largos a ser convertida.  
  
 [in] `count`  
 O número de caracteres a ser convertido.  
  
 [in] `mbstate`  
 Um ponteiro para um objeto do estado da conversão `mbstate_t`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o número de bytes convertidos com êxito, não incluindo o byte nulo de terminação nula (se houver), caso contrário, retorna –1 em caso de erro.  
  
## <a name="remarks"></a>Comentários  
 A função `wcsrtombs` converte uma cadeia de caracteres largos que começa no estado da conversão especificado contido em `mbstate`, com base nos valores indiretos apontados em `wcstr`, no endereço de `mbstr`. A conversão continuará para cada caractere até: um caractere largo de terminação nula ser encontrado, um caractere não correspondente ser encontrado ou o próximo caractere exceder o limite contido em `count`. Se `wcsrtombs` encontrar o caractere nulo de caractere largo (L'\0') antes ou quando `count` ocorrer, ele o converterá em um 0 de 8 bits e será interrompido.  
  
 Dessa forma, a cadeia de caracteres multibyte em `mbstr` será terminada em nulo somente se `wcsrtombs` encontrar um caractere nulo de caractere largo durante a conversão. Se as sequências apontadas por `wcstr` e por `mbstr` se sobrepuserem, o comportamento de `wcsrtombs` será indefinido. `wcsrtombs` é afetado pela categoria LC_TYPE da localidade atual.  
  
 A função `wcsrtombs` difere de [wcstombs, wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo usaria `wcsrlen` em vez de `wcsnlen` se uma chamada subsequente a `wcsrtombs` fosse usada em vez de `wcstombs`.  
  
 Se o argumento `mbstr` for `NULL`, `wcsrtombs` retornará o tamanho necessário em bytes da cadeia de caracteres de destino. Se `mbstate` for nulo, o estado da conversão `mbstate_t` interno será usado. Se a sequência de caracteres `wchar` não tiver nenhuma representação de caracteres multibyte correspondente, –1 será retornado e `errno` será definido como `EILSEQ`.  
  
 Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `wcsrtombs` será multithread-safe contanto que nenhuma função no thread atual chame `setlocale` enquanto essa função estiver em execução e o `mbstate` não for nulo.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_wcsrtombs.cpp  
// compile with: /W3  
// This code example converts a wide  
// character string into a multibyte  
// character string.  
  
#include <stdio.h>  
#include <memory.h>  
#include <wchar.h>  
#include <errno.h>  
  
#define MB_BUFFER_SIZE 100  
  
int main()  
{  
    const wchar_t   wcString[] =   
                    {L"Every good boy does fine."};  
    const wchar_t   *wcsIndirectString = wcString;  
    char            mbString[MB_BUFFER_SIZE];  
    size_t          countConverted;  
    mbstate_t       mbstate;  
  
    // Reset to initial shift state  
    ::memset((void*)&mbstate, 0, sizeof(mbstate));  
  
    countConverted = wcsrtombs(mbString, &wcsIndirectString,  
                               MB_BUFFER_SIZE, &mbstate); // C4996  
    // Note: wcsrtombs is deprecated; consider using wcsrtombs_s  
    if (errno == EILSEQ)  
    {  
        printf( "An encoding error was detected in the string.\n" );  
    }  
    else   
    {  
        printf( "The string was successfuly converted.\n" );  
    }  
}  
```  
  
```Output  
The string was successfuly converted.  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcsrtombs`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [wcrtomb](../../c-runtime-library/reference/wcrtomb.md)   
 [wcrtomb_s](../../c-runtime-library/reference/wcrtomb-s.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)