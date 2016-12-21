---
title: "stdin, stdout, stderr | Microsoft Docs"
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
  - "stdin"
  - "stderr"
  - "stdout"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "fluxo de erro padrão"
  - "fluxo de entrada padrão"
  - "fluxo de saída padrão"
  - "Função stderr"
  - "Função stdin"
  - "Função stdout"
ms.assetid: badd4735-596d-4498-857c-ec8b7e670e4c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# stdin, stdout, stderr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
      FILE *stdin;   
FILE *stdout;   
FILE *stderr;   
#include <stdio.h>  
```  
  
## Comentários  
 Esses são fluxos padrão para a entrada, as saídas, e a saída de erro.  
  
 Por padrão, a entrada padrão será lido de teclado, quando a saída padrão e o erro padrão são impressos na tela.  
  
 Estes ponteiros de fluxo estão disponíveis para acessar os fluxos padrão:  
  
|Ponteiro|Fluxo|  
|--------------|-----------|  
|`stdin`|Entrada padrão|  
|**stdout**|Saída padrão|  
|`stderr`|Erro padrão|  
  
 Esses ponteiros podem ser usados como argumentos para as funções.  Algumas funções, como **getchar** e `putchar`, use `stdin` e **stdout** automaticamente.  
  
 Esses ponteiros são constantes, e não podem ser atribuídos novos valores.  A função de `freopen` pode ser usada para redirecionar fluxos em arquivos de disco ou outros dispositivos.  O sistema operacional permite redirecionar uma entrada e uma saída padrão de programa no nível de comando.  
  
## Consulte também  
 [E\/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)