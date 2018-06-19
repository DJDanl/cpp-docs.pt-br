---
title: Ferramentas de vinculador LNK2005 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2005
dev_langs:
- C++
helpviewer_keywords:
- LNK2005
ms.assetid: d9587adc-68be-425c-8a30-15dbc86717a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f853bec220c7d46ed2a0c44ac1e1d45fbca8318f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33301236"
---
# <a name="linker-tools-error-lnk2005"></a>Erro das Ferramentas de Vinculador LNK2005
*símbolo* já definido no objeto  
  
O símbolo *símbolo* foi definido mais de uma vez.   
  
Esse erro é seguido por um erro fatal [LNK1169](../../error-messages/tool-errors/linker-tools-error-lnk1169.md).  
  
### <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções  
  
Geralmente, esse erro significa que tenham interrompido a *regra de definição de um*, que permite apenas uma definição para qualquer modelo usado, a função, o tipo ou o objeto em um arquivo de objeto em questão e apenas uma definição entre o executável inteiro para objetos visíveis externamente ou funções.  
  
Aqui estão algumas causas comuns desse erro.  
  
-   Esse erro pode ocorrer quando um arquivo de cabeçalho define uma variável. Por exemplo, se você incluir esse arquivo de cabeçalho em mais de um arquivo de origem em seu projeto, ocorrerá um erro:  
  
    ```h  
    // LNK2005_global.h  
    int global_int;  // LNK2005
    ```  
  
    As possíveis soluções incluem:  
  
    -   Declarar a variável `extern` no arquivo de cabeçalho: `extern int global_int;`, em seguida, defini-lo e, opcionalmente, inicializá-lo em apenas um arquivo de origem: `int global_int = 17;`. Essa variável é agora um objeto global que você pode usar em qualquer arquivo de origem, declarando- `extern`, por exemplo, incluindo o arquivo de cabeçalho. Recomendamos essa solução para variáveis que devem ser global, mas a prática boa engenharia de software minimiza as variáveis globais.  
    
    -   Declarar a variável [estático](../../cpp/storage-classes-cpp.md#static): `static int static_int = 17;`. Isso restringe o escopo de sua definição para o arquivo de objeto atual e permite que vários arquivos de objeto têm sua própria cópia da variável. Não é recomendável que definir variáveis estáticas em arquivos de cabeçalho por causa do potencial de confusão com variáveis globais. Prefira mover as definições de variável estáticas para os arquivos de origem que usá-los.  
  
    -   Declarar a variável [selectany](../../cpp/selectany.md): `__declspec(selectany) int global_int = 17;`. Isso informa o vinculador para escolher uma definição para uso por todas as referências externas e descartar o resto. Essa solução, às vezes, é útil ao combinar as bibliotecas de importação. Caso contrário, não recomendamos como uma maneira de evitar erros de vinculador.  
  
-   Esse erro pode ocorrer quando um arquivo de cabeçalho define uma função que não seja `inline`. Se você incluir esse arquivo de cabeçalho em mais de um arquivo de origem, você receberá várias definições de função no executável.  
    
    ```h  
    // LNK2005_func.h  
    int sample_function(int k) { return 42 * (k % 167); }  // LNK2005
    ```  
  
    As possíveis soluções incluem:  
  
    -   Adicionar o `inline` palavra-chave para a função: 

        ```h  
        // LNK2005_func_inline.h  
        inline int sample_function(int k) { return 42 * (k % 167); }  
        ```  
  
    -   Remova o corpo da função do arquivo de cabeçalho e deixe somente a declaração e implementar a função em apenas um arquivo de origem:  
  
        ```h  
        // LNK2005_func_decl.h  
        int sample_function(int);  
        ```  
  
        ```cpp  
        // LNK2005_func_impl.cpp  
        int sample_function(int k) { return 42 * (k % 167); }  
        ```  
-   Esse erro também pode ocorrer se você definir funções de membro fora da declaração de classe em um arquivo de cabeçalho:  
  
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
  
-   Esse erro pode ocorrer se você vincular mais de uma versão da biblioteca padrão ou CRT. Por exemplo, se você tentar vincular tanto de varejo e depuração CRT bibliotecas ou as versões estáticas e dinâmicas de uma biblioteca ou duas versões diferentes de uma biblioteca padrão para o executável, esse erro pode ser relatado muitas vezes. Para corrigir esse problema, remova o comando de link na apenas uma cópia de cada biblioteca. Não recomendamos misturar varejo e bibliotecas, ou diferentes versões de uma biblioteca, no mesmo executável de depuração.  
  
    Para informar o vinculador para usar bibliotecas diferente dos padrões, na linha de comando, especifique as bibliotecas para usar e usar o [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) opção de desabilitar as bibliotecas padrão. No IDE, adicione referências ao seu projeto para especificar as bibliotecas para usar e, em seguida, abra o **páginas de propriedade** caixa de diálogo para seu projeto e, no **vinculador**, **entrada** propriedade Defina o **ignorar todas as bibliotecas padrão**, ou **ignorar bibliotecas específicas de padrão** propriedades para desabilitar as bibliotecas padrão.   
  
-   Esse erro pode ocorrer se você combinar o uso de bibliotecas estáticas e dinâmicas ao usar o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção. Por exemplo, esse erro pode ocorrer se você criar uma DLL para uso em seu executável que vincula-se no CRT estático. Para corrigir esse problema, use apenas as bibliotecas estáticas ou apenas as bibliotecas dinâmico para todo o executável em qualquer biblioteca que você criar para usar no executável.  
  
-   Esse erro pode ocorrer se o símbolo for uma função empacotada (criado pela compilação com [/Gy](../../build/reference/gy-enable-function-level-linking.md)) e ele foi incluído em mais de um arquivo, mas foi alterado entre compilações. Para corrigir esse problema, compile novamente todos os arquivos que incluem a função de pacote.  
  
-   Esse erro pode ocorrer se o símbolo é definido de forma diferente em dois objetos de membro em bibliotecas diferentes, e os dois objetos de membro são usados. Uma maneira de corrigir esse problema quando as bibliotecas são vinculadas estaticamente é usar o objeto de membro de apenas uma biblioteca e incluir essa biblioteca primeiro na linha de comando do vinculador. Para usar ambos os símbolos, você deve criar uma maneira para diferenciá-los. Por exemplo, se você pode criar as bibliotecas de origem, você pode encapsular cada biblioteca em um namespace exclusivo. Como alternativa, você pode criar uma nova biblioteca de wrapper que usa nomes exclusivos para encapsular as referências a uma das bibliotecas do originais, a nova biblioteca de vínculo para a biblioteca original e vincular o executável para sua nova biblioteca em vez da biblioteca original.  
  
-   Esse erro pode ocorrer se um `extern const` variável é definida duas vezes e tem um valor diferente em cada definição. Para corrigir esse problema, defina a constante apenas uma vez ou usar namespaces ou `enum class` definições para distinguir as constantes.  
  
-   Esse erro pode ocorrer se você usar uuid.lib em combinação com outros arquivos. lib que definem os GUIDs (por exemplo, oledb.lib e adsiid.lib). Por exemplo:  
  
    ```Output  
    oledb.lib(oledb_i.obj) : error LNK2005: _IID_ITransactionObject  
    already defined in uuid.lib(go7.obj)  
    ```  
  
     Para corrigir esse problema, adicione [/Force: Multiple](../../build/reference/force-force-file-output.md) às opções de linha de comando do vinculador e certifique-se que uuid.lib é a primeira biblioteca referenciada.
  
## <a name="additional-information"></a>Informações adicionais  
  
Se você estiver usando uma versão mais antiga do conjunto de ferramentas, consulte estes artigos da Base de dados de conhecimento para obter mais informações sobre causas específicas para esse erro:  
  
-   [Um erro LNK2005 ocorre quando as bibliotecas CRT e MFC estão vinculadas na ordem errada no Visual C++](https://support.microsoft.com/kb/148652)  
  
-   [CORREÇÃO: Delete sobrecarregados Global operador causas LNK2005](https://support.microsoft.com/kb/140440)  
  
-   [Você recebe erros LNK2005 quando você compila um projeto executável (.exe) do ATL no Visual C++](https://support.microsoft.com/kb/184235).  
  
