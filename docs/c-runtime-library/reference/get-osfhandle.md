---
title: "_get_osfhandle | Microsoft Docs"
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
  - "_get_osfhandle"
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
  - "get_osfhandle"
  - "_get_osfhandle"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "sistemas operacionais, obtendo identificadores de arquivos"
  - "Função get_osfhandle"
  - "Função _get_osfhandle"
  - "identificadores de arquivo [C++], sistema operacional"
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_osfhandle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o identificador de arquivo do sistema operacional que é associado ao descritor de arquivo especificado.  
  
## Sintaxe  
  
```  
intptr_t _get_osfhandle(   
   int fd   
);  
```  
  
#### Parâmetros  
 `fd`  
 Um descritor de arquivo existente.  
  
## Valor de retorno  
 Um identificador de arquivo do sistema operacional se `fd` é válido.  Caso contrário, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, retorna `INVALID_HANDLE_VALUE` dessa função \(– 1\) e definem `errno` a `EBADF`, indicando um identificador de arquivo inválido.  
  
## Comentários  
 Para fechar um arquivo aberto com `_get_osfhandle`, chame `_close`.  O identificador subjacente também é fechada por uma chamada a `_close`portanto, não é necessário chamar a função `CloseHandle` do Win32 no identificador original.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_osfhandle`|\<io.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_close](../Topic/_close.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_dup, \_dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)