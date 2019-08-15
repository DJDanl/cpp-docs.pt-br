---
title: 'Como: Crie aplicativos isolados para consumir componentes COM'
ms.date: 11/04/2016
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 04587547-1174-44ab-bd99-1292358fba20
ms.openlocfilehash: 8ae3c51502267f202cbb85ea7be2a81dc3310410
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493242"
---
# <a name="how-to-build-isolated-applications-to-consume-com-components"></a>Como: Crie aplicativos isolados para consumir componentes COM

Aplicativos isolados são aplicativos que têm manifestos incorporados ao programa. Você pode criar aplicativos isolados para consumir componentes COM.

### <a name="to-add-com-references-to-manifests-of-isolated-applications"></a>Para adicionar referências COM a manifestos de aplicativos isolados

1. Abra as páginas de propriedades do projeto para o aplicativo isolado.

1. Expanda o nó **Propriedades de configuração** e expanda o nó **ferramenta de manifesto** .

1. Selecione a página de propriedade **com isolada** e defina a propriedade **nome do arquivo de componente** como o nome do componente com que você deseja que o aplicativo isolado consuma.

1. Clique em **OK**.

### <a name="to-build-manifests-into-isolated-applications"></a>Para criar manifestos em aplicativos isolados

1. Abra as páginas de propriedades do projeto para o aplicativo isolado.

1. Expanda o nó **Propriedades de configuração** e expanda o nó **ferramenta de manifesto** .

1. Selecione a página de propriedades **entrada e saída** e defina a propriedade **Inserir manifesto** igual a **Sim**.

1. Clique em **OK**.

1. Compile a solução.

## <a name="see-also"></a>Consulte também

[Aplicativos isolados](/windows/win32/SbsCs/isolated-applications)<br/>
[Sobre assemblies lado a lado](/windows/win32/SbsCs/about-side-by-side-assemblies-)
