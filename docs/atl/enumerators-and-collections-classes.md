---
title: Os enumeradores e Classes de coleções (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.enum
dev_langs:
- C++
helpviewer_keywords:
- enumerators, ATL classes
ms.assetid: fcd093b2-98bf-444d-94ab-9a55520a5051
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c84becc5b7117c9095a055e6a815e52396987800
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758385"
---
# <a name="enumerators-and-collections-classes"></a>Classes de coleções e enumeradores

As classes a seguir fornecem suporte para coleções de COM e enumerações:

- [CComEnum](../atl/reference/ccomenum-class.md) define uma COM o objeto de enumerador com base em uma matriz.

- [CComEnumImpl](../atl/reference/ccomenumimpl-class.md) fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz.

- [CComEnumOnSTL](../atl/reference/ccomenumonstl-class.md) define uma COM o objeto de enumerador com base em uma coleção de biblioteca padrão C++.

- [IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md) fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em um contêiner de biblioteca padrão C++ compatível com.

- [ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md) fornece a implementação para o `Count`, `Item`, e `_NewEnum` propriedades de uma interface de coleção.

## <a name="related-articles"></a>Artigos relacionados

[Coleções e enumeradores da ATL](../atl/atl-collections-and-enumerators.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)

