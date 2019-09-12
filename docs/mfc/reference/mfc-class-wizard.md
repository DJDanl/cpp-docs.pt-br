---
title: Assistente de classe MFC
ms.date: 09/06/2019
f1_keywords:
- vc.wizards.classwizard
helpviewer_keywords:
- MFC Class Wizard
ms.assetid: 8b0dd867-5d07-4214-99be-2a1c1995e6d9
ms.openlocfilehash: be829156d8fea8188a217b2c0a189ac5d6057a7e
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907996"
---
# <a name="mfc-class-wizard"></a>Assistente de classe MFC

Use o **Assistente de classe** para criar novas classes MFC ou adicione mensagens e manipuladores de mensagem a classes existentes em seu projeto.

Há três maneiras de abrir o **Assistente de classe**:

- No menu **projeto** , escolha **Assistente de classe**.
- Digite **Ctrl** > SHIFTX > .
- Em **modo de exibição de classe**, clique com o botão direito do mouse em uma classe ou no nó do projeto e escolha **Assistente de classe**.

![Assistente de classe](media/class-wizard.png "Assistente de classe MFC")

## <a name="uielement-list"></a>Lista UIElement

- **Projeto**

   O nome de um projeto em sua solução.

   Você pode selecionar outros projetos em sua solução na caixa de listagem suspensa.

- **Nome da classe**

   O nome de uma classe em seu projeto.

   Quando você seleciona uma classe na lista **nome da classe** , os dados da classe popula os controles no assistente de **classe do MFC**. Quando você altera o valor de um controle, os dados na classe selecionada são afetados.

- **Adicionar classe**

   Permite que você adicione uma nova classe ao seu projeto do MFC.

- **Classe base**

   A classe base da classe que é exibida no **nome da classe**.

- **Declaração de classe**

   A classe na qual a classe de **nome de classe** é declarada.

   A caixa **declaração de classe** será exibida somente se o nome em si for diferente do nome na **implementação da classe**.

- **Kit**

   A ID do recurso no **nome da classe**, se houver. Caso contrário, a caixa de **recursos** estará vazia.

- **Implementação de classe**

   O nome do arquivo que contém a implementação da classe no nome da **classe**.

   Você pode selecionar um arquivo de implementação diferente clicando na seta. A tabela a seguir lista as opções disponíveis.

   |Opção|Descrição|
   |------------|-----------------|
   |**Open File**|Sai do assistente de classe e abre o arquivo de implementação de classe atual.|
   |**Abrir pasta recipiente**|Abre a pasta que contém o arquivo de implementação da classe atual.|
   |**Copiar caminho completo para área de transferência**|Copia o caminho do arquivo de implementação atual para a área de transferência.|

- **Comandos**

   Permite adicionar, excluir, editar ou pesquisar um comando e seu manipulador de mensagens.

   Para adicionar um manipulador, clique em **Adicionar manipulador**ou clique duas vezes em um item na lista **IDs de objeto** ou na lista de **mensagens** . O nome da função resultante, a ID e a mensagem são exibidos na lista de **funções do membro** .

   Para excluir um manipulador, selecione um item na lista **funções de membro** e clique em **excluir manipulador**.

   Para modificar um manipulador, clique duas vezes no item correspondente na lista de **funções de membro** . Ou então, selecione um item na caixa de listagem e clique em **Editar código**.

- **Mensagens**

   Permite adicionar, excluir, editar ou pesquisar uma mensagem e seu manipulador de mensagens.

   Para adicionar um manipulador, clique em **Adicionar manipulador**ou clique duas vezes em um item na lista **mensagens** .

   Para adicionar uma mensagem personalizada, clique em **Adicionar mensagem personalizada** ou pressione a tecla Enter e especifique os valores na caixa de diálogo **Adicionar mensagem personalizada** . Nessa caixa de diálogo, você também pode selecionar **mensagem registrada** para manipular uma mensagem de janela que tem a garantia de ser exclusiva em todo o sistema operacional.

- **Funções virtuais**

   Permite adicionar, excluir, editar ou pesquisar uma função virtual ou uma função virtual substituída.

- **Variáveis de membro**

   Permite adicionar, excluir, editar ou pesquisar uma variável de membro.

- **Métodos**

   Permite adicionar, excluir ou pesquisar um método e também ir para a definição ou declaração de um método.

   Para adicionar um método, clique em **Adicionar método**e especifique os valores na caixa de diálogo **Adicionar método** .

   Para excluir um método, selecione um item na lista **métodos** e, em seguida, clique em **Excluir método**.

   Para exibir uma declaração, selecione um item na lista **métodos** e clique em **ir para a declaração.**

   Para exibir uma definição, clique duas vezes em um item na lista de **métodos** . Ou selecione um item na lista de **métodos** e clique no botão **ir para definição** .

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)
