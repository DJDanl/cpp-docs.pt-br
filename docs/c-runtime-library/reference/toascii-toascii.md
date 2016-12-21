---
title: "ToAscii, ToAscii | Microsoft Docs"
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
  - "__toascii"
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
  - "__toascii"
  - "toascii"
  - "ctype/toascii"
  - "ctype/__toascii"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função toascii"
  - "conversão de cadeia de caracteres, em caracteres ASCII"
  - "Função __toascii"
  - "Caracteres ASCII, convertendo em"
ms.assetid: a07c0608-b0e2-4da2-a20c-7b64d6a9b77c
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ToAscii, ToAscii
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte caracteres em ASCII de 7 bits por truncamento.  
  
## Sintaxe  
  
```  
int __toascii(  
   int c   
);  
#define toascii __toascii  
```  
  
#### Parâmetros  
 `c`  
 Caractere para converter.  
  
## Valor de retorno  
 `__toascii` Converte o valor de `c` para o ASCII de 7 bits de intervalo e retorna o resultado. Não há nenhum valor de retorno reservado para indicar um erro.  
  
## Comentários  
 O `__toascii` rotina converte o caractere especificado para um caractere ASCII truncando\-a para os 7 bits de ordem inferior. Nenhuma outra transformação é aplicada.  
  
 O `__toascii` rotina é definida como uma macro, a menos que a macro do pré\-processador \_CTYPE\_DISABLE\_MACROS está definido. Para compatibilidade com versões anteriores, `toascii` é definido como uma macro somente quando [\_\_STDC\_\_](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, é indefinido.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`toascii`, `__toascii`|C: \< CType \><br /><br /> C\+\+: \< cctype \> ou \< CType \>|  
  
 O `toascii` macro é uma extensão POSIX, e `__toascii` é uma implementação específica da Microsoft da extensão POSIX. Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Funções to](../../c-runtime-library/to-functions.md)