---
title: Erro fatal C1905 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1905
dev_langs:
- C++
helpviewer_keywords:
- C1905
ms.assetid: fefc6769-477f-45a2-9878-6f0a5f42472c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 263bf0ff63d71f381e68ea33b294abd423f59bf4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46058439"
---
# <a name="fatal-error-c1905"></a>Erro fatal C1905

Front-end e back-end não compatíveis (devem usar o mesmo processador)

Esse erro ocorre quando um arquivo. obj é gerado por um front end do compilador (C1.dll) que um processador de destinos, como x86, ARM ou x64, mas está sendo lido por um back-end (C2.dll) que tem como alvo um processador diferente.

Para corrigir esse problema, certifique-se de que você está usando um front-end e um back-end correspondentes. Esse é o padrão para projetos criados no Visual Studio. Este erro pode ocorrer se você editou o arquivo de projeto e usou caminhos diferentes para as ferramentas do compilador. Se você não tiver definido o caminho para as ferramentas do compilador especificamente, este erro pode ocorrer se a instalação do Visual Studio estiver corrompida. Por exemplo, talvez você tenha copiado os arquivos .dll do compilador de um local para outro. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.