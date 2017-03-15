---
title: C2097 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2097
dev_langs:
- C++
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
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
ms.openlocfilehash: 0f983b1e5786ed820874209984fa3d4dc3760dbf
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2097"></a>C2097 de erro do compilador
inicialização inválida  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Inicialização de uma variável com um valor não constante.  
  
2.  Inicialização de um endereço curto com um endereço longo.  
  
3.  Inicialização de uma estrutura local, união ou matriz com uma expressão não constante ao compilar com **/Za**.  
  
4.  Inicialização com uma expressão que contém um operador de vírgula.  
  
5.  Inicialização com uma expressão que é constante nem simbólico.
