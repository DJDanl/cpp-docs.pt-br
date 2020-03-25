---
title: Aviso do compilador (nível 1) C4124
ms.date: 11/04/2016
f1_keywords:
- C4124
helpviewer_keywords:
- C4124
ms.assetid: c08c3a65-9584-47a1-a147-44f00c4b230e
ms.openlocfilehash: 6408185c99a54d5411fa5b1058cd5ec09d3326d6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176306"
---
# <a name="compiler-warning-level-1-c4124"></a>Aviso do compilador (nível 1) C4124

__fastcall com verificação de pilha é ineficiente

A palavra-chave `__fastcall` foi usada com a verificação de pilha habilitada.

A Convenção de `__fastcall` gera código mais rápido, mas a verificação de pilha causa um código mais lento. Ao usar `__fastcall`, desative a verificação de pilha com o **check_stack** pragma ou/GS.

Esse aviso é emitido somente para a primeira função declarada sob essas condições.
