---
title: "Compilador aviso (níveis 2 e 3) C4008 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4008
dev_langs:
- C++
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
caps.latest.revision: 6
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
ms.openlocfilehash: b2c690df4c0b258249373ea8381e713f34f5da29
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Compilador C4008 de aviso (níveis 2 e 3)
'identifier': atributo ' atributo ' ignorado  
  
 O compilador ignorado a `__fastcall`, **estático**, ou **embutido** atributo para uma função (aviso de nível 3) ou dados (aviso de nível 2).  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  `__fastcall`atributo com dados.  
  
2.  **estático** ou **embutido** atributo com **principal** função.
