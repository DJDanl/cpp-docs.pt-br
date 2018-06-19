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
ms.openlocfilehash: 4acfbb5a0790dec6f7b5770832cc6b09f69a28d7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32408015"
---
# <a name="abort-function"></a>Função abort

O **anular** função, também é declarada no arquivo de inclusão padrão \<stdlib.h >, encerra um programa C++. A diferença entre **sair** e **anular** é que **sair** permite o processamento de término do tempo de execução C++ ocorra (objeto global destruidores serão chamados), enquanto **anular** o programa é encerrado imediatamente. Para obter mais informações, consulte [anular](../c-runtime-library/reference/abort.md) no *referência da biblioteca de tempo de execução*.

## <a name="see-also"></a>Consulte também

[Término do programa](../cpp/program-termination.md)