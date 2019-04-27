---
title: Referência de vinculador MSVC
ms.date: 12/10/2018
ms.assetid: bb736587-d13b-4f3c-8982-3cc2c015c59c
ms.openlocfilehash: 3a9eebef0a264b0131311b5ca96011a4d56264a1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62176623"
---
# <a name="linking"></a>Vinculação

Em um projeto do C++, o *vinculação* etapa é executada depois que o compilador tiver compilado o código-fonte em arquivos de objeto (*. obj). O vinculador (link.exe) combina os arquivos de objeto em um único arquivo executável. 

Opções de vinculador podem ser definidas dentro ou fora do Visual Studio. No Visual Studio, acesse as opções do vinculador clicando em um nó de projeto no **Gerenciador de soluções** e escolhendo **propriedades** para exibir as páginas de propriedade. Escolher **vinculador** no painel esquerdo, expanda o nó e ver todas as opções. 


## <a name="linker-command-line-syntax"></a>Sintaxe da linha de comando do vinculador

Quando você executa o vínculo fora do Visual Studio, você pode especificar a entrada de uma ou mais formas:

- Na linha de comando

- Usando arquivos de comando

- Em variáveis de ambiente

Opções de processos primeiro LINK especificado na variável de ambiente LINK, seguido pelas opções na ordem em que elas são especificadas na linha de comando e nos arquivos de comando. Se uma opção é repetida com argumentos diferentes, o último processado terá precedência.

As opções se aplicam à compilação inteira; Não há opções podem ser aplicadas a arquivos de entrada específicos.

Para executar o LINK. EXE, use a seguinte sintaxe de comando:

```
LINK arguments
```

O `arguments` incluem opções e nomes de arquivo e podem ser especificados em qualquer ordem. As opções são processadas primeiro e, em seguida, arquivos. Use um ou mais espaços ou tabulações para separar os argumentos.

> [!NOTE]
>  Você pode iniciar essa ferramenta apenas de prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

## <a name="command-line"></a>Linha de comando

Na linha de comando, uma opção consiste em um especificador de opção, um traço (-) ou uma barra (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções têm um argumento, especificado após dois-pontos (:). Sem espaços ou tabulações são permitidas dentro de uma especificação de opção, exceto em uma cadeia de caracteres entre aspas na opção /COMMENT. Especifica argumentos numéricos em decimal ou notação de linguagem C. Nomes de opções e seus argumentos de palavra-chave ou nome de arquivo não diferenciam maiusculas de minúsculas, mas identificadores como argumentos diferenciam maiusculas de minúsculas.

Para passar um arquivo para o vinculador, especifique o nome do arquivo na linha de comando após o comando LINK. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo, e você pode usar curingas no nome do arquivo. Se você omitir a extensão de nome de arquivo e o ponto (.), o LINK pressupõe. obj com a finalidade de localizar o arquivo. LINK não usa extensões de nome de arquivo ou a falta delas fazer suposições sobre o conteúdo de arquivos; ele determina o tipo de arquivo examinando-a e processa de acordo.

link.exe retorna zero para êxito (sem erros).  Caso contrário, o vinculador retorna o número do erro que interrompeu o link.  Por exemplo, se o vinculador gera LNK1104, o vinculador retorna 1104.  Da mesma forma, o menor número de erro retornado em um erro pelo vinculador é 1000.  Um valor de retorno de 128 representa um problema de configuração com o sistema operacional ou um arquivo. config; o carregador não foi carregado link.exe ou c2.dll.

## <a name="link-command-files"></a>Arquivos de comando LINK

Você pode passar argumentos de linha de comando para o LINK na forma de um arquivo de comando. Para especificar um arquivo de comando para o vinculador, use a seguinte sintaxe:

> **LINK \@**  <em>commandfile</em>

O *commandfile* é o nome de um arquivo de texto. Nenhum espaço ou tabulação é permitida entre o sinal de arroba (**\@**) e o nome do arquivo. Não há nenhuma extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não pode ser usada. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo. LINK não usa uma variável de ambiente para pesquisar o arquivo.

No arquivo de comando, argumentos podem ser separados por espaços ou tabulações (como na linha de comando) e por caracteres de nova linha.

Você pode especificar todos ou parte da linha de comando em um arquivo de comando. Você pode usar mais de um arquivo de comando em um comando LINK. LINK aceita a entrada do arquivo de comando, como se ele foi especificado no local na linha de comando. Arquivos de comando não podem ser aninhados. LINK exibe o conteúdo dos arquivos de comando, a menos que o [/NOLOGO](nologo-suppress-startup-banner-linker.md) opção for especificada.

## <a name="example"></a>Exemplo

O comando a seguir para criar uma DLL passa os nomes dos arquivos de objeto e bibliotecas em arquivos separados de comando e usa um terceiro arquivo para a especificação da opção/exportações de comando:

```cmd
link /dll @objlist.txt @liblist.txt @exports.txt
```

## <a name="link-environment-variables"></a>Variáveis de ambiente LINK

A ferramenta LINK usa as seguintes variáveis de ambiente:

- LINK e \_LINK\_, se definido. A ferramenta LINK precede as opções e argumentos definidos na variável de ambiente LINK e acrescenta as opções e argumentos definidos na \_LINK\_ variável de ambiente para os argumentos de linha de comando antes do processamento.

- LIB, se definido. As ferramentas LINK usa o caminho do LIB ao pesquisar por um objeto, biblioteca ou outro arquivo especificado na linha de comando ou pelo [/base](base-base-address.md) opção. Ele também usa o caminho do LIB para localizar um arquivo. PDB chamado em um objeto. A variável LIB pode conter uma ou mais especificações de caminho, separadas por ponto e vírgula. Um caminho deve apontar para o subdiretório \lib de sua instalação do Visual C++.

- CAMINHO, se a ferramenta precisa ser executado CVTRES e não é possível localizar o arquivo no mesmo diretório que o próprio LINK. (O LINK exige CVTRES vincular um arquivo. res). CAMINHO deve apontar para o subdiretório \bin de sua instalação do Visual C++.

- TMP, especifique um diretório ao vincular arquivos OMF ou. res.

## <a name="see-also"></a>Consulte também

[Referência de build do C/C++](c-cpp-building-reference.md)
[opções de vinculador MSVC](linker-options.md)
[arquivos de definição de módulo (. def)](module-definition-dot-def-files.md)
[suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
