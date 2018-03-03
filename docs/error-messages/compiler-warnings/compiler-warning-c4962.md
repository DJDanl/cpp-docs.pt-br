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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: da57dfd020b1763d0749f66098a17c37a722a44d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4962"></a>C4962 de aviso do compilador
"function': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente"  
  
 Uma função não foi compilada com /LTCG:PGO, porque os dados de contagem (perfil) para a função não confiáveis. Refaça a criação de perfil para gerar o arquivo. PGC que contém os dados de perfil não confiável para essa função.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).