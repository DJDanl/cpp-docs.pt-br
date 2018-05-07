---
title: Compilador (nível 1) de aviso C4951 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4951
dev_langs:
- C++
helpviewer_keywords:
- C4951
ms.assetid: 669d8bb7-5efa-4ba9-99db-4e65addbf054
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c3ebf012338bdf6b90cc943e754056335c6751a4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4951"></a>Compilador C4951 de aviso (nível 1)
'function' foi editado após os dados de perfil de função não usados coleta dados de perfil  
  
 Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil não são válidos agora. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (***função***) com um outro fluxo de controle que era no módulo no momento do **/LTCG:PGINSTRUMENT**  operação.  
  
 Esse aviso é informativo. Para resolver este aviso, execute **/LTCG:PGINSTRUMENT**, todos os teste de refazer é executado e execute **/LTCG:PGOPTIMIZE**.  
  
 Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tenha sido usada.