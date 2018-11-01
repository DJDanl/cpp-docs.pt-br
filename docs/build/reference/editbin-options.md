---
title: Opções EDITBIN
ms.date: 11/04/2016
f1_keywords:
- editbin
helpviewer_keywords:
- EDITBIN program, options
ms.assetid: 2da9f88e-cbab-4d64-bb66-ef700535230f
ms.openlocfilehash: 263cfb79897ae60daff64521928db865f1dcb874
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50540537"
---
# <a name="editbin-options"></a>Opções EDITBIN

Você pode usar (editbin) para modificar os arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLLs). Opções especificam as alterações que faz (editbin).

Uma opção consiste em um especificador de opção, que é um traço (-) ou uma barra (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções de levam os argumentos que são especificados após dois-pontos (:). Não há espaços ou tabulações são permitidas em uma especificação de opção. Use um ou mais espaços ou tabulações para separar as especificações de opção na linha de comando. Nomes de opções e seus argumentos de palavra-chave ou os argumentos de nome de arquivo não diferenciam maiusculas de minúsculas. Por exemplo, - bind e /BIND. significam a mesma coisa.

(Editbin) tem as seguintes opções:

|Opção|Finalidade|
|------------|-------------|
|[/ALLOWBIND](../../build/reference/allowbind.md)|Especifica se uma DLL pode ser associada.|
|[/ALLOWISOLATION](../../build/reference/allowisolation.md)|Especifica o comportamento de pesquisa de manifesto de arquivo executável ou DLL.|
|[/APPCONTAINER](../../build/reference/appcontainer.md)|Especifica se o aplicativo deve ser executado em um AppContainer — por exemplo, um aplicativo UWP.|
|[/BIND](../../build/reference/bind.md)|Define os endereços para os pontos de entrada em que os objetos especificados para acelerar o tempo de carga.|
|[/DYNAMICBASE](../../build/reference/dynamicbase.md)|Especifica se a imagem executável ou DLL pode trocar base aleatoriamente no momento do carregamento usando randomização de layout de espaço de endereço (ASLR).|
|[/ERRORREPORT](../../build/reference/errorreport-editbin-exe.md)|Erros internos de relatórios à Microsoft.|
|[/HEAP](../../build/reference/heap.md)|Define o tamanho do heap da imagem executável em bytes.|
|[/HIGHENTROPYVA](../../build/reference/highentropyva.md)|Especifica se a DLL ou uma imagem executável dá suporte a randomização de layout de espaço de endereço (64 bits) de alta entropia (ASLR).|
|[/INTEGRITYCHECK](../../build/reference/integritycheck.md)|Especifica se é necessário verificar a assinatura digital no tempo de carregamento.|
|[/LARGEADDRESSAWARE](../../build/reference/largeaddressaware.md)|Especifica se o objeto dá suporte a endereços maiores que dois gigabytes.|
|[/NOLOGO](../../build/reference/nologo-editbin.md)|Suprime a faixa de inicialização (editbin).|
|[/NXCOMPAT](../../build/reference/nxcompat.md)|Especifica se a imagem executável é compatível com Windows Data Execution Prevention.|
|[/REBASE](../../build/reference/rebase.md)|Define os endereços base para os objetos especificados.|
|[/RELEASE](../../build/reference/release.md)|Define a soma de verificação no cabeçalho.|
|[/ SEÇÃO](../../build/reference/section-editbin.md)|Substitui os atributos de uma seção.|
|[/STACK](../../build/reference/stack.md)|Define o tamanho da pilha da imagem executável em bytes.|
|[/SUBSYSTEM](../../build/reference/subsystem.md)|Especifica o ambiente de execução.|
|[/SWAPRUN](../../build/reference/swaprun.md)|Especifica que a imagem executável deve ser copiada para o arquivo de permuta e, em seguida, executar a partir daí.|
|[/TSAWARE](../../build/reference/tsaware.md)|Especifica que o aplicativo foi projetado para ser executado em um ambiente multiusuário.|
|[/VERSION](../../build/reference/version.md)|Define o número de versão no cabeçalho.|

## <a name="see-also"></a>Consulte também

[Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)<br/>
[Referência de EDITBIN](../../build/reference/editbin-reference.md)