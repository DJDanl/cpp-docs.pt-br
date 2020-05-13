---
title: Referência de vinculador MSVC
ms.date: 12/10/2018
ms.assetid: bb736587-d13b-4f3c-8982-3cc2c015c59c
ms.openlocfilehash: 2503e212e7325fc97f9057861cb85d5cf0571094
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336493"
---
# <a name="linking"></a>Vinculação

Em um projeto C++, a etapa *de vinculação* é executada após o compilador ter compilado o código-fonte em arquivos de objetos (*.obj). O linker (link.exe) combina os arquivos de objeto em um único arquivo executável.

As opções de linker podem ser definidas dentro ou fora do Visual Studio. No Visual Studio, você acessa as opções de linker clicando com o botão direito do mouse em um nó de projeto no **Solution Explorer** e escolhendo **Propriedades** para exibir as páginas de propriedade. Escolha **Linker** no painel esquerdo para expandir o nó e veja todas as opções.

## <a name="linker-command-line-syntax"></a>Sintaxe de linha de comando linker

Quando você executa o LINK fora do Visual Studio, você pode especificar a entrada de uma ou mais maneiras:

- Na linha de comando

- Usando arquivos de comando

- Em variáveis ambientais

Link primeiro processa opções especificadas na variável ambiente LINK, seguidas de opções na ordem em que são especificadas na linha de comando e em arquivos de comando. Se uma opção é repetida com argumentos diferentes, a última processada tem precedência.

As opções se aplicam a toda a compilação; nenhuma opção pode ser aplicada a arquivos de entrada específicos.

Para executar LINK. EXE, use a seguinte sintaxe de comando:

```
LINK arguments
```

As `arguments` opções de inclusão e nomes de arquivos podem ser especificadas em qualquer ordem. As opções são processadas primeiro, depois arquivos. Use um ou mais espaços ou guias para separar argumentos.

> [!NOTE]
> Você só pode iniciar esta ferramenta a partir do prompt de comando do Visual Studio. Não é possível iniciá-lo a partir de um prompt de comando do sistema ou do Explorador de Arquivos.

## <a name="command-line"></a>Linha de comando

Na linha de comando, uma opção consiste em um especificador de opção, um dash (-) ou um corte para frente (/), seguido pelo nome da opção. Nomes de opções não podem ser abreviados. Algumas opções tomam um argumento, especificado após um cólon (:). Não são permitidos espaços ou guias dentro de uma especificação de opção, exceto dentro de uma seqüência de string citada na opção /COMMENT. Especifique argumentos numéricos na notação decimal ou c. Nomes de opções e seus argumentos de palavra-chave ou nome de arquivo não são sensíveis ao caso, mas os identificadores, pois os argumentos são sensíveis a maiúsculas e minúsculas.

Para passar um arquivo para o linker, especifique o nome do arquivo na linha de comando após o comando LINK. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo, e você pode usar curingas no nome do arquivo. Se você omite a extensão do ponto (.) e o nome do arquivo, o LINK assumirá .obj com o propósito de encontrar o arquivo. O LINK não usa extensões de nome de arquivo ou a falta delas para fazer suposições sobre o conteúdo dos arquivos; ele determina o tipo de arquivo examinando-o, e processa-o de acordo.

link.exe retorna zero para sucesso (sem erros).  Caso contrário, o linker retorna o número de erro que parou o link.  Por exemplo, se o linker gerar LNK1104, o linker retorna 1104.  Assim, o menor número de erro retornado em um erro pelo linker é 1000.  Um valor de retorno de 128 representa um problema de configuração com o sistema operacional ou um arquivo .config; o carregador não carregou link.exe ou c2.dll.

## <a name="link-command-files"></a>Arquivos de comando LINK

Você pode passar argumentos de linha de comando para LINK na forma de um arquivo de comando. Para especificar um arquivo de comando no linker, use a seguinte sintaxe:

> **Arquivo \@ ** <em>de comando LINK</em>

O *arquivo de comando* é o nome de um arquivo de texto. Não é permitido espaço ou guia**\@** entre o sinal at ( ) e o nome do arquivo. Não há extensão padrão; você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Curingas não podem ser usados. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo. Link não usa uma variável de ambiente para procurar o arquivo.

No arquivo de comando, os argumentos podem ser separados por espaços ou guias (como na linha de comando) e por caracteres newline.

Você pode especificar tudo ou parte da linha de comando em um arquivo de comando. Você pode usar mais de um arquivo de comando em um comando LINK. O LINK aceita a entrada de arquivo de comando como se fosse especificada nesse local na linha de comando. Os arquivos de comando não podem ser aninhados. Link ecoa o conteúdo dos arquivos de comando, a menos que a opção [/NOLOGO](nologo-suppress-startup-banner-linker.md) seja especificada.

## <a name="example"></a>Exemplo

O seguinte comando para construir um DLL passa os nomes de arquivos de objetos e bibliotecas em arquivos de comando separados e usa um terceiro arquivo de comando para especificação da opção /EXPORTS:

```cmd
link /dll @objlist.txt @liblist.txt @exports.txt
```

## <a name="link-environment-variables"></a>Variáveis de ambiente LINK

A ferramenta LINK usa as seguintes variáveis de ambiente:

- LINK \_e\_LINK, se definidos. A ferramenta LINK prepara as opções e argumentos definidos na variável ambiente \_LINK\_ e anexa as opções e argumentos definidos na variável ambiente LINK aos argumentos da linha de comando antes do processamento.

- LIB, se definido. As ferramentas LINK usam o caminho LIB ao procurar um objeto, biblioteca ou outro arquivo especificado na linha de comando ou pela opção [/BASE.](base-base-address.md) Ele também usa o caminho LIB para encontrar um arquivo .pdb nomeado em um objeto. A variável LIB pode conter uma ou mais especificações de caminho, separadas por ponto e vírgula. Um caminho deve apontar para o subdiretório \lib da instalação Visual C+++.

- PATH, se a ferramenta precisar executar CVTRES e não conseguir encontrar o arquivo no mesmo diretório do link em si. (Link requer CVTRES para vincular um arquivo .res.) O PATH deve apontar para o subdiretório \bin da instalação Visual C++..

- TMP, para especificar um diretório ao vincular arquivos OMF ou .res.

## <a name="see-also"></a>Confira também

[C/C++ Referência de](c-cpp-building-reference.md)
[Module-Definition (.def) Files](module-definition-dot-def-files.md)
[Linker Support for Delay-Loaded DLLs](linker-support-for-delay-loaded-dlls.md) construção Opções
[de linker MSVC](linker-options.md)
