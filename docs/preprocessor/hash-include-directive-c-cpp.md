---
title: '#incluir a diretiva (C/C++)'
ms.date: 11/04/2016
f1_keywords:
- '#include'
helpviewer_keywords:
- preprocessor, directives
- '#include directive'
- include directive (#include)
ms.assetid: 17067dc0-8db1-4f2d-b43e-ec12ecf83238
ms.openlocfilehash: 67a44574a5a72a7b7addc0ed3d7b51cd3eb5b984
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57821374"
---
# <a name="include-directive-cc"></a>Diretiva #include (C/C++)

Informa o pré-processador para tratar o conteúdo de um arquivo especificado como se ele aparecesse no programa de origem no ponto onde a política aparece.

## <a name="syntax"></a>Sintaxe

```
#include  "path-spec"
#include  <path-spec>
```

## <a name="remarks"></a>Comentários

Você pode organizar as definições de constante e de macro em arquivos de inclusão e, em seguida, use **#include** diretivas para adicioná-los para qualquer arquivo de origem. Os arquivos de inclusão também são úteis para incorporar declarações de variáveis externas e tipos de dados complexos. Os tipos podem ser definidos e nomeados somente uma vez em um arquivo de inclusão criado para essa finalidade.

O *caminho-spec* é um nome de arquivo que pode ser opcionalmente precedido por uma especificação de diretório. O nome do arquivo deve nomear um arquivo existente. A sintaxe do *caminho-spec* depende do sistema operacional em que o programa é compilado.

Para obter informações sobre como fazer referência a assemblies em um aplicativo C++ compilado usando [/clr](../build/reference/clr-common-language-runtime-compilation.md), consulte [#using](../preprocessor/hash-using-directive-cpp.md).

As duas formas de sintaxe causam a substituição da política pelo conteúdo inteiro do arquivo de inclusão especificado. A diferença entre as duas formas é a ordem em que o pré-processador procura por arquivos de cabeçalho quando o caminho é especificado de forma incompleta. A tabela a seguir mostra a diferença entre as duas formas de sintaxe.

|Forma de sintaxe|Ação|
|---|------------|
|Forma entre aspas|O pré-processador pesquisa por arquivos de inclusão nesta ordem:<br/><br/> 1) no mesmo diretório que o arquivo que contém o **#include** instrução.<br/><br/> 2) nos diretórios de abertos atualmente incluem arquivos, na ordem inversa em que foram abertos. A pesquisa começará no diretório do arquivo de inclusão pai e continuará para cima até os diretórios de qualquer arquivo de inclusão avô.<br/><br/> 3) ao longo do caminho especificado por cada **/I** opção de compilador.<br/><br/> 4) ao longo dos caminhos que são especificados pela variável de ambiente INCLUDE.|
|Forma de colchete angular|O pré-processador pesquisa por arquivos de inclusão nesta ordem:<br/><br/> 1) ao longo do caminho especificado por cada **/I** opção de compilador.<br/><br/> 2) ao compilar na linha de comando, ao longo dos caminhos que são especificados pela variável de ambiente INCLUDE.|

O pré-processador para de pesquisar assim que encontra um arquivo com o nome especificado. Se você delimitar uma especificação de caminho completa e inequívoca para o arquivo de inclusão entre aspas duplas (**""**), o pré-processador pesquisará apenas essa especificação de caminho e ignorará os diretórios padrão.

Se o nome do arquivo que estiver dentro das aspas duplas for uma especificação incompleta do caminho, o pré-processador primeiro pesquisará no diretório do arquivo “pai”. Um arquivo pai é o arquivo que contém o **#include** diretiva. Por exemplo, se você incluir um arquivo chamado *arquivo2* em um arquivo chamado *file1*, *file1* é o arquivo pai.

Incluir arquivos que podem ser "aninhados"; ou seja, uma **#include** diretiva pode aparecer em um arquivo denominado por outra **#include** diretiva. Por exemplo, *arquivo2* poderia incluir *arquivo3*. Nesse caso, *file1* ainda será o pai do *arquivo2*, mas ele seria "avô" de *arquivo3*.

Ao incluir os arquivos que estão aninhados e ao compilar na linha de comando, a pesquisa de diretório começa com os diretórios do arquivo pai e depois continua pelos diretórios dos arquivos avô. Ou seja, a pesquisa inicia relativa ao diretório que contém a fonte que está sendo processada atualmente. Se o arquivo não for encontrado, a pesquisa muda para diretórios especificados pela [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) opção de compilador. Por fim, os diretórios que são especificados pela variável de ambiente INCLUDE são pesquisados.

Do ambiente de desenvolvimento do Visual Studio, a variável de ambiente INCLUDE é ignorada. Para obter informações sobre como definir os diretórios que são pesquisados para arquivos de inclusão — isso também se aplica à variável de ambiente LIB — consulte [página de propriedade dos diretórios VC + +](../build/reference/vcpp-directories-property-page.md).

Este exemplo mostra a inclusão de arquivo usando os colchetes angulares:

```
#include <stdio.h>
```

Este exemplo adiciona o conteúdo do arquivo chamado STDIO.H ao programa de origem. Os colchetes angulares fazem com que o pré-processador Procure diretórios especificados pela variável de ambiente INCLUDE para STDIO. H, e depois procure nos diretórios especificados pela **/I** opção de compilador.

O exemplo a seguir mostra a inclusão de arquivo usando a forma entre aspas:

```
#include "defs.h"
```

Este exemplo adiciona o conteúdo do arquivo especificado por DEFS.H para o programa de origem. As aspas significam que o pré-processador pesquisa primeiro no diretório que contém o arquivo de origem pai.

O aninhamento dos arquivos de inclusão pode continuar até 10 níveis. Quando aninhado **#include** é processado, o pré-processador continuará a inserir o arquivo de inclusão delimitador no arquivo de origem original.

**Seção específica da Microsoft**

Para localizar os arquivos de origem, o pré-processador pesquisa primeiro os diretórios especificados pela **/I** opção de compilador. Se o **/I** opção não está presente ou falhar, o pré-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares. A variável de ambiente INCLUDE e **/I** opção de compilador pode conter vários caminhos, separados por ponto e vírgula (**;**). Se mais de um diretório aparecer como parte do **/I** opção ou dentro de variável de ambiente INCLUDE, o pré-processador procurará por eles na ordem em que aparecem.

Por exemplo, o comando

```
CL /ID:\MSVC\INCLUDE MYPROG.C
```

faz com que o pré-processador procure no diretório D:\MSVC\INCLUDE\ os arquivos de inclusão, como STDIO.H. Os comandos

```
SET INCLUDE=D:\MSVC\INCLUDE
CL MYPROG.C
```

têm o mesmo efeito. Quando ambos os conjuntos de pesquisas falham, um erro fatal de compilador é gerado.

Se o nome de arquivo for totalmente especificado para um arquivo de inclusão que possui um caminho que inclui dois-pontos (por exemplo, F:\MSVC\SPECIAL\INCL\TEST.H), o pré-processador segue o caminho.

Para incluir arquivos que são especificados como `#include "path-spec"`, pesquisa de diretório começa com o diretório do arquivo pai e, em seguida, continua pelos diretórios dos arquivos avô. Ou seja, pesquisa inicia relativa ao diretório que contém o arquivo de origem que contém o **#include** diretiva que está sendo processada. Se não houver nenhum arquivo avô e o arquivo não tiver sido encontrado, a pesquisa continua como se o nome do arquivo estivesse dentro de colchetes.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)<br/>
[/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md)<br/>
