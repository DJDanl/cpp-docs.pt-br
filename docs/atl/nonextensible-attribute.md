---
title: Atributo nonextensible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- nonextensible
dev_langs:
- C++
helpviewer_keywords:
- nonextensible attribute
- dual interfaces, nonextensible attribute
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1112f533e2e38dd90b1693e8bd31e5896ebca5e7
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848425"
---
# <a name="nonextensible-attribute"></a>Atributo nonextensible
Se uma interface dupla não será estendida em tempo de execução (ou seja, você não fornecer métodos ou propriedades por meio `IDispatch::Invoke` que não estão disponíveis por meio de vtable), você deve aplicar a **nonextensible** à sua interface de atributo definição. Esse atributo fornece informações para idiomas do cliente (por exemplo, o Visual Basic) que pode ser usado para habilitar a verificação de código completo no tempo de compilação. Se esse atributo não for fornecido, bugs permanecerão ocultos no código do cliente até o tempo de execução.  
  
 Para obter mais informações sobre o **nonextensible** atributo e um exemplo, consulte [nonextensible](../windows/nonextensible.md).  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

