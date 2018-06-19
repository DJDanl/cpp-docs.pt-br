---
title: Associando um comando de Menu com uma tecla aceleradora | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts, menu association
- commands, associating menu commands with accelerator keys
- menu commands, associating with keyboard shortcuts
ms.assetid: ad2de43f-b20a-4c9f-bda8-0420179da48c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c4f1aa4b80aec2e7c16485c08d2505695b21f4d5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33858069"
---
# <a name="associating-a-menu-command-with-an-accelerator-key"></a>Associando um comando Menu a uma tecla de aceleração
Geralmente há horários em que um comando de menu e uma combinação de teclado para emitir o mesmo comando do programa. Você pode fazer isso usando o editor de Menu para atribuir o mesmo identificador de recurso para o comando de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você edita o [legenda](../windows/menu-command-properties.md) do comando de menu para mostrar o nome da chave do acelerador.  
  
### <a name="to-associate-a-menu-command-with-an-accelerator-key"></a>Para associar um comando de menu com uma tecla de aceleração  
  
1.  No **Menu** editor, selecione o comando de menu que você deseja.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), adicione o nome da chave de aceleração para o **legenda** propriedade:  
  
    -   Após a legenda do menu, digite a sequência de escape para uma tabulação (\t), para que todas as que teclas de aceleração do menu são deixadas alinhadas.  
  
    -   Digite o nome da chave de modificador (**CTRL**, **ALT**, ou **SHIFT**) seguido por um sinal de adição (**+**) e o nome, uma letra, ou símbolo da chave adicional.  
  
         Por exemplo, para atribuir **CTRL + O** para o **abrir** comando o **arquivo** menu, modifique o comando de menu **legenda** para que ele se parece com Isso:  
  
        ```  
        &Open...\tCtrl+O   
        ```  
  
         O comando de menu no editor de Menu é atualizado para refletir a nova legenda conforme você digita.  
  
3.  [Criar a entrada da tabela de aceleradores](../windows/adding-an-entry-to-an-accelerator-table.md) no **Accelerator** editor e atribua a ele o mesmo identificador que o comando de menu. Use uma combinação de teclas que você acha que seja fácil de lembrar.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando comandos a um Menu](../windows/adding-commands-to-a-menu.md)   
 [Editor de Menu](../windows/menu-editor.md)