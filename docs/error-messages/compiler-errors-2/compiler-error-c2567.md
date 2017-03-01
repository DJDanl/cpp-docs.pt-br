---
title: C2567 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2567
dev_langs:
- C++
helpviewer_keywords:
- C2567
ms.assetid: 9c140ac9-7059-47e6-9ba1-e7939c8c0dc3
caps.latest.revision: 4
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
ms.openlocfilehash: 6cd355d7654f931196acc324f7d58b99c6f25f29
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2567"></a>C2567 de erro do compilador
não é possível abrir metadados no 'arquivo', arquivo pode ter foram excluído ou movido  
  
 Um arquivo de metadados que foi referenciado na fonte (com `#using`) não foi encontrado no mesmo diretório pelo processo de back-end do compilador como era pelo processo de front-end do compilador. Consulte [#using diretiva](../../preprocessor/hash-using-directive-cpp.md) para obter mais informações.  
  
 C2567 pode ser causado se você compilar com **/c** em uma máquina e, em seguida, tente uma geração de código para link-time em outra máquina. Para obter mais informações, consulte [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md)).  
  
 Isso também pode indicar que o computador tem não mais memória.  
  
 Para corrigir esse erro, verifique se o arquivo de metadados está no mesmo local de diretório para todas as fases do processo de compilação.
