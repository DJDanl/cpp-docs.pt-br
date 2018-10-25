---
title: Criação de objeto dinâmico | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c1b8cca1453ef4a044a39853e615c5d0e6c3268f
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50051883"
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico

Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe de tempo de execução, conforme discutido no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md).

#### <a name="to-dynamically-create-an-object-given-its-run-time-class"></a>Para criar dinamicamente um objeto, considerando sua classe de tempo de execução

1. Use o seguinte código para criar dinamicamente um objeto usando o `CreateObject` função do `CRuntimeClass`. Observe que, em caso de falha, `CreateObject` retorna **nulo** em vez de gerar uma exceção:

   [!code-cpp[NVC_MFCCObjectSample#6](../mfc/codesnippet/cpp/dynamic-object-creation_1.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CObject](../mfc/using-cobject.md)

