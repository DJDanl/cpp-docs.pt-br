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
ms.openlocfilehash: 1694d9cbc770e02c550891fc83c1cc0a9f64824a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50517787"
---
# <a name="displaying-and-manipulating-data-in-a-form"></a>Exibindo e manipulando dados em um formulário

Muitos aplicativos de acesso a dados selecionam dados e exibem-los em campos em um formulário. A classe de banco de dados [CRecordView](../../mfc/reference/crecordview-class.md) lhe dá uma [CFormView](../../mfc/reference/cformview-class.md) objeto conectado diretamente a um objeto de conjunto de registros. Usa o modo de exibição de registro [troca de dados de caixa de diálogo (DDX)](../../mfc/dialog-data-exchange-and-validation.md) para mover os valores dos campos do registro atual do conjunto de registros para os controles no formulário e para mover as informações atualizadas de volta para o conjunto de registros. O conjunto de registros, por sua vez, usa a troca de campos de registro (RFX) para mover dados entre seus membros de dados de campo e as colunas correspondentes em uma tabela na fonte de dados.

Você pode usar o Assistente de aplicativo do MFC ou **Add Class** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) para criar a classe de exibição e sua classe de conjunto de registros associado em conjunto.

A exibição do registro e seu conjunto de registros são destruídos quando você fechar o documento. Para obter mais informações sobre exibições de registro, consulte [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter mais informações sobre RFX, consulte [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).

## <a name="see-also"></a>Consulte também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)