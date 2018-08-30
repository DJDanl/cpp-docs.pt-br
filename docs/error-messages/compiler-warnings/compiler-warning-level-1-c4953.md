---
title: Compilador aviso (nível 1) C4953 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4953
dev_langs:
- C++
helpviewer_keywords:
- C4953
ms.assetid: 3c4f6ac6-3976-41ab-8a27-3c41d7472ea7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9e53808d4ad97bad4eccdf81b0a863277f8f7796
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43194626"
---
# <a name="compiler-warning-level-1-c4953"></a>Compilador aviso (nível 1) C4953

> Item embutido '*função*' foi editado desde o perfil de dados foram coletados, dados de perfil não usados

Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma função (*função*) que foi editado e onde existente execuções de teste identificado o funcionar como um candidato para inlining. No entanto, como resultado de recompilação do módulo, a função deixará de ser um candidato para inlining.

Esse aviso é informativo. Para resolver este aviso, execute `/LTCG:PGINSTRUMENT`, todos os teste de refazer é executado e executar `/LTCG:PGOPTIMIZE`.

Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tivesse sido usada.