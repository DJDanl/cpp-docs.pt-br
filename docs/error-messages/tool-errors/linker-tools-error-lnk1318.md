---
title: Erro das Ferramentas de Vinculador LNK1318
ms.date: 05/29/2018
f1_keywords:
- LNK1318
helpviewer_keywords:
- LNK1318
ms.openlocfilehash: 8ed6489a27d4c0e117f7f18281ff188f40936e0a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160985"
---
# <a name="linker-tools-error-lnk1318"></a>Erro das Ferramentas de Vinculador LNK1318

> Erro PDB inesperado; *causar* '*detalhes*'

O vinculador encontrou um erro inesperado ao abrir, ler ou gravar em um arquivo PDB.

Essa mensagem de erro é produzida para problemas incomuns em arquivos PDB. O *causar* e *detalhes* representam as informações disponíveis para o vinculador quando a falha ocorreu. Isso não pode ser muito úteis, como erros comuns ao lidar com arquivos PDB ter mensagens de erro mais informativo separado.

Como a origem do erro é incomum, apenas orientação genérica está disponível para resolver esse problema:

- Executar uma operação de limpeza em seus diretórios de compilação e, em seguida, fazer uma compilação completa de sua solução.

- Reinicializar o computador, ou verificar se há processos isolados ou travada mspdbsrv.exe e kill-los no Gerenciador de tarefas.

- Desative a verificações antivírus em seus diretórios de projeto.

- Use o [/Zf](../../build/reference/zf.md) se usando a opção do compilador [/MP](../../build/reference/mp-build-with-multiple-processes.md) com o MSBuild ou outro paralela o processo de compilação.

- Tente compilar usando o conjunto de ferramentas hospedado de 64 bits.

- Serialização de vinculação para atenuar problemas de link paralelo, se necessário. Esse erro pode ser causado se mspdbsrv.exe é iniciado por uma instância do link e é desligado antes que outra instância do link é feita usá-lo. A desvantagem dessa correção é que suas compilações do projeto podem demorar muito para ser concluída.