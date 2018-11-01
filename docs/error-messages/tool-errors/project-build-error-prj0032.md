---
title: Erro de Build PRJ0032 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0032
helpviewer_keywords:
- PRJ0032
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
ms.openlocfilehash: f1f292f3979c993a8fa8cb8ff44653ac7124b121
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499824"
---
# <a name="project-build-error-prj0032"></a>Erro de Build PRJ0032 no Projeto

A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto continha 'macro', que é avaliado como 'macro_expansion'.

Uma etapa de compilação personalizada em um projeto teve saída incorreta provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.