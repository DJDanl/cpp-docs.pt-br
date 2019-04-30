---
title: Compilador aviso (nível 4) C4718
ms.date: 11/04/2016
f1_keywords:
- C4718
helpviewer_keywords:
- C4718
ms.assetid: 29507f8a-b024-42c1-a3b8-f35d1f2641f3
ms.openlocfilehash: c313e26af5f5b17db9c7d001a705ff7211461c2b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395164"
---
# <a name="compiler-warning-level-4-c4718"></a>Compilador aviso (nível 4) C4718

chamada de função: chamada recursiva não tem efeitos colaterais, excluindo

Uma função contém uma chamada recursiva, mas caso contrário, não tem efeitos colaterais. Uma chamada para essa função está sendo excluída. A correção do programa não é afetada, mas é o comportamento. Enquanto deixando a chamada no pode resultar em uma exceção de estouro de pilha de tempo de execução, a chamada a exclusão remove essa possibilidade.