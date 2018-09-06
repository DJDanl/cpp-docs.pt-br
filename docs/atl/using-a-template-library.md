---
title: Usando um Template Library (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- template libraries
ms.assetid: 5e80ec6e-a61c-41ce-b34b-9a6252c46265
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 91a9c10bef285780ded145e33800ebd3db198827
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754766"
---
# <a name="using-a-template-library"></a>Usando uma biblioteca de modelos

Um modelo é um pouco como uma macro. Assim como acontece com uma macro, invocar um modelo faz com que ele expandir (com a substituição de parâmetro apropriado) para o código escrito por você. No entanto, um modelo vai além do que esta opção para permitir a criação de novas classes com base nos tipos que você passa como parâmetros. Essas novas classes implementam fortemente tipado maneiras de executar a operação expressada em seu código de modelo.

Bibliotecas de modelo como ATL diferem das bibliotecas de classes C++ tradicionais geralmente são fornecidos somente como código-fonte (ou como código-fonte com um pouco, que dão suporte a tempo de execução) e não são hierárquicas por natureza ou necessariamente por natureza. Em vez de derivar de uma classe para obter a funcionalidade desejada, você instancia uma classe a partir de um modelo.

## <a name="see-also"></a>Consulte também

[Introdução à ATL](../atl/introduction-to-atl.md)

