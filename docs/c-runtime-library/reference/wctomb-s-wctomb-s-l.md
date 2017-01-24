---
title: "wctomb_s, _wctomb_s_l | Microsoft Docs"
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
  - "_wctomb_s_l"
  - "wctomb_s"
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
  - "wctomb_s"
  - "_wctomb_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _wctomb_s_l"
  - "caracteres, convertendo"
  - "conversão de cadeia de caracteres, cadeias de caracteres multibyte"
  - "conversão de cadeia de caracteres, caracteres largos"
  - "Função wctomb_s"
  - "Função wctomb_s_l"
  - "caracteres largos, convertendo"
ms.assetid: 7e94a888-deed-4dbd-b5e9-d4a0455538b8
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wctomb_s, _wctomb_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um caractere largo em caracteres multibyte correspondente.  Uma versão de [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t wctomb_s(  
   int *pRetValue,  
   char *mbchar,  
   size_t sizeInBytes,  
   wchar_t wchar   
);  
errno_t _wctomb_s_l(  
   int *pRetValue,  
   char *mbchar,  
   size_t sizeInBytes,  
   wchar_t wchar,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 \[saída\] `pRetValue`  
 O número de bytes, ou um código que indica o resultado.  
  
 \[saída\] `mbchar`  
 O endereço de um caracteres multibyte.  
  
 \[entrada\] `sizeInBytes`  
 Tamanho do buffer `mbchar`.  
  
 \[entrada\] `wchar`  
 Um caractere largo.  
  
 \[entrada\] `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Zero se tiver êxito, um código de erro ou falha.  
  
 Condições de erro  
  
|`mbchar`|`sizeInBytes`|Valor de retorno|`pRetValue`|  
|--------------|-------------------|----------------------|-----------------|  
|`NULL`|\>0|`EINVAL`|não modificado|  
|any|\>`INT_MAX`|`EINVAL`|não modificado|  
|any|muito pequeno|`EINVAL`|não modificado|  
  
 Se qualquer uma das condições de erro acima ocorrerem, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar,`wctomb` retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
## Comentários  
 A função de `wctomb_s` converte seu argumento de `wchar` correspondente em caracteres multibyte e armazena o resultado em `mbchar`.  Você pode chamar a função de qualquer ponto em qualquer programa.  
  
 Se `wctomb_s` converte o caractere largo a um caracteres multibyte, coloca o número de bytes \(que nunca é maior que `MB_CUR_MAX`\) em caractere largo em inteiro apontado por `pRetValue`.  Se `wchar` é o caractere nulo ampla de caracteres \(L \\ 0 '\), `wctomb_s` preenche `pRetValue` com 1.  Se o ponteiro `mbchar` de destino for NULL, `wctomb_s` coloca 0 em `pRetValue`.  Se a conversão não é possível na localidade atual, `wctomb_s` coloca – 1 em `pRetValue`.  
  
 `wctomb_s` usa a localidade atual para as informações de localidade dependente; `_wctomb_s_l` é idêntico exceto que usa a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wctomb_s`|\<stdlib.h\>|  
|`_wctomb_s_l`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Esse programa ilustra o comportamento da função de `wctomb` .  
  
```  
// crt_wctomb_s.cpp  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
    int i;  
    wchar_t wc = L'a';  
    char *pmb = (char *)malloc( MB_CUR_MAX );  
  
    printf_s( "Convert a wide character:\n" );  
    wctomb_s( &i, pmb, MB_CUR_MAX, wc );  
    printf_s( "   Characters converted: %u\n", i );  
    printf_s( "   Multibyte character: %.1s\n\n", pmb );  
}  
```  
  
  **Converter um caractere largo:**  
 **Caracteres convertidos: 1**  
 **Caractere de Multibyte: a**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbstowcs, \_mbstowcs\_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)