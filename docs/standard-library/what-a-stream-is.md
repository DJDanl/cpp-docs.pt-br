---
title: "O que é um fluxo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- reading data [C++], iostream programming
- data [C++], reading
- streams [C++], in iostream classes
- streams [C++]
ms.assetid: a7e661e9-6cd1-4543-a9a4-c58ee9fd32f3
caps.latest.revision: 8
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
ms.openlocfilehash: 75c23582cbbb42a417a7a5effdb879300c2a7732
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="what-a-stream-is"></a>O que é um fluxo
Como na C, a C++ não tem funcionalidade interna de entrada/saída. Todos os compiladores C++, no entanto, são fornecidos com um pacote de E/S sistemático orientado a objeto, conhecido como as classes iostream. O fluxo é o conceito central das classes iostream. Você pode pensar em um objeto de fluxo como um arquivo inteligente que atua como origem e destino para bytes. As características do fluxo são determinadas por sua classe e por operadores personalizados de inserção e de extração.  
  
 Por meio de drivers de dispositivos, o sistema operacional do disco lida com o teclado, a tela, a impressora e as portas de comunicação como arquivos estendidos. As classes iostream interagem com esses arquivos estendidos. As classes internas dão suporte à leitura e à gravação na memória com sintaxe idêntica à da E/S de disco, o que facilita a derivação das classes de fluxo.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Alternativas de entrada/saída](../standard-library/input-output-alternatives.md)  
  
## <a name="see-also"></a>Consulte também  
 [Programação de iostream](../standard-library/iostream-programming.md)


