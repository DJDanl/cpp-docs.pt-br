---
title: Editando tabelas de aceleradores (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.accelerator
helpviewer_keywords:
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
ms.assetid: 56e24efb-d06b-4ed9-8915-1f99f725e247
ms.openlocfilehash: dfa0c26132378bcbe8a7f5203351134d91746aa7
ms.sourcegitcommit: 5beace7dcc6bf0e8b8cc96a930e7424f9daa05cb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2019
ms.locfileid: "55232169"
---
# <a name="editing-accelerator-tables-c"></a>Editando tabelas de aceleradores (C++)

Em um projeto do C++, você pode editar uma tabela de aceleradores diretamente com a edição in-loco na **Accelerator** editor.

Os procedimentos a seguir se referem ao uso de páginas de propriedades padrão, no entanto, a edição no local e o método de página de propriedade tem o mesmo resultado. As alterações feitas usando páginas de propriedades ou usando a edição in-loco são refletidas imediatamente na tabela de acelerador.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

## <a name="to-edit-in-an-accelerator-table"></a>Para editar em uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. Selecione uma entrada na tabela e selecione para ativar a edição in-loco.

1. Selecione a caixa de combinação suspensa ou digite para fazer alterações.

   - Para [ID](id-property.md), selecione na lista ou digite para editar.

   - Para [modificador](../windows/accelerator-modifier-property.md), selecione na lista.

   - Para [chave](../windows/accelerator-key-property.md), selecione na lista ou digite para editar.

   - Para [tipo](../windows/accelerator-type-property.md), selecione **ASCII** ou **VIRTKEY** na lista.

## <a name="to-find-an-entry-in-an-open-accelerator-table"></a>Para localizar uma entrada em uma tabela de aceleradores aberto

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. Selecione um cabeçalho de coluna para classificar o conteúdo da coluna em ordem alfabética. Por exemplo, selecione **ID** para exibir todas as IDs em sua tabela de aceleradores em ordem alfabética.

Você pode, em seguida, examine a lista e localize a entrada.

## <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada para uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. Clique dentro da tabela do acelerador e escolha **novo Acelerador** do menu de atalho, ou selecione a entrada de linha vazia na parte inferior da tabela.

1. Selecione um [identificação](id-property.md) na lista suspensa na ID de caixa ou digite uma nova ID no **ID** caixa.

1. Tipo de [chave](../windows/accelerator-key-property.md) você deseja usar como um acelerador ou o botão direito do mouse e escolha **próxima chave digitada** no menu de atalho para definir uma combinação de teclas (o **próxima chave digitada** comando é também disponível na **editar** menu).

1. Alterar o [modificador](../windows/accelerator-modifier-property.md) e [tipo](../windows/accelerator-type-property.md), se necessário.

1. Pressione **ENTER**.

   > [!NOTE]
   > Verifique se todos os aceleradores que você define são exclusivos. Você pode ter várias combinações de teclas atribuídas para a mesma ID com nenhum efeito mal, por exemplo, **Ctrl** + **P** e **F8** podem ser atribuídos ao ID_PRINT. No entanto, ter atribuída a mais de uma ID não funcionará bem, por exemplo, uma combinação de teclas **Ctrl** + **Z** atribuídas a ID_SPELL_CHECK e ID_THESAURUS.

## <a name="to-delete-an-entry-from-an-accelerator-table"></a>Para excluir uma entrada de uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. Selecione a entrada que você deseja excluir. (Mantenha pressionada a **Ctrl** ou **Shift** chave durante a seleção para escolher várias entradas.)

1. Clique com botão direito e escolha **exclua** no menu de atalho (ou selecione **excluir** do **editar** menu).

\- ou -

- Pressione a **excluir** chave.

## <a name="to-move-or-copy-an-accelerator-table-entry-to-another-resource-script-file"></a>Para mover ou copiar uma entrada de tabela de aceleradores para outro arquivo de script de recurso

1. Abra as tabelas de aceleradores em ambos os arquivos de script de recurso.

1. Selecione a entrada que você deseja mover.

1. Dos **edite** menu, escolha **cópia** ou **Recortar**.

1. Selecione uma entrada no arquivo de script de recurso de destino.

1. Dos **edite** menu, escolha **colar**.

   > [!NOTE]
   > Você também pode usar as teclas de atalho para copiar e colar.

## <a name="to-change-the-properties-of-multiple-accelerator-keys"></a>Para alterar as propriedades de várias teclas de aceleração

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

1. Selecione as teclas de aceleração que você deseja alterar, mantendo pressionada a **Ctrl** da chave conforme você seleciona cada uma delas.

1. Vá para o [janela de propriedades](/visualstudio/ide/reference/properties-window) e digite os valores que você deseja que todos os aceleradores selecionados para compartilhar.

   > [!NOTE]
   > Cada valor de modificador aparece como uma propriedade booleana na **propriedades** janela. Se você alterar uma [modificador](../windows/accelerator-modifier-property.md) o valor de **propriedades** janela, a tabela de aceleradores trata o novo modificador como uma adição a qualquer modificador que anteriormente estavam lá. Por isso, se você definir quaisquer valores do modificador, você precisará definir todas elas para garantir que cada Acelerador compartilha os mesmos **modificador** configurações.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de aceleradores](../windows/accelerator-editor.md)<br/>
[Editores de recursos](../windows/resource-editors.md)
