---
title: Erro fatal C1054 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1054
dev_langs:
- C++
helpviewer_keywords:
- C1054
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d02d8eb05633d7250dc3f7ee85dd78ccf4153052
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1054"></a>Erro fatal C1054
limite do compilador: inicializadores com aninhamento muito profundo  
  
 O código excede o limite de aninhamento em inicializadores (níveis de 10 a 15, dependendo da combinação de tipos está sendo inicializado).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifica os tipos de dados que está sendo inicializados para reduzir o aninhamento.  
  
2.  Inicialize variáveis em instruções separadas após a declaração.
