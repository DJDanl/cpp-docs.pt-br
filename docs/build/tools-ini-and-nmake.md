---
title: Tools.ini e NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, reading files
- Tools.ini and NMake
ms.assetid: ebd5eab6-ddf4-430e-bf4a-1db5bb84e344
ms.openlocfilehash: 1a8673741cb49c504855fb1af00dbdc06379210d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50654409"
---
# <a name="toolsini-and-nmake"></a>Tools.ini e NMAKE

NMAKE lê Tools. ini antes que ele lê makefiles, a menos que /R é usado. Ele procura Tools. ini primeiro no diretório atual e, em seguida, no diretório especificado pela variável de ambiente de inicialização. A seção de configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter qualquer informação de makefile. Especifique um comentário em uma linha separada que começa com um sinal numérico (#).

## <a name="see-also"></a>Consulte também

[Executando NMAKE](../build/running-nmake.md)