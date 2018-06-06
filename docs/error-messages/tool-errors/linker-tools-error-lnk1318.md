---
title: Ferramentas de vinculador erro LNK1318 | Microsoft Docs
ms.custom: ''
ms.date: 05/29/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1318
dev_langs:
- C++
helpviewer_keywords:
- LNK1318
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 364c819c6ec2bf6e1195011eced6e6ad1699877b
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34570679"
---
# <a name="linker-tools-error-lnk1318"></a>LNK1318 de erro de ferramentas de vinculador

> Erro inesperado ao PDB; *causar* '*detalhes*'

O vinculador encontrou um erro inesperado ao abrir, ler ou gravar em um arquivo PDB.

Essa mensagem de erro é gerada para problemas incomuns em arquivos PDB. O *causar* e *detalhes* representar as informações disponíveis para o vinculador quando a falha ocorreu. Isso não pode ser muito útil, como erros comuns ao lidar com arquivos PDB com mensagens de erro mais informativo, separada.

Como a origem do erro é raro, apenas aviso genérico está disponível para resolver esse problema:

- Executar uma operação de limpeza em seus diretórios de compilação e, em seguida, fazer uma compilação completa de sua solução.

- Reinicialize o computador, ou procurar processos mspdbsrv.exe suspenso ou perdidos e kill-los no Gerenciador de tarefas.

- Desative verificações antivírus em seus diretórios de projeto.

- Use o [/Zf](../../build/reference/zf.md) se usando a opção do compilador [/MP](../../build/reference/mp-build-with-multiple-processes.md) com o MSBuild ou outro paralela o processo de compilação.

- Tente construção usando o conjunto de ferramentas hospedado de 64 bits.

- Serialize vinculação para atenuar problemas de link paralelo, se necessário. Esse erro pode ser causado se mspdbsrv.exe é iniciado por uma instância do link e está desligada antes que outra instância do link é feita usá-lo. A desvantagem dessa correção é que as compilações de projeto podem levar muito tempo para concluir.