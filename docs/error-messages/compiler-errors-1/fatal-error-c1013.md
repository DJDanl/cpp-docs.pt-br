---
title: Erro fatal C1013 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1013
dev_langs:
- C++
helpviewer_keywords:
- C1013
ms.assetid: 5514a679-efe7-4055-bdd3-5693ca0c332f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 00b5dae643ec20e9d7d8a8dcdf41d9debe7e6b7e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1013"></a>Erro fatal C1013
limite do compilador: muitos parênteses abertos  
  
 Uma expressão contém muitos níveis de parênteses em uma única expressão. Simplifique a expressão ou dividi-la em várias instruções.  
  
 Antes do Visual C++ 6.0 Service Pack 3, o limite de parênteses aninhados em uma única expressão foi 59. Atualmente, o limite de parênteses aninhados é 256.