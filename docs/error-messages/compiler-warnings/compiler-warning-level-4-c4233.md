---
title: "Compilador aviso (nível 4) C4233 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4233
dev_langs:
- C++
helpviewer_keywords:
- C4233
ms.assetid: 9aa51fc6-8ef3-43b5-bafb-c9333cf60de3
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
ms.openlocfilehash: 993bb9f48775fae49ed66df21126ac40449f9634
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4233"></a>Compilador C4233 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' só tem suportado em C++, não C  
  
 O compilador compilado seu código-fonte como C em vez de C++, e você usou uma palavra-chave só é válida em C++. O compilador compila o arquivo de origem como C se a extensão do arquivo de origem é. c ou usar [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md).  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema do aviso de nível 4, C4233  
  
```  
#pragma warning(2:4233)  
```  
  
 no arquivo de código fonte.
