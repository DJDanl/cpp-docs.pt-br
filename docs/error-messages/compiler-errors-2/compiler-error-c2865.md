---
title: Erro do compilador C2865 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2865
dev_langs:
- C++
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cc0a49f8e6ab42f7e607cd5f4f7cc91f6895abe0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035156"
---
# <a name="compiler-error-c2865"></a>Erro do compilador C2865

'function': comparação inválida para handle_or_pointer

Você pode comparar as referências a [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md) ou tipos de referência apenas para igualdade para ver se elas se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).

Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.