---
title: COM+ 1.0 suporte em projetos ATL
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.ATL.MTS
helpviewer_keywords:
- ATL projects, COM+ 1.0 support
ms.assetid: 51fb08ac-d632-4657-a4e0-d3f989f0b6f8
ms.openlocfilehash: 4bc7683d6121dec748e30c1ea717042b9cf1ecbc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562455"
---
# <a name="com-10-support-in-atl-projects"></a>COM+ 1.0 suporte em projetos ATL

Você pode usar o [ATL Project Wizard](../../atl/reference/creating-an-atl-project.md) para criar um projeto com o suporte básico para componentes COM+ 1.0.

COM+ 1.0 foi projetado para o desenvolvimento de aplicativos distribuídos baseados em componentes. Ele também fornece uma infraestrutura de tempo de execução para implantar e gerenciar esses aplicativos.

Se você selecionar o **suporte COM+ 1.0** caixa de seleção, o assistente modifica o script de compilação na etapa de link. Especificamente, a COM+ 1.0 projeto contém links para as bibliotecas a seguir:

- Comsvcs.lib

- Mtxguid.lib

Se você selecionar o **suporte COM+ 1.0** caixa de seleção, você pode selecionar também **registrador de componentes de suporte**. O registrador de componentes permite que seu objeto COM+ 1.0 obter uma lista de componentes, componentes de registrar ou cancelar o registro de componentes (individualmente ou ao mesmo tempo).

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Programando com código de tempo de execução C e da ATL](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

