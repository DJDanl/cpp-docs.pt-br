---
title: Erro de Build PRJ0032 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0032
helpviewer_keywords:
- PRJ0032
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
ms.openlocfilehash: 62efa0e72c6fbe4bd38983ff0507923392427c04
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192478"
---
# <a name="project-build-error-prj0032"></a>Erro de Build PRJ0032 no Projeto

A propriedade ' Outputs ' para a etapa de compilação personalizada no nível do projeto continha ' macro ', que é avaliada como ' macro_expansion '.

Uma etapa de compilação personalizada em um projeto tinha uma saída inadequada provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, contendo caracteres ou combinações de caracteres ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
