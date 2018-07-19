---
title: Agregação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2457d6e94677c43985cadf8ca49a176a82566b6a
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37847863"
---
# <a name="aggregation"></a>Agregação
Há vezes quando o implementador de um objeto gostaria de aproveitar os serviços oferecidos pelo predefinidas, de outro objeto. Além disso, ele gostaria que este segundo objeto a ser exibido como uma parte natural do primeiro. COM atinge ambas essas metas por meio de agregação e confinamento.  
  
 Agregação significa que o objeto de recipiente (externo) cria o objeto de (interno) independente como parte do processo de criação e as interfaces do objeto interno são expostas pelo externo. Um objeto permite que seja agregável, ou não. Se for, ele deve seguir algumas regras de agregação para funcionar corretamente.  
  
 Basicamente, tudo `IUnknown` chamadas de método no objeto independente devem delegar para o objeto recipiente.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução a COM](../atl/introduction-to-com.md)   
 [Reutilizando objetos](http://msdn.microsoft.com/library/windows/desktop/ms678443)

