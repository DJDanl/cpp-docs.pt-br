---
title: NMAKE Erro Fatal U1073 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1073
dev_langs:
- C++
helpviewer_keywords:
- U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dde9ca2f4a15edf6599dcc31b39d9411645f2a6f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33316300"
---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)
Não sei como tornar 'targetname'  
  
 O destino especificado não existe e não há nenhum comando a ser executado ou a regra de inferência para aplicar.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Verifique a ortografia do nome do destino.  
  
2.  Se *targetname* é um pseudotarget especificá-lo como um destino em outro bloco de descrição.  
  
3.  Se *targetname* é uma invocação de macro, certifique-se de que ele não se expandir para uma cadeia de caracteres nula.