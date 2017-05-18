---
title: C3715 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3715
dev_langs:
- C++
helpviewer_keywords:
- C3715
ms.assetid: ee5dce88-ddc4-4bdb-9464-47467ce1674f
caps.latest.revision: 8
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
ms.openlocfilehash: 3b37be48c281f3c3e381abd3ed4c6704c8b5c528
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3715"></a>C3715 de erro do compilador
'ponteiro': deve ser um ponteiro para 'class'  
  
 Você especificou um ponteiro em [hook](../../cpp/hook.md) ou [unhook](../../cpp/unhook.md) que não apontou para uma classe válida. Para corrigir esse erro, verifique se o `__hook` e `__unhook` chamadas especificar ponteiros para classes válidos.
