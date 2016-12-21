---
title: "_mbsnbcmp, _mbsnbcmp_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbsnbcmp"
  - "_mbsnbcmp_l"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbsnbcmp"
  - "tcsnbmp"
  - "_mbsnbcmp_l"
  - "mbsnbcmp_l"
  - "_mbsnbcmp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbcmp"
  - "Função _mbsnbcmp_l"
  - "Função _tcsncmp"
  - "Função mbsnbcmp"
  - "Função mbsnbcmp_l"
  - "Função tcsncmp"
ms.assetid: dbc99e50-cf85-4e57-a13f-067591f18ac8
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbcmp, _mbsnbcmp_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara o primeiro `n` bytes de duas cadeias de caracteres multibyte.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _mbsnbcmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsnbcmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 As cadeias de caracteres a ser comparado.  
  
 `count`  
 O número de bytes a ser comparado.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 O valor de retorno indica a ordinal relação entre as subcadeias de caracteres de `string1` e `string`.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`string1` subcadeia de caracteres é menor que `string2` subcadeia de caracteres.|  
|0|`string1` subcadeia de caracteres é idêntica à `string2` subcadeia de caracteres.|  
|\> 0|`string1` subcadeia de caracteres é maior que `string2` subcadeia de caracteres.|  
  
 Em um erro de validação de parâmetro, `_mbsnbcmp` e `_mbsnbcmp_l` retornar `_NLSCMPERROR`, que é definido em \< String. h \> e \< mbstring.h \>.  
  
## Comentários  
 O `_mbsnbcmp` no máximo comparam o primeiro `count` bytes em `string1` e `string2` e retornar um valor que indica a relação entre as subcadeias de caracteres.  `_mbsnbcmp` é uma versão de maiúsculas e minúsculas do `_mbsnbicmp`.  Ao contrário de `_mbsnbcoll`, `_mbsnbcmp` não é afetada pela ordem de agrupamento da localidade.  `_mbsnbcmp` reconhece sequências de caracteres multibyte de acordo com a atual multibyte [página de código](../../c-runtime-library/code-pages.md).  
  
 `_mbsnbcmp` é semelhante a `_mbsncmp`, exceto que `_mbsncmp` compara cadeias de caracteres em vez de bytes.  
  
 O valor de saída é afetado pelo `LC_CTYPE` categoria de configuração de localidade, que especifica o líder de bytes e bytes de caracteres multibyte à direita.  Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  O `_mbsnbcmp` função usa a localidade atual desse comportamento dependente de localidade.  O `_mbsnbcmp_l` função é idêntica, exceto que ele usa o `locale` parâmetro em vez disso.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `string1` ou `string2` é um ponteiro nulo, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções retornam `_NLSCMPERROR` e `errno` é definido como `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|Unicode e MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|----------------------------------|---------------------|------------------------|  
|`_tcsncmp`|[strncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|`_mbsnbcmp`|[wcsncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|  
|`_tcsncmp_l`|[strncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|`_mbsnbcml`|[wcsncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbcmp`|\<mbstring.h\>|  
|`_mbsnbcmp_l`|\<mbstring.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_mbsnbcmp.c  
#include <mbstring.h>  
#include <stdio.h>  
  
char string1[] = "The quick brown dog jumps over the lazy fox";  
char string2[] = "The QUICK brown fox jumps over the lazy dog";  
  
int main( void )  
{  
   char tmp[20];  
   int result;  
   printf( "Compare strings:\n          %s\n", string1 );  
   printf( "          %s\n\n", string2 );  
   printf( "Function: _mbsnbcmp (first 10 characters only)\n" );  
   result = _mbsncmp( string1, string2 , 10 );  
   if( result > 0 )  
      _mbscpy_s( tmp, sizeof(tmp), "greater than" );  
   else if( result < 0 )  
      _mbscpy_s( tmp, sizeof(tmp), "less than" );  
   else  
      _mbscpy_s( tmp, sizeof(tmp), "equal to" );  
   printf( "Result:   String 1 is %s string 2\n\n", tmp );  
   printf( "Function: _mbsnicmp _mbsnicmp (first 10 characters only)\n" );  
   result = _mbsnicmp( string1, string2, 10 );  
   if( result > 0 )  
      _mbscpy_s( tmp, sizeof(tmp), "greater than" );  
   else if( result < 0 )  
      _mbscpy_s( tmp, sizeof(tmp), "less than" );  
   else  
      _mbscpy_s( tmp, sizeof(tmp), "equal to" );  
   printf( "Result:   String 1 is %s string 2\n\n", tmp );  
}  
```  
  
## Saída  
  
```  
Compare strings:  
          The quick brown dog jumps over the lazy fox  
          The QUICK brown fox jumps over the lazy dog  
  
Function: _mbsnbcmp (first 10 characters only)  
Result:   String 1 is greater than string 2  
  
Function: _mbsnicmp _mbsnicmp (first 10 characters only)  
Result:   String 1 is equal to string 2  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcat, \_mbsnbcat\_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [\_mbsnbicmp, \_mbsnbicmp\_l](../../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)