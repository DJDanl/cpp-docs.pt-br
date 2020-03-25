---
title: Erro de Build PRJ0031 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0031
helpviewer_keywords:
- PRJ0031
ms.assetid: b42435c6-e570-4f8e-9ad5-12a7ea69ccb2
ms.openlocfilehash: e13236f65aaca778a297cdd2942c07b75dd701d0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192491"
---
# <a name="project-build-error-prj0031"></a>Erro de Build PRJ0031 no Projeto

A propriedade ' Outputs ' para a etapa de compilação personalizada para o arquivo ' file ' continha ' macro ', que é avaliada como ' macro_expansion '.

Uma etapa de compilação personalizada em um arquivo tinha uma saída inadequada provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, contendo caracteres ou combinações de caracteres ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
