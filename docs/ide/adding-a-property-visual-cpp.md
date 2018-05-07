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
ms.openlocfilehash: 45eda098202fdf9286905bdc967b6aa1d7bd7035
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adding-a-property-visual-c"></a>Adicionando uma propriedade (Visual C++)
Você pode usar o [Assistente para adição de propriedade](../ide/names-add-property-wizard.md) para adicionar um método para uma interface em seu projeto.  
  
### <a name="to-add-a-property-to-your-object"></a>Para adicionar uma propriedade ao seu objeto  
  
1.  Em [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome da interface para o qual você deseja adicionar a propriedade.  
  
    > [!NOTE]
    >  Você também pode adicionar propriedades ao dispinterfaces, que, a menos que o projeto é atribuído, são aninhados dentro do nó de biblioteca.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **adicionar propriedade**.  
  
3.  No [Assistente para adição de propriedade](../ide/names-add-property-wizard.md), forneça as informações para criar a propriedade.  
  
4.  Especifique quaisquer configurações de linguagem IDL de definição de interface para a propriedade no [atributos IDL](../ide/idl-attributes-add-property-wizard.md) página do assistente.  
  
5.  Clique em **concluir** para adicionar a propriedade.  
  
 O **obter** e `Put` métodos de propriedade são exibidos como dois ícones no modo de exibição de classe, a interface onde ele está definido. Clique duas vezes em um ícone para exibir a declaração de propriedade no arquivo. idl.  
  
-   Para interfaces ATL, o **obter** e **colocar** funções são adicionadas ao arquivo. cpp e referências a essas funções são adicionadas ao arquivo. h.  
  
-   Para dispinterfaces MFC, se você selecionar **variável membro** como o tipo de implementação, um método e uma variável são adicionados à classe que implementa. Se você selecionar **métodos Get/Set** como o tipo de implementação, os dois métodos são adicionados à classe que implementa.  
  
## <a name="see-also"></a>Consulte também  
 [Criando uma Interface COM](../ide/creating-a-com-interface-visual-cpp.md)   
 [Editando uma Interface COM](../ide/editing-a-com-interface.md)   
 [O modelo de objeto do componente](http://msdn.microsoft.com/library/windows/desktop/ms694363)   
 [Ponteiros de interface e Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms688484)