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
ms.openlocfilehash: 29a462f83bff3bab158e9bcf9fa7947efb56a79b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074468"
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção

A principal limitação usando manipuladores de exceção no código é que você não pode usar um **goto** instrução para ir diretamente para um **Try** bloco de instrução. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode ir de um **Try** instrução bloquear e aninhar manipuladores de exceção como quiser.

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)