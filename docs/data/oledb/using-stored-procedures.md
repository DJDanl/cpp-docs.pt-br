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
ms.openlocfilehash: 7ace43283c56c0c859b193f63e8ca104f6b52a31
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041167"
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

[Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)