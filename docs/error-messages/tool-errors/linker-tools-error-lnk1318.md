---
title: Erro das Ferramentas de Vinculador LNK1318
ms.date: 05/29/2018
f1_keywords:
- LNK1318
helpviewer_keywords:
- LNK1318
ms.openlocfilehash: cce2c03783039a62b5cb6f60ecf8d76b23589483
ms.sourcegitcommit: e15b46ea7888dbdd7e0bb47da76aeed680c3c1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2020
ms.locfileid: "86446695"
---
# <a name="linker-tools-error-lnk1318"></a>Erro das Ferramentas de Vinculador LNK1318

> Erro de PDB inesperado; *causa* '*detalhes*'

O vinculador encontrou um erro inesperado ao abrir, ler ou gravar em um arquivo PDB.

Essa mensagem de erro é produzida para problemas incomuns em arquivos PDB. A *causa* e os *detalhes* representam as informações disponíveis para o vinculador quando a falha ocorreu. Isso pode não ser muito útil, pois erros comuns ao lidar com arquivos PDB têm mensagens de erro separadas e mais informativas.

Como a origem do erro é incomum, há apenas conselhos genéricos disponíveis para resolver esse problema:

- Execute uma operação de limpeza em seus diretórios de compilação e, em seguida, faça uma compilação completa da sua solução.

- Reinicialize o computador ou verifique se há processos de mspdbsrv.exe isolados ou sem resposta e elimine-os no taskmanager.

- Desative as verificações de antivírus em seus diretórios de projeto.

- Use a opção de compilador [/ZF](../../build/reference/zf.md) se estiver usando [/MP](../../build/reference/mp-build-with-multiple-processes.md) com MSBuild ou outro processo de compilação paralela.

- Tente criar usando o conjunto de ferramentas hospedados de 64 bits.

- Serialize a vinculação para atenuar problemas de link paralelo, se necessário. Esse erro pode ser causado se mspdbsrv.exe é iniciado por uma instância do link e é desligado antes que outra instância do link seja feita usando-o. A desvantagem dessa correção é que as compilações do projeto podem levar consideravelmente mais tempo para serem concluídas.
