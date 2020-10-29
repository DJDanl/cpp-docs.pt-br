---
title: Cadeia de caracteres, Assistente de Página de Propriedades da ATL
ms.date: 05/09/2019
f1_keywords:
- vc.codewiz.class.atl.ppg.strings
helpviewer_keywords:
- ATL Property Page Wizard, strings
ms.assetid: 00547db6-911f-49eb-92e1-2ba67079d4df
ms.openlocfilehash: 61378e0aa2cee94420849195a94203be078418ff
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921107"
---
# <a name="strings-atl-property-page-wizard"></a>Cadeia de caracteres, Assistente de Página de Propriedades da ATL

::: moniker range="msvc-160"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

Fornece o texto associado à página de propriedades.

- **Título**

   Define o texto que aparece na guia da página de propriedades.

- **Doc string**

   Define uma cadeia de caracteres de texto que descreve a página. Essa cadeia de caracteres pode ser exibida na caixa de diálogo da folha de propriedades. O quadro de propriedade poderia usar a descrição em uma dica de ferramenta ou linha de status. O quadro de propriedades padrão no momento não usa essa cadeia de caracteres.

- **Arquivo de ajuda**

   Define o nome do arquivo de ajuda que descreve como usar a página de propriedades. Esse nome não deve incluir um caminho. Quando o usuário pressiona **Ajuda** , o quadro abre o arquivo de ajuda no diretório indicado no valor da chave HelpDir nas entradas de registro de página de propriedades em sua CLSID.

::: moniker-end

## <a name="see-also"></a>Veja também

[Assistente de página de propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)<br/>
[Opções, Assistente de Página de Propriedades da ATL](../../atl/reference/options-atl-property-page-wizard.md)
