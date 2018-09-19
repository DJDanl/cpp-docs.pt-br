---
title: Compilador aviso (nível 4) C4718 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4718
dev_langs:
- C++
helpviewer_keywords:
- C4718
ms.assetid: 29507f8a-b024-42c1-a3b8-f35d1f2641f3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8736902f4c3a1cfac7313806fde65d1b253716b3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054227"
---
# <a name="compiler-warning-level-4-c4718"></a>Compilador aviso (nível 4) C4718

chamada de função: chamada recursiva não tem efeitos colaterais, excluindo

Uma função contém uma chamada recursiva, mas caso contrário, não tem efeitos colaterais. Uma chamada para essa função está sendo excluída. A correção do programa não é afetada, mas é o comportamento. Enquanto deixando a chamada no pode resultar em uma exceção de estouro de pilha de tempo de execução, a chamada a exclusão remove essa possibilidade.