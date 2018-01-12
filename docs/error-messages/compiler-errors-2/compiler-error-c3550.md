---
title: C3550 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3550
dev_langs: C++
helpviewer_keywords: C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a05f0fc0b16cd7e3da851cb696f0ff60b8498319
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3550"></a>C3550 de erro do compilador
apenas um 'decltype (Auto)' é permitido neste contexto  
  
 Se `decltype(auto)` é usado como um espaço reservado para o tipo de retorno de uma função, ele deve ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`), ou qualquer outra essa qualificação.  
  
## <a name="see-also"></a>Consulte também  
 [auto](../../cpp/auto-cpp.md)