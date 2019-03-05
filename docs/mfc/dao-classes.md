---
title: Classes DAO
ms.date: 11/04/2016
f1_keywords:
- vc.classes.data
helpviewer_keywords:
- database classes [MFC], DAO
- DAO [MFC], classes
ms.assetid: b15d0cd6-328b-4288-9c19-d037a795db57
ms.openlocfilehash: 238aab0a1948f16a85b8ea16719b75b49f5e69c8
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287486"
---
# <a name="dao-classes"></a>Classes DAO

Essas classes funcionam com as outras classes de estrutura de aplicativo para fornecer acesso fácil aos bancos de dados de objeto de acesso de dados (DAO), que usam o mesmo mecanismo de banco de dados como o Microsoft Visual Basic e do Microsoft Access. As classes DAO também podem acessar uma grande variedade de bancos de dados para o qual os drivers de conectividade de banco de dados aberto (ODBC) estão disponíveis.

Programas que usam bancos de dados DAO terá pelo menos um `CDaoDatabase` objeto e um `CDaoRecordset` objeto.

> [!NOTE]
>  Os assistentes e o ambiente do Visual C++ não suportam DAO (embora as classes DAO estão incluídas e você ainda pode usá-los). A Microsoft recomenda que você use o ODBC para novos projetos MFC. Você só deve usar DAO em manutenção de aplicativos existentes.

[CDaoWorkspace](../mfc/reference/cdaoworkspace-class.md)<br/>
Gerencia uma sessão de banco de dados nomeado e protegido por senha de logon para fazer logoff. A maioria dos programas usam o espaço de trabalho padrão.

[CDaoDatabase](../mfc/reference/cdaodatabase-class.md)<br/>
Uma conexão a um banco de dados por meio do qual você pode operar nos dados.

[CDaoRecordset](../mfc/reference/cdaorecordset-class.md)<br/>
Representa um conjunto de registros selecionados de uma fonte de dados.

[CDaoRecordView](../mfc/reference/cdaorecordview-class.md)<br/>
Uma exibição que exibe registros de banco de dados em controles.

[CDaoQueryDef](../mfc/reference/cdaoquerydef-class.md)<br/>
Representa uma definição de consulta, geralmente uma salva em um banco de dados.

[CDaoTableDef](../mfc/reference/cdaotabledef-class.md)<br/>
Representa a definição armazenada de uma tabela base ou uma tabela anexada.

[CDaoException](../mfc/reference/cdaoexception-class.md)<br/>
Representa uma condição de exceção decorrente das classes DAO.

[CDaoFieldExchange](../mfc/reference/cdaofieldexchange-class.md)<br/>
Oferece suporte as rotinas de exchange (DFX) de campos de registro DAO usadas pelas classes de banco de dados DAO. Você normalmente não irá usar essa classe diretamente.

## <a name="related-classes"></a>Classes relacionadas

[CLongBinary](../mfc/reference/clongbinary-class.md)<br/>
Encapsula um identificador para o armazenamento para um objeto binário grande (BLOB), como um bitmap. `CLongBinary` objetos são usados para gerenciar objetos de dados grandes armazenados nas tabelas de banco de dados.

[COleCurrency](../mfc/reference/colecurrency-class.md)<br/>
Wrapper para o tipo de automação OLE **moeda**, um tipo aritmético de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos após.

[COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)<br/>
Wrapper para o tipo de automação OLE **data**. Representa valores de data e hora.

[COleVariant](../mfc/reference/colevariant-class.md)<br/>
Wrapper para o tipo de automação OLE **VARIANT**. Dados no **VARIANT**s podem ser armazenados em vários formatos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
