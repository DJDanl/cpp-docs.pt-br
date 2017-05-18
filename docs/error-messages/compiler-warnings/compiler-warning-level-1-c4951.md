---
title: "Compilador aviso (nível 1) C4951 | Documentos do Microsoft"
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8317491a1649741c3322af3125fef80c0fb52f47
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4951"></a>Compilador C4951 de aviso (nível 1)
'function' foi editada desde o perfil de dados foram coletados, os dados de perfil de função não usados  
  
 Uma função foi editada em um módulo de entrada para [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), de modo que os dados de perfil agora não são válidos. O módulo de entrada foi recompilado após **/LTCG:PGINSTRUMENT** e tem uma função (***função***) com um outro fluxo de controle que era no módulo no momento do **/LTCG:PGINSTRUMENT** operação.  
  
 Esse aviso é informativo. Para resolver esse aviso, execute **/LTCG:PGINSTRUMENT**, Refazer todos os teste é executado e executado **/LTCG:PGOPTIMIZE**.  
  
 Esse aviso deve ser substituído com um erro se **/LTCG:PGOPTIMIZE** tenha sido usada.
