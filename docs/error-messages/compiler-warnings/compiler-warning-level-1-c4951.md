---
title: Aviso do compilador (nível 1) C4951
ms.date: 08/27/2018
f1_keywords:
- C4951
helpviewer_keywords:
- C4951
ms.assetid: 669d8bb7-5efa-4ba9-99db-4e65addbf054
ms.openlocfilehash: d94347df17bac01334cfd85c2bd9f6c8a98b5fc0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174590"
---
# <a name="compiler-warning-level-1-c4951"></a>Aviso do compilador (nível 1) C4951

> '*Function*' foi editado desde que os dados de perfil foram coletados, dados de perfil de função não usados

Uma função foi editada em um módulo de entrada para [/LTCG: PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), para que os dados do perfil agora não sejam válidos. O módulo de entrada foi recompilado após **/LTCG: PGINSTRUMENT** e tem uma função (*função*) com um fluxo diferente de controle do que estava no módulo no momento da operação **/LTCG: PGINSTRUMENT** .

Esse aviso é informativo. Para resolver esse aviso, execute **/LTCG: PGINSTRUMENT**, refaça todas as execuções de teste e execute **/LTCG: PGOPTIMIZE**.

Esse aviso seria substituído por um erro se **/LTCG: PGOPTIMIZE** tivesse sido usado.
