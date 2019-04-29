---
title: Recomendações para manusear entrada / saída
ms.date: 11/04/2016
helpviewer_keywords:
- I/O [MFC], about I/O
- file-based I/O options
- I/O [MFC]
- I/O [MFC], options
- I/O [MFC], file-based options
ms.assetid: d664b175-3b4a-40c3-b14b-39de6b12e419
ms.openlocfilehash: 760c213c3af7f9c75374f04e3dfc6b9499eade5c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62218558"
---
# <a name="recommendations-for-handling-inputoutput"></a>Recomendações para manusear entrada/saída

Se você usa e/s baseado em arquivo ou não depende de como você responder às perguntas na árvore de decisão a seguir:

**Os dados primários em seu aplicativo residam em um arquivo de disco**

- Sim, os dados primários residem em um arquivo de disco:

     **O aplicativo ler o arquivo inteiro na memória no arquivo abrir e gravar todo o arquivo de volta no disco no arquivo Salvar**

   - Sim: Esse é o caso de documento padrão MFC. Use `CDocument` serialização.

   - Não: Isso normalmente é o caso de atualização do arquivo de baseado em transação. Atualize o arquivo em uma base por transação e não precisa `CDocument` serialização.

- Não, os dados primários não residem em um arquivo de disco:

     **Os dados residir em uma fonte de dados ODBC**

   - Sim, os dados residem em uma fonte de dados ODBC:

         Use MFC's database support. The standard MFC implementation for this case includes a `CDatabase` object, as discussed in the article [MFC: Using Database Classes with Documents and Views](../data/mfc-using-database-classes-with-documents-and-views.md). The application might also read and write an auxiliary file — the purpose of the application wizard "both a database view and file support" option. In this case, you'd use serialization for the auxiliary file.

   - Não, os dados não residir em uma fonte de dados ODBC.

         Examples of this case: the data resides in a non-ODBC DBMS; the data is read via some other mechanism, such as OLE or DDE.

         In such cases, you won't use serialization, and your application won't have Open and Save menu items. You might still want to use a `CDocument` as a home base, just as an MFC ODBC application uses the document to store `CRecordset` objects. But you won't use the framework's default File Open/Save document serialization.

Para dar suporte a abrir, salvar e salve como comandos no menu Arquivo, o framework fornece a serialização de documento. Serialização lê e grava dados, incluindo objetos derivados da classe `CObject`, permanente para armazenamento, normalmente um arquivo de disco. A serialização é fácil de usar e atende a muitas das suas necessidades, mas pode ser inadequado em muitos aplicativos de acesso a dados. Aplicativos de acesso a dados normalmente atualizam dados em uma base por transação. Eles atualizar os registros afetados pela transação em vez de ler e gravar um arquivo de dados inteira ao mesmo tempo.

Para obter informações sobre serialização, consulte [serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Serialização: Serialização vs. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md)
