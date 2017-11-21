---
title: "Registre o código de exibição criado pelo Assistente de aplicativo (MFC acesso a dados) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- application wizards [C++], record view code
- record views, refreshing controls
- record views, application wizard code
ms.assetid: 18fd4703-5939-491d-b759-985f767b951f
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a9475dd6192eb6bc1abd00e3614c18482be415c8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="record-view-code-created-by-application-wizard--mfc-data-access"></a>Código criado pelo assistente de aplicativo (Acesso a dados MFC)
O [Assistente de aplicativo MFC](../mfc/reference/database-support-mfc-application-wizard.md) substitui o modo de exibição `OnInitialUpdate` e `OnGetRecordset` funções de membro. Depois que a estrutura cria a janela do quadro, o documento e a exibição, ela chama `OnInitialUpdate` para inicializar a exibição. `OnInitialUpdate` obtém um ponteiro para o conjunto de registros do documento. Uma chamada para a classe base [CView::OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) função abre o conjunto de registros. O código a seguir mostra esse processo para uma `CRecordView`:  
  
```  
void CSectionForm::OnInitialUpdate()  
{  
   m_pSet = &GetDocument()->m_sectionSet;  
   CRecordView::OnInitialUpdate();  
}  
```  
  
 Quando o conjunto de registros é aberto, ele seleciona os registros. [CRecordset::Open](../mfc/reference/crecordset-class.md#open) torna o primeiro registro, o registro atual e DDX move dados de membros de dados de campo do conjunto de registros para o correspondente controles de formulário no modo de exibição. Para obter mais informações sobre RFX, consulte [troca de campos de registro (RFX)](../data/odbc/record-field-exchange-rfx.md). Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre o processo de criação de documento/exibição, consulte [usando as Classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).  
  
> [!NOTE]
>  Você deve dar aos usuários finais a capacidade de atualizar os controles de exibição de registro a partir do conjunto de registros. Sem esse recurso, se um usuário alterar o valor de um controle com um valor inválido, o usuário pode ficar permanentemente preso no registro atual. Para atualizar os controles, você deve chamar o `CWnd` função de membro [UpdateData](../mfc/reference/cwnd-class.md#updatedata) com um parâmetro de **FALSE**.  
  
## <a name="see-also"></a>Consulte também  
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)