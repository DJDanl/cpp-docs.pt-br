---
title: "mbstowcs, _mbstowcs_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "mbstowcs"
  - "_mbstowcs_l"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbstowcs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbstowcs_l"
  - "Função mbstowcs"
  - "Função mbstowcs_l"
ms.assetid: 96696b27-e068-4eeb-8006-3f7a0546ae6d
caps.latest.revision: 30
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbstowcs, _mbstowcs_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma sequência de caracteres multibyte a uma sequência de caracteres amplos correspondente.  Versões mais seguras dessas funções estão disponíveis; consulte [mbstowcs\_s, \_mbstowcs\_s\_l](../../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md).  
  
## Sintaxe  
  
```  
size_t mbstowcs(  
   wchar_t *wcstr,  
   const char *mbstr,  
   size_t count   
);  
size_t _mbstowcs_l(  
   wchar_t *wcstr,  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
size_t mbstowcs(  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count   
); // C++ only  
template <size_t size>  
size_t _mbstowcs_l(  
   wchar_t (&wcstr)[size],  
   const char *mbstr,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 \[out\] `wcstr`  
 O endereço de uma sequência de caracteres amplos.  
  
 \[in\] `mbstr`  
 O endereço de uma sequência de zero terminou caracteres multibyte.  
  
 \[entrada\] `count`  
 O número máximo de caracteres multibyte a ser convertida.  
  
 \[entrada\] `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Se `mbstowcs` converte a cadeia de caracteres de origem, retorna o número de caracteres convertidos de vários bytes.  Se o argumento de `wcstr` é `NULL`, a função retornará o tamanho necessário \(em caracteres amplos\) da cadeia de caracteres de destino.  Se `mbstowcs` encontrar um caractere inválido multibyte, 1 será retornado.  Se o valor de retorno é `count`, a cadeia de caracteres de ampla caractere nulo não é encerrada.  
  
> [!IMPORTANT]
>  Certifique\-se de que `wcstr` e `mbstr` não se sobrepõem, e que `count` reflete corretamente o número de caracteres multibyte para converter.  
  
## Comentários  
 A função de `mbstowcs` converte até um número máximo de caracteres multibyte de `count` apontados por `mbstr` a uma cadeia de caracteres de corresponder os caracteres largos que são determinados pela localidade atual.  Armazena a cadeia de caracteres resultante ampla de caracteres no endereço representado por `wcstr`*.* O resultado é semelhante a uma série de chamadas a `mbtowc`.  Se `mbstowcs` encontrar o caractere nulo de byte único \(“\\ "\) ou 0 antes ou `count` quando ocorrer, converte o caractere nulo em um caractere nulo ampla de caracteres \(L \\ 0 '\) e paradas.  Portanto a cadeia de caracteres de ampla caractere em `wcstr` tiver terminação apenas se um caractere nulo for encontrado durante a conversão.  Se as sequências apontadas por `wcstr` e a sobreposição de `mbstr` , o comportamento são indefinidas.  
  
 Se o argumento de `wcstr` é `NULL`, `mbstowcs` retorna o número de caracteres largos que resultariam de conversão, não incluindo um terminador nulo.  A cadeia de caracteres de origem deve terminar ser finalizada para que o valor correto ser retornado.  Se você precisar mais da cadeia de caracteres resultante todo terminar de ser concluído, adicione uma ao valor retornado.  
  
 Se o argumento de `mbstr` é `NULL`, ou se `count` é \>`INT_MAX`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução for permitida continuar, o errno está definido como `EINVAL` e a função retorna \-1.  
  
 `mbstowcs` usa a localidade atual para qualquer comportamento dependente de localidade; `_mbstowcs_l` é idêntico exceto que usa a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbstowcs`|\<stdlib.h\>|  
|`_mbstowcs_l`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_mbstowcs.c  
// compile with: /W3  
// illustrates the behavior of the mbstowcs function  
  
#include <stdlib.h>  
#include <stdio.h>  
#include <locale.h>  
  
int main( void )  
{  
    size_t size;  
    int nChar = 2; // number of characters to convert  
    int requiredSize;  
  
    unsigned char    *pmbnull  = NULL;  
    unsigned char    *pmbhello = NULL;  
    char* localeInfo;  
  
    wchar_t *pwchello = L"\x3042\x3043"; // 2 Hiragana characters  
    wchar_t *pwc;  
  
    /* Enable the Japanese locale and codepage */  
    localeInfo = setlocale(LC_ALL, "Japanese_Japan.932");  
    printf("Locale information set to %s\n", localeInfo);  
  
    printf( "Convert to multibyte string:\n" );  
  
    requiredSize = wcstombs( NULL, pwchello, 0); // C4996  
    // Note: wcstombs is deprecated; consider using wcstombs_s  
    printf("  Required Size: %d\n", requiredSize);  
  
    /* Add one to leave room for the null terminator. */  
    pmbhello = (unsigned char *)malloc( requiredSize + 1);  
    if (! pmbhello)  
    {  
        printf("Memory allocation failure.\n");  
        return 1;  
    }  
    size = wcstombs( pmbhello, pwchello, requiredSize + 1); // C4996  
    // Note: wcstombs is deprecated; consider using wcstombs_s  
    if (size == (size_t) (-1))  
    {  
        printf("Couldn't convert string. Code page 932 may"  
                " not be available.\n");  
        return 1;  
    }  
    printf( "  Number of bytes written to multibyte string: %u\n",  
            (unsigned int) size );  
    printf( "  Hex values of the " );  
    printf( " multibyte characters: %#.2x %#.2x %#.2x %#.2x\n",  
            pmbhello[0], pmbhello[1], pmbhello[2], pmbhello[3] );  
    printf( "  Codepage 932 uses 0x81 to 0x9f as lead bytes.\n\n");  
  
    printf( "Convert back to wide-character string:\n" );  
  
    /* Assume we don't know the length of the multibyte string.  
     Get the required size in characters, and allocate enough space. */  
  
    requiredSize = mbstowcs(NULL, pmbhello, 0); // C4996  
    /* Add one to leave room for the NULL terminator */  
    pwc = (wchar_t *)malloc( (requiredSize + 1) * sizeof( wchar_t ));  
    if (! pwc)  
    {  
        printf("Memory allocation failure.\n");  
        return 1;  
    }  
    size = mbstowcs( pwc, pmbhello, requiredSize + 1); // C4996  
    if (size == (size_t) (-1))  
    {  
       printf("Couldn't convert string--invalid multibyte character.\n");  
    }  
    printf( "  Characters converted: %u\n", (unsigned int)size );  
    printf( "  Hex value of first 2" );  
    printf( " wide characters: %#.4x %#.4x\n\n", pwc[0], pwc[1] );  
    free(pwc);  
    free(pmbhello);  
}  
```  
  
  **Informações de localidade definida como Japanese\_Japan.932**  
**Converter a cadeia de caracteres multibyte:**  
 **Tamanho necessário: 4**  
 **Número de bytes gravados na cadeia de caracteres multibyte: 4**  
 **Valores hexadecimais de caracteres multibyte: 0x82 0xa0 0x82 0xa1**  
 **Usa 0x81 de página de código 932 a 0x9f como bytes iniciais.**  
**Converter de volta para a cadeia de caracteres de ampla caractere:**  
 **Caracteres convertidos: 2**  
 **O valor hexadecimal de 2 primeiros caracteres amplos: 0x3042 0x3043**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072)