---
title: "Compilador aviso (nível 1) C4952 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4952
dev_langs:
- C++
helpviewer_keywords:
- C4952
ms.assetid: 593324f0-5cfe-42fb-b221-2f71308765dd
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6bb297c2e19498a4f752d18eb49e988099e24e10
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4952"></a>Compilador C4952 de aviso (nível 1)
'function': nenhum dado de perfil encontrado no banco de dados do programa 'pgd_file'  
  
 Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada recompilada após `/LTCG:PGINSTRUMENT` e tem uma nova função (***função***) presente.  
  
 Esse aviso é informativo. Para resolver esse aviso, execute `/LTCG:PGINSTRUMENT`, Refazer todos os teste é executado e executar `/LTCG:PGOPTIMIZE`.  
  
 Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tenha sido usada.
