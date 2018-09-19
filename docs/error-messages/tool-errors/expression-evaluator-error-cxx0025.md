---
title: CXX0025 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0025
dev_langs:
- C++
helpviewer_keywords:
- CAN0025
- CXX0025
ms.assetid: 3e2fb541-63b3-46ac-9f93-3dadb253bcf6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd89faa4de7b296d6a6771f857f3d16dbe2f94f2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46043697"
---
# <a name="expression-evaluator-error-cxx0025"></a>Erro CXX0025 (avaliador de expressão)

operador precisa struct/union

Um operador que usa uma expressão de `struct` ou **união** tipo foi aplicado a uma expressão que não seja um `struct` ou **união**.

Componentes de classe, estrutura ou união variáveis devem ter um nome totalmente qualificado. Componentes não podem ser inseridos sem a especificação completa.

Esse erro é idêntico ao CAN0025.