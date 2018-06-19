---
title: Exibindo e manipulando dados em um formulário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- forms [C++], displaying data
- displaying data [C++], forms
- ODBC [C++], forms
- record views [C++], displaying data
- data [MFC]
- data [MFC], displaying in a form
ms.assetid: c56185c4-12cb-40b1-b499-02b29ea83e3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3b86c58c8e5afb53cb02174beb3553378dd0efc8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089360"
---
# <a name="displaying-and-manipulating-data-in-a-form"></a>Exibindo e manipulando dados em um formulário
Muitos aplicativos de acesso a dados selecionam dados e exibem-lo em campos em um formulário. A classe de banco de dados [CRecordView](../../mfc/reference/crecordview-class.md) fornece um [CFormView](../../mfc/reference/cformview-class.md) objeto conectado diretamente a um objeto de conjunto de registros. Usa o modo de exibição de registro [troca de dados de caixa de diálogo (DDX)](../../mfc/dialog-data-exchange-and-validation.md) para mover os valores dos campos do registro atual do conjunto de registros para os controles no formulário e para mover as informações atualizadas de volta para o conjunto de registros. O conjunto de registros, por sua vez, usa a troca de campos de registro (RFX) para mover dados entre as colunas correspondentes em uma tabela e de seus membros de dados do campo na fonte de dados.  
  
 Você pode usar o Assistente de aplicativo do MFC ou **Adicionar classe** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) para criar a classe de exibição e sua classe de conjunto de registros associado em conjunto.  
  
 A exibição de registro e seu conjunto de registros são destruídos quando você fechar o documento. Para obter mais informações sobre exibições de registro, consulte [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre RFX, consulte [troca de campos de registro (RFX)](../../data/odbc/record-field-exchange-rfx.md).  
  
## <a name="see-also"></a>Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)