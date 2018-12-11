---
title: Aviso D9035 (linha de comando)
ms.date: 12/10/2018
f1_keywords:
- D9035
helpviewer_keywords:
- D9035
ms.assetid: 6254f933-e37a-45ba-b860-1a870d1bc8e8
ms.openlocfilehash: 9c0a159dcf193b4ad016069bafd86c557e9e1281
ms.sourcegitcommit: 6990f842fefc27b522b15cf352f3517b319d78da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/11/2018
ms.locfileid: "53248514"
---
# <a name="command-line-warning-d9035"></a>Aviso D9035 (linha de comando)

> opção '*opção*' foi preterido e será removido em uma versão futura

## <a name="remarks"></a>Comentários

Você especificou uma opção de compilador que será removida em uma versão futura do compilador. Se não houver uma substituição sugerida para *opção*, esse aviso é seguido por aviso [D9036](../../error-messages/tool-errors/command-line-warning-d9036.md).

A opção especificada ainda funciona, mas você deve atualizar sua configuração de compilação agora. Como resultado, o seu projeto é mais provável continuar a criar quando você atualiza o compilador.

## <a name="see-also"></a>Consulte também

[Opções do compilador removidos e preteridos](../../build/reference/compiler-options-listed-by-category.md#deprecated-and-removed-compiler-options)<br/>
[Aviso de linha de comando D9036](command-line-warning-d9036.md)