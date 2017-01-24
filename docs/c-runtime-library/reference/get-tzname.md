---
title: "_get_tzname | Microsoft Docs"
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
  - "_get_tzname"
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
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_get_tzname"
  - "get_tzname"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _get_tzname"
  - "Função get_tzname"
  - "fusos horários"
ms.assetid: df0065ff-095f-4237-832c-2fe9ab913875
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_tzname
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a representação de cadeia de caracteres de nome de fuso horário ou o nome do deslocamento de fuso horário padrão para baixo clara do dia \(DST\).  
  
## Sintaxe  
  
```  
errno_t _get_tzname(  
    size_t* pReturnValue,  
    char* timeZoneName,  
    size_t sizeInBytes,  
    int index      
);  
```  
  
#### Parâmetros  
 \[saída\] `pReturnValue`  
 O comprimento da cadeia de caracteres de `timeZoneName` que inclui um terminador NULL.  
  
 \[saída\] `timeZoneName`  
 O endereço de uma cadeia de caracteres para que representa o nome de fuso horário ou o nome do deslocamento de fuso horário padrão para baixo clara do dia \(DST\), dependendo de `index`.  
  
 \[entrada\] `sizeInBytes`  
 O tamanho da cadeia de caracteres de `timeZoneName` em bytes.  
  
 \[entrada\] `index`  
 O índice de um dos dois nomes de fuso horário a ser recuperado.  
  
## Valor de retorno  
 Zero se bem\-sucedido, caso contrário um valor do tipo de `errno` .  
  
 Se ou `timeZoneName` é `NULL`, ou `sizeInBytes` for nula ou menor que zero \(mas não ambos\), um manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `EINVAL`.  
  
### Condições de erro  
  
|`pReturnValue`|`timeZoneName`|`sizeInBytes`|`index`|Valor de retorno|Conteúdo de `timeZoneName`|  
|--------------------|--------------------|-------------------|-------------|----------------------|--------------------------------|  
|tamanho do nome de TZ|`NULL`|0|0 ou 1|0|não modificado|  
|tamanho do nome de TZ|any|\> 0|0 ou 1|0|A nomeação TZ|  
|não modificado|`NULL`|\> 0|any|`EINVAL`|não modificado|  
|não modificado|any|zero|any|`EINVAL`|não modificado|  
|não modificado|any|\> 0|\> 1|`EINVAL`|não modificado|  
  
## Comentários  
 A função de `_get_tzname` recupera a representação de cadeia de caracteres de nome de fuso horário ou o nome do deslocamento de fuso horário padrão para baixo clara do dia \(DST\) no endereço de `timeZoneName` dependendo do valor de índice, junto com o tamanho da cadeia de caracteres em `pReturnValue`.  Se `timeZoneName` é `NULL` e `sizeInBytes` for zero, apenas o tamanho da cadeia de caracteres de um ou outro fuso horário em bytes será retornado em `pReturnValue`.  Os valores de índice deve ser 0 para o fuso horário padrão ou 1 para o fuso horário padrão para baixo clara do dia; todos os outros valores de índice terão resultados indefinidos.  
  
### Valores de índice  
  
|`index`|Conteúdo de `timeZoneName`|valor padrão de`timeZoneName`|  
|-------------|--------------------------------|-----------------------------------|  
|0|Nome de fuso horário|“PST”|  
|1|Nome do deslocamento de fuso horário padrão para baixo clara do dia|“PDT”|  
|\> 1 ou \< 0|`errno` definido como `EINVAL`|não modificado|  
  
 A menos que os valores sejam alterados explicitamente durante o tempo de execução, os valores padrão são “PST” e “PDT” respectivamente.  Os tamanhos das matrizes de caractere são controlados pelo valor de `TZNAME_MAX` .  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_tzname`|\<time.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md)   
 [\_get\_daylight](../../c-runtime-library/reference/get-daylight.md)   
 [\_get\_dstbias](../../c-runtime-library/reference/get-dstbias.md)   
 [\_get\_timezone](../../c-runtime-library/reference/get-timezone.md)   
 [TZNAME\_MAX](../Topic/TZNAME_MAX.md)