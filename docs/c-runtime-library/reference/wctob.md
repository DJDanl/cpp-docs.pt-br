---
title: wctob | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- wctob
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
- wctob
dev_langs:
- C++
helpviewer_keywords:
- wide characters, converting
- wctob function
- characters, converting
ms.assetid: 46aec98b-c2f2-4e9d-9d89-7db99ba8a9a6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2534eb98c39be91ed753fdc0ff286a9a5c5ce707
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="wctob"></a>wctob
Determina se um caractere largo corresponde a um caractere multibyte e retorna sua representação de caracteres multibyte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int wctob(  
   wint_t wchar  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `wchar`  
 A valor a ser movido.  
  
## <a name="return-value"></a>Valor de retorno  
 Se `wctob` converter com êxito um caractere largo, ele retornará sua representação de caracteres multibyte somente se o tamanho do caractere multibyte for exatamente um byte. Se `wctob` encontra um caractere largo não pode converter um caractere multibyte ou os caracteres multibyte não é exatamente um byte longo, ele retorna -1.  
  
## <a name="remarks"></a>Comentários  
 A função `wctob` converterá um caractere largo contido em `wchar` no caractere multibyte correspondente passado pelo valor retornado `int` se o tamanho do caractere multibyte for exatamente um byte.  
  
 Se `wctob` não for bem-sucedido e nenhum caractere multibyte correspondente for encontrado, a função definirá `errno` como `EILSEQ` e retornará –1.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`wctob`|\<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Este programa ilustra o comportamento da função `wcstombs`.  
  
```  
// crt_wctob.c  
#include <stdio.h>  
#include <wchar.h>  
  
int main( void )  
{  
    int     bChar = 0;  
    wint_t  wChar = 0;  
  
    // Set the corresponding wide character to exactly one byte.  
    wChar = (wint_t)'A';  
  
    bChar = wctob( wChar );  
    if (bChar == WEOF)  
    {  
        printf( "No corresponding multibyte character was found.\n");  
    }  
    else  
    {  
        printf( "Determined the corresponding multibyte character to"  
                " be \"%c\".\n", bChar);  
    }  
}  
  
```  
  
```Output  
Determined the corresponding multibyte character to be "A".  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)