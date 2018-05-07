---
title: Compilador aviso (níveis 2 e 3) C4008 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4008
dev_langs:
- C++
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4cdc88f222f9e5ce3829a63c131c955ce2abdd7d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Compilador C4008 de aviso (níveis 2 e 3)
'Identificador': atributo ' atributo ' ignorado  
  
 O compilador ignorado o `__fastcall`, **estático**, ou **embutido** atributo para uma função (aviso de nível 3) ou os dados (aviso de nível 2).  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  `__fastcall` atributo com dados.  
  
2.  **estático** ou **embutido** atributo com **principal** função.