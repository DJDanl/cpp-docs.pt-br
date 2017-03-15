---
title: "Vis&#227;o geral da programa&#231;&#227;o de banco de dados OLE | Microsoft Docs"
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
  - "OLE DB, sobre OLE DB"
  - "Acesso a Dados Universais"
ms.assetid: a5a69730-2793-4277-a67d-6f3c8edab6df
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral da programa&#231;&#227;o de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Que são OLE DB, e o que faz distinto de outras tecnologias de base de dados?  OLE DB é uma tecnologia da base de dados de alto desempenho, COM base em COM gerada pela Microsoft.  O que define OLE DB independentemente de outras tecnologias da base de dados do Microsoft é como fornece acesso a dados universal.  
  
## Acesso a dados universal  
 O acesso a dados universal fornece uma forma comum de acessar dados independentemente do formato em que está armazenada.  Em uma situação típica comercial, uma grande quantidade de informações são armazenadas fora de bases de dados corporativos.  Essas informações são encontradas em sistemas de arquivos FAT \(como ou\) NTFS, arquivos indexar\- sequenciais, em bases de dados pessoais \(como o access\), em planilhas \(como o Excel\), em aplicativos de planejamento de projeto \(como o projeto\), e nos emails \(como o Outlook\).  
  
 Para acessar esses dados que usam os vários aplicativos associados apresenta um afunilamento principal no fluxo de trabalho ou pelo menos um aborrecimento.  A maioria de empresas localizam\-se nessa situação e tratam\-se o problema consolidando informações em um sistema de gerenciamento da base de dados \(DBMS\).  Entretanto, esse movimentação é caro, demorado e, em muitos casos não for possível.  
  
 A alternativa é desenvolver uma solução universal de acesso a dados.  OLE DB e ADO fornecem o recurso de acesso a dados universal.  Os dois, OLE DB o desempenho é mais intensivos e é recomendado para uso com aplicativos do Visual C\+\+.  
  
 O acesso a dados universal implica dois recursos: o primeiro é consulta distribuída ou uniforme acesso a várias fontes de dados \(distribuídas\) e a segunda é a capacidade de fazer fontes de dados não DBMS acessíveis para aplicativos de base de dados.  
  
-   Consulta distribuída  
  
     A capacidade de acessar dados uniformemente em vários \(ou seja, distribuída\) fontes de dados.  As fontes de dados podem ser do mesmo tipo \(como dois bases de dados do Access separados\) ou de tipos diferentes \(como um base de dados do SQL Server e uma base de dados do Access\).  Uniformemente significa que você pode executar a mesma consulta significativa em todas as fontes de dados.  
  
-   Acesso do DBMS não  
  
     A capacidade de fazer fontes de dados não DBMS acessíveis para aplicativos de base de dados.  Os exemplos de fontes de dados do DBMS incluem o IMS, o DB2 do, Oracle, o SQL Server, o acesso, e o paradox.  Os exemplos de fontes de dados não DBMS incluem informações em sistemas de arquivos, no email, em planilhas, e as ferramentas de gerenciamento de projetos.  
  
 Considere um cenário em que um departamento de vendas precisa localizar todas as mensagens de email recebidas em um período de uma semana de clientes em qualquer área.  Essa consulta pode exigir uma pesquisa no arquivo da caixa de entrada de um aplicativo de email e uma pesquisa em uma tabela do Access de clientes especificar os nomes de clientes.  Quando o acesso é um aplicativo do DBMS, Outlook não é.  
  
 OLE DB permite que você desenvolva aplicativos que acessam diversas fontes de dados, se o DBMS são ou não.  OLE DB permite o acesso universal possível usar as interfaces COM que dão suporte à funcionalidade apropriado do DBMS para uma determinada fonte de dados.  COM reduz a duplicação desnecessária de serviços e de interoperabilidade maximizada não apenas entre fontes de dados mas também entre outros aplicativos.  
  
## Benefícios do COM  
 Isso é o local onde COM logon.  OLE DB é um conjunto de interfaces COM.  Acessando dados por meio de um par conjunto de interfaces, você pode organizar um base de dados em uma matriz de componentes de cooperação.  
  
 Com base na especificação de COM, OLE DB define uma coleção extensível e visando das interfaces que elas serão fatoradas e encapsulam partes consistentes, reutilizáveis de funcionalidade do DBMS.  Essas interfaces definem os limites de componentes do DBMS como contêiner de linha, processadores de consulta, e os engenheiros da transação, que habilitam o acesso transacional uniforme a várias fontes de informações.  
  
 Normalmente, os aplicativos OLE DB são gravados como DLL, mas sua implementação de COM supera as desvantagens da DLL \(como problemas de nomenclatura e da versão\) usando o código componentized.  No OLE DB, chame interfaces ou acessa outros componentes que usam os GUIDs \(identificadores globais exclusivos\).  
  
 Finalmente, COM o controla o uso componente usando a contagem de referência.  Quando você chama um método em uma interface, a contagem de referência é incrementada; quando o método retornar, a contagem de referência é reduzida.  Quando a contagem é igual a zero, o componente ao qual pertence o método são liberados.  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Modelos de banco de dados OLE](../Topic/OLE%20DB%20Templates.md)