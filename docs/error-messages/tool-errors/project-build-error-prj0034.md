---
title: "PRJ0034 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0034
dev_langs:
- C++
helpviewer_keywords:
- PRJ0034
ms.assetid: 1da4a55b-231b-4476-8545-6997628fbc00
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
ms.openlocfilehash: 0c4b9e5fc6c2b80729df021f439f537d60b34501
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0034"></a>Erro de Build PRJ0034 no Projeto
A propriedade 'Additional Dependencies' para o nível de projeto personalizado de compilação etapa contida 'macro' que é avaliado como 'macro_expansion'.  
  
 Uma etapa de compilação personalizada em um projeto continha um erro em sua dependência adicional provavelmente devido a um problema de avaliação de macro. Esse erro também pode significar que o caminho é mal formado, contendo caracteres ou combinações de caracteres são ilegais em um caminho de arquivo.  
  
 Para resolver esse erro, corrija a macro ou corrigir a especificação do caminho. O caminho avaliado é um caminho absoluto do diretório do projeto.
