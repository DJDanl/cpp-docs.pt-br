---
title: Classes ODBC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.data
dev_langs:
- C++
helpviewer_keywords:
- database classes [MFC], ODBC
- ODBC classes [MFC]
ms.assetid: 6c40fca8-3033-4873-9abe-7f51725de0e0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 33fcc3453d36a2567330f60cec73383f842210c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="odbc-classes"></a>Classes ODBC
Essas classes de trabalhar com as outras classes de estrutura de aplicativo para fornecer acesso fácil a uma ampla variedade de bancos de dados para os quais os drivers de conectividade de banco de dados aberto (ODBC) estão disponíveis.  
  
 Programas que usam bancos de dados ODBC terá pelo menos um `CDatabase` objeto e um `CRecordset` objeto.  
  
 [CDatabase](../mfc/reference/cdatabase-class.md)  
 Encapsula uma conexão a uma fonte de dados, por meio do qual você pode operar na fonte de dados.  
  
 [CRecordset](../mfc/reference/crecordset-class.md)  
 Encapsula um conjunto de registros selecionados de uma fonte de dados. Conjuntos de registros Habilitar rolagem de registro para registro, atualizar registros (adicionando, editando e excluindo registros), a seleção de qualificação com um filtro, classificação da seleção e parametrizando a seleção com informações obtidas ou calculados em tempo de execução.  
  
 [CRecordView](../mfc/reference/crecordview-class.md)  
 Fornece um formulário de exibição conectada diretamente a um objeto de conjunto de registros. Os dados de caixa de diálogo (DDX) mecanismo troca dados entre o conjunto de registros e os controles de exibição de registro do exchange. Como todos os modos de exibição de formulário, uma exibição de registro com base em um recurso de modelo de caixa de diálogo. Exibições de registro também oferecem suporte a movimentação de registro para registro no conjunto de registros, atualizando os registros e fechar o conjunto de registros associado quando fecha o modo de exibição do registro.  
  
 [CDBException](../mfc/reference/cdbexception-class.md)  
 Uma exceção resultante de falhas no acesso a dados do processamento. Essa classe tem a mesma finalidade como outras classes de exceção no mecanismo de tratamento de exceção da biblioteca de classes.  
  
 [CFieldExchange](../mfc/reference/cfieldexchange-class.md)  
 Fornece informações de contexto para dar suporte à troca de campos de registro (RFX), que troca dados entre os membros de dados de campo e membros de dados de parâmetro de um objeto de conjunto de registros e as colunas da tabela correspondente na fonte de dados. Semelhante à classe [CDataExchange](../mfc/reference/cdataexchange-class.md), que é usado da mesma forma para troca de dados de caixa de diálogo (DDX).  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CLongBinary](../mfc/reference/clongbinary-class.md)  
 Encapsula um identificador para o armazenamento para um objeto binário grande (BLOB), como um bitmap. `CLongBinary`objetos são usados para gerenciar objetos de grandes dados armazenados nas tabelas de banco de dados.  
  
 [CDBVariant](../mfc/reference/cdbvariant-class.md)  
 Permite que você armazene um valor sem se preocupar com o tipo de dados do valor. `CDBVariant`Controla o tipo de dados do valor atual, que é armazenado em uma união.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

