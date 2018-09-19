---
title: Erro de Build prj0009 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0009
dev_langs:
- C++
helpviewer_keywords:
- PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: efeb110823e801dd86a503a7069c4898f400769e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46057178"
---
# <a name="project-build-error-prj0009"></a>Erro de Build PRJ0009 no Projeto

Criar log não pôde ser aberto para gravação.

**Certifique-se de que o arquivo não está aberto por outro processo e não está protegido contra gravação.**

Depois de definir a **log de Build** propriedade **Sim** e executar um build ou recompilação, Visual C++ não pôde abrir o log de compilação no modo exclusivo.

Inspecionar a **log de Build** definindo abrindo o **opções** caixa de diálogo (no **ferramentas** menu, clique em **opções** comando) e, em seguida, selecionando **compilação do VC + +** na **projetos** pasta. O arquivo de build chama BuildLog. htm e é gravado para o diretório intermediário de $(IntDir).

Possíveis motivos para esse erro:

- Você está executando dois processos do Visual C++ e tentar compilar a mesma configuração do mesmo projeto em ambos simultaneamente.

- O arquivo de log de compilação é aberto em um processo que bloqueia o arquivo.

- O usuário não tem permissão para criar um arquivo.

- O usuário atual não tem acesso de gravação para o arquivo BuildLog.