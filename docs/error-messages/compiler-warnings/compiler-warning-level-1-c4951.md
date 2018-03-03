---
title: "Compilador (nível 1) de aviso C4951 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4951
dev_langs:
- C++
helpviewer_keywords:
- C4951
ms.assetid: 669d8bb7-5efa-4ba9-99db-4e65addbf054
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 199df135d5d2c00255037e5a1b31db80e2683d4f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4951"></a>Compilador C4951 de aviso (nível 1)
'function' foi editado após os dados de perfil de função não usados coleta dados de perfil  
  
 Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil não são válidos agora. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (***função***) com um outro fluxo de controle que era no módulo no momento do **/LTCG:PGINSTRUMENT**  operação.  
  
 Esse aviso é informativo. Para resolver este aviso, execute **/LTCG:PGINSTRUMENT**, todos os teste de refazer é executado e execute **/LTCG:PGOPTIMIZE**.  
  
 Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tenha sido usada.