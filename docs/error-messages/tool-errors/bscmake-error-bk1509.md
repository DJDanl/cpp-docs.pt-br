---
title: Erro de BSCMAKE BK1509 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK1509
dev_langs:
- C++
helpviewer_keywords:
- BK1509
ms.assetid: 53df7037-1913-4b63-b425-c0bf44081792
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 091fab63737c7ee1b3b85753a354bb7214cfa411
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025237"
---
# <a name="bscmake-error-bk1509"></a>Erro BK1509 (BSCMAKE)

sem espaço de heap

BSCMAKE ficou sem memória, incluindo a memória virtual.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Libere espaço em disco.

1. Aumente o tamanho do arquivo de permuta.

1. Aumente o tamanho do arquivo de permuta do Windows.

1. Reduza a memória que BSCMAKE requer usando /Ei ou /Es eliminar alguns arquivos ou /Em para eliminar os corpos de macro de entrada.