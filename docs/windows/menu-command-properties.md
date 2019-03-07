---
title: Comandos de menu (C++)
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
ms.openlocfilehash: 62249bff7a278963ea67b2d2015ff52f22fcfc85
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562920"
---
# <a name="menu-commands-c"></a>Comandos de menu (C++)

As informações a seguir são organizadas de acordo com o **menus** as propriedades que aparecem na [janela propriedades](/visualstudio/ide/reference/properties-window) quando você seleciona um comando de menu. Eles estão listados em ordem alfabética, embora a **propriedades** janela também permite que você exibir essas propriedades por categoria.

|Propriedade|Descrição|
|--------------|-----------------|
|**Interromper**|Pode ser um destes valores:<br/>  - **Nenhum**: Sem quebra. Esse é o padrão.<br/>  - **Coluna**: Para menus estáticos, esse valor coloca o comando de menu em uma nova linha.<br/>      Para menus pop-up, esse valor coloca o comando de menu em uma nova coluna com nenhuma linha divisória entre as colunas.<br/>      Definir essa propriedade afeta a aparência do menu apenas em tempo de execução, não no editor de menu.<br />   - **Bar**: Mesmo que **coluna** , exceto, para menus pop-up, esse valor separa a nova coluna de coluna antiga com uma linha vertical.<br/>      Definir essa propriedade afeta a aparência do menu apenas em tempo de execução, não na **Editor de Menu**.|
|**Caption**|O texto que rotula o comando de menu (o nome do menu). Para fazer uma das letras na legenda de um menu de comando de uma tecla mnemônica, preceda-o com um e comercial (&).|
|**Verificado**|Se **verdadeira**, o comando de menu inicialmente é verificado. Tipo: **Bool**. Padrão: **False**.|
|**Habilitado**|Se **falsos**, o item de menu está desabilitado.|
|**Indisponível**|Se **verdadeira**, o comando de menu é inicialmente esmaecida e inativo. Tipo: **Bool**. Padrão: **False**.|
|**Ajuda**|Alinha o item de menu à direita. Padrão: **False**.<br/><br/>Por exemplo, o **ajudar** comando de menu é sempre à direita em todos os aplicativos do Windows. Se você definir essa propriedade em um item de menu, o item aparecerá muito à direita e no final do menu. Aplica-se a itens de nível superior.|
|**ID**|Um símbolo definido no arquivo de cabeçalho. Tipo: **Símbolo**, **inteiro**, ou **caracteres entre aspas**.<br/><br/>Você pode usar qualquer símbolo que é geralmente disponível em qualquer um dos editores, mesmo que o [janela de propriedades](/visualstudio/ide/reference/properties-window) não fornece uma lista suspensa para seleção do.|
|**Pop-up**|Se **verdadeira**, o comando de menu é um menu pop-up. Tipo: **Bool**. Padrão: **Verdadeiro** menus de nível superior em uma barra de menus, caso contrário **falso**.|
|**Solicitar**|Contém o texto a ser exibido na barra de status quando esse comando de menu é realçado. O texto é colocado na tabela de cadeia de caracteres com o mesmo identificador que o comando de menu.<br/><br/>Essa propriedade está disponível para qualquer tipo de projeto, mas a funcionalidade de tempo de execução é específico do MFC.|
|**Justificar à direita para esquerda**|Justifica à direita o comando de menu na barra de menus em tempo de execução. Tipo: **Bool**. Padrão: **False**.|
|**Direita para esquerda ordem**|Permite que os comandos de menu a exibir da direita para a esquerda quando a interface está localizada para qualquer linguagem que lê da direita para a esquerda, como hebraico ou árabe.|
|**Separador**|Se **verdadeira**, o comando de menu é um separador. Tipo: **Bool**. Padrão: **False**.|

## <a name="associate-menu-commands"></a>Associar comandos de Menu

Geralmente, há vezes que deseja que um comando de menu e uma combinação de teclado para emitir o mesmo comando do programa. Comandos idênticos são emitidos usando o **Editor de Menu** para atribuir o mesmo identificador de recurso para o comando de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você, em seguida, edite o [legenda](../windows/menu-command-properties.md) o comando de menu para mostrar o nome da chave do acelerador.

### <a name="to-associate-a-menu-command-with-an-accelerator-key"></a>Para associar um comando de menu com uma tecla de aceleração

1. No **Editor de Menu**, selecione o comando de menu que você deseja.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), adicione o nome da chave do acelerador para o **legenda** propriedade:

   - Após a legenda do menu, digite a sequência de escape para uma tabulação (\t), para que todas as que teclas de aceleração do menu ficam alinhados.

   - Digite o nome da chave de modificador (**Ctrl**, **Alt**, ou **Shift**) seguido por um sinal de adição (**+**) e o nome, uma letra, ou símbolo da chave adicional.

   Por exemplo, para atribuir **Ctrl**+**s** para o **abertos** comando o **arquivo** menu, modificar o comando de menu  **Legenda** para que ele se parece com o seguinte texto:

   ```
   &Open...\tCtrl+O
   ```

   O comando de menu na **Editor de Menu** é atualizada para refletir a nova legenda conforme você o digita.

1. [Criar a entrada de tabela de aceleradores](../windows/adding-an-entry-to-an-accelerator-table.md) no **Accelerator** editor e atribua a ele o mesmo identificador que o comando de menu. Use uma combinação de teclas que você acha que será fácil de lembrar.

Seu aplicativo do MFC pode exibir o texto descritivo para cada um dos comandos de menu, que um usuário pode selecionar. Exibir o texto descritivo, atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade no **propriedades** janela. Se você tiver uma cadeia de caracteres na [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC exibirá automaticamente esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando um usuário passa o mouse sobre um item de menu.

- Para associar um comando de menu com um cadeia de caracteres de texto em aplicativos MFC, da barra de status na **Editor de Menu**, selecione o comando de menu. No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associado na **Prompt** caixa.

Em um projeto do C++, você pode atribuir uma chave de acesso (um mnemônico que permite ao usuário selecionar o menu com o teclado) para seus menus e comandos de menu.

- Para atribuir uma chave de acesso (atalho) a um comando de menu, digite um e comercial (`&`) na frente de uma letra no nome do menu ou nome do comando para especificar essa letra como a chave de acesso correspondente. 

   Por exemplo, "& do arquivo" conjuntos **Alt**+**F** como a tecla de atalho para o **arquivo** menu em aplicativos escritos para Microsoft Windows.

   O item de menu fornecerá uma indicação visível de que uma das letras tenha uma tecla de atalho atribuída a ele. A seguinte letra que o e comercial será exibido sublinhado (contingente no sistema operacional).

> [!NOTE]
> Verifique se todas as chaves de acesso em um menu são exclusivas, menu do botão direito do mouse e escolhendo **Verificar mnemônicos**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)<br/>

<!--
[Strings (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>-->