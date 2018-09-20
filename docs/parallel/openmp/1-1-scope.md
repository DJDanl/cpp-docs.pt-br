---
title: 1.1 definir o escopo de | Microsoft Docs
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
ms.openlocfilehash: 81babf799860030f6d398f64b55ed65039de8649
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393523"
---
# <a name="11-scope"></a>1.1 Escopo

Essa especificação aborda paralelização apenas direcionadas ao usuário, no qual o usuário especifica explicitamente as ações a serem realizadas pelo compilador e o sistema de tempo de execução para executar o programa em paralelo. Implementações de OpenMP C e C++ não são necessários para verificar se há dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução do programa incorreto. O usuário é responsável por garantir que o aplicativo usando as construções OpenMP C e C++ API é executado corretamente. Paralelização automática gerado pelo compilador e diretivas para o compilador para ajudá-lo tal paralelização não são abordadas neste documento.