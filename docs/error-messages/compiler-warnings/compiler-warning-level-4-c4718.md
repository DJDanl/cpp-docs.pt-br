---
title: Compilador (nível 4) de aviso C4718 | Microsoft Docs
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
ms.openlocfilehash: a92ab7a32babd181f282c799568e3a9dea436c49
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33294028"
---
# <a name="compiler-warning-level-4-c4718"></a>Compilador C4718 de aviso (nível 4)
chamada de função: chamada recursiva não tem efeitos colaterais, excluindo  
  
 Uma função contém uma chamada recursiva, mas, caso contrário, não tem efeitos colaterais. Uma chamada para essa função está sendo excluída. A exatidão do programa não é afetada, mas o comportamento é. Enquanto deixa a chamada no pode resultar em uma exceção de estouro de pilha do tempo de execução, a chamada a exclusão remove essa possibilidade.