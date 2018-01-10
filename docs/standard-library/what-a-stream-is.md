---
title: "O que é um fluxo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- reading data [C++], iostream programming
- data [C++], reading
- streams [C++], in iostream classes
- streams [C++]
ms.assetid: a7e661e9-6cd1-4543-a9a4-c58ee9fd32f3
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7084a0fb74d963532e01623e8e9047768c67f801
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="what-a-stream-is"></a>O que é um fluxo
Como na C, a C++ não tem funcionalidade interna de entrada/saída. Todos os compiladores C++, no entanto, são fornecidos com um pacote de E/S sistemático orientado a objeto, conhecido como as classes iostream. O fluxo é o conceito central das classes iostream. Você pode pensar em um objeto de fluxo como um arquivo inteligente que atua como origem e destino para bytes. As características do fluxo são determinadas por sua classe e por operadores personalizados de inserção e de extração.  
  
 Por meio de drivers de dispositivos, o sistema operacional do disco lida com o teclado, a tela, a impressora e as portas de comunicação como arquivos estendidos. As classes iostream interagem com esses arquivos estendidos. As classes internas dão suporte à leitura e à gravação na memória com sintaxe idêntica à da E/S de disco, o que facilita a derivação das classes de fluxo.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Alternativas de entrada/saída](../standard-library/input-output-alternatives.md)  
  
## <a name="see-also"></a>Consulte também  
 [Programação de iostream](../standard-library/iostream-programming.md)

