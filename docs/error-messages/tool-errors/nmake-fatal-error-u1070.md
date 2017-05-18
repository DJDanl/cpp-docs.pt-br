---
title: NMAKE Erro Fatal U1070 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1070
dev_langs:
- C++
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 706b1a9275e6e74a762e4a8a1efe4a25d4c015c1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1070"></a>Erro fatal U1070 (NMAKE)
ciclo na definição de macro 'macroname'  
  
 Definição da macro determinado continha uma macro cuja definição de macro determinada. As definições de macro circulares são inválidas.  
  
## <a name="example"></a>Exemplo  
 As seguintes definições de macro  
  
```  
ONE=$(TWO)  
TWO=$(ONE)  
```  
  
 fazer com que o erro a seguir:  
  
```  
cycle in macro definition 'TWO'  
```
