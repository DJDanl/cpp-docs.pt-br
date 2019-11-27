---
title: Arquivos de dica
ms.date: 02/26/2019
f1_keywords:
- cpp.hint
- vc.hint.file
helpviewer_keywords:
- stop file
- cpp.hint
- hint file
- cpp.stop
- Class View, hint file
ms.assetid: 17194f66-cf62-4523-abec-77db0675ab65
ms.openlocfilehash: ca111fcb8b0fc511fda3bbb3a4769ebc9fdd28bc
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189000"
---
# <a name="hint-files"></a>Arquivos de dica

Um *arquivo de dica* contém macros que de outro modo fariam regiões de código serem ignoradas pelo Analisador de Banco de Dados de Navegação C++. Quando você abre um projeto do Visual Studio C++, o analisador revisa o código em cada arquivo de origem no projeto e compila o banco de dados com informações sobre cada identificador. O IDE usa essas informações para dar suporte a recursos de navegação de código como o navegador do **Modo de Exibição de Classe** e a **Barra de Navegação**.

O Analisador de Banco de Dados de Navegação C++ é um analisador difuso que pode revisar grandes quantidades de código em um curto período. Um dos motivos da sua rapidez é que ele ignora o conteúdo de blocos. Por exemplo, ele só registra o local e os parâmetros de uma função e ignora o seu conteúdo. Algumas macros podem causar problemas para a heurística usada para determinar o início e o término de um bloco. Esses problemas fazem regiões do código serem gravadas incorretamente.

Essas regiões ignoradas podem se manifestar de várias maneiras:

- Tipos e funções ausentes em **Modo de Exibição de Classe**, **Ir Para** e **Barra de Navegação**

- Escopos incorretos na **Barra de Navegação**

- Sugestões para **Criar Declaração/Definição** para as funções já definidas

Um arquivo de dica contém dicas personalizáveis pelo usuário, que têm a mesma sintaxe das definições de macro do C/C++. O Visual C++ inclui um arquivo de dica interno suficiente para a maioria dos projetos. No entanto, você pode criar seus próprios arquivos de dica para melhorar o analisador especificamente para seu projeto.

> [!IMPORTANT]
> Se você modificar ou adicionar um arquivo de dica, precisará executar etapas adicionais para que as alterações entrem em vigor:
> - Em versões anteriores ao Visual Studio 2017 versão 15,6: exclua o arquivo. sdf e/ou o arquivo VC. DB na solução para todas as alterações.
> - No Visual Studio 2017 versão 15,6 e posteriores: feche e reabra a solução depois de adicionar novos arquivos de dica.

## <a name="scenario"></a>Cenário

```cpp
#define NOEXCEPT noexcept
void Function() NOEXCEPT
{
}
```

Sem um arquivo de dica, a `Function` não aparecerá no **Modo de Exibição de Classe**, em **Ir Para** nem na **Barra de Navegação**. Depois de adicionar um arquivo de dica com essa definição de macro, o analisador agora compreende e substitui a macro `NOEXCEPT`, o que lhe permite analisar corretamente a função:

```cpp.hint
#define NOEXCEPT
```

## <a name="disruptive-macros"></a>Macros interruptivas

Há duas categorias de macros que interrompem o analisador:

- Macros que encapsulam as palavras-chave que adornam uma função

   ```cpp
   #define NOEXCEPT noexcept
   #define STDMETHODCALLTYPE __stdcall
   ```

   Para esses tipos de macros, apenas o nome da macro é necessário no arquivo de dica:

   ```cpp.hint
   #define NOEXCEPT
   #define STDMETHODCALLTYPE
   ```

- Macros que contenham colchetes desbalanceados

   ```cpp
   #define BEGIN {
   ```

   Para esses tipos de macros, o nome da macro e seu conteúdo são necessários no arquivo de dica:

   ```cpp.hint
   #define BEGIN {
   ```

## <a name="editor-support"></a>Suporte do editor

A partir do Visual Studio 2017 versão 15.8 em diante, há vários recursos para identificar macros que causam interrupções:

- As macros que estão dentro de regiões ignoradas pelo analisador são realçadas.

- Há uma Ação Rápida para criar um arquivo de dica que inclui a macro realçada ou, se houver um arquivo de dica existente, para adicionar a macro ao arquivo de dica.

![Macro realçada.](media/hint-squiggle-and-actions.png "Dica rabisca e ações rápidas")

Depois de executar qualquer uma das Ações Rápidas, o analisador revisa novamente os arquivos afetados pelo arquivo de dica.

Por padrão, a macro do problema é realçada como uma sugestão. O realce pode ser alterado para algo mais perceptível, como um rabisco vermelho ou verde. Use a opção **Macros em Regiões de Navegação Ignoradas** na seção **Rabiscos de Código** em **Ferramentas** > **Opções** > **Editor de Texto** > **C/C++**  > **Exibir**.

![Macros na opção de regiões de navegação ignorada.](media/skipped-regions-squiggle-option.png "Opção de áreas sinuosa ignorada.")

## <a name="display-browsing-database-errors"></a>Exibir Erros de Banco de Dados de Navegação

O comando de menu **Projeto** > **Exibir Erros de Banco de Dados de Navegação** exibe todas as regiões que falharam na análise na **Lista de Erros**. O comando destina-se a simplificar a criação do arquivo de dica inicial. No entanto, o analisador não pode determinar se a causa do erro foi uma macro que causa interrupções, portanto, você deve avaliar cada erro. Execute o comando **Exibir Erros do Banco de Dados de Navegação** e navegue até cada erro para carregar o arquivo afetado no editor. Depois que o arquivo for carregado, se alguma macro estiver dentro da região, ela será realçada. Você pode invocar as Ações Rápidas para adicioná-las a um arquivo de dica. Após uma atualização do arquivo de dica, a lista de erros é atualizada automaticamente. Como alternativa, se você estiver modificando o arquivo de dica manualmente, poderá usar o comando **Examinar Novamente a Solução** para disparar uma atualização.

## <a name="architecture"></a>Arquitetura

Os arquivos de dica relacionam-se aos diretórios físicos, não aos diretórios lógicos mostrados na **Gerenciador de Soluções**. Não é necessário adicionar um arquivo de dica ao projeto para que o arquivo de dica tenha efeito. O sistema de análise usa arquivos de dica somente quando analisa arquivos de origem.

Cada arquivo de dica é chamado **cpp.hint**. Vários diretórios podem conter um arquivo de dica, mas apenas um arquivo de dica pode ocorrer em um diretório específico.

O projeto pode ser afetado por zero ou mais arquivos de dica. Se não há nenhum arquivo de dica, o sistema de análise usa técnicas de recuperação de erro para ignorar o código-fonte indecifrável. Caso contrário, o sistema de análise usa a estratégia a seguir para encontrar e coletar dicas.

### <a name="search-order"></a>Ordem de pesquisa

O sistema de análise pesquisa diretórios em busca de arquivos de dica na ordem a seguir.

- O diretório que contém o pacote de instalação do Visual C++ (**vcpackages**). Esse diretório contém um arquivo de dica interno que descreve os símbolos nos arquivos de sistema usados com frequência, como **windows.h**. Como consequência, o projeto herda automaticamente a maioria das dicas de que precisa.

- O caminho do diretório raiz de um arquivo de origem para o diretório que contém o próprio arquivo de origem. Em um projeto típico do Visual Studio C++, o diretório raiz contém o arquivo de solução ou de projeto.

   A exceção a essa regra ocorrerá se um *arquivo de parada* estiver no caminho para o arquivo de origem. Um arquivo de parada é qualquer arquivo chamado **cpp.stop**. Um arquivo de parada fornece controle adicional sobre a ordem de pesquisa. Em vez de começar no diretório raiz, o sistema de análise começa a pesquisa no diretório que contém o arquivo de parada para o diretório que contém o arquivo de origem. Em um projeto típico, não é necessário ter um arquivo de parada.

### <a name="hint-gathering"></a>Coleta de dica

Um arquivo de dica contém zero ou mais *dicas*. Uma dica é definida ou excluída da mesma forma que uma macro do C/C++. Ou seja, a diretiva do pré-processador `#define` cria ou redefine uma dica, e a diretiva `#undef` exclui uma dica.

O sistema de análise abre cada arquivo de dica na ordem de pesquisa descrita anteriormente. Ele acumula as dicas de cada arquivo em um conjunto de *dicas efetivas* e, em seguida, usa as dicas em vigor para interpretar os identificadores em seu código.

O sistema de análise usa estas regras para acumular dicas:

- Se a nova dica especifica um nome que ainda não está definido, ela adiciona o nome às dicas efetivas.

- Se a nova dica especifica um nome que já está definido, a nova dica redefine a dica existente.

- Se a nova dica é uma diretiva `#undef` que especifica uma dica efetiva existente, a nova dica exclui a dica existente.

A primeira regra significa que as dicas efetivas são herdadas dos arquivos de dica abertos anteriormente. As duas últimas regras significam que as dicas mais adiante na ordem de pesquisa podem substituir as dicas anteriores. Por exemplo, você poderá substituir as dicas anteriores se criar um arquivo de dica no diretório que contém um arquivo de origem.

Para uma representação de como as dicas são coletadas, veja a seção [Exemplo](#example).

### <a name="syntax"></a>Sintaxe

Crie e exclua dicas usando a mesma sintaxe que a das diretivas de pré-processador para criar e excluir macros. Na verdade, o sistema de análise usa o pré-processador C/C++ para avaliar as dicas. Para obter mais informações sobre as diretivas do pré-processador, confira [Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md) e [Diretiva #undef (C/C++)](../../preprocessor/hash-undef-directive-c-cpp.md).

Os únicos elementos de sintaxe incomuns são as cadeias de caracteres de substituição `@<`, `@=` e `@>`. Essas cadeias de caracteres de substituição específicas do arquivo de dica são usadas somente nos macros de *mapa*. Um mapa é um conjunto de macros que relacionam dados, funções ou eventos a outros dados, funções ou manipuladores de eventos. Por exemplo, `MFC` usa mapas para criar [mapas de mensagens](../../mfc/reference/message-maps-mfc.md), e `ATL` usa mapas para criar [mapas de objetos](../../atl/reference/object-map-macros.md). As cadeias de caracteres de substituição específicas a um arquivo de dica marcam os elementos iniciais, intermediários e finais de um mapa. Somente o nome de uma macro de mapa é significativo. Portanto, cada cadeia de caracteres de substituição intencionalmente oculta a implementação da macro.

Dicas usam a seguinte sintaxe:

|Sintaxe|Significado|
|------------|-------------|
|`#define` *hint-name* *replacement-string*<br /><br /> `#define` *hint-name* `(` *parameter*, ...`)`*replacement-string*|Uma diretiva do pré-processador que define uma nova dica ou redefine uma dica existente. Após a diretiva, o pré-processador substitui cada ocorrência de *hint-name* no código-fonte por *replacement-string*.<br /><br /> O segundo formato de sintaxe define uma dica semelhante a uma função. Se uma dica semelhante a uma função ocorre no código-fonte, o pré-processador primeiro substitui cada ocorrência do *parameter* na *replacement-string* pelo argumento correspondente no código-fonte e, em seguida, substitui *hint-name* pela *replacement-string*.|
|`@<`|Uma *replacement-string* específica a um arquivo de dica que indica o início de um conjunto de elementos de mapa.|
|`@=`|Uma *replacement-string* específica a um arquivo de dica que indica um elemento do mapa intermediário. Um mapa pode ter vários elementos de mapa.|
|`@>`|Uma *replacement-string* específica a um arquivo de dica que indica o fim de um conjunto de elementos de mapa.|
|`#undef` *hint-name*|A diretiva do pré-processador que exclui uma dica existente. O nome da dica é fornecido pelo identificador *hint-name*.|
|`//` *comment*|Um comentário de linha única.|
|`/*` *comment* `*/`|Um comentário de várias linhas.|

## <a name="example"></a>Exemplo

Este exemplo mostra como as dicas são acumuladas de arquivos de dica. Os arquivos de parada não são usados neste exemplo.

A ilustração mostra alguns dos diretórios físicos em um projeto do Visual Studio C++. Há arquivos de dica nos diretórios `vcpackages`, `Debug`, `A1` e `A2`.

### <a name="hint-file-directories"></a>Diretórios de arquivos de dica

![Diretórios de arquivos&#45;de dica específicos do projeto e comuns.](media/hintfile.png "Dica de")

### <a name="directories-and-hint-file-contents"></a>Diretórios e conteúdo do arquivo de dica

A lista mostra os diretórios nesse projeto que contêm arquivos de dica e o conteúdo desses arquivos de dica. Apenas algumas das muitas dicas no arquivo de dica do diretório `vcpackages` são listadas:

- vcpackages

    ```cpp.hint
    // vcpackages (partial list)
    #define _In_
    #define _In_opt_
    #define _In_z_
    #define _In_opt_z_
    #define _In_count_(size)
    ```

- Depuração

    ```cpp.hint
    // Debug
    #undef _In_
    #define OBRACE {
    #define CBRACE }
    #define RAISE_EXCEPTION(x) throw (x)
    #define START_NAMESPACE namespace MyProject {
    #define END_NAMESPACE }
    ```

- A1

    ```cpp.hint
    // A1
    #define START_NAMESPACE namespace A1Namespace {
    ```

- A2

    ```cpp.hint
    // A2
    #undef OBRACE
    #undef CBRACE
    ```

### <a name="effective-hints"></a>Dicas efetivas

A tabela lista as dicas efetivas para os arquivos de origem neste projeto:

- Arquivo de origem: A1_A2_B.cpp

- Dicas efetivas:

    ```cpp.hint
    // vcpackages (partial list)
    #define _In_opt_
    #define _In_z_
    #define _In_opt_z_
    #define _In_count_(size)
    // Debug...
    #define RAISE_EXCEPTION(x) throw (x)
    // A1
    #define START_NAMESPACE namespace A1Namespace {
    // ...Debug
    #define END_NAMESPACE }
    ```

Estas notas se aplicam à lista anterior:

- As dicas efetivas pertencem aos diretórios `vcpackages`, `Debug`, `A1` e `A2`.

- A diretiva **#undef** no arquivo de dica `Debug` removeu a dica `#define _In_` do arquivo de dica do diretório `vcpackages`.

- O arquivo de dica no diretório `A1` redefine `START_NAMESPACE`.

- A dica `#undef` no diretório `A2` removeu as dicas para `OBRACE` e `CBRACE` no arquivo de dica do diretório `Debug`.

## <a name="see-also"></a>Consulte também

[Tipos de arquivo criados para projetos do Visual Studio C++](file-types-created-for-visual-cpp-projects.md)<br>
[Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)<br>
[Diretiva #undef (C/C++)](../../preprocessor/hash-undef-directive-c-cpp.md)<br>
[Anotações de SAL](../../c-runtime-library/sal-annotations.md)<br>

