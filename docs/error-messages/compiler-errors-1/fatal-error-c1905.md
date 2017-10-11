---
title: Erro fatal C1905 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1905
dev_langs:
- C++
helpviewer_keywords:
- C1905
ms.assetid: fefc6769-477f-45a2-9878-6f0a5f42472c
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9d1662b05764500d0ac6a96119f865294cac260b
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="fatal-error-c1905"></a>Erro fatal C1905
Front-end e back-end não compatíveis (devem usar o mesmo processador)  
  
 Este erro ocorre quando um arquivo .obj é gerado por um front-end do compilador (C1.dll) que tem como alvo um processador, como x86, ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], mas é lido por um back-end (C2.dll) que é destinado a um processador diferente.  
  
 Para corrigir esse problema, certifique-se de que você está usando um front-end e um back-end correspondentes. Esse é o padrão para projetos criados no Visual Studio. Este erro pode ocorrer se você editou o arquivo de projeto e usou caminhos diferentes para as ferramentas do compilador. Se você não tiver definido o caminho para as ferramentas do compilador especificamente, este erro pode ocorrer se a instalação do Visual Studio estiver corrompida. Por exemplo, talvez você tenha copiado os arquivos .dll do compilador de um local para outro. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.
