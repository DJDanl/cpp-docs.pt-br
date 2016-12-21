---
title: "E/S de texto e arquivo de modo bin&#225;rio | Microsoft Docs"
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
  - "c.io"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "acesso binário"
  - "acesso binário, E/S de arquivo de modo binário"
  - "Arquivos  [C++], Funções open"
  - "Funções [CRT], acesso a arquivos"
  - "E/S [CRT], binário"
  - "E/S [CRT], arquivos de texto"
  - "E/S [CRT], modos de tradução"
  - "arquivos de texto, E/S"
  - "arquivos de modo de tradução (E/S de arquivo)"
  - "tradução, modos"
ms.assetid: 3196e321-8b87-4609-b302-cd6f3c516051
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# E/S de texto e arquivo de modo bin&#225;rio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As operações de E\/S de Arquivo ocorrem em um de dois modos de tradução, texto ou binário, dependendo do modo em que o arquivo é aberto.  Os arquivos de dados são processados em geral no modo de texto.  Para controlar o modo de conversão de arquivo, um pode:  
  
-   Mantenha a configuração padrão atual e especifique o modo alternativo somente quando você abre arquivos selecionados.  
  
-   Use a função [\_set\_fmode](../c-runtime-library/reference/set-fmode.md) para alterar o modo padrão para arquivos abertos recentemente.  Use [\_get\_fmode](../c-runtime-library/reference/get-fmode.md) para localizar o modo padrão atual.  A configuração padrão inicial é o modo de texto \(`_O_TEXT`\).  
  
-   Alterar o modo padrão de conversão diretamente definindo a variável global [\_fmode](../c-runtime-library/fmode.md) em seu programa.  A função `_set_fmode` define o valor dessa variável, mas também pode ser definida corretamente.  
  
 Quando você chama uma função de arquivo como Abrir [\_open](../c-runtime-library/reference/open-wopen.md), [fopen](../c-runtime-library/reference/fopen-wfopen.md), [fopen\_s](../c-runtime-library/reference/fopen-s-wfopen-s.md), [freopen](../c-runtime-library/reference/freopen-wfreopen.md), [freopen\_s](../c-runtime-library/reference/freopen-s-wfreopen-s.md), [\_fsopen](../c-runtime-library/reference/fsopen-wfsopen.md) ou [\_sopen\_s](../c-runtime-library/reference/sopen-s-wsopen-s.md), você pode substituir a configuração padrão atual de `_fmode` especificando o argumento apropriado à função [\_set\_fmode](../c-runtime-library/reference/set-fmode.md).  `stdin`, `stdout`, e os fluxos de `stderr` sempre são abertos no modo de texto por padrão; você também pode substituir esse padrão ao abrir qualquer um desses arquivos.  O uso [\_setmode](../c-runtime-library/reference/setmode.md) alterar o modo de conversão que usa o descritor de arquivo após o arquivo é aberto.  
  
## Consulte também  
 [Entrada e saída](../Topic/Input%20and%20Output.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)