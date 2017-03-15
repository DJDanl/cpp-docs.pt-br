---
title: "Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de aplicativos de banco de dados | Microsoft Docs"
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
  - "aplicativos [MFC], Banco de dados"
  - "aplicativos de banco de dados [C++]"
  - "aplicativos de banco de dados [C++], criando"
  - "MFC [C++], aplicativos de banco de dados"
ms.assetid: 9371da59-8536-43cd-8314-706ad320e2ec
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de aplicativos de banco de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra a função e a função da estrutura em aplicativos de base de gravação de dados.  
  
> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use ODBC para novos projetos MFC.  Você só deve usar DAO manter os aplicativos existentes.  
  
### Criando aplicativos de base de dados  
  
|Tarefa|Você fizer|A estrutura faz|  
|------------|----------------|---------------------|  
|Decida se usar as classes de MFC ODBC ou de DAO.|Use ODBC para novos projetos MFC.  Use DAO somente para manter os aplicativos existentes.  Consulte [Eu deveria usar DAO ou ODBC?](../data/should-i-use-dao-or-odbc-q.md).  Para obter informações gerais, consulte o artigo [Programação de acesso a dados](../data/data-access-programming-mfc-atl.md).|A estrutura do fornece classes que oferecem suporte ao acesso ao base de dados.|  
|Crie seu aplicativo do esqueleto com as opções de base de dados.|Execute o assistente de aplicativo MFC.  Selecione opções na página de suporte da base de dados.  Se você escolher uma opção que cria uma exibição do registro, também especificar:<br /><br /> -   Fonte de dados e nome ou nomes de tabela<br />-   Nome ou nomes de consulta.|O assistente de aplicativo MFC cria arquivos e especifica o inclui necessário.  Dependendo das opções que você especifica, os arquivos pode incluir uma classe do conjunto de registros.|  
|Criar seus formulário ou formulários da base de dados.|Use o editor da caixa de diálogo do Visual C\+\+ para colocar controles de recursos do modelo da caixa de diálogo para suas classes de exibição do registro.|O assistente de aplicativo MFC cria um recurso vazia do modelo da caixa de diálogo para que você seja preenchido.|  
|Crie classes de exibição e do conjunto de registros de registro adicional quando necessário.|Use a exibição da classe para criar as classes e o publicador da caixa de diálogo para criar exibições.|A exibição da classe cria arquivos adicionais para suas classes novas.|  
|Crie objetos do conjunto de registros conforme necessário em seu código.  Use cada conjunto de registros para manipular registros…|Os conjuntos de registros são baseados nas classes derivadas de [CRecordset](../Topic/CRecordset%20Class.md) com os assistentes.|Troca do campo de registro de ODBC \(RFX\) para trocar dados entre o base de dados e os membros de dados do campo do conjunto de registros.  Se você estiver usando uma exibição do registro, dados de troca de troca de dados da caixa de diálogo \(DDX\) entre o conjunto de registros e os controles na exibição do registro.|  
|… ou crie [CDatabase](../mfc/reference/cdatabase-class.md) explícito em seu código para cada base de dados que você deseja abrir.|Baseie seus objetos do conjunto de registros nos objetos de base de dados.|O objeto de base de dados fornece uma interface para a fonte de dados.|  
|Colunas de dados de associação ao conjunto de registros dinamicamente.|No ODBC, adicione o código à sua classe derivada do conjunto de registros para gerenciar a associação.  Consulte o artigo [Conjunto de registros: Colunas de dados dinamicamente associação \(ODBC\)](../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||  
  
## Consulte também  
 [Aproveitando o Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para compilação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)