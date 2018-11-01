---
title: 2.4 Construtos Work-sharing
ms.date: 11/04/2016
ms.assetid: 25bb4ded-8466-4daa-a863-766b5a99b995
ms.openlocfilehash: e7bf8d37ecdc6a3ef451c9d9746fb47a76a16eb4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502876"
---
# <a name="24-work-sharing-constructs"></a>2.4 Construtos Work-sharing

Uma construção de compartilhamento de trabalho distribui a execução da instrução associada entre os membros da equipe que encontrá-lo. As diretivas de compartilhamento de trabalho não iniciar novos threads e não há nenhum barreira implícita na entrada para uma construção de compartilhamento de trabalho.

Constrói a sequência de compartilhamento de trabalho e **barreira** diretivas encontradas devem ser o mesmo para cada thread em uma equipe.

OpenMP define as seguintes construções de compartilhamento de trabalho, e elas são descritas nas seções a seguir:

- **para** diretiva

- **seções** diretiva

- **único** diretiva