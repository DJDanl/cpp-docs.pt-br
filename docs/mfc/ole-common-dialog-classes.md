---
title: Classes de caixa de diálogo comuns OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.ole
dev_langs:
- C++
helpviewer_keywords:
- ActiveX classes [MFC]
- dialog classes [MFC], OLE
- OLE common dialog classes [MFC]
- common dialog classes [MFC]
ms.assetid: 706526ae-f94f-4909-a0f8-6b5fe954fd97
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2e3cedbe3cd08a425bd2bde2b4a6ca8c5a493c72
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ole-common-dialog-classes"></a>Classes de caixa de diálogo comuns OLE
Essas classes lidar com tarefas comuns de OLE com a implementação de um número de caixas de diálogo OLE padrão. Eles também fornecem uma interface de usuário consistente para a funcionalidade OLE.  
  
 [COleDialog](../mfc/reference/coledialog-class.md)  
 Usado pelo framework para conter implementações comuns para todas as caixas de diálogo OLE. Todas as classes de caixa de diálogo na categoria de interface do usuário são derivadas desta classe base. `COleDialog` não pode ser usada diretamente.  
  
 [COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)  
 Exibe a caixa de diálogo Inserir objeto, a interface de usuário padrão para inserir novos OLE vinculados ou incorporados itens.  
  
 [COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)  
 Exibe a caixa de diálogo Colar especial, a interface de usuário padrão para implementar o comando Editar Colar especial.  
  
 [COleLinksDialog](../mfc/reference/colelinksdialog-class.md)  
 Exibe a caixa de diálogo Editar Links, a interface de usuário padrão para modificar informações sobre itens vinculados.  
  
 [COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)  
 Exibe a caixa de diálogo Alterar ícone, a interface de usuário padrão para alterar o ícone associado a uma OLE inserido ou item vinculado.  
  
 [COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)  
 Exibe a caixa de diálogo Converter, a interface de usuário padrão para converter itens OLE de um tipo para outro.  
  
 [COlePropertiesDialog](../mfc/reference/colepropertiesdialog-class.md)  
 Encapsula a caixa de diálogo de propriedades OLE comuns do Windows. Caixas de diálogo comuns OLE propriedades fornecem uma maneira fácil de exibir e modificar as propriedades de um item do documento OLE de maneira consistente com os padrões do Windows.  
  
 [COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md)  
 Exibe a caixa de diálogo de atualização, a interface de usuário padrão para a atualização de todos os links em um documento. A caixa de diálogo contém um indicador de progresso para indicar como fechar o procedimento de atualização até a conclusão.  
  
 [COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)  
 Exibe a caixa de diálogo Alterar origem, a interface de usuário padrão para alterar o destino ou origem de um link.  
  
 [COleBusyDialog](../mfc/reference/colebusydialog-class.md)  
 Exibe as caixas de diálogo servidor ocupado e o servidor não responder, a interface de usuário padrão para lidar com chamadas para aplicativos ocupados. Normalmente são exibidos automaticamente pelo `COleMessageFilter` implementação.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

