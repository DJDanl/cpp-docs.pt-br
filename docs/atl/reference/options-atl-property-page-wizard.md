---
title: "Opções, o Assistente de página de propriedades ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.ppg.options
dev_langs:
- C++
helpviewer_keywords:
- ATL Property Page Wizard, options
ms.assetid: a7107779-b2ea-4f99-b84b-7f3e0c504bc8
caps.latest.revision: 13
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
ms.openlocfilehash: bea768cf456fadfbe05e450c5e6652d1f7f378f5
ms.lasthandoff: 02/25/2017

---
# <a name="options-atl-property-page-wizard"></a>Opções, o Assistente de página de propriedades ATL
Use esta página do Assistente para definir o nível de agregação e o modelo de threading da página de propriedade que você está criando.  
  
 **Modelo de Threading**  
 Especifica o modelo de threading usado pela página de propriedade.  
  
 Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|`Single`|A página de propriedades é executado somente no thread primário COM.|  
|**Apartment**|A página de propriedade pode ser criada em qualquer apartment do thread único. O padrão.|  
  
 **Agregação**  
 Adiciona o suporte de agregação para a página de propriedade que você está criando. Consulte [agregação](../../atl/aggregation.md) para obter mais informações.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Sim**|Crie uma página de propriedades que pode ser agregada.|  
|**No**|Crie uma página de propriedades que não pode ser agregada.|  
|**Somente**|Crie uma página de propriedades só pode ser instanciada por meio da agregação.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md)   
 [Cadeias de caracteres, Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)


