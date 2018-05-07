---
title: Erro de Build prj0034 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0034
dev_langs:
- C++
helpviewer_keywords:
- PRJ0034
ms.assetid: 1da4a55b-231b-4476-8545-6997628fbc00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a65ca2c53ba2801f861471c66f7e1f2ec8766345
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="project-build-error-prj0034"></a>Erro de Build PRJ0034 no Projeto
A propriedade 'Additional Dependencies' para o nível de projeto personalizado compilação etapa contida 'macro' que é avaliado como 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um projeto continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação da macro. Esse erro também pode significar que o caminho é mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.