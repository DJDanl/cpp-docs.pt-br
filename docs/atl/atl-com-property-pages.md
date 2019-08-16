---
title: Página de propriedades ATL COM
ms.date: 11/04/2016
helpviewer_keywords:
- property pages, COM
- ATL COM objects
- COM property pages
- property pages, ATL
- COM objects, ATL
- ATL property pages
ms.assetid: 663c7caa-2e5e-4b5c-b8ea-fd434ceb1654
ms.openlocfilehash: f6f549388e69e9549c64645de758d92822205fd5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491866"
---
# <a name="atl-com-property-pages"></a>Página de propriedades ATL COM

As páginas de propriedades COM fornecem uma interface do usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos COM. As páginas de propriedades são usadas extensivamente pelos controles ActiveX para fornecer interfaces de usuário avançadas que permitem que as propriedades de controle sejam definidas em tempo de design.

As páginas de propriedades são objetos COM que implementam a interface [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) ou [IPropertyPage2](/windows/win32/api/ocidl/nn-ocidl-ipropertypage2) . Essas interfaces fornecem métodos que permitem que a página seja associada a um `site` (objeto com que representa o contêiner da página) e a vários *objetos* (objetos com cujos métodos serão chamados em resposta às alterações feitas pelo usuário do página de propriedades). O contêiner da página de propriedades é responsável por chamar métodos na interface da página de propriedades para dizer à página quando mostrar ou ocultar sua interface do usuário e quando aplicar as alterações feitas pelo usuário aos objetos subjacentes.

Cada página de propriedades pode ser criada completamente independentemente dos objetos cujas propriedades podem ser definidas. Tudo o que uma página de propriedades precisa é entender uma interface específica (ou conjunto de interfaces) e fornecer uma interface do usuário para chamar métodos nessa interface.

Para obter mais informações, consulte [folhas de propriedades e páginas de propriedades](/windows/win32/com/property-sheets-and-property-pages) no SDK do Windows.

## <a name="in-this-section"></a>Nesta seção

[Especificando páginas de propriedades](../atl/specifying-property-pages.md)<br/>
Lista as etapas para especificar páginas de propriedades para o controle e mostra uma classe de exemplo.

[Implementando páginas de propriedades](../atl/implementing-property-pages.md)<br/>
Lista as etapas para implementar páginas de propriedades, incluindo métodos a serem substituídos. Percorre um exemplo completo com base no programa de exemplo ATLPages.

## <a name="related-sections"></a>Seções relacionadas

[Exemplo de páginas ATL](../overview/visual-cpp-samples.md)<br/>
O resumo de exemplo do exemplo ATLPages, que implementa uma página de propriedades `IPropertyPageImpl`usando.

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
