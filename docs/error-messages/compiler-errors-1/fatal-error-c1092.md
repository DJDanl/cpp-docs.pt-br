---
title: Erro fatal C1092 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1092
dev_langs:
- C++
helpviewer_keywords:
- C1092
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9852b7b3d695d5414e52727ce672ee3258f6840b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077146"
---
# <a name="fatal-error-c1092"></a>Erro fatal C1092

Editar e continuar não dá suporte a alterações em tipos de dados; Compilar necessária

Alterados ou adicionados a um tipo de dados desde a última compilação bem-sucedida.

- Editar e continuar não suporta alterações em tipos de dados existentes, incluindo definições de classe, struct ou enum. Você deve parar a depuração e compilar o aplicativo.

- Editar e continuar não dá suporte a adição de novos tipos de dados se um arquivo de banco de dados do programa, como vc*x*0. pdb (onde *x* é a versão principal do Visual C++ em uso) é somente leitura. Para adicionar tipos de dados, o compilador deve abrir o arquivo. PDB no modo de gravação.

### <a name="to-remove-this-error-without-ending-the-current-debug-session"></a>Para remover esse erro sem encerrar a sessão de depuração atual

1. Altere o tipo de dados para seu estado antes do erro.

1. Dos **Debug** menu, escolha **aplicar alterações de código**.

### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar seu código-fonte

1. Dos **Debug** menu, escolha **parar depuração**.

1. Dos **Build** menu, escolha **Build**.

Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).