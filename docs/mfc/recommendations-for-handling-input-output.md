---
title: Recomendações para tratamento de entrada-saída
ms.date: 11/04/2016
helpviewer_keywords:
- I/O [MFC], about I/O
- file-based I/O options
- I/O [MFC]
- I/O [MFC], options
- I/O [MFC], file-based options
ms.assetid: d664b175-3b4a-40c3-b14b-39de6b12e419
ms.openlocfilehash: 956a92fd1761f61081afa2eb9c6cb35fe72b46d6
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446902"
---
# <a name="recommendations-for-handling-inputoutput"></a>Recomendações para manusear entrada/saída

Se você usa e/s baseada em arquivo ou não depende de como você responde às perguntas na árvore de decisão a seguir:

**Os dados primários em seu aplicativo residem em um arquivo de disco**

- Sim, os dados primários residem em um arquivo de disco:

     **O aplicativo lê o arquivo inteiro na memória no arquivo aberto e grava todo o arquivo de volta em disco no arquivo salvar**

   - Sim: esse é o caso de documento padrão do MFC. Use `CDocument` serialização.

   - Não: normalmente, esse é o caso da atualização baseada em transações do arquivo. Você atualiza o arquivo por transação e não precisa de `CDocument` serialização.

- Não, os dados primários não residem em um arquivo de disco:

     **Os dados residem em uma fonte de dados ODBC**

   - Sim, os dados residem em uma fonte de dados ODBC:

      Use o suporte a banco de dados do MFC. A implementação padrão do MFC para esse caso inclui um objeto `CDatabase`, conforme discutido no artigo [MFC: usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md). O aplicativo também pode ler e gravar um arquivo auxiliar – a finalidade do assistente de aplicativo "a opção de exibição de banco de dados e suporte a arquivos". Nesse caso, você usaria a serialização para o arquivo auxiliar.

   - Não, os dados não residem em uma fonte de dados ODBC.

      Exemplos desse caso: os dados residem em um DBMS não-ODBC; os dados são lidos por meio de algum outro mecanismo, como OLE ou DDE.

      Nesses casos, você não usará a serialização e seu aplicativo não terá itens de menu abrir e salvar. Talvez você ainda queira usar um `CDocument` como base inicial, assim como um aplicativo ODBC do MFC usa o documento para armazenar `CRecordset` objetos. Mas você não usará a serialização de documento de abrir/salvar arquivo padrão da estrutura.

Para dar suporte aos comandos abrir, salvar e salvar como no menu arquivo, a estrutura fornece a serialização de documentos. A serialização lê e grava dados, incluindo objetos derivados da classe `CObject`, para armazenamento permanente, normalmente um arquivo de disco. A serialização é fácil de usar e atende a muitas das suas necessidades, mas pode ser inadequada em muitos aplicativos de acesso a dados. Os aplicativos de acesso a dados normalmente atualizam dados por transação. Eles atualizam os registros afetados pela transação em vez de ler e gravar um arquivo de dados inteiro ao mesmo tempo.

Para obter informações sobre serialização, consulte [serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Serialização: entrada/saída do banco de dados de serialização](../mfc/serialization-serialization-vs-database-input-output.md)
