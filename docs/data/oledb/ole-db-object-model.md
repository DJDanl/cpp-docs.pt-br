---
title: "Modelo de objeto do banco de dados OLE | Microsoft Docs"
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
  - "OLE DB, modelo de objeto"
  - "conjuntos de linhas, modelo de objeto do OLE DB"
ms.assetid: 1a274a25-c310-4430-a1ec-bd2bd8120eff
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelo de objeto do banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O modelo de objeto do OLE DB inclui os seguintes objetos ou componentes.  Os primeiros quatro objetos ou componentes listados \(fontes de dados, sessões, comandos, e conjuntos de linhas\) permitem que você se conectar a uma fonte de dados e exibi\-la.  O restante, a partir de acessadores, está relacionado ao trabalhar com os dados quando é exibido.  
  
## Fontes de dados  
 Os objetos de fonte de dados permitem que você se conectar a uma fonte de dados como um arquivo ou DBMS.  Um objeto de fonte de dados cria e gerencia a conexão e contém permissões e informações de autenticação \(como o nome e a senha de logon\).  Um objeto de fonte de dados pode criar uma ou mais sessões.  
  
## Sessões  
 Uma sessão específica gerencia uma interação com a fonte de dados para consultar e recuperar dados.  Cada sessão é uma única transação.  Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID.  Para uma definição de ACID, consulte [Transações](#vcconoledbcomponents_transactions).  
  
 As sessões executam tarefas importantes como conjuntos de linhas e retornar de abertura o objeto de fonte de dados que o criou.  As sessões também podem retornar metadados, ou informações sobre a fonte de dados em si \(como informações da tabela\).  
  
 Uma sessão pode criar um ou mais comandos.  
  
## Comandos  
 Os comandos executa um comando de texto como uma instrução SQL.  Se o comando de texto especifica um conjunto de linhas, como uma instrução SQL **SELECIONAR** , o comando cria o conjunto de linhas.  
  
 Um comando é apenas um contêiner para um comando de texto, que é uma cadeia de caracteres \(como uma instrução SQL\) transmitidas de um consumidor a um objeto de fonte de dados para execução pelo repositório de dados subjacente do provedor.  Normalmente, o comando de texto é uma instrução SQL **SELECIONAR** \(nesse caso, como o SQL **SELECIONAR** especifica um conjunto de linhas, o comando cria automaticamente um conjunto de linhas\).  
  
## Conjuntos de linhas  
 Expõem dados dos conjuntos de linhas no formato de tabela.  Um índice é um caso especial de um conjunto de linhas.  Você pode criar conjuntos de linhas da sessão ou do comando.  
  
### Conjuntos de linhas de esquema  
 Os esquemas contêm metadados \(\) informações estruturais sobre um base de dados.  Conjuntos de linhas de esquema são conjuntos de linhas que contêm informações de esquema.  Alguns provedores OLE DB para o DBMS oferecem suporte a objetos de conjunto de linhas de esquema.  Para obter mais informações sobre conjuntos de linhas de esquema, consulte [Obtendo metadados com conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) e [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md).  
  
### Objetos de exibição  
 Um objeto de exibição define um subconjunto de linhas e colunas de um conjunto de linhas.  Não contém nenhum dado de sua escolha.  Os objetos de exibição não podem combinar dados de vários conjuntos de linhas.  
  
## Acessadores  
 Somente OLE DB usa o conceito de acessadores.  Um acessador descreve como os dados são armazenados em um consumidor.  Contém um conjunto de associações \(chamadas um mapa de coluna\) entre os campos do conjunto de linhas \(colunas\) e os membros de dados que você declara no consumidor.  
  
##  <a name="vcconoledbcomponents_transactions"></a> Transações  
 Os objetos de transação são usados ao confirmar ou anular a transações aninhadas diferente no nível mais baixo.  Uma transação é uma unidade de trabalho indivisível definida pelo teste ACID.  O ACID representa:  
  
-   Atomicidade: não pode ser dividido em unidades de trabalho menores.  
  
-   Simultaneidade: mais de uma transação pode ocorrer em cada vez.  
  
-   Isolamento: uma transação limitou o conhecimento sobre as alterações feitas por outra.  
  
-   Durabilidade: a transação faz alterações persistentes.  
  
## Enumeradores  
 Os enumeradores a procura de fontes de dados disponíveis e por outros enumeradores.  Consumidores que não são personalizados para que os enumeradores específicos do uso da fonte de dados pesquisados por uma fonte de dados para usar.  
  
 Um enumerador raiz, enviado no acesso a dados SDK do Microsoft, atravessa o Registro que procura fontes de dados e outros enumeradores.  Outros enumeradores atravessam o Registro ou a pesquisa de uma maneira específica do provedor.  
  
## Erros  
 Qualquer interface em qualquer objeto OLE DB pode gerar erros.  Os erros contêm informações adicionais sobre um erro, incluindo um objeto personalizado opcional do erro.  Essa informação está contida em um HRESULT.  
  
## Notificações  
 As notificações são usadas por grupos de consumidores de cooperação que compartilham um conjunto de linhas \(compartilhar onde significa que os consumidores será presumido trabalhar na mesma transação\).  As notificações permitem que os consumidores de cooperação que compartilham um conjunto de linhas a ser informado sobre ações no conjunto de linhas executado por seus pontos.  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)