---
title: Listas de inicializadores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- initializer lists
ms.assetid: b3e53442-9809-4105-9226-ae845bd20cae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 6634b749480e5108548de0c8b53f8b09cc5a42c2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="initializer-lists"></a>Listas de inicializadores
Agora são chamadas de listas de inicializadores em construtores antes do construtor de classe base.  
  
## <a name="remarks"></a>Comentários  
 Antes do Visual C++ 2005, o construtor de classe base foi chamado antes da lista de inicializador ao compilar com extensões gerenciadas para C++. Agora, ao compilar com **/clr**, a lista de inicializadores é chamada primeiro.  
  
## <a name="see-also"></a>Consulte também  
 [Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)