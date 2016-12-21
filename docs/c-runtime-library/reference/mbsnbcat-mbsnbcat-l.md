---
title: "_mbsnbcat, _mbsnbcat_l | Microsoft Docs"
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
  - "_mbsnbcat_l"
  - "_mbsnbcat"
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
  - "mbsnbcat"
  - "mbsnbcat_l"
  - "_mbsnbcat"
  - "_mbsnbcat_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbcat"
  - "Função _mbsnbcat_l"
  - "Função _tcsncat"
  - "Função _tcsncat_l"
  - "Função mbsnbcat"
  - "Função mbsnbcat_l"
  - "Função tcsncat"
  - "Função tcsncat_l"
ms.assetid: aa0f1d30-0ddd-48d1-88eb-c6884b20fd91
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbcat, _mbsnbcat_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Acrescenta, no máximo, os primeiros bytes de `n` de uma cadeia de caracteres multibyte para outra.  Versões mais seguras dessas funções estão disponíveis; consulte [\_mbsnbcat\_s, \_mbsnbcat\_s\_l](../Topic/_mbsnbcat_s,%20_mbsnbcat_s_l.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
unsigned char *_mbsnbcat(  
   unsigned char *dest,  
   const unsigned char *src,  
   size_t count   
);  
unsigned char *_mbsnbcat_l(  
   unsigned char *dest,  
   const unsigned char *src,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
unsigned char *_mbsnbcat(  
   unsigned char (&dest)[size],  
   const unsigned char *src,  
   size_t count   
); // C++ only  
template <size_t size>  
unsigned char *_mbsnbcat_l(  
   unsigned char (&dest)[size],  
   const unsigned char *src,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `dest`  
 Cadeia de caracteres de destino com caractere multibyte terminado com Null.  
  
 `src`  
 Cadeia de caracteres de origem com caractere multibyte terminado com Null.  
  
 `count`  
 Número de bytes de `src` a serem acrescentados a `dest`.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_mbsnbcat` retorna um ponteiro para a cadeia de caracteres de destino.  Nenhum valor de retorno é reservado para indicar um erro.  
  
## Comentários  
 A função `_mbsnbcat` acrescenta, no máximo, os primeiros `count` bytes de `src` a `dest`.  Se o byte que precede o caractere nulo em `dest` é um byte inicial, o byte inicial de `src` substitui esse byte inicial.  Caso contrário, o byte inicial de `src` substituirá o caractere nulo de terminação de `dest`.  Se um byte nulo aparecer em `src` antes que os bytes de `count` sejam acrescentados, o \_`mbsnbcat` acrescenta todos os bytes de `src`, até o caractere nulo.  Se `count` for maior que o tamanho de `src`, o tamanho de `src` será usado no lugar de `count`.  A cadeia de caracteres resultante é finalizada com um caractere nulo.  Se a cópia for feita entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  A versão `_mbsnbcat` da função usa o local atual para esse comportamento dependente de local; a versão `_mbsnbcat_l` é idêntica, exceto pelo fato de que ela usa o parâmetro de local transmitido.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 **Observação de segurança** Use uma cadeia de caracteres terminada em nulo.  A cadeia de caracteres terminadas em nulo não devem exceder o tamanho do buffer de destino.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 Se `dest` ou `src` for `NULL`, a função gerará um erro de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se o erro for tratado, a função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsncat`|[strncat](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|`_mbsnbcat`|[wcsncat](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|  
|`_tcsncat_l`|`_strncat_l`|`_mbsnbcat_l`|`_wcsncat_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbcat`|\<mbstring.h\>|  
|`_mbsnbcat_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcmp, \_mbsnbcmp\_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [\_strncnt, \_wcsncnt, \_mbsnbcnt, \_mbsnbcnt\_l, \_mbsnccnt, \_mbsnccnt\_l](../Topic/_strncnt,%20_wcsncnt,%20_mbsnbcnt,%20_mbsnbcnt_l,%20_mbsnccnt,%20_mbsnccnt_l.md)   
 [\_mbsnbcpy, \_mbsnbcpy\_l](../Topic/_mbsnbcpy,%20_mbsnbcpy_l.md)   
 [\_mbsnbicmp, \_mbsnbicmp\_l](../../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)   
 [\_mbsnbset, \_mbsnbset\_l](../../c-runtime-library/reference/mbsnbset-mbsnbset-l.md)   
 [strncat, \_strncat\_l, wcsncat, \_wcsncat\_l, \_mbsncat, \_mbsncat\_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [\_mbsnbcat\_s, \_mbsnbcat\_s\_l](../Topic/_mbsnbcat_s,%20_mbsnbcat_s_l.md)