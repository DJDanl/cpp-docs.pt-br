---
title: Referência de vinculador MSVC
ms.date: 12/10/2018
ms.assetid: bb736587-d13b-4f3c-8982-3cc2c015c59c
ms.openlocfilehash: d46874b5eaff889834df284ba90e6c6f196d8d66
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079506"
---
# <a name="linking"></a>Vinculação

Em um C++ projeto, a etapa de *vinculação* é executada Depois que o compilador compilou o código-fonte em arquivos de objeto (*. obj). O vinculador (link. exe) combina os arquivos de objeto em um único arquivo executável.

As opções do vinculador podem ser definidas dentro ou fora do Visual Studio. No Visual Studio, você acessa as opções do vinculador clicando com o botão direito do mouse em um nó do projeto em **Gerenciador de soluções** e escolhendo **Propriedades** para exibir as páginas de propriedades. Escolha **vinculador** no painel esquerdo para expandir o nó e ver todas as opções.

## <a name="linker-command-line-syntax"></a>Sintaxe de linha de comando do vinculador

Ao executar o LINK fora do Visual Studio, você pode especificar a entrada de uma ou mais maneiras:

- Na linha de comando

- Usando arquivos de comando

- Em variáveis de ambiente

As opções vincular primeiro processos especificadas na variável de ambiente de LINK, seguidas pelas opções na ordem em que são especificadas na linha de comando e nos arquivos de comando. Se uma opção for repetida com argumentos diferentes, o último processado terá precedência.

As opções se aplicam a toda a compilação; nenhuma opção pode ser aplicada a arquivos de entrada específicos.

Para executar o LINK. EXE, use a seguinte sintaxe de comando:

```
LINK arguments
```

O `arguments` incluir opções e nomes de Filee pode ser especificado em qualquer ordem. As opções são processadas primeiro e, em seguida, arquivos. Use um ou mais espaços ou guias para separar argumentos.

> [!NOTE]
>  Você pode iniciar essa ferramenta somente no prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no explorador de arquivos.

## <a name="command-line"></a>Linha de comando

Na linha de comando, uma opção consiste em um especificador de opção, um traço (-) ou uma barra (/), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam um argumento, especificado após dois-pontos (:). Não são permitidos espaços ou guias dentro de uma especificação de opção, exceto dentro de uma cadeia de caracteres entre aspas na opção/COMMENT. Especifique os argumentos numéricos em notação decimal ou de linguagem C. Os nomes de opção e seus argumentos de palavra-chave ou nome de arquivo não diferenciam maiúsculas de minúsculas, mas os identificadores como argumentos diferenciam maiúsculas

Para passar um arquivo para o vinculador, especifique o nome de arquivo na linha de comando após o comando de LINK. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo e pode usar curingas no nome do arquivo. Se você omitir o ponto (.) e a extensão de nome de arquivo, o LINK assumirá. obj para a finalidade de localizar o arquivo. O LINK não usa extensões de nome de arquivo ou a falta delas para fazer suposições sobre o conteúdo dos arquivos; Ele determina o tipo de arquivo examinando-o e o processa de acordo.

o link. exe retorna zero para êxito (sem erros).  Caso contrário, o vinculador retornará o número do erro que interrompeu o link.  Por exemplo, se o vinculador gerar LNK1104, o vinculador retornará 1104.  De acordo, o menor número de erro retornado em um erro pelo vinculador é 1000.  Um valor de retorno de 128 representa um problema de configuração com o sistema operacional ou um arquivo. config; o carregador não carregou o link. exe ou o C2. dll.

## <a name="link-command-files"></a>Arquivos de comando LINK

Você pode passar argumentos de linha de comando para vincular na forma de um arquivo de comando. Para especificar um arquivo de comando para o vinculador, use a seguinte sintaxe:

> **Vincular \@** <em>comandofile</em>

O *comandofile* é o nome de um arquivo de texto. Nenhum espaço ou guia é permitido entre o sinal de arroba ( **\@** ) e o nome do arquivo. Não há extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não podem ser usados. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo. O LINK não usa uma variável de ambiente para pesquisar o arquivo.

No arquivo de comando, os argumentos podem ser separados por espaços ou tabulações (como na linha de comando) e por caracteres de nova linha.

Você pode especificar toda ou parte da linha de comando em um arquivo de comando. Você pode usar mais de um arquivo de comando em um comando de LINK. O LINK aceita a entrada do arquivo de comando como se fosse especificado nesse local na linha de comando. Os arquivos de comando não podem ser aninhados. O LINK ecoa o conteúdo dos arquivos de comando, a menos que a opção [/nologo](nologo-suppress-startup-banner-linker.md) seja especificada.

## <a name="example"></a>Exemplo

O comando a seguir para criar uma DLL passa os nomes de arquivos de objeto e bibliotecas em arquivos de comando separados e usa um terceiro arquivo de comando para especificação da opção/EXPORTS:

```cmd
link /dll @objlist.txt @liblist.txt @exports.txt
```

## <a name="link-environment-variables"></a>Variáveis de ambiente LINK

A ferramenta LINK usa as seguintes variáveis de ambiente:

- LINK e \_LINK\_, se definido. A ferramenta de LINK precede as opções e os argumentos definidos na variável de ambiente de LINK e acrescenta as opções e os argumentos definidos no LINK de \_\_ variável de ambiente aos argumentos de linha de comando antes do processamento.

- LIB, se definido. As ferramentas de LINK usam o caminho LIB ao pesquisar um objeto, uma biblioteca ou outro arquivo especificado na linha de comando ou pela opção [/base](base-base-address.md) . Ele também usa o caminho LIB para localizar um arquivo. pdb chamado em um objeto. A variável LIB pode conter uma ou mais especificações de caminho, separadas por ponto e vírgula. Um caminho deve apontar para o subdiretório \lib da sua instalação Visual C++ .

- CAMINHO, se a ferramenta precisar executar CVTRES e não encontrar o arquivo no mesmo diretório que o próprio LINK. (O LINK requer CVTRES para vincular um arquivo. res.) O caminho deve apontar para o subdiretório \bin da instalação do C++ Visual.

- TMP, para especificar um diretório ao vincular arquivos OMF ou. res.

## <a name="see-also"></a>Confira também

[C/C++ build Reference](c-cpp-building-reference.md)
[Opções do vinculador MSVC](linker-options.md)
[arquivos de definição de módulo (. def)](module-definition-dot-def-files.md)
[suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
