---
title: "_strdec, _wcsdec, _mbsdec, _mbsdec_l | Microsoft Docs"
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
  - "_wcsdec"
  - "_strdec"
  - "_mbsdec"
  - "_mbsdec_l"
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
  - "_strdec"
  - "mbsdec_l"
  - "strdec"
  - "_mbsdec"
  - "_mbsdec_l"
  - "mbsdec"
  - "wcsdec"
  - "_wcsdec"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "_mbsdec - função"
  - "_mbsdec_l - função"
  - "_strdec - função"
  - "_tcsdec - função"
  - "_wcsdec - função"
  - "mbsdec - função"
  - "mbsdec_l - função"
  - "strdec - função"
  - "tcsdec - função"
  - "wcsdec - função"
ms.assetid: ae37c223-800f-48a9-ae8e-38c8d20af2dd
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strdec, _wcsdec, _mbsdec, _mbsdec_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move um ponteiro de cadeia de caracteres para trás em um caractere.  
  
> [!IMPORTANT]
>  `mbsdec` e `mbsdec_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
unsigned char *_strdec(  
   const unsigned char *start,  
   const unsigned char *current   
);  
unsigned wchar_t *_wcsdec(  
   const unsigned wchar_t *start,  
   const unsigned wchar_t *current   
);  
unsigned char *_mbsdec(  
   const unsigned char *start,  
   const unsigned char *current   
);  
unsigned char *_mbsdec_l(  
   const unsigned char *start,  
   const unsigned char *current,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `start`  
 Ponteiro para qualquer caractere \(ou para `_mbsdec` e \_`mbsdec_l`, o primeiro byte de qualquer caractere multibyte\) na cadeia de caracteres de origem; `start` deve preceder `current` na cadeia de caracteres de origem.  
  
 `current`  
 Ponteiro para qualquer caractere \(ou para `_mbsdec` e \_`mbsdec_l`, o primeiro byte de qualquer caractere multibyte\) na cadeia de caracteres de origem; `current` deve seguir `start` na cadeia de caracteres de origem.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 `_mbsdec`, \_`mbsdec_l`, `_strdec` e `_wcsdec` cada um retornará um ponteiro para o caractere que o precede imediatamente `current`; `_mbsdec` retornará `NULL` se o valor de `start` for maior ou igual ao de `current`.  Os mapas de `_tcsdec` a uma dessas funções e o valor de retorno dependem do mapeamento.  
  
## Comentários  
 As funções `_mbsdec` e `_mbsdec_l` retornam um ponteiro para o primeiro byte do caractere multibyte que precede imediatamente `current` na cadeia de caracteres que contém `start`.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md). `_mbsdec` reconhece sequências de caracteres multibyte, de acordo com a localidade que está sendo usada no momento, enquanto `_mbsdec_l` é idêntico, exceto pelo fato de que usa o parâmetro de localidade que é passado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `start` ou `current` for `NULL`, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
> [!IMPORTANT]
>  Essas funções podem ser vulneráveis às ameaças de saturação de buffer.  As saturações de buffer podem ser usadas para ataques ao sistema, pois podem causar uma elevação de privilégios injustificável.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsdec`|`_strdec`|`_mbsdec`|`_wcsdec`|  
  
 `_strdec` e `_wcsdec` são versões de caracteres largos e de caracteres de byte único de `_mbsdec` e `_mbsdec_l`.  `_strdec` e `_wcsdec` são fornecidos apenas para esse mapeamento e não devem ser usados de outra maneira.  
  
 Para obter mais informações, consulte [Usando mapeamentos de texto genérico](../../c-runtime-library/using-generic-text-mappings.md) e [Mapeamentos de texto genérico](../../c-runtime-library/generic-text-mappings.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_mbsdec`|\<mbstring.h\>|\<mbctype.h\>|  
|`_mbsdec_l`|\<mbstring.h\>|\<mbctype.h\>|  
|`_strdec`|\<tchar.h\>||  
|`_wcsdec`|\<tchar.h\>||  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 O exemplo a seguir mostra o uso de `_tcsdec`.  
  
```  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main()  
{  
   const TCHAR *str = _T("12345");  
   cout << "str: " << str << endl;  
  
   const TCHAR *str2;  
   str2 = str + 2;  
   cout << "str2: " << str2 << endl;  
  
   TCHAR *answer;  
   answer = _tcsdec( str, str2 );  
   cout << "answer: " << answer << endl;  
  
   return (0);   
}  
  
```  
  
 O exemplo a seguir mostra o uso de `_mbsdec`.  
  
```  
#include <iostream>  
#include <mbstring.h>  
using namespace std;  
  
int main()   
{   
   char *str = "12345";  
   cout << "str: " << str << endl;  
  
   char *str2;  
   str2 = str + 2;   
   cout << "str2: " << str2 << endl;  
  
   unsigned char *answer;  
   answer = _mbsdec( reinterpret_cast<unsigned char *>( str ), reinterpret_cast<unsigned char *>( str2 ));  
  
   cout << "answer: " << answer << endl;  
  
   return (0);   
}  
  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_strinc, \_wcsinc, \_mbsinc, \_mbsinc\_l](../../c-runtime-library/reference/strinc-wcsinc-mbsinc-mbsinc-l.md)   
 [\_strnextc, \_wcsnextc, \_mbsnextc, \_mbsnextc\_l](../../c-runtime-library/reference/strnextc-wcsnextc-mbsnextc-mbsnextc-l.md)   
 [\_strninc, \_wcsninc, \_mbsninc, \_mbsninc\_l](../../c-runtime-library/reference/strninc-wcsninc-mbsninc-mbsninc-l.md)