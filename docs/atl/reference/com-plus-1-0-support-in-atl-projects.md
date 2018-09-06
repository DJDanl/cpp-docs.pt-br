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
ms.openlocfilehash: 06a9e6cd4a374f0941b360a3f8f24f61e4b46a6a
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763292"
---
# <a name="com-10-support-in-atl-projects"></a>COM+ 1.0 suporte em projetos ATL

Você pode usar o [ATL Project Wizard](../../atl/reference/creating-an-atl-project.md) para criar um projeto com o suporte básico para componentes COM+ 1.0.

COM+ 1.0 foi projetado para o desenvolvimento de aplicativos distribuídos baseados em componentes. Ele também fornece uma infraestrutura de tempo de execução para implantar e gerenciar esses aplicativos.

Se você selecionar o **suporte COM+ 1.0** caixa de seleção, o assistente modifica o script de compilação na etapa de link. Especificamente, a COM+ 1.0 projeto contém links para as bibliotecas a seguir:

- Comsvcs.lib

- Mtxguid.lib

Se você selecionar o **suporte COM+ 1.0** caixa de seleção, você pode selecionar também **registrador de componentes de suporte**. O registrador de componentes permite que seu objeto COM+ 1.0 obter uma lista de componentes, componentes de registrar ou cancelar o registro de componentes (individualmente ou ao mesmo tempo).

## <a name="see-also"></a>Consulte também

[Conceitos básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)   
[Programando com código de tempo de execução de C e ATL](../../atl/programming-with-atl-and-c-run-time-code.md)   
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

