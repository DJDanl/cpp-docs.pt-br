---
title: Tools.ini e NMAKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, reading files
- Tools.ini and NMake
ms.assetid: ebd5eab6-ddf4-430e-bf4a-1db5bb84e344
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 860a334274a3a1a4ac9e11c3e7b5e9a0f136ecc0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32380544"
---
# <a name="toolsini-and-nmake"></a>Tools.ini e NMAKE
NMAKE lê Tools.ini antes de ler makefiles, a menos que /R é usada. Ele procura Tools.ini primeiro no diretório atual e, em seguida, no diretório especificado pela variável de ambiente de inicialização. A seção de configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter qualquer informação de makefile. Especifique um comentário em uma linha separada que começa com um sinal numérico (#).  
  
## <a name="see-also"></a>Consulte também  
 [Executando NMAKE](../build/running-nmake.md)