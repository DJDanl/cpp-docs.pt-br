---
title: Aviso do compilador C4962
ms.date: 11/04/2016
f1_keywords:
- C4962
helpviewer_keywords:
- C4962
ms.assetid: 62b156fe-04e5-4a6e-9339-6ab148185f87
ms.openlocfilehash: e3f7b715da3774d8289fdd526cf1fa0b5bdddba6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585309"
---
# <a name="compiler-warning-c4962"></a>Aviso do compilador C4962

"function': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente"

Uma função não foi compilada com /ltcg: PGO, porque os dados de contagem (perfil) para a função não confiáveis. Refa a criação de perfil para gerar o arquivo. PGC que contém os dados de perfil não confiável para essa função.

Esse aviso é desativado por padrão. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).