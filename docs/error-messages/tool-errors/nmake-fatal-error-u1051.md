---
title: NMAKE Erro Fatal U1051 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1051
dev_langs:
- C++
helpviewer_keywords:
- U1051
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d3d3a14b75a30aa22bcc9faafb97a218051bb080
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045010"
---
# <a name="nmake-fatal-error-u1051"></a>Erro fatal U1051 (NMAKE)

Memória insuficiente

NMAKE ficou sem memória, incluindo a memória virtual, porque o makefile era muito grande ou complexo.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Libere espaço em disco.

1. Aumente o tamanho do arquivo de paginação do Windows NT ou o arquivo de permuta do Windows.

1. Se apenas parte do makefile estiver sendo usado, divida o makefile em arquivos separados ou use **! Se** pré-processando diretivas para limitar a quantidade que NMAKE deve processar. O **! IF** incluem diretivas **! IF**, `!IFDEF`, **! IFNDEF**, **! ELSE IF**, **! ELSE** `IFDEF`, e **! ELSE** `IFNDEF`.