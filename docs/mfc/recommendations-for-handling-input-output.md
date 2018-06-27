---
title: Recomendações para manusear entrada / saída | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- I/O [MFC], about I/O
- file-based I/O options
- I/O [MFC]
- I/O [MFC], options
- I/O [MFC], file-based options
ms.assetid: d664b175-3b4a-40c3-b14b-39de6b12e419
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9ee88b7784abb6ca622e72a9dfb31efc39fa7816
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930934"
---
# <a name="recommendations-for-handling-inputoutput"></a>Recomendações para manusear entrada/saída
Se você usar a e/s baseado em arquivo ou não depende de como você responder às perguntas na árvore de decisão a seguir:  
  
 **Dados primários em seu aplicativo reside em um arquivo de disco**  
  
-   Sim, os dados primários residem em um arquivo de disco:  
  
     **O aplicativo de ler o arquivo inteiro na memória em Abrir arquivo e gravar todo o arquivo em disco novamente no salvamento do arquivo**  
  
    -   Sim: Esse é o caso de documento do MFC padrão. Use `CDocument` serialização.  
  
    -   Não: Isso normalmente é o caso de baseado em transação atualização do arquivo. Atualizar o arquivo em uma base por transação e não é necessário `CDocument` serialização.  
  
-   Não, os dados primários não residam em um arquivo de disco:  
  
     **Os dados residir em uma fonte de dados ODBC**  
  
    -   Sim, os dados residem em uma fonte de dados ODBC:  
  
         Use o suporte de banco de dados do MFC. A implementação padrão do MFC para esse caso inclui um `CDatabase` do objeto, conforme descrito no artigo [MFC: usando Classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md). O aplicativo também pode ler e gravar um arquivo auxiliar, o objetivo do Assistente de aplicativo a opção "uma exibição de banco de dados e o arquivo de suportam". Nesse caso, você usaria serialização para o arquivo auxiliar.  
  
    -   Não, os dados não residir em uma fonte de dados ODBC.  
  
         Exemplos de caso: os dados residem em uma não - ODBC DBMS; os dados são lidos por meio de outro mecanismo, como OLE ou DDE.  
  
         Nesses casos, você não usa a serialização e seu aplicativo não estão abertos e salvar itens de menu. Você ainda queira usar um `CDocument` como uma base de casa, assim como um MFC ODBC aplicativo usa o documento para armazenar `CRecordset` objetos. Mas você não usar a serialização de documento da estrutura padrão abrir arquivo/Salvar.  
  
 Para oferecer suporte a abrir, salvar e salvar como comandos no menu Arquivo, o framework fornece a serialização de documento. Serialização lê e grava os dados, incluindo objetos derivados da classe `CObject`, permanente para armazenamento, normalmente um arquivo de disco. Serialização é fácil de usar e serve muitas das suas necessidades, mas pode ser inadequada em muitos aplicativos de acesso a dados. Aplicativos de acesso a dados normalmente atualizam dados em uma base por transação. Eles atualizar os registros afetados por transação em vez de ler e gravar um arquivo de dados inteiro de uma vez.  
  
 Para obter informações sobre serialização, consulte [serialização](../mfc/serialization-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Serialização: Serialização vs. Banco de dados de entrada/saída](../mfc/serialization-serialization-vs-database-input-output.md)
