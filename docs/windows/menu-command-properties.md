---
title: Comandos de menuC++()
ms.date: 02/15/2019
helpviewer_keywords:
- menu items, properties
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
ms.assetid: 6d308205-3c9e-42f2-ab42-45e656940e45
ms.openlocfilehash: 33b1260d088008a94d935f7e4fd7c18b0dd249e3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167934"
---
# <a name="menu-commands-c"></a>Comandos de menuC++()

As informações abaixo são organizadas de acordo com as propriedades do **menu** que aparecem na [janela Propriedades](/visualstudio/ide/reference/properties-window) quando você seleciona um comando de menu. Eles são listados em ordem alfabética, embora a janela **Propriedades** também permita que você exiba essas propriedades por categoria.

|Propriedade|DESCRIÇÃO|
|--------------|-----------------|
|**Interromper**|Pode ser um destes valores:<br/>  - **nenhum**: sem interrupção. Esse é o padrão.<br/>  - **coluna**: para menus estáticos, esse valor coloca o comando de menu em uma nova linha.<br/>      Para menus pop-up, esse valor coloca o comando de menu em uma nova coluna sem linha de divisão entre as colunas.<br/>      Definir essa propriedade afeta a aparência do menu somente em tempo de execução, não no editor de menu.<br />   **barra**de - : igual à **coluna** , exceto para menus pop-up, esse valor separa a nova coluna da coluna antiga com uma linha vertical.<br/>      Definir essa propriedade afeta a aparência do menu somente em tempo de execução, não no **Editor de menu**.|
|**Caption**|O texto que rotula o comando de menu (o nome do menu). Para tornar uma das letras da legenda de um comando de menu a chave mnemônico, preceda-a com um e comercial (&).|
|**Check**|Se **for true**, o comando de menu será inicialmente marcado. Tipo: **bool**. Padrão: **false**.|
|**Enabled**|Se for **false**, o item de menu será desabilitado.|
|**Esmaecido**|Se for **true**, o comando de menu estará inicialmente esmaecido e inativo. Tipo: **bool**. Padrão: **false**.|
|**Ajuda**|Alinha o item de menu à direita. Padrão: **false**.<br/><br/>Por exemplo, o comando de menu **ajuda** está sempre à direita em todos os aplicativos do Windows. Se você definir essa propriedade em um item de menu, esse item será exibido na extrema direita e no final do menu. Aplica-se a itens de nível superior.|
|**ID**|Um símbolo definido no arquivo de cabeçalho. Tipo: **símbolo**, **inteiro**ou **cadeia de caracteres entre aspas**.<br/><br/>Você pode usar qualquer símbolo que esteja normalmente disponível em qualquer um dos editores, mesmo que a [janela Propriedades](/visualstudio/ide/reference/properties-window) não forneça uma lista suspensa na qual você possa selecionar.|
|**Pop-up**|Se for **true**, o comando de menu será um menu pop-up. Tipo: **bool**. Padrão: **true** para menus de nível superior em uma barra de menus; caso contrário, **false**.|
|**Prompt**|Contém o texto a ser exibido na barra de status quando este comando de menu é realçado. O texto é colocado na tabela de cadeia de caracteres com o mesmo identificador do comando de menu.<br/><br/>Essa propriedade está disponível para qualquer tipo de projeto, mas a funcionalidade de tempo de execução é específica do MFC.|
|**Da direita para a esquerda justificar**|Justifica à direita o comando de menu na barra de menus em tempo de execução. Tipo: **bool**. Padrão: **false**.|
|**Ordem da direita para a esquerda**|Permite que os comandos de menu sejam exibidos da direita para a esquerda quando a interface é localizada em qualquer idioma que lê da direita para a esquerda, como hebraico ou árabe.|
|**Separador**|Se for **true**, o comando de menu será um separador. Tipo: **bool**. Padrão: **false**.|

## <a name="associate-menu-commands"></a>Associar comandos de menu

Geralmente, há ocasiões em que você deseja que um comando de menu e uma combinação de teclado emitam o mesmo comando de programa. Comandos idênticos são emitidos usando o **Editor de menu** para atribuir o mesmo identificador de recurso ao comando de menu e a uma entrada na tabela de acelerador do aplicativo. Em seguida, edite a [legenda](../windows/menu-command-properties.md) do comando de menu para mostrar o nome da tecla aceleradora.

### <a name="to-associate-a-menu-command-with-an-accelerator-key"></a>Para associar um comando de menu a uma tecla aceleradora

1. No **Editor de menu**, selecione o comando de menu desejado.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), adicione o nome da tecla acelerada à propriedade **legenda** :

   - Seguindo a legenda do menu, digite a sequência de escape para uma tabulação (\t), de modo que todas as teclas de aceleração do menu sejam alinhadas à esquerda.

   - Digite o nome da tecla modificadora (**Ctrl**, **ALT**ou **Shift**) seguido por um sinal de adição ( **+** ) e o nome, a letra ou o símbolo da chave adicional.

   Por exemplo, para atribuir **Ctrl**+**o** ao comando **abrir** no menu **arquivo** , modifique a **legenda** do comando de menu para que fique semelhante ao seguinte texto:

   ```
   &Open...\tCtrl+O
   ```

   O comando de menu no **Editor de menu** é atualizado para refletir a nova legenda à medida que você digita.

1. [Crie a entrada Accelerator-Table](../windows/adding-an-entry-to-an-accelerator-table.md) no editor de **acelerador** e atribua-o ao mesmo identificador que o comando de menu. Use uma combinação de teclas que você ache que será fácil de lembrar.

Seu aplicativo MFC pode exibir texto descritivo para cada um dos comandos de menu que um usuário pode selecionar. Exiba o texto descritivo atribuindo uma cadeia de texto a cada comando de menu usando a propriedade **prompt** na janela **Propriedades** . Se você tiver uma cadeia de caracteres na [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é igual ao comando, um aplicativo MFC exibirá automaticamente esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando um usuário passar o mouse sobre um item de menu.

- Para associar um comando de menu a uma cadeia de caracteres de texto da barra de status em aplicativos MFC, no **Editor de menu**, selecione o comando de menu. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associada na caixa **prompt** .

Em um C++ projeto do, você pode atribuir uma tecla de acesso (um mnemônico que permite ao usuário selecionar o menu com o teclado) para seus menus e comandos de menu.

- Para atribuir uma chave de acesso (atalho) a um comando de menu, digite um e comercial (`&`) na frente de uma letra no nome do menu ou no nome do comando para especificar essa letra como a chave de acesso correspondente.

   Por exemplo, "& arquivo" define **Alt**+**F** como a tecla de atalho para o menu **arquivo** em aplicativos escritos para o Microsoft Windows.

   O item de menu fornecerá uma indicação visível de que uma das letras tem uma tecla de atalho atribuída a ela. A letra após o e comercial aparecerá sublinhada (contingente no sistema operacional).

> [!NOTE]
> Verifique se todas as chaves de acesso em um menu são exclusivas clicando com o botão direito do mouse no menu e escolhendo **verificar mnemônicos**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editor de Menu](../windows/menu-editor.md)

<!--
[Strings (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>-->
