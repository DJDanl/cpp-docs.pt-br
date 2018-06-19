---
title: Troca de dados para exibições de registro (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- RFX (record field exchange), data exchange mechanism
- RFX (record field exchange), record views
- record views, data exchange
- DDX (dialog data exchange), record views
- RFX (record field exchange)
ms.assetid: abc52ca7-6997-47a7-98f3-f347f52b1f72
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 58bda2d9a712e38951b8201c08e5bbbe369537eb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089405"
---
# <a name="data-exchange-for-record-views---mfc-data-access"></a>Troca de dados para exibições de registro (Acesso a dados MFC)
Quando você usa [Adicionar classe](../mfc/reference/adding-an-mfc-odbc-consumer.md) para mapear os controles no recurso de modelo de caixa de diálogo da exibição de um registro para os campos de um conjunto de registros, a estrutura gerencia a troca de dados em ambas as direções — do conjunto de registros para controles e de controles para o conjunto de registros. O uso do mecanismo DDX significa que você não precisa escrever o código para transferir os dados de um para outro lado por conta própria.  
  
 DDX para exibições de registro funciona em conjunto com [RFX](../data/odbc/record-field-exchange-rfx.md) para conjuntos de registros da classe `CRecordset` (ODBC).  RFX move dados entre o registro atual da fonte de dados e os membros de dados do campo de um objeto de conjunto de registros. DDX move os dados de membros de dados de campo para os controles no formulário. Essa combinação preenche os controles do formulário inicialmente e conforme o usuário é movido de registro em registro. Ela também pode mover dados atualizados de volta ao conjunto de registros e, em seguida, para a fonte de dados.  
  
 A figura a seguir mostra a relação entre DDX e RFX para exibições de registro.  
  
 ![Caixa de diálogo&#45;troca de dados e o registro&#45;a troca de campos](../data/media/vc37xt1.gif "vc37xt1")  
Troca de dados de diálogo e troca de campos de registro  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md). Para obter mais informações sobre RFX, consulte [troca de campos de registro (RFX)](../data/odbc/record-field-exchange-rfx.md).  
  
## <a name="see-also"></a>Consulte também  
 [Exibições de registro (acesso a dados MFC)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)