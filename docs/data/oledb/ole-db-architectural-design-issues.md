---
title: Problemas de design arquitetônico de banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- OLE DB, application design considerations
ms.assetid: 8caa7d99-d2bb-42c9-8884-74f228bb6ecc
ms.openlocfilehash: 2f0a7a114c671e17d8f95280ab00ed93570e8609
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037666"
---
# <a name="ole-db-architectural-design-issues"></a>Problemas de design arquitetônico de banco de dados OLE

Considere os seguintes problemas antes de iniciar seu aplicativo OLE DB:

## <a name="what-programming-implementation-will-you-use-to-write-your-ole-db-application"></a>Qual implementação de programação você usará para escrever seu aplicativo OLE DB?

A Microsoft oferece várias bibliotecas para realizar essa tarefa: uma biblioteca de modelos OLE DB, OLE DB atributos e as interfaces OLE DB brutas no SDK do OLE DB. Além disso, há assistentes que o ajudam a escrever o seu programa. Essas implementações são descritas em [modelos OLE DB, atributos e outras implementações](../../data/oledb/ole-db-templates-attributes-and-other-implementations.md).

## <a name="do-you-need-to-write-your-own-provider"></a>Você precisa escrever seu próprio provedor?

A maioria dos desenvolvedores não precisa escrever seu próprio provedor. A Microsoft fornece vários provedores. Sempre que você cria uma conexão de dados (por exemplo, quando você adiciona um consumidor ao seu projeto usando o **ATL OLE DB Assistente de consumidor**), o **propriedades de vínculo de dados** caixa de diálogo lista todos os provedores disponíveis registrado em seu sistema. Se um dos provedores é apropriado para seu próprio aplicativo de acesso de dados e armazenamento de dados, fazer a coisa mais fácil é usar uma destas opções. No entanto, se o armazenamento de dados não couber uma dessas categorias, você precisa criar seu próprio provedor. Para obter informações sobre como criar provedores, consulte [modelos OLE DB Provider](../../data/oledb/ole-db-provider-templates-cpp.md).

## <a name="what-level-of-support-do-you-need-for-your-consumer"></a>O nível de suporte precisa para que o consumidor?

Alguns consumidores podem ser básicas; enquanto outros podem ser complexos. A funcionalidade dos objetos de banco de dados OLE especificada pelas propriedades. Quando você usa o **ATL OLE DB Assistente de consumidor** para criar um consumidor ou o **Assistente de provedor de banco de dados** para criar um provedor, ele define as propriedades de objeto apropriado para você dar a você um conjunto padrão de funcionalidades. No entanto, se as classes de provedor ou consumidor gerado pelo assistente não dão suporte a tudo que você precisa que eles façam, você precisa para se referir às interfaces para essas classes na [OLE DB modelos de biblioteca](../../data/oledb/ole-db-templates.md). Essas interfaces encapsulam as interfaces OLE DB brutas, fornecendo uma implementação adicional para tornar a usá-los mais fácil para você.

Por exemplo, se você deseja atualizar dados em um conjunto de linhas, mas esqueceu de especificar isso quando você criou o consumidor com o assistente, você pode especificar a funcionalidade após o fato, definindo o `DBPROP_IRowsetChange` e `DBPROP_UPDATABILITY` propriedades no objeto de comando. Em seguida, quando o conjunto de linhas é criado, ele tem o `IRowsetChange` interface.

## <a name="do-you-have-older-code-using-another-data-access-technology-ado-odbc-or-dao"></a>Você tem código mais antigo usando outra tecnologia de acesso de dados (ADO, ODBC ou DAO)?

Considerando as combinações possíveis de tecnologias (por exemplo, usando componentes ADO com componentes de OLE DB e migrar o código do ODBC para OLE DB), que abrange todas as situações está além do escopo da documentação do Visual C++. No entanto, muitos artigos que abordam vários cenários estão disponíveis nos seguintes sites da Microsoft:

- [Ajuda e Suporte da Microsoft](https://support.microsoft.com/)

- [Visão geral do Microsoft Data Access artigos técnicos](https://msdn.microsoft.com/library/ms810811.aspx)

## <a name="see-also"></a>Consulte também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)
