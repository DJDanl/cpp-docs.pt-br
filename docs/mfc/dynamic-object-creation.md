---
title: Criação de objeto dinâmico
ms.date: 03/27/2020
helpviewer_keywords:
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
ms.openlocfilehash: 00e627e6d73e510ca694966291e2ef518fef18b5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619544"
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico

Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe de tempo de execução, conforme discutido no artigo [Acessando informações de classe em tempo de execução](accessing-run-time-class-information.md).

#### <a name="dynamically-create-an-object-given-its-run-time-class"></a>Criar dinamicamente um objeto de acordo com sua classe de tempo de execução

1. Use o código a seguir para criar dinamicamente um objeto usando a `CreateObject` função do `CRuntimeClass` . Em caso de falha, `CreateObject` retorna **NULL** em vez de gerar uma exceção:

   [!code-cpp[NVC_MFCCObjectSample#6](codesnippet/cpp/dynamic-object-creation_1.cpp)]

## <a name="see-also"></a>Consulte também

[Destruindo objetos](tn017-destroying-window-objects.md) 
 de janela [Usando CObject](using-cobject.md)
