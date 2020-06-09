---
title: Classes DAO
ms.date: 09/17/2019
helpviewer_keywords:
- database classes [MFC], DAO
- DAO [MFC], classes
ms.assetid: b15d0cd6-328b-4288-9c19-d037a795db57
ms.openlocfilehash: 51abd29ef4de5d70f4a5b2b6b14b53510e7876a1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615929"
---
# <a name="dao-classes"></a>Classes DAO

O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

Essas classes funcionam com as outras classes de estrutura de aplicativo para fornecer acesso fácil aos bancos de dados DAO (objeto de acesso a data), que usam o mesmo mecanismo de banco de dados que o Microsoft Visual Basic e o Microsoft Access. As classes DAO também podem acessar uma ampla variedade de bancos de dados para os quais estão disponíveis drivers ODBC (Open Database Connectivity).

Os programas que usam bancos de dados DAO terão pelo menos um `CDaoDatabase` objeto e um `CDaoRecordset` objeto.

> [!NOTE]
> O ambiente Visual C++ e os assistentes não dão mais suporte a DAO (embora as classes DAO estejam incluídas e você ainda possa usá-las). A Microsoft recomenda que você use o ODBC para novos projetos MFC. Você só deve usar o DAO na manutenção de aplicativos existentes.

[CDaoWorkspace](reference/cdaoworkspace-class.md)<br/>
Gerencia uma sessão de banco de dados nomeada e protegida por senha do logon para fazer logoff. A maioria dos programas usa o espaço de trabalho padrão.

[CDaoDatabase](reference/cdaodatabase-class.md)<br/>
Uma conexão com um banco de dados do por meio do qual você pode operar com o dado.

[CDaoRecordset](reference/cdaorecordset-class.md)<br/>
Representa um conjunto de registros selecionados de uma fonte de dados.

[CDaoRecordView](reference/cdaorecordview-class.md)<br/>
Uma exibição que exibe registros de banco de dados em controles.

[CDaoQueryDef](reference/cdaoquerydef-class.md)<br/>
Representa uma definição de consulta, geralmente uma salva em um banco de dados.

[CDaoTableDef](reference/cdaotabledef-class.md)<br/>
Representa a definição armazenada de uma tabela base ou de uma tabela anexada.

[CDaoException](reference/cdaoexception-class.md)<br/>
Representa uma condição de exceção resultante das classes DAO.

[CDaoFieldExchange](reference/cdaofieldexchange-class.md)<br/>
Dá suporte às rotinas de troca de campo de registro (DFX) do DAO usadas pelas classes de banco de dados DAO. Normalmente, você não usará essa classe diretamente.

## <a name="related-classes"></a>Classes relacionadas

[CLongBinary](reference/clongbinary-class.md)<br/>
Encapsula um identificador para o armazenamento de um objeto binário grande (BLOB), como um bitmap. `CLongBinary`os objetos são usados para gerenciar grandes objetos de dados armazenados em tabelas de banco de dado.

[COleCurrency](reference/colecurrency-class.md)<br/>
Wrapper para a **moeda**do tipo de automação OLE, um tipo aritmético de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos após.

[COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)<br/>
Wrapper para a **Data**do tipo de automação OLE. Representa os valores de data e hora.

[COleVariant](reference/colevariant-class.md)<br/>
Wrapper para a **variante**de tipo de automação OLE. Os dados na **variante**s podem ser armazenados em vários formatos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
