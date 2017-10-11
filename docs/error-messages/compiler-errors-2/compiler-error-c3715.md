---
title: C3715 de erro do compilador | Microsoft Docs
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0fcfe83ada2c55540562fc17189d693675326c81
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3715"></a>C3715 de erro do compilador
'ponteiro': deve ser um ponteiro para 'class'  
  
 Você especificou um ponteiro em [hook](../../cpp/hook.md) ou [unhook](../../cpp/unhook.md) que não apontou para uma classe válida. Para corrigir esse erro, certifique-se de que seu `__hook` e `__unhook` chamadas especificar ponteiros para classes válidos.
