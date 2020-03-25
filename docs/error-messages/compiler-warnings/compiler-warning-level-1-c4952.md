---
title: Aviso do compilador (nível 1) C4952
ms.date: 08/27/2018
f1_keywords:
- C4952
helpviewer_keywords:
- C4952
ms.assetid: 593324f0-5cfe-42fb-b221-2f71308765dd
ms.openlocfilehash: 560705edeb0bbdd6be760736a8d4a19d914133d2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174564"
---
# <a name="compiler-warning-level-1-c4952"></a>Aviso do compilador (nível 1) C4952

> '*Function*': nenhum dado de perfil encontrado no banco de dados do programa '*pgd_file*'

Ao usar [/LTCG: PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada que foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma nova função (*função*) presente.

Esse aviso é informativo. Para resolver esse aviso, execute `/LTCG:PGINSTRUMENT`, refaça todas as execuções de teste e execute `/LTCG:PGOPTIMIZE`.

Esse aviso será substituído por um erro se `/LTCG:PGOPTIMIZE` tivesse sido usado.
