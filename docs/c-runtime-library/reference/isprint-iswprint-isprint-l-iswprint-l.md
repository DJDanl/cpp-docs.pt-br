---
title: "isprint, iswprint, _isprint_l, _iswprint_l | Microsoft Docs"
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
  - "iswprint"
  - "isprint"
  - "_isprint_l"
  - "_iswprint_l"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "iswprint"
  - "_istprint"
  - "isprint"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _isprint_l"
  - "Função _istprint"
  - "Função _iswprint_l"
  - "Função isprint"
  - "Função isprint_l"
  - "Função istprint"
  - "Função iswprint"
  - "Função iswprint_l"
ms.assetid: a8bbcdb0-e8d0-4d8c-ae4e-56d3bdee6ca3
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isprint, iswprint, _isprint_l, _iswprint_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um número inteiro representa um caractere de impressão.  
  
## Sintaxe  
  
```  
int isprint(  
   int c   
);  
int iswprint(  
   wint_t c   
);  
int _isprint_l(  
   int c,  
   _locale_t locale  
);  
int _iswprint_l(  
   wint_t c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas rotinas retorna diferente de zero se `c` for uma representação específica de um caractere imprimível.  `isprint` retorna um valor diferente de zero se `c` for um caractere imprimível, isso inclui o caractere de espaço \(0x20 – 0x7E\).  `iswprint` retorna um valor diferente de zero se `c` for um caractere largo imprimível, isso inclui o caractere largo de espaço.  Cada uma dessas rotinas retornará 0 se `c` não atender à condição de teste.  
  
 O resultado da condição de teste para essas funções de depende da configuração da categoria `LC_CTYPE` da localidade; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções que não têm o sufixo de `_l` usam a localidade atual para qualquer comportamento dependente de local; as versões que têm o sufixo de `_l` são idênticas, exceto as que usam a localidade que é passada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `isprint` e de `_isprint_l` é indefinido se `c` não é EOF ou no intervalo 0 0xFF direto, inclusive.  Quando uma biblioteca de CRT de depuração é usada e o `c` e não é um desses valores, as funções geram uma declaração.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_unicode definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|**\_** `istprint`|`isprint`|[\_ismbcprint](../../c-runtime-library/reference/ismbcgraph-functions.md)|`iswprint`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isprint`|\<ctype.h\>|  
|`iswprint`|\<ctype.h\> ou \<wchar.h\>|  
|`_isprint_l`|\<ctype.h\>|  
|`_iswprint_l`|\<ctype.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)