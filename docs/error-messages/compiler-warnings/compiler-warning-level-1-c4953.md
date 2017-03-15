---
title: "Compilador aviso (nível 1) C4953 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4953
dev_langs:
- C++
helpviewer_keywords:
- C4953
ms.assetid: 3c4f6ac6-3976-41ab-8a27-3c41d7472ea7
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
ms.openlocfilehash: be8e32bd07da47d79e974d979eb19466c5b19416
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4953"></a>Compilador C4953 de aviso (nível 1)
Inlinee 'function' foi editada desde o perfil de dados foram coletados, os dados de perfil não usados  
  
 Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada recompilada após `/LTCG:PGINSTRUMENT` e tem uma função (***função***) que foi editado e onde é executado de teste existente identificado a função como um candidato para inlining. No entanto, como resultado de recompilar o módulo, a função deixará de ser um candidato para inlining.  
  
 Esse aviso é informativo. Para resolver esse aviso, execute `/LTCG:PGINSTRUMENT`, Refazer todos os teste é executado e executar `/LTCG:PGOPTIMIZE`.  
  
 Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tenha sido usada.
