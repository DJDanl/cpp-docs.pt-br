---
title: "Compilador (nível 1) de aviso C4042 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4042
dev_langs: C++
helpviewer_keywords: C4042
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3369b2786c552e408e8eedf8e6ed8bf73f272ff6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4042"></a>Compilador C4042 de aviso (nível 1)
'Identificador': possui classe de armazenamento incorreta  
  
 A classe de armazenamento especificado não pode ser usada com este identificador neste contexto. Em vez disso, o compilador usa a classe de armazenamento padrão:  
  
-   `extern`, se *identificador* é uma função.  
  
-   **auto**, se *identificador* é uma variável local ou o parâmetro formal.  
  
-   Nenhum armazenamento de classe, se *identificador* é uma variável global.  
  
 Esse aviso pode ser causado por especificar uma classe de armazenamento diferente **registrar** em uma declaração de parâmetro.  
  
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