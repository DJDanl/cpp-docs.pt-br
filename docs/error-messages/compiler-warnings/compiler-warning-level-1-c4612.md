---
title: "Compilador aviso (nível 1) C4612 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4612
dev_langs:
- C++
helpviewer_keywords:
- C4612
ms.assetid: 21ac02b2-51cd-4aff-9b70-d543511d5962
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
ms.openlocfilehash: 1ed66cadfee2b5da2967f634639273835e5a1f47
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4612"></a>Compilador C4612 de aviso (nível 1)
erro no nome de arquivo de include  
  
 Este aviso ocorre com **#pragma include_alias** quando um nome de arquivo está incorreta ou ausente.  
  
 Os argumentos para o **#pragma include_alias** instrução pode usar a citação de (**"***filename***"**) ou forma de colchete angular (**\<***filename***>**), mas ambas devem usar o mesmo formulário.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4612.cpp  
// compile with: /W1 /LD  
#pragma include_alias("StandardIO", <stdio.h>) // C4612  
```
