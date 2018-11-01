---
title: Função abort
ms.date: 12/01/2017
helpviewer_keywords:
- abort function
ms.assetid: 3352bcc4-1a8a-4e1f-8dcc-fe30f6b50f2d
ms.openlocfilehash: 7c87cb4fe7349a0d623c765c20e7e213a8454571
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451227"
---
# <a name="abort-function"></a>Função abort

O **anular** função, também declarada no arquivo de inclusão padrão \<stdlib. h >, encerra um programa C++. A diferença entre `exit` e **anular** é que `exit` permite que o processamento de encerramento do tempo de execução C++ ocorra (objeto global serão chamados destruidores), enquanto que **anular** Encerra o programa imediatamente. Para obter mais informações, consulte [anular](../c-runtime-library/reference/abort.md) na *referência de biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Término do programa](../cpp/program-termination.md)