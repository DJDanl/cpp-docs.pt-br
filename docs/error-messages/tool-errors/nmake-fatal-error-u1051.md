---
title: Erro fatal U1051 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1051
helpviewer_keywords:
- U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
ms.openlocfilehash: ddf1d262fb8dfc6e63b0bf5cc098b7b140539310
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641500"
---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)

Memória insuficiente

NMAKE ficou sem memória, incluindo a memória virtual, porque o makefile era muito grande ou complexo.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Libere espaço em disco.

1. Aumente o tamanho do arquivo de paginação do Windows NT ou o arquivo de permuta do Windows.

1. Se apenas parte do makefile estiver sendo usado, divida o makefile em arquivos separados ou use **! Se** pré-processando diretivas para limitar a quantidade que NMAKE deve processar. O **! IF** incluem diretivas **! IF**, `!IFDEF`, **! IFNDEF**, **! ELSE IF**, **! ELSE** `IFDEF`, e **! ELSE** `IFNDEF`.