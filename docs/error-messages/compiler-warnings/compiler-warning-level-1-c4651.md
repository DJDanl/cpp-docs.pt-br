---
title: "Compilador aviso (nível 1) C4651 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4651
dev_langs:
- C++
helpviewer_keywords:
- C4651
ms.assetid: f1ea82aa-4dc1-4972-b55a-57fdb962f0dd
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5746ab638928ceb422dfb0db52132d6b76df5777
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4651"></a>Compilador C4651 de aviso (nível 1)
'definição' especificada para o cabeçalho pré-compilado, mas não para a compilação atual  
  
 A definição foi especificada quando o cabeçalho pré-compilado foi gerado, mas não nesta compilação.  
  
 A definição será em vigor dentro do cabeçalho pré-compilado, mas não no restante do código.  
  
 Se um cabeçalho pré-compilado foi construído com /DSYMBOL, o compilador irá gerar esse aviso se a compilação /Yu não tem /DSYMBOL.  Adicionar /DSYMBOL à linha de comando /Yu resolve esse aviso.
