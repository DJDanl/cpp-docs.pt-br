---
title: "_fcvt_s | Microsoft Docs"
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
  - "_fcvt_s"
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
  - "fcvt_s"
  - "_fcvt_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fcvt_s"
  - "convertendo ponto flutuante, em cadeias de caracteres"
  - "Função fcvt_s"
  - "funções de ponto flutuante, convertendo número em cadeia de caracteres"
ms.assetid: 48671197-1d29-4c2b-a5d8-d2368f5f68a1
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fcvt_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um número de ponto flutuante como uma cadeia de caracteres.  Essa é uma versão de [\_fcvt](../Topic/_fcvt.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _fcvt_s(   
   char* buffer,  
   size_t sizeInBytes,  
   double value,  
   int count,  
   int *dec,  
   int *sign   
);  
template <size_t size>  
errno_t _fcvt_s(   
   char (&buffer)[size],  
   double value,  
   int count,  
   int *dec,  
   int *sign   
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `buffer`  
 O buffer fornecido que conterá o resultado da conversão.  
  
 \[entrada\] `sizeInBytes`  
 O tamanho do buffer em bytes.  
  
 \[entrada\] `value`  
 Número a ser convertido.  
  
 \[entrada\] `count`  
 Número de dígitos após o ponto decimal.  
  
 \[saída\] `dec`  
 Ponteiro para a posição do ponto decimal armazenada.  
  
 \[saída\] `sign`  
 Ponteiro para o indicador armazenado de sinal.  
  
## Valor de retorno  
 Nulo se com êxito.  O valor de retorno é um código de erro se houver uma falha.  Os códigos de erro são definidos em Errno.h.  Para uma lista desses erros, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 No caso de um parâmetro inválido, como listados na tabela a seguir, essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `EINVAL`.  
  
### Condições de erro  
  
|`buffer`|`sizeInBytes`|Valor|count|dec|sinal|Return|Valor em `buffer`|  
|--------------|-------------------|-----------|-----------|---------|-----------|------------|-----------------------|  
|`NULL`|any|any|any|any|any|`EINVAL`|Não modificados.|  
|Não `NULL` \(pontos para a memória válido\)|\<\=0|any|any|any|any|`EINVAL`|Não modificados.|  
|any|any|any|any|`NULL`|any|`EINVAL`|Não modificados.|  
|any|any|any|any|any|`NULL`|`EINVAL`|Não modificados.|  
  
 **Problemas de segurança**  
  
 `_fcvt_s` pode gerar uma violação de acesso se `buffer` não aponta para a memória e não é válido `NULL`.  
  
## Comentários  
 A função de `_fcvt_s` converte um número de ponto flutuante como uma cadeia de caracteres com terminação nula.  O parâmetro de `value` é o número de ponto flutuante a ser convertido.  `_fcvt_s` armazena os dígitos de `value` como uma cadeia de caracteres e anexará um caractere nulo \(\\ “0 "\).  O parâmetro de `count` especifica o número de dígitos a serem armazenados após o ponto decimal.  Os dígitos adicionais são arredondados fora para locais de `count` .  Se houver menos do que `count` de dígitos de precisão, a cadeia de caracteres é preenchida com zeros.  
  
 Somente os dígitos são armazenados na cadeia de caracteres.  A posição do ponto decimal e o sinal de `value` podem ser obtidos de `dec` e de `sign` depois da chamada.  O parâmetro de `dec` a um valor inteiro; este valor inteiro da posição do ponto decimal em relação ao início da cadeia de caracteres.  Um valor inteiro negativo ou zero indica que o ponto decimal se encontra à esquerda do primeiro dígito.  Os pontos de `sign` de parâmetro para um inteiro que indica o sinal de `value`.  O inteiro é definido como 0 se `value` é positivo e como um número diferente de zero se `value` é negativo.  
  
 Um buffer de comprimento `_CVTBUFSIZE` é suficiente para qualquer valor de ponto flutuante.  
  
 A diferença entre `_ecvt_s` e `_fcvt_s` está na interpretação de parâmetro de `count` .  `_ecvt_s` interpreta `count` como o número total de dígitos na cadeia de caracteres de saída, e `_fcvt_s` interpretam c`ount` como o número de dígitos após o ponto decimal.  
  
 Em C\+\+, usar essa função é simplificada por uma sobrecarga de modelo; a sobrecarga poderá deduzir o comprimento do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 A versão de depuração dessa função preenche o primeiro buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_fcvt_s`|\<stdlib.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** Todas as versões das [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// fcvt_s.c  
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
  
int main()  
{  
  char * buf = 0;  
  int decimal;  
  int sign;  
  int err;  
  
  buf = (char*) malloc(_CVTBUFSIZE);  
  err = _fcvt_s(buf, _CVTBUFSIZE, 1.2, 5, &decimal, &sign);  
  
  if (err != 0)  
  {  
     printf("_fcvt_s failed with error code %d\n", err);  
     exit(1);  
  }  
  
  printf("Converted value: %s\n", buf);    
  
}  
```  
  
  **Valor convertido: 120000**   
## Equivalência do .NET Framework  
 <xref:System.Convert.ToString%2A>  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)   
 [\_ecvt\_s](../Topic/_ecvt_s.md)   
 [\_gcvt\_s](../../c-runtime-library/reference/gcvt-s.md)   
 [\_fcvt](../Topic/_fcvt.md)