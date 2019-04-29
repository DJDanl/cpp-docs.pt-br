---
title: Erro de Build PRJ0009 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0009
helpviewer_keywords:
- PRJ0009
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
ms.openlocfilehash: 963b7c861f9e8ee7105ebdc23afff08c4be46465
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359495"
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