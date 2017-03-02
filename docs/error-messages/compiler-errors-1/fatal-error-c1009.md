---
title: Erro fatal C1009 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1009
dev_langs:
- C++
helpviewer_keywords:
- C1009
ms.assetid: dcc8383c-3362-4c47-9c26-25d2451ebd53
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
ms.openlocfilehash: 9c266982e49b570c3f0398ad39b26103b621d52a
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1009"></a>Erro fatal C1009
limite do compilador: macros aninhadas muito profundamente  
  
 O compilador tentar expandir muitas macros ao mesmo tempo. O compilador tem um limite de 256 níveis de macros aninhadas. Divida macros aninhadas em macros mais simples.
