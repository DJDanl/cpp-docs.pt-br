---
title: Erro fatal C1092
ms.date: 11/04/2016
f1_keywords:
- C1092
helpviewer_keywords:
- C1092
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
ms.openlocfilehash: af43ddb83e872762f720b156644e0d466957a8a7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203873"
---
# <a name="fatal-error-c1092"></a>Erro fatal C1092

Editar e continuar não oferece suporte a alterações em tipos de dados; compilação necessária

Você alterou ou adicionou um tipo de dados desde a última compilação bem-sucedida.

- Editar e continuar não oferece suporte a alterações em tipos de dados existentes, incluindo definições de classe, struct ou enumeração. Você deve parar a depuração e compilar o aplicativo.

- Editar e continuar não dá suporte à adição de novos tipos de dados se um arquivo de banco de dado do programa, como vc*x*0. PDB (em que *x* é C++ a principal versão do Visual em uso) é somente leitura. Para adicionar tipos de dados, o compilador deve abrir o arquivo. pdb no modo de gravação.

### <a name="to-remove-this-error-without-ending-the-current-debug-session"></a>Para remover este erro sem encerrar a sessão de depuração atual

1. Altere o tipo de dados de volta para seu estado anterior ao erro.

1. No menu **depurar** , escolha **aplicar alterações de código**.

### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar o código-fonte

1. No menu **depurar** , escolha **parar depuração**.

1. No menu **Compilar** , escolha **Compilar**.

Para obter mais informações, consulte as [alterações de código com suporte](/visualstudio/debugger/supported-code-changes-cpp).
