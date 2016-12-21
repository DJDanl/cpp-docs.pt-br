---
title: "strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l | Microsoft Docs"
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
  - "wcsnlen"
  - "strnlen_s"
  - "_mbstrnlen"
  - "_mbsnlen_l"
  - "_mbstrnlen_l"
  - "strnlen"
  - "wcsnlen_s"
  - "_mbsnlen"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wcsnlen"
  - "strnlen_s"
  - "_mbsnlen"
  - "_mbsnlen_l"
  - "_tcsnlen"
  - "_tcscnlen"
  - "_mbstrnlen_l"
  - "wcsnlen_s"
  - "_mbstrnlen"
  - "strnlen"
  - "_tcscnlen_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnlen"
  - "Função _mbsnlen_l"
  - "Função _mbstrnlen"
  - "Função _mbstrnlen_l"
  - "Função _tcscnlen"
  - "Função _tcscnlen_l"
  - "Função _tcsnlen"
  - "comprimentos, cadeias de caracteres"
  - "Função mbsnlen"
  - "Função mbsnlen_l"
  - "Função mbstrnlen"
  - "Função mbstrnlen_l"
  - "comprimento da cadeia de caracteres"
  - "Função strnlen"
  - "Função strnlen_l"
  - "Função strnlen_s"
  - "Função wcsnlen"
  - "Função wcsnlen_l"
  - "Função wcsnlen_s"
ms.assetid: cc05ce1c-72ea-4ae4-a7e7-4464e56e5f80
caps.latest.revision: 35
caps.handback.revision: 33
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o tamanho de uma cadeia de caracteres usando a localidade atual ou uma que foi enviada.  Essas são versões mais seguras [strlen, wcslen, \_mbslen, \_mbslen\_l, \_mbstrlen, \_mbstrlen\_l](../Topic/strlen,%20wcslen,%20_mbslen,%20_mbslen_l,%20_mbstrlen,%20_mbstrlen_l.md).  
  
> [!IMPORTANT]
>  `_mbsnlen`, `_mbsnlen_l`, `_mbstrnlen` e `_mbstrnlen_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
size_t strnlen(  
   const char *str,  
   size_t numberOfElements   
);  
size_t strnlen_s(  
   const char *str,  
   size_t numberOfElements   
);  
size_t wcsnlen(  
   const wchar_t *str,  
   size_t numberOfElements  
);  
size_t wcsnlen_s(  
   const wchar_t *str,  
   size_t numberOfElements  
);  
size_t _mbsnlen(  
   const unsigned char *str,  
   size_t numberOfElements  
);  
size_t _mbsnlen_l(  
   const unsigned char *str,  
   size_t numberOfElements,  
   _locale_t locale  
);  
size_t _mbstrnlen(  
   const char *str,  
   size_t numberOfElements  
);  
size_t _mbstrnlen_l(  
   const char *str,  
   size_t numberOfElements,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres terminada em nulo.  
  
 `numberOfElements`  
 O tamanho do buffer da cadeia de caracteres.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 Essas funções retornam o número de caracteres na cadeia de caracteres, sem incluir o caractere de terminação nula.  Se não houver terminador nulo dentro dos primeiros `numberOfElements` bytes da cadeia de caracteres \(ou caracteres largos para `wcsnlen`\), `numberOfElements` é retornado para indicar a condição de erro; a cadeia de caracteres de terminação nula tem comprimento estritamente menor que `numberOfElements`.  
  
 `_mbstrnlen` e `_mbstrnlen_l` retornam \-1 se a cadeia de caracteres contiver um caractere multibyte inválido.  
  
## Comentários  
  
> [!NOTE]
>  `strnlen` não é uma substituição de `strlen`; `strnlen` é feito para ser usado apenas para calcular o tamanho dos dados não confiáveis recebidos em um buffer de tamanho conhecido, por exemplo, um pacote de rede.  `strnlen` calcula o tamanho, mas não passa do fim do buffer se a cadeia de caracteres não estiver terminada.  Para ter outras situações, use `strlen`.  \(O mesmo se aplica a `wcsnlen`, `_mbsnlen` e `_mbstrnlen`.\)  
  
 Cada uma dessas funções retorna o número de caracteres em `str`, sem incluir o caractere de terminação nula.  Porém, `strnlen` e `strnlen_s` interpretam a cadeia de caracteres como uma cadeia de caracteres de byte único e, portanto, o valor retornado é sempre igual ao número de bytes, mesmo que a cadeia de caracteres contenha caracteres multibyte.  `wcsnlen` e `wcsnlen_s` são versões de caractere largo de `strnlen` e `strnlen_s`, respectivamente; os argumentos para `wcsnlen` e `wcsnlen_s` são cadeia de caracteres larga e a contagem de caracteres ficam em unidades de caractere largo.  Caso contrário, `wcsnlen` e `strnlen` comportam\-se de modo idêntico, assim como `strnlen_s` e `wcsnlen_s`.  
  
 `strnlen`, `wcsnlen,` e `_mbsnlen` não validam seus parâmetros.  Se `str` for `NULL`, ocorre uma violação de acesso.  
  
 `strnlen_s` e `wcsnlen_s` validam seus parâmetros.  Se `str` for `NULL`, as funções retornam 0.  
  
 `_mbstrnlen` também valida seus parâmetros.  Se `str` for `NULL`, ou se `numberOfElements` for maior que `INT_MAX`, `_mbstrnlen` gera uma exceção de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `_mbstrnlen` define `errno` para `EINVAL` e retorna \-1.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnlen`|`strnlen`|`strnlen`|`wcsnlen`|  
|`_tcscnlen`|`strnlen`|`_mbsnlen`|`wcsnlen`|  
|`_tcscnlen_l`|`strnlen`|`_mbsnlen_l`|`wcsnlen`|  
  
 `_mbsnlen` e `_mbstrnlen` retorna o número de caracteres multibyte em uma cadeia de caracteres multibyte.  O `_mbsnlen` reconhece sequências de caracteres multibyte de acordo com a página de código multibyte que está em uso no momento ou com a localidade informada; não testa a validade de caracteres multibyte.  O `_mbstrnlen` testa a validade de caracteres multibyte e reconhece sequências de caracteres multibyte.  Se a cadeia de caracteres enviada para `_mbstrnlen` contiver um caractere multibyte inválido, `errno` é definido para `EILSEQ`.  
  
 O valor de saída é afetado pela definição da configuração de categoria `LC_CTYPE` da localidade. Consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md) para obter mais informações.  As versões dessas funções são idênticas, exceto que aquelas que não têm o sufixo `_l` usam a localidade atual para esse comportamento dependente de localidade e as versões com um sufixo `_l` usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strnlen`, `strnlen_s`|\<string.h\>|  
|`wcsnlen`, `wcsnlen_s`|\<string.h\> ou \<wchar.h\>|  
|`_mbsnlen`, `_mbsnlen_l`|\<mbstring.h\>|  
|`_mbstrnlen`, `_mbstrnlen_l`|\<stdlib.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strnlen.c  
  
#include <string.h>  
  
int main()  
{  
   // str1 is 82 characters long. str2 is 159 characters long   
  
   char* str1 = "The length of a string is the number of characters\n"  
               "excluding the terminating null.";  
   char* str2 = "strnlen takes a maximum size. If the string is longer\n"  
                "than the maximum size specified, the maximum size is\n"  
                "returned rather than the actual size of the string.";  
   size_t len;  
   size_t maxsize = 100;  
  
   len = strnlen(str1, maxsize);  
   printf("%s\n Length: %d \n\n", str1, len);  
  
   len = strnlen(str2, maxsize);  
   printf("%s\n Length: %d \n", str2, len);  
}  
```  
  
  **O comprimento de uma cadeia de caracteres é o número de caracteres**  
**excluindo a terminação nula.  Comprimento: 82**   
**strnlen assume um tamanho máximo.  Se a cadeia de caracteres for mais longa**  
**que o tamanho máximo especificado, o tamanho máximo é**  
**retornado, em vez do tamanho real da cadeia de caracteres.  Comprimento: 100**    
## Equivalência do .NET Framework  
 [System::String::Length](https://msdn.microsoft.com/en-us/library/system.string.length.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [strncat, \_strncat\_l, wcsncat, \_wcsncat\_l, \_mbsncat, \_mbsncat\_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)