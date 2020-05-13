---
title: Erro das Ferramentas de Vinculador LNK2005
ms.date: 11/04/2016
f1_keywords:
- LNK2005
helpviewer_keywords:
- LNK2005
ms.assetid: d9587adc-68be-425c-8a30-15dbc86717a4
ms.openlocfilehash: 6090478c3761c477250b6706a350e261b51f2a05
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353233"
---
# <a name="linker-tools-error-lnk2005"></a>Erro das Ferramentas de Vinculador LNK2005

> *símbolo* já definido em objeto

O *símbolo* foi definido mais de uma vez.

Este erro é seguido por erro fatal [LNK1169](../../error-messages/tool-errors/linker-tools-error-lnk1169.md).

### <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Geralmente, esse erro significa que você quebrou a *regra de uma definição,* que permite apenas uma definição para qualquer modelo, função, tipo ou objeto usado em um determinado arquivo de objeto, e apenas uma definição em todo o executável para objetos ou funções externamente visíveis.

Aqui estão algumas causas comuns para este erro.

- Esse erro pode ocorrer quando um arquivo de cabeçalho define uma variável. Por exemplo, se você incluir este arquivo de cabeçalho em mais de um arquivo de origem em seu projeto, um erro resulta:

    ```h
    // LNK2005_global.h
    int global_int;  // LNK2005
    ```

   Entre as soluções possíveis estão:

  - Declare a `extern` variável no `extern int global_int;`arquivo de cabeçalho: , em seguida, defina-a e, opcionalmente, inicialize-a em um único arquivo de origem: `int global_int = 17;`. Esta variável é agora um global que você pode `extern`usar em qualquer arquivo de origem declarando-o , por exemplo, incluindo o arquivo de cabeçalho. Recomendamos esta solução para variáveis que devem ser globais, mas uma boa prática de engenharia de software minimiza variáveis globais.

  - Declare a variável `static int static_int = 17;` [estática](../../cpp/storage-classes-cpp.md#static): . Isso restringe o escopo da definição ao arquivo objeto atual e permite que vários arquivos de objeto tenham sua própria cópia da variável. Não recomendamos que você defina variáveis estáticas em arquivos de cabeçalho devido ao potencial de confusão com variáveis globais. Prefira mover definições de variáveis estáticas para os arquivos de origem que as usam.

  - Declare a variável `__declspec(selectany) int global_int = 17;` [selectany](../../cpp/selectany.md): . Isso diz ao linker para escolher uma definição para uso por todas as referências externas e descartar o resto. Esta solução às vezes é útil ao combinar bibliotecas de importação. Caso contrário, não recomendamos isso como uma maneira de evitar erros de linker.

- Esse erro pode ocorrer quando um arquivo de `inline`cabeçalho define uma função que não é . Se você incluir este arquivo de cabeçalho em mais de um arquivo de origem, você terá várias definições da função no executável.

    ```h
    // LNK2005_func.h
    int sample_function(int k) { return 42 * (k % 167); }  // LNK2005
    ```

   Entre as soluções possíveis estão:

  - Adicione `inline` a palavra-chave à função:

    ```h
    // LNK2005_func_inline.h
    inline int sample_function(int k) { return 42 * (k % 167); }
    ```

  - Remova o corpo de função do arquivo de cabeçalho e deixe apenas a declaração e, em seguida, implemente a função em um único arquivo de origem:

    ```h
    // LNK2005_func_decl.h
    int sample_function(int);
    ```

    ```cpp
    // LNK2005_func_impl.cpp
    int sample_function(int k) { return 42 * (k % 167); }
    ```

- Esse erro também pode ocorrer se você definir funções de membro fora da declaração de classe em um arquivo de cabeçalho:

    ```h
    // LNK2005_member_outside.h
    class Sample {
    public:
        int sample_function(int);
    };
    int Sample::sample_function(int k) { return 42 * (k % 167); }  // LNK2005
    ```

   Para corrigir esse problema, mova as definições da função do membro dentro da classe. As funções dos membros definidas dentro de uma declaração de classe são implicitamente inlineadas.

    ```h
    // LNK2005_member_inline.h
    class Sample {
    public:
        int sample_function(int k) { return 42 * (k % 167); }
    };
    ```

- Esse erro pode ocorrer se você vincular mais de uma versão da biblioteca padrão ou CRT. Por exemplo, se você tentar vincular as bibliotecas CRT de varejo e depuração, ou as versões estáticas e dinâmicas de uma biblioteca, ou duas versões diferentes de uma biblioteca padrão para o seu executável, esse erro pode ser relatado muitas vezes. Para corrigir esse problema, remova todas as cópias de cada biblioteca do comando link. Não recomendamos que você misture bibliotecas de varejo e depuração, ou versões diferentes de uma biblioteca, no mesmo executável.

   Para dizer ao linker para usar bibliotecas que não os padrões, na linha de comando, especifique as bibliotecas a serem usados e use a opção [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para desativar as bibliotecas padrão. No IDE, adicione referências ao seu projeto para especificar as bibliotecas a serem usados e, em seguida, abra a caixa de diálogo **Páginas de propriedade** para o seu projeto e, na página **Linker**, **Input** property, defina ignorar todas **as bibliotecas padrão**ou ignorar as propriedades **Bibliotecas Padrão específicas** para desativar as bibliotecas padrão.

- Esse erro pode ocorrer se você misturar o uso de bibliotecas estáticas e dinâmicas quando você usa a opção [/clr.](../../build/reference/clr-common-language-runtime-compilation.md) Por exemplo, esse erro pode ocorrer se você construir uma DLL para uso em seu executável que se vincula no CRT estático. Para corrigir esse problema, use apenas bibliotecas estáticas ou apenas bibliotecas dinâmicas para todo o executável e para quaisquer bibliotecas que você construir para usar no executável.

- Esse erro pode ocorrer se o símbolo for uma função embalada (criada compilando com [/Gy](../../build/reference/gy-enable-function-level-linking.md)) e foi incluído em mais de um arquivo, mas foi alterado entre compilações. Para corrigir esse problema, recompile todos os arquivos que incluem a função embalada.

- Esse erro pode ocorrer se o símbolo for definido de forma diferente em dois objetos membros em bibliotecas diferentes, e ambos os objetos membros forem usados. Uma maneira de corrigir esse problema quando as bibliotecas estão estáticamente ligadas é usar o objeto membro de apenas uma biblioteca e incluir essa biblioteca primeiro na linha de comando linker. Para usar ambos os símbolos, você deve criar uma maneira de distingui-los. Por exemplo, se você pode construir as bibliotecas a partir da fonte, você pode envolver cada biblioteca em um espaço de nome exclusivo. Alternativamente, você pode criar uma nova biblioteca de invólucros que usa nomes exclusivos para embrulhar referências a uma das bibliotecas originais, vincular a nova biblioteca à biblioteca original e, em seguida, vincular o executável à sua nova biblioteca em vez da biblioteca original.

- Esse erro pode `extern const` ocorrer se uma variável for definida duas vezes e tiver um valor diferente em cada definição. Para corrigir esse problema, defina a constante `enum class` apenas uma vez ou use namespaces ou definições para distinguir as constantes.

- Esse erro pode ocorrer se você usar uuid.lib em combinação com outros arquivos .lib que definem GUIDs (por exemplo, oledb.lib e adsiid.lib). Por exemplo:

    ```Output
    oledb.lib(oledb_i.obj) : error LNK2005: _IID_ITransactionObject
    already defined in uuid.lib(go7.obj)
    ```

   Para corrigir esse problema, adicione [/FORCE:MULTIPLE](../../build/reference/force-force-file-output.md) às opções de linha de comando do linker e certifique-se de que uuid.lib seja a primeira biblioteca referenciada.
