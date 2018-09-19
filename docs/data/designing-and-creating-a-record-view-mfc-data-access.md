---
title: Projetando e criando uma exibição do registro (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- designing forms
- record views, creating
- forms [C++], designing
- record views, designing
- application wizards [C++], creating record view classes
- designing record views
ms.assetid: 1d6f5439-754f-4b8b-a19d-841a4657827b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f0b984fdda988ce83fdf8eece0a8f6d11ddd6e94
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031477"
---
# <a name="designing-and-creating-a-record-view--mfc-data-access"></a>Projetando e criando uma exibição de registro (Acesso a dados MFC)

Você pode criar sua classe de exibição de registro com o [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md). Se você usar um assistente de aplicativo, ele criará a classe de exibição de registro e um recurso de modelo de diálogo para ele (sem controles). Você deve usar o editor de diálogo do Visual C++ para adicionar controles ao recurso de modelo de diálogo. Por outro lado, se você usar **Adicionar classe**, você deve primeiro criar o recurso de modelo de caixa de diálogo na caixa de diálogo editor e, em seguida, criar a classe de exibição do registro.  
  
  
#### <a name="to-create-your-record-view-with-the-mfc-application-wizard"></a>Para criar a exibição do registro com o Assistente de Aplicativo MFC  
  
1. Ver [suporte, o Assistente de aplicativo MFC de banco de dados](../mfc/reference/database-support-mfc-application-wizard.md).  
  
#### <a name="to-design-your-form"></a>Para criar o formulário  
  
1. Ver [Editor de caixa de diálogo](../windows/dialog-editor.md).  
  
#### <a name="to-create-your-record-view-class"></a>Para criar sua classe de exibição de registro  
  
1. Ver [adicionando um consumidor ODBC do MFC](../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
Os tópicos a seguir explicam os detalhes adicionais do uso de exibição de registro:  
  
- [Exibições de registro: Suportando navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)  
  
- [Exibições de registro: Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)  
  
- [Exibições de registro: Preenchendo uma caixa de listagem de um segundo conjunto de registros](../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md)  
  
## <a name="see-also"></a>Consulte também  

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Conjunto de registros (ODBC)](../data/odbc/recordset-odbc.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)