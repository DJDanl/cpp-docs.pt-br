---
title: "_fmode | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "fmode"
  - "_fmode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tradução de arquivo [C++], modo padrão"
  - "Função fmode"
  - "Função _fmode"
ms.assetid: ac6df9eb-e5cc-4c54-aff3-373c21983118
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fmode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A variável de `_fmode` define o modo padrão de arquivo tradução para a conversão de texto ou binários.  Essa variável global foi substituído para o mais seguro [\_get\_fmode](../c-runtime-library/reference/get-fmode.md) versões funcionais e [\_set\_fmode](../c-runtime-library/reference/set-fmode.md), que devem ser usados no lugar da variável global.  É declarada em Stdlib.h seguinte maneira.  
  
## Sintaxe  
  
```  
extern int _fmode;  
```  
  
## Comentários  
 A configuração padrão de `_fmode` é `_O_TEXT` para a conversão de modo gráfico.  `_O_BINARY` é a configuração do modo binário.  
  
 Você pode alterar o valor de `_fmode` de três maneiras:  
  
-   Link com o Binmode.obj.  Isso altera a configuração inicial de `_fmode` a `_O_BINARY`, fazendo com que todos os arquivos diferente que `stdin`, `stdout`, e `stderr` a ser aberto no modo binário.  
  
-   Chame um a `_get_fmode` ou a `_set_fmode` para obter ou definir a variável global de `_fmode` , respectivamente.  
  
-   Altere o valor de `_fmode` diretamente definindo o em seu programa.  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)   
 [\_get\_fmode](../c-runtime-library/reference/get-fmode.md)   
 [\_set\_fmode](../c-runtime-library/reference/set-fmode.md)