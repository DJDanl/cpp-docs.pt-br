---
title: C2856 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2856
dev_langs:
- C++
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: fb5ecdb4f1c99a42a0e133d67cfa074ba2a069fc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2856"></a>C2856 de erro do compilador
\#pragma hdrstop não pode ser dentro de um bloco #if  
  
 O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.  
  
 Mova o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.
