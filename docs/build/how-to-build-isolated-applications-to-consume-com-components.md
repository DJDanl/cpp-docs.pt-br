---
title: 'Como: compilar aplicativos isolados para consumir componentes COM | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 04587547-1174-44ab-bd99-1292358fba20
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6d2acabb6a5e9c35029b346097a66eaf1311826c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45704022"
---
# <a name="how-to-build-isolated-applications-to-consume-com-components"></a>Como compilar aplicativos isolados para consumir componentes COM

Aplicativos isolados são aplicativos que têm manifestos incorporados ao programa. Você pode criar aplicativos isolados para consumir componentes COM.

### <a name="to-add-com-references-to-manifests-of-isolated-applications"></a>Para adicionar referências de COM para manifestos de aplicativos isolados

1. Abra as páginas de propriedades do projeto para o aplicativo isolado.

1. Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.

1. Selecione o **COM isolado** página de propriedades e defina as **nome do arquivo de componente** propriedade para o nome do componente COM que você deseja que o aplicativo isolado para consumir.

1. Clique em **OK**.

### <a name="to-build-manifests-into-isolated-applications"></a>Para compilar manifestos em aplicativos isolados

1. Abra as páginas de propriedades do projeto para o aplicativo isolado.

1. Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.

1. Selecione o **de entrada e saída** página de propriedades e defina as **Inserir manifesto** propriedade igual a **Sim**.

1. Clique em **OK**.

1. Compile a solução.

## <a name="see-also"></a>Consulte também

[Aplicativos isolados](/windows/desktop/SbsCs/isolated-applications)<br/>
[Sobre Assemblies lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-)