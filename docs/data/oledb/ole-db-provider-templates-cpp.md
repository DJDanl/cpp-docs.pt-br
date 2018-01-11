---
title: Modelos de provedor do OLE DB (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB providers [C++], about providers
- databases [C++], OLE DB templates
- OLE DB provider templates [C++], about OLE DB provider templates
- templates [C++], OLE DB
ms.assetid: fccff85f-2af8-4500-82bd-6312d28a74b8
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f95b32d62d964c83853025ed4e4af9b90e7a630a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ole-db-provider-templates-c"></a>Modelos de provedor de banco de dados OLE (C++)
OLE DB é uma parte importante da estratégia de acesso a dados Universal Microsoft. O design de banco de dados OLE permite acesso a dados de alto desempenho de qualquer fonte de dados. Dados de tabela são visíveis através do OLE DB, independentemente se ela veio de um banco de dados. A flexibilidade lhe oferecem uma enorme quantidade de energia.  
  
 Conforme explicado em [consumidores do OLE DB e provedores de](../../data/oledb/ole-db-consumers-and-providers.md), o conceito de consumidores e provedores do OLE DB usa. O consumidor faz solicitações de dados. o provedor retorna dados em um formato de tabela para o consumidor. De uma perspectiva de programação, a mais importante implicação desse modelo é que o provedor deve implementar qualquer chamada que o consumidor pode fazer.  
  
## <a name="what-is-a-provider"></a>O que é um provedor?  
 Um provedor OLE DB é um conjunto de objetos COM que atender a chamadas de interface de um objeto do consumidor, a transferência de dados em um formato tabular de uma fonte durável (chamada de um repositório de dados) para o consumidor.  
  
 Provedores podem ser simples ou complexa. O provedor pode dar suporte a uma quantidade mínima de funcionalidade ou um provedor de qualidade de produção completo implementando interfaces mais. Um provedor pode retornar uma tabela, permitem que o cliente determinar o formato de tabela e executar operações em que os dados.  
  
 Cada provedor implementa um conjunto padrão de objetos para lidar com solicitações do cliente, com significado padrão que o consumidor OLE DB pode acessar dados de qualquer provedor, independentemente do idioma (como C++ e básica).  
  
 Cada objeto COM contém várias interfaces, alguns dos quais são necessários e alguns dos quais são opcionais. Ao implementar as interfaces obrigatórias, um provedor garante um nível mínimo de funcionalidade (chamada conformidade) que qualquer cliente deve ser capaz de usar. Um provedor pode implementar interfaces opcionais para fornecer funcionalidade adicional. [O OLE DB Provider arquitetura de modelo](../../data/oledb/ole-db-provider-template-architecture.md) descreve essas interfaces em detalhes. O cliente sempre deve chamar `QueryInterface` para determinar se um provedor oferece suporte a uma determinada interface.  
  
## <a name="ole-db-specification-level-support"></a>Suporte de nível de especificação do OLE DB  
 Os modelos de provedor do OLE DB oferecer suporte a especificação de versão 2.7 OLE DB. Usando os modelos de provedor do OLE DB, você pode implementar um provedor compatível com o nível 0. O exemplo de provedor, por exemplo, usa os modelos para implementar um servidor de comando non-MS-DOS que executa o comando DIR para consultar o sistema de arquivos. O exemplo de provedor retorna as informações do diretório em um conjunto de linhas, que é o mecanismo de banco de dados OLE padrão para retornar dados tabulares.  
  
 O tipo mais simples de provedor com suporte os modelos OLE DB é um provedor somente leitura com nenhum comando. Provedores de comandos também são compatíveis, pois são recurso marcando e leitura/gravação. Você pode implementar um provedor de leitura/gravação ao escrever código adicional. Transações e conjuntos de linhas dinâmicos não são suportadas pela versão atual, mas você pode adicioná-los se desejar.  
  
## <a name="when-do-you-need-to-create-an-ole-db-provider"></a>Quando você precisa criar um provedor OLE DB?  
 Você sempre precisa criar seu próprio provedor; A Microsoft fornece vários provedores predefinidos e padrão no **propriedades de vínculo de dados** caixa de diálogo no Visual C++. É o principal motivo para criar um provedor OLE DB para se beneficiar da estratégia de acesso a dados Universal. Algumas das vantagens de fazer, portanto, são:  
  
-   Acessando dados através de qualquer linguagem como C++, Basic e Visual Basic Scripting Edition. Ele permite que os programadores diferentes em sua organização para acessar os mesmos dados da mesma maneira, independentemente da linguagem em que eles usam.  
  
-   Expondo seus dados para outros dados de fontes como o SQL Server, o Excel e o acesso. Isso pode ser muito útil se você quiser transferir dados entre formatos diferentes.  
  
-   Participar de operações de fonte de dados entre (heterogêneos). Isso pode ser uma maneira muito eficiente de data warehouse. Usando provedores OLE DB, você pode manter os dados em seu formato nativo e ainda é possível acessá-lo em uma operação simple.  
  
-   Adicionando recursos adicionais para seus dados, como o processamento de consulta.  
  
-   Aumentando o desempenho de acesso aos dados por meio do controle como ele é manipulado.  
  
-   Aumentar a robustez. Se você tiver um formato de dados proprietários que apenas um programador pode acessar, estão em risco. Usando provedores OLE DB, você pode abrir esse formato proprietário para todas as suas programadores.  
  
## <a name="read-only-and-updatable-providers"></a>Provedores atualizáveis e somente leitura  
 Provedores podem variar muito em complexidade e funcionalidade. É útil categorizar provedores em provedores somente leitura e atualizável:  
  
-   Visual C++ 6.0 tem suporte apenas a provedores somente leitura. [Criando um provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md) discute como criar um provedor somente leitura.  
  
-   Provedores atualizáveis, o que podem ser atualizada pela linguagem Visual C++ (gravar) no repositório de dados. Para obter informações sobre provedores atualizáveis, consulte [criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md); o [UpdatePV](http://msdn.microsoft.com/en-us/c8bed873-223c-4a7d-af55-f90138c6f38f) é um exemplo de um provedor atualizável.  
  
 Para obter mais informações, consulte:  
  
-   [A arquitetura de modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)  
  
-   [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)  
  
-   [Programação do OLE DB](../../data/oledb/ole-db-programming.md)  
  
## <a name="see-also"></a>Consulte também  
 [Acesso a dados](../data-access-in-cpp.md)   
 [Documentação do SDK do OLE DB](https://msdn.microsoft.com/en-us/library/ms722784.aspx)   
 [Referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx)