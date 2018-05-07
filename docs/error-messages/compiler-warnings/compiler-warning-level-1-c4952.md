---
title: Compilador (nível 1) de aviso C4952 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 42696dfae816742c958bca23e25e311e834dd62a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4952"></a>Compilador C4952 de aviso (nível 1)
'function': nenhum dado de perfil encontrado no banco de dados do programa 'pgd_file'  
  
 Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma nova função (***função***) presente.  
  
 Esse aviso é informativo. Para resolver este aviso, execute `/LTCG:PGINSTRUMENT`, todos os teste de refazer é executado e executar `/LTCG:PGOPTIMIZE`.  
  
 Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tenha sido usada.