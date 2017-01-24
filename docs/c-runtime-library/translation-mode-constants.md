---
title: "Constantes do modo de transla&#231;&#227;o | Microsoft Docs"
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
  - "_O_BINARY"
  - "_O_TEXT"
  - "_O_RAW"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _O_BINARY"
  - "Constante _O_RAW"
  - "Constante _O_TEXT"
  - "Constante O_BINARY"
  - "Constante O_RAW"
  - "Constante O_TEXT"
  - "constantes de tradução"
  - "arquivos de modo de tradução (E/S de arquivo)"
  - "tradução, constantes"
  - "tradução, modos"
ms.assetid: a5993bf4-7e7a-47f9-83c3-e46332b85579
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes do modo de transla&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <fcntl.h>  
  
```  
  
## Comentários  
 `_O_BINARY` e `_O_TEXT` manifestam constantes determinam o modo de conversão de arquivos \(`_open` e `_sopen`\) ou o modo de conversão de fluxos`_setmode`\(\).  
  
 Os valores permitidos são:  
  
 `_O_TEXT`  
 Abre o arquivo no modo de texto traduzido \(\).  Retorno de carro – as combinações de alimentação de linha \(CR\-LF\) são convertidas em uma única avanço de linha \(LF\) na entrada.  Os caracteres de alimentação de linha são convertidos em combinações de CR\-LF na saída.  Além disso, CTRL\+Z é interpretado como um caractere de participante de Arquivo na entrada.  Em arquivos abertos leitura e leitura\/gravação, `fopen` verifica se há CTRL\+Z no final do arquivo e solte\-o, se possível.  Isso é feito como usar as funções de `fseek` e de `ftell` para mover dentro de um final do arquivo com CTRL\+Z pode fazer com que `fseek` se com comportamento de forma incorreta próximo do fim do arquivo.  
  
 `_O_BINARY`  
 Abre o arquivo no modo binário não traduzido \(\).  As traduções acima são suprimida.  
  
 `_O_RAW`  
 Mesmo que `_O_BINARY`.  Suporte para compatibilidade de C 2.0.  
  
 Para obter mais informações, consulte [Modo de E\/S de Arquivo de texto e binários](../c-runtime-library/text-and-binary-mode-file-i-o.md) e [Conversão de Arquivo](../c-runtime-library/file-translation-constants.md).  
  
## Consulte também  
 [\_open, \_wopen](../c-runtime-library/reference/open-wopen.md)   
 [\_pipe](../c-runtime-library/reference/pipe.md)   
 [\_sopen, \_wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [\_setmode](../c-runtime-library/reference/setmode.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)