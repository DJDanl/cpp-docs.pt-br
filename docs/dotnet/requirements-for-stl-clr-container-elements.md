---
title: Requisitos para elementos de contêiner STL/CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- C++ Standard Library, template class containers
- STL/CLR, containers
- containers, STL/CLR
- containers, C++ Standard Library
ms.assetid: 59ab240c-15bf-4701-a9f9-e7c56e5ab53f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fcba36fdf280cef31efb9a84288475fcbb82b291
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400413"
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