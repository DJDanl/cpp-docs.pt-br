---
title: Erro fatal C1020 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1020
dev_langs:
- C++
helpviewer_keywords:
- C1020
ms.assetid: 42f429e2-5e3b-4086-a10d-b99e032e51c5
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
ms.openlocfilehash: 23b9d24fde38495818665ea520f2f0d63b85e1b8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1020"></a>Erro fatal C1020
#endif inesperado  
  
 O `#endif` diretiva não tem nenhuma correspondência `#if`, `#ifdef`, ou `#ifndef` diretiva. Ser-se de que cada `#endif` tem uma diretiva correspondente.  
  
 O exemplo a seguir gera C1020:  
  
```  
// C1020.cpp  
#endif     // C1020  
```  
  
 Resolução possível:  
  
```  
// C1020b.cpp  
// compile with: /c  
#if 1  
#endif  
```
