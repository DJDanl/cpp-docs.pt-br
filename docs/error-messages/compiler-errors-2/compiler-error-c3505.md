---
title: C3505 de erro do compilador | Microsoft Docs
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f7b13350ea7a2ffaf232e990bd3ade42d0c44a6c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3505"></a>C3505 de erro do compilador

> não é possível carregar a biblioteca de tipos '*guid*'  
  
C3505 pode ocorrer se você estiver executando o de 32 bits, hospedado x86 compilador cruzado para 64 bits, x64 destinos em 64 bits do computador, porque o compilador está em execução em WOW64 e só podem ler o hive de registro de 32 bits.  
  
Você pode resolver esse erro, a criação de versões de 32 bits e 64 bits da biblioteca de tipos que você está tentando importar e, em seguida, registre-os.  Ou você pode usar o compilador de 64 bits nativo, o que exige que você altere seu **diretórios VC + +** propriedade no IDE para apontar para o compilador de 64 bits.  
  
Para obter mais informações, consulte  
  
-   [Como habilitar um conjunto de ferramentas Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como configurar projetos do Visual C++ para terem plataformas x64 de 64 bits como destino](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)