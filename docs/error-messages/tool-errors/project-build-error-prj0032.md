---
title: "PRJ0032 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0032
dev_langs:
- C++
helpviewer_keywords:
- PRJ0032
ms.assetid: bc6acbea-4041-4237-8b5a-f0434705d89f
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 40645f929c19d68ba972784cbbfdd45f5890218c
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0032"></a>Erro de Build PRJ0032 no Projeto
A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto continha 'macro', que é avaliado como 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um projeto teve saída incorreta provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho é mal formado, contendo caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
