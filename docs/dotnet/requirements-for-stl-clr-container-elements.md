---
title: Requisitos dos elementos de contêiner STL/CLR
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- C++ Standard Library, template class containers
- STL/CLR, containers
- containers, STL/CLR
- containers, C++ Standard Library
ms.assetid: 59ab240c-15bf-4701-a9f9-e7c56e5ab53f
ms.openlocfilehash: 0744d38a08dbd972b786e1cc74c112322ecf181f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428568"
---
# <a name="requirements-for-stlclr-container-elements"></a>Requisitos dos elementos de contêiner STL/CLR

Todos os tipos de referência que são inseridos em contêineres STL/CLR devem ter, no mínimo, os seguintes elementos:

- Um construtor de cópia público.

- Um operador de atribuição de público.

- Um destruidor público.

Além disso, como os contêineres associativos [definir](../dotnet/set-stl-clr.md) e [mapa](../dotnet/map-stl-clr.md) deve ter um operador de comparação público definido, que é `operator<` por padrão. Algumas operações em contêineres também podem exigir um construtor padrão público e um operador de equivalência público para ser definido.

Como tipos de referência, identificadores e tipos de valor para fazer referência a tipos que devem ser inseridos em um contêiner associativo devem ter um operador de comparação como `operator<` definido. Os requisitos para um construtor de cópia público, o operador de atribuição público e um destruidor público não existem para tipos de valor ou identificadores para tipos de referência.

## <a name="see-also"></a>Consulte também

[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)