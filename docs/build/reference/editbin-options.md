---
title: Opções EDITBIN
description: Guia de referência para as opções de linha de comando do utilitário do Microsoft EDITBIN.
ms.date: 02/09/2020
f1_keywords:
- editbin
helpviewer_keywords:
- EDITBIN program, options
ms.assetid: 2da9f88e-cbab-4d64-bb66-ef700535230f
ms.openlocfilehash: c27172522ceabeccd06d7b957aa791edc49beec8
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257696"
---
# <a name="editbin-options"></a>Opções EDITBIN

Você pode usar EDITBIN para modificar arquivos de objeto, arquivos executáveis e DLLs (bibliotecas de vínculo dinâmico). As opções especificam as alterações que o EDITBIN faz.

Uma opção consiste em um especificador de opção, que é um traço (`-`) ou uma barra (`/`), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam argumentos que são especificados após um sinal de dois-pontos (`:`). Não são permitidos espaços ou guias dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Nomes de opção e seus argumentos de palavra-chave ou argumentos de nome de arquivo não diferenciam maiúsculas de minúsculas Por exemplo, `-bind` e `/BIND` significam a mesma coisa.

EDITBIN tem as seguintes opções:

|Opção|Finalidade|
|------------|-------------|
|[/ALLOWBIND](allowbind.md)|Especifica se uma DLL pode ser associada.|
|[/ALLOWISOLATION](allowisolation.md)|Especifica o comportamento de pesquisa de manifesto de arquivo executável ou DLL.|
|[/APPCONTAINER](appcontainer.md)|Especifica se o aplicativo deve ser executado em um AppContainer — por exemplo, um aplicativo UWP.|
|[/BIND](bind.md)|Define os endereços para os pontos de entrada nos objetos especificados para acelerar o tempo de carregamento.|
|[/DYNAMICBASE](dynamicbase.md)|Especifica se a imagem DLL ou executável pode ser baseada aleatoriamente com base no tempo de carregamento usando a ASLR (Address Space layout Randomization).|
|[/ERRORREPORT](errorreport-editbin-exe.md)| Preterido. O relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) . |
|[/HEAP](heap.md)|Define o tamanho do heap da imagem executável em bytes.|
|[/HIGHENTROPYVA](highentropyva.md)|Especifica se a imagem DLL ou executável dá suporte a alta entropia (64 bits) de ASLR (Address Space layout Randomization).|
|[/INTEGRITYCHECK](integritycheck.md)|Especifica se a assinatura digital deve ser verificada no tempo de carregamento.|
|[/LARGEADDRESSAWARE](largeaddressaware.md)|Especifica se o objeto dá suporte a endereços maiores que dois gigabytes.|
|[/NOLOGO](nologo-editbin.md)|Suprime a faixa de inicialização EDITBIN.|
|[/NXCOMPAT](nxcompat.md)|Especifica se a imagem executável é compatível com a prevenção de execução de dados do Windows.|
|[/REBASE](rebase.md)|Define os endereços base para os objetos especificados.|
|[/RELEASE](release.md)|Define a soma de verificação no cabeçalho.|
|[/SECTION](section-editbin.md)|Substitui os atributos de uma seção.|
|[/STACK](stack.md)|Define o tamanho da pilha da imagem executável em bytes.|
|[/SUBSYSTEM](subsystem.md)|Especifica o ambiente de execução.|
|[/SWAPRUN](swaprun.md)|Especifica que a imagem executável é copiada para o arquivo de permuta e, em seguida, executada a partir daí.|
|[/TSAWARE](tsaware.md)|Especifica que o aplicativo foi projetado para ser executado em um ambiente de vários usuários.|
|[/VERSION](version.md)|Define o número de versão no cabeçalho.|

## <a name="see-also"></a>Confira também

[Ferramentas de compilação MSVC adicionais](c-cpp-build-tools.md)\
[Referência de EDITBIN](editbin-reference.md)
