---
title: "strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l | Microsoft Docs"
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
  - "strncpy"
  - "_strncpy_l"
  - "_mbsncpy"
  - "wcsncpy"
  - "_mbsncpy_l"
  - "_wcsncpy_l"
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
  - "_fstrncpy"
  - "strncpy"
  - "_ftcsncpy"
  - "_tcsnccpy_l"
  - "_tcsnccpy"
  - "_mbsncpy"
  - "wcsncpy"
  - "_tcsncpy"
  - "_strncpy_l"
  - "_mbsncpy_l"
  - "_wcsncpy_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função wcsncpy_l"
  - "caracteres [C++], copiando"
  - "Função mbsncpy_l"
  - "Função strncpy_l"
  - "Função wcsncpy"
  - "Função tcsnccpy"
  - "Função ftcsncpy"
  - "copiando caracteres de cadeias de caracteres"
  - "Função _wcsncpy_l"
  - "Função _tcsnccpy"
  - "Função _tcsnccpy_l"
  - "Função strncpy"
  - "Função _tcsncpy"
  - "Função mbsncpy"
  - "Função _fstrncpy"
  - "Função _mbsncpy_l"
  - "Função tcsncpy_l"
  - "Função tcsnccpy_l"
  - "Função fstrncpy"
  - "cadeias de caracteres [C++], copiando"
  - "Função _ftcsncpy"
  - "Função _tcsncpy_l"
  - "Função _mbsncpy"
  - "Função tcsncpy"
  - "Função _strncpy_l"
ms.assetid: ac4345a1-a129-4f2f-bb8a-373ec58ab8b0
caps.latest.revision: 42
caps.handback.revision: 42
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Copie os caracteres de uma cadeia de caracteres para outro. Versões mais seguras dessas funções estão disponíveis; consulte [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md).  
  
> [!IMPORTANT]
>  `_mbsncpy` e `_mbsncpy_l` não pode ser usado em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *strncpy(  
   char *strDest,  
   const char *strSource,  
   size_t count   
);  
char *_strncpy_l(  
   char *strDest,  
   const char *strSource,  
   size_t count,  
   locale_t locale   
);  
wchar_t *wcsncpy(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count   
);  
wchar_t *_wcsncpy_l(  
   wchar_t *strDest,  
   const wchar_t *strSource,  
   size_t count,  
   locale_t locale   
);  
unsigned char *_mbsncpy(  
   unsigned char *strDest,  
   const unsigned char *strSource,  
   size_t count   
);  
unsigned char *_mbsncpy_l(  
   unsigned char *strDest,  
   const unsigned char *strSource,  
   size_t count,  
   _locale_t locale  
);  
template <size_t size>  
char *strncpy(  
   char (&strDest)[size],  
   const char *strSource,  
   size_t count   
); // C++ only  
template <size_t size>  
char *_strncpy_l(  
   char (&strDest)[size],  
   const char *strSource,  
   size_t count,  
   locale_t locale   
); // C++ only  
template <size_t size>  
wchar_t *wcsncpy(  
   wchar_t (&strDest)[size],  
   const wchar_t *strSource,  
   size_t count   
); // C++ only  
template <size_t size>  
wchar_t *_wcsncpy_l(  
   wchar_t (&strDest)[size],  
   const wchar_t *strSource,  
   size_t count,  
   locale_t locale   
); // C++ only  
template <size_t size>  
unsigned char *_mbsncpy(  
   unsigned char (&strDest)[size],  
   const unsigned char *strSource,  
   size_t count   
); // C++ only  
template <size_t size>  
unsigned char *_mbsncpy_l(  
   unsigned char (&strDest)[size],  
   const unsigned char *strSource,  
   size_t count,  
   _locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 `strDest`  
 Cadeia de caracteres de destino.  
  
 `strSource`  
 Cadeia de caracteres de origem.  
  
 `count`  
 Número de caracteres a serem copiados.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna `strDest`. Nenhum valor de retorno é reservado para indicar um erro.  
  
## Comentários  
 O `strncpy` função copia inicial `count` caracteres de `strSource` para `strDest` e retorna `strDest`. Se `count` é menor ou igual ao comprimento da `strSource`, um caractere nulo não é acrescentado automaticamente a cadeia de caracteres copiada. Se `count` for maior que o comprimento de `strSource`, a cadeia de caracteres de destino é preenchida com caracteres nulos até comprimento `count`. O comportamento de `strncpy` é indefinido se sobreponham as cadeias de caracteres de origem e de destino.  
  
> [!IMPORTANT]
>  `strncpy` não verifica se há espaço suficiente na `strDest`; isso o torna uma causa potencial de saturações de buffer. O `count` argumento limita o número de caracteres copiados; não é um limite no tamanho do `strDest`. Consulte o exemplo a seguir. Para obter mais informações, consulte [evitando saturações de Buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 Se `strDest` ou `strSource` é um `NULL` ponteiro, ou se `count` é menor ou igual a zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão \-1 e defina `errno` para `EINVAL`  
  
 `wcsncpy` e `_mbsncpy` são versões de caractere largo e caracteres multibyte `strncpy`. O valor de retorno e argumentos `wcsncpy` e `_mbsncpy` variam de acordo. Esses seis funções se comportam de forma idêntica caso contrário.  
  
 As versões dessas funções com o `_l` sufixo são idênticas, exceto que eles usam a localidade passada em vez da localidade atual para o seu comportamento depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 No C\+\+, essas funções têm sobrecargas de modelo que invocam as contrapartes seguros, mais recentes dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tcsncpy`|`strncpy`|`_mbsnbcpy`|`wcsncpy`|  
|`_tcsncpy_l`|`_strncpy_l`|`_mbsnbcpy_l`|`_wcsncpy_l`|  
  
> [!NOTE]
>  `_strncpy_l` e `_wcsncpy_l` não ter nenhuma dependência de localidade; eles são fornecidos apenas para `_tcsncpy_l` e não se destina a ser chamado diretamente.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strncpy`|\< h \>|  
|`wcsncpy`|\< h \> ou \< WCHAR \>|  
|`_mbsncpy`, `_mbsncpy_l`|\< mbstring.h \>|  
  
 Para obter informações de compatibilidade de plataforma adicionais, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 O exemplo a seguir demonstra o uso de `strncpy` e como ele pode ser usado indevidamente para fazer com que o programa bugs e problemas de segurança. O compilador gera um aviso para cada chamada para `strncpy` semelhante a **crt\_strncpy\_x86.c\(15\): aviso C4996: 'strncpy': essa função ou variável pode não ser seguro. Considere usar strncpy\_s. Para desativar a substituição, use \_CRT\_SECURE\_NO\_WARNINGS. Consulte a Ajuda online para obter detalhes.**  
  
```  
// crt_strncpy_x86.c  
// Use this command in an x86 developer command prompt to compile:   
// cl /TC /W3 crt_strncpy_x86.c  
  
#include <stdio.h>  
#include <string.h>  
  
int main() {  
   char t[20];  
   char s[20];  
   char *p = 0, *q = 0;  
  
   strcpy_s(s, sizeof(s), "AA BB CC");  
   // Note: strncpy is deprecated; consider using strncpy_s instead  
   strncpy(s, "aa", 2);     // "aa BB CC"         C4996  
   strncpy(s + 3, "bb", 2); // "aa bb CC"         C4996  
   strncpy(s, "ZZ", 3);     // "ZZ",              C4996  
                            // count greater than strSource, null added  
   printf("%s\n", s);  
  
   strcpy_s(s, sizeof(s), "AA BB CC");  
   p = strstr(s, "BB");  
   q = strstr(s, "CC");  
   strncpy(s, "aa", p - s - 1);   // "aa BB CC"   C4996  
   strncpy(p, "bb", q - p - 1);   // "aa bb CC"   C4996  
   strncpy(q, "cc",  q - s);      // "aa bb cc"   C4996  
   strncpy(q, "dd", strlen(q));   // "aa bb dd"   C4996  
   printf("%s\n", s);  
  
   // some problems with strncpy  
   strcpy_s(s, sizeof(s), "test");  
   strncpy(t, "this is a very long string", 20 ); // C4996  
   // Danger: at this point, t has no terminating null,  
   // so the printf continues until it runs into one.  
   // In this case, it will print "this is a very long test"  
   printf("%s\n", t);  
  
   strcpy_s(t, sizeof(t), "dogs like cats");  
   printf("%s\n", t);  
  
   strncpy(t + 10, "to chase cars.", 14); // C4996  
   printf("%s\n", t);  
  
   // strncpy has caused a buffer overrun and corrupted string s  
   printf("Buffer overrun: s = '%s' (should be 'test')\n", s);  
   // Since the stack grows from higher to lower addresses, buffer  
   // overruns can corrupt function return addresses on the stack,  
   // which can be exploited to run arbitrary code.  
}  
```  
  
 Saída  
  
```Output  
ZZ bb aa dd isso é um teste muito longos cachorros como cachorros gatos gostam de perseguir carros. Estouro de buffer: s = 'ars'. (deve ser 'test')  
```  
  
 O layout de variáveis automáticas e o nível de proteção de detecção e o código de erro podem variar com as configurações de compilador alterados. Este exemplo pode ter resultados diferentes quando criados em outros ambientes de compilação ou com outras opções do compilador.  
  
## Equivalência do .NET Framework  
 [System::String::Copy](https://msdn.microsoft.com/en-us/library/system.string.copy.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [\_mbsnbcpy, \_mbsnbcpy\_l](../Topic/_mbsnbcpy,%20_mbsnbcpy_l.md)   
 [strcat, wcscat, \_mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [strncat, \_strncat\_l, wcsncat, \_wcsncat\_l, \_mbsncat, \_mbsncat\_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)   
 [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md)   
 [strcpy\_s, wcscpy\_s, \_mbscpy\_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)