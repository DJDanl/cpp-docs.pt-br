---
title: "Entrada e saída | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: 424cf158f8d5801f0fd4e1b92e9c95d792832b2d
ms.lasthandoff: 02/25/2017

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
