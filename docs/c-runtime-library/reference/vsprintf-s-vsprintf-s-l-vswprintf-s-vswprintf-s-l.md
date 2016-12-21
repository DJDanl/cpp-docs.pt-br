---
title: "vsprintf_s, _vsprintf_s_l, vswprintf_s, _vswprintf_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_vswprintf_s_l"
  - "vsprintf_s"
  - "vswprintf_s"
  - "_vsprintf_s_l"
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
  - "vswprintf_s"
  - "vsprintf_s"
  - "_vstprintf_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _vstprintf_s_l"
  - "Função vsprintf_s_l"
  - "Função _vstprintf_s"
  - "Função vswprintf_s"
  - "Função vstprintf_s"
  - "Função vstprintf_s_l"
  - "Função vswprintf_s_l"
  - "Função vsprintf_s"
  - "Função _vsprintf_s_l"
  - "texto formatado [C++]"
  - "Função _vswprintf_s_l"
ms.assetid: 60e90518-57f0-4f1b-b732-f62a69702833
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsprintf_s, _vsprintf_s_l, vswprintf_s, _vswprintf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A saída formatada de gravação usando um ponteiro para uma lista de argumentos.  Essas são as versões de [vsprintf, \_vsprintf\_l, vswprintf, \_vswprintf\_l, \_\_vswprintf\_l](../../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int vsprintf_s(  
   char *buffer,  
   size_t numberOfElements,  
   const char *format,  
   va_list argptr   
);   
int _vsprintf_s_l(  
   char *buffer,  
   size_t numberOfElements,  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);   
int vswprintf_s(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   const wchar_t *format,  
   va_list argptr   
);  
int _vswprintf_s_l(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
template <size_t size>  
int vsprintf_s(  
   char (&buffer)[size],  
   const char *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int vswprintf_s(  
   wchar_t (&buffer)[size],  
   const wchar_t *format,  
   va_list argptr   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída.  
  
 `numberOfElements`  
 Tamanho de `buffer` em caracteres.  
  
 `format`  
 Especificação de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `vsprintf_s` e `vswprintf_s` retornam o número de caracteres gravados, sem incluir o caractere nulo de terminação ou um valor negativo, no caso de ocorrer um erro de saída.  Se `buffer` ou `format` for um ponteiro nulo, se o número for zero, ou se a cadeia de formato contiver caracteres de formatação inválidos, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções retornarão \-1 e definirão `errno` como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos, e nos formatos e grava os dados dados para a memória apontada por `buffer`.  
  
 `vswprintf_s` está em conformidade com o padrão para `vswprintf`, que ISO C requer o segundo parâmetro, `count`, do tipo `size_t`.  
  
 Essas funções são diferentes das versões de não seguras que somente as versões seguros oferecem suporte a parâmetros posicionais.  Para obter mais informações, consulte [Parâmetros posicionais printf\_p](../../c-runtime-library/printf-p-positional-parameters.md).  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vstprintf_s`|`vsprintf_s`|`vsprintf_s`|`vswprintf_s`|  
|`_vstprintf_s_l`|`_vsprintf_s_l`|`_vsprintf_s_l`|`_vswprintf_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`vsprintf_s`, `_vsprintf_s_l`|\<stdio.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
|`vswprintf_s`, `_vswprintf_s_l`|\<stdio.h\> ou \<wchar.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
  
 \* Necessário para a compatibilidade de UNIX V.  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_vsprintf_s.c  
// This program uses vsprintf_s to write to a buffer.  
// The size of the buffer is determined by _vscprintf.  
  
#include <stdlib.h>  
#include <stdarg.h>  
  
void test( char * format, ... )  
{  
   va_list args;  
   int len;  
   char * buffer;  
  
   va_start( args, format );  
   len = _vscprintf( format, args ) // _vscprintf doesn't count  
                               + 1; // terminating '\0'  
   buffer = malloc( len * sizeof(char) );  
   vsprintf_s( buffer, len, format, args );  
   puts( buffer );  
   free( buffer );  
}  
  
int main( void )  
{  
   test( "%d %c %d", 123, '<', 456 );  
   test( "%s", "This is a string" );  
}  
```  
  
  **123 \< 456**  
**Esta é uma cadeia de caracteres**   
## Equivalência do .NET Framework  
 [System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [va\_arg, va\_copy, va\_end, va\_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)