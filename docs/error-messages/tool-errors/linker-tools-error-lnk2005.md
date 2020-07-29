---
title: Erro das Ferramentas de Vinculador LNK2005
ms.date: 11/04/2016
f1_keywords:
- LNK2005
helpviewer_keywords:
- LNK2005
ms.assetid: d9587adc-68be-425c-8a30-15dbc86717a4
ms.openlocfilehash: 278f05b8338ac4238d6862fd7b9bd7744f6c8ee5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225209"
---
# <a name="linker-tools-error-lnk2005"></a>Erro das Ferramentas de Vinculador LNK2005

> *símbolo* já definido no objeto

O *símbolo* de símbolo foi definido mais de uma vez.

Esse erro é seguido pelo erro fatal [LNK1169](../../error-messages/tool-errors/linker-tools-error-lnk1169.md).

### <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Em geral, esse erro significa que você desrompeu a *regra de definição*, que permite apenas uma definição para qualquer modelo, função, tipo ou objeto usado em um determinado arquivo de objeto e apenas uma definição em todo o executável para objetos ou funções visíveis externamente.

Aqui estão algumas causas comuns para esse erro.

- Esse erro pode ocorrer quando um arquivo de cabeçalho define uma variável. Por exemplo, se você incluir esse arquivo de cabeçalho em mais de um arquivo de origem em seu projeto, um erro resultará:

    ```h
    // LNK2005_global.h
    int global_int;  // LNK2005
    ```

   Entre as soluções possíveis estão:

  - Declare a variável **`extern`** no arquivo de cabeçalho: e, `extern int global_int;` em seguida, defina-a e, opcionalmente, inicialize-a em um único arquivo de origem: `int global_int = 17;` . Essa variável é agora um global que você pode usar em qualquer arquivo de origem declarando- **`extern`** a, por exemplo, incluindo o arquivo de cabeçalho. Recomendamos essa solução para variáveis que devem ser globais, mas boa prática de engenharia de software minimiza as variáveis globais.

  - Declare a variável [estática](../../cpp/storage-classes-cpp.md#static): `static int static_int = 17;` . Isso restringe o escopo da definição para o arquivo de objeto atual e permite que vários arquivos de objeto tenham sua própria cópia da variável. Não recomendamos que você defina variáveis estáticas em arquivos de cabeçalho devido ao potencial de confusão com variáveis globais. Prefira mover definições de variáveis estáticas para os arquivos de origem que as usam.

  - Declare a variável [selectany](../../cpp/selectany.md): `__declspec(selectany) int global_int = 17;` . Isso informa o vinculador para escolher uma definição para uso por todas as referências externas e para descartar o restante. Essa solução às vezes é útil ao combinar bibliotecas de importação. Caso contrário, não recomendamos isso como uma maneira de evitar erros de vinculador.

- Esse erro pode ocorrer quando um arquivo de cabeçalho define uma função que não é **`inline`** . Se você incluir esse arquivo de cabeçalho em mais de um arquivo de origem, obterá várias definições da função no executável.

    ```h
    // LNK2005_func.h
    int sample_function(int k) { return 42 * (k % 167); }  // LNK2005
    ```

   Entre as soluções possíveis estão:

  - Adicione a **`inline`** palavra-chave à função:

    ```h
    // LNK2005_func_inline.h
    inline int sample_function(int k) { return 42 * (k % 167); }
    ```

  - Remova o corpo da função do arquivo de cabeçalho e deixe apenas a declaração e, em seguida, implemente a função em apenas um arquivo de origem:

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

   Para corrigir esse problema, mova as definições de função de membro dentro da classe. Funções de membro definidas dentro de uma declaração de classe são implicitamente embutidas.

    ```h
    // LNK2005_member_inline.h
    class Sample {
    public:
        int sample_function(int k) { return 42 * (k % 167); }
    };
    ```

- Esse erro pode ocorrer se você vincular mais de uma versão da biblioteca padrão ou do CRT. Por exemplo, se você tentar vincular as bibliotecas CRT de varejo e de depuração, ou as versões estática e dinâmica de uma biblioteca ou duas versões diferentes de uma biblioteca padrão ao seu executável, esse erro poderá ser relatado muitas vezes. Para corrigir esse problema, remova tudo, exceto uma cópia de cada biblioteca, do comando de link. Não recomendamos que você misture bibliotecas de varejo e de depuração, ou versões diferentes de uma biblioteca, no mesmo executável.

   Para instruir o vinculador a usar bibliotecas diferentes dos padrões, na linha de comando, especifique as bibliotecas a serem usadas e use a opção [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para desabilitar as bibliotecas padrão. No IDE, adicione referências ao seu projeto para especificar as bibliotecas a serem usadas e, em seguida, abra a caixa de diálogo **páginas de propriedades** do seu projeto e, na página **vinculador**, **entrada** de propriedades, defina **ignorar todas as bibliotecas padrão**ou ignorar Propriedades de **bibliotecas padrão específicas** para desabilitar as bibliotecas padrão.

- Esse erro pode ocorrer se você misturar o uso de bibliotecas estáticas e dinâmicas ao usar a opção [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) . Por exemplo, esse erro pode ocorrer se você criar uma DLL para uso em seu executável que vincule o CRT estático. Para corrigir esse problema, use somente bibliotecas estáticas ou apenas bibliotecas dinâmicas para o executável inteiro e para todas as bibliotecas que você criar para usar no executável.

- Esse erro pode ocorrer se o símbolo é uma função empacotada (criada por compilação com [/GY](../../build/reference/gy-enable-function-level-linking.md)) e foi incluída em mais de um arquivo, mas foi alterada entre compilações. Para corrigir esse problema, recompile todos os arquivos que incluem a função empacotada.

- Esse erro pode ocorrer se o símbolo for definido de forma diferente em dois objetos de membro em bibliotecas diferentes, e ambos os objetos de membro forem usados. Uma maneira de corrigir esse problema quando as bibliotecas são estaticamente vinculadas é usar o objeto membro de apenas uma biblioteca e incluir essa biblioteca primeiro na linha de comando do vinculador. Para usar os dois símbolos, você deve criar uma maneira de diferenciá-los. Por exemplo, se você puder criar as bibliotecas da origem, poderá encapsular cada biblioteca em um namespace exclusivo. Como alternativa, você pode criar uma nova biblioteca de wrapper que usa nomes exclusivos para encapsular referências a uma das bibliotecas originais, vincular a nova biblioteca à biblioteca original e, em seguida, vincular o executável à sua nova biblioteca em vez da biblioteca original.

- Esse erro pode ocorrer se uma `extern const` variável for definida duas vezes e tiver um valor diferente em cada definição. Para corrigir esse problema, defina a constante apenas uma vez ou use namespaces ou **`enum class`** definições para distinguir as constantes.

- Esse erro pode ocorrer se você usar UUID. lib em combinação com outros arquivos. lib que definem GUIDs (por exemplo, OLEDB. lib e adsiid. lib). Por exemplo:

    ```Output
    oledb.lib(oledb_i.obj) : error LNK2005: _IID_ITransactionObject
    already defined in uuid.lib(go7.obj)
    ```

   Para corrigir esse problema, adicione [/Force: Multiple](../../build/reference/force-force-file-output.md) às opções de linha de comando do vinculador e verifique se UUID. lib é a primeira biblioteca referenciada.
