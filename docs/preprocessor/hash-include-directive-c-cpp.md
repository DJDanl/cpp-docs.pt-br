---
title: '#Diretiva include (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#include'
helpviewer_keywords:
- preprocessor, directives
- '#include directive'
- include directive (#include)
ms.assetid: 17067dc0-8db1-4f2d-b43e-ec12ecf83238
ms.openlocfilehash: 0792f522427e5658de992969745878894fbd454d
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220252"
---
# <a name="include-directive-cc"></a>Diretiva de #include (CC++/)

Informa o pré-processador para tratar o conteúdo de um arquivo especificado como se ele aparecesse no programa de origem no ponto onde a política aparece.

## <a name="syntax"></a>Sintaxe

> **#include** "*caminho-especificação*" \
> **#include** *caminho-especificação* \<>

## <a name="remarks"></a>Comentários

Você pode organizar as definições de macro e constantes em arquivos de inclusão e, em seguida, usar **#include** diretivas para adicioná-los a qualquer arquivo de origem. Os arquivos de inclusão também são úteis para incorporar declarações de variáveis externas e tipos de dados complexos. Os tipos podem ser definidos e nomeados somente uma vez em um arquivo de inclusão criado para essa finalidade.

O *caminho-spec* é um nome de arquivo que pode, opcionalmente, ser precedido por uma especificação de diretório. O nome do arquivo deve nomear um arquivo existente. A sintaxe de *Path-spec* depende do sistema operacional no qual o programa é compilado.

Para obter informações sobre como referenciar assemblies em C++ um aplicativo que é compilado usando o [/clr](../build/reference/clr-common-language-runtime-compilation.md), consulte [#using](../preprocessor/hash-using-directive-cpp.md).

As duas formas de sintaxe causam a substituição da política pelo conteúdo inteiro do arquivo de inclusão especificado. A diferença entre as duas formas é a ordem em que o pré-processador procura por arquivos de cabeçalho quando o caminho é especificado de forma incompleta. A tabela a seguir mostra a diferença entre as duas formas de sintaxe.

|Forma de sintaxe|Ação|
|---|------------|
|Forma entre aspas|O pré-processador pesquisa por arquivos de inclusão nesta ordem:<br/><br/> 1) no mesmo diretório que o arquivo que contém a instrução **#include** .<br/><br/> 2) nos diretórios dos arquivos de inclusão abertos no momento, na ordem inversa em que foram abertos. A pesquisa começará no diretório do arquivo de inclusão pai e continuará para cima até os diretórios de qualquer arquivo de inclusão avô.<br/><br/> 3) ao longo do caminho especificado por cada opção de compilador **/i** .<br/><br/> 4) ao longo dos caminhos que são especificados pela variável de ambiente INCLUDE.|
|Forma de colchete angular|O pré-processador pesquisa por arquivos de inclusão nesta ordem:<br/><br/> 1) ao longo do caminho especificado por cada opção de compilador **/i** .<br/><br/> 2) quando a compilação ocorre na linha de comando, ao longo dos caminhos especificados pela variável de ambiente INCLUDE.|

O pré-processador para de pesquisar assim que encontra um arquivo com o nome especificado. Se você colocar uma especificação de caminho completa e não ambígua para o arquivo de inclusão entre aspas duplas (`" "`), o pré-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.

Se o nome do arquivo que estiver dentro das aspas duplas for uma especificação incompleta do caminho, o pré-processador primeiro pesquisará no diretório do arquivo “pai”. Um arquivo pai é o arquivo que contém a diretiva de **#include** . Por exemplo, se você incluir um arquivo chamado *arquivo2* em um arquivo chamado *arquivo1*, *arquivo1* será o arquivo pai.

Os arquivos de inclusão podem ser "aninhados": Uma diretiva de **#include** pode aparecer em um arquivo nomeado por outra diretiva de **#include** . Por exemplo, *file2* pode incluir *arquivo3*. Nesse caso, o *arquivo1* ainda seria o pai de *arquivo2*, mas seria o "avô" do *arquivo3*.

Quando os arquivos de inclusão são aninhados e quando a compilação ocorre na linha de comando, a pesquisa de diretório começa nos diretórios do arquivo pai. Em seguida, ele prossegue nos diretórios de qualquer arquivo avô. Ou seja, a pesquisa inicia relativa ao diretório que contém a fonte que está sendo processada atualmente. Se o arquivo não for encontrado, a pesquisa será movida para os diretórios especificados pela opção de compilador [/i (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) . Por fim, os diretórios que são especificados pela variável de ambiente INCLUDE são pesquisados.

No ambiente de desenvolvimento do Visual Studio, a variável de ambiente INCLUDE é ignorada. Para obter informações sobre como definir os diretórios que são pesquisados em arquivos de inclusão e arquivos de biblioteca, consulte [página de propriedades de diretórios do vc + +](../build/reference/vcpp-directories-property-page.md).

Este exemplo mostra a inclusão de arquivo usando os colchetes angulares:

```C
#include <stdio.h>
```

Este exemplo adiciona o conteúdo do arquivo chamado STDIO.H ao programa de origem. Os colchetes angulares fazem com que o pré-processador pesquise os diretórios especificados pela variável de ambiente INCLUDE para STDIO. H, depois de Pesquisar os diretórios que são especificados pela opção de compilador **/i** .

O exemplo a seguir mostra a inclusão de arquivo usando a forma entre aspas:

```C
#include "defs.h"
```

Este exemplo adiciona o conteúdo do arquivo especificado por DEFS.H para o programa de origem. As aspas significam que o pré-processador pesquisa primeiro no diretório que contém o arquivo de origem pai.

O aninhamento dos arquivos de inclusão pode continuar até 10 níveis. Quando o **#include** aninhado é processado, o pré-processador continua a inserir o arquivo de inclusão de circunscrição no arquivo de origem original.

**Seção específica da Microsoft**

Para localizar os arquivos de origem do includable, o pré-processador primeiro pesquisa os diretórios que são especificados pela opção de compilador **/i** . Se a opção **/i** não estiver presente ou se falhar, o pré-processador usará a variável de ambiente include para localizar os arquivos de inclusão entre colchetes angulares. A opção INCLUDE Environment Variable e **/i** Compiler pode conter vários caminhos, separados por ponto-e-vírgula ( **;** ). Se mais de um diretório aparecer como parte da opção **/i** ou dentro da variável de ambiente include, o pré-processador os pesquisará na ordem em que aparecem.

Por exemplo, o comando

```cmd
CL /ID:\MSVC\INCLUDE MYPROG.C
```

faz com que o pré-processador procure no diretório D:\MSVC\INCLUDE\ os arquivos de inclusão, como STDIO.H. Os comandos

```cmd
SET INCLUDE=D:\MSVC\INCLUDE
CL MYPROG.C
```

têm o mesmo efeito. Quando ambos os conjuntos de pesquisas falham, um erro fatal de compilador é gerado.

Se o nome de arquivo for totalmente especificado para um arquivo de inclusão que possui um caminho que inclui dois-pontos (por exemplo, F:\MSVC\SPECIAL\INCL\TEST.H), o pré-processador segue o caminho.

Para arquivos de inclusão que são especificados `#include "path-spec"`como, a pesquisa de diretório começa com o diretório do arquivo pai e, em seguida, prossegue nos diretórios de qualquer arquivo avô. Ou seja, a pesquisa começa em relação ao diretório que contém o arquivo de origem que contém a diretiva de **#include** que está sendo processada. Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continua como se o nome do arquivo estivesse dentro de colchetes.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)\
[/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md)
