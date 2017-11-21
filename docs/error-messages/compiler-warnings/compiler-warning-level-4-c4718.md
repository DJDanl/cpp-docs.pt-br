---
title: "Compilador (nível 4) de aviso C4718 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4718
dev_langs: C++
helpviewer_keywords: C4718
ms.assetid: 29507f8a-b024-42c1-a3b8-f35d1f2641f3
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 837e0e69d2a2f0694dc9c99e8c3425bbd12a94e2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4718"></a>Compilador C4718 de aviso (nível 4)
chamada de função: chamada recursiva não tem efeitos colaterais, excluindo  
  
 Uma função contém uma chamada recursiva, mas, caso contrário, não tem efeitos colaterais. Uma chamada para essa função está sendo excluída. A exatidão do programa não é afetada, mas o comportamento é. Enquanto deixa a chamada no pode resultar em uma exceção de estouro de pilha do tempo de execução, a chamada a exclusão remove essa possibilidade.