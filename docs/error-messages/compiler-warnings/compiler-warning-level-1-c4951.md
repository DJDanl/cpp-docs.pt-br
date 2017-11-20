---
title: "Compilador (nível 1) de aviso C4951 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4951
dev_langs: C++
helpviewer_keywords: C4951
ms.assetid: 669d8bb7-5efa-4ba9-99db-4e65addbf054
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: efb4b4a283964230d191962db40c4d061a039dfd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4951"></a>Compilador C4951 de aviso (nível 1)
'function' foi editado após os dados de perfil de função não usados coleta dados de perfil  
  
 Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil não são válidos agora. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (***função***) com um outro fluxo de controle que era no módulo no momento do **/LTCG:PGINSTRUMENT**  operação.  
  
 Esse aviso é informativo. Para resolver este aviso, execute **/LTCG:PGINSTRUMENT**, todos os teste de refazer é executado e execute **/LTCG:PGOPTIMIZE**.  
  
 Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tenha sido usada.