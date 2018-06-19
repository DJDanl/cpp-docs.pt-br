---
title: C3550 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3550
dev_langs:
- C++
helpviewer_keywords:
- C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 91003af2069ba32083caefa8f5a79cbe0e7cd9c9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33252888"
---
# <a name="compiler-error-c3550"></a>C3550 de erro do compilador
apenas um 'decltype (Auto)' é permitido neste contexto  
  
 Se `decltype(auto)` é usado como um espaço reservado para o tipo de retorno de uma função, ele deve ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`), ou qualquer outra essa qualificação.  
  
## <a name="see-also"></a>Consulte também  
 [auto](../../cpp/auto-cpp.md)