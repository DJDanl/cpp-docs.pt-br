---
title: Propriedades do depurador (Linux C++) | Microsoft Docs
ms.date: 06/07/2019
ms.assetid: 0c1c0fcc-a49b-451c-a5cb-ce9711fac064
ms.openlocfilehash: d76e398d648db7c5cf65e4ca2bb1665aef4359ad
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821404"
---
# <a name="c-debugging-properties-linux-c"></a>Propriedades do depurador C++ (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

Propriedade | Descrição | Opções
--- | ---| ---
Computador de depuração remoto | **Visual Studio 2019 versão 16.1**: Especifica o computador no qual o programa será depurado. Pode ser diferente do computador de build remoto especificado na página [Geral](general-linux.md).
Comando de pré-inicialização | Um comando que é executado no shell antes do depurador ser iniciado, que possa ser usado para afetar o ambiente de depuração.
Programa | O caminho completo no sistema remoto para programa a ser depurado. Se ele for deixado em branco ou inalterado, usará como padrão a saída do projeto atual.
Argumentos do Programa | Os argumentos de linha de comando a serem passados ao programa que está sendo depurado.
Diretório de trabalho | O diretório de trabalho do aplicativo remoto. Por padrão, o diretório base do usuário.
Comandos adicionais do depurador | Comandos `gdb` adicionais para o depurador executar antes de iniciar a depuração.
Número da porta do depurador | O número da porta para a comunicação do depurador com o depurador remoto. A porta não deve estar em uso localmente. Esse valor precisa ser positivo e estar entre 1 e 65535. Se ele não for fornecido, um número de porta disponível será usado.
Número da porta do depurador remoto | O número da porta no qual o servidor do depurador remoto `gdbserver` está escutando no sistema remoto. A porta não deve estar em uso no sistema remoto. Esse valor precisa ser positivo e estar entre 1 e 65535. Se ele não for fornecido, um número de porta disponível começando com 4444 será usado.
Modo de depuração | Especifica como o depurador faz interface com o `gdb`. No *modo do gdb*, o depurador direciona o `gdb` para o shell no sistema remoto. Na *modo do gdbserver*, o `gdb` é executado localmente e se conecta ao `gdbserver` executado remotamente. | **gdbserver**<br/>**gdb**
Caminhos de pesquisa de símbolo adicionais | Caminho de pesquisa adicional para símbolos de depuração (solib-search-path).
Depurar processos filhos | Especifica se é necessário habilitar a depuração dos processos filhos.
Habilitar estilos de formação Python | Habilite os estilos de formação de valores de expressão. Apenas há suporte no modo de depuração gdb.
Arquivo de visualização | Arquivo de visualização nativo padrão (.natvis) que contém as diretivas de visualização para os tipos SLT. Outros arquivos .natvis que pertencem à solução atual são carregados automaticamente.
Mapa adicional de caminho de arquivo de origem | Equivalências de caminho adicionais para o depurador usar para mapear os nomes de arquivo de origem do Windows para os nomes de arquivo de origem do Linux. O formato é "\<windows-path>=\<linux-path>;...". Um nome de arquivo de origem encontrado no caminho do Windows é referenciado como se fosse encontrado na mesma posição relativa no caminho do Linux. Os arquivos encontrados no projeto local não exigem mapeamento adicional.

::: moniker-end
