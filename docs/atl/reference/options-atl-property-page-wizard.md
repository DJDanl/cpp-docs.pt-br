---
title: Opções, Assistente de Página de Propriedades da ATL
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.ppg.options
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
ms.openlocfilehash: a46a55cca221293e83a72bf0c2670e2343c744b0
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076202"
---
# <a name="options-atl-property-page-wizard"></a>Opções, Assistente de Página de Propriedades da ATL

::: moniker range="vs-2019"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Use esta página do assistente para definir o modelo de threading e o nível de agregação da página de propriedades que você está criando.

- **Modelo de threading**

   Especifica o modelo de threading usado pela página de propriedades.

   Confira mais informações em [Como especificar o modelo de threading para um projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md).

   |Opção|DESCRIÇÃO|
   |------------|-----------------|
   |**Single**|A página de propriedades é executada apenas no thread COM primário.|
   |**Apartment**|A página de propriedades pode ser criada em qualquer apartament de thread único. O padrão.|

- **Agregação**

   Adiciona suporte de agregação para a página de propriedades que você está criando. Confira mais informações em [Agregação](../../atl/aggregation.md).

   |Opção|DESCRIÇÃO|
   |------------|-----------------|
   |**Sim**|Cria uma página de propriedades que pode ser agregada.|
   |**Não**|Cria uma página de propriedades que não pode ser agregada.|
   |**Apenas**|Cria uma página de propriedades que só pode ser instanciada por meio de uma agregação.|

::: moniker-end

## <a name="see-also"></a>Confira também

[Assistente de página de propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, Assistente de Página de Propriedades da ATL](../../atl/reference/strings-atl-property-page-wizard.md)
