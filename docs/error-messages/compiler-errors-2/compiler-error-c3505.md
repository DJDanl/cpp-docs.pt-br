---
title: C3505 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3505
dev_langs: C++
helpviewer_keywords: C3505
ms.assetid: ed73c99e-93a1-4f3a-bac7-ba7ed5d836e4
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 47ca6c4e8e8c01e97ed0098c84c8ea8c64f387a6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3505"></a>C3505 de erro do compilador

> não é possível carregar a biblioteca de tipos '*guid*'  
  
C3505 pode ocorrer se você estiver executando o de 32 bits, hospedado x86 compilador cruzado para 64 bits, x64 destinos em 64 bits do computador, porque o compilador está em execução em WOW64 e só podem ler o hive de registro de 32 bits.  
  
Você pode resolver esse erro, a criação de versões de 32 bits e 64 bits da biblioteca de tipos que você está tentando importar e, em seguida, registre-os.  Ou você pode usar o compilador de 64 bits nativo, o que exige que você altere seu **diretórios VC + +** propriedade no IDE para apontar para o compilador de 64 bits.  
  
Para obter mais informações, consulte  
  
-   [Como habilitar um conjunto de ferramentas Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como: configurar projetos do Visual C++ para o destino de 64 bits x64 plataformas](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)