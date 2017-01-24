---
title: "_setmaxstdio | Microsoft Docs"
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
  - "_setmaxstdio"
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
  - "setmaxstdio"
  - "_setmaxstdio"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _setmaxstdio"
  - "máximo de arquivos abertos"
  - "arquivos abertos, máximo"
  - "Função setmaxstdio"
ms.assetid: 9e966875-9ff5-47c4-9b5f-e79e83b70249
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _setmaxstdio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um máximo para o número de arquivos abertos simultaneamente em `stdio` em nível.  
  
## Sintaxe  
  
```  
int _setmaxstdio(  
   int newmax   
);  
```  
  
#### Parâmetros  
 `newmax`  
 Novo máximo para o número de arquivos abertos simultaneamente em `stdio` em nível.  
  
## Valor de retorno  
 Retorna `newmax` se bem\-sucedido; – 1 de outra forma.  
  
 Se `newmax` é menor que `_IOB_ENTRIES` ou maior que o número máximo de identificadores disponíveis no sistema operacional, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, os essa função retornará \-1 e definirá `errno` a `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_setmaxstdio` o valor máximo para o número de arquivos que podem estar simultaneamente abertos em `stdio` em nível.  
  
 O tempo de execução E\/S C agora oferece suporte muito mais arquivos abertos em plataformas Win32 do que nas versões anteriores.  Até 2.048 arquivos podem ser abertos simultaneamente em [lowio em nível](../../c-runtime-library/low-level-i-o.md) \(ou seja, aberto e acessado por meio de `_open`, de `_read`, de `_write`, e assim por diante família de funções de E\/S\).  Até 512 arquivos podem ser abertos simultaneamente em [stdio em nível](../../c-runtime-library/stream-i-o.md) \(ou seja, aberto e acessado por meio de `fopen`, de `fgetc`, de `fputc`, e assim por diante família das funções\).  O limite de 512 arquivos abertos no nível de `stdio` pode ser aumentado a um máximo de 2.048 por meio da função de `_setmaxstdio` .  
  
 Como `stdio`\- as funções de nível, como `fopen`, são criadas sobre as funções de `lowio` , o máximo de 2.048 é um limite superior difícil para o número de arquivos abertos simultaneamente acessados pela biblioteca de tempo de execução C.  
  
> [!NOTE]
>  Esse limite superior pode ser além do que tem suporte por uma plataforma e por uma configuração específicos do Win32.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_setmaxstdio`|\<stdio.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte [\_getmaxstdio](../../c-runtime-library/reference/getmaxstdio.md) para obter um exemplo de como usar `_setmaxstdio`.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)