---
title: Serviços ATL
ms.date: 11/04/2016
helpviewer_keywords:
- CServiceModule class
- COM objects, ATL
- services, ATL
- ATL services
ms.assetid: 8c09d1a8-7548-4d2c-947c-9d795a81659b
ms.openlocfilehash: 052169154a62cbd07a82f08087fc2c2db8ae46c5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57819049"
---
# <a name="atl-services"></a>Serviços ATL

Para criar o objeto COM ATL para que ele seja executado em um serviço, basta selecione o serviço (EXE) na lista de opções de servidor no Assistente de projeto de ATL. O assistente, em seguida, criará uma classe derivada de `CAtlServiceModuleT` para implementar o serviço.

Quando o objeto COM ATL é compilado como um serviço, ele só será registrado como um servidor local e não aparecerão na lista de serviços no painel de controle. Isso ocorre porque é mais fácil depurar o serviço como um servidor local que, como um serviço. Para instalá-lo como um serviço, execute o seguinte no prompt de comando:

`YourEXE` `.exe /Service`

Para desinstalar, execute o seguinte:

`YourEXE` `.exe /UnregServer`

Os quatro primeiros tópicos nesta seção abordam as ações que ocorrem durante a execução de `CAtlServiceModuleT` funções de membro. Esses tópicos são exibidos na mesma sequência conforme as funções normalmente são chamadas. Para melhorar sua compreensão desses tópicos, é uma boa ideia usar o código-fonte gerado pelo Assistente de projeto de ATL como uma referência. Esses quatro primeiros tópicos são:

- [A função catlservicemodulet:: Start](../atl/reference/catlservicemodulet-class.md#start)

- [A função catlservicemodulet:: Servicemain](../atl/reference/catlservicemodulet-class.md#servicemain)

- [A função catlservicemodulet:: Run](../atl/reference/catlservicemodulet-class.md#run)

- [A função catlservicemodulet:: Handler](../atl/reference/catlservicemodulet-class.md#handler)

Os três últimos tópicos discutem os conceitos relacionados ao desenvolvimento de um serviço:

- [As entradas do registro](../atl/registry-entries.md) para serviços da ATL

- [DCOMCNFG](../atl/dcomcnfg.md)

- [Dicas de depuração](../atl/debugging-tips.md) para serviços da ATL

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
