---
title: Adicionar uma classe C++ genérica
ms.date: 11/09/2018
f1_keywords:
- vc.codewiz.classes.adding.generic
- vc.codewiz.class.generic
helpviewer_keywords:
- Visual C++, classes
- generic classes, adding
- generic classes
- generic C++ class wizard [C++]
ms.assetid: e95a5a14-dbed-4edc-8551-344fe48613cb
ms.openlocfilehash: e81ea442578e69bdd28301eba8f70561f6aa76c6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230539"
---
# <a name="add-a-generic-c-class"></a>Adicionar uma classe C++ genérica

Adicione uma classe C++ genérica usando **Modo de Exibição de Classe**. Uma classe C++ genérica é uma classe definida ou derivada de uma classe definida.

**Para adicionar uma classe C++ genérica a um projeto:**

1. Em **Modo de Exibição de Classe**, clique com o botão direito do mouse no projeto ao qual deseja adicionar a nova classe, escolha **Adicionar** e, em seguida, **Classe**.

1. Na caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md), no painel de modelos, selecione **Classe C++**. Selecione **Adicionar** para exibir o [Assistente da Classe C++ Genérica](#generic-c-class-wizard).

1. No assistente, forneça um nome de classe e, em seguida, defina as configurações ou aceite os padrões.

1. Para fechar o assistente e exibir a nova classe C++ genérica no projeto, selecione **Concluir**.

## <a name="in-this-section"></a>Nesta seção

- [Assistente da Classe C++ Genérica](#generic-c-class-wizard)

## <a name="generic-c-class-wizard"></a>Assistente da Classe C++ Genérica

Adiciona uma classe C++ genérica a um projeto. A classe não herda da ATL ou do MFC.

- **Nome da classe**

  Define o nome da nova classe.

- **Arquivo .h**

  Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Para salvar o arquivo de cabeçalho no local de sua escolha ou anexar a declaração de classe a um arquivo existente, selecione o botão de reticências (**...**). Se você especificar um arquivo existente e selecionar **concluir**, o assistente solicitará que você especifique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Para acrescentar a declaração, selecione **Sim**; para retornar ao assistente e especificar outro nome de arquivo, selecione **Não**.

- **Arquivo .cpp**

  Define o nome do arquivo de implementação para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Para salvar o arquivo de implementação no local de sua escolha ou acrescentar a definição de classe a um arquivo existente, selecione o botão de reticências (**...**). Se você especificar um arquivo existente e selecionar **concluir**, o assistente solicitará que você especifique se a definição de classe deve ser anexada ao conteúdo do arquivo. Para acrescentar a definição, selecione **Sim**; para retornar ao assistente e especificar outro nome de arquivo, selecione **Não**.

- **Classe base**

  Define a classe base para a nova classe.

- **Acesso**

  Define o acesso aos membros da classe base para a nova classe. Modificadores de acesso são palavras-chave que especificam o nível de acesso que outras classes têm às funções de membro de classe. Para obter mais informações sobre como especificar o acesso, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md). Por padrão, o nível de acesso da classe é definido como **`public`** .

  - **`public`**
  - **`protected`**
  - **`private`**
  - **Padrão** (nenhum modificador de acesso é gerado.)

- **Destruidor virtual**

  Especifica se o destruidor de classe é virtual. O uso de um destruidor virtual ajuda a garantir que o destruidor correto seja chamado quando instâncias de classes derivadas são excluídas.

- **Embutido**

  Gera o construtor de classe e a definição de classe como funções embutidas no arquivo de cabeçalho.

- **Gerenciado**

  Quando marcado, adiciona uma classe gerenciada e um arquivo de cabeçalho. Quando desmarcado, adiciona uma classe nativa e um arquivo de cabeçalho.
