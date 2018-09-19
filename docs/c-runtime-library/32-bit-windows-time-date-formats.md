---
title: Formatos de data/hora do Windows de 32 bits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- vc.time
dev_langs:
- C++
helpviewer_keywords:
- 32-bit Windows
ms.assetid: ef1589db-84d7-4b24-8799-7c7a22cfe2bf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 55eca447de7818f749628505a4c4f2fa6eb0dcd2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46061104"
---
# <a name="32-bit-windows-timedate-formats"></a>Formatos de data/hora do Windows de 32 bits

A data e a hora do arquivo são armazenadas individualmente, usando inteiros sem sinal como campos de bits. A data e a hora do arquivo são incluídas como segue:

### <a name="time"></a>Hora

|Posição de bit:|0   1   2   3   4|5   6   7   8   9   A|B   C   D   E   F|
|-------------------|-----------------------|---------------------------|-----------------------|
|Comprimento:|5|6|5|
|Conteúdo:|horas|minutos|incrementos de 2 segundos|
|Alcance de valores:|0-23|0-59|0-29 em intervalos de 2 segundos|

### <a name="date"></a>Date

|Posição de bit:|0   1   2   3   4   5   6|7   8   9   A|B   C   D   E   F|
|-------------------|-------------------------------|-------------------|-----------------------|
|Comprimento:|7|4|5|
|Conteúdo:|ano|mês|dia|
|Alcance de valores:|0-119|1-12|1-31|
||(relativo a 1980)|||

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)