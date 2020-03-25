---
title: Exibindo e manipulando dados em um formulário
ms.date: 11/04/2016
helpviewer_keywords:
- forms [C++], displaying data
- displaying data [C++], forms
- ODBC [C++], forms
- record views [C++], displaying data
- data [MFC]
- data [MFC], displaying in a form
ms.assetid: c56185c4-12cb-40b1-b499-02b29ea83e3a
ms.openlocfilehash: 6b663fabd0c87d9a2773e6f5a2796bcc8f57ce29
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213246"
---
# <a name="displaying-and-manipulating-data-in-a-form"></a>Exibindo e manipulando dados em um formulário

Muitos aplicativos de acesso a dados selecionam dados e os exibem em campos em um formulário. A classe de banco de dados [CRecordView](../../mfc/reference/crecordview-class.md) fornece a você um objeto [CFormView](../../mfc/reference/cformview-class.md) diretamente conectado a um objeto Recordset. A exibição de registro usa a [troca de dados de caixa de diálogo (campo DDX)](../../mfc/dialog-data-exchange-and-validation.md) para mover os valores dos campos do registro atual do conjunto de registros para os controles no formulário e para mover informações atualizadas de volta para o conjunto de registros. O conjunto de registros, por sua vez, usa o suporte RFX (Record Field Exchange) para mover dados entre seus membros de dados de campo e as colunas correspondentes em uma tabela na fonte de dados.

Você pode usar o assistente de aplicativo do MFC ou **Adicionar a classe** (conforme descrito em [adicionando um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) para criar a classe View e sua classe recordset associada em conjunto.

A exibição de registro e seu conjunto de registros são destruídos quando você fecha o documento. Para obter mais informações sobre exibições de registro, consulte [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre suporte RFX, consulte [Record Field Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

## <a name="see-also"></a>Confira também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)
