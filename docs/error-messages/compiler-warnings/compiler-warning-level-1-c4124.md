---
title: Aviso do compilador (nível 1) C4124
ms.date: 11/04/2016
f1_keywords:
- C4124
helpviewer_keywords:
- C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
ms.openlocfilehash: 59860bef108a3cd3e8bbbc6ff0790e17dbdaa0d4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214484"
---
# <a name="compiler-warning-level-1-c4124"></a>Aviso do compilador (nível 1) C4124

__fastcall com verificação de pilha é ineficiente

A **`__fastcall`** palavra-chave foi usada com a verificação de pilha habilitada.

A **`__fastcall`** Convenção gera um código mais rápido, mas a verificação de pilha causa um código mais lento. Ao usar **`__fastcall`** , desative a verificação de pilha com o **check_stack** pragma ou/GS.

Esse aviso é emitido somente para a primeira função declarada sob essas condições.
