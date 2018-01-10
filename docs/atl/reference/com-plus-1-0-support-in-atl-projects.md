---
title: COM+ 1.0 suporte em projetos ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: vc.appwiz.ATL.MTS
dev_langs: C++
helpviewer_keywords: ATL projects, COM+ 1.0 support
ms.assetid: 51fb08ac-d632-4657-a4e0-d3f989f0b6f8
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a3b55cb078dc5db1f0bf727a10f2a77ebfddd260
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="com-10-support-in-atl-projects"></a>COM+ 1.0 suporte em projetos ATL
Você pode usar o [Assistente de projeto de ATL](../../atl/reference/creating-an-atl-project.md) para criar um projeto com o suporte básico para componentes COM+ 1.0.  
  
 COM+ 1.0 foi projetado para o desenvolvimento de aplicativos distribuídos com base em componente. Ele também fornece uma infraestrutura de tempo de execução para implantar e gerenciar esses aplicativos.  
  
 Se você selecionar o **suporte COM+ 1.0** caixa de seleção, o assistente modifica o script de compilação na etapa de link. Especificamente, os COM+ 1.0 projeto links para as bibliotecas a seguir:  
  
-   Comsvcs.lib  
  
-   Mtxguid.lib  
  
 Se você selecionar o **suporte COM+ 1.0** caixa de seleção, você também pode selecionar **registrador de componente de suporte**. O registrador de componente permite que seu objeto de COM+ 1.0 obter uma lista de componentes, registrar componentes ou cancelar o registro de componentes (individualmente ou todos de uma vez).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

