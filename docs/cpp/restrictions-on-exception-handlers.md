---
title: Restrições em manipuladores de exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- restrictions, exception handlers
- exception handling [C++], exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1f739152b502a156dc62dfab279e5ad044cfff99
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção
A principal limitação do uso de manipuladores de exceção no código é que você não pode usar uma instrução `goto` para ir diretamente para um bloco de instruções `__try`. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode sair de um bloco de instruções `__try` e aninhar manipuladores de exceção como quiser.  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)