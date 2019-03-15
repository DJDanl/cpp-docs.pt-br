---
title: Opções EDITBIN
ms.date: 11/04/2016
f1_keywords:
- editbin
helpviewer_keywords:
- EDITBIN program, options
ms.assetid: 2da9f88e-cbab-4d64-bb66-ef700535230f
ms.openlocfilehash: e7338c6a45d74aa8efac1b72683cca7661c62e0a
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820098"
---
# <a name="editbin-options"></a>Opções EDITBIN

Você pode usar (editbin) para modificar os arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLLs). Opções especificam as alterações que faz (editbin).

Uma opção consiste em um especificador de opção, que é um traço (-) ou uma barra (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções de levam os argumentos que são especificados após dois-pontos (:). Não há espaços ou tabulações são permitidas em uma especificação de opção. Use um ou mais espaços ou tabulações para separar as especificações de opção na linha de comando. Nomes de opções e seus argumentos de palavra-chave ou os argumentos de nome de arquivo não diferenciam maiusculas de minúsculas. Por exemplo, - bind e /BIND. significam a mesma coisa.

(Editbin) tem as seguintes opções:

|Opção|Finalidade|
|------------|-------------|
|[/ALLOWBIND](allowbind.md)|Especifica se uma DLL pode ser associada.|
|[/ALLOWISOLATION](allowisolation.md)|Especifica o comportamento de pesquisa de manifesto de arquivo executável ou DLL.|
|[/APPCONTAINER](appcontainer.md)|Especifica se o aplicativo deve ser executado em um AppContainer — por exemplo, um aplicativo UWP.|
|[/BIND](bind.md)|Define os endereços para os pontos de entrada em que os objetos especificados para acelerar o tempo de carga.|
|[/DYNAMICBASE](dynamicbase.md)|Especifica se a imagem executável ou DLL pode trocar base aleatoriamente no momento do carregamento usando randomização de layout de espaço de endereço (ASLR).|
|[/ERRORREPORT](errorreport-editbin-exe.md)|Erros internos de relatórios à Microsoft.|
|[/HEAP](heap.md)|Define o tamanho do heap da imagem executável em bytes.|
|[/HIGHENTROPYVA](highentropyva.md)|Especifica se a DLL ou uma imagem executável dá suporte a randomização de layout de espaço de endereço (64 bits) de alta entropia (ASLR).|
|[/INTEGRITYCHECK](integritycheck.md)|Especifica se é necessário verificar a assinatura digital no tempo de carregamento.|
|[/LARGEADDRESSAWARE](largeaddressaware.md)|Especifica se o objeto dá suporte a endereços maiores que dois gigabytes.|
|[/NOLOGO](nologo-editbin.md)|Suprime a faixa de inicialização (editbin).|
|[/NXCOMPAT](nxcompat.md)|Especifica se a imagem executável é compatível com Windows Data Execution Prevention.|
|[/REBASE](rebase.md)|Define os endereços base para os objetos especificados.|
|[/RELEASE](release.md)|Define a soma de verificação no cabeçalho.|
|[/ SEÇÃO](section-editbin.md)|Substitui os atributos de uma seção.|
|[/STACK](stack.md)|Define o tamanho da pilha da imagem executável em bytes.|
|[/SUBSYSTEM](subsystem.md)|Especifica o ambiente de execução.|
|[/SWAPRUN](swaprun.md)|Especifica que a imagem executável deve ser copiada para o arquivo de permuta e, em seguida, executar a partir daí.|
|[/TSAWARE](tsaware.md)|Especifica que o aplicativo foi projetado para ser executado em um ambiente multiusuário.|
|[/VERSION](version.md)|Define o número de versão no cabeçalho.|

## <a name="see-also"></a>Consulte também

[Ferramentas de Build do MSVC adicionais](c-cpp-build-tools.md)<br/>
[Referência de EDITBIN](editbin-reference.md)
