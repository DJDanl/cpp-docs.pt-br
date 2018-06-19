---
title: C4962 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4962
dev_langs:
- C++
helpviewer_keywords:
- C4962
ms.assetid: 62b156fe-04e5-4a6e-9339-6ab148185f87
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 74878342e153a78c6149ae3b177eff8c49e4a261
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33272094"
---
# <a name="compiler-warning-c4962"></a>C4962 de aviso do compilador
"function': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente"  
  
 Uma função não foi compilada com /LTCG:PGO, porque os dados de contagem (perfil) para a função não confiáveis. Refaça a criação de perfil para gerar o arquivo. PGC que contém os dados de perfil não confiável para essa função.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).