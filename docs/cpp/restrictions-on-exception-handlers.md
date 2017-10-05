---
title: "Restrições em manipuladores de exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- restrictions, exception handlers
- exception handling, exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 1806c737b9adfcefbe6417fda92ddc054094d4db
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção
A principal limitação do uso de manipuladores de exceção no código é que você não pode usar uma instrução `goto` para ir diretamente para um bloco de instruções `__try`. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode sair de um bloco de instruções `__try` e aninhar manipuladores de exceção como quiser.  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
