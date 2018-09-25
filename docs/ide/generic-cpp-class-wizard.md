---
title: Assistente da Classe C++ Genérica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.class.generic
dev_langs:
- C++
helpviewer_keywords:
- Generic C++ Class Wizard [C++]
ms.assetid: aa95be9e-fc1b-45db-a11d-0d32c4929077
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7b104c0631fde3164ef4299cead47caba912874b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46431080"
---
# <a name="generic-c-class-wizard"></a>Assistente da Classe C++ Genérica

Adiciona uma classe C++ genérica a um projeto. A classe não herda da ATL ou do MFC.

- **Nome da classe**

   Define o nome da nova classe.

- **Arquivo .h**

   Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Para salvar o arquivo de cabeçalho no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente, clique no botão de reticências (**...**). Se você especificar um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você especifique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Para acrescentar a declaração, clique em **Sim**; para retornar ao assistente e especificar outro nome de arquivo, clique em **Não**.

- **Arquivo .cpp**

   Define o nome do arquivo de implementação para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Nome da classe**. Para salvar o arquivo de implementação no local de sua escolha, ou para acrescentar a definição de classe a um arquivo existente, clique no botão de reticências (**...**). Se você especificar um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você especifique se a definição de classe deve ser acrescentada ao conteúdo do arquivo. Para acrescentar a definição, clique em **Sim**; para retornar ao assistente e especificar outro nome de arquivo, clique em **Não**.

- **Classe base**

   Define a classe base para a nova classe.

- **Access**

   Define o acesso aos membros da classe base para a nova classe. Modificadores de acesso são palavras-chave que especificam o nível de acesso que outras classes têm às funções de membro de classe. Para obter mais informações sobre como especificar o acesso, confira [Controle de acesso de membro](../cpp/member-access-control-cpp.md). Por padrão, o nível de acesso de classe é definido como `public`.

   - `public`

   - `protected`

   - `private`

   - **Padrão** (nenhum modificador de acesso é gerado.)

- **Destruidor virtual**

   Especifica se o destruidor de classe é virtual. O uso de um destruidor virtual ajuda a garantir que o destruidor correto seja chamado quando instâncias de classes derivadas são excluídas.

- **Embutido**

   Gera o construtor de classe e a definição de classe como funções embutidas no arquivo de cabeçalho.

- **Gerenciado**

   Quando marcado, adiciona uma classe gerenciada e um arquivo de cabeçalho. Quando desmarcado, adiciona uma classe nativa e um arquivo de cabeçalho.

## <a name="see-also"></a>Consulte também

[Adicionando uma classe do C++ genérica](../ide/adding-a-generic-cpp-class.md)