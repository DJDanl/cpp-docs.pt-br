---
title: Alternativas de saída de entrada
ms.date: 05/07/2019
helpviewer_keywords:
- I/O [C++], alternatives
ms.assetid: 9f8401c7-d90d-4285-8918-63573df74a80
ms.openlocfilehash: b46ff242fc263be5069eb691dd0ea9e8fb00b0f9
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455297"
---
# <a name="inputoutput-alternatives"></a>Alternativas de Entrada/Saída

O compilador C++ da Microsoft fornece várias alternativas para a programação de e/s:

- E/S não armazenada em buffer, direta, da biblioteca em tempo de execução C.

- E/S de fluxo da biblioteca em tempo de execução do C ANSI.

- E/S direta de porta e console.

- Biblioteca MFC.

- Biblioteca Padrão C++ da Microsoft.

As classes iostream são úteis para E/S de texto formatado, armazenada em buffer. Elas também são úteis para E/S binária ou não armazenada em buffer se você precisar de uma interface de programação de C++ e optar por não usar a biblioteca MFC. As classes iostream são uma alternativa de E/S voltada ao objeto às funções de tempo de execução de C.

É possível usar classes iostream com o sistema operacional Microsoft Windows. Fluxos de arquivos e cadeias de caracteres funcionam sem restrições, mas os objetos de fluxo de modo de caractere `cin`, `cout`, `cerr` e `clog` são inconsistentes com a interface gráfica do usuário do Windows. Também é possível derivar classes de fluxos personalizados que interagem diretamente com o ambiente do Windows.

## <a name="see-also"></a>Consulte também

[O que é um fluxo](../standard-library/what-a-stream-is.md)
