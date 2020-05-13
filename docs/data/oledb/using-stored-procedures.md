---
title: Usando procedimentos armazenados
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB, stored procedures
- stored procedures, Visual C++
- stored procedures, about stored procedures
- OLE DB provider templates, stored procedures
- stored procedures, OLE DB
ms.assetid: 90507e4c-eca2-46c9-ad8c-07e10dc1d41b
ms.openlocfilehash: 436c796b24b0fa498f2b3f45e848392635b22a34
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376036"
---
# <a name="using-stored-procedures"></a>Usando procedimentos armazenados

Um procedimento armazenado é um objeto executável armazenado em um banco de dados. Chamar um procedimento armazenado é semelhante a invocar um comando SQL. O uso de procedimentos armazenados na fonte de dados (em vez de executar ou preparar uma declaração no aplicativo do cliente) pode fornecer várias vantagens, incluindo maior desempenho, redução da sobrecarga da rede e maior consistência e precisão.

Um procedimento armazenado pode ter qualquer número de (incluindo zero) parâmetros de entrada ou saída e pode passar um valor de retorno. Você pode usar valores de parâmetro de código rígido como valores de dados específicos ou usar um marcador de parâmetro (um ponto de interrogação '?').

> [!NOTE]
> Os procedimentos armazenados pelo CLR SQL Server criados `/clr:safe` usando o Visual C++ devem ser compilados com a opção compilador.

O provedor OLE DB para SQLOLEDB (SQLOLEDB) suporta os seguintes mecanismos que os procedimentos armazenados usam para retornar dados:

- Cada declaração **SELECT** no procedimento gera um conjunto de resultados.

- O procedimento pode retornar dados através de parâmetros de saída.

- O procedimento pode ter um código de retorno de inteiro.

> [!NOTE]
> Não é possível usar procedimentos armazenados com o provedor OLE DB da Jet porque esse provedor não suporta procedimentos armazenados; apenas constantes são permitidas em strings de consulta.

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)
