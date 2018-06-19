---
title: Páginas de propriedades do ATL COM | Microsoft Docs
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
ms.openlocfilehash: d5d7904b9f31a1be858dadaa8a087c720c277465
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357526"
---
# <a name="atl-com-property-pages"></a>Página de propriedades ATL COM
Páginas de propriedades COM fornecem uma interface de usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos. Páginas de propriedade forem usadas extensivamente por controles ActiveX para fornecer interfaces do usuário avançadas que permitem que as propriedades de controle a ser definido em tempo de design.  
  
 Páginas de propriedades são COM os objetos que implementam o [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) ou [IPropertyPage2](http://msdn.microsoft.com/library/windows/desktop/ms683996) interface. Essas interfaces fornecem métodos que permitem que a página a ser associado com um `site` (um objeto COM que representa o contêiner da página) e um número de *objetos* (objetos cujos métodos serão chamados em resposta a alterações feitas pelo usuário na página de propriedade). O contêiner da página de propriedade é responsável por chamar os métodos na interface de página de propriedade para indicar a página quando mostrar ou ocultar a interface do usuário e quando aplicar as alterações feitas pelo usuário para os objetos subjacentes.  
  
 Cada página de propriedades pode ser construída completamente independentemente dos objetos cujas propriedades podem ser definidas. Tudo o que uma página de propriedades é precisa entender uma interface específica (ou conjunto de interfaces) e para fornecer uma interface de usuário para chamar métodos nessa interface.  
  
 Para obter mais informações, consulte [folhas de propriedades e páginas de propriedade](http://msdn.microsoft.com/library/windows/desktop/ms686577) no [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## <a name="in-this-section"></a>Nesta seção  
 [Especificando páginas de propriedades](../atl/specifying-property-pages.md)  
 Lista as etapas para especificar as páginas de propriedade para o controle e mostra um exemplo de classe.  
  
 [Implementando páginas de propriedades](../atl/implementing-property-pages.md)  
 Lista as etapas para implementar as páginas de propriedades, incluindo métodos para substituir. Orienta você por meio de um exemplo completo baseado no programa de exemplo ATLPages.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Exemplo de ATLPages](../visual-cpp-samples.md)  
 O resumo de exemplo para o exemplo de ATLPages, que implementa uma página de propriedade usando `IPropertyPageImpl`.  
  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

