---
title: Aviso LNK4075 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4075
dev_langs: C++
helpviewer_keywords: LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 78ff64b316a9b87a95fa68a95b5e4ca57923649d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4075"></a>Aviso LNK4075 (Ferramentas de Vinculador)
Ignorando a opção "1" devido à especificação de "option2"  
  
 A segunda opção substitui o primeiro.  
  
 Opções do vinculador mutuamente estão sendo especificadas.  Examine suas opções do vinculador.  Em que as opções do vinculador são especificadas depende de como você está criando o projeto.  
  
-   Se você estiver criando no ambiente de desenvolvimento, examine as páginas de propriedades de vinculador para seu projeto e ver onde as duas opções de vinculador estão sendo especificadas.  Consulte [trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md) para obter mais informações.  
  
-   Se você compilar na linha de comando, examine as opções de vinculador especificadas existe.  
  
-   Se você compilar com scripts de compilação, procure por meio de seus scripts para ver onde essas opções de vinculador estão sendo especificadas.  
  
 Quando você localizar onde as opções de vinculador mutuamente forem especificadas, remova uma das opções de vinculador.  
  
 Alguns exemplos específicos:  
  
-   Se você vincular um módulo que foi compilado com **/ZI**, que implica uma opção de vinculador interno chamado /EDITANDCONTINUE e um módulo que foi compilado com /OPT: REF, /OPT: ICF ou /incremental: no, que implica em nenhuma /EDITANDCONTINUE, você vai obter LNK4075.  Consulte [/Z7, /Zi, /ZI (Depurar formato de informações)](../../build/reference/z7-zi-zi-debug-information-format.md) para obter mais informações.