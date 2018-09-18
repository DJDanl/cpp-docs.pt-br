---
title: Erro de Build prj0032 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0032
dev_langs:
- C++
helpviewer_keywords:
- PRJ0032
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 106b1c3f470bbdb134a5fd53ebaef65a4392fd4b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053564"
---
# <a name="project-build-error-prj0032"></a>Erro de Build PRJ0032 no Projeto

A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto continha 'macro', que é avaliado como 'macro_expansion'.

Uma etapa de compilação personalizada em um projeto teve saída incorreta provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho está mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.

Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.