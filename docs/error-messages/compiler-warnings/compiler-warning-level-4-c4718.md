---
title: Aviso do compilador (nível 4) C4718
ms.date: 11/04/2016
f1_keywords:
- C4718
helpviewer_keywords:
- C4718
ms.assetid: 29507f8a-b024-42c1-a3b8-f35d1f2641f3
ms.openlocfilehash: 48452ed53b93d7cd89daadd3f7ab3a69b453e1a1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198153"
---
# <a name="compiler-warning-level-4-c4718"></a>Aviso do compilador (nível 4) C4718

' chamada de função ': chamada recursiva não tem efeitos colaterais, excluindo

Uma função contém uma chamada recursiva, mas, caso contrário, não tem efeitos colaterais. Uma chamada para esta função está sendo excluída. A exatidão do programa não é afetada, mas o comportamento é. Enquanto que deixar a chamada em pode resultar em uma exceção de estouro de pilha de tempo de execução, a exclusão da chamada remove essa possibilidade.
