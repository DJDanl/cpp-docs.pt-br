---
title: C4962 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4962
dev_langs:
- C++
helpviewer_keywords:
- C4962
ms.assetid: 62b156fe-04e5-4a6e-9339-6ab148185f87
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: dae3bfa67f9f40072c8c200cd681b3babd92aff3
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-c4962"></a>C4962 de aviso do compilador
"function': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente"  
  
 Uma função não foi compilada com /LTCG:PGO, porque os dados de contagem (perfil) para a função não confiáveis. Refaça a criação de perfil para gerar o arquivo. PGC que contém os dados de perfil não confiável para essa função.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
