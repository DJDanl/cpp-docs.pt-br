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
ms.openlocfilehash: a7e97781d245e236c57942db15d61080d6418cfa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209268"
---
# <a name="using-stored-procedures"></a>Usando procedimentos armazenados

Um procedimento armazenado é um objeto executável armazenado em um banco de dados. Chamar um procedimento armazenado é semelhante a invocar um comando SQL. O uso de procedimentos armazenados na fonte de dados (em vez de executar ou preparar uma instrução no aplicativo cliente) pode fornecer várias vantagens, incluindo melhor desempenho, sobrecarga de rede reduzida e consistência e precisão aprimoradas.

Um procedimento armazenado pode ter qualquer número de parâmetros de entrada ou saída (incluindo zero) e pode passar um valor de retorno. Você pode codificar valores de parâmetro como valores de dados específicos ou usar um marcador de parâmetro (um ponto de interrogação '? ').

> [!NOTE]
>  CLR SQL Server procedimentos armazenados criados usando o C++ Visual devem ser compilados com a opção de compilador `/clr:safe`.

O provedor de OLE DB para SQL Server (SQLOLEDB) dá suporte aos seguintes mecanismos que os procedimentos armazenados usam para retornar dados:

- Cada instrução **Select** no procedimento gera um conjunto de resultados.

- O procedimento pode retornar dados através de parâmetros de saída.

- O procedimento pode ter um código de retorno de inteiro.

> [!NOTE]
> Você não pode usar procedimentos armazenados com o provedor de OLE DB para Jet porque esse provedor não oferece suporte a procedimentos armazenados; somente constantes são permitidas em cadeias de caracteres de consulta.

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)
