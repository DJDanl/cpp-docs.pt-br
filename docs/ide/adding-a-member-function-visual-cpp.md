---
title: Adicionar uma função de membro
ms.date: 11/09/2018
f1_keywords:
- vc.codewiz.classes.member.function
- vc.codewiz.function.overview
helpviewer_keywords:
- member functions, adding to classes
- classes [C++], adding members
- add member function wizard [C++]
ms.assetid: 55b25ddb-541d-44ed-957c-974ef91cfc85
ms.openlocfilehash: c5423cfb8e2ea1b39001ec512c9c7f460d6a1a19
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228681"
---
# <a name="add-a-member-function"></a>Adicionar uma função de membro

Em **Modo de Exibição de Classe**, adicione uma função de membro a qualquer classe. Quando você faz isso, uma declaração é adicionada ao arquivo de cabeçalho e o corpo de uma função de membro de stub é adicionado ao arquivo de implementação da classe, que pode então ser modificado.

**Para adicionar uma função de membro a uma classe:**

1. Em **Modo de Exibição de Classe**, expanda o nó do projeto para exibir as classes no projeto. (Para abrir **Modo de Exibição de Classe**, na barra de menus, escolha **Exibir**, **Modo de Exibição de Classe**.)

1. Abra o menu de atalho da classe à qual deseja adicionar uma função de membro e, em seguida, escolha **Adicionar**, **Adicionar Função**.

1. Forneça os detalhes apropriados sobre a função de membro. Para obter mais informações, confira [Assistente de adição de função de membro](#add-member-function-wizard).

1. Escolha o botão **Concluir** para gerar o código da função de membro.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de adição de função de membro](#add-member-function-wizard)

## <a name="add-member-function-wizard"></a>Assistente de adição de função de membro

Este assistente adiciona uma declaração de função de membro ao arquivo de cabeçalho. Também adiciona uma implementação de função de membro de stub ao arquivo de implementação para a classe selecionada.

Depois de adicionar a função de membro usando o assistente, edite o código no ambiente de desenvolvimento.

- **Tipo de retorno**

  Define o tipo de retorno da função de membro que está sendo adicionada. Forneça seu próprio tipo de retorno ou selecione um na lista de tipos disponíveis. Para obter informações sobre os tipos, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).

  | | | |
  |---|---|---|
  | **`char`** | **`int`** | **`unsigned int`** |
  | **`double`** | **`long`** | **`unsigned long`** |
  | **`float`** | **`short`** | **`void`** |
  | `HRESULT` | **`unsigned char`** | |

- **Nome da função**

  Define o nome da função de membro que está sendo adicionada.

- **Tipo de parâmetro**

  Define o tipo de parâmetro que está sendo adicionado à função de membro, caso a função de membro tenha parâmetros. Forneça seu próprio tipo de parâmetro ou selecione um na lista de tipos disponíveis.

  | | | |
  |---|---|---|
  | **`char`** | **`int`** | **`unsigned char`** |
  | **`double`** | **`long`** | **`unsigned int`** |
  | **`float`** | **`short`** | **`unsigned long`** |

- **Nome do parâmetro**

  Define o nome de um parâmetro que está sendo adicionado à função de membro, caso a função de membro tenha parâmetros.

- **Lista de parâmetros**

  Exibe uma lista de parâmetros adicionados à função de membro. Para adicionar um parâmetro à lista, forneça um tipo e um nome nas caixas **Tipo de parâmetro** e **Nome do parâmetro** e selecione **Adicionar**. Para remover um parâmetro da lista, selecione o parâmetro e **Remover**.

- **Acesso**

  Define o acesso à função de membro. Modificadores de acesso são palavras-chave que especificam o acesso que outras classes têm à função de membro. Para obter mais informações sobre como especificar o acesso, confira [Controle de acesso a membro](../cpp/member-access-control-cpp.md). O nível de acesso da função de membro é definido como **`public`** por padrão.

  - [público](../cpp/public-cpp.md)
  - [protected](../cpp/protected-cpp.md)
  - [pessoal](../cpp/private-cpp.md)

  Verifique se a nova função de membro é estática ou virtual e se ela é embutida ou pura. Se você definir a função de membro para que ela seja pura, a caixa de seleção **Virtual** será marcada e a caixa de seleção **Embutida** não ficará disponível. O padrão é uma função de membro não estática e não virtual.

  | Opção | Descrição |
  |--------|-------------|
  | [Estático](../cpp/storage-classes-cpp.md) |  Especifica que a função atua como uma função global e pode ser chamada fora da classe, mesmo sem nenhuma instanciação de classe. A função de membro não tem acesso a membros não estáticos. Uma função de membro especificada como `Static` não pode ser virtual. |
  | [Virtual](../cpp/virtual-cpp.md) | Assegura que a função de membro correta seja chamada para um objeto, seja qual for a expressão usada para fazer a chamada à função de membro. Uma função de membro especificada como `Virtual` não pode ser estática. |
  | **Mero** | Indica que nenhuma implementação é fornecida para a função de membro virtual que está sendo declarada. **Pura** pode ser especificada apenas em funções de membro virtual. Uma classe que contém, pelo menos, uma função de membro virtual pura é considerada uma classe abstrata. Classes derivadas da classe abstrata precisam implementar a função de membro virtual pura, ou também serão classes abstratas. |
  | [Embutido](../cpp/inline-functions-cpp.md) | Instrui o compilador a inserir uma cópia do corpo da função de membro em cada local em que a função de membro é chamada. Uma função de membro especificada como **Embutida** não pode ser pura. |

- **Arquivo .cpp**

  Define o local de arquivo em que a implementação da função de membro de stub é gravada. Por padrão, ela é gravada no arquivo .cpp da classe à qual a função de membro é adicionada. Selecione o botão de reticências para alterar o nome do arquivo. A implementação da função de membro é adicionada ao conteúdo do arquivo selecionado.

- **Comentário**

  Fornece um comentário no arquivo de cabeçalho da função de membro.

- **Assinatura de função**

  Exibe a função de membro textual do código quando você seleciona **Concluir**. Não possível editar o texto desta caixa. Para alterar a função de membro, altere as caixas apropriadas no assistente.
