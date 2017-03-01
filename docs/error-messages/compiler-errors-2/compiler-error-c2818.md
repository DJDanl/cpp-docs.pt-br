---
title: C2818 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2818
dev_langs:
- C++
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
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
ms.openlocfilehash: 4ff5267aa7f8386638a5a9c3f8ec3ad01e0fe443
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2818"></a>C2818 de erro do compilador
aplicativo de 'operador sobrecarregado->' é recursiva por meio do tipo 'type'  
  
 Uma redefinição do operador de acesso de membro de classe contém uma recursiva `return` instrução. Para redefinir o `->` operador com a recursão, você deve mover a rotina recursiva para uma função distinta chamada do operador substitui a função.
