---
title: "Personalizando processamento de linha de comando C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_setenvp"
  - "_setargv"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _setargv"
  - "Função _setenvp"
  - "linha de comando, processando"
  - "linha de comando, processando argumentos"
  - "processamento de linha de comando"
  - "ambiente, rotina de processamento de ambiente"
  - "código de inicialização, personalizando o processamento de linha de comando"
  - "suprimindo o processamento de ambiente"
ms.assetid: aae01cbb-892b-48b8-8e1f-34f22421f263
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personalizando processamento de linha de comando C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando.  Essa rotina é chamada **\_setargv** e descrita em [Expansão curinga](../cpp/wildcard-expansion.md).  Para suprimir seu uso, defina uma rotina que não faça nada no arquivo que contém a função **main** e denomine\-a **\_setargv**.  A chamada para **\_setargv** é satisfeita por sua definição de **\_setargv** e a versão da biblioteca não é carregada.  
  
 Da mesma forma, se você nunca acessa a tabela de ambiente pelo argumento `envp`, é possível fornecer sua própria rotina vazia a ser usada em vez de **\_setenvp**, a rotina de ambiente de processamento.  Da mesma forma que a função **\_setargv**, **\_setenvp** deve ser declarada como **extern "C"**.  
  
 O programa poderá fazer chamadas para a família de rotinas **spawn** ou `exec` na biblioteca em tempo de execução de C.  Se esse for o caso, você não deve suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [main: inicialização do programa](../Topic/main:%20Program%20Startup.md)