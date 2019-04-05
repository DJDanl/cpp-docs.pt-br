---
title: Editor de aceleradores (C++)
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
ms.openlocfilehash: f5ae9880719a3a8b799ea8deb751b6f0a85542bd
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041118"
---
# <a name="accelerator-editor-c"></a>Editor de aceleradores (C++)

Uma tabela de Aceleradores é um recurso do Windows C++ que contém uma lista de teclas de aceleração, conhecidos como teclas de atalho e os identificadores de comando que estão associados eles. Um programa pode ter mais de uma tabela de aceleradores.

Normalmente, os aceleradores são usados como atalhos de teclado para comandos de programa que também estão disponíveis em um menu ou barra de ferramentas. No entanto, você pode usar a tabela de aceleradores para definir as combinações de teclas para comandos que não têm um objeto de interface do usuário associado a eles.

> [!TIP]
> Ao usar o **Editor de aceleradores**, clique com botão direito para exibir um menu de atalho de comandos frequentes. Os comandos disponíveis dependem do que o ponteiro estiver apontando para.

Você pode usar [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code) conectem os comandos do acelerador chave ao código. Para obter uma lista de teclas de aceleração predefinidas, consulte [teclas de aceleração](../windows/predefined-accelerator-keys.md).

> [!NOTE]
> Windows não permite que você crie tabelas de aceleradores vazio. Se você criar uma tabela de aceleradores sem entradas, ele é excluído automaticamente quando você salva a tabela.

## <a name="accelerator-properties"></a>Propriedades do acelerador

Você pode definir propriedades do acelerador [janela de propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o **Editor de aceleradores** para modificar as propriedades de acelerador na tabela de acelerador. As alterações feitas usando o **propriedades** janela ou o **Editor de aceleradores** têm o mesmo resultado, as edições são refletidas imediatamente na tabela de aceleradores.

O **ID** propriedade faz referência a cada entrada de tabela do acelerador no código do programa. Essa entrada é o valor do comando que o programa recebe quando um usuário pressiona a tecla de atalho ou uma combinação de teclas. Para fazer o mesmo que um item de menu um acelerador, faça o **ID** o mesmo, desde que o **ID** do acelerador de tabela é o mesmo que o **ID** para o recurso de menu.

Cada Acelerador **ID** tem três propriedades: **Modificador**, **chave**, e **tipo**

O **modificador** propriedade define o controle de combinações de teclas para o acelerador.

> [!NOTE]
> No **propriedades** janela, o **modificador** propriedade apareça como três separado **booliano** propriedades, que pode ser controlado de forma independente: **ALT**, **Ctrl**, e **Shift**.

A seguir estão as entradas legais para o **modificador** propriedade na tabela de acelerador:

   |Valor|Descrição|
   |-----------|-----------------|
   |**Nenhum**|Usuário pressiona apenas o **chave** valor.<br/><br/>Esse valor com mais eficiência é usado com os valores de ASCII/ANSI 001 a 026, que é interpretado como ^ A até ^ Z (**Ctrl + T** por meio **Ctrl + Z**).|
   |**Alt**|O usuário deve pressionar **Alt** antes do **chave** valor.|
   |**Ctrl**|O usuário deve pressionar **Ctrl** antes do **chave** valor, não é válido com o tipo de ASCII.|
   |**Shift**|O usuário deve pressionar **Shift** antes do **chave** valor.|
   |**Ctrl+Alt**|O usuário deve pressionar **Ctrl** e **Alt** antes do **chave** valor, não é válido com o tipo de ASCII.|
   |**Ctrl+Shift**|O usuário deve pressionar **Ctrl** e **Shift** antes do **chave** valor, não é válido com o tipo de ASCII.|
   |**Alt+Shift**|O usuário deve pressionar **Alt** e **Shift** antes do **chave** valor, não é válido com o tipo de ASCII.|
   |**Ctrl+Alt+Shift**|O usuário deve pressionar **Ctrl**, **Alt**, e **Shift** antes do **chave** valor, não é válido com o tipo de ASCII.|

O **chave** propriedade define a chave real a ser usado como o acelerador.

A seguir estão as entradas legais para o **chave** propriedade na tabela de acelerador:

   |Valor|Descrição|
   |-----------|-----------------|
   |Um inteiro entre 0 e 255 no formato decimal.|O valor determina se o valor é tratado como ASCII ou ANSI da seguinte maneira:<br/><br/>   -Números de dígito sempre são interpretados como a chave correspondente, em vez de valores ASCII ou ANSI.<br/>   -Valores de 1 a 26, quando precedido com zeros, são interpretados como ^ A até ^ Z, que representa o valor de ASCII das letras do alfabeto quando pressionado com o **Ctrl** tecla pressionada.<br/>   -Valores de 27 32 sempre são interpretados como valores de três dígitos decimais 027 por meio de 032.<br/>   -Valores do 033 a 255, precedido por 0 ou não são interpretados como valores de ANSI.|
   |Um caractere de teclado único.|Letras maiusculas A - Z ou os números 0 - 9 podem ser ASCII ou virtuais valores de chave. Qualquer outro caractere só é ASCII.|
   |Um caractere de teclado único no intervalo A - Z (apenas maiusculo), precedido por um acento circunflexo (^), por exemplo, ^ C.|Essa opção insere o valor de ASCII da chave quando ela estiver pressionada com a **Ctrl** tecla pressionada.|
   |Qualquer válido identificador de chave virtual.|Na lista suspensa **chave** caixa na tabela de acelerador contém uma lista de identificadores de chave virtuais padrão.|

> [!NOTE]
> Ao inserir um valor de ASCII, o **modificador** opções de propriedade são limitadas. É a única chave de controle disponível para uso a **Alt** chave.

> [!TIP]
> Um atalho para definir uma tecla aceleradora é mouse uma entrada ou várias entradas na tabela de aceleradores, em seguida, escolha **próxima chave digitada** e pressione qualquer uma das chaves ou combinações de teclas no teclado.
>
> Isso **próxima chave digitada** comando também está disponível na **editar** menu.

O **tipo** propriedade determina se a combinação de teclas de atalho associado com o acelerador **ID** é interpretado como um valor de chave ASCII/ANSI ou uma combinação de chave virtual (VIRTKEY).

- Se o **tipo** é de propriedade **ASCII**, o **modificador** propriedade só pode ser `None` ou `Alt`, ou pode ter um acelerador que usa o **Ctrl** principais, conforme especificado precedendo a chave com um `^`.

- Se o **tipo** é de propriedade **VIRTKEY**, qualquer combinação de **modificador** e **chave** valores é válido.

> [!NOTE]
> Se você quiser inserir um valor para a tabela de Aceleradores e têm o valor tratado como ASCII/ANSI, selecione a **tipo** para a entrada na tabela e selecione **ASCII** na lista suspensa. No entanto, se você usar o **próxima chave digitada** comando da **editar** menu para especificar o **chave**, você deve alterar o **tipo** propriedade de **VIRTKEY** à **ASCII** *antes* inserindo a **chave** código.

## <a name="accelerator-tables"></a>Tabelas de aceleradores

Em um projeto do C++, você pode editar uma tabela de aceleradores diretamente com a edição in-loco na **Editor de aceleradores**.

Os procedimentos a seguir se referem ao uso de páginas de propriedades padrão, no entanto, a edição no local e o método de página de propriedade tem o mesmo resultado. As alterações feitas usando páginas de propriedades ou usando a edição in-loco são refletidas imediatamente na tabela de acelerador.

### <a name="to-edit-in-an-accelerator-table"></a>Para editar em uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione uma entrada na tabela e selecione para ativar a edição in-loco.

1. Selecione a caixa de combinação suspensa ou digite para fazer alterações:

   - Para **ID**, selecione na lista ou digite para editar.

   - Para **modificador**, selecione na lista.

   - Para **chave**, selecione na lista ou digite para editar.

   - Para **tipo**, selecione **ASCII** ou **VIRTKEY** na lista.

### <a name="to-find-an-entry-in-an-open-accelerator-table"></a>Para localizar uma entrada em uma tabela de aceleradores aberto

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione um cabeçalho de coluna para classificar o conteúdo da coluna em ordem alfabética. Por exemplo, selecione **ID** para exibir todas as IDs em sua tabela de aceleradores em ordem alfabética.

   Você pode, em seguida, examine a lista e localize a entrada.

### <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada para uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Clique dentro da tabela do acelerador e escolha **novo Acelerador**, ou selecione a entrada de linha vazia na parte inferior da tabela.

1. Selecione uma **ID** na lista suspensa na **ID** caixa ou digite um novo *ID* no **ID** caixa.

1. Tipo de *chave* que deseja usar como um acelerador, ou clique com botão direito e escolha **próxima chave digitada** para definir uma combinação de teclas, ou vá para o menu **editar**  >  **Próxima chave digitada**.

1. Alterar o **modificador** e **tipo**, se necessário e pressione **Enter**.

> [!NOTE]
> Verifique se todos os aceleradores que você define são exclusivos. Você pode ter várias combinações de teclas atribuídas para a mesma ID com nenhum efeito mal, por exemplo, **Ctrl**+**P** e **F8** podem ser atribuídos ao ID_PRINT. No entanto, ter atribuída a mais de uma ID não funcionará bem, por exemplo, uma combinação de teclas **Ctrl**+**Z** atribuídas a ID_SPELL_CHECK e ID_THESAURUS.

### <a name="to-delete-an-entry-from-an-accelerator-table"></a>Para excluir uma entrada de uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a entrada que você deseja excluir, ou mantenha pressionada a **Ctrl** ou **Shift** chave durante a seleção para escolher várias entradas.

1. Clique com botão direito e escolha **exclua**, ou vá para o menu **editar** > **excluir**.

> [!TIP]
> Você também pode pressionar o **excluir** tecla para excluir.

### <a name="to-move-or-copy-an-accelerator-table-entry-to-another-resource-script-file"></a>Para mover ou copiar uma entrada de tabela de aceleradores para outro arquivo de script de recurso

1. Abra as tabelas de aceleradores em ambos os arquivos de script de recurso e selecione a entrada que você deseja mover.

1. Dos **edite** menu, escolha **cópia** ou **Recortar**.

1. Selecione uma entrada no arquivo de script de recurso de destino e nos **edite** menu, escolha **colar**.

> [!NOTE]
> Você também pode usar as teclas de atalho para copiar e colar.

### <a name="to-change-the-properties-of-multiple-accelerator-keys"></a>Para alterar as propriedades de várias teclas de aceleração

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione as teclas de aceleração que você deseja alterar, mantendo pressionada a **Ctrl** da chave conforme você seleciona cada uma delas.

1. Vá para o [janela de propriedades](/visualstudio/ide/reference/properties-window) e digite os valores que você deseja que todos os aceleradores selecionados para compartilhar.

> [!NOTE]
> Cada valor de modificador aparece como uma propriedade booleana na **propriedades** janela. Se você alterar uma [modificador](../windows/accelerator-modifier-property.md) o valor de **propriedades** janela, a tabela de aceleradores trata o novo modificador como uma adição a qualquer modificador que anteriormente estavam lá. Por isso, se você definir quaisquer valores do modificador, você precisará definir todas elas para garantir que cada Acelerador compartilha os mesmos **modificador** configurações.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Teclas de aceleração](../windows/predefined-accelerator-keys.md)<br/>