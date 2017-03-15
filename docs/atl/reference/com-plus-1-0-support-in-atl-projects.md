---
title: COM+ 1.0 suporte em projetos do ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.MTS
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, COM+ 1.0 support
ms.assetid: 51fb08ac-d632-4657-a4e0-d3f989f0b6f8
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7521c1dae6fd29b8b951d23fe33c91179d4b46ed
ms.lasthandoff: 02/25/2017

---
# <a name="com-10-support-in-atl-projects"></a>COM+ 1.0 suporte em projetos ATL
Você pode usar o [ATL Project Wizard](../../atl/reference/creating-an-atl-project.md) para criar um projeto com suporte básico para componentes COM+ 1.0.  
  
 COM+ 1.0 foi projetado para o desenvolvimento de aplicativos distribuídos baseados em componentes. Ele também fornece uma infraestrutura de tempo de execução para implantar e gerenciar esses aplicativos.  
  
 Se você selecionar o **suporte COM+ 1.0** caixa de seleção, o assistente modifica o script de compilação na etapa de link. Especificamente, os COM+ 1.0 projeto links para as seguintes bibliotecas:  
  
-   Comsvcs.lib  
  
-   Mtxguid.lib  
  
 Se você selecionar o **suporte COM+ 1.0** caixa de seleção, você também pode selecionar **registrador de componentes de suporte**. O registrador de componentes permite que seu objeto de COM+ 1.0 obter uma lista de componentes, registrar componentes ou cancelar o registro de componentes (individualmente ou todos de uma vez).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


