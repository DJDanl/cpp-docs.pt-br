---
title: Compilador aviso (nível 1) C4953
ms.date: 08/27/2018
f1_keywords:
- C4953
helpviewer_keywords:
- C4953
ms.assetid: 3c4f6ac6-3976-41ab-8a27-3c41d7472ea7
ms.openlocfilehash: 1948342e1ff97c38ca3a44694dc7e7d399d96825
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384147"
---
# <a name="compiler-warning-level-1-c4953"></a>Compilador aviso (nível 1) C4953

> Item embutido '*função*' foi editado desde o perfil de dados foram coletados, dados de perfil não usados

Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma função (*função*) que foi editado e onde existente execuções de teste identificado o funcionar como um candidato para inlining. No entanto, como resultado de recompilação do módulo, a função deixará de ser um candidato para inlining.

Esse aviso é informativo. Para resolver este aviso, execute `/LTCG:PGINSTRUMENT`, todos os teste de refazer é executado e executar `/LTCG:PGOPTIMIZE`.

Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tivesse sido usada.