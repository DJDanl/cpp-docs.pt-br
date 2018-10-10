---
title: Adicionando uma propriedade (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interfaces, adding properties
- properties [C++], adding to interfaces
ms.assetid: 37bd4db7-efd3-4faa-87ad-64902ed16a36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bca3d282318217ad9d19c0576b933b45fcbc0b41
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393952"
---
# <a name="adding-a-property-visual-c"></a>Adicionando uma propriedade (Visual C++)

Use o [Assistente de Adição de Propriedade](../ide/names-add-property-wizard.md) para adicionar um método a uma interface no projeto.

### <a name="to-add-a-property-to-your-object"></a>Para adicionar uma propriedade ao objeto

1. Em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome da interface à qual você deseja adicionar a propriedade.

   > [!NOTE]
   > Adicione também propriedades a dispinterfaces, que estarão aninhadas no nó da biblioteca, a menos que o projeto esteja atribuído.

1. No menu de atalho, clique em **Adicionar** e, em seguida, em **Adicionar Propriedade**.

1. No [Assistente de Adição de Propriedade](../ide/names-add-property-wizard.md), forneça as informações para criar a propriedade.

1. Especifique as configurações de linguagem IDL para a propriedade na página [Atributos IDL](../ide/idl-attributes-add-property-wizard.md) do assistente.

1. Clique em **Concluir** para adicionar a propriedade.

Os métodos **Get** e `Put` da propriedade são exibidos como dois ícones em Modo de Exibição de Classe, abaixo da interface na qual ela está definida. Clique duas vezes em um dos ícones para exibir a declaração de propriedade no arquivo .idl.

- Para interfaces da ATL, as funções **Get** e **Put** são adicionadas ao arquivo .cpp, e as referências a essas funções são adicionadas ao arquivo .h.

- Para dispinterfaces MFC, se você selecionar **Variável de membro** como o tipo de implementação, um método e uma variável serão adicionados à classe que o implementa. Se você selecionar **métodos Get/Set** como o tipo de implementação, os dois métodos serão adicionados à classe que o implementa.

## <a name="see-also"></a>Consulte também

[Criando uma interface COM](../ide/creating-a-com-interface-visual-cpp.md)<br>
[Editando uma interface COM](../ide/editing-a-com-interface.md)<br>
[O Component Object Model](/windows/desktop/com/the-component-object-model)<br>
[Ponteiros de interface e interfaces](/windows/desktop/com/interface-pointers-and-interfaces)