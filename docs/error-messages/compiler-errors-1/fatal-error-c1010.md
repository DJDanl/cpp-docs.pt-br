---
title: Erro fatal C1010
ms.date: 09/03/2019
f1_keywords:
- C1010
helpviewer_keywords:
- C1010
ms.assetid: dfd035f1-a7a2-40bc-bc92-dc4d7f456767
ms.openlocfilehash: 0315af63e9fdbbb0b136a85a23cb28936dee6836
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273556"
---
# <a name="fatal-error-c1010"></a>Erro fatal C1010

> fim de arquivo inesperado ao procurar cabeçalho pré-compilado. Você esqueceu de adicionar ' #include *Name*' à sua fonte?

## <a name="remarks"></a>Comentários

Um arquivo de inclusão especificado por [/Yu](../../build/reference/yu-use-precompiled-header-file.md) não está listado no arquivo de origem. Essa opção é habilitada por padrão em muitos tipos C++ de projeto do Visual Studio. O arquivo de inclusão padrão especificado por essa opção é *PCH. h*ou *stdafx. h* no Visual Studio 2017 e anterior.

No ambiente do Visual Studio, use um dos seguintes métodos para resolver esse erro:

- Verifique se você não excluiu acidentalmente, renomeou ou removeu o arquivo de cabeçalho *PCH. h* ou o arquivo de origem *PCH. cpp* do projeto atual. (Em projetos mais antigos, esses arquivos podem ser nomeados *stdafx. h* e *stdafx. cpp*.)

- Verifique se o arquivo de cabeçalho *PCH. h* ou *stdafx. h* está incluído antes de qualquer outro código ou diretivas de pré-processador em seus arquivos de origem. (No Visual Studio, esse arquivo de cabeçalho é especificado pela propriedade de projeto do **arquivo de cabeçalho pré-compilado** .)

- Você pode desativar o uso de cabeçalho pré-compilado. Se você desativar cabeçalhos pré-compilados, ele poderá afetar seriamente o desempenho da compilação.

### <a name="to-turn-off-precompiled-headers"></a>Para desativar cabeçalhos pré-compilados

Para desativar o uso de cabeçalho pré-compilado em um projeto, siga estas etapas:

1. Na janela **Gerenciador de soluções** , clique com o botão direito do mouse no nome do projeto e escolha **Propriedades** para abrir a caixa de diálogo **páginas de propriedades** do projeto.

1. Na lista suspensa **configuração** , selecione **todas as configurações**.

1. Selecione a página de propriedades **configuração** > de cabeçalhos**CC++/**  > pré-compilados.

1. Na lista propriedade, selecione a lista suspensa para a propriedade de **cabeçalho pré-compilado** e escolha **não usar cabeçalhos pré-compilados**. Escolha **OK** para salvar suas alterações.

1. Na janela **Gerenciador de soluções** , clique com o botão direito do mouse no arquivo de origem *PCH. cpp* em seu projeto. (Em projetos mais antigos, o arquivo pode ser nomeado *stdafx. cpp*.) Escolha **excluir do projeto** para removê-lo da compilação.

1. Use o comando de menu **criar** > **solução limpa** para cada configuração que você criar, para excluir todos os arquivos *Project_Name. pch* em seus diretórios de Build intermediários.

## <a name="see-also"></a>Consulte também

[Arquivos de cabeçalho pré-compilados](../../build/creating-precompiled-header-files.md)\
[/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md)\
[/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md)