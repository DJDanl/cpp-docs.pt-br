---
title: Propriedades do depurador (Linux C++) | Microsoft Docs
ms.custom: ''
ms.date: 9/26/2017
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: 0c1c0fcc-a49b-451c-a5cb-ce9711fac064
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 55f07d8903d8110410648e352d364151bf6d2a73
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="c-debugging-properties-linux-c"></a>Propriedades do depurador C++ (Linux C++)

propriedade | Descrição | Opções
--- | ---| ---
Comando de pré-inicialização | Um comando que é executado no shell antes da depuração ser iniciada e antes do depurador estar em execução. Ele pode ser usado para afetar o ambiente de depuração.
Programa | O caminho completo para o programa a ser depurado no sistema remoto. É um caminho no sistema remoto. Se for deixado em branco ou inalterado, será assumido como a saída do projeto atual.
Argumentos do Programa | Os argumentos da linha de comando a serem passados ao programa que está sendo depurado.
Diretório de trabalho | O diretório de trabalho do aplicativo remoto. Por padrão, o diretório base do usuário.
Comandos adicionais do depurador | Comandos gdb adicionais para o depurador executar antes de iniciar a depuração.
Número da porta do depurador | O número da porta para a comunicação do depurador com o depurador remoto. A porta não deve estar em uso localmente. Esse valor deve ser positivo e estar entre 1 e 65535. Se não for fornecido, um número da porta disponível será usado.
Número da porta do depurador remoto | O número da porta na qual o servidor do depurador remoto (gdbserver) está escutando no sistema remoto. A porta não deve estar em uso no sistema remoto. Esse valor deve ser positivo e estar entre 1 e 65535. Se não for fornecido, um número da porta disponível começando em 4444 será usado.
Modo de depuração | Especifica como o depurador faz interface com o gdb. No modo gdb, o depurador direciona o gdb pelo shell no sistema remoto. No modo gdbserver, o gdb é executado localmente e conecta-se ao gdbserver que é executado remotamente. | **gdbserver**<br>**gdb**<br>
Caminhos de pesquisa de símbolo adicionais | Caminho de pesquisa adicional para símbolos de depuração (solib-search-path).
Depurar processos filhos | Especifica se é necessário habilitar a depuração dos processos filhos.
Habilitar estilos de formação Python | Habilite os estilos de formação de valores de expressão. Apenas há suporte no modo de depuração gdb.
Arquivo de visualização | Arquivo de visualização nativo padrão (.natvis) que contém as diretivas de visualização para os tipos SLT. Outros arquivos .natvis que pertencem à solução atual serão carregados automaticamente.
Mapa adicional de caminho de arquivo de origem | Equivalências de caminho adicionais para o depurador usar para mapear os nomes de arquivo de origem do Windows para os nomes de arquivo de origem do Linux. O formato é "\<windows-path>=\<linux-path>;...". Um nome de arquivo de origem encontrado no caminho do Windows será referenciado como se tivesse sido encontrado na mesma posição relativa no caminho do Linux. Os arquivos encontrados no projeto local não exigem mapeamento adicional.
