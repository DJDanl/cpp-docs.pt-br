---
title: "_snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l | Microsoft Docs"
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
  - "_snwscanf_s_l"
  - "_snwscanf_s"
  - "_snscanf_s"
  - "_snscanf_s_l"
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
apitype: "DLLExport"
f1_keywords: 
  - "_sntscanf_s"
  - "snscanf_s"
  - "_snwscanf_s_l"
  - "sntscanf_s_l"
  - "snwscanf_s_l"
  - "snwscanf_s"
  - "_snscanf_s"
  - "_snwscanf_s"
  - "snscanf_s_l"
  - "_sntscanf_s_l"
  - "_snscanf_s_l"
  - "sntscanf_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _snscanf_s"
  - "Função _snscanf_s_l"
  - "Função _sntscanf_s"
  - "Função _sntscanf_s_l"
  - "Função _snwscanf_s"
  - "Função _snwscanf_s_l"
  - "lendo dados, cadeias de caracteres"
  - "Função snscanf_s"
  - "Função snscanf_s_l"
  - "Função sntscanf_s"
  - "Função sntscanf_s_l"
  - "Função snwscanf_s"
  - "Função snwscanf_s_l"
  - "cadeias de caracteres [C++], lendo"
  - "cadeias de caracteres [C++], lendo dados de"
ms.assetid: 72356653-7362-461a-af73-597b9c0a8094
caps.latest.revision: 24
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As leituras mostram dados de um comprimento especificado de uma cadeia de caracteres.  Essas são as versões de [\_snscanf, \_snscanf\_l, \_snwscanf, \_snwscanf\_l](../../c-runtime-library/reference/snscanf-snscanf-l-snwscanf-snwscanf-l.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int __cdecl _snscanf_s(  
   const char * input,  
   size_t length,  
   const char * format,  
   ...  
);  
int __cdecl _snscanf_s_l(  
   const char * input,  
   size_t length,  
   const char * format,  
   locale_t locale,  
   ...  
);  
int __cdecl _snwscanf_s(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format,  
   ...  
);  
int __cdecl _snwscanf_s_l(  
   const wchar_t * input,  
   size_t length,  
   const wchar_t * format,  
   locale_t locale,  
   …  
);  
```  
  
#### Parâmetros  
 `input`  
 Cadeia de caracteres de entrada para verificar.  
  
 `length`  
 Número de caracteres a ser analisada em `input`.  
  
 `format`  
 Um ou mais formato especificadores.  
  
 `... (optional)`  
 As variáveis que serão usados para armazenar os valores extraíram de cadeia de caracteres de entrada pelos especificadores de formato em `format`.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Essas duas funções retornam o número de campos com êxito convertidos e atribuídos; o valor de retorno não inclui os campos que foram lidos mas não atribuído.  Um valor de retorno 0 indica que nenhum campo foi atribuído.  O valor de retorno é `EOF` para um erro ou se o final da cadeia de caracteres for atingido antes da primeira conversão.  Para obter mais informações, consulte [sscanf\_s, \_sscanf\_s\_l, swscanf\_s, \_swscanf\_s\_l](../Topic/sscanf_s,%20_sscanf_s_l,%20swscanf_s,%20_swscanf_s_l.md).  
  
 Se `input` ou `format` são um ponteiro nulo `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Essa função é como `sscanf_s` exceto que fornece a capacidade de especificar um número fixo de caracteres para examinar de cadeia de caracteres de entrada.  Para obter mais informações, consulte [sscanf\_s, \_sscanf\_s\_l, swscanf\_s, \_swscanf\_s\_l](../Topic/sscanf_s,%20_sscanf_s_l,%20swscanf_s,%20_swscanf_s_l.md).  
  
 O parâmetro de tamanho do buffer é necessário com os caracteres `c`, `C`, `s`, `S`, e `[`de campo do tipo.  Para obter mais informações, consulte [Caracteres de campo de tipo scanf](../../c-runtime-library/scanf-type-field-characters.md).  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, e não `size_t`.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_sntscanf_s`|`_snscanf_s`|`_snscanf_s`|`_snwscanf_s`|  
|`_sntscanf_s_l`|`_snscanf_s_l`|`_snscanf_s_l`|`_snwscanf_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_snscanf_s`, \_`snscanf_s_l`|\<stdio.h\>|  
|`_snwscanf_s`, `_snwscanf_s_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_snscanf_s.c  
// This example scans a string of   
// numbers, using both the character  
// and wide character secure versions  
// of the snscanf function.  
  
#include <stdio.h>  
  
int main( )  
{  
    char        str1[] = "15 12 14...";  
    wchar_t     str2[] = L"15 12 14...";  
    char        s1[3];  
    wchar_t     s2[3];  
    int         i;  
    float       fp;  
  
    i = _snscanf_s( str1, 6,  "%s %f", s1, 3, &fp);  
    printf_s("_snscanf_s converted %d fields: ", i);  
    printf_s("%s and %f\n", s1, fp);  
  
    i = _snwscanf_s( str2, 6,  L"%s %f", s2, 3, &fp);  
    wprintf_s(L"_snwscanf_s converted %d fields: ", i);  
    wprintf_s(L"%s and %f\n", s2, fp);  
}  
```  
  
  **os \_snscanf\_s converteram 2 campos: 15 e 12,000000**  
**os \_snwscanf\_s converteram 2 campos: 15 e 12,000000**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Especificação de largura scanf Width](../../c-runtime-library/scanf-width-specification.md)