---
title: C2567 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2567
dev_langs: C++
helpviewer_keywords: C2567
ms.assetid: 9c140ac9-7059-47e6-9ba1-e7939c8c0dc3
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 28cd1dc74e15ae3cd63286fc6de9c3508bb1d279
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2567"></a>C2567 de erro do compilador
não é possível abrir metadados 'file', arquivo pode ter foi excluído ou movido  
  
 Um arquivo de metadados referenciado na fonte (com `#using`) não foi encontrado no mesmo diretório pelo processo de back-end do compilador como ele era pelo processo de front-end do compilador. Consulte [#using diretiva](../../preprocessor/hash-using-directive-cpp.md) para obter mais informações.  
  
 C2567 pode ocorrer se você compilar com **/c** em um computador e, em seguida, tente uma geração de código para link-time em outro computador. Para obter mais informações, consulte [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md)).  
  
 Ele também pode indicar que o computador tem não mais memória.  
  
 Para corrigir esse erro, certifique-se de que o arquivo de metadados é o mesmo local de diretório para todas as fases do processo de compilação.