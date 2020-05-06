---
title: Geração de manifesto no Visual Studio
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
ms.assetid: 0af60aa9-d223-42cd-8426-b3fc543a2a81
ms.openlocfilehash: f055e3d16dfc0ea4320883210458ae10daebdc45
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62273347"
---
# <a name="manifest-generation-in-visual-studio"></a>Geração de manifesto no Visual Studio

A geração de um arquivo de manifesto para um projeto específico pode ser controlada na caixa de diálogo **páginas de propriedades** do projeto. Na guia **Propriedades de configuração** , clique **em vinculador**, em **arquivo de manifesto**, em seguida, em **gerar manifesto**. Por padrão, as propriedades do projeto de novos projetos são definidas para gerar um arquivo de manifesto. No entanto, é possível desabilitar a geração do manifesto para um projeto usando a propriedade **gerar manifesto** do projeto. Quando essa propriedade é definida como **Sim**, o manifesto para esse projeto é gerado. Caso contrário, o vinculador ignora as informações do assembly ao resolver as dependências do código do aplicativo e não gera o manifesto.

O sistema de compilação no Visual Studio permite que o manifesto seja inserido no arquivo de aplicativo binário final ou gerado como um arquivo externo. Esse comportamento é controlado pela opção **Inserir manifesto** na caixa de diálogo **Propriedades do projeto** . Para definir essa propriedade, abra o nó de **ferramenta de manifesto** e, em seguida, selecione **entrada e saída**. Se o manifesto não for inserido, ele será gerado como um arquivo externo e salvo no mesmo diretório que o binário final. Se o manifesto for inserido, o Visual Studio incorporará os manifestos finais usando o seguinte processo:

1. Depois que o código-fonte é compilado em arquivos de objeto, o vinculador coleta informações de assembly dependentes. Ao vincular o binário final, o vinculador gera um manifesto intermediário que é usado posteriormente para gerar o manifesto final.

1. Depois que o manifesto intermediário e a vinculação forem concluídos, a ferramenta de manifesto será executada para mesclar um manifesto final e salvá-lo como um arquivo externo.

1. O sistema de compilação do projeto detecta se o manifesto gerado pela ferramenta de manifesto contém informações diferentes do manifesto já inserido no binário.

1. Se o manifesto inserido no binário for diferente do manifesto gerado pela ferramenta de manifesto, ou se o binário não contiver um manifesto incorporado, o Visual Studio invocará o vinculador mais uma vez para inserir o arquivo de manifesto externo dentro do binário como um recurso.

1. Se o manifesto inserido no binário for o mesmo que o manifesto gerado pela ferramenta de manifesto, a compilação continuará nas próximas etapas de compilação.

O manifesto é inserido dentro do binário final como um recurso de texto e pode ser exibido abrindo-se o binário final como um arquivo no Visual Studio. Para garantir que o manifesto aponte para as bibliotecas corretas, siga as etapas descritas em [noções básicas sobre as dependências de um aplicativo Visual C++](../windows/understanding-the-dependencies-of-a-visual-cpp-application.md) ou siga as sugestões descritas na seção [solução de problemas](troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md) .

## <a name="see-also"></a>Confira também

[Entendendo a geração de manifesto para programas C/C++](understanding-manifest-generation-for-c-cpp-programs.md)
