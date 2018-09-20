---
title: Classes ODBC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.data
dev_langs:
- C++
helpviewer_keywords:
- database classes [MFC], ODBC
- ODBC classes [MFC]
ms.assetid: 6c40fca8-3033-4873-9abe-7f51725de0e0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97bbdb74d122e633574dcf76876f0907de8ef2c4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400569"
---
# <a name="odbc-classes"></a>Classes ODBC

Essas classes funcionam com as outras classes de estrutura de aplicativo para fornecer acesso fácil a uma ampla variedade de bancos de dados para o qual os drivers de conectividade de banco de dados aberto (ODBC) estão disponíveis.

Programas que usam bancos de dados ODBC terá pelo menos um `CDatabase` objeto e um `CRecordset` objeto.

[CDatabase](../mfc/reference/cdatabase-class.md)<br/>
Encapsula uma conexão a uma fonte de dados, por meio do qual você pode operar na fonte de dados.

[CRecordset](../mfc/reference/crecordset-class.md)<br/>
Encapsula um conjunto de registros selecionados de uma fonte de dados. Conjuntos de registros habilitar a rolagem de registro em registro, atualização de registros (adicionando, editando e excluindo registros), a seleção de qualificação com um filtro, classificação da seleção e parametrizar a seleção com informações obtidas ou calculados em tempo de execução.

[CRecordView](../mfc/reference/crecordview-class.md)<br/>
Fornece um formulário de exibição diretamente conectada a um objeto de conjunto de registros. Os dados de caixa de diálogo (DDX) mecanismo troca dados entre o conjunto de registros e os controles de exibição de registro do exchange. Como todos os modos de exibição de formulário, uma exibição de registro com base em um recurso de modelo de caixa de diálogo. Exibições de registro também dão suporte a movimentação de registro para registro no conjunto de registros, Atualizando registros e fechando o conjunto de registros associado quando o modo de exibição do registro é fechado.

[CDBException](../mfc/reference/cdbexception-class.md)<br/>
Uma exceção resultante de falhas no acesso a dados do processamento. Essa classe tem a mesma finalidade como outras classes de exceção no mecanismo de tratamento de exceção da biblioteca de classes.

[CFieldExchange](../mfc/reference/cfieldexchange-class.md)<br/>
Fornece informações de contexto para dar suporte à troca de campos de registro (RFX), que troca dados entre os membros de dados de campo e membros de dados de parâmetro de um objeto de conjunto de registros e as colunas da tabela correspondente na fonte de dados. Semelhante à classe [CDataExchange](../mfc/reference/cdataexchange-class.md), que é usado da mesma forma para troca de dados de caixa de diálogo (DDX).

## <a name="related-classes"></a>Classes relacionadas

[CLongBinary](../mfc/reference/clongbinary-class.md)<br/>
Encapsula um identificador para o armazenamento para um objeto binário grande (BLOB), como um bitmap. `CLongBinary` objetos são usados para gerenciar objetos de dados grandes armazenados nas tabelas de banco de dados.

[CDBVariant](../mfc/reference/cdbvariant-class.md)<br/>
permite que você armazene um valor sem se preocupar sobre o tipo de dados do valor. `CDBVariant` Controla o tipo de dados do valor atual, que é armazenado em uma união.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

