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
ms.openlocfilehash: 34fa9944d1daa443850454560f8e5741e881f6f8
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42598705"
---
# <a name="menu-command-properties"></a>Propriedades do comando Menu

As informações a seguir são organizadas de acordo com o **menus** as propriedades que aparecem na [janela propriedades](/visualstudio/ide/reference/properties-window) quando você seleciona um comando de menu. Eles estão listados em ordem alfabética, embora a **propriedades** janela também permite que você exibir essas propriedades por categoria.

|Propriedade|Descrição|
|--------------|-----------------|
|**quebra**|Pode ser um destes valores:<br /><br /> -   **Nenhum** (padrão): nenhuma quebra.<br />-   **Coluna**: para menus estáticos, esse valor coloca o comando de menu em uma nova linha. Para menus pop-up, esse valor coloca o comando de menu em uma nova coluna com nenhuma linha divisória entre as colunas. Definir essa propriedade afeta a aparência do menu apenas em tempo de execução, não no editor de menu.<br />-   **Barra**: igual **coluna** , exceto, para menus pop-up, esse valor separa a nova coluna de coluna antiga com uma linha vertical. Definir essa propriedade afeta a aparência do menu apenas em tempo de execução, não na **Menu** editor.|
|**Caption**|O texto que rotula o comando de menu (o nome do menu). Para fazer uma das letras na legenda de um menu de comando de uma tecla mnemônica, preceda-o com um e comercial (&).|
|**Verificado**|Se **verdadeira**, o comando de menu inicialmente é verificado. Tipo: **Bool**. Padrão: **falsos**.|
|**Habilitado**|Se **falsos**, o item de menu está desabilitado.|
|**Indisponível**|Se **verdadeira**, o comando de menu é inicialmente esmaecida e inativo. Tipo: **Bool**. Padrão: **falsos**.|
|**Ajuda**|Alinha o item de menu à direita. Por exemplo, o **ajudar** comando de menu é sempre à direita em todos os aplicativos do Windows. Se você definir essa propriedade em um item de menu, o item aparecerá muito à direita e no final do menu. Aplica-se a itens de nível superior. Padrão: **falsos**.|
|**ID**|Um símbolo definido no arquivo de cabeçalho. Tipo: **símbolo**, **inteiro**, ou **caracteres entre aspas**. Você pode usar qualquer símbolo que é geralmente disponível em qualquer um dos editores, mesmo que o [janela de propriedades](/visualstudio/ide/reference/properties-window) não fornece uma lista suspensa para seleção do.|
|**Pop-up**|Se **verdadeira**, o comando de menu é um menu pop-up. Tipo: **Bool**. Padrão: **verdadeira** menus de nível superior em da barra de menus; caso contrário **falso**.|
|**Solicitar**|Contém o texto a ser exibido na barra de status quando esse comando de menu é realçado. O texto é colocado na tabela de cadeia de caracteres com o mesmo identificador que o comando de menu. Essa propriedade está disponível para qualquer tipo de projeto, mas a funcionalidade de tempo de execução é específico do MFC.|
|**Justificar à direita para esquerda**|Justifica à direita o comando de menu na barra de menus em tempo de execução. Tipo: **Bool**. Padrão: **falsos**.|
|**Direita para esquerda ordem**|Permite que os comandos de menu a exibir da direita para a esquerda quando a interface está localizada para qualquer linguagem que lê da direita para a esquerda, como hebraico ou árabe.|
|**Separador**|Se **verdadeira**, o comando de menu é um separador. Tipo: **Bool**. Padrão: **falsos**.|

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)