---
title: C3398 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3398
dev_langs:
- C++
helpviewer_keywords:
- C3398
ms.assetid: 26f8c8a4-526f-415b-8047-155c5cd4f180
caps.latest.revision: 7
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
ms.openlocfilehash: 799a334cba62ea66b3a9e255df47e201823cfa41
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3398"></a>C3398 de erro do compilador
'operator': não é possível converter de 'function_signature' em 'function_pointer'. Expressão fonte deve ser um símbolo de função  
  
 Quando o [clrcall](../../cpp/clrcall.md) convenção de chamada não for especificada durante a compilação com **/clr**, o compilador gera dois pontos de entrada (endereços) para cada função, um ponto de entrada nativo e um ponto de entrada gerenciado.  
  
 Por padrão, o compilador retorna o ponto de entrada nativo, mas há alguns casos em que o ponto de entrada gerenciado é desejado (por exemplo ao atribuir o endereço para um `__clrcall` ponteiro de função). Para o compilador confiável, escolha o ponto de entrada gerenciado em uma atribuição, o lado direito deve ser um símbolo de função.
