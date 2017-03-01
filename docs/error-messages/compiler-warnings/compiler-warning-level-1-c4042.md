---
title: "Compilador aviso (nível 1) C4042 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4042
dev_langs:
- C++
helpviewer_keywords:
- C4042
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
caps.latest.revision: 6
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 53c7d3cd497ebb07e0bea7f326655d6c287c9a64
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4042"></a>Compilador C4042 de aviso (nível 1)
'identifier': tem a classe de armazenamento inválido  
  
 A classe de armazenamento especificada não pode ser usada com este identificador neste contexto. Em vez disso, o compilador usa a classe de armazenamento padrão:  
  
-   `extern`, se *identificador* é uma função.  
  
-   **auto**, se *identificador* é um parâmetro formal ou variável local.  
  
-   Nenhum armazenamento de classe, se *identificador* é uma variável global.  
  
 Esse aviso pode ser causado por especificar uma classe de armazenamento diferente de **registrar** em uma declaração de parâmetro.  
  
 O exemplo a seguir gera C4042  
  
```  
// C4042.cpp  
// compile with: /W1 /LD  
int func2( __declspec( thread ) int tls_i )    // C4042  
// try the following line instead  
// int func2( int tls_i )  
{  
   return tls_i;  
}  
```
