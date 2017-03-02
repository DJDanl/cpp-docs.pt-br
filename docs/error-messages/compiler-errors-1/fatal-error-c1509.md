---
title: Erro fatal C1509 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1509
dev_langs:
- C++
helpviewer_keywords:
- C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
caps.latest.revision: 7
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
ms.openlocfilehash: bb83e385126b05694c1c3c7cc437e68faa102c08
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1509"></a>Erro fatal C1509
limite do compilador: muitos estados de manipulador de exceção na função 'function'. simplificar a função  
  
 O código excede um limite interno em estados do manipulador de exceção (32.768 estados).  
  
 A causa mais comum é que a função contém uma expressão complexa de operadores aritméticos e variáveis de classe definida pelo usuário.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Simplifica expressões atribuindo subexpressões comuns para variáveis temporárias.  
  
2.  Divida a função em funções menores.
