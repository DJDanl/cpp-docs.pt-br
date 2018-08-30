---
title: Compilador aviso (nível 1) C4951 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
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
ms.openlocfilehash: e26c4bc176a54f063a3f9bce2faf451a9c0406f0
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43204229"
---
# <a name="compiler-warning-level-1-c4951"></a>Compilador aviso (nível 1) C4951

> '*função*' foi editado desde o perfil de dados foram coletados, dados de perfil de função não usados

Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil agora não são válidos. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (*função*) com um fluxo diferente do controle que era no módulo no momento do **/LTCG:PGINSTRUMENT**  operação.

Esse aviso é informativo. Para resolver este aviso, execute **/LTCG:PGINSTRUMENT**, todos os teste de refazer é executado e executados **/LTCG:PGOPTIMIZE**.

Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tivesse sido usada.