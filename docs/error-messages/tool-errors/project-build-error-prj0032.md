---
title: Erro de Build prj0032 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PRJ0032
dev_langs: C++
helpviewer_keywords: PRJ0032
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 92497027db3a2449914696f03fc86a144a48b62e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0032"></a>Erro de Build PRJ0032 no Projeto
A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto continha 'macro', que é avaliado como 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um projeto tinha saída incorreta provavelmente devido a um problema de avaliação da macro. Esse erro também pode significar que o caminho é mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.