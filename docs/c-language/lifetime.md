---
title: "Tempo de vida | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "classe de armazenamento automático"
  - "classe de armazenamento automático, duração"
  - "alocação de memória dinâmica"
  - "funções [C++], tempo de vida"
  - "variáveis globais, tempo de vida"
  - "tempo de vida"
  - "variáveis locais, tempo de vida"
  - "alocação de memória, dynamic"
  - "alocação de memória, alocação dinâmica"
  - "especificadores de classe de armazenamento, duração do armazenamento"
  - "classes de armazenamento, tempo de vida"
  - "duração do armazenamento"
  - "variáveis, automático"
  - "variáveis, tempo de vida"
ms.assetid: ff0b42cb-3f0f-49a3-a94f-d1d825d8ddfe
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tempo de vida
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O “tempo de vida” é o período durante a execução de um programa em que uma variável ou uma função existe.  A duração de armazenamento de identificador determina seu tempo de vida.  
  
 Um identificador declarado com *especificador de classe de armazenamento* **static** tem a duração de armazenamento estático.  Os identificadores com a duração de armazenamento estático \(também chamados de “globais”\) têm o armazenamento e um valor definido para a duração de um programa.  O armazenamento é reservado e o valor armazenado do identificador é inicializado apenas uma vez, antes da inicialização do programa.  Um identificador declarado com vinculação externa ou interna também tem a duração de armazenamento estático \(consulte [Vinculação](../c-language/linkage.md)\).  
  
 Um identificador declarado sem o especificador de classe de armazenamento **static** tem a duração automática de armazenamento se declarada na função.  Um identificador com duração automática de armazenamento \(um "identificador local"\) tem armazenamento e um valor definido apenas dentro do bloco no qual que o identificador está definido ou declarado.  Um identificador automático é alocado ao novo armazenamento sempre que o programa entrar nesse bloco, e perde seu armazenamento \(e seu valor\) quando o programa sai do bloco.  Os identificadores declarados em uma função sem vinculação também têm a duração automática de armazenamento.  
  
 As regras a seguir especificam se um identificador tem tempo de vida global \(estático\) ou local \(automático\):  
  
-   Todas as funções têm tempo de vida estático.  Portanto, elas existem em sempre durante a execução do programa.  Os identificadores declarados no nível externo \(ou seja, fora de todos os blocos no programa no mesmo nível das definições de função\) sempre têm o tempo de vida global \(estático\).  
  
-   Se uma variável local tiver um inicializador, a variável será inicializada sempre que for criada \(a menos que seja declarada como **static**\).  Os parâmetros de função também têm o tempo de vida local.  Você pode especificar o tempo de vida global de um identificador dentro de um bloco incluindo o especificador de classe de armazenamento **static** em sua declaração.  Quando declarada **static**, a variável retém seu valor de uma entrada do bloco para a próxima.  
  
 Embora um identificador com um tempo de vida global exista durante a execução do programa de origem \(por exemplo, uma variável declarada externamente ou uma variável local declarada com a palavra\-chave **static**\), ele pode não ficar visível em todas as partes do programa.  Consulte [Escopo e visibilidade](../c-language/scope-and-visibility.md) para obter informações sobre visibilidade, e consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para visualizar uma discussão do não terminal *especificador de classe de armazenamento*.  
  
 A memória pode ser alocada conforme necessário \(dinâmica\) se criada com o uso de rotinas de biblioteca especiais como `malloc`.  Como a alocação de memória dinâmica usa rotinas de biblioteca, não é considerado como parte da linguagem.  Consulte a função [malloc](../c-runtime-library/reference/malloc.md) na *Referência da biblioteca em tempo de execução*.  
  
## Consulte também  
 [Tempo de vida, escopo, visibilidade e ligação](../Topic/Lifetime,%20Scope,%20Visibility,%20and%20Linkage.md)