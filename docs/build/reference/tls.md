---
title: /TLS
ms.date: 11/04/2016
f1_keywords:
- /TLS
helpviewer_keywords:
- /TLS dumpbin option
- -TLS dumpbin option
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
ms.openlocfilehash: c125a6439e6cda2159a8bde2317528e667eaf310
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532613"
---
# <a name="tls"></a>/TLS

Exibe a estrutura IMAGE_TLS_DIRECTORY de um executável.

## <a name="remarks"></a>Comentários

/ TLS exibe os campos da estrutura de TLS, bem como os endereços das funções de retorno de chamada de TLS.

Se um programa não usar o armazenamento local de thread, sua imagem não conterá uma estrutura TLS.  Ver [thread](../../cpp/thread.md) para obter mais informações.

IMAGE_TLS_DIRECTORY é definido em Winnt. h.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)