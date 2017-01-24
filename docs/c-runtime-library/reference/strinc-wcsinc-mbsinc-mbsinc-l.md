---
title: "_strinc, _wcsinc, _mbsinc, _mbsinc_l | Microsoft Docs"
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
  - "_mbsinc"
  - "_wcsinc"
  - "_mbsinc_l"
  - "_strinc"
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
  - "mbsinc_l"
  - "_strinc"
  - "strinc"
  - "_mbsinc"
  - "_wcsinc"
  - "wcsinc"
  - "mbsinc"
  - "_mbsinc_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "_mbsinc - função"
  - "_mbsinc_l - função"
  - "_strinc - função"
  - "_tcsinc - função"
  - "_wcsinc - função"
  - "mbsinc - função"
  - "mbsinc_l - função"
  - "strinc - função"
  - "tcsinc - função"
  - "wcsinc - função"
ms.assetid: 54685943-8e2c-45e9-a559-2d94930dc6b4
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strinc, _wcsinc, _mbsinc, _mbsinc_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Avança um ponteiro de cadeia de caracteres em um caractere.  
  
> [!IMPORTANT]
>  `_mbsinc` e `_mbsinc_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *_strinc(    const char *current,    _locale_t locale ); wchar_t *_wcsinc(    const wchar_t *current,    _locale_t locale ); unsigned char *_mbsinc(    const unsigned char *current  ); unsigned char *_mbsinc_l(    const unsigned char *current,    _locale_t locale );   
```  
  
#### Parâmetros  
 `current`  
 Ponteiro de caractere.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 Todas essas rotinas retornam um ponteiro para o caractere logo depois de `current`.  
  
## Comentários  
 A função `_mbsinc` retorna um ponteiro para o primeiro byte do caractere multibyte logo depois de `current`.  `_mbsinc` reconhece sequências de caractere multibyte de acordo com a [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso. O `_mbsinc_l` é idêntico, exceto por usar o parâmetro de localidade passado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 A função de texto genérica `_tcsinc`, definida em Tchar.h, é mapeada para `_mbsinc` caso `_MBCS` tenha sido definido ou para `_wcsinc` caso `_UNICODE` tenha sido definido.  Do contrário, `_tcsinc` é mapeado para `_strinc`.  `_strinc` e `_wcsinc` são versões de caractere de byte único e de caractere largo de `_mbsinc`.  `_strinc` e `_wcsinc` só são fornecidos para esse mapeamento e não devem ser usados de outra forma.  Para obter mais informações, consulte [Usando mapeamentos de texto genérico](../../c-runtime-library/using-generic-text-mappings.md) e [Mapeamentos de texto genérico](../../c-runtime-library/generic-text-mappings.md).  
  
 Se `current` for `NULL`, o manipulador de parâmetros inválido será invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
> [!IMPORTANT]
>  Essas funções podem ser vulneráveis a ameaças de estouro de buffer.  Os estouros de buffer podem ser usados em ataques de sistema porque podem causar uma elevação de privilégio não garantida.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsinc`|\<mbstring.h\>|  
|`_mbsinc_l`|\<mbstring.h\>|  
|`_strinc`|\<tchar.h\>|  
|`_wcsinc`|\<tchar.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_strdec, \_wcsdec, \_mbsdec, \_mbsdec\_l](../../c-runtime-library/reference/strdec-wcsdec-mbsdec-mbsdec-l.md)   
 [\_strnextc, \_wcsnextc, \_mbsnextc, \_mbsnextc\_l](../../c-runtime-library/reference/strnextc-wcsnextc-mbsnextc-mbsnextc-l.md)   
 [\_strninc, \_wcsninc, \_mbsninc, \_mbsninc\_l](../../c-runtime-library/reference/strninc-wcsninc-mbsninc-mbsninc-l.md)