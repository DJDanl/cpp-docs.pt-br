---
title: /TLS
ms.date: 11/04/2016
f1_keywords:
- /TLS
helpviewer_keywords:
- /TLS dumpbin option
- -TLS dumpbin option
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
ms.openlocfilehash: 751c212398f3d309b1d31d204291fe3a0503cf06
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811856"
---
# <a name="tls"></a>/TLS

Exibe a estrutura IMAGE_TLS_DIRECTORY de um executável.

## <a name="remarks"></a>Comentários

/ TLS exibe os campos da estrutura de TLS, bem como os endereços das funções de retorno de chamada de TLS.

Se um programa não usar o armazenamento local de thread, sua imagem não conterá uma estrutura TLS.  Ver [thread](../../cpp/thread.md) para obter mais informações.

IMAGE_TLS_DIRECTORY é definido em Winnt. h.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
