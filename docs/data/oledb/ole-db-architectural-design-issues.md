---
title: "Problemas de Design arquitetônico de banco de dados OLE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: OLE DB, application design considerations
ms.assetid: 8caa7d99-d2bb-42c9-8884-74f228bb6ecc
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 085c658fff3d387019c6e8574ebafcd347400823
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ole-db-architectural-design-issues"></a>Problemas de design arquitetônico de banco de dados OLE
Você deve considerar os seguintes problemas antes de iniciar seu aplicativo OLE DB:  
  
 **Qual implementação programação será usado para gravar seu aplicativo OLE DB?**  
 A Microsoft oferece várias bibliotecas para fazer isso: uma biblioteca de modelos de banco de dados OLE, atributos de OLE DB e as interfaces do OLE DB brutas no SDK do OLE DB. Além disso, há assistentes que o ajudam a gravar seu programa. Essas implementações são descritas na [modelos OLE DB, atributos e outras implementações](../../data/oledb/ole-db-templates-attributes-and-other-implementations.md).  
  
 **Você precisa escrever seu próprio provedor?**  
 A maioria dos desenvolvedores não precisa escrever seu próprio provedor. A Microsoft fornece vários provedores. Sempre que você criar uma conexão de dados (por exemplo, quando você adiciona um consumidor ao seu projeto usando o Assistente de ATL OLE DB consumidor), o **propriedades de vínculo de dados** caixa de diálogo lista todos os provedores disponíveis registrados no seu sistema. Se um desses provedores é apropriado para seu próprio aplicativo de acesso de dados e armazenamento de dados, o mais fácil fazer é usar uma destas opções. No entanto, se o armazenamento de dados não couber uma dessas categorias, você precisa criar seu próprio provedor. Para obter informações sobre como criar provedores, consulte [modelos OLE DB Provider](../../data/oledb/ole-db-provider-templates-cpp.md).  
  
 **O nível de suporte para o consumidor você precisa?**  
 Alguns consumidores podem ser muito básicas; enquanto outros podem ser muito complexos. A funcionalidade dos objetos de banco de dados OLE especificada pelas propriedades. Quando você usa o ATL OLE DB consumidor Assistente para criar um consumidor ou o Assistente de provedor de banco de dados para criar um provedor, ele define as propriedades de objeto apropriado para fornecer um conjunto padrão de funcionalidades. No entanto, se as classes de provedor ou consumidor gerado pelo assistente não oferecem suporte a tudo o que precisar fazer, você precisa se referir às interfaces para essas classes do [OLE DB modelos de biblioteca](../../data/oledb/ole-db-templates.md). Essas interfaces encapsulam as interfaces OLE DB brutas, fornecendo uma implementação extra para facilitar usá-los para você.  
  
 Por exemplo, se você quiser atualizar dados em um conjunto de linhas, mas esqueceu de especificar isso quando você criou o consumidor com o assistente, você pode especificar a funcionalidade após o fato definindo o **DBPROP_IRowsetChange** e  **DBPROP_UPDATABILITY** propriedades no objeto de comando. Em seguida, quando o conjunto de linhas é criado, ele tem o `IRowsetChange` interface.  
  
 **Você tem o código anterior usando outra tecnologia de acesso a dados (ADO, ODBC ou DAO)?**  
 Considerando as combinações possíveis de tecnologias (como usar componentes de ADO com componentes de OLE DB e migrando código ODBC para o banco de dados OLE), que abrangem todas as situações está além do escopo da documentação do Visual C++. No entanto, vários artigos que abrangem vários cenários estão disponíveis nos seguintes sites:  
  
-   [Ajuda e Suporte da Microsoft](http://go.microsoft.com/fwlink/?linkid=148218)  
  
-   [Visão geral de artigos técnicos do Microsoft Data Access](http://go.microsoft.com/fwlink/?linkid=148217)  
  
-   [Centro de soluções do Visual Studio](http://go.microsoft.com/fwlink/?linkid=148215)  
  
-   [Pesquisar no Microsoft.com](http://search.microsoft.com/)  
  
 Quando você executa uma pesquisa, insira uma combinação de palavras-chave que melhor se adapta ao seu cenário; Por exemplo: se você estiver usando objetos ADO com um provedor OLE DB, tente fazer uma pesquisa booliana com **ADO e "OLE DB"**. Se você quiser migrar código DAO anterior para ODBC, selecione "todas as palavras" e especificar cadeias de caracteres como **DAO migrando**.  
  
## <a name="see-also"></a>Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)