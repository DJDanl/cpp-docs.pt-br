---
title: "Associando um comando Menu a uma tecla de acelera&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atalhos de teclado, associação de menus"
  - "comandos, associando comandos de menu com teclas de aceleração"
  - "comandos de menu, associando a atalhos de teclado"
ms.assetid: ad2de43f-b20a-4c9f-bda8-0420179da48c
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Associando um comando Menu a uma tecla de acelera&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Geralmente há vezes que um comando de menu e uma combinação de teclado para emitir o mesmo comando do programa. Você pode fazer isso usando o editor de Menu para atribuir o mesmo identificador de recurso para o comando de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você edita o [legenda](../windows/menu-command-properties.md) do comando de menu para mostrar o nome da chave do acelerador.  
  
### Para associar um comando de menu com uma tecla de aceleração  
  
1.  No **Menu** editor, selecione o comando de menu que você deseja.  
  
2.  No [janela propriedades](../Topic/Properties%20Window.md), adicione o nome da tecla de aceleração para o **legenda** propriedade:  
  
    -   Após a legenda do menu, digite a seqüência de escape para uma tabulação \(\\t\), para que todas as que teclas de aceleração do menu ficam alinhados.  
  
    -   Digite o nome da chave de modificador \(**CTRL**, **ALT**, ou **SHIFT**\) seguido por um sinal de adição \(**\+**\) e o nome, letra ou símbolo da chave adicional.  
  
         Por exemplo, para atribuir **CTRL \+ O** para o **Abrir** comando o **arquivo** menu, modifique o comando de menu **legenda** para que ele seja semelhante a:  
  
        ```  
        &Open...\tCtrl+O   
        ```  
  
         O comando de menu no editor de Menu é atualizado para refletir a nova legenda conforme você digita.  
  
3.  [Criar a entrada de tabela de teclas aceleradoras](../windows/adding-an-entry-to-an-accelerator-table.md) no **Accelerator** editor e atribua a ele o mesmo identificador que o comando de menu. Use uma combinação de teclas que você acha que será fácil de lembrar.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Adicionando comandos a um menu](../Topic/Adding%20Commands%20to%20a%20Menu.md)   
 [Editor de menu](../Topic/Menu%20Editor.md)