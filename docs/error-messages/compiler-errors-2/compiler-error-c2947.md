---
title: C2947 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2947
dev_langs: C++
helpviewer_keywords: C2947
ms.assetid: 6c056f62-ec90-4883-8a67-aeeb6ec13546
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: bb5b22d4fd4b874e19cff564dec96609f9da0789
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2947"></a>C2947 de erro do compilador
esperando ' >' para encerrar a construção, encontrado 'sintaxe'  
  
 Uma lista de argumento genérico ou modelo pode não ter sido encerrada corretamente.  
  
 C2947 também pode ser gerado por erros de sintaxe.  
  
 O exemplo a seguir gera C2947:  
  
```  
// C2947.cpp  
// compile with: /c  
template <typename T>=   // C2947  
// try the following line instead  
// template <typename T>  
struct A {};  
```