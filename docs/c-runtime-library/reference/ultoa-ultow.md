---
title: "_ultoa, _ultow | Microsoft Docs"
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
  - "_ultoa"
  - "_ultow"
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
  - "ultot"
  - "ultow"
  - "_ultoa"
  - "_ultow"
  - "_ultot"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ultoa"
  - "Função _ultot"
  - "Função _ultow"
  - "convertendo inteiros"
  - "convertendo números, em cadeias de caracteres"
  - "números inteiros, convertendo"
  - "Função ultot"
  - "Função ultow"
ms.assetid: 7a472dc4-5652-4513-93c3-3358522c23be
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ultoa, _ultow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um inteiro longo não assinado para uma cadeia de caracteres.  Versões mais seguras dessas funções estão disponíveis; consulte [\_ultoa\_s, \_ultow\_s](../Topic/_ultoa_s,%20_ultow_s.md).  
  
## Sintaxe  
  
```  
char *_ultoa(  
   unsigned long value,  
   char *str,  
   int radix   
);  
wchar_t *_ultow(  
   unsigned long value,  
   wchar_t *str,  
   int radix   
);  
template <size_t size>  
char *_ultoa(  
   unsigned long value,  
   char (&str)[size],  
   int radix   
); // C++ only  
template <size_t size>  
wchar_t *_ultow(  
   unsigned long value,  
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
 Base de `value`*.*  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para `str`.  Não há nenhum retorno de erro.  
  
## Comentários  
 A função de `_ultoa` converte `value` a uma cadeia de caracteres com terminação nula e armazena o resultado \(até 33 bytes\) em `str`.  Nenhuma verificação de estouro será executado.  `radix` especifica a base de `value`; `radix` deve estar no intervalo de 2 a 36.  `_ultow` é uma versão de caracteres largos de `_ultoa`.  
  
> [!IMPORTANT]
>  Para impedir excesso de buffer, verifique se o buffer de `str` seja grande o suficiente para manter os dígitos convertidos mais com o caractere à direita.  
  
 No C\+\+, essas funções têm as sobrecargas de modelo que invocam as correspondentes seguras mais recentes dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_ultot`|`_ultoa`|`_ultoa`|`_ultow`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ultoa`|\<stdlib.h\>|  
|`_ultow`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [\_itoa](../../c-runtime-library/reference/itoa-i64toa-ui64toa-itow-i64tow-ui64tow.md).  
  
## Equivalência do .NET Framework  
 [System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [\_itoa, \_i64toa, \_ui64toa, \_itow, \_i64tow, \_ui64tow](../../c-runtime-library/reference/itoa-i64toa-ui64toa-itow-i64tow-ui64tow.md)