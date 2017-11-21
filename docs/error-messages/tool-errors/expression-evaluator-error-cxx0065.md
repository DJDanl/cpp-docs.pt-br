---
title: "CXX0065 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0065
dev_langs: C++
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a80869ad54541a493450ce4cc3696da5da6116b0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)
a variável necessita de quadro de pilha  
  
 Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não foi criada ainda.  
  
 Esse erro pode ocorrer quando você tiver entrado no prólogo de uma função, mas ainda não configurar o quadro de pilha para a função, ou se você tiver entrado em código de saída para a função.  
  
 Percorrer o código de prólogo até que o quadro da pilha foi configurado antes de avaliar a expressão.  
  
 Esse erro é idêntico ao CAN0065.