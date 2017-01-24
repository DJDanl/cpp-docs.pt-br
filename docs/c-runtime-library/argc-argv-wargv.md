---
title: "__argc, __argv, __wargv | Microsoft Docs"
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
  - "__wargv"
  - "__argv"
  - "__argc"
apilocation: 
  - "msvcrt120.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__argv"
  - "__argc"
  - "__wargv"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__argc"
  - "__argv"
  - "__wargv"
ms.assetid: 17001b0a-04ad-4762-b3a6-c54847f02d7c
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __argc, __argv, __wargv
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A variável global `__argc` é uma contagem do número de argumentos de linha de comando passados para o programa.  `__argv` é um ponteiro para uma matriz de cadeias de caracteres de caractere de byte único ou de caractere multibyte que contêm os argumentos do programa, e `__wargv` é um ponteiro para uma matriz de cadeias de caracteres de caractere largo que contêm os argumentos do programa.  Essas variáveis globais fornecem os argumentos para `main` ou `wmain`.  
  
## Sintaxe  
  
```  
extern int __argc; extern char ** __argv; extern wchar_t ** __wargv;  
```  
  
## Comentários  
 Em um programa que usa a função `main`,  `__argc` e `__argv` são inicializados na inicialização do programa com a linha de comando usada para iniciar o programa.  A linha de comando é analisada em argumentos individuais, e os curingas são expandidos.  A contagem de argumentos é atribuída ao `__argc` e as cadeias de caracteres de argumento são alocadas no heap, e um ponteiro para a matriz de argumentos é atribuído ao `__argv`.  Em um programa compilado para usar caracteres largos e uma função `wmain`, os argumentos são analisados e os curingas são expandidos como cadeias de caracteres de caractere largo, e um ponteiro para a matriz de cadeias de caracteres de argumento é atribuído ao `__wargv`.  
  
 No caso do código portátil, recomendamos usar os argumentos passados para `main` a fim de obter os argumentos de linha de comando no programa.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE não definido|\_UNICODE definido|  
|--------------------|----------------------------|------------------------|  
|`__targv`|`__argv`|`__wargv`|  
  
## Requisitos  
  
|Variável global|Cabeçalho necessário|  
|---------------------|--------------------------|  
|`__argc`, `__argv`, `__wargv`|\<stdlib.h\>, \<cstdlib\> \(C\+\+\)|  
  
 `__argc`, `__argv` e `__wargv` são extensões da Microsoft.  Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)   
 [main: inicialização do programa](../Topic/main:%20Program%20Startup.md)   
 [Usando wmain em vez main](../cpp/using-wmain-instead-of-main.md)