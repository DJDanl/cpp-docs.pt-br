---
title: Compilador aviso (nível 1) C4124 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4124
dev_langs:
- C++
helpviewer_keywords:
- C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a69190487c22987ead2d00ec102785ed42ea93c4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46090915"
---
# <a name="compiler-warning-level-1-c4124"></a>Compilador aviso (nível 1) C4124

fastcall com verificação de pilha é ineficiente

O `__fastcall` palavra-chave foi usado com a verificação da pilha habilitado.

O `__fastcall` convenção gera um código mais rápido, mas a verificação da pilha faz com que o código mais lento. Ao usar `__fastcall`, desativar a verificação de pilha com o **check_stack** pragma ou /Gs.

Esse aviso é emitido apenas para a primeira função declarada sob essas condições.