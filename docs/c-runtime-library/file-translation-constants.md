---
title: "Constantes de transla&#231;&#227;o de arquivo | Microsoft Docs"
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
  - "c.constants.file"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "constantes [C++], modo de tradução de arquivo"
  - "tradução de arquivo [C++]"
  - "tradução de arquivo [C++], constantes"
  - "constantes de tradução"
  - "tradução, constantes"
  - "tradução, constantes de tradução de arquivo"
ms.assetid: 49b13bf3-442e-4d19-878b-bd1029fa666a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de transla&#231;&#227;o de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## Comentários  
 Essas constantes especificam o modo de conversão \(**"b"** ou **"t"**\).  O modo é incluído na cadeia de caracteres que especifica o tipo de acesso \(**"r"**, **"w"**, **"a"**, **"r\+"**, **"w\+"**, **"a\+"**\).  
  
 Os modos de tradução são os seguintes:  
  
 **t**  
 É aberto no modo de texto traduzido \(\).  Nesse modo, as combinações de retorno\/avanço de linha \(CR\-LF\) são convertidas em únicas avanço de linha \(LF\) na entrada, e os caracteres de LF são convertidos em combinações de CR\-LF na saída.  Além disso, CTRL\+Z é interpretado como um caractere de participante de Arquivo na entrada.  Em arquivos abertos leitura ou leitura\/gravação, `fopen` verifica se há CTRL\+Z no final do arquivo e solte\-o, se possível.  Isso é feito como usar as funções de `fseek` e de `ftell` para mover dentro de um final do arquivo com CTRL\+Z pode fazer com que `fseek` se com comportamento de forma incorreta próximo do fim do arquivo.  
  
> [!NOTE]
>  A opção de **t** não é parte do padrão ANSI para `fopen` e `freopen`.  É uma extensão da Microsoft e não deve ser usado onde a portabilidade de ANSI é desejada.  
  
 **b**  
 É aberto no modo binário não traduzido \(\).  As traduções acima são suprimida.  
  
 Se **t** ou **b** não são dados no *modo*, o modo de conversão é definido pela variável [\_fmode](../c-runtime-library/fmode.md)de modo padrão.  Para obter mais informações sobre como usar os modos de texto e binários, consulte [O modo de texto e binários de E\/S](../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
## Consulte também  
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [fopen, \_wfopen](../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, \_wfreopen](../c-runtime-library/reference/freopen-wfreopen.md)   
 [\_fsopen, \_wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)