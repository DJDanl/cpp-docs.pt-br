---
title: "vsprintf, _vsprintf_l, vswprintf, _vswprintf_l, __vswprintf_l | Microsoft Docs"
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
  - "_vswprintf_l"
  - "_vsprintf_l"
  - "vsprintf"
  - "vswprintf"
  - "__vswprintf_l"
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
  - "vstprintf"
  - "vswprintf"
  - "_vstprintf"
  - "vsprintf"
  - "__vswprintf_l"
  - "_vsprintf_l"
  - "_vswprintf_l"
  - "vswprintf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __vswprintf_l"
  - "Função _vsprintf_l"
  - "Função _vstprintf"
  - "Função _vstprintf_l"
  - "Função _vswprintf_l"
  - "saturações de buffer"
  - "buffers, evitando saturações"
  - "buffers, saturações de buffer"
  - "texto formatado"
  - "Função vsprintf"
  - "Função vsprintf_l"
  - "Função vstprintf"
  - "Função vstprintf_l"
  - "Função vswprintf"
  - "Função vswprintf_l"
ms.assetid: b8ef1c0d-58f9-4a18-841a-f1a989e1c29b
caps.latest.revision: 32
caps.handback.revision: 30
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vsprintf, _vsprintf_l, vswprintf, _vswprintf_l, __vswprintf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A saída formatada de gravação usando um ponteiro para uma lista de argumentos.  Versões mais seguras dessas funções estão disponíveis; consulte [vsprintf\_s, \_vsprintf\_s\_l, vswprintf\_s, \_vswprintf\_s\_l](../../c-runtime-library/reference/vsprintf-s-vsprintf-s-l-vswprintf-s-vswprintf-s-l.md).  
  
## Sintaxe  
  
```  
int vsprintf(  
   char *buffer,  
   const char *format,  
   va_list argptr   
);   
int _vsprintf_l(  
   char *buffer,  
   const char *format,  
   locale_t locale,  
   va_list argptr   
);   
int vswprintf(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   va_list argptr   
);  
int _vswprintf_l(  
   wchar_t *buffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
int __vswprintf_l(  
   wchar_t *buffer,  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
);  
template <size_t size>  
int vsprintf(  
   char (&buffer)[size],  
   const char *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vsprintf_l(  
   char (&buffer)[size],  
   const char *format,  
   locale_t locale,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int vswprintf(  
   wchar_t (&buffer)[size],  
   const wchar_t *format,  
   va_list argptr   
); // C++ only  
template <size_t size>  
int _vswprintf_l(  
   wchar_t (&buffer)[size],  
   const wchar_t *format,  
   locale_t locale,  
   va_list argptr   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para saída.  
  
 `count`  
 Número máximo de caracteres a ser armazenado, na versão de `UNICODE` dessa função.  
  
 `format`  
 Especificação de formato.  
  
 `argptr`  
 Ponteiro para a lista de argumentos.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `vsprintf` e `vswprintf` retornam o número de caracteres gravados, sem incluir o caractere nulo de terminação ou um valor negativo, no caso de ocorrer um erro de saída.  Se `buffer` ou `format` for um ponteiro nulo, essas funções invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` a `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções usa um ponteiro para uma lista de argumentos, e nos formatos e grava os dados dados para a memória apontada por `buffer`.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
> [!IMPORTANT]
>  Usando `vsprintf`, não veja nenhuma forma de limitar o número de caracteres gravados, o que significa que o código que usa essa função é improvável que a excesso de buffer.  Use [\_vsnprintf](../../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md) em vez disso, ou chame [\_vscprintf](../../c-runtime-library/reference/vscprintf-vscprintf-l-vscwprintf-vscwprintf-l.md) para determinar como grande um buffer é necessário.  Além disso, verifique se `format` não é uma cadeia de caracteres definida pelo usuário.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
 `vswprintf` estão de acordo com o Padrão ISO C, que exige o segundo parâmetro, `count`, do tipo `size_t`.  Para forçar o comportamento fora do padrão antigo, defina `_CRT_NON_CONFORMING_SWPRINTFS.` que o antigo comportamento não pode estar em uma versão futura, assim que o código deve ser alterado para usar o novo comportamento compatível.  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vstprintf`|`vsprintf`|`vsprintf`|`vswprintf`|  
|`_vstprintf_l`|`_vsprintf_l`|`_vsprintf_l`|`_vswprintf_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`vsprintf`, `_vsprintf_l`|\<stdio.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
|`vswprintf`, `_vswprintf_l`|\<stdio.h\> ou \<wchar.h\> e \<stdarg.h\>|\<varargs.h\>\*|  
  
 \* Necessário para a compatibilidade de UNIX V.  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_vsprintf.c  
// compile with: /W3  
// This program uses vsprintf to write to a buffer.  
// The size of the buffer is determined by _vscprintf.  
  
#include <stdlib.h>  
#include <stdio.h>  
#include <stdarg.h>  
  
void test( char * format, ... )  
{  
    va_list args;  
    int     len;  
    char    *buffer;  
  
    // retrieve the variable arguments  
    va_start( args, format );  
  
    len = _vscprintf( format, args ) // _vscprintf doesn't count  
                                + 1; // terminating '\0'  
  
    buffer = (char*)malloc( len * sizeof(char) );  
  
    vsprintf( buffer, format, args ); // C4996  
    // Note: vsprintf is deprecated; consider using vsprintf_s instead  
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