---
title: Atributo nonextensible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: nonextensible
dev_langs: C++
helpviewer_keywords:
- nonextensible attribute
- dual interfaces, nonextensible attribute
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: af16748bb3b2048ce854ccc7a03b2400039184a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nonextensible-attribute"></a>Atributo nonextensible
Se uma interface dupla não será estendida em tempo de execução (ou seja, você não fornecer métodos ou propriedades por meio de **IDispatch:: Invoke** que não estão disponíveis por meio de vtable), você deve aplicar o **nonextensible** o atributo à sua definição de interface. Esse atributo fornece informações para idiomas do cliente (como o Visual Basic) que pode ser usado para habilitar a verificação de código completo em tempo de compilação. Se esse atributo não for fornecido, bugs podem permanecer ocultos no código do cliente até o tempo de execução.  
  
 Para obter mais informações sobre o **nonextensible** atributo e um exemplo, consulte [nonextensible](../windows/nonextensible.md).  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

