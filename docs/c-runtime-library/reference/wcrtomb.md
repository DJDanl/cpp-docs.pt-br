---
title: wcrtomb | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- wcrtomb
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
- wcrtomb
dev_langs:
- C++
helpviewer_keywords:
- wide characters, converting
- wcrtomb function
- multibyte characters
- characters, converting
ms.assetid: 717f1b21-2705-4b7f-b6d0-82adc5224340
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 203b3ec1d72b7691aa8e46d60784100c0bf89a5e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="wcrtomb"></a>wcrtomb
Converta um caractere largo em sua representação de caracteres multibyte. Uma versão mais segura dessa função está disponível; consulte [wcrtomb_s](../../c-runtime-library/reference/wcrtomb-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t wcrtomb(  
   char *mbchar,  
   wchar_t wchar,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t wcrtomb(  
   char (&mbchar)[size],  
   wchar_t wchar,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `mbchar`  
 O caractere multibyte convertido resultante.  
  
 [in] `wchar`  
 Um caractere largo a ser convertido.  
  
 [in] `mbstate`  
 Um ponteiro para um objeto `mbstate_t`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o número de bytes necessários para representar o caractere multibyte convertido, caso contrário, retorna –1 em caso de erro.  
  
## <a name="remarks"></a>Comentários  
 A função `wcrtomb` converte um caractere largo que começa no estado da conversão especificado contido em `mbstate`, com base no valor contido em `wchar`, no endereço representado por `mbchar`. O valor retornado é o número de bytes necessário para representar o caractere multibyte correspondente, mas não retornará mais de `MB_CUR_MAX` bytes.  
  
 Se `mbstate` for nulo, o objeto `mbstate_t` interno contendo o estado da conversão de `mbchar` será usado. Se a sequência de caracteres `wchar` não tiver nenhuma representação de caracteres multibyte correspondente, –1 será retornado e `errno` será definido como `EILSEQ`.  
  
 A função `wcrtomb` difere de [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria `wcsrlen` em vez de `wcsnlen` se uma chamada subsequente a `wcsrtombs` fosse usada em vez de `wcstombs`.  
  
 Em C++, essa função tem uma sobrecarga de modelo que invoca os equivalentes mais recentes e seguros dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `wcrtomb` será multithread-safe contanto que nenhuma função no thread atual chame `setlocale` enquanto essa função estiver em execução e o `mbstate` for nulo.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_wcrtomb.c  
// compile with: /W3  
// This program converts a wide character  
// to its corresponding multibyte character.  
  
#include <string.h>  
#include <stdio.h>  
#include <wchar.h>  
  
int main( void )  
{  
    size_t      sizeOfCovertion = 0;  
    mbstate_t   mbstate;  
    char        mbStr = 0;  
    wchar_t*    wcStr = L"Q";  
  
    // Reset to initial conversion state  
    memset(&mbstate, 0, sizeof(mbstate));  
  
    sizeOfCovertion = wcrtomb(&mbStr, *wcStr, &mbstate); // C4996  
    // Note: wcrtomb is deprecated; consider using wcrtomb_s instead  
    if (sizeOfCovertion > 0)  
    {  
        printf("The corresponding wide character \"");  
        wprintf(L"%s\"", wcStr);  
        printf(" was converted to the \"%c\" ", mbStr);  
        printf("multibyte character.\n");  
    }  
    else  
    {  
        printf("No corresponding multibyte character "  
               "was found.\n");  
    }  
}  
```  
  
```Output  
The corresponding wide character "Q" was converted to the "Q" multibyte character.  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wcrtomb`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)