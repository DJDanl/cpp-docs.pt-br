---
title: Associando um comando de Menu uma tecla de aceleração (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts [C++], menu association
- commands [C++], associating menu commands with accelerator keys
- menu commands [C++], associating with keyboard shortcuts
ms.assetid: ad2de43f-b20a-4c9f-bda8-0420179da48c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: da9807e552590513116a7a09a58609b2b576efcc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379730"
---
# <a name="associating-a-menu-command-with-an-accelerator-key-c"></a>Associando um comando de Menu uma tecla de aceleração (C++)

Geralmente, há vezes que deseja que um comando de menu e uma combinação de teclado para emitir o mesmo comando do programa. Você pode fazer isso usando o **Menu** editor para atribuir o mesmo identificador de recurso para o comando de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você, em seguida, edite o [legenda](../windows/menu-command-properties.md) o comando de menu para mostrar o nome da chave do acelerador.

### <a name="to-associate-a-menu-command-with-an-accelerator-key"></a>Para associar um comando de menu com uma tecla de aceleração

1. No **Menu** editor, selecione o comando de menu que você deseja.

2. No [janela de propriedades](/visualstudio/ide/reference/properties-window), adicione o nome da chave do acelerador para o **legenda** propriedade:

   - Após a legenda do menu, digite a sequência de escape para uma tabulação (\t), para que todas as que teclas de aceleração do menu ficam alinhados.

   - Digite o nome da chave de modificador (**Ctrl**, **Alt**, ou **Shift**) seguido por um sinal de adição (**+**) e o nome, uma letra, ou símbolo da chave adicional.

       Por exemplo, para atribuir **Ctrl**+**s** para o **abertos** comando o **arquivo** menu, modificar o comando de menu  **Legenda** para que ele tem esta aparência:

        ```
        &Open...\tCtrl+O
        ```

       O comando de menu na **Menu** editor é atualizado para refletir a nova legenda conforme você o digita.

3. [Criar a entrada de tabela de aceleradores](../windows/adding-an-entry-to-an-accelerator-table.md) no **Accelerator** editor e atribua a ele o mesmo identificador que o comando de menu. Use uma combinação de teclas que você acha que será fácil de lembrar.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Adicionando comandos a um menu](../windows/adding-commands-to-a-menu.md)<br/>
[Editor de Menu](../windows/menu-editor.md)