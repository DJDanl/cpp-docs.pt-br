---
title: 2.5 constructos de compartilhamento de trabalho em paralelo de combinados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 45936e5a-c62a-4eea-a8f4-232210c9d0c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3c456eceb39d969e6841e3d3bf9028fae4bf5000
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404755"
---
# <a name="25-combined-parallel-work-sharing-constructs"></a>2.5 Constructos de compartilhamento de trabalho em paralelo combinado

Constructos de compartilhamento de trabalho combinados em paralelo são atalhos para especificar uma região paralela que contém apenas uma construção de compartilhamento de trabalho. A semântica dessas diretivas é idêntica de especificar explicitamente uma **paralela** diretiva seguido por um único constructo de compartilhamento de trabalho.

As seções a seguir descrevem as construções de compartilhamento de trabalho paralelas combinadas:

- o **paralela para** diretiva.

- o **seções em paralelo** diretiva.