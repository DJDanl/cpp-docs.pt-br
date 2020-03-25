---
title: Erro fatal C1905
ms.date: 11/04/2016
f1_keywords:
- C1905
helpviewer_keywords:
- C1905
ms.assetid: fefc6769-477f-45a2-9878-6f0a5f42472c
ms.openlocfilehash: 106dfe8a078047225097686d185a1ba43987ce33
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202613"
---
# <a name="fatal-error-c1905"></a>Erro fatal C1905

Front-end e back-end não compatíveis (devem usar o mesmo processador)

Esse erro ocorre quando um arquivo. obj é gerado por um front-end do compilador (C1. dll) que tem como alvo um processador, como x86, ARM ou x64, mas está sendo lido por um back-end (C2. dll) que tem como alvo um processador diferente.

Para corrigir esse problema, certifique-se de que você está usando um front-end e um back-end correspondentes. Esse é o padrão para projetos criados no Visual Studio. Este erro pode ocorrer se você editou o arquivo de projeto e usou caminhos diferentes para as ferramentas do compilador. Se você não tiver definido o caminho para as ferramentas do compilador especificamente, este erro pode ocorrer se a instalação do Visual Studio estiver corrompida. Por exemplo, talvez você tenha copiado os arquivos .dll do compilador de um local para outro. Use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.
