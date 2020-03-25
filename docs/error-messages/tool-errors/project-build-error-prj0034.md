---
title: Erro de Build PRJ0034 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0034
helpviewer_keywords:
- PRJ0034
ms.assetid: 1da4a55b-231b-4476-8545-6997628fbc00
ms.openlocfilehash: bcb7e22d6a09e3435eb2236532101a1836c08a03
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192172"
---
# <a name="project-build-error-prj0034"></a>Erro de Build PRJ0034 no Projeto

A propriedade ' dependências adicionais ' para a etapa de compilação personalizada em nível de projeto continha ' macro ', que é avaliada como ' macro_expansion '.

Uma etapa de compilação personalizada em um projeto continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, contendo caracteres ou combinações de caracteres ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
