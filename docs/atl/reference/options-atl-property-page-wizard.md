---
title: Opções, Assistente de página de propriedades da ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.class.atl.ppg.options
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
ms.openlocfilehash: e891bd9e37bbf2fbedcdd71649305cdc366065fd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641997"
---
# <a name="options-atl-property-page-wizard"></a>Opções, Assistente de página de propriedades da ATL

Use esta página do Assistente para definir o nível de agregação e o modelo de threading da página de propriedades que você está criando.

- **Modelo de Threading**

   Especifica o modelo de threading usado pela página de propriedade.

   Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.

   |Opção|Descrição|
   |------------|-----------------|
   |**Simples**|A página de propriedades é executado somente no thread COM primário.|
   |**Apartment**|A página de propriedades pode ser criada em qualquer apartment de thread único. O padrão.|

- **Agregação**

   Adiciona o suporte de agregação para a página de propriedades que você está criando. Ver [agregação](../../atl/aggregation.md) para obter mais informações.

   |Opção|Descrição|
   |------------|-----------------|
   |**Sim**|Crie uma página de propriedades que pode ser agregada.|
   |**No**|Crie uma página de propriedades que não pode ser agregada.|
   |**Only**|Crie uma página de propriedades só pode ser instanciada por meio de agregação.|

## <a name="see-also"></a>Consulte também

[Assistente de página de propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)<br/>
[Cadeias de caracteres, o Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)

