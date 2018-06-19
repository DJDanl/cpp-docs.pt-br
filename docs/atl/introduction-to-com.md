---
title: Introdução ao COM | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- COM
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 938d0c45cae5ec9a2988f77f539af1a3d5513b83
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356169"
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

