---
title: CXX0065 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0065
dev_langs:
- C++
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 78c25c9c6bde27219f10e4047dc7a6ab416f55d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33297531"
---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)
a variável necessita de quadro de pilha  
  
 Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não foi criada ainda.  
  
 Esse erro pode ocorrer quando você tiver entrado no prólogo de uma função, mas ainda não configurar o quadro de pilha para a função, ou se você tiver entrado em código de saída para a função.  
  
 Percorrer o código de prólogo até que o quadro da pilha foi configurado antes de avaliar a expressão.  
  
 Esse erro é idêntico ao CAN0065.