---
title: Criando uma caixa de diálogo (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.dialog
helpviewer_keywords:
- dialog boxes [C++], creating
- Dialog Editor [C++], creating dialog boxes
- modal dialog boxes [C++], logon screens
- logon screens
ms.assetid: 303de801-c4f8-42e1-b622-353f6423f688
ms.openlocfilehash: 928432000fb9a6347433b78b224e15f07ce810d2
ms.sourcegitcommit: 52c05e10b503e834c443ef11e7ca1987e332f876
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2019
ms.locfileid: "55742642"
---
# <a name="creating-a-dialog-box-c"></a>Criando uma caixa de diálogo (C++)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-create-a-new-dialog-box"></a>Para criar uma nova caixa de diálogo

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **adicionar recurso** no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **adicionar recurso** caixa de diálogo, selecione **caixa de diálogo** no **tipo de recurso** lista e, em seguida, escolha **novo**.

   Se um sinal de adição (**+**) é exibido ao lado de **caixa de diálogo** tipo de recurso, isso significa que os modelos de caixa de diálogo estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

   A nova caixa de diálogo é aberta na **caixa de diálogo** editor.

   Você também pode [abrir caixas de diálogo existente no editor de caixa de diálogo para edição](../windows/viewing-and-editing-resources-in-a-resource-editor.md).

## <a name="to-create-a-dialog-box-that-a-user-cant-exit"></a>Para criar uma caixa de diálogo que um usuário não possam sair

Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de documento ou aplicativo.

1. No **propriedades** painel para a caixa de diálogo, defina as **Menu do sistema** propriedade a ser **false**.

   Essa configuração desabilita o menu de sistema de caixa de diálogo e **fechar** botão.

1. No formulário de caixa de diálogo, exclua o **cancele** e **Okey** botões.

   Em tempo de execução, um usuário não pode sair de uma caixa de diálogo modal que tem as seguintes características.

Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo test detecta quando **Esc** é pressionado. (**Esc** também é conhecido como a chave de virtual VK_ESCAPE.) Não importa como a caixa de diálogo é projetada para se comportar em tempo de execução, você pode encerrar o modo de teste pressionando **Esc**.

> [!NOTE]
> Para aplicativos do MFC para criar uma caixa de diálogo que os usuários não possam sair, você deve substituir o comportamento padrão do `OnOK` e `OnCancel` porque, mesmo se você excluir os botões associados, a caixa de diálogo ainda pode ser descartada, pressionando  **Insira** ou **Esc**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como: criar um recurso](../windows/how-to-create-a-resource.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)