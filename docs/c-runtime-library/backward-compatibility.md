---
title: Compatibilidade com versões anteriores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.programs
dev_langs:
- C++
helpviewer_keywords:
- CRT, compatibility
- backward compatibility, C run-time libraries
- compatibility, C run-time libraries
- backward compatibility
ms.assetid: cc3175cf-97fd-492f-b329-5791aea63090
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3056b90f3c6f0f62158a9b6dcfe145cda9740c6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092187"
---
# <a name="backward-compatibility"></a>Compatibilidade com versões anteriores

Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos em relação a novos nomes. Por exemplo, `open` mapeia para `_open`. Você deve vincular explicitamente com OLDNAMES. LIB somente quando você compilar com as seguintes combinações de opções de linha de comando:

- `/Zl`(omitir nome da biblioteca padrão do arquivo de objeto) e `/Ze` (o padrão — use extensões da Microsoft)

- `/link`(vinculador controle), `/NOD` (nenhuma pesquisa de biblioteca padrão) e `/Ze`

Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência de compilador](../build/reference/compiler-options.md).

## <a name="see-also"></a>Consulte também

[Compatibilidade](../c-runtime-library/compatibility.md)