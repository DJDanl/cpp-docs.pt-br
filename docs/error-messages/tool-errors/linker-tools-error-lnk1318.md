---
title: Erro das Ferramentas de Vinculador LNK1318
ms.date: 05/29/2018
f1_keywords:
- LNK1318
helpviewer_keywords:
- LNK1318
ms.openlocfilehash: a61c11a9cbb25fea6fddc0bf1c5c4c2a7af1cf4f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183573"
---
# <a name="linker-tools-error-lnk1318"></a>Erro das Ferramentas de Vinculador LNK1318

> Erro de PDB inesperado; *causa* '*detalhes*'

O vinculador encontrou um erro inesperado ao abrir, ler ou gravar em um arquivo PDB.

Essa mensagem de erro é produzida para problemas incomuns em arquivos PDB. A *causa* e os *detalhes* representam as informações disponíveis para o vinculador quando a falha ocorreu. Isso pode não ser muito útil, pois erros comuns ao lidar com arquivos PDB têm mensagens de erro separadas e mais informativas.

Como a origem do erro é incomum, há apenas conselhos genéricos disponíveis para resolver esse problema:

- Execute uma operação de limpeza em seus diretórios de compilação e, em seguida, faça uma compilação completa da sua solução.

- Reinicialize o computador ou verifique se há processos MSPDBSRV. exe isolados ou desligados e elimine-os no taskmanager.

- Desative as verificações de antivírus em seus diretórios de projeto.

- Use a opção de compilador [/ZF](../../build/reference/zf.md) se estiver usando [/MP](../../build/reference/mp-build-with-multiple-processes.md) com MSBuild ou outro processo de compilação paralela.

- Tente criar usando o conjunto de ferramentas hospedados de 64 bits.

- Serialize a vinculação para atenuar problemas de link paralelo, se necessário. Esse erro pode ser causado se MSPDBSRV. exe for iniciado por uma instância do link e for desligado antes que outra instância do link seja feita usando-o. A desvantagem dessa correção é que as compilações do projeto podem levar consideravelmente mais tempo para serem concluídas.
