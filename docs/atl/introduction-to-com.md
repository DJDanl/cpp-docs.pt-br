---
title: "Introdução ao COM | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs:
- C++
helpviewer_keywords:
- COM
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2a8953949e722265afabc22410174b84c017276c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="introduction-to-com"></a>Introdução ao COM
COM é fundamentais "modelo de objeto" no qual OLE e controles ActiveX são criados. COM permite que um objeto expor sua funcionalidade a outros componentes e aplicativos do host. Ele define como o objeto expõe em si e como essa exposição funciona em processos e em redes. COM também define o ciclo de vida do objeto.  
  
 Fundamentais para COM são esses conceitos:  
  
-   [Interfaces](../atl/interfaces-atl.md) — o mecanismo pelo qual um objeto expõe sua funcionalidade.  
  
-   [IUnknown](../atl/iunknown.md) — a interface básica em que todos os outros são baseados. Ele implementa a contagem de referência e a interface de consulta mecanismos em execução usando COM.  
  
-   [Contagem de referência](../atl/reference-counting.md) — a técnica pelo qual um objeto (ou, estritamente, uma interface) decide quando ele não está mais sendo usado e, portanto, é livre para remover a mesmo.  
  
-   [QueryInterface](../atl/queryinterface.md) — o método usado para consultar um objeto para uma determinada interface.  
  
-   [Marshaling](../atl/marshaling.md) — o mecanismo que permite que objetos sejam usados por thread, processo e limites de rede, permitindo a independência de localização.  
  
-   [Agregação](../atl/aggregation.md) — uma maneira na qual um objeto pode fazer uso de outro.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM e ATL](../atl/introduction-to-com-and-atl.md)   
 [O modelo de objeto do componente](http://msdn.microsoft.com/library/windows/desktop/ms694363)

