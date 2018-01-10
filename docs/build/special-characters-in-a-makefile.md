---
title: Caracteres especiais em um Makefile | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- NMAKE program, special characters
- makefiles, special characters
- special characters, in NMAKE macros
- macros, special characters
ms.assetid: 92c34ab5-ca6b-4fc0-bcf4-3172eaeda9f0
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6c574040d6004516682379a5e64b87c1b92388ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="special-characters-in-a-makefile"></a>Caracteres especiais em um makefile
Para usar um caractere especial NMAKE como um caractere literal, coloque um sinal de intercalação (^) na frente dele. NMAKE ignora acentos circunflexos que precedem outros caracteres. Os caracteres especiais são:  
  
 `:  ;  #  (  )  $  ^  \  {  }  !  @  —`  
  
 Um acento circunflexo (^) dentro de uma cadeia de caracteres entre aspas é tratado como um caractere literal do cursor. Um cursor no final de uma linha insere um caractere de nova linha literal em uma cadeia de caracteres ou uma macro.  
  
 Em macros, uma barra invertida (\\) seguido por uma nova linha será substituído por um espaço.  
  
 Em comandos, um símbolo de porcentagem (%) é um especificador de arquivo. Para representar % literalmente em um comando, especifique dois sinais de porcentagem (%) no lugar de uma única. Em outras situações, NMAKE interpreta um único % literalmente, mas ele sempre interpreta um duplo % % como um único %. Portanto, para representar um literal % %, especificar qualquer um dos sinais de três por cento % % %, ou sinais de porcentagem de quatro % % %.  
  
 Para usar o símbolo de cifrão ($) como um caractere literal em um comando, especifique dois cifrões ($$). Esse método também pode ser usado em outras situações onde ^ $ funciona.  
  
## <a name="see-also"></a>Consulte também  
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)