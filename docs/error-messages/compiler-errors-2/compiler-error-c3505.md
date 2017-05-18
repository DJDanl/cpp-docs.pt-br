---
title: C3505 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3505
dev_langs:
- C++
helpviewer_keywords:
- C3505
ms.assetid: ed73c99e-93a1-4f3a-bac7-ba7ed5d836e4
caps.latest.revision: 4
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
ms.openlocfilehash: 8b728dd13c1ddc24d22b2bc7265074a843422161
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3505"></a>C3505 de erro do compilador
não é possível carregar a biblioteca de tipos 'guid'  
  
 C3505 pode ser causado se você estiver executando a (32 bits para) compilador cruzado de 64 bits em 64 bits do computador porque o compilador está em execução no WOW64 e pode somente leitura na seção do registro de 32 bits.  
  
 Você pode resolver essa C3505 criando versões de 32 bits e 64 bits da biblioteca de tipos que você está tentando importar e registre-os.  Ou você pode usar o compilador nativo de 64 bits, mas isso exigiria alterando seus diretórios VC + + no IDE para apontar para o compilador de 64 bits.  
  
 Para obter mais informações, consulte  
  
-   [Como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como: configurar projetos do Visual C++ para plataformas de 64 bits](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)
