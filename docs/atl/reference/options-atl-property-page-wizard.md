---
title: Opções, Assistente de Página de Propriedades da ATL
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.ppg.options
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
ms.openlocfilehash: 74cf72feedd8dc8e1186d54a8abe840195964620
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923665"
---
# <a name="options-atl-property-page-wizard"></a>Opções, Assistente de Página de Propriedades da ATL

::: moniker range="msvc-160"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

Use esta página do assistente para definir o modelo de threading e o nível de agregação da página de propriedades que você está criando.

- **Modelo de threading**

   Especifica o modelo de threading usado pela página de propriedades.

   Confira mais informações em [Como especificar o modelo de threading para um projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Single**|A página de propriedades é executada apenas no thread COM primário.|
   |**Sta**|A página de propriedades pode ser criada em qualquer apartament de thread único. O padrão.|

- **Aggregation**

   Adiciona suporte de agregação para a página de propriedades que você está criando. Confira mais informações em [Agregação](../../atl/aggregation.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Sim**|Cria uma página de propriedades que pode ser agregada.|
   |**Não**|Cria uma página de propriedades que não pode ser agregada.|
   |**Somente**|Cria uma página de propriedades que só pode ser instanciada por meio de uma agregação.|

::: moniker-end

## <a name="see-also"></a>Veja também

[Assistente de página de propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, Assistente de Página de Propriedades da ATL](../../atl/reference/strings-atl-property-page-wizard.md)
