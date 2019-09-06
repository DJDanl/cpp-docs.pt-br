---
title: Problemas de design arquitetônico de banco de dados OLE
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB, application design considerations
ms.assetid: 8caa7d99-d2bb-42c9-8884-74f228bb6ecc
ms.openlocfilehash: b481d9948d3055247bd284ca794a0fa65905e21b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311683"
---
# <a name="ole-db-architectural-design-issues"></a>Problemas de design arquitetônico de banco de dados OLE

> [!NOTE]
> O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

Considere os seguintes problemas antes de iniciar seu aplicativo OLE DB:

## <a name="what-programming-implementation-will-you-use-to-write-your-ole-db-application"></a>Qual implementação de programação você usará para escrever seu aplicativo OLE DB?

A Microsoft oferece várias bibliotecas para realizar essa tarefa: uma biblioteca de Modelos OLE DB, OLE DB atributos e as interfaces OLE DB brutas no SDK do OLE DB. Além disso, há assistentes que o ajudam a escrever o seu programa. Essas implementações são descritas em [Modelos, atributos e outras implementações de OLE DB](../../data/oledb/ole-db-templates-attributes-and-other-implementations.md).

## <a name="do-you-need-to-write-your-own-provider"></a>Você precisa escrever seu próprio provedor?

A maioria dos desenvolvedores não precisa escrever seu próprio provedor. A Microsoft fornece vários provedores. Sempre que você cria uma conexão de dados (por exemplo, ao adicionar um consumidor ao seu projeto usando o **Assistente de Consumidor OLE DB da ATL**), a caixa de diálogo **Propriedades do Link de Dados** lista todos os provedores disponíveis registrados em seu sistema. Se um dos provedores for apropriado para seu próprio armazenamento de dados e aplicativo de acesso a dados, a coisa mais fácil a ser feita é usar um deles. No entanto, se o armazenamento de dados não for adequado a uma dessas categorias, será preciso criar o seu próprio provedor. Saiba mais sobre como criar provedores em [Modelos de provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md).

## <a name="what-level-of-support-do-you-need-for-your-consumer"></a>De qual nível de suporte você precisa para seu consumidor?

Alguns consumidores podem ser básicos; enquanto outros podem ser complexos. A funcionalidade dos objetos OLE DB é especificada pelas propriedades. Quando você usa o **Assistente de Consumidor OLE DB da ATL** para criar um consumidor ou o **Assistente de Provedor de Banco de Dados** para criar um provedor, ele define as propriedades de objeto apropriadas para oferecer um conjunto padrão de funcionalidades. No entanto, se as classes de consumidor ou provedor geradas pelo assistente não forem compatíveis com tudo o que você precisa, será preciso fazer referência às interfaces dessas classes na [Biblioteca de Modelos OLE DB](../../data/oledb/ole-db-templates.md). Essas interfaces encapsulam as interfaces OLE DB brutas, fornecendo implementação adicional para tornar o uso delas mais fácil para você.

Por exemplo, se você deseja atualizar dados em um conjunto de linhas, mas esqueceu de especificar isso quando criou o consumidor com o assistente, é possível especificar a funcionalidade após o fato definindo as propriedades `DBPROP_IRowsetChange` e `DBPROP_UPDATABILITY` no objeto de comando. Assim, quando o conjunto de linhas for criado, ele terá a interface `IRowsetChange`.

## <a name="do-you-have-older-code-using-another-data-access-technology-ado-odbc-or-dao"></a>Você tem código mais antigo usando outra tecnologia de acesso de dados (ADO, ODBC ou DAO)?

Considerando as possíveis combinações de tecnologias (por exemplo, usando componentes ADO com componentes OLE DB e migrando o código ODBC para OLE DB), cobrir todas as situações está além do escopo da documentação do Visual C++. No entanto, muitos artigos que abordam vários cenários estão disponíveis nos seguintes sites da Microsoft:

- [Ajuda e Suporte da Microsoft](https://support.microsoft.com/)

- [Visão geral dos artigos técnicos do Microsoft Data Access](/previous-versions/ms810811(v=msdn.10))

## <a name="see-also"></a>Consulte também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)
