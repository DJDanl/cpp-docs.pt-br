---
title: Páginas de propriedade do ATL COM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property pages, COM
- ATL COM objects
- COM property pages
- property pages, ATL
- COM objects, ATL
- ATL property pages
ms.assetid: 663c7caa-2e5e-4b5c-b8ea-fd434ceb1654
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0da9a0299679ec140888e9536329f0957a786279
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43759997"
---
# <a name="atl-com-property-pages"></a>Página de propriedades ATL COM

Páginas de propriedades COM fornecem uma interface do usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos de COM. Páginas de propriedades são usadas amplamente por controles ActiveX para fornecer interfaces do usuário avançadas que permitem que as propriedades de controle a ser definido em tempo de design.

Páginas de propriedades são COM objetos que implementam o [IPropertyPage](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage) ou [IPropertyPage2](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage2) interface. Essas interfaces fornecem métodos que permitem que a página a ser associada com um `site` (um objeto COM que representa o contêiner da página) e um número de *objetos* (objetos cujos métodos serão chamados em resposta a alterações feitas pelo usuário da página de propriedades). O contêiner de página de propriedade é responsável por chamar métodos na interface de página de propriedade para informar a página quando mostrar ou ocultar sua interface do usuário e quando aplicar as alterações feitas pelo usuário para os objetos subjacentes.

Cada página de propriedades pode ser criada independentemente dos objetos cujas propriedades podem ser definidas completamente. Tudo o que uma página de propriedades é precisa entender uma interface específica (ou conjunto de interfaces) e fornecer uma interface do usuário para chamar métodos nessa interface.

Para obter mais informações, consulte [folhas de propriedades e páginas de propriedade](/windows/desktop/com/property-sheets-and-property-pages) no SDK do Windows.

## <a name="in-this-section"></a>Nesta seção

[Especificando páginas de propriedades](../atl/specifying-property-pages.md)  
Lista as etapas para especificar as páginas de propriedades para o controle e mostra um exemplo de classe.

[Implementando páginas de propriedades](../atl/implementing-property-pages.md)  
Lista as etapas para a implementação de páginas de propriedades, incluindo métodos para substituir. Orienta você por meio de um exemplo completo, com base em que o programa de exemplo ATLPages.

## <a name="related-sections"></a>Seções relacionadas

[Exemplo de ATLPages](../visual-cpp-samples.md)  
O resumo de exemplo para o exemplo de ATLPages, que implementa uma página de propriedade usando `IPropertyPageImpl`.

[ATL](../atl/active-template-library-atl-concepts.md)  
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)

