---
title: Erro PRJ0033 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0033
helpviewer_keywords:
- PRJ0033
ms.assetid: 84d4a052-0586-4b78-9315-81c1e8386c1e
ms.openlocfilehash: 141355ac49ec4722e85b5d4c25240e8048a72c9a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192174"
---
# <a name="project-build-error-prj0033"></a>Erro PRJ0033 (compilação de projeto)

A propriedade ' dependências adicionais ' para a etapa de compilação personalizada para o arquivo ' file ' continha ' macro ', que é avaliada como ' macro_expansion '.

Uma etapa de compilação personalizada em um arquivo continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, contendo caracteres ou combinações de caracteres ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
