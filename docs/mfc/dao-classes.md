---
title: Classes DAO
ms.date: 09/17/2019
helpviewer_keywords:
- database classes [MFC], DAO
- DAO [MFC], classes
ms.assetid: b15d0cd6-328b-4288-9c19-d037a795db57
ms.openlocfilehash: 7ae85cbeb7790cadb8c26dfbdb7a5163dbcd47c0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373513"
---
# <a name="dao-classes"></a>Classes DAO

O DAO é usado com bancos de dados access e é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

Essas classes trabalham com as outras classes de framework de aplicativos para dar fácil acesso aos bancos de dados DAO (Data Access Object, objeto de acesso de dados), que usam o mesmo mecanismo de banco de dados que o Microsoft Visual Basic e o Microsoft Access. As classes DAO também podem acessar uma grande variedade de bancos de dados para os quais os drivers ODBC (Open Database Connectivity, conectividade de banco de dados aberto) estão disponíveis.

Programas que usam bancos de dados `CDaoDatabase` DAO `CDaoRecordset` terão pelo menos um objeto e um objeto.

> [!NOTE]
> O ambiente Visual C++ e os assistentes não suportam mais DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use ODBC para novos projetos de MFC. Você só deve usar DAO na manutenção de aplicativos existentes.

[Cdaoworkspace](../mfc/reference/cdaoworkspace-class.md)<br/>
Gerencia uma sessão de banco de dados nomeada e protegida por senha do login ao logoff. A maioria dos programas usa o espaço de trabalho padrão.

[Cdaodatabase](../mfc/reference/cdaodatabase-class.md)<br/>
Uma conexão com um banco de dados através do qual você pode operar sobre os dados.

[Cdaorecordset](../mfc/reference/cdaorecordset-class.md)<br/>
Representa um conjunto de registros selecionados a partir de uma fonte de dados.

[Cdaorecordview](../mfc/reference/cdaorecordview-class.md)<br/>
Uma exibição que exibe registros de banco de dados em controles.

[Cdaoquerydef](../mfc/reference/cdaoquerydef-class.md)<br/>
Representa uma definição de consulta, geralmente uma salva em um banco de dados.

[Cdaotabledef](../mfc/reference/cdaotabledef-class.md)<br/>
Representa a definição armazenada de uma tabela base ou de uma tabela anexada.

[Cdaoexception](../mfc/reference/cdaoexception-class.md)<br/>
Representa uma condição de exceção decorrente das classes DAO.

[Cdaofieldexchange](../mfc/reference/cdaofieldexchange-class.md)<br/>
Suporta as rotinas de troca de campo de registro DAO (DFX) usadas pelas classes de banco de dados DAO. Você normalmente não usará diretamente esta classe.

## <a name="related-classes"></a>Classes Relacionadas

[Clongbinary](../mfc/reference/clongbinary-class.md)<br/>
Encapsula uma alça para armazenamento de um objeto grande binário (BLOB), como um bitmap. `CLongBinary`objetos são usados para gerenciar grandes objetos de dados armazenados em tabelas de banco de dados.

[Colecurrency](../mfc/reference/colecurrency-class.md)<br/>
Wrapper para o tipo de automação OLE **CURRENCY**, um tipo de aritmética de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos depois.

[Coledatetime](../atl-mfc-shared/reference/coledatetime-class.md)<br/>
Wrapper para o tipo de automação OLE **DATE**. Representa valores de data e hora.

[Colevariant](../mfc/reference/colevariant-class.md)<br/>
Wrapper para o tipo de automação OLE **VARIANT**. Os dados em **VARIANTS**podem ser armazenados em muitos formatos.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../mfc/class-library-overview.md)
