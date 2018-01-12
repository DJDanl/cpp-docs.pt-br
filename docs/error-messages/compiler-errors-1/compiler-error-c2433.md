---
title: C2433 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2433
dev_langs: C++
helpviewer_keywords: C2433
ms.assetid: 7079fedd-6059-4125-82ef-ebe275f1f9d1
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 565c013f36cf8c9037c461e74c24cf18a21194f9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2433"></a>C2433 de erro do compilador
'Identificador': 'modificador' não é permitido em declarações de dados  
  
 O `friend`, `virtual`, e `inline` modificadores não podem ser usados para declarações de dados.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2433.  
  
```  
// C2433.cpp  
class C{};  
  
int main() {  
   inline C c;   // C2433  
}  
```