---
title: Associando um comando de Menu com uma tecla aceleradora | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts, menu association
- commands, associating menu commands with accelerator keys
- menu commands, associating with keyboard shortcuts
ms.assetid: ad2de43f-b20a-4c9f-bda8-0420179da48c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 79a16cf8d67fb7a6a45043c28455a7ed22f90ffa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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