---
title: Erro de Build prj0031 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0031
dev_langs:
- C++
helpviewer_keywords:
- PRJ0031
ms.assetid: b42435c6-e570-4f8e-9ad5-12a7ea69ccb2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d5ebd25c239a05c4300b574ec0d47035904187d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318315"
---
# <a name="project-build-error-prj0031"></a>Erro de Build PRJ0031 no Projeto
A propriedade 'Outputs' para a compilação personalizada passo para o arquivo 'file' contido 'macro' que é avaliado 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um arquivo tinha saída incorreta provavelmente devido a um problema de avaliação da macro. Esse erro também pode significar que o caminho é mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.