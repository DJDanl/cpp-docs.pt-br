---
title: "Problemas de design arquitet&#244;nico de banco de dados OLE | Microsoft Docs"
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
  - "OLE DB, considerações sobre o design de aplicativo"
ms.assetid: 8caa7d99-d2bb-42c9-8884-74f228bb6ecc
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Problemas de design arquitet&#244;nico de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Considere os seguintes problemas antes de iniciar o aplicativo OLE DB:  
  
 **What programming implementation will you use to write your OLE DB application?**  
 Microsoft oferece várias bibliotecas fazer isso: uma biblioteca do modelo do OLE DB, OLE DB, atributos e as interfaces brutos OLE DB no OLE DB SDK.  Além disso, há assistentes que o ajudam a gravar seu programa.  Essas implementações são descritas em [Modelos OLE DB, atributos, e outras implementações](../../data/oledb/ole-db-templates-attributes-and-other-implementations.md).  
  
 **Do you need to write your own provider?**  
 A maioria dos desenvolvedores não precisa escrever seu próprio provedor.  O Microsoft fornece diversos provedores.  Sempre que você criar uma conexão de dados \(por exemplo, quando você adicionar um consumidor ao seu projeto usando o assistente do consumidor de ATL OLE DB\), a caixa de diálogo de **Propriedades de associação de dados** lista todos os provedores disponíveis registrados em seu sistema.  Se um desses provedores é apropriado para seu próprio aplicativo do repositório de dados e de acesso a dados, à maneira mais fácil de fazer é usar um desses.  No entanto, se o repositório de dados não couber uma dessas categorias, você precisa criar seu próprio provedor.  Para obter informações sobre como criar provedores, consulte [Modelos do provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md).  
  
 **What level of support do you need for your consumer?**  
 Alguns consumidores podem ser muito básicos; quando outro podem ser muito complexos.  A funcionalidade de objetos OLE DB é especificada por propriedades.  Quando você usa o assistente do consumidor de ATL OLE DB para criar um consumidor ou o assistente do provedor de base de dados do para criar um provedor, defina as propriedades adequadas do objeto para o qual você atribua um conjunto padrão de funcionalidades.  No entanto, se as classes \- gerados ou do consumidor do provedor não dão suporte a todos você só precisam fazer, você precisar consultar as interfaces para essas classes em [Biblioteca de modelos OLE DB](../Topic/OLE%20DB%20Templates.md).  Essas interfaces envolvem as interfaces brutos do OLE DB, fornecendo a implementação adicional para facilitar usando as para você.  
  
 Por exemplo, se você quiser atualizar dados em um conjunto de linhas, mas esqueceu especificar essa opção quando você criou o consumidor com o assistente, você pode especificar a funcionalidade após o fato **DBPROP\_IRowsetChange** e definindo as propriedades de **DBPROP\_UPDATABILITY** no comando objeto.  Então, quando o conjunto de linhas é criado, tem a interface de `IRowsetChange` .  
  
 **Do you have older code using another data access technology \(ADO, ODBC, or DAO\)?**  
 Conforme as combinações possíveis de tecnologias \(como o uso de componentes do ADO com componentes do OLE DB e migrar o código do ODBC para OLE DB\), para cobrir todas as situações está além do escopo da documentação do Visual C\+\+.  Porém, muitos artigos que abrangem vários cenários estão disponíveis nos seguintes sites do Microsoft:  
  
-   [A Ajuda do Microsoft e Suporte](http://go.microsoft.com/fwlink/?LinkId=148218)  
  
-   [Visão geral dos artigos técnica de acesso a dados da Microsoft](http://go.microsoft.com/fwlink/?LinkId=148217)  
  
-   [Solution center do Visual Studio](http://go.microsoft.com/fwlink/?LinkId=148215)  
  
-   [Pesquisar Microsoft.com](http://search.microsoft.com/)  
  
 Quando você executa uma pesquisa, insira uma combinação de palavras\-chave que o mais adequado ao seu cenário; por exemplo: se você estava usando o ADO objetos com um provedor OLE DB, o tentará uma pesquisa booliano com **ADO AND "OLE DB"**.  Se você desejar migrar um código mais antigo de DAO a ODBC, selecione “todas as palavras” e especificar as cadeias de caracteres como **migrating DAO**.  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação de banco de dados OLE](../../data/oledb/ole-db-programming-overview.md)