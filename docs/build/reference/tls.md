---
title: /TLS
ms.date: 11/04/2016
f1_keywords:
- /TLS
helpviewer_keywords:
- /TLS dumpbin option
- -TLS dumpbin option
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
ms.openlocfilehash: 1760e94046a950f67d3c3fd7ef13aa40ca7de47a
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417782"
---
# <a name="tls"></a>/TLS

Exibe a estrutura IMAGE_TLS_DIRECTORY de um executável.

## <a name="remarks"></a>Comentários

/ TLS exibe os campos da estrutura de TLS, bem como os endereços das funções de retorno de chamada de TLS.

Se um programa não usar o armazenamento local de thread, sua imagem não conterá uma estrutura TLS.  Ver [thread](../../cpp/thread.md) para obter mais informações.

IMAGE_TLS_DIRECTORY é definido em Winnt. h.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)
