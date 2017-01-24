---
title: "&lt;iostream&gt; | Microsoft Docs"
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
  - "std.<iostream>"
  - "std::<iostream>"
  - "<iostream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho iostream"
ms.assetid: de5d39e1-7e77-4b55-bcd1-7c77b41515c8
caps.latest.revision: 23
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;iostream&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara objetos que controlam a leitura e gravação para fluxos padrão.  Isso geralmente é o cabeçalho só que é necessário incluir para executar a entrada e saída de um programa C\+\+.  
  
## Sintaxe  
  
```  
  
#include <iostream>  
  
```  
  
## Comentários  
 Os objetos se dividem em dois grupos:  
  
-   [cin](../Topic/cin.md), [cout](../Topic/cout.md), [cerr](../Topic/cerr.md), e [obstruir](../Topic/clog.md) são byte orientada ao executar transferências de bytes no tempo convencionais.  
  
-   [wcin](../Topic/wcin.md), [wcout](../Topic/wcout.md), [wcerr](../Topic/wcerr.md), e [wclog](../Topic/wclog.md) ampla orientadas, conversão de e para os caracteres largos que o programa manipula internamente.  
  
 Quando você executa determinadas operações em um fluxo, como a entrada padrão, você não pode executar operações de uma orientação diferente no mesmo fluxo.  Portanto, um programa não pode operar alternadamente em ambos os [cin](../Topic/cin.md) e [wcin](../Topic/wcin.md), por exemplo.  
  
 Todos os objetos declarados nesse compartilhamento de cabeçalho uma propriedade peculiar — você pode assumir que são construídas antes que qualquer membro estático objetos define, em uma unidade de conversão que inclui \< iostream \>.  Igualmente, você pode supor que esses objetos não são destruídos antes dos destruidores para esses objetos de estáticos que você definir.  \(Os fluxos de saída são, no entanto, liberados durante o encerramento do programa.\) Portanto, com segurança podem ler ou gravar fluxos padrão antes da inicialização do programa e após o encerramento do programa.  
  
 Essa garantia não é universal, no entanto.  Um construtor estático pode chamar uma função em outra unidade de tradução.  A função chamada não pode assumir que os objetos declarados nesse cabeçalho foram construídos, dada a incerteza ordem em que a conversão de unidades de participarem de construção estática.  Para usar esses objetos em um contexto tal, você deve primeiro criar um objeto da classe [ios\_base:: init](../Topic/ios_base::Init.md).  
  
### Objetos de fluxo global  
  
|||  
|-|-|  
|[cerr](../Topic/cerr.md)|Especifica o `cerr` fluxo global.|  
|[cin](../Topic/cin.md)|Especifica o `cin` fluxo global.|  
|[clog](../Topic/clog.md)|Especifica o `clog` fluxo global.|  
|[cout](../Topic/cout.md)|Especifica o `cout` fluxo global.|  
|[wcerr](../Topic/wcerr.md)|Especifica o `wcerr` fluxo global.|  
|[wcin](../Topic/wcin.md)|Especifica o `wcin` fluxo global.|  
|[wclog](../Topic/wclog.md)|Especifica o `wclog` fluxo global.|  
|[wcout](../Topic/wcout.md)|Especifica o `wcout` fluxo global.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)