---
title: Geração de manifesto no Visual Studio
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
ms.assetid: 0af60aa9-d223-42cd-8426-b3fc543a2a81
ms.openlocfilehash: f055e3d16dfc0ea4320883210458ae10daebdc45
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58781673"
---
# <a name="manifest-generation-in-visual-studio"></a>Geração de manifesto no Visual Studio

Geração de um arquivo de manifesto para um projeto específico pode ser controlada no projeto **páginas de propriedade** caixa de diálogo. No **propriedades de configuração** , clique em **vinculador**, em seguida, **arquivo de manifesto**, em seguida, **gerar manifesto**. Por padrão, as propriedades do projeto de novos projetos são definidas para gerar um arquivo de manifesto. No entanto é possível desabilitar a geração de manifesto para um projeto usando o **gerar manifesto** propriedade do projeto. Quando essa propriedade é definida como **Sim**, o manifesto para este projeto é gerado. Caso contrário, o vinculador ignora as informações de assembly ao resolver as dependências de código do aplicativo e não gera o manifesto.

O sistema de compilação no Visual Studio permite que o manifesto a ser inserido no arquivo binário de aplicativo final ou gerado como um arquivo externo. Esse comportamento é controlado pelo **Inserir manifesto** opção a **propriedades do projeto** caixa de diálogo. Para definir essa propriedade, abra o **ferramenta de manifesto** nó, em seguida, selecione **de entrada e saída**. Se o manifesto não for inserido, ele é gerado como um arquivo externo e salvo no mesmo diretório que o binário final. Se o manifesto é incorporado, o Visual Studio incorpora os manifestos finais usando o seguinte processo:

1. Depois que o código-fonte é compilado em arquivos de objeto, o vinculador coleta informações de assembly dependente. Ao fazer a ligação final binário, o vinculador gera um manifesto intermediário que é usado posteriormente para gerar o manifesto final.

1. Depois de intermediários manifesto e vinculação estiverem concluídas, a ferramenta de manifesto será executada para mesclar um manifesto final e salvá-lo como um arquivo externo.

1. O projeto do sistema de compilação e detecta se o manifesto gerado pela ferramenta de manifesto contém informações diferentes de manifesto já inserida no binário.

1. Se o manifesto inserido no binário é diferente do manifesto gerado pela ferramenta de manifesto ou o binário não contém um manifesto inserido, o Visual Studio invocará o vinculador mais uma vez para inserir o arquivo de manifesto externo dentro do binário como um recurso.

1. Se o manifesto inserido no binário é o mesmo que o manifesto gerado pela ferramenta de manifesto, a compilação continuará para as próximas etapas de compilação.

O manifesto é incorporado no final binário como um recurso de texto e pode ser exibido, abrindo o binário final como um arquivo no Visual Studio. Para garantir que o manifesto aponta para as bibliotecas corretas, siga as etapas descritas em [Noções básicas sobre as dependências de um aplicativo do Visual C++](../windows/understanding-the-dependencies-of-a-visual-cpp-application.md) ou seguir as sugestões descritas o [desoluçãodeproblemas](troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md) seção.

## <a name="see-also"></a>Consulte também

[Noções básicas sobre o Manifest Generation para programas do C/C++](understanding-manifest-generation-for-c-cpp-programs.md)
