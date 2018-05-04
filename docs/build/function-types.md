---
title: Tipos de função | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7e33d5f4-dabb-406d-afb3-13777b995028
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 322bd45abbfe217671fd39f0617987fde21445db
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="function-types"></a>Tipos de função
Basicamente, há dois tipos de funções. Uma função que requer um quadro de pilha é chamada de função de quadro. Uma função que não requer um quadro de pilha é chamada de função de folha.  
  
 Uma função de quadro é uma função que aloca espaço de pilha, chama outras funções, salva os registros não volátil ou usa o tratamento de exceção. Ele também requer uma entrada de tabela de função. Uma função de quadro requer um prólogo e um epílogo. Uma função de quadro pode alocar dinamicamente o espaço de pilha e pode empregar um ponteiro de quadro. Uma função de quadro tem os recursos completos disso chamando padrão à sua disposição.  
  
 Se uma função de quadro não chama outra função, não é necessário para alinhar a pilha (mencionada na seção [alocação da pilha](../build/stack-allocation.md)).  
  
 Uma função de folha é aquele que não requer uma entrada de tabela de função. Ele não é possível alterar qualquer registros não volátil, incluindo RSP, o que significa que ele não é possível chamar quaisquer funções ou alocar espaço de pilha. É permitido para deixar a pilha não alinhado enquanto ele é executado.  
  
## <a name="see-also"></a>Consulte também  
 [Uso da pilha](../build/stack-usage.md)
