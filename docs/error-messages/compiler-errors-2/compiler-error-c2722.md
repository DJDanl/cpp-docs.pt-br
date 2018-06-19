---
title: C2722 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2722
dev_langs:
- C++
helpviewer_keywords:
- C2722
ms.assetid: 4cc2c7fa-cb12-4bcf-9df1-6d627ef62973
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c8838ed6b2d202d58c9553a773da9653839b6c8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33236372"
---
# <a name="compiler-error-c2722"></a>C2722 de erro do compilador
':: operador ': inválido após comando operator; Use 'operator operador'  
  
 Um `operator` redefinições de instrução `::new` ou `::delete`. O `new` e `delete` operadores são globais, portanto, o operador de resolução do escopo (`::`) não tem sentido. Remover o `::` operador.