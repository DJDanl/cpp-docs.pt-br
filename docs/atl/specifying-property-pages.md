---
title: Especificação de páginas de propriedade (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- ISpecifyPropertyPages
dev_langs:
- C++
helpviewer_keywords:
- ISpecifyPropertyPages method
- property pages, specifying
ms.assetid: ee8678cf-c708-49ab-b0ad-fc2db31f1ac3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e8d4cbeaa8ea9a57f9287f2d2fe78c61884ba4a3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="specifying-property-pages"></a>Especificar as páginas de propriedade
Quando você cria um controle ActiveX, geralmente você desejará associá-la a páginas de propriedades que podem ser usadas para definir as propriedades de seu controle. Controla o uso de contêineres de **ISpecifyPropertyPages** interface para descobrir quais páginas de propriedade podem ser usadas para definir propriedades do controle. Você precisará implementar essa interface do controle.  
  
 Para implementar **ISpecifyPropertyPages** usando a ATL, execute as seguintes etapas:  
  
1.  Derive a classe de [ISpecifyPropertyPagesImpl](../atl/reference/ispecifypropertypagesimpl-class.md).  
  
2.  Adicione uma entrada para **ISpecifyPropertyPages** para mapa de COM da classe.  
  
3.  Adicionar um [PROP_PAGE](reference/property-map-macros.md#prop_page) entrada para o mapa de propriedade para cada página associado a seu controle.  
  
> [!NOTE]
>  Ao gerar um controle padrão usando o [Assistente de controle ATL](../atl/reference/atl-control-wizard.md), você só precisa adicionar o `PROP_PAGE` entradas para o mapa de propriedade. O assistente gera o código necessário para as outras etapas.  
  
 Contêineres bom exibirá as páginas de propriedade especificada na mesma ordem que a `PROP_PAGE` entradas no mapa de propriedade. Em geral, você deve colocar as entradas de página de propriedade padrão após as entradas para suas páginas personalizadas no mapa de propriedade, para que os usuários veem as páginas específicas para seu controle primeiro.  
  
## <a name="example"></a>Exemplo  
 A seguinte classe de um calendário de controle usa o **ISpecifyPropertyPages** interface dizer contêineres que suas propriedades podem ser definidas usando uma página personalizado de data e a cor de estoque.  
  
 [!code-cpp[NVC_ATL_Windowing#72](../atl/codesnippet/cpp/specifying-property-pages_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [Exemplo de ATLPages](../visual-cpp-samples.md)

