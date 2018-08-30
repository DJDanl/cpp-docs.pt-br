---
title: Compilador aviso (nível 1) C4952 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4952
dev_langs:
- C++
helpviewer_keywords:
- C4952
ms.assetid: 593324f0-5cfe-42fb-b221-2f71308765dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f62f4c18380d89eb516a5fa49ef63e92ab79a6f2
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43207145"
---
# <a name="compiler-warning-level-1-c4952"></a>Compilador aviso (nível 1) C4952

> '*função*': nenhum dado de perfil encontrado no banco de dados do programa '*pgd_file*'

Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma nova função (*função*) presente.

Esse aviso é informativo. Para resolver este aviso, execute `/LTCG:PGINSTRUMENT`, todos os teste de refazer é executado e executar `/LTCG:PGOPTIMIZE`.

Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tivesse sido usada.