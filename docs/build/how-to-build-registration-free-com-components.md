---
title: Como compilar componentes COM sem registro
ms.date: 11/04/2016
helpviewer_keywords:
- COM components, registration-free
ms.assetid: 7e585d6a-0314-45b2-8f1b-cae9ac4df037
ms.openlocfilehash: 783677c97835acc98751fc4a19f9405af752b71a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62188932"
---
# <a name="how-to-build-registration-free-com-components"></a>Como compilar componentes COM sem registro

Os componentes COM sem registro são componentes COM que têm manifestos incorporados às DLLs.

### <a name="to-build-manifests-into-com-components"></a>Para criar manifestos em componentes COM

1. Abra as páginas de propriedades do projeto para o componente COM.

1. Expanda o nó **Propriedades de configuração** e expanda o nó **ferramenta de manifesto** .

1. Selecione a página de propriedades **entrada e saída** e defina a propriedade **Inserir manifesto** igual a **Sim**.

1. Clique em **OK**.

1. Compile a solução.

## <a name="see-also"></a>Confira também

[Como compilar aplicativos isolados para consumir componentes COM](how-to-build-isolated-applications-to-consume-com-components.md)
