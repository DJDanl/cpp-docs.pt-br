---
title: Tools.ini e NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, reading files
- Tools.ini and NMake
ms.assetid: ebd5eab6-ddf4-430e-bf4a-1db5bb84e344
ms.openlocfilehash: 38eebb3aaf07438da85b0cfe6bd3f26fb5d6db29
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317673"
---
# <a name="toolsini-and-nmake"></a>Tools.ini e NMAKE

NMAKE lê Tools. ini antes que ele lê makefiles, a menos que /R é usado. Ele procura Tools. ini primeiro no diretório atual e, em seguida, no diretório especificado pela variável de ambiente de inicialização. A seção de configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter qualquer informação de makefile. Especifique um comentário em uma linha separada que começa com um sinal numérico (#).

## <a name="see-also"></a>Consulte também

[Executando NMAKE](running-nmake.md)
