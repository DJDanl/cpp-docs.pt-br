---
title: Varargs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: aac0c54b-0a2d-4a22-b1de-ee41381a3eb1
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8492610721846e8252cbe71b358e428a2aaf024f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="varargs"></a>Varargs
Se os parâmetros são passados por meio de varargs (por exemplo, argumentos de reticências), essencialmente o parâmetro normal passando aplica incluindo derramada os argumentos quinto e subsequentes. Novamente, é responsabilidade do receptor argumentos de despejo que ter seus endereços obtidos. Para valores de ponto flutuante somente, o número inteiro e o registro de ponto flutuante conterá o valor de float caso o chamador espera que o valor nos registradores inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)