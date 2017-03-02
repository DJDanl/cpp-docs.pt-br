---
title: Aviso LNK4075 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4075
dev_langs:
- C++
helpviewer_keywords:
- LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
caps.latest.revision: 8
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
ms.sourcegitcommit: 9dee257bec0f09bd729bf10c4a1468ecb20dfa61
ms.openlocfilehash: 84dea754a1d2268c92e703dd04b0169ccc258ab3
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4075"></a>Aviso LNK4075 (Ferramentas de Vinculador)
Ignorando a opção "1" devido à especificação de "option2"  
  
 A segunda opção substitui o primeiro.  
  
 Opções do vinculador mutuamente estão sendo especificadas.  Examine as opções do vinculador.  Onde são especificadas opções de vinculador depende de como você está criando o projeto.  
  
-   Se você estiver criando no ambiente de desenvolvimento, examine as páginas de propriedades do vinculador para seu projeto e ver onde as duas opções de vinculador estão sendo especificadas.  Consulte [trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md) para obter mais informações.  
  
-   Se você compilar na linha de comando, observe as opções do vinculador especificadas não existe.  
  
-   Se você compilar com scripts de compilação, examine seus scripts para ver onde essas opções de vinculador estão sendo especificadas.  
  
 Quando você encontrar onde são especificadas as opções do vinculador mutuamente, remova uma das opções do vinculador.  
  
 Alguns exemplos específicos:  
  
-   Se você vincular um módulo que foi compilado com **/ZI**, o que implica uma opção de vinculador interno chamada /EDITANDCONTINUE e um módulo que foi compilado com /OPT: REF, /OPT: ICF ou /incremental, que não significa nenhum /EDITANDCONTINUE, você obterá LNK4075.  Consulte [/Z7, /Zi, /ZI (formato informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md) para obter mais informações.
