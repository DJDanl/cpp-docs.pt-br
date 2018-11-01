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
ms.openlocfilehash: 2c0c1c71103384439d0b7b94f942e1b5a6d9e651
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536144"
---
# <a name="using-stored-procedures"></a>Usando procedimentos armazenados

Um procedimento armazenado é um objeto executável armazenado em um banco de dados. Chamar um procedimento armazenado é semelhante ao invocar um comando SQL. Usando procedimentos armazenados na fonte de dados (em vez de executar ou preparar uma instrução no aplicativo cliente) pode fornecer várias vantagens, incluindo o melhor desempenho, sobrecarga de rede reduzida e aprimorar a consistência e precisão.

Um procedimento armazenado pode ter qualquer número de (incluindo zero) entrada ou parâmetros de saída e pode passar um valor de retorno. É possível que qualquer um dos valores de parâmetro de embutir no código como valores de dados específicos ou usam um marcador de parâmetro (um ponto de interrogação '?').

> [!NOTE]
>  CLR SQL Server, procedimentos armazenados criados usando o Visual C++ devem ser compilados com o `/clr:safe` opção de compilador.

O provedor OLE DB para SQL Server (SQLOLEDB) suporta os seguintes mecanismos que armazenados o uso de procedimentos para retornar dados:

- Cada **selecionar** instrução no procedimento gera um conjunto de resultados.

- O procedimento pode retornar dados por meio de parâmetros de saída.

- O procedimento pode ter um número inteiro de código de retorno.

> [!NOTE]
> Você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não dá suporte a procedimentos armazenados; somente constantes são permitidas nas cadeias de caracteres de consulta.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)