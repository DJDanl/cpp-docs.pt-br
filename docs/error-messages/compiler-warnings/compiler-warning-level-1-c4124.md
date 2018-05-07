---
title: Compilador (nível 1) de aviso C4124 | Microsoft Docs
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
ms.openlocfilehash: accd58c123bcd74e54176eed5eb974c3df33dbab
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4124"></a>Compilador C4124 de aviso (nível 1)
fastcall com verificação de pilha é ineficiente  
  
 O `__fastcall` palavra-chave foi usado com verificação de pilha habilitado.  
  
 O `__fastcall` convenção gera código mais rápido, mas a verificação de pilha faz com que o código mais lento. Ao usar `__fastcall`, desativar a verificação de pilha com o **check_stack** pragma ou /Gs.  
  
 Esse aviso é emitido apenas para a primeira função declarada sob essas condições.