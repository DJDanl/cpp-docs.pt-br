---
title: "CXX0017 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0017
dev_langs:
- C++
helpviewer_keywords:
- CAN0017
- CXX0017
ms.assetid: af74db02-a64d-49ca-8363-3e044a107580
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 65b6e174a00071094ec6fbee4f835848cf8688f9
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0017"></a>Erro CXX0017 (avaliador de expressão)
símbolo não encontrado  
  
 Não foi possível encontrar um símbolo especificado em uma expressão.  
  
 Uma possível causa desse erro é uma incompatibilidade de maiusculas no nome do símbolo. Como C e C++ são linguagens diferencia maiusculas de minúsculas, um nome de símbolo deve ser fornecido em diferencie maiusculas de minúsculas no qual está definido na origem.  
  
 Esse erro pode ocorrer durante a tentativa de conversão de tipo uma variável para assistir a variável durante a depuração. O `typedef` declara um novo nome para um tipo, mas não define um novo tipo. A tentativa no depurador typecast requer o nome de um tipo definido.  
  
 Esse erro é idêntico ao CAN0017.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Verifique se que o símbolo já está declarado no ponto no programa onde ele está sendo usado.  
  
2.  Use um nome de tipo real para converter variáveis no depurador, em vez de uma `typedef`-nome definido.
