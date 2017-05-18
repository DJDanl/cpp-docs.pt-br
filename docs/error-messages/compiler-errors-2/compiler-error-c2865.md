---
title: C2865 de erro do compilador | Documentos do Microsoft
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 3bb55d094e00400c57617857aa1ac29677f1b72a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2865"></a>C2865 de erro do compilador
'function': comparação ilegal para handle_or_pointer  
  
 Você pode comparar as referências a [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md) ou tipos de referência somente para igualdade para ver se eles se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).  
  
 Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.
