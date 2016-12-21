---
title: "_set_printf_count_output | Microsoft Docs"
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
  - "_set_printf_count_output"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_printf_count_output"
  - "_set_printf_count_output"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "formato %n"
  - "Função _set_printf_count_output"
  - "Função set_printf_count_output"
ms.assetid: d8259ec5-764e-42d0-9169-72172e95163b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_printf_count_output
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilitar ou desabilitar suporte de formato em [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)\- funções de `%n` de família.  
  
## Sintaxe  
  
```  
int _set_printf_count_output(  
   int enable  
);  
```  
  
#### Parâmetros  
 `enable`  
 Um valor diferente de zero para habilitar o suporte de `%n` , 0 para desabilitar o suporte de `%n` .  
  
## Valor de propriedade\/valor de retorno  
 O estado de suporte de `%n` antes de chamar essa função: diferente de zero se o suporte de `%n` foi habilitado, 0 se foi desabilitado.  
  
## Comentários  
 Por questões de segurança, o suporte para o especificador de formato de `%n` é desabilitado por padrão em `printf` e em todas as variantes.  Se `%n` é encontrado em uma especificação do formato de `printf` , o comportamento padrão é chamar o manipulador inválido do parâmetro como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  A chamada `_set_printf_count_output` com um argumento diferente de zero faz com que `printf`\- funções de família para interpretar `%n` conforme descrito em [Caracteres de campo de tipo printf](../../c-runtime-library/printf-type-field-characters.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_printf_count_output`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_set_printf_count_output.c  
#include <stdio.h>  
  
int main()  
{  
   int e;  
   int i;  
   e = _set_printf_count_output( 1 );  
   printf( "%%n support was %sabled.\n",  
        e ? "en" : "dis" );  
   printf( "%%n support is now %sabled.\n",  
        _get_printf_count_output() ? "en" : "dis" );  
   printf( "12345%n6789\n", &i ); // %n format should set i to 5  
   printf( "i = %d\n", i );  
}  
```  
  
## Saída  
  
```  
%n support was disabled.  
%n support is now enabled.  
123456789  
i = 5  
```  
  
## Equivalente ao .NET Framework  
 Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_get\_printf\_count\_output](../../c-runtime-library/reference/get-printf-count-output.md)