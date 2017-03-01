---
title: C2142 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2142
dev_langs:
- C++
helpviewer_keywords:
- C2142
ms.assetid: d0dbe10e-0952-49a4-8b33-e82fb7558b19
caps.latest.revision: 9
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
ms.openlocfilehash: d52eff9bee2f55d5fc67e9300f7278373a7f6f98
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2142"></a>C2142 de erro do compilador
declarações da função diferem, parâmetros variáveis especificados em apenas uma delas  
  
 Uma declaração da função contém uma lista de parâmetros de variável. Outra declaração não. ANSI C ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) apenas.  
  
 O exemplo a seguir gera C2142:  
  
```  
// C2142.c  
// compile with: /Za /c  
void func();  
void func( int, ... );   // C2142  
void func2( int, ... );   // OK  
```
