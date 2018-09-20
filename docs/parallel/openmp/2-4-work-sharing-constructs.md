---
title: 2.4 construtos work-sharing | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 25bb4ded-8466-4daa-a863-766b5a99b995
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 719b33698b708761f0cd56e65a70a6ea8fa3b053
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46411112"
---
# <a name="24-work-sharing-constructs"></a>2.4 Construtos Work-sharing

Uma construção de compartilhamento de trabalho distribui a execução da instrução associada entre os membros da equipe que encontrá-lo. As diretivas de compartilhamento de trabalho não iniciar novos threads e não há nenhum barreira implícita na entrada para uma construção de compartilhamento de trabalho.

Constrói a sequência de compartilhamento de trabalho e **barreira** diretivas encontradas devem ser o mesmo para cada thread em uma equipe.

OpenMP define as seguintes construções de compartilhamento de trabalho, e elas são descritas nas seções a seguir:

- **para** diretiva

- **seções** diretiva

- **único** diretiva