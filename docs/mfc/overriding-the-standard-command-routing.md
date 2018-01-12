---
title: "Substituindo o roteamento de comando padrão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], overriding
- command handling [MFC], routing commands
- overriding, standard command routing
ms.assetid: 872b698a-7432-40c4-9008-68721e8effa5
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6a8f926a2aa9ed48dac24f75850876bbd1e04ef4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overriding-the-standard-command-routing"></a>Substituindo o roteamento de comando padrão
Em casos raros, quando você deve implementar algumas variações de roteamento de estrutura padrão, você pode substituí-la. A ideia é alterar o roteamento em uma ou mais classes, substituindo `OnCmdMsg` nessas classes. Fazer isso:  
  
-   Na classe que interrompe a ordem para passar para um objeto não padrão.  
  
-   No novo objeto não padrão ou em destinos de comando por sua vez ele pode passar comandos para.  
  
 Se você inserir um novo objeto para o roteamento, sua classe deve ser uma classe de destino do comando. Em suas versões de substituição do `OnCmdMsg`, certifique-se de chamar a versão que você está substituindo. Consulte o [OnCmdMsg](../mfc/reference/ccmdtarget-class.md#oncmdmsg) função de membro de classe `CCmdTarget` no *referência MFC* e as versões nessas classes como `CView` e **CDocument** no fornecido para obter exemplos de código-fonte.  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

