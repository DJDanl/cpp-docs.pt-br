---
title: Erro fatal C1905 | Documentos do Microsoft
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
ms.openlocfilehash: 6fb82fa80566f576b80c6bc7a0e27e4e2e7c3a7e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1905"></a>Erro fatal C1905
Front-end e back-end não compatíveis (devem usar o mesmo processador)  
  
 Este erro ocorre quando um arquivo .obj é gerado por um front-end do compilador (C1.dll) que tem como alvo um processador, como x86, ARM ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], mas é lido por um back-end (C2.dll) que é destinado a um processador diferente.  
  
 Para corrigir esse problema, certifique-se de que você está usando um front-end e um back-end correspondentes. Esse é o padrão para projetos criados no Visual Studio. Este erro pode ocorrer se você editou o arquivo de projeto e usou caminhos diferentes para as ferramentas do compilador. Se você não tiver definido o caminho para as ferramentas do compilador especificamente, este erro pode ocorrer se a instalação do Visual Studio estiver corrompida. Por exemplo, talvez você tenha copiado os arquivos .dll do compilador de um local para outro. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.
