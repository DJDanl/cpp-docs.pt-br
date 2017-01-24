---
title: "_gcvt_s | Microsoft Docs"
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
  - "_gcvt_s"
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
  - "_gcvt_s"
  - "gcvt_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "_CVTBUFSIZE"
  - "Função _gcvt_s"
  - "conversões, ponto flutuante para cadeias de caracteres"
  - "CVTBUFSIZE"
  - "funções de ponto flutuante, convertendo número em cadeia de caracteres"
  - "Função gcvt_s"
  - "números, convertendo em cadeias de caracteres"
  - "cadeias de caracteres [C++], convertendo de ponto flutuante"
ms.assetid: 0a8d8a26-5940-4ae3-835e-0aa6ec1b0744
caps.latest.revision: 30
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _gcvt_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um valor de ponto flutuante como uma cadeia de caracteres.  Essa é uma versão de [\_gcvt](../../c-runtime-library/reference/gcvt.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _gcvt_s(   
   char *buffer,  
   size_t sizeInBytes,  
   double value,  
   int digits   
);  
template <size_t cchStr>  
errno_t _gcvt_s(   
   char (&buffer)[cchStr],  
   double value,  
   int digits   
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `buffer`  
 Buffer para armazenar o resultado da conversão.  
  
 \[entrada\] `sizeInBytes`  
 O tamanho do buffer.  
  
 \[entrada\] `value`  
 Valor a ser convertido.  
  
 \[entrada\] `digits`  
 Número de dígitos significativos armazenados.  
  
## Valor de retorno  
 Nulo se com êxito.  Se ocorrer uma falha devido a um parâmetro inválido \(consulte a tabela a seguir para valores inválidos\), o manipulador inválido do parâmetro será invocado como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, um código de erro será retornado.  Os códigos de erro são definidos em Errno.h.  Para uma lista desses erros, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
### Condições de erro  
  
|`buffer`|`sizeInBytes`|`value`|`digits`|Return|Valor em `buffer`|  
|--------------|-------------------|-------------|--------------|------------|-----------------------|  
|`NULL`|any|any|any|`EINVAL`|Não modificados.|  
|Não `NULL` \(pontos para a memória válido\)|zero|any|any|`EINVAL`|Não modificados.|  
|Não `NULL` \(pontos para a memória válido\)|any|any|\>\= `sizeInBytes`|`EINVAL`|Não modificados.|  
  
 **Problemas de segurança**  
  
 `_gcvt_s` pode gerar uma violação de acesso se `buffer` não aponta para a memória e não é válido `NULL`.  
  
## Comentários  
 A função de `_gcvt_s` converte `value` de ponto flutuante como uma cadeia de caracteres \(que inclui um ponto decimal opcional e um byte que o sinal\) e armazena a cadeia de caracteres em `buffer`.  `buffer` deve ser grande o suficiente para acomodar o valor convertido mais um caractere terminador nulo, que é acrescentado automaticamente.  Um buffer de comprimento `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante.  Se um tamanho do buffer de `digits` \+ 1 for usado, a função não substituirá a extremidade do buffer portanto, certifique\-se de fornecer um buffer suficiente para esta operação.  `_gcvt_s` tenta gerar dígitos de `digits` em formato decimal.  Se não puder, gerencia dígitos de `digits` no formato exponencialmente.  Zeros à direita podem ser suprimidos na conversão.  
  
 Em C\+\+, usar essa função é simplificada por uma sobrecarga de modelo; a sobrecarga poderá deduzir o comprimento do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 A versão de depuração dessa função preenche o primeiro buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_gcvt_s`|\<stdlib.h\>|\<error.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_gcvt_s.c  
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
  
int main()  
{  
  char buf[_CVTBUFSIZE];  
  int decimal;  
  int sign;  
  int err;  
  
  err = _gcvt_s(buf, _CVTBUFSIZE, 1.2, 5);  
  
  if (err != 0)  
  {  
     printf("_gcvt_s failed with error code %d\n", err);  
     exit(1);  
  }  
  
  printf("Converted value: %s\n", buf);    
  
}  
```  
  
  **Valor convertido: 1,2**   
## Equivalência do .NET Framework  
 <xref:System.Convert.ToString%2A>  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [\_ecvt\_s](../Topic/_ecvt_s.md)   
 [\_fcvt\_s](../../c-runtime-library/reference/fcvt-s.md)   
 [\_gcvt](../../c-runtime-library/reference/gcvt.md)