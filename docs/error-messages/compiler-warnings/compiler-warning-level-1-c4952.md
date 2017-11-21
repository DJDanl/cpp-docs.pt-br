---
title: "Compilador (nível 1) de aviso C4952 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4952
dev_langs: C++
helpviewer_keywords: C4952
ms.assetid: 593324f0-5cfe-42fb-b221-2f71308765dd
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ffe150b84c297ef747836863d0da4306f0623665
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4952"></a>Compilador C4952 de aviso (nível 1)
'function': nenhum dado de perfil encontrado no banco de dados do programa 'pgd_file'  
  
 Ao usar [/LTCG:PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma nova função (***função***) presente.  
  
 Esse aviso é informativo. Para resolver este aviso, execute `/LTCG:PGINSTRUMENT`, todos os teste de refazer é executado e executar `/LTCG:PGOPTIMIZE`.  
  
 Esse aviso deve ser substituído com um erro se `/LTCG:PGOPTIMIZE` tenha sido usada.