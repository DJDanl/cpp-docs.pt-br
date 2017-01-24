---
title: "_ltoa_s, _ltow_s | Microsoft Docs"
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
  - "_ltoa_s"
  - "_ltow_s"
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
  - "_ltow_s"
  - "_ltoa_s"
  - "ltoa_s"
  - "ltow_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ltoa_s"
  - "Função _ltow_s"
  - "convertendo inteiros"
  - "convertendo números, em cadeias de caracteres"
  - "conversão de inteiros longos em cadeia de caracteres"
  - "Função ltoa_s"
  - "Função ltow_s"
ms.assetid: d7dc61ea-1ccd-412d-b262-555a58647386
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ltoa_s, _ltow_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um inteiro longo para uma cadeia de caracteres.  Essas são as versões de [\_ltoa, \_ltow](../Topic/_ltoa,%20_ltow.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _ltoa_s(  
    long value,  
    char *str,  
    size_t sizeOfstr,  
    int radix   
);  
errno_t _ltow_s(  
    long value,  
    wchar_t *str,  
    size_t sizeOfstr,  
    int radix   
);  
template <size_t size>  
errno_t _ltoa_s(  
    long value,  
    char (&str)[size],  
    int radix   
); // C++ only  
template <size_t size>  
errno_t _ltow_s(  
    long value,  
    wchar_t (&str)[size],  
    int radix   
); // C++ only  
```  
  
#### Parâmetros  
 `value`  
 Número a ser convertido.  
  
 `str`  
 Buffer da cadeia de caracteres resultante.  
  
 `sizeOfstr`  
 Tamanho de `str` em bytes para `_ltoa_s` ou no word para `_ltow_s`.  
  
 `radix`  
 Base de `value`.  
  
## Valor de retorno  
 Nulo se a função foi bem\-sucedida ou um código de erro.  
  
## Comentários  
 A função de `_ltoa_s` converte os dígitos de `value` a uma cadeia de caracteres com terminação nula e armazena o resultado \(até 33 bytes\) em `str`.  O argumento de `radix` especifica a base de `value`, que deve estar no intervalo de 2 a 36.  Se `radix` é igual a 10 e `value` for negativo, o primeiro caractere da cadeia de caracteres é armazenada o sinal de menos \(–\).  `_ltow_s` é uma versão ampla de caracteres de `_ltoa_s`; o segundo argumento de `_ltow_s` é cadeias de caracteres amplas.  
  
 Se `str` é um ponteiro de `NULL` ou `sizeOfstr` é menor ou igual a zero, essas funções invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, essas funções retornam \-1 e `errno` definido como `EINVAL` ou se `value` ou `str` fora do intervalo de um inteiro longo, essas funções retornam A\-1 e definem `errno` a `ERANGE`.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_ltot_s`|`_ltoa_s`|`_ltoa_s`|`_ltow_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ltoa_s`|\<stdlib.h\>|  
|`_ltow_s`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 [System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [\_itoa, \_i64toa, \_ui64toa, \_itow, \_i64tow, \_ui64tow](../../c-runtime-library/reference/itoa-i64toa-ui64toa-itow-i64tow-ui64tow.md)   
 [\_ultoa, \_ultow](../../c-runtime-library/reference/ultoa-ultow.md)   
 [\_ultoa\_s, \_ultow\_s](../Topic/_ultoa_s,%20_ultow_s.md)