---
title: Compilador aviso (nível 1) C4951
ms.date: 08/27/2018
f1_keywords:
- C4951
helpviewer_keywords:
- C4951
ms.assetid: 669d8bb7-5efa-4ba9-99db-4e65addbf054
ms.openlocfilehash: 73e048aeaa044c35e09539b07d51398829a0fdfd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50617849"
---
# <a name="compiler-warning-level-1-c4951"></a>Compilador aviso (nível 1) C4951

> '*função*' foi editado desde o perfil de dados foram coletados, dados de perfil de função não usados

Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil agora não são válidos. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (*função*) com um fluxo diferente do controle que era no módulo no momento do **/LTCG:PGINSTRUMENT**  operação.

Esse aviso é informativo. Para resolver este aviso, execute **/LTCG:PGINSTRUMENT**, todos os teste de refazer é executado e executados **/LTCG:PGOPTIMIZE**.

Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tivesse sido usada.