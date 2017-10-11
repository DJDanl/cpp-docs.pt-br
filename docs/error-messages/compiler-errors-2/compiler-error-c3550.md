---
title: C3550 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3550
dev_langs:
- C++
helpviewer_keywords:
- C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 52b3e3323bac9ad55ff10481b3504e4e054ba874
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3550"></a>C3550 de erro do compilador
apenas um 'decltype (Auto)' é permitido neste contexto  
  
 Se `decltype(auto)` é usado como um espaço reservado para o tipo de retorno de uma função, ele deve ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`), ou qualquer outra essa qualificação.  
  
## <a name="see-also"></a>Consulte também  
 [auto](../../cpp/auto-cpp.md)
