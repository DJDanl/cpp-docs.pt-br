---
title: Opções, Assistente de Página de Propriedades da ATL
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.ppg.options
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
ms.openlocfilehash: c883b3e79bd857bb457da0a1bd540a08ddddf017
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65524549"
---
# <a name="options-atl-property-page-wizard"></a>Opções, Assistente de Página de Propriedades da ATL


::: moniker range="vs-2019"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="vs-2017"

Use esta página do assistente para definir o modelo de threading e o nível de agregação da página de propriedades que você está criando.

- **Modelo de threading**

   Especifica o modelo de threading usado pela página de propriedades.

   Confira mais informações em [Como especificar o modelo de threading para um projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|A página de propriedades é executada apenas no thread COM primário.|
   |**Apartment**|A página de propriedades pode ser criada em qualquer apartament de thread único. O padrão.|

- **Agregação**

   Adiciona suporte de agregação para a página de propriedades que você está criando. Confira mais informações em [Agregação](../../atl/aggregation.md).

   |Opção|Descrição|
   |------------|-----------------|
   |**Sim**|Cria uma página de propriedades que pode ser agregada.|
   |**No**|Cria uma página de propriedades que não pode ser agregada.|
   |**Apenas**|Cria uma página de propriedades que só pode ser instanciada por meio de uma agregação.|

::: moniker-end

## <a name="see-also"></a>Consulte também

[Assistente de página de propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, Assistente de Página de Propriedades da ATL](../../atl/reference/strings-atl-property-page-wizard.md)
