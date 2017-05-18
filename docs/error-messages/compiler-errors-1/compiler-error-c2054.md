---
title: C2054 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2054
dev_langs:
- C++
helpviewer_keywords:
- C2054
ms.assetid: 37f7c612-0d7d-4728-9e67-ac4160555f48
caps.latest.revision: 7
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: dbaf9a6589c939952b2965998d56366f1698c3d8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2054"></a>C2054 de erro do compilador
esperado ' (' a seguir 'Identificador'  
  
 O identificador de função é usado em um contexto que requer parênteses à direita.  
  
 Esse erro pode ser causado por um sinal de igual (=) em uma inicialização complexa a omissão.  
  
 O exemplo a seguir gera C2054:  
  
```  
// C2054.c  
int array1[] { 1, 2, 3 };   // C2054, missing =  
```  
  
 Resolução possível:  
  
```  
// C2054b.c  
int main() {  
   int array2[] = { 1, 2, 3 };  
}  
```
