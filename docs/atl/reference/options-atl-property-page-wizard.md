---
title: Opções, o Assistente de página de propriedades ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.ppg.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8e7edfb2cb4040238985c6cd78e8f1e5756f4d6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358763"
---
# <a name="options-atl-property-page-wizard"></a>Opções de Assistente de página de propriedades ATL
Use esta página do Assistente para definir o nível de agregação e o modelo de threading da página de propriedade que você está criando.  
  
 **Modelo de Threading**  
 Especifica o modelo de threading usado pela página de propriedade.  
  
 Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|`Single`|A página de propriedade é executada somente no thread COM primário.|  
|**Apartment**|A página de propriedade pode ser criada em qualquer single thread apartment. O padrão.|  
  
 **Agregação**  
 Adiciona o suporte de agregação para a página de propriedade que você está criando. Consulte [agregação](../../atl/aggregation.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Sim**|Crie uma página de propriedades que pode ser agregada.|  
|**No**|Crie uma página de propriedades que não pode ser agregada.|  
|**Only**|Crie uma página de propriedade que pode ser instanciada somente por meio de agregação.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md)   
 [Cadeias de caracteres, o Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)

