---
title: "4. Variáveis de ambiente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cef1bac78afbcc8b852c3bd42e0904e1963137c8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="4-environment-variables"></a>4. Variáveis de ambiente
Este capítulo descreve OpenMP C e C++ API variáveis de ambiente (ou equivalentes mecanismos de específicos de plataforma) que controla a execução de código paralelo.  Os nomes de variáveis de ambiente devem ser em maiusculas. Os valores atribuídos a eles diferenciam maiusculas de minúsculas e podem ter espaço em branco à esquerda e à direita.  As modificações de valores depois que o programa foi iniciado são ignoradas.  
  
 As variáveis de ambiente são da seguinte maneira:  
  
-   **OMP_SCHEDULE** define o tamanho de bloco e de tipo de agendamento de tempo de execução.  
  
-   **OMP_NUM_THREADS** define o número de threads a serem usados durante a execução.  
  
-   **OMP_DYNAMIC** ativa ou desativa o ajuste dinâmico do número de threads.  
  
-   **OMP_NESTED** habilita ou desabilita o paralelismo aninhado.  
  
 Os exemplos neste capítulo somente demonstram como essas variáveis podem ser definidas em ambientes do Unix C shell (csh). Em Korn shell e ambientes das ações são semelhantes, da seguinte maneira:  
  
 csh:  
 SetEnv OMP_SCHEDULE "dinâmica"  
  
 ksh:  
 Exportar OMP_SCHEDULE = "dynamic"  
  
 DOS:  
 Definir OMP_SCHEDULE = "dynamic"