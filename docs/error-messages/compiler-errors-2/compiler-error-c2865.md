---
title: C2865 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2865
dev_langs:
- C++
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 149ca019ef30d66dba63bc927d79064a269d8c70
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2865"></a>C2865 de erro do compilador
'function': comparação inválida para handle_or_pointer  
  
 Você pode comparar as referências a [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md) ou tipos de referência somente para fins de igualdade para ver se elas se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).  
  
 Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.