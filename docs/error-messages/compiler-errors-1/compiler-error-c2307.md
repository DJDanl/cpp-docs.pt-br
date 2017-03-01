---
title: C2307 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2307
dev_langs:
- C++
helpviewer_keywords:
- C2307
ms.assetid: ce6c8033-a673-4679-9883-bedec36ae385
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
ms.openlocfilehash: 505b1fb12008d562b3b74785ad4ada0cc9ab98e4
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2307"></a>C2307 de erro do compilador
pragma 'pragma' deve ser a função externa se a compilação incremental estiver habilitada  
  
 Você deve colocar o `data_seg` pragma entre as funções se você estiver usando a compilação incremental.
