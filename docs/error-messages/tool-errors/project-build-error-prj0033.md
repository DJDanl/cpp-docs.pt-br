---
title: Erro de Build PRJ0033 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0033
helpviewer_keywords:
- PRJ0033
ms.assetid: 84d4a052-0586-4b78-9315-81c1e8386c1e
ms.openlocfilehash: e074ee18508271b56686aa16f9012085ed3bd77d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50586206"
---
# <a name="project-build-error-prj0033"></a>Erro de Build PRJ0033 no Projeto

A propriedade 'Additional Dependencies' para a compilação personalizada passo para o arquivo 'file' contido 'macro' que é avaliado 'macro_expansion'.

Uma etapa de compilação personalizada em um arquivo continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.