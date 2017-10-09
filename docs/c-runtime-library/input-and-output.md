---
title: "Entrada e saída | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.io
dev_langs:
- C++
helpviewer_keywords:
- input routines
- I/O [CRT]
- I/O routines
- I/O [CRT], routines
- output routines
ms.assetid: 1c177301-e341-4ca0-aedc-0a87fe1c75ae
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 5c4705ae56f11c1299e512814f8d83a49690a6ac
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="input-and-output"></a>Entrada e saída
As funções de E/S leem e gravam dados de e para dispositivos e arquivos. Operações de E/S de arquivo ocorrem no modo de texto ou binário. A biblioteca em tempo de execução da Microsoft tem três tipos de funções de E/S:  
  
-   Funções [Fluxo de E/S](../c-runtime-library/stream-i-o.md) tratam os dados como um fluxo de caracteres individuais.  
  
-   Funções [E/S de baixo nível](../c-runtime-library/low-level-i-o.md) invocam o sistema operacional diretamente para a operação de nível mais baixo do que o fornecido pelo fluxo de E/S.  
  
-   Funções [Console e E/S de porta](../c-runtime-library/console-and-port-i-o.md) leem ou gravam diretamente em um console (tela e teclado) ou uma porta de E/S (como uma porta de impressora).  
  
    > [!NOTE]
    >  Como funções de fluxo são armazenadas em buffer e funções de nível inferior não são armazenadas, esses dois tipos de funções são geralmente incompatíveis. Para processar um arquivo específico, use o fluxo ou funções de nível inferior exclusivamente.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
