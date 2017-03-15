---
title: "Modelos de provedor de banco de dados OLE (C++) | Microsoft Docs"
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
  - "bancos de dados [C++], Modelos OLE DB"
  - "Modelos de provedor OLE DB [C++], sobre modelos de provedor OLE DB"
  - "provedores OLE DB [C++], sobre provedores"
  - "modelos [C++], OLE DB"
ms.assetid: fccff85f-2af8-4500-82bd-6312d28a74b8
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de provedor de banco de dados OLE (C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

OLE DB é uma parte importante da estratégia universal de acesso a dados da Microsoft.  O design de OLE DB permite o acesso a dados de alto desempenho de qualquer fonte de dados.  Todos os dados tabulares são visíveis por meio do OLE DB independentemente de origem de um base de dados.  A flexibilidade fornece uma quantidade enorme de capacidade.  
  
 Como explicado em [Consumidores e provedores OLE DB](../../data/oledb/ole-db-consumers-and-providers.md), o OLE DB usa o conceito dos consumidores os provedores e.  O consumidor faz solicitações de dados; o provedor retorna dados em um formato de tabela ao consumidor.  De uma perspectiva de programação, a implicação a mais importante desse modelo é que o provedor deve implementar qualquer chamada que o consumidor pode fazer.  
  
## O que é um provedor?  
 Um provedor OLE DB é um conjunto de objetos COM que servem chamadas da interface de um objeto do consumidor, transferindo dados em um formato de tabela de uma fonte durável \(chamada um repositório de dados\) ao consumidor.  
  
 Os provedores podem ser simples ou complexos.  O provedor pode oferecer suporte a uma quantidade mínima de funcionalidade ou um provedor desenvolvido de qualidade de produção implementando mais interfaces.  Um provedor pode retornar uma tabela, permite ao cliente determinar o formato da tabela, e executa operações nesses dados.  
  
 Cada provedor implementa um conjunto padrão de objetos COM a solicitações do identificador do cliente, com significado padrão que o consumidor OLE DB pode acessar dados de qualquer provedor, independentemente do idioma \(como C\+\+ e básico\).  
  
 Cada objeto COM várias interfaces, algumas das quais são necessários e alguns dos quais é opcional.  Implementando as interfaces obrigatórias, um provedor garante um nível mínimo de funcionalidade correspondente chamado \(\) que qualquer cliente deve poder usar.  Um provedor pode implementar interfaces opcionais para fornecer funcionalidade adicional.  [A arquitetura do modelo do provedor OLE DB](../../data/oledb/ole-db-provider-template-architecture.md) descreve essas interfaces em detalhes.  O cliente deve sempre chamar `QueryInterface` para determinar se um provedor oferece suporte a uma interface especificada.  
  
## Suporte do nível da especificação OLE DB  
 Os modelos do provedor OLE DB oferecem suporte à especificação do OLE DB versão 2,7.  Usando os modelos do provedor OLE DB, você pode implementar um provedor compatível de nível 0.  O exemplo do provedor, por exemplo, use os modelos para implementar um servidor do comando não SQL \(MS\-DOS\) que executa o comando de OS DIR consulte o sistema de arquivos.  O exemplo do provedor retorna informações de diretório em um conjunto de linhas, que é o mecanismo padrão de OLE DB para retornar dados de tabela.  
  
 Digite o mais simples de provedor com suporte pelos modelos OLE DB é um provedor somente leitura sem comandos.  Os provedores com comandos também são suportados, como são marcando um endereço da Internet\) e o recurso de leitura\/gravação.  Você pode implementar um provedor de leitura\/gravação gravando o código adicional.  Os conjuntos de linhas dinâmicas e as transações não têm suporte na versão atual, mas você pode adicionar desejadas.  
  
## Quando você precisar criar um provedor OLE DB?  
 Você não sempre precisar criar seu próprio provedor; O Microsoft fornece vários provedores pré\-embalados padrão, na caixa de diálogo de **Propriedades de associação de dados** no Visual C\+\+.  O principal motivo criar um provedor OLE DB é aproveitar a estratégia universal de acesso a dados.  Algumas das vantagens de fazer isso são:  
  
-   Acessando dados com qualquer linguagem como a edição básica, C\+\+, Basic e Visual de script.  Permite que os desenvolvedores diferentes em sua organização acessem os mesmos dados da mesma forma, independentemente de idioma que usam.  
  
-   Expõe os dados em outras fontes de dados como o SQL Server, Excel, e acesso.  Isso pode ser muito útil se você quiser transferir dados entre formatos diferentes.  
  
-   Participação em operações \(heterogêneas\) da fonte de dados cruzado.  Esse pode ser muito um modo eficiente de armazenamento de dados.  Usando provedores OLE DB, você pode manter dados em seu formato nativo e ainda poderá acessá\-lo em uma operação simples.  
  
-   Adicionando recursos adicionais nos dados, como o processamento de consulta.  
  
-   Desempenho do crescent de acessar dados controlando como é manipulado.  
  
-   Vigor crescente.  Se você tiver um formato de dados proprietário que apenas um programador possa acessar, você está em risco.  Usando provedores OLE DB, você pode abrir que proprietário formatar a todos os programadores.  
  
## Provedores somente leitura e atualizáveis  
 Os provedores podem variar significativamente na complexidade e a funcionalidade do.  É útil para categorizar provedores em provedores somente leitura e em provedores atualizáveis:  
  
-   Visual C\+\+ 6.0 oferece suporte somente provedores somente leitura.  [Criando um provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md) discute como criar um provedor somente leitura.  
  
-   Visual C\+\+ .NET oferece suporte aos provedores atualizáveis, que podem atualizar \(gravação\) o repositório de dados.  Para obter informações sobre provedores atualizáveis, consulte [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md); o exemplo de [UpdatePV](http://msdn.microsoft.com/pt-br/c8bed873-223c-4a7d-af55-f90138c6f38f) é um exemplo de um provedor atualizável.  
  
 Para obter mais informações, consulte:  
  
-   [A arquitetura do modelo do provedor OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)  
  
-   [Criando um provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md)  
  
-   [Programação de OLE DB](../../data/oledb/ole-db-programming.md)  
  
## Consulte também  
 [Acesso a dados](../Topic/Data%20Access%20in%20Visual%20C++.md)   
 [Documentação de OLE DB SDK](https://msdn.microsoft.com/en-us/library/ms722784.aspx)   
 [A referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx)