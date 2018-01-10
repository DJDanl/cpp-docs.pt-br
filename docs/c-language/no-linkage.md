---
title: "Sem ligação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: abacc6fbd49f9f42620385a4206c9412648c173b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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