---
title: Propriedades do comando de menu | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- menu items, properties
ms.assetid: 6d308205-3c9e-42f2-ab42-45e656940e45
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 343c1ce255a26753c2b125d2a0a53e04808a0233
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="menu-command-properties"></a>Propriedades do comando Menu
As informações a seguir são organizadas de acordo com as propriedades de Menu que aparecem no [janela propriedades](/visualstudio/ide/reference/properties-window) quando você seleciona um comando de menu. Eles estão listados em ordem alfabética Embora a janela Propriedades também permite que você exibir essas propriedades por categoria.  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|**Quebra**|Pode ser um destes valores:<br /><br /> -   **Nenhum** (padrão): sem quebra.<br />-   **Coluna**: menus estáticos, esse valor coloca o comando de menu em uma nova linha. Menus pop-up, esse valor coloca o comando de menu em uma nova coluna com nenhuma linha divisória entre as colunas. A definição dessa propriedade afeta a aparência do menu somente em tempo de execução, não no editor de menu.<br />-   **Barra**: mesmo que a coluna exceto, menus pop-up, esse valor separa a nova coluna de coluna antiga com uma linha vertical. A definição dessa propriedade afeta a aparência do menu somente em tempo de execução, não no editor de Menu.|  
|**Legenda**|O texto que rotula o comando de menu (o nome de menu). Para fazer uma das letras na legenda de um menu de comando de tecla mnemônica, preceda-o com um e comercial (&).|  
|**Verificado**|Se for True, o comando de menu está marcado inicialmente. Tipo: Bool. Padrão: False.|  
|**Habilitado**|Se **False**, o item de menu está desabilitado.|  
|**Cinza**|Se for True, o comando de menu é inicialmente esmaecida e inativa. Tipo: Bool. Padrão: False.|  
|**Ajuda**|Alinha o item de menu à direita. Por exemplo, o **ajuda** comando de menu é sempre à direita em todos os aplicativos do Windows. Se você definir essa propriedade em um item de menu, o item aparecerá muito à direita e no final do menu. Aplica-se a itens de nível superior. Padrão: **False**.|  
|**ID**|Um símbolo definido no arquivo de cabeçalho. Tipo: Símbolo, inteiro ou cadeia de caracteres entre aspas. Você pode usar qualquer símbolo que é geralmente disponível em qualquer um dos editores, mesmo que o [janela propriedades](/visualstudio/ide/reference/properties-window) não fornece uma lista suspensa para selecionar em.|  
|**Pop-up**|Se for True, o comando de menu é um menu pop-up. Tipo: Bool. Padrão: True para os menus de nível superior em uma barra de menus; Caso contrário, False.|  
|**prompt**|Contém o texto a ser exibido na barra de status quando esse comando de menu é realçado. O texto é colocado na tabela de cadeia de caracteres com o mesmo identificador que o comando de menu. Essa propriedade está disponível para qualquer tipo de projeto, mas a funcionalidade de tempo de execução é específico do MFC.|  
|**Justificar à direita para esquerda**|Justifica o comando de menu na barra de menus em tempo de execução. Tipo: Bool. Padrão: False.|  
|**Direita para esquerda ordem**|Permite que os comandos de menu a ser exibido da direita para a esquerda quando a interface está localizada em qualquer linguagem que lê da direita para esquerda como hebraico ou árabe.|  
|**Separador**|Se for True, o comando de menu é um separador. Tipo: Bool. Padrão: False.|  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)