---
title: 4. Variáveis de ambiente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: edd4f795a3511358d2b95b93e180b9b21b964dd2
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690995"
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