---
title: "_setmbcp | Microsoft Docs"
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
  - "_setmbcp"
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
  - "api-ms-win-crt-locale-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_setmbcp"
  - "setmbcp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _setmbcp"
  - "páginas de código multibyte"
  - "Função setmbcp"
ms.assetid: cfde53b5-0b73-4684-81b1-a8d3aafc85de
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _setmbcp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define uma nova página de código de multibyte.  
  
## Sintaxe  
  
```  
int _setmbcp(  
   int codepage   
);  
```  
  
#### Parâmetros  
 `codepage`  
 Novo composição de código para rotinas com independentes multibyte.  
  
## Valor de retorno  
 Retornará 0 se a página de código é definida com êxito.  Se um valor inválido de página de código é fornecido para `codepage`, 1 será retornado e a composição do código é inalterados.  Define `errno` a `EINVAL` se uma falha de alocação de memória ocorre.  
  
## Comentários  
 A função de `_setmbcp` especifica uma nova página de código de multibyte.  Por padrão, o sistema de tempo de execução define automaticamente a página de código de multibyte para a página de código ANSI de sistema padrão.  A composição de código de multibyte afeta todas as rotinas de multibyte que não é dependente da localidade.  No entanto, é possível instruir `_setmbcp` para usar a página de código definido para a localidade atual \(consulte a seguinte lista de manifestas e constantes de resultados associada do comportamento\).  Para obter uma lista das rotinas multibyte dependentes na página de código da localidade em vez da página de código de multibyte, consulte [Interpretação de sequências de caracteres Multibyte\-](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).  
  
 A página de código de multibyte também afeta o processamento de multibyte\- caractere por seguintes rotinas de biblioteca de tempo de execução:  
  
||||  
|-|-|-|  
|[funções de \_exec](../../c-runtime-library/exec-wexec-functions.md)|[\_mktemp](../../c-runtime-library/reference/mktemp-wmktemp.md)|[\_stat](../../c-runtime-library/reference/stat-functions.md)|  
|[\_fullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)|[funções de \_spawn](../Topic/_spawn,%20_wspawn%20Functions.md)|[\_tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
|[\_makepath](../../c-runtime-library/reference/makepath-wmakepath.md)|[\_splitpath](../Topic/_splitpath,%20_wsplitpath.md)|[tmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
  
 Além disso, todas as rotinas de biblioteca de tempo de execução que recebem o multibyte\- caractere `argv` ou argumentos de programa de `envp` como parâmetros \(como as famílias de `_exec` e de `_spawn` \) processam essas cadeias de caracteres de acordo com a página de código de multibyte.  Em virtude disso, essas rotinas também são afetadas por uma chamada a `_setmbcp` que modifica a página de código de multibyte.  
  
 O argumento de `codepage` pode ser definido como qualquer um dos seguintes valores:  
  
-   `_MB_CP_ANSI` Use a página de código ANSI obtida do sistema operacional na inicialização do programa.  
  
-   `_MB_CP_LOCALE` Use a página de código atual da localidade obtido de uma chamada a anterior [setlocale](../Topic/setlocale,%20_wsetlocale.md).  
  
-   `_MB_CP_OEM` Use a página de código OEM obtida do sistema operacional na inicialização do programa.  
  
-   `_MB_CP_SBCS` Use a página de código de um byte.  Quando a página de código é definida como `_MB_CP_SBCS`, uma rotina como [\_ismbblead](../../c-runtime-library/reference/ismbblead-ismbblead-l.md) sempre retorna false.  
  
-   Qualquer outro valor válido da página de código, independentemente do valor é ANSI, OEM, ou outra página de código operar\-sistema\- suporte \(exceto UTF\-7 e UTF\-8, que não têm suporte\).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_setmbcp`|\<mbctype.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Consulte também  
 [\_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)