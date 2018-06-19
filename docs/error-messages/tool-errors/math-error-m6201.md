---
title: Matemática erro M6201 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6201
dev_langs:
- C++
helpviewer_keywords:
- M6201
ms.assetid: 4041c331-d9aa-4dd4-b565-7dbe0218538c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d6a15e841cfc8daf1abdafc9997698807e7356af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33332059"
---
# <a name="math-error-m6201"></a>Erro M6201 (Math)
'function': erro de Domain  
  
 Um argumento para a função fornecida estava fora do domínio de valores de entrada válidos para essa função.  
  
## <a name="example"></a>Exemplo  
  
```  
result = sqrt(-1.0)   // C statement  
result = SQRT(-1.0)   !  FORTRAN statement  
```  
  
 Esse erro chama o `_matherr` função com o tipo de erro, o nome da função e seus argumentos. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.