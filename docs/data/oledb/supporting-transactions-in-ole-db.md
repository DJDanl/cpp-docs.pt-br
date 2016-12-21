---
title: "Dando suporte a transa&#231;&#245;es em banco de dados OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bancos de dados [C++], transações"
  - "transações distribuídas [C++]"
  - "transações aninhadas [C++]"
  - "OLE DB [C++], suporte a transações"
  - "Modelos de consumidor OLE DB [C++], suporte a transações"
  - "transações [C++], suporte OLE DB para"
ms.assetid: 3d72e583-ad38-42ff-8f11-e2166d60a5a7
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dando suporte a transa&#231;&#245;es em banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[transação](../../data/transactions-mfc-data-access.md) é uma maneira de clustering, ou o lote, uma série de atualizações em uma fonte de dados para que todos tenham êxito e foram confirmados imediatamente ou se qualquer um deless \(falha\) não são confirmadas e a transação inteira será revertida.  Esse processo garante a integridade de resultado na fonte de dados.  
  
 O OLE DB da suporte a transações com os seguintes métodos:  
  
-   [\<caps:sentence id\="tgt4" sentenceid\="0699a86bb6d6316bff035b804a56f0aa" class\="tgtSentence"\>ITransactionLocal::StartTransaction\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms709786.aspx)  
  
-   [\<caps:sentence id\="tgt5" sentenceid\="39299b0fea086b86052550bd165334f7" class\="tgtSentence"\>ITransaction::Commit\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms713008.aspx)  
  
-   [\<caps:sentence id\="tgt6" sentenceid\="8e992150c28ae247d532408ca7828bfe" class\="tgtSentence"\>ITransaction::Abort\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms709833.aspx)  
  
## Relação das sessões e transações  
 Um único objeto de fonte de dados pode criar um ou mais objetos de sessão, que podem estar dentro ou fora do escopo de uma transação de em um determinado momento.  
  
 Quando uma sessão não insere uma transação, todos funcionam feito nessa sessão no repositório de dados são confirmados imediatamente em cada chamada de método. \(Isso às vezes é referenciado como o modo de confirmação automática ou o modo implícito.\)  
  
 Quando uma sessão inserir uma transação, todos funcionam feito nessa sessão no repositório de dados fazem parte da transação e são confirmados ou cancelada como uma única unidade. \(Isso às vezes é referenciado como o modo de confirmação manual\).  
  
 O suporte a transações é específica do provedor.  Se você estiver usando o provedor da suporte a transações, um objeto de sessão que oferece suporte **ITransaction** e **ITransactionLocal** pode inserir \(isto é, não aninhado\) uma transação simples.  A classe [CSession](../../data/oledb/csession-class.md) de modelos OLE DB oferecer suporte a essas interfaces e é recomendado para implementar o suporte a transações no Visual C\+\+.  
  
## Iniciando e terminando a transação  
 Chame `StartTransaction`, **Confirmar**, e os métodos de **Anular** no conjunto de linhas object no consumidor.  
  
 A chamada **ITransactionLocal::StartTransaction** inicia uma nova transação local.  Quando você iniciar a transação, todas as alterações designada por operações subsequentes não estão realmente aplicadas ao repositório de dados até que você confirme a transação.  
  
 A chamada **ITransaction::Commit** ou **ITransaction::Abort** finalizar a transação.  **Confirmar** faz com que todas as alterações no escopo da transação a ser aplicada ao repositório de dados.  **Anular** faz com que todas as alterações no escopo da transação seja cancelada e o repositório de dados foi deixado no estado que tinha antes que a transação foi iniciada.  
  
## Transações aninhadas  
 [transação aninhada](https://msdn.microsoft.com/en-us/library/ms716985.aspx) ocorre quando você inicia uma nova transação local quando uma transação ativa já existir na sessão.  A nova transação é iniciada como uma transação aninhada abaixo da transação atual.  Se o provedor não oferecer suporte a transações aninhadas, chamando `StartTransaction` quando já houver uma transação ativa na sessão retorna **XACT\_E\_XTIONEXISTS**.  
  
## Transações distribuídas  
 Uma transação distribuída é uma transação que atualiza dados distribuídos; ou seja, dados em mais de um sistema de computador conectado.  Se você quiser oferecer suporte a transações sobre um sistema distribuído, você deve usar o .NET Framework em vez da suporte a transações do OLE DB.  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)