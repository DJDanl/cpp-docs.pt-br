---
title: Coprocessador de ponto flutuante e convenções de chamada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- floating-point numbers [C++]
- floating-point coprocessor
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: da656442bc655db973f9b1e40cea76b8d7142819
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada
Se você estiver escrevendo assembly rotinas para flutuante coprocessador de ponto, você deve preservar flutuante aponte a palavra de controle e limpar a pilha de coprocessador, a menos que você estiver retornando um **float** ou **duplo** valor (que a função deve retornar em ST(0)).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)