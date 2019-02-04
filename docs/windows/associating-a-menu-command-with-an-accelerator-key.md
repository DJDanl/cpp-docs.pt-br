---
title: Associando comandos de Menu (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- keyboard shortcuts [C++], menu association
- commands [C++], associating menu commands with accelerator keys
- menu commands [C++], associating with keyboard shortcuts
- status bars [C++], associating menu items
- menus [C++], status bar text
- access keys [C++], checking
- menus [C++], shortcut keys
- keyboard shortcuts [C++], command assignments
- access keys [C++], assigning
- mnemonics [C++], adding to menus
- keyboard shortcuts [C++], uniqueness checking
- mnemonics [C++], uniqueness checking
- Check Mnemonics command
ms.assetid: ad2de43f-b20a-4c9f-bda8-0420179da48c
ms.openlocfilehash: f72fe5de3ef29b9575ef1a3138d4d114d7470fee
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55703032"
---
# <a name="associating-menu-commands-c"></a>Associando comandos de Menu (C++)

Geralmente, há vezes que deseja que um comando de menu e uma combinação de teclado para emitir o mesmo comando do programa. Comandos idênticos são emitidos usando o **Menu** editor para atribuir o mesmo identificador de recurso para o comando de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você, em seguida, edite o [legenda](../windows/menu-command-properties.md) o comando de menu para mostrar o nome da chave do acelerador.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-associate-a-menu-command-with-an-accelerator-key"></a>Para associar um comando de menu com uma tecla de aceleração

1. No **Menu** editor, selecione o comando de menu que você deseja.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), adicione o nome da chave do acelerador para o **legenda** propriedade:

   - Após a legenda do menu, digite a sequência de escape para uma tabulação (\t), para que todas as que teclas de aceleração do menu ficam alinhados.

   - Digite o nome da chave de modificador (**Ctrl**, **Alt**, ou **Shift**) seguido por um sinal de adição (**+**) e o nome, uma letra, ou símbolo da chave adicional.

       Por exemplo, para atribuir **Ctrl**+**s** para o **abertos** comando o **arquivo** menu, modificar o comando de menu  **Legenda** para que ele se parece com o seguinte texto:

        ```
        &Open...\tCtrl+O
        ```

       O comando de menu na **Menu** editor é atualizado para refletir a nova legenda conforme você o digita.

1. [Criar a entrada de tabela de aceleradores](../windows/adding-an-entry-to-an-accelerator-table.md) no **Accelerator** editor e atribua a ele o mesmo identificador que o comando de menu. Use uma combinação de teclas que você acha que será fácil de lembrar.

## <a name="to-associate-a-menu-command-with-a-status-bar-text-string-in-mfc-applications"></a>Para associar um comando de menu com um cadeia de caracteres de texto em aplicativos MFC da barra de status

Seu aplicativo do MFC pode exibir o texto descritivo para cada um dos comandos de menu, que um usuário pode selecionar. Exibir o texto descritivo, atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade no **propriedades** janela. Se você tiver uma cadeia de caracteres na [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC exibirá automaticamente esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando um usuário passa o mouse sobre um item de menu.

1. No **Menu** editor, selecione o comando de menu.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associado na **Prompt** caixa.

> [!NOTE]
> Esse conjunto de etapas exige MFC.

## <a name="to-assign-an-access-shortcut-key-to-a-menu-command"></a>Para atribuir uma chave de acesso (atalho) a um comando de menu

Em um projeto do C++, você pode atribuir uma chave de acesso (um mnemônico que permite ao usuário selecionar o menu com o teclado) para seus menus e comandos de menu.

Digite um e comercial (`&`) na frente de uma letra no nome do menu ou nome do comando para especificar essa letra como a chave de acesso correspondente. Por exemplo, "& do arquivo" conjuntos **Alt**+**F** como a tecla de atalho para o **arquivo** menu em aplicativos escritos para Microsoft Windows.

   O item de menu fornecerá uma indicação visível de que uma das letras tenha uma tecla de atalho atribuída a ele. A seguinte letra que o e comercial será exibido sublinhado (contingente no sistema operacional).

   > [!NOTE]
   > Verifique se todas as chaves de acesso em um menu são exclusivas, menu do botão direito do mouse e escolhendo **Verificar mnemônicos** no menu de atalho.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)<br/>
[Adicionando comandos a um menu](../windows/adding-commands-to-a-menu.md)<br/>
[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
