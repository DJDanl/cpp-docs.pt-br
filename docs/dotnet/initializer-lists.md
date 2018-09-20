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
ms.openlocfilehash: 981f2737d370dc25ca4e7dc6c20947b3867a0c65
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46394602"
---
# <a name="initializer-lists"></a>Listas de inicializadores

Listas de inicializadores em construtores agora são chamadas antes do construtor de classe base.

## <a name="remarks"></a>Comentários

Antes do Visual C++ 2005, o construtor de classe base foi chamado antes da lista do inicializador ao compilar com extensões gerenciadas para C++. Agora, ao compilar com **/clr**, a lista de inicializadores é chamada pela primeira vez.

## <a name="see-also"></a>Consulte também

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)