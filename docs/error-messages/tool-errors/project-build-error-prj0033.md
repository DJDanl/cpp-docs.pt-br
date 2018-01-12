---
title: Erro de Build prj0033 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: PRJ0033
dev_langs: C++
helpviewer_keywords: PRJ0033
ms.assetid: 84d4a052-0586-4b78-9315-81c1e8386c1e
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0cd7bcc0239ce88a19ae6009195f120a88be59ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0033"></a>Erro de Build PRJ0033 no Projeto
A propriedade 'Additional Dependencies' para a compilação personalizada passo para o arquivo 'file' contido 'macro' que é avaliado 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um arquivo continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação da macro. Esse erro também pode significar que o caminho é mal formado, que contém caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrija a especificação do caminho. O caminho de avaliado é um caminho absoluto do diretório do projeto.