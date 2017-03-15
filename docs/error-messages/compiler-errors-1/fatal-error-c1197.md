---
title: Erro fatal C1197 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1197
dev_langs:
- C++
helpviewer_keywords:
- C1197
ms.assetid: 22b801b7-e792-41f6-a461-973c03c69f25
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
ms.openlocfilehash: 63ede2dc064405ef8c388a82b88c2be102daaa4f
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1197"></a>Erro fatal C1197
não é possível fazer referência a 'mscorlib.dll_1' como o programa já está referenciado 'mscorlib.dll_2'  
  
 O compilador corresponde a uma versão do common language runtime.  No entanto, foi feita uma tentativa para fazer referência a uma versão de um arquivo do common language runtime de uma versão anterior.  
  
 Para resolver esse erro, somente os arquivos de referência da versão do common language runtime que acompanha a versão do Visual C++, você estão compilando com.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C1197:  
  
```  
// C1197.cpp  
// compile with: /clr /c  
// processor: x86  
#using "C:\Windows\Microsoft.NET\Framework\v1.1.4322\mscorlib.dll"   // C1197  
// try the following line instead  
// #using "mscorlib.dll"  
```
