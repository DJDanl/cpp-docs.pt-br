---
title: "Macros de vari&#225;vel de ambiente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "variáveis de ambiente, macros em NMAKE"
  - "Macros , Variável de ambiente"
  - "programa NMAKE, macros de variável de ambiente"
ms.assetid: f8e96635-0906-47b0-9f56-12a6fdf5e347
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros de vari&#225;vel de ambiente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

NMAKE herda definições macro para as variáveis de ambiente que existam antes do início da sessão.  Se uma variável foi definido no ambiente de sistema operacional, está disponível como uma macro de NMAKE.  Os nomes herdados são convertidos em maiúsculas.  A herança ocorre antes de pré\-processamento.  Use a opção \/E causar macros herdados de variáveis de ambiente para substituir todas as macros com o mesmo nome no makefile.  
  
 Macros da variável de ambiente podem ser reiniciados na sessão, e esse alterar a variável de ambiente correspondente.  Você também pode modificar as variáveis de ambiente com o comando SET.  Usar o comando SET. modificar uma variável de ambiente em uma sessão não altera a macro correspondente, porém.  
  
 Por exemplo:  
  
```  
PATH=$(PATH);\nonesuch  
  
all:  
    echo %PATH%  
```  
  
 Neste exemplo, altere `PATH` alterar a variável de ambiente correspondente `PATH`; anexa `\nonesuch` ao caminho.  
  
 Se uma variável de ambiente é definido como uma cadeia de caracteres que está sintaticamente incorretas em um makefile, nenhuma macro é criado e nenhum aviso é gerado.  Se um valor de variável contiver um cifrão \($\), NMAKE interpreta\-o como o início de uma invocação macro.  Usar a macro pode causar um comportamento inesperado.  
  
## Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)