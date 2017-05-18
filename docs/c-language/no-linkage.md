---
title: "Sem ligação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: f906d67db7cc30bd019184f249dfae94289a4392
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="no-linkage"></a>Sem ligação
Se uma declaração de um identificador em um bloco não inclui o especificador de classe de armazenamento `extern`, o identificador não tem nenhuma vinculação e é exclusivo à função.  
  
 Os seguintes identificadores não têm nenhuma vinculação:  
  
-   Um identificador declarado como qualquer coisa que não seja um objeto ou uma função  
  
-   Um identificador declarado como um parâmetro de função  
  
-   Um identificador de escopo de bloco referente a um objeto declarado sem o especificador de classe de armazenamento `extern`  
  
 Se um identificador não tem nenhuma vinculação, declarar o mesmo nome novamente (em um declarador ou especificador de tipo) no mesmo nível de escopo gera um erro de redefinição de símbolo.  
  
## <a name="see-also"></a>Consulte também  
 [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
