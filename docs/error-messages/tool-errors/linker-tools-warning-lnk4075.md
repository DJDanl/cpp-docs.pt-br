---
title: Aviso LNK4075 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4075
dev_langs:
- C++
helpviewer_keywords:
- LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4bd9a4ecdad30a0be2d45300367f6f79a65a6b31
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33301028"
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