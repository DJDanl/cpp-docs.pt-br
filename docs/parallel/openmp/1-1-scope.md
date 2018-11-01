---
title: 1.1 Escopo
ms.date: 11/04/2016
ms.assetid: a8570a3c-1dd6-4c3d-b368-a10fcb3534a6
ms.openlocfilehash: f87f631ae2d36662daa2ece4790170c00c5cbeb3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449199"
---
# <a name="11-scope"></a>1.1 Escopo

Essa especificação aborda paralelização apenas direcionadas ao usuário, no qual o usuário especifica explicitamente as ações a serem realizadas pelo compilador e o sistema de tempo de execução para executar o programa em paralelo. Implementações de OpenMP C e C++ não são necessários para verificar se há dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução do programa incorreto. O usuário é responsável por garantir que o aplicativo usando as construções OpenMP C e C++ API é executado corretamente. Paralelização automática gerado pelo compilador e diretivas para o compilador para ajudá-lo tal paralelização não são abordadas neste documento.