---
title: Recomendações para manipulação de entrada-saída
ms.date: 11/04/2016
helpviewer_keywords:
- I/O [MFC], about I/O
- file-based I/O options
- I/O [MFC]
- I/O [MFC], options
- I/O [MFC], file-based options
ms.assetid: d664b175-3b4a-40c3-b14b-39de6b12e419
ms.openlocfilehash: c365120a385c440f09f0ee4c0a2fc52afb55834f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371730"
---
# <a name="recommendations-for-handling-inputoutput"></a>Recomendações para manusear entrada/saída

Se você usa I/O baseado em arquivos ou não depende de como você responde às perguntas na seguinte árvore de decisão:

**Os dados primários do seu aplicativo residem em um arquivo de disco**

- Sim, os dados principais residem em um arquivo de disco:

   **O aplicativo lê todo o arquivo em memória no File Open e escreve todo o arquivo de volta para o disco no File Save**

  - Sim: Este é o caso de documento MFC padrão. Use `CDocument` serialização.

  - Não: Este é tipicamente o caso de atualização baseada em transações do arquivo. Você atualiza o arquivo por transação e `CDocument` não precisa de serialização.

- Não, os dados primários não residem em um arquivo de disco:

   **Os dados residem em uma fonte de dados ODBC**

  - Sim, os dados residem em uma fonte de dados ODBC:

      Use o suporte de banco de dados do MFC. A implementação padrão do MFC `CDatabase` para este caso inclui um objeto, conforme discutido no artigo [MFC: Usando classes de banco de dados com documentos e visualizações](../data/mfc-using-database-classes-with-documents-and-views.md). O aplicativo também pode ler e gravar um arquivo auxiliar — o propósito da opção "visão de banco de dados e suporte a arquivos". Neste caso, você usaria serialização para o arquivo auxiliar.

  - Não, os dados não residem em uma fonte de dados ODBC.

      Exemplos deste caso: os dados residem em um DBMS não-ODBC; os dados são lidos através de algum outro mecanismo, como OLE ou DDE.

      Nesses casos, você não usará serialização e seu aplicativo não terá itens de menu Abrir e Salvar. Você ainda pode querer `CDocument` usar um como base inicial, assim como um aplicativo `CRecordset` MFC ODBC usa o documento para armazenar objetos. Mas você não usará a serialização padrão de documentos open/save do framework.

Para suportar os comandos Abrir, Salvar e Salvar como no menu Arquivo, a estrutura fornece serialização de documentos. A serialização lê e grava dados, `CObject`incluindo objetos derivados da classe, para o armazenamento permanente, normalmente um arquivo de disco. A serialização é fácil de usar e atende a muitas de suas necessidades, mas pode ser inadequada em muitos aplicativos de acesso a dados. Os aplicativos de acesso a dados normalmente atualizam os dados por transação. Eles atualizam os registros afetados pela transação em vez de ler e escrever um arquivo de dados inteiro de uma só vez.

Para obter informações sobre serialização, consulte [Serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Confira também

[Serialização: serialização em comparação com entrada/saída do banco de dados](../mfc/serialization-serialization-vs-database-input-output.md)
