---
title: COM+ 1.0 suporte em projetos ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.MTS
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, COM+ 1.0 support
ms.assetid: 51fb08ac-d632-4657-a4e0-d3f989f0b6f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e3440d3ed2e3244b35588d5c07fd181f1ad2f082
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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

