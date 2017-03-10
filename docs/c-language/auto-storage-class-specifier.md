---
title: Especificador de classe de armazenamento auto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 8e73f57e-aa92-4e41-91ea-5c8ad2a2b332
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 942759b9866f2ad749c4683de6ec90d4c9c5089e
ms.lasthandoff: 02/25/2017

---
# <a name="auto-storage-class-specifier"></a>Especificador de classe de armazenamento auto
O especificador de classe de armazenamento **auto** declara uma variável automática, uma variável com um tempo de vida local. Uma variável **auto** pode ser vista somente no bloco em que é declarada. As declarações de variáveis **auto** podem incluir inicializadores, conforme discutido em [Inicialização](../c-language/initialization.md). Como as variáveis com a classe de armazenamento **auto** não são inicializadas automaticamente, você deve inicializá-las explicitamente ao declará-las ou atribuir valores iniciais a elas em instruções no bloco. Os valores das variáveis **auto** não inicializadas estão indefinidos. (A variável local da classe de armazenamento **auto** ou **register** será inicializada sempre que aparecer no escopo, se um inicializador for fornecido.)  
  
 Uma variável interna **static** (uma variável estática com escopo local ou de bloco) pode ser inicializada com o endereço de qualquer item externo ou **static**, mas não com o endereço de outro item **auto**, pois o endereço de um item **auto** não é uma constante.  
  
## <a name="see-also"></a>Consulte também  
 [Palavra-chave auto](../cpp/auto-keyword.md)
