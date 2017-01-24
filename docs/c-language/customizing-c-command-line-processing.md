---
title: "Personalizando processamento de linha de comando C | Microsoft Docs"
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
  - "Função _exec"
  - "Função _setargv"
  - "Funções _spawn"
  - "linha de comando, processando"
  - "linha de comando, processando argumentos"
  - "processamento de linha de comando"
  - "ambiente, rotina de processamento de ambiente"
  - "código de inicialização, personalizando o processamento de linha de comando"
  - "suprimindo o processamento de ambiente"
ms.assetid: c20fa11d-b35b-4f3e-93b6-2cd5a1c3c993
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personalizando processamento de linha de comando C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando.  Essa rotina é chamada de **\_setargv** \(ou **\_wsetargv** no ambiente de caractere largo\), conforme descrito em [Expandindo argumentos curinga](../Topic/Expanding%20Wildcard%20Arguments.md).  Para suprimir seu uso, defina uma rotina que não faça nada no arquivo que contém a função **main** e denomine\-a **\_setargv** \(ou **\_wsetargv** no ambiente de caractere largo\).  A chamada para **\_setargv** ou **\_wsetargv** é atendida por sua definição de **\_setargv** ou de **\_wsetargv**, e a versão da biblioteca não é carregada.  
  
 Da mesma forma, se você nunca acessar a tabela de ambiente pelo argumento `envp`, pode fornecer sua própria rotina vazia, que será usada em vez de **\_setenvp** \(ou de **\_wsetenvp**\), a rotina de processamento de ambiente.  
  
 Se seu programa faz chamadas para a família **\_spawn** ou **\_exec** das rotinas na biblioteca em tempo de execução de C, você não deve suprimir a rotina de processamento de ambiente, pois a rotina é usada para transmitir um ambiente do processo de geração para o novo processo.  
  
## Consulte também  
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)