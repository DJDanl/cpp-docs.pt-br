---
title: "CXX0065 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0065
dev_langs:
- C++
helpviewer_keywords:
- CAN0065
- CXX0065
ms.assetid: aac68f87-0b90-4c19-afa6-1c587625a5fd
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
ms.openlocfilehash: ff7093ee69dea3f39a37110bdc8076d1dc0e5cbe
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0065"></a>Erro CXX0065 (avaliador de expressão)
a variável necessita de moldura da pilhas  
  
 Uma expressão continha uma variável que existe dentro do escopo atual, mas ainda não tiver sido criada.  
  
 Esse erro pode ocorrer quando você ter passado no prólogo de uma função, mas ainda não configurar o quadro de pilhas da função, ou se você ter passado para o código de saída para a função.  
  
 Percorrer o código de prólogo até que o quadro de pilha foi configurado antes de avaliar a expressão.  
  
 Esse erro é idêntico ao CAN0065.
