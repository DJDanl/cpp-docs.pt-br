---
title: Classes ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- database classes [MFC], ODBC
- ODBC classes [MFC]
ms.assetid: 6c40fca8-3033-4873-9abe-7f51725de0e0
ms.openlocfilehash: 18b6e3a0ea20dbd352a61c4faab52c35b852dcb3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622187"
---
# <a name="odbc-classes"></a>Classes ODBC

Essas classes funcionam com as outras classes de estrutura de aplicativo para fornecer acesso fácil a uma ampla variedade de bancos de dados para os quais estão disponíveis drivers ODBC (Open Database Connectivity).

Os programas que usam bancos de dados ODBC terão, pelo menos, um `CDatabase` objeto e um `CRecordset` objeto.

[CDatabase](reference/cdatabase-class.md)<br/>
Encapsula uma conexão com uma fonte de dados, por meio da qual você pode operar na fonte de dados.

[CRecordset](reference/crecordset-class.md)<br/>
Encapsula um conjunto de registros selecionados de uma fonte de dados. Os conjuntos de registros habilitam a rolagem do registro para registro, Atualizando registros (adicionando, editando e excluindo registros), qualificando a seleção com um filtro, classificando a seleção e parametrizando a seleção com informações obtidas ou calculadas em tempo de execução.

[CRecordView](reference/crecordview-class.md)<br/>
Fornece uma exibição de formulário diretamente conectada a um objeto Recordset. O mecanismo de intercâmbio de dados de caixa de diálogo (campo DDX) troca dados entre o conjunto de registros e os controles da exibição de registro. Como todas as exibições de formulário, uma exibição de registro é baseada em um recurso de modelo de caixa de diálogo. As exibições de registro também dão suporte à movimentação de registro para registro no conjunto de registros, à atualização de registros e ao fechamento do conjunto de registros associado quando a exibição de registro é fechada.

[CDBException](reference/cdbexception-class.md)<br/>
Uma exceção resultante de falhas no processamento de acesso a dados. Essa classe tem a mesma finalidade que outras classes de exceção no mecanismo de tratamento de exceções da biblioteca de classes.

[CFieldExchange](reference/cfieldexchange-class.md)<br/>
Fornece informações de contexto para dar suporte ao suporte RFX (Record Field Exchange), que troca dados entre os membros de dados de campo e os membros de dados de parâmetro de um objeto Recordset e as colunas de tabela correspondentes na fonte de dados. Análogo à classe [CDataExchange](reference/cdataexchange-class.md), que é usada da mesma forma para a troca de dados de caixa de diálogo (campo DDX).

## <a name="related-classes"></a>Classes relacionadas

[CLongBinary](reference/clongbinary-class.md)<br/>
Encapsula um identificador para o armazenamento de um objeto binário grande (BLOB), como um bitmap. `CLongBinary`os objetos são usados para gerenciar grandes objetos de dados armazenados em tabelas de banco de dado.

[CDBVariant](reference/cdbvariant-class.md)<br/>
Permite que você armazene um valor sem se preocupar com o tipo de dados do valor. `CDBVariant`controla o tipo de dados do valor atual, que é armazenado em uma União.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
