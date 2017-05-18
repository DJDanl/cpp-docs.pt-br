---
title: Aviso LNK4102 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4102
dev_langs:
- C++
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 10787b30d700583ab998d5ece757c7d8aa4c6f60
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)
exportação de exclusão de destruidor 'name'; imagem pode não funcionar corretamente  
  
 O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de forma que um processo pode liberar memória que não possui. Certifique-se de que o símbolo fornecido não está listado no arquivo. def e que o símbolo não está listado como um argumento do **/importação** ou **/exportar** opção na linha de comando do vinculador.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.
