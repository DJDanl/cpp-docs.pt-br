---
title: Varargs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: aac0c54b-0a2d-4a22-b1de-ee41381a3eb1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e7b71cd426bc89570f9d394f3e38dc7a002f6e8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="varargs"></a>Varargs
Se os parâmetros são passados por meio de varargs (por exemplo, argumentos de reticências), essencialmente o parâmetro normal passando aplica incluindo derramada os argumentos quinto e subsequentes. Novamente, é responsabilidade do receptor argumentos de despejo que ter seus endereços obtidos. Para valores de ponto flutuante somente, o número inteiro e o registro de ponto flutuante conterá o valor de float caso o chamador espera que o valor nos registradores inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)