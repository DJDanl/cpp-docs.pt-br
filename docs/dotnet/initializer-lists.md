---
title: Listas de inicializadores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- initializer lists
ms.assetid: b3e53442-9809-4105-9226-ae845bd20cae
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1af020bec295f0f949b7ebb6abe88102f3942b1f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="initializer-lists"></a>Listas de inicializadores
Agora são chamadas de listas de inicializadores em construtores antes do construtor de classe base.  
  
## <a name="remarks"></a>Comentários  
 Antes do Visual C++ 2005, o construtor de classe base foi chamado antes da lista de inicializador ao compilar com extensões gerenciadas para C++. Agora, ao compilar com **/clr**, a lista de inicializadores é chamada primeiro.  
  
## <a name="see-also"></a>Consulte também  
 [Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)