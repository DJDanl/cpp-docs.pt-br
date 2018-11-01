---
title: Compilador aviso (nível 1) C4124
ms.date: 11/04/2016
f1_keywords:
- C4124
helpviewer_keywords:
- C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
ms.openlocfilehash: 04732619571420e777244b81bf4b93b775477a20
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50582554"
---
# <a name="compiler-warning-level-1-c4124"></a>Compilador aviso (nível 1) C4124

fastcall com verificação de pilha é ineficiente

O `__fastcall` palavra-chave foi usado com a verificação da pilha habilitado.

O `__fastcall` convenção gera um código mais rápido, mas a verificação da pilha faz com que o código mais lento. Ao usar `__fastcall`, desativar a verificação de pilha com o **check_stack** pragma ou /Gs.

Esse aviso é emitido apenas para a primeira função declarada sob essas condições.