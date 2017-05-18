---
title: Erro fatal C1305 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1305
dev_langs:
- C++
helpviewer_keywords:
- C1305
ms.assetid: 1629c850-e2db-4678-83d8-9bfc85323bc5
caps.latest.revision: 10
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f494e3649d24f40d13c82ed893a860562cba8bcc
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1305"></a>Erro fatal C1305
banco de dados de perfil 'pgd_file' é uma arquitetura diferente  
  
 Um arquivo. PGD que foi gerado da operação /LTCG:PGINSTRUMENT para outra plataforma foi passada para [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) . [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md) estão disponíveis para x86 e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] plataformas. No entanto, um arquivo. PGD gerado com uma operação de /LTCG:PGINSTRUMENT para uma plataforma não é válido como entrada para uma /LTCG:PGOPTIMIZE para uma plataforma diferente.  
  
 Para resolver esse erro, passe apenas um arquivo. PGD que é criado com /LTCG:PGINSTRUMENT para /LTCG:PGOPTIMIZE na mesma plataforma.
