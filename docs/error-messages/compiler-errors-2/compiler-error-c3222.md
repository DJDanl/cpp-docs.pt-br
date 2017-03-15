---
title: C3222 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3222
dev_langs:
- C++
helpviewer_keywords:
- C3222
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
caps.latest.revision: 10
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: bd1058f4e33bc70c9021bfb1ceff78af58d09552
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3222"></a>C3222 de erro do compilador
'parâmetro': não é possível declarar argumentos padrão para o membro funções de gerenciada ou tipo WinRT ou genérico  
  
Não é permitido para declarar um parâmetro de método com um argumento padrão. Um formulário de sobrecarga do método é uma maneira de contornar esse problema. Ou seja, defina um método com o mesmo nome sem parâmetros e, em seguida, inicialize a variável no corpo do método.  
  
O exemplo a seguir gera C3222:  
  
```  
// C3222_2.cpp  
// compile with: /clr  
public ref class G {  
   void f( int n = 0 );   // C3222  
};  
```  

