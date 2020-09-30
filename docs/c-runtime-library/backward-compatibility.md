---
title: Backward Compatibility
description: Como usar o Microsoft OLDNAMES. Biblioteca LIB para mapear nomes de funções para compatibilidade com versões anteriores.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- CRT, compatibility
- backward compatibility, C run-time libraries
- compatibility, C run-time libraries
- backward compatibility
ms.assetid: cc3175cf-97fd-492f-b329-5791aea63090
ms.openlocfilehash: b09104a5cff4d8e4cc31f9cc4707e808988401d6
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590284"
---
# <a name="backward-compatibility"></a>Backward Compatibility

Para compatibilidade entre versões do produto, a biblioteca OLDNAMES.LIB mapeia nomes antigos em relação a novos nomes. Por exemplo, `open` mapeia para `_open`. Você deve vincular explicitamente com OLDNAMES. LIB somente quando você compilar com as seguintes combinações de opções de linha de comando:

- `/Zl`(omitir nome da biblioteca padrão do arquivo de objeto) e `/Ze` (o padrão — use extensões da Microsoft)

- `/link`(vinculador controle), `/NOD` (nenhuma pesquisa de biblioteca padrão) e `/Ze`

Para obter mais informações sobre opções de linha de comando do compilador, consulte [Referência de compilador](../build/reference/compiler-options.md).

## <a name="see-also"></a>Confira também

[Compatibilidade](../c-runtime-library/compatibility.md)
