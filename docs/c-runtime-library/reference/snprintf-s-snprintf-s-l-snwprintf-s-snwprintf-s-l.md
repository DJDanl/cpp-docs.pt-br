---
title: "_snprintf_s, _snprintf_s_l, _snwprintf_s, _snwprintf_s_l | Microsoft Docs"
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
  - "_snprintf_s"
  - "_snprintf_s_l"
  - "_snwprintf_s"
  - "_snwprintf_s_l"
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
  - "_snwprintf_s_l"
  - "_sntprintf_s_l"
  - "snprintf_s_l"
  - "_snprintf_s_l"
  - "_sntprintf_s"
  - "_snprintf_s"
  - "snprintf_s"
  - "_snwprintf_s"
  - "snwprintf_s_l"
  - "snwprintf_s"
  - "sntprintf_s"
  - "sntprintf_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _snprintf_s"
  - "Função _snprintf_s_l"
  - "Função _sntprintf_s"
  - "Função _sntprintf_s_l"
  - "Função _snwprintf_s"
  - "Função _snwprintf_s_l"
  - "texto formatado [C++]"
  - "Função snprintf_s"
  - "Função snprintf_s_l"
  - "Função sntprintf_s"
  - "Função sntprintf_s_l"
  - "Função snwprintf_s"
  - "Função snwprintf_s_l"
ms.assetid: 9336ab86-13e5-4a29-a3cd-074adfee6891
caps.latest.revision: 32
caps.handback.revision: 32
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _snprintf_s, _snprintf_s_l, _snwprintf_s, _snwprintf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava dados formatados em uma cadeia de caracteres. Essas são versões de [snprintf, snprintf, snprintf\_l, snwprintf, snwprintf\_l](../../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int _snprintf_s(  
   char *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const char *format [,  
   argument] ...   
);  
int _snprintf_s_l(  
   char *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const char *format,  
   locale_t locale [,  
   argument] ...   
);  
int _snwprintf_s(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const wchar_t *format [,  
   argument] ...   
);  
int _snwprintf_s_l(  
   wchar_t *buffer,  
   size_t sizeOfBuffer,  
   size_t count,  
   const wchar_t *format,  
   locale_t locale [,  
   argument] ...   
);  
template <size_t size>  
int _snprintf_s(  
   char (&buffer)[size],  
   size_t count,  
   const char *format [,  
   argument] ...   
); // C++ only  
template <size_t size>  
int _snwprintf_s(  
   wchar_t (&buffer)[size],  
   size_t count,  
   const wchar_t *format [,  
   argument] ...   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para a saída.  
  
 `sizeOfBuffer`  
 O tamanho do local de armazenamento para saída. Tamanho em `bytes` para `_snprintf_s` ou tamanho em `words` para `_snwprintf_s`.  
  
 `Count`  
 Número máximo de caracteres para armazenar, ou [\_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `_snprintf_s` Retorna o número de caracteres armazenados em `buffer`, sem contar o caractere de terminação nula.`_snwprintf_s` Retorna o número de caracteres largos armazenados em `buffer`, sem contar o caractere largo nulo de terminação.  
  
 Se o armazenamento necessário para armazenar os dados e uma terminação nula exceder `sizeOfBuffer`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continua após o manipulador de parâmetro inválido, defina essas funções `buffer` para uma cadeia de caracteres vazia, definir `errno` para `ERANGE`, e retornará \-1.  
  
 Se `buffer` ou `format` é um `NULL` ponteiro, ou se `count` é menor ou igual a zero, o manipulador de parâmetro inválido é invocado. Se a execução puder continuar, essas funções definir `errno` para `EINVAL` e retornará \-1.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `_snprintf_s` função formata e armazena `count` ou menos caracteres em `buffer` e acrescenta uma terminação nula. Cada argumento \(se houver\) é convertido e saído de acordo com a especificação de formato correspondente em `format`. A formatação é consistente com o `printf` família de funções; consulte [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md). Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 Se `count` é [\_TRUNCATE](../../c-runtime-library/truncate.md), em seguida, `_snprintf_s` gravações máximo da cadeia de caracteres como irá se ajustar no `buffer` deixando espaço para uma terminação nula. Se a cadeia de caracteres inteira \(com terminação nula\) se encaixa `buffer`, em seguida, `_snprintf_s` retorna o número de caracteres gravados \(não incluindo a terminação nula\); caso contrário, `_snprintf_s` retorna \-1 para indicar que o truncamento ocorreu.  
  
> [!IMPORTANT]
>  Certifique\-se de que `format` não é uma cadeia de caracteres definida pelo usuário.  
  
 `_snwprintf_s` é uma versão de caractere largo de `_snprintf_s`; os argumentos de ponteiro para `_snwprintf_s` são cadeias de caracteres largos. Detecção de erros de codificação `_snwprintf_s` pode ser diferente do que em `_snprintf_s`.`_snwprintf_s`, como `swprintf_s`, grava a saída em uma cadeia de caracteres em vez de um destino do tipo `FILE`.  
  
 As versões dessas funções com o `_l` sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.  
  
 No C\+\+, usando essas funções é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir o comprimento do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e eles podem substituir automaticamente funções mais antigas e não seguras com suas contrapartes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_sntprintf_s`|`_snprintf_s`|`_snprintf_s`|`_snwprintf_s`|  
|`_sntprintf_s_l`|`_snprintf_s_l`|`_snprintf_s_l`|`_snwprintf_s_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_snprintf_s`, `_snprintf_s_l`|\< stdio \>|  
|`_snwprintf_s`, `_snwprintf_s_l`|\< stdio \> ou \< WCHAR \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_snprintf_s.cpp  
// compile with: /MTd  
  
// These #defines enable secure template overloads  
// (see last part of Examples() below)  
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1   
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 1  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <crtdbg.h>  // For _CrtSetReportMode  
#include <errno.h>  
  
// This example uses a 10-byte destination buffer.  
  
int snprintf_s_tester( const char * fmt, int x, size_t count )  
{  
   char dest[10];  
  
   printf( "\n" );  
  
   if ( count == _TRUNCATE )  
      printf( "%zd-byte buffer; truncation semantics\n",  
               _countof(dest) );  
   else  
      printf( "count = %zd; %zd-byte buffer\n",  
               count, _countof(dest) );  
  
   int ret = _snprintf_s( dest, _countof(dest), count, fmt, x );  
  
   printf( "    new contents of dest: '%s'\n", dest );  
  
   return ret;  
}  
  
void Examples()  
{  
   // formatted output string is 9 characters long: "<<<123>>>"  
   snprintf_s_tester( "<<<%d>>>", 121, 8 );  
   snprintf_s_tester( "<<<%d>>>", 121, 9 );  
   snprintf_s_tester( "<<<%d>>>", 121, 10 );  
  
   printf( "\nDestination buffer too small:\n" );  
  
   snprintf_s_tester( "<<<%d>>>", 1221, 10 );  
  
   printf( "\nTruncation examples:\n" );  
  
   int ret = snprintf_s_tester( "<<<%d>>>", 1221, _TRUNCATE );  
   printf( "    truncation %s occur\n", ret == -1 ? "did"  
                                                  : "did not" );  
  
   ret = snprintf_s_tester( "<<<%d>>>", 121, _TRUNCATE );  
   printf( "    truncation %s occur\n", ret == -1 ? "did"  
                                                  : "did not" );  
   printf( "\nSecure template overload example:\n" );  
  
   char dest[10];  
   _snprintf( dest, 10, "<<<%d>>>", 12321 );  
   // With secure template overloads enabled (see #defines  
   // at top of file), the preceding line is replaced by  
   //    _snprintf_s( dest, _countof(dest), 10, "<<<%d>>>", 12345 );  
   // Instead of causing a buffer overrun, _snprintf_s invokes  
   // the invalid parameter handler.  
   // If secure template overloads were disabled, _snprintf would  
   // write 10 characters and overrun the dest buffer.  
   printf( "    new contents of dest: '%s'\n", dest );  
}  
  
void myInvalidParameterHandler(  
   const wchar_t* expression,  
   const wchar_t* function,   
   const wchar_t* file,   
   unsigned int line,   
   uintptr_t pReserved)  
{  
   wprintf(L"Invalid parameter handler invoked: %s\n", expression);  
}  
  
int main( void )  
{  
   _invalid_parameter_handler oldHandler, newHandler;  
  
   newHandler = myInvalidParameterHandler;  
   oldHandler = _set_invalid_parameter_handler(newHandler);  
   // Disable the message box for assertions.  
   _CrtSetReportMode(_CRT_ASSERT, 0);  
  
   Examples();  
}  
```  
  
```Output  
  
Count = 8; novo conteúdo do buffer de 10 bytes de destino: ' <<< 121 >> ' contagem = 9; novo conteúdo do buffer de 10 bytes de destino: '<<< 121 >>> ' contagem = 10; novo conteúdo do buffer de 10 bytes de destino: '<<< 121 >>> ' buffer de destino é muito pequeno: contagem = 10; manipulador de parâmetro inválido de buffer de 10 bytes invocado: ("Buffer muito pequeno", 0) novo conteúdo de destino: ' exemplos de truncamento: buffer de 10 bytes; truncamento semântica novo conteúdo de destino: ' <<< 1221 >> ' truncamento aconteceram 10 bytes do buffer; truncamento semântica novo conteúdo de destino: '<<< 121 >>> ' truncamento não houve exemplo de sobrecarga de modelo seguras: manipulador de parâmetro inválido invocado: ("Buffer muito pequeno", 0) novo conteúdo de destino: '  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)