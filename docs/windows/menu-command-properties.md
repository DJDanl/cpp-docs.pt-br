---
title: "Propriedades do comando Menu | Microsoft Docs"
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
  - "itens de menu, propriedades"
ms.assetid: 6d308205-3c9e-42f2-ab42-45e656940e45
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Propriedades do comando Menu
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As informações a seguir são organizadas de acordo com as propriedades de Menu que aparecem no [janela propriedades](../Topic/Properties%20Window.md) quando você seleciona um comando de menu. Elas são listadas em ordem alfabética Embora a janela de propriedades também permite que você exibir essas propriedades por categoria.  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|**Quebra**|Pode ser um destes valores:<br /><br /> -   **Nenhum** \(padrão\): sem interrupções.<br />-   **Coluna**: para menus estáticos, esse valor coloca o comando de menu em uma nova linha. Para menus pop\-up, esse valor coloca o comando de menu em uma nova coluna com nenhuma linha divisória entre as colunas. A definição dessa propriedade afeta a aparência do menu apenas em tempo de execução, não no editor de menu.<br />-   **Barra**: mesmo que a coluna acima para menus pop\-up, esse valor separa a nova coluna da coluna antiga com uma linha vertical. A definição dessa propriedade afeta a aparência do menu apenas em tempo de execução, não no editor de Menu.|  
|**Legenda**|O texto que rotula o comando de menu \(o nome de menu\). Para tornar uma das letras na legenda de um menu de comando de tecla mnemônica, precedê\-lo com um e comercial \(&\).|  
|**Verificado**|Se for True, o comando de menu é marcado inicialmente. Tipo: Bool. Padrão: False.|  
|**Habilitado**|Se **False**, o item de menu está desativado.|  
|**Cinza**|Se for True, o comando de menu é inicialmente esmaecido e inativos. Tipo: Bool. Padrão: False.|  
|**Ajuda**|Alinha o item de menu à direita. Por exemplo, o **Ajuda** comando de menu é sempre à direita em todos os aplicativos do Windows. Se você definir essa propriedade em um item de menu, o item aparecerá muito à direita e no final do menu. Aplica\-se a itens de nível superior. Padrão: **False**.|  
|**ID**|Um símbolo definido no arquivo de cabeçalho. Tipo: Símbolo, inteiro ou cadeia de caracteres entre aspas. Você pode usar qualquer símbolo que é geralmente disponível em qualquer um dos editores, embora o [janela propriedades](../Topic/Properties%20Window.md) não fornece uma lista suspensa para selecionar de.|  
|**Pop\-up**|Se for True, o comando de menu é um menu pop\-up. Tipo: Bool. Padrão: True para menus de nível superior em uma barra de menu; Caso contrário, False.|  
|**Solicitar**|Contém o texto a ser exibido na barra de status quando esse comando de menu é realçado. O texto é colocado na tabela de cadeia de caracteres com o mesmo identificador que o comando de menu. Essa propriedade está disponível para qualquer tipo de projeto, mas a funcionalidade de tempo de execução é específico do MFC.|  
|**Justificar à direita para a esquerda**|Justifica à direita do comando de menu na barra de menus em tempo de execução. Tipo: Bool. Padrão: False.|  
|**Direita para esquerda ordem**|Permite que os comandos de menu para exibir da direita para a esquerda quando a interface foi traduzida para qualquer idioma que lê da direita para esquerda como hebraico ou árabe.|  
|**Separador**|Se for True, o comando de menu é um separador. Tipo: Bool. Padrão: False.|  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Editor de menu](../Topic/Menu%20Editor.md)