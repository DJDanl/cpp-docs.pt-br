---
title: "_itoa, _i64toa, _ui64toa, _itow, _i64tow, _ui64tow | Microsoft Docs"
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
  - "_itow"
  - "_i64tow"
  - "_itoa"
  - "_i64toa"
  - "_ui64toa"
  - "_ui64tow"
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
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_i64tow"
  - "ui64toa"
  - "ui64tow"
  - "itot"
  - "_itot"
  - "_i64toa"
  - "_itoa"
  - "_itow"
  - "_ui64tow"
  - "i64toa"
  - "i64tow"
  - "itow"
  - "_ui64toa"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _i64toa"
  - "Função _i64tow"
  - "Função _itoa"
  - "Função _itot"
  - "Função _itow"
  - "Função _ui64toa"
  - "Função _ui64tow"
  - "convertendo inteiros"
  - "convertendo números, em cadeias de caracteres"
  - "Função i64toa"
  - "Função i64tow"
  - "números inteiros, convertendo"
  - "Função itoa"
  - "Função itot"
  - "Função itow"
  - "Função ui64toa"
  - "Função ui64tow"
ms.assetid: 46592a00-77bb-4e73-98c0-bf629d96cea6
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _itoa, _i64toa, _ui64toa, _itow, _i64tow, _ui64tow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um inteiro para uma cadeia de caracteres.  Versões mais seguras dessas funções estão disponíveis; consulte [\_itoa\_s, \_i64toa\_s, \_ui64toa\_s, \_itow\_s, \_i64tow\_s, \_ui64tow\_s](../../c-runtime-library/reference/itoa-s-i64toa-s-ui64toa-s-itow-s-i64tow-s-ui64tow-s.md).  
  
## Sintaxe  
  
```  
char *_itoa(  
   int value,  
   char *str,  
   int radix   
);  
char *_i64toa(  
   __int64 value,  
   char *str,  
   int radix   
);  
char * _ui64toa(  
   unsigned _int64 value,  
   char *str,  
   int radix   
);  
wchar_t * _itow(  
   int value,  
   wchar_t *str,  
   int radix   
);  
wchar_t * _i64tow(  
   __int64 value,  
   wchar_t *str,  
   int radix   
);  
wchar_t * _ui64tow(  
   unsigned __int64 value,  
   wchar_t *str,  
   int radix   
);  
template <size_t size>  
char *_itoa(  
   int value,  
   char (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
char *_i64toa(  
   __int64 value,  
   char (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
char * _ui64toa(  
   unsigned _int64 value,  
   char (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
wchar_t * _itow(  
   int value,  
   wchar_t (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
wchar_t * _i64tow(  
   __int64 value,  
   wchar_t (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
wchar_t * _ui64tow(  
   unsigned __int64 value,  
   wchar_t (&str)[size],  
   int radix   
); // C++ only  
```  
  
#### Parâmetros  
 `value`  
 Número a ser convertido.  
  
 `str`  
 Resultado da cadeia de caracteres.  
  
 `radix`  
 Base de `value`; qual deve estar no intervalo 2\-36.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para `str`.  Não há nenhum retorno de erro.  
  
## Comentários  
 `_itoa`, `_i64toa`, e as funções de `_ui64toa` convertem os dígitos do argumento específico de `value` a uma cadeia de caracteres com terminação nula e os armazena o resultado \(até 33 caracteres para `_itoa` e 65 para `_i64toa` e `_ui64toa`\) em `str`.  Se `radix` é igual a 10 e `value` for negativo, o primeiro caractere da cadeia de caracteres é armazenada o sinal de menos \( `–` \).  `_itow`, `_i64tow`, e `_ui64tow` são versões de ampla caractere de `_itoa`, de `_i64toa`, e de `_ui64toa`, respectivamente.  
  
> [!IMPORTANT]
>  Para impedir excesso de buffer, verifique se o buffer de `str` seja grande o suficiente para manter os dígitos convertidos mais com o caractere à direita e um caractere de sinal.  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_itot`|`_itoa`|`_itoa`|`_itow`|  
|`_i64tot`|`_i64toa`|`_i64toa`|`_i64tow`|  
|`_ui64tot`|`_ui64toa`|`_ui64toa`|`_ui64tow`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_itoa`|\<stdlib.h\>|  
|`_i64toa`|\<stdlib.h\>|  
|`_ui64toa`|\<stdlib.h\>|  
|`_itow`|\<stdlib.h\>|  
|`_i64tow`|\<stdlib.h\>|  
|`_ui64tow`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_itoa.c  
// compile with: /W3  
// This program makes use of the _itoa functions  
// in various examples.  
  
#include <string.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   char buffer[65];  
   int r;  
   for( r=10; r>=2; --r )  
   {  
     _itoa( -1, buffer, r ); // C4996  
     // Note: _itoa is deprecated; consider using _itoa_s instead  
     printf( "base %d: %s (%d chars)\n", r, buffer, strnlen(buffer, _countof(buffer)) );  
   }  
   printf( "\n" );  
   for( r=10; r>=2; --r )  
   {  
     _i64toa( -1L, buffer, r ); // C4996  
     // Note: _i64toa is deprecated; consider using _i64toa_s  
     printf( "base %d: %s (%d chars)\n", r, buffer, strnlen(buffer, _countof(buffer)) );  
   }  
   printf( "\n" );  
   for( r=10; r>=2; --r )  
   {  
     _ui64toa( 0xffffffffffffffffL, buffer, r ); // C4996  
     // Note: _ui64toa is deprecated; consider using _ui64toa_s  
     printf( "base %d: %s (%d chars)\n", r, buffer, strnlen(buffer, _countof(buffer)) );  
   }  
}  
```  
  
  **base 10: \-1 \(2 caracteres\)**  
**base 9: 12068657453 \(11 caracteres\)**  
**base 8: 37777777777 \(11 caracteres\)**  
**base 7: 211301422353 \(12 caracteres\)**  
**base 6: 1550104015503 \(13 caracteres\)**  
**base 5: 32244002423140 \(14 caracteres\)**  
**base 4: 3333333333333333 \(16 caracteres\)**  
**base 3: 102002022201221111210 \(21 caracteres\)**  
**base 2: 11111111111111111111111111111111 \(32 caracteres\)**  
**base 10: \-1 \(2 caracteres\)**  
**base 9: 145808576354216723756 \(21 caracteres\)**  
**base 8: 1777777777777777777777 \(22 caracteres\)**  
**base 7: 45012021522523134134601 \(23 caracteres\)**  
**base 6: 3520522010102100444244423 \(25 caracteres\)**  
**base 5: 2214220303114400424121122430 \(28 caracteres\)**  
**base 4: 33333333333333333333333333333333 \(32 caracteres\)**  
**base 3: 11112220022122120101211020120210210211220 \(41 caracteres\)**  
**base 2: 1111111111111111111111111111111111111111111111111111111111111111 \(64 caracteres\)**  
**base 10: 18446744073709551615 \(20 caracteres\)**  
**base 9: 145808576354216723756 \(21 caracteres\)**  
**base 8: 1777777777777777777777 \(22 caracteres\)**  
**base 7: 45012021522523134134601 \(23 caracteres\)**  
**base 6: 3520522010102100444244423 \(25 caracteres\)**  
**base 5: 2214220303114400424121122430 \(28 caracteres\)**  
**base 4: 33333333333333333333333333333333 \(32 caracteres\)**  
**base 3: 11112220022122120101211020120210210211220 \(41 caracteres\)**  
**base 2: 1111111111111111111111111111111111111111111111111111111111111111 \(64 caracteres\)**   
## Equivalência do .NET Framework  
 [System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [\_ltoa, \_ltow](../Topic/_ltoa,%20_ltow.md)   
 [\_ltoa\_s, \_ltow\_s](../../c-runtime-library/reference/ltoa-s-ltow-s.md)   
 [\_ultoa, \_ultow](../../c-runtime-library/reference/ultoa-ultow.md)   
 [\_ultoa\_s, \_ultow\_s](../Topic/_ultoa_s,%20_ultow_s.md)