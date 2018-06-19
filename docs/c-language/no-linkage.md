---
title: Sem ligação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7dc6515020272d19a9b9efca7341293be4983a56
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32383781"
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