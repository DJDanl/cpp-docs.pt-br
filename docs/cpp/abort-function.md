---
title: Função Abort | Microsoft Docs
ms.custom: ''
ms.date: 12/01/2017
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- abort function
ms.assetid: 3352bcc4-1a8a-4e1f-8dcc-fe30f6b50f2d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d6e0b7dc49fbc53eb5e079657d98380d10bedf4c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46036482"
---
# <a name="abort-function"></a>Função abort

O **anular** função, também declarada no arquivo de inclusão padrão \<stdlib. h >, encerra um programa C++. A diferença entre `exit` e **anular** é que `exit` permite que o processamento de encerramento do tempo de execução C++ ocorra (objeto global serão chamados destruidores), enquanto que **anular** Encerra o programa imediatamente. Para obter mais informações, consulte [anular](../c-runtime-library/reference/abort.md) na *referência de biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Término do programa](../cpp/program-termination.md)