---
title: NMAKE Erro Fatal U1073 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1073
dev_langs: C++
helpviewer_keywords: U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: faae317df44560991a88d47ec7f123e6a8126429
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)
Não sei como tornar 'targetname'  
  
 O destino especificado não existe e não há nenhum comando a ser executado ou a regra de inferência para aplicar.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Verifique a ortografia do nome do destino.  
  
2.  Se *targetname* é um pseudotarget especificá-lo como um destino em outro bloco de descrição.  
  
3.  Se *targetname* é uma invocação de macro, certifique-se de que ele não se expandir para uma cadeia de caracteres nula.