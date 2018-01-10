---
title: "Requisitos dos elementos de contêiner STL/CLR | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords:
- C++ Standard Library, template class containers
- STL/CLR, containers
- containers, STL/CLR
- containers, C++ Standard Library
ms.assetid: 59ab240c-15bf-4701-a9f9-e7c56e5ab53f
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3317e3c9349963fc24b37b421def05c475732fd8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="requirements-for-stlclr-container-elements"></a>Requisitos dos elementos de contêiner STL/CLR
Todos os tipos de referência que são inseridos em contêineres STL/CLR devem ter, no mínimo, os seguintes elementos:  
  
-   Um construtor público.  
  
-   Um operador de atribuição pública.  
  
-   Um destruidor público.  
  
 Além disso, contêineres associativos como [definir](../dotnet/set-stl-clr.md) e [mapa](../dotnet/map-stl-clr.md) deve ter um operador de comparação público definido, que é `operator<` por padrão. Algumas operações em contêineres também podem exigir um construtor padrão público e um operador de equivalência pública a ser definido.  
  
 Como tipos de referência, identificadores e tipos de valor para fazer referência a tipos que devem ser inseridos em um contêiner de associação devem ter um operador de comparação como `operator<` definido. Os requisitos para um construtor de cópia público, o operador de atribuição público e um destruidor público não existem tipos de valor ou identificadores de tipos de referência.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)