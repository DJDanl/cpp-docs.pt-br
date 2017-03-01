---
title: C2447 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2447
dev_langs:
- C++
helpviewer_keywords:
- C2447
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: eddf391965641a7c91074d05dbcfffa298945494
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2447"></a>C2447 de erro do compilador
“{”: cabeçalho de função ausente (lista formal antiga?)  
  
 O compilador encontrou uma chave de abertura inesperada no escopo global. Na maioria dos casos, isso é causado por um cabeçalho malformado, uma declaração posicionada incorretamente ou por um ponto-e-vírgula disperso. Para resolver esse problema, verifique se a chave de abertura segue um cabeçalho de função formado corretamente e não é precedida de uma declaração ou um ponto-e-vírgula disperso.  
  
 Esse erro também pode ser causado por uma lista de argumentos formais em linguagem C antiga. Para resolver esse problema, refatore a lista de argumentos para usar um estilo moderno, ou seja, incluído entre parênteses.  
  
 O exemplo a seguir gera C2447:  
  
```  
// C2447.cpp  
int c;  
{}       // C2447  
```
