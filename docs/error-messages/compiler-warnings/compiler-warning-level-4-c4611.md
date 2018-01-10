---
title: "Compilador (nível 4) de aviso C4611 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4611
dev_langs: C++
helpviewer_keywords: C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3020cf7d115b735141b81e9007ac7fd027ed8674
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4611"></a>Compilador C4611 de aviso (nível 4)
interação entre 'function' e destruição de objeto C++ é não portátil  
  
 Em algumas plataformas, funções que incluam **catch** pode não oferecer suporte a semântica de objeto C++ de destruição quando estiver fora do escopo.  
  
 Para evitar um comportamento inesperado, evite usar **catch** em funções que tenham construtores e destruidores.  
  
 Esse aviso é emitido somente uma vez; consulte [aviso de pragma](../../preprocessor/warning.md).