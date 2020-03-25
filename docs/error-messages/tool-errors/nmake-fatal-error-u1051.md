---
title: Erro fatal U1051 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1051
helpviewer_keywords:
- U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
ms.openlocfilehash: 9c6b939c97f993e42049677292374377d825d474
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193674"
---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)

memória insuficiente

O NMAKE ficou sem memória, incluindo a memória virtual, porque o makefile era muito grande ou complexo.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Libere espaço no disco.

1. Aumente o tamanho do arquivo de paginação do Windows NT ou do arquivo de permuta do Windows.

1. Se apenas parte do makefile estiver sendo usada, divida o makefile em arquivos separados ou use-o **! SE** diretivas de pré-processamento para limitar o valor que NMAKE deve processar. O **! SE** as diretivas incluírem **! SE**, `!IFDEF`, **! IFNDEF**, **! CASO contrário**, **! Caso contrário** `IFDEF`e **! Caso contrário** `IFNDEF`.
