---
title: Classe de IAtlAutoThreadModule | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IAtlAutoThreadModule
- atlbase/ATL::IAtlAutoThreadModule
dev_langs:
- C++
helpviewer_keywords:
- IAtlAutoThreadModule class
ms.assetid: fcb58cf9-a427-4be9-89eb-04e1ab5cc3a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2c5d92eb693a73aff20ff8869be4412574a15cbe
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764355"
---
# <a name="iatlautothreadmodule-class"></a>Classe de IAtlAutoThreadModule

Essa classe representa uma interface para um `CreateInstance` método.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
__interface IAtlAutoThreadModule
```

## <a name="remarks"></a>Comentários

A classe [CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md) deriva `IAtlAutoThreadModule`, usá-lo para fornecer o código para criar um objeto e recuperar um ponteiro de interface.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
