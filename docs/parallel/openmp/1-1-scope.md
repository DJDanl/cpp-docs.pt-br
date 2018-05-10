---
title: 1.1 escopo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a8570a3c-1dd6-4c3d-b368-a10fcb3534a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48d14ec722299a9ff72ad5bab0a68cde5e00d6ad
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="11-scope"></a>1.1 Escopo
Essa especificação abrange paralelização somente direcionadas ao usuário, no qual o usuário especifica explicitamente as ações a serem tomadas pelo compilador e sistema de tempo de execução para executar o programa em paralelo. Implementações OpenMP C e C++ não são necessários para verificar se há dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução do programa incorreto. O usuário é responsável por garantir que o aplicativo usando as construções OpenMP C e C++ API seja executado corretamente. Diretivas para o compilador para auxiliar tal paralelização e gerado pelo compilador paralelização automática não são abordadas neste documento.