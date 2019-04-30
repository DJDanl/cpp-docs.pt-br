---
title: Alternativas de entrada e saída
ms.date: 11/04/2016
helpviewer_keywords:
- I/O [C++], alternatives
ms.assetid: 9f8401c7-d90d-4285-8918-63573df74a80
ms.openlocfilehash: bc595b64c991ada8e958e71e13f8cb9d134adb8a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404956"
---
# <a name="inputoutput-alternatives"></a>Alternativas de Entrada/Saída

O Visual C++ fornece várias alternativas para programação de E/S:

- E/S não armazenada em buffer, direta, da biblioteca em tempo de execução C.

- E/S de fluxo da biblioteca em tempo de execução do C ANSI.

- E/S direta de porta e console.

- Biblioteca MFC.

- Biblioteca Padrão C++ da Microsoft.

As classes iostream são úteis para E/S de texto formatado, armazenada em buffer. Elas também são úteis para E/S binária ou não armazenada em buffer se você precisar de uma interface de programação de C++ e optar por não usar a biblioteca MFC. As classes iostream são uma alternativa de E/S voltada ao objeto às funções de tempo de execução de C.

É possível usar classes iostream com o sistema operacional Microsoft Windows. Fluxos de arquivos e cadeias de caracteres funcionam sem restrições, mas os objetos de fluxo de modo de caractere `cin`, `cout`, `cerr` e `clog` são inconsistentes com a interface gráfica do usuário do Windows. Também é possível derivar classes de fluxos personalizados que interagem diretamente com o ambiente do Windows.

## <a name="see-also"></a>Consulte também

[O que é um fluxo](../standard-library/what-a-stream-is.md)<br/>
