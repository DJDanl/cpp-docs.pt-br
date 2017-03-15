---
title: NMAKE Erro Fatal U1073 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1073
dev_langs:
- C++
helpviewer_keywords:
- U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
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
ms.openlocfilehash: 522998f6c294e053b89fbc652045c22d17b1596d
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)
não sabe como tornar 'targetname'  
  
 O destino especificado não existir, e nenhum comando para executar ou a regra de inferência para aplicar.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Verifique a ortografia do nome do destino.  
  
2.  Se *targetname* é um pseudotarget, especifique-o como um destino em outro bloco de descrição.  
  
3.  Se *targetname* é uma invocação de macro, certifique-se de que ele não será expandida para uma cadeia de caracteres nula.
