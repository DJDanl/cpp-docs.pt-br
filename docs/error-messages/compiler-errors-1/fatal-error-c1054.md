---
title: Erro fatal C1054 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: dad2a6f88563f805d00c3d44590084d29da132bf
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1054"></a>Erro fatal C1054
limite do compilador : inicializadores aninhados muito profundamente  
  
 O código excede o limite de aninhamento inicializadores (10 a&15; níveis, dependendo da combinação de tipos está sendo inicializado).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Simplificar os tipos de dados que está sendo inicializados para reduzir o aninhamento.  
  
2.  Inicialize variáveis em instruções separadas depois da declaração.
