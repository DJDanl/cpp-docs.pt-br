---
title: Aviso do compilador C4962
ms.date: 11/04/2016
f1_keywords:
- C4962
helpviewer_keywords:
- C4962
ms.assetid: 62b156fe-04e5-4a6e-9339-6ab148185f87
ms.openlocfilehash: a600c1875040e1076978bb80c467e6232303cd82
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164840"
---
# <a name="compiler-warning-c4962"></a>Aviso do compilador C4962

' function ': otimizações guiadas por perfil desabilitadas porque otimizações fizeram com que os dados de perfil se tornem inconsistentes "

Uma função não foi compilada com/LTCG: PGO, pois os dados de contagem (perfil) da função não são confiáveis. Refazer a criação de perfil para gerar novamente o arquivo. pgc que contém os dados de perfil não confiáveis para essa função.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
