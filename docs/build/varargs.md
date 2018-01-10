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
ms.workload: cplusplus
ms.openlocfilehash: f3d22a5c3f20480d1e904ec8e087114385ba7ee9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="varargs"></a>Varargs
Se os parâmetros são passados por meio de varargs (por exemplo, argumentos de reticências), essencialmente o parâmetro normal passando aplica incluindo derramada os argumentos quinto e subsequentes. Novamente, é responsabilidade do receptor argumentos de despejo que ter seus endereços obtidos. Para valores de ponto flutuante somente, o número inteiro e o registro de ponto flutuante conterá o valor de float caso o chamador espera que o valor nos registradores inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)