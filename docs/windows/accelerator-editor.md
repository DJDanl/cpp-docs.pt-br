---
title: Editor de acelerador (C++)
ms.date: 02/14/2019
f1_keywords:
- vc.editors.accelerator.F1
- vc.editors.accelerator
helpviewer_keywords:
- accelerator tables [C++], editing
- tables [C++], accelerator key
- accelerator keys [C++]
- resource editors [C++], Accelerator editor
- keyboard shortcuts [C++], Accelerator editor
- accelerator properties
- properties [C++], accelerator properties
- Type property
- Key property
- Modifier property
- VIRTKEY
- Key property
- ID property
- accelerator tables [C++], editing
- keyboard shortcuts [C++], editing in an accelerator table
- searching, in accelarator tables
- accelerator tables [C++], finding entries
- accelerator tables [C++], adding entries
- New Accelerator command
- accelerator tables [C++], deleting entries
- keyboard shortcuts [C++], deleting entry from accelerator table
- accelerator tables [C++], copying entries
- rc files [C++], moving an accelerator table entry
- .rc files [C++], moving accelerator table entries
- accelerator tables [C++], moving entries
- keyboard shortcuts [C++], property changing
- accelerator tables [C++], changing properties
ms.assetid: 013c30b6-5d61-4f1c-acef-8bd15bed7060
ms.openlocfilehash: c98ff1fd44b73b3f204e9b952836c387f7f21146
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91353084"
---
# <a name="accelerator-editor-c"></a>Editor de acelerador (C++)

Uma tabela de acelerador é um recurso do Windows do C++ que contém uma lista de teclas de aceleração, conhecidas como teclas de atalho, e os identificadores de comando associados a eles. Um programa pode ter mais de uma tabela de acelerador.

Normalmente, os aceleradores são usados como atalhos de teclado para comandos de programa que também estão disponíveis em um menu ou barra de ferramentas. No entanto, você pode usar a tabela acelerador para definir combinações de teclas para comandos que não têm um objeto de interface de usuário associado a eles.

> [!TIP]
> Ao usar o **Editor de acelerador**, clique com o botão direito do mouse para exibir um menu de atalho com comandos frequentes. Os comandos disponíveis dependem do que o ponteiro está apontando.

Você pode usar [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code) para conectar comandos de tecla acelerador ao código. Para obter uma lista de chaves de acelerador predefinidas, consulte [teclas de aceleração](predefined-accelerator-keys.md).

> [!NOTE]
> O Windows não permite que você crie tabelas de acelerador vazias. Se você criar uma tabela de acelerador sem entradas, ela será excluída automaticamente quando você salvar a tabela.

## <a name="accelerator-properties"></a>Propriedades do acelerador

Você pode definir as propriedades do acelerador no [janela Propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o **Editor de acelerador** para modificar as propriedades do acelerador na tabela do acelerador. As alterações feitas usando a janela **Propriedades** ou o **Editor do acelerador** têm o mesmo resultado, as edições são refletidas imediatamente na tabela do acelerador.

A propriedade **ID** faz referência a cada entrada de tabela de acelerador no código do programa. Essa entrada é o valor de comando que o programa recebe quando um usuário pressiona a tecla aceleradora ou uma combinação de teclas. Para tornar um acelerador igual a um item de menu, faça com que a **ID** seja a mesma, desde que a **ID** da tabela de acelerador seja igual à **ID** do recurso de menu.

Cada **ID** do acelerador tem três propriedades: **modificador**, **chave**e **tipo**

A propriedade **modificador** define combinações de teclas de controle para o acelerador.

> [!NOTE]
> Na janela **Propriedades** , a propriedade **modificador** aparece como três propriedades **booleanas** separadas, todas que podem ser controladas independentemente: **ALT**, **Ctrl**e **Shift**.

Veja a seguir as entradas legais para a propriedade **modificador** na tabela aceleradora:

   |Valor|Descrição|
   |-----------|-----------------|
   |**Nenhuma**|O usuário pressiona apenas o valor da **chave** .<br/><br/>Esse valor é usado com mais eficiência com os valores ASCII/ANSI 001 a 026, que é interpretado como ^ A a ^ Z (**Ctrl + a** através de **Ctrl + Z**).|
   |**Pressionando**|O usuário deve pressionar **ALT** antes do valor da **chave** .|
   |**Teclas**|O usuário deve pressionar **Ctrl** antes do valor da **chave** , não é válido com o tipo ASCII.|
   |**Alternância**|O usuário deve pressionar **Shift** antes do valor da **chave** .|
   |**CTRL + ALT**|O usuário deve pressionar **Ctrl** e **ALT** antes do valor da **chave** , não é válido com o tipo ASCII.|
   |**Ctrl + Shift**|O usuário deve pressionar **Ctrl** e **Shift** antes do valor da **chave** , não é válido com o tipo ASCII.|
   |**Alt + Shift**|O usuário deve pressionar **ALT** e **Shift** antes do valor da **chave** , não é válido com o tipo ASCII.|
   |**Ctrl + Alt + Shift**|O usuário deve pressionar **Ctrl**, **ALT**e **Shift** antes do valor da **chave** , não é válido com o tipo ASCII.|

A propriedade de **chave** define a chave real a ser usada como o acelerador.

Veja a seguir as entradas legais para a propriedade de **chave** na tabela aceleradora:

   |Valor|Descrição|
   |-----------|-----------------|
   |Um inteiro entre 0 e 255 no formato decimal.|O valor determina se o valor é tratado como ASCII ou ANSI da seguinte maneira:<br/><br/>   -Números de dígito único são sempre interpretados como a chave correspondente, em vez de valores ASCII ou ANSI.<br/>   -Os valores de 1 a 26, quando precedidos por zeros, são interpretados como ^ A até ^ Z, que representa o valor ASCII das letras do alfabeto quando pressionado com a tecla **Ctrl** pressionada.<br/>   -Os valores de 27-32 são sempre interpretados como valores decimais de três dígitos 027 a 032.<br/>   -Valores de 033 a 255, precedidos por 0 ou não são interpretados como valores ANSI.|
   |Um único caractere de teclado.|Maiúsculas a-Z ou os números 0-9 podem ser valores ASCII ou de chave virtual. Qualquer outro caractere é somente ASCII.|
   |Um único caractere de teclado no intervalo de A-Z (somente maiúsculas), precedido por um acento circunflexo (^), por exemplo, ^ C.|Essa opção insere o valor ASCII da chave quando ela é pressionada com a tecla **Ctrl** pressionada.|
   |Qualquer identificador de chave virtual válido.|A caixa de **chave** suspensa na tabela acelerador contém uma lista de identificadores de chave virtual padrão.|

> [!NOTE]
> Ao inserir um valor ASCII, as opções de Propriedade do **modificador** são limitadas. A única chave de controle disponível para uso é a tecla **ALT** .

> [!TIP]
> Um atalho para definir uma chave de acelerador é clicar com o botão direito do mouse em uma entrada ou em várias entradas na tabela do acelerador e escolher a **tecla seguinte digitada** e pressionar qualquer uma das chaves ou combinações de teclas no teclado.
>
> Esse **próximo comando digitado de chave** também está disponível no menu **Editar** .

A propriedade **Type** determina se a combinação de teclas de atalho associada à **ID** do acelerador é interpretada como um valor de chave ASCII/ANSI ou uma combinação de chave virtual (VIRTKEY).

- Se a propriedade **Type** for **ASCII**, a propriedade **modificadora** só poderá ser `None` ou `Alt` , ou poderá ter um acelerador que use a tecla **Ctrl** , conforme especificado, precedendo a chave com um `^` .

- Se a propriedade **Type** for **VIRTKEY**, qualquer combinação de valores **modificadores** e de **chave** será válida.

> [!NOTE]
> Se você quiser inserir um valor na tabela de acelerador e tiver o valor tratado como ASCII/ANSI, selecione o **tipo** para a entrada na tabela e selecione **ASCII** na lista suspensa. No entanto, se você usar o **próximo comando digitado de chave** no menu **Editar** para especificar a **chave**, será necessário alterar a propriedade **Type** de **VIRTKEY** para **ASCII** *antes* de inserir o código de **chave** .

## <a name="accelerator-tables"></a>Tabelas do acelerador

Em um projeto C++, você pode editar uma tabela de acelerador diretamente com a edição in-loco no **Editor de acelerador**.

Os procedimentos a seguir referem-se ao uso de páginas de propriedades padrão, no entanto, tanto a edição in-loco quanto o método de página de propriedades têm o mesmo resultado. As alterações feitas usando páginas de propriedades ou usando a edição in-loco são refletidas imediatamente na tabela de aceleração.

### <a name="to-edit-in-an-accelerator-table"></a>Para editar em uma tabela de acelerador

1. Abra a tabela acelerador clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione uma entrada na tabela e selecione para ativar a edição in-loco.

1. Selecione na caixa de combinação suspensa ou digite no local para fazer alterações:

   - Para **ID**, selecione na lista ou digite para editar.

   - Para o **modificador**, selecione na lista.

   - Para **chave**, selecione na lista ou digite para editar.

   - Para **tipo**, selecione **ASCII** ou **VIRTKEY** na lista.

### <a name="to-find-an-entry-in-an-open-accelerator-table"></a>Para localizar uma entrada em uma tabela de acelerador aberta

1. Abra a tabela acelerador clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione um cabeçalho de coluna para classificar o conteúdo da coluna em ordem alfabética. Por exemplo, selecione **ID** para exibir todas as IDs em sua tabela do acelerador em ordem alfabética.

   Em seguida, você pode verificar a lista e encontrar a entrada.

### <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada a uma tabela de acelerador

1. Abra a tabela acelerador clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com o botão direito do mouse na tabela acelerador e escolha **novo acelerador**ou selecione a entrada de linha vazia na parte inferior da tabela.

1. Selecione uma **ID** na lista suspensa na caixa **ID** ou digite uma nova *ID* na caixa **ID** .

1. Digite a *chave* que você deseja usar como um acelerador ou clique com o botão direito do mouse e escolha a **tecla seguinte digitada** para definir uma combinação de teclas ou vá para o menu **Editar**  >  **próxima chave digitada**.

1. Altere o **modificador** e o **tipo**, se necessário, e pressione **Enter**.

> [!NOTE]
> Verifique se todos os aceleradores definidos são exclusivos. Você pode ter várias combinações de teclas atribuídas à mesma ID sem nenhum efeito de mal, por exemplo, **Ctrl** + **P** e **F8** podem ser atribuídas a ID_PRINT. No entanto, ter uma combinação de teclas atribuída a mais de uma ID não funcionará bem, por exemplo, **Ctrl** + **Z** atribuído a ID_SPELL_CHECK e ID_THESAURUS.

### <a name="to-delete-an-entry-from-an-accelerator-table"></a>Para excluir uma entrada de uma tabela de acelerador

1. Abra a tabela acelerador clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a entrada que você deseja excluir ou mantenha pressionada a tecla **Ctrl** ou **Shift** enquanto seleciona para escolher várias entradas.

1. Clique com o botão direito do mouse e escolha **excluir**ou vá para o menu **Editar**  >  **excluir**.

> [!TIP]
> Você também pode pressionar a tecla **delete** para excluir.

### <a name="to-move-or-copy-an-accelerator-table-entry-to-another-resource-script-file"></a>Para mover ou copiar uma entrada de tabela de acelerador para outro arquivo de script de recurso

1. Abra as tabelas do acelerador em ambos os arquivos de script de recurso e selecione a entrada que você deseja mover.

1. No menu **Editar** , escolha **copiar** ou **recortar**.

1. Selecione uma entrada no arquivo de script de recurso de destino e, no menu **Editar** , escolha **colar**.

> [!NOTE]
> Você também pode usar as teclas de atalho para copiar e colar.

### <a name="to-change-the-properties-of-multiple-accelerator-keys"></a>Para alterar as propriedades de várias teclas aceleradoras

1. Abra a tabela acelerador clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione as teclas de aceleração que você deseja alterar mantendo a tecla **Ctrl** pressionada ao selecionar cada uma delas.

1. Vá para a [janela Propriedades](/visualstudio/ide/reference/properties-window) e digite os valores que você deseja que todos os aceleradores selecionados compartilhem.

> [!NOTE]
> Cada valor de modificador é exibido como uma propriedade booliana na janela **Propriedades** . Se você alterar um valor de modificador na janela **Propriedades** , a tabela aceleradora tratará o novo modificador como uma adição de quaisquer modificadores que estavam anteriormente. Por isso, se você definir qualquer valor de modificador, precisará definir todos eles para garantir que cada acelerador Compartilhe as mesmas configurações de **modificador** .

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editores de recursos](resource-editors.md)<br/>
[Teclas de aceleração](predefined-accelerator-keys.md)<br/>
