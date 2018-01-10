---
title: 1.1 escopo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a8570a3c-1dd6-4c3d-b368-a10fcb3534a6
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 07859a95b739cf649ab6516cb2e8b605efe442dc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="11-scope"></a>1.1 Escopo
Essa especificação abrange paralelização somente direcionadas ao usuário, no qual o usuário especifica explicitamente as ações a serem tomadas pelo compilador e sistema de tempo de execução para executar o programa em paralelo. Implementações OpenMP C e C++ não são necessários para verificar se há dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução do programa incorreto. O usuário é responsável por garantir que o aplicativo usando as construções OpenMP C e C++ API seja executado corretamente. Diretivas para o compilador para auxiliar tal paralelização e gerado pelo compilador paralelização automática não são abordadas neste documento.