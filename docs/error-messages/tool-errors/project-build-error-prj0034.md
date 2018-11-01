---
title: Erro de Build PRJ0034 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0034
helpviewer_keywords:
- PRJ0034
ms.assetid: 1da4a55b-231b-4476-8545-6997628fbc00
ms.openlocfilehash: 7c078a3d2aef24df9151cb10f81c1b7423809e68
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50549052"
---
# <a name="project-build-error-prj0034"></a>Erro de Build PRJ0034 no Projeto

A propriedade 'Additional Dependencies' para o nível de projeto personalizado compilar etapa contida 'macro' que é avaliado como 'macro_expansion'.

Uma etapa de compilação personalizada em um projeto continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.