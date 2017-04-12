---
title: "Compilador (níveis 1 e 4) de aviso C4115 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4115
dev_langs:
- C++
helpviewer_keywords:
- C4115
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 865ac3098afb947fb80fd0a6dce94d69f25593c0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-levels-1-and-4-c4115"></a>Compilador C4115 de aviso (níveis 1 e 4)
'type': chamada a definição de tipo entre parênteses  
  
 Determinado símbolo é usado para definir uma estrutura, união ou tipo enumerado dentro de uma expressão entre parênteses. A definição do escopo pode ser inesperado.  
  
 Em uma chamada de função C, a definição tem escopo global. Em uma chamada de C++, a definição tem o mesmo escopo da função que está sendo chamado.  
  
 Esse aviso também pode ser causado por declaradores dentro dos parênteses (como protótipos) que não são expressões entre parênteses.  
  
 Este é um aviso de nível&1; com programas do C++ e C compilados em compatibilidade com ANSI (/Za). Caso contrário, ele é o nível 3.
