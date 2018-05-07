---
title: CXX0017 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0017
dev_langs:
- C++
helpviewer_keywords:
- CAN0017
- CXX0017
ms.assetid: af74db02-a64d-49ca-8363-3e044a107580
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f7540dc701ffa6e0acb3d2661e1196e5f4552d2c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="expression-evaluator-error-cxx0017"></a>Erro CXX0017 (avaliador de expressão)
símbolo não encontrado  
  
 Não foi possível encontrar um símbolo especificado em uma expressão.  
  
 Uma possível causa desse erro é uma incompatibilidade de casos em que o nome do símbolo. Como C e C++ são idiomas diferencia maiusculas de minúsculas, um nome de símbolo deve ser fornecido em diferencie maiusculas de minúsculas no qual ele é definido na fonte.  
  
 Esse erro pode ocorrer durante a tentativa de conversão de tipo uma variável para assistir a variável durante a depuração. O `typedef` declara um novo nome de um tipo, mas não define um novo tipo. A tentativa no depurador typecast requer o nome de um tipo definido.  
  
 Esse erro é idêntico ao CAN0017.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Verifique se que o símbolo já está declarado no ponto no programa de onde ele está sendo usado.  
  
2.  Use um nome de tipo real para converter variáveis no depurador, em vez de `typedef`-nome definido.