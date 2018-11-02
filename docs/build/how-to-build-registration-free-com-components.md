---
title: Como compilar componentes COM sem registro
ms.date: 11/04/2016
helpviewer_keywords:
- COM components, registration-free
ms.assetid: 7e585d6a-0314-45b2-8f1b-cae9ac4df037
ms.openlocfilehash: 4f4ebf121b761c37969fa3f9788bda52d913f340
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463525"
---
# <a name="how-to-build-registration-free-com-components"></a>Como compilar componentes COM sem registro

Componentes do COM sem registro são componentes COM que tem criados as DLLs de manifestos.

### <a name="to-build-manifests-into-com-components"></a>Para compilar manifestos em componentes COM

1. Abra as páginas de propriedades do projeto para o componente COM.

1. Expanda o **propriedades de configuração** nó e, em seguida, expanda o **ferramenta de manifesto** nó.

1. Selecione o **de entrada e saída** página de propriedades e defina as **Inserir manifesto** propriedade igual a **Sim**.

1. Clique em **OK**.

1. Compile a solução.

## <a name="see-also"></a>Consulte também

[Aplicativos isolados](/windows/desktop/SbsCs/isolated-applications)<br/>
[Sobre Assemblies lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-)<br/>
[Como compilar aplicativos isolados para consumir componentes COM](../build/how-to-build-isolated-applications-to-consume-com-components.md)