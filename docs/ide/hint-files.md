---
title: Arquivos de dica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- cpp.hint
- vc.hint.file
dev_langs:
- C++
helpviewer_keywords:
- stop file
- cpp.hint
- hint file
- cpp.stop
- Class View, hint file
ms.assetid: 17194f66-cf62-4523-abec-77db0675ab65
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 687e5cba94693a752f934d7816e6a7c36e318354
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33336691"
---
# <a name="hint-files"></a>Arquivos de dica
Um *arquivo de dica* ajuda o IDE (ambiente de desenvolvimento integrado) do Visual Studio a interpretar identificadores do Visual C++, como os nomes de funções e macros. Quando você abre um projeto do Visual C++, o *sistema do análise* do IDE analisa o código em cada arquivo de origem no projeto e reúne informações sobre cada identificador. Em seguida, o IDE usa essas informações para dar suporte a funcionalidades como o navegador do **Modo de Exibição de Classe** e a **Barra de Navegação**.  
  
 O sistema de análise, que foi introduzido no Visual C++ 2010, reconhece a sintaxe C/C++, mas pode interpretar incorretamente uma instrução que contém uma macro. A instrução poderá ser interpretada incorretamente se a macro fizer com que o código-fonte fique sintaticamente incorreto conforme ele é escrito. A instrução pode se tornar sintaticamente correta quando o código-fonte é compilado e o pré-processador substitui o [identificador de macro](../preprocessor/hash-define-directive-c-cpp.md) por sua definição. O sistema de análise funciona sem a necessidade de compilar o projeto, porque usa os arquivos de dica para interpretar as macros. Portanto, um recurso de navegação, como o **Modo de Exibição de Classe**, está imediatamente disponível.  
  
 Um arquivo de dica contém *dicas* personalizáveis pelo usuário, que têm a mesma sintaxe das definições de macro do C/C++. O Visual C++ inclui um arquivo de dica interno que é suficiente para a maioria dos projetos, mas você pode criar seus próprios arquivos de dica para melhorar a maneira como o Visual Studio manipula os identificadores.  
  
> [!IMPORTANT]
>  Se você modificar ou adicionar um arquivo de dica, exclua o arquivo .sdf e/ou o arquivo VC.db da solução para que as alterações entrem em vigor.  
  
## <a name="scenario"></a>Cenário  
 Suponha que o código a seguir esteja em um arquivo de origem examinado com o navegador do **Modo de Exibição de Classe**. A macro `STDMETHOD` declara um método chamado `myMethod`, que usa um parâmetro e retorna um ponteiro para um **HRESULT**.  
  
```  
// Source code file.  
STDMETHOD(myMethod)(int parameter1);  
```  
  
 As definições de macro a seguir estão em um arquivo de cabeçalho separado.  
  
```  
// Header file.  
#define STDMETHOD(method) HRESULT (STDMETHODCALLTYPE * method)  
#define STDMETHODCALLTYPE __stdcall  
#define HRESULT void*  
```  
  
 O sistema de análise não pode interpretar o código-fonte porque uma função chamada STDMETHOD parece estar declarada e essa declaração está sintaticamente incorreta porque tem duas listas de parâmetros. O sistema de análise não abre o arquivo de cabeçalho para descobrir as definições para as macros `STDMETHOD`, `STDMETHODCALLTYPE` e `HRESULT`. Como o sistema de análise não pode interpretar a macro `STDMETHOD`, ele ignora toda a instrução e, em seguida, continua a análise.  
  
 O sistema de análise não usa arquivos de cabeçalho porque o projeto pode depender de um ou mais arquivos de cabeçalho importantes. Se um arquivo de cabeçalho for alterado, o sistema de análise poderá precisar reexaminar todos os arquivos de cabeçalho no projeto, o que diminui o desempenho do IDE. Em vez disso, o sistema de análise usa dicas que especificam como manipular as macros `STDMETHOD`, `STDMETHODCALLTYPE` e `HRESULT`.  
  
 Como saber se você precisa de uma dica? E se precisar de uma, que tipo de dica deverá criar? Um sinal de que uma dica é necessária é se a exibição de um identificador no **Modo de Exibição de Classe** está inconsistente com a exibição no **Editor**. Por exemplo, **Modo de Exibição de Classe** pode não exibir um membro de classe que você sabe que existe, ou o nome do membro está incorreto. Para obter mais informações sobre os tipos de dicas que resolvem problemas comuns, confira a seção Quais macros exigem uma dica? mais adiante neste tópico.  
  
## <a name="architecture"></a>Arquitetura  
 Os arquivos de dica pertencem aos diretórios físicos, e não aos diretórios lógicos descritos no **Gerenciador de Soluções**. Não é necessário adicionar um arquivo de dica ao projeto para que o arquivo de dica tenha efeito. O sistema de análise usa arquivos de dica somente quando analisa arquivos de origem.  
  
 Cada arquivo de dica é chamado **cpp.hint**. Portanto, vários diretórios podem conter um arquivo de dica, mas apenas um arquivo de dica pode ocorrer em um diretório específico.  
  
 O projeto pode ser afetado por zero ou mais arquivos de dica. Se não há nenhum arquivo de dica, o sistema de análise usa técnicas de recuperação de erro para ignorar o código-fonte indecifrável. Caso contrário, o sistema de análise usa a estratégia a seguir para encontrar e coletar dicas.  
  
### <a name="search-order"></a>Ordem de pesquisa  
 O sistema de análise pesquisa diretórios em busca de arquivos de dica na ordem a seguir.  
  
-   O diretório que contém o pacote de instalação do Visual C++ (**vcpackages**). Esse diretório contém um arquivo de dica interno que descreve os símbolos nos arquivos de sistema usados com frequência, como **windows.h**. Como consequência, o projeto herda automaticamente a maioria das dicas de que precisa.  
  
-   O caminho do diretório raiz de um arquivo de origem para o diretório que contém o próprio arquivo de origem. Em um projeto típico do Visual C++, o diretório raiz contém o arquivo de solução ou de projeto.  
  
     A exceção a essa regra ocorrerá se um *arquivo de parada* estiver no caminho para o arquivo de origem. Um arquivo de parada fornece controle adicional sobre a ordem de pesquisa e é qualquer arquivo chamado **cpp.stop**. Em vez de começar no diretório raiz, o sistema de análise começa a pesquisa no diretório que contém o arquivo de parada para o diretório que contém o arquivo de origem. Em um projeto típico, não é necessário ter um arquivo de parada.  
  
### <a name="hint-gathering"></a>Coleta de dica  
 Um arquivo de dica contém zero ou mais *dicas*. Uma dica é definida ou excluída da mesma forma que uma macro do C/C++. Ou seja, a diretiva do pré-processador `#define` cria ou redefine uma dica, e a diretiva `#undef` exclui uma dica.  
  
 O sistema de análise abre cada arquivo de dica na ordem de pesquisa descrita anteriormente, acumula as dicas de cada arquivo em um conjunto de *dicas efetivas* e, em seguida, usa as dicas efetivas para interpretar os identificadores no código.  
  
 O sistema de análise usa as regras a seguir para acumular dicas.  
  
-   Se a nova dica especifica um nome que ainda não está definido, a nova dica adiciona o nome às dicas efetivas.  
  
-   Se a nova dica especifica um nome que já está definido, a nova dica redefine a dica existente.  
  
-   Se a nova dica é uma diretiva `#undef` que especifica uma dica efetiva existente, a nova dica exclui a dica existente.  
  
 A primeira regra significa que as dicas efetivas são herdadas dos arquivos de dica abertos anteriormente. As últimas duas regras significam que as dicas que ocorrem posteriormente na ordem de pesquisa podem substituir as dicas que ocorreram anteriormente. Por exemplo, você poderá substituir as dicas anteriores se criar um arquivo de dica no diretório que contém um arquivo de origem.  
  
 Para obter uma descrição de como as dicas são coletadas, confira a seção `Example` mais adiante neste tópico.  
  
### <a name="syntax"></a>Sintaxe  
 As dicas são criadas e excluídas com a mesma sintaxe das diretivas do pré-processador que criam e excluem macros. Na verdade, o sistema de análise usa o pré-processador C/C++ para avaliar as dicas. Para obter mais informações sobre as diretivas do pré-processador, confira [Diretiva #define (C/C++)](../preprocessor/hash-define-directive-c-cpp.md) e [Diretiva #undef (C/C++)](../preprocessor/hash-undef-directive-c-cpp.md).  
  
 Os únicos elementos de sintaxe incomuns são as cadeias de caracteres de substituição `@<`, `@=` e `@>`. Elas são cadeias de caracteres de substituição específicas a um arquivo de dica que são usadas somente com macros de *mapa*. Um mapa é um conjunto de macros que relacionam dados, funções ou eventos a outros dados, funções ou manipuladores de eventos. Por exemplo, `MFC` usa mapas para criar [mapas de mensagens](../mfc/reference/message-maps-mfc.md), e `ATL` usa mapas para criar [mapas de objetos](../atl/reference/object-map-macros.md). As cadeias de caracteres de substituição específicas a um arquivo de dica indicam os elementos iniciais, intermediários e finais de um mapa. Somente o nome de uma macro de mapa é significativo. Portanto, cada cadeia de caracteres de substituição intencionalmente oculta a implementação da macro.  
  
 As dicas usam a sintaxe a seguir.  
  
|Sintaxe|Significado|  
|------------|-------------|  
|`#define` *hint-name* *replacement-string*<br /><br /> `#define` *hint-name* `(` *parameter*, ...`)`*replacement-string*|Uma diretiva do pré-processador que define uma nova dica ou redefine uma dica existente. Após a diretiva, o pré-processador substitui cada ocorrência de *hint-name* no código-fonte por *replacement-string*.<br /><br /> O segundo formato de sintaxe define uma dica semelhante a uma função. Se uma dica semelhante a uma função ocorre no código-fonte, o pré-processador primeiro substitui cada ocorrência do *parameter* na *replacement-string* pelo argumento correspondente no código-fonte e, em seguida, substitui *hint-name* pela *replacement-string*.|  
|`@<`|Uma *replacement-string* específica a um arquivo de dica que indica o início de um conjunto de elementos de mapa.|  
|`@=`|Uma *replacement-string* específica a um arquivo de dica que indica um elemento do mapa intermediário. Um mapa pode ter vários elementos de mapa.|  
|`@>`|Uma *replacement-string* específica a um arquivo de dica que indica o fim de um conjunto de elementos de mapa.|  
|`#undef` *hint-name*|A diretiva do pré-processador que exclui uma dica existente. O nome da dica é fornecido pelo identificador *hint-name*.|  
|`//` *comment*|Um comentário de linha única.|  
|`/*` *comment* `*/`|Um comentário de várias linhas.|  
  
## <a name="what-macros-require-a-hint"></a>Quais macros exigem uma dica?  
 Alguns tipos de macros podem interferir no sistema de análise. Esta seção descreve os tipos de macros que podem causar um problema e o tipo de dica que você pode criar para resolver o problema.  
  
### <a name="disruptive-macros"></a>Macros interruptivas  
 Algumas macros fazem com que o sistema de análise interprete o código-fonte incorretamente, mas podem ser ignoradas sem comprometer a experiência de navegação. Por exemplo, as macros de SAL ([Source Code Annotation Language](../c-runtime-library/sal-annotations.md)) são resolvidas para atributos do C++ que ajudam você a encontrar bugs de programação. Caso deseje ignorar as anotações de SAL ao navegar pelo código, crie um arquivo de dica que oculte a anotação.  
  
 No código-fonte a seguir, o tipo de parâmetro para a função `FormatWindowClassName()` é `PXSTR`, e o nome do parâmetro é `szBuffer`. No entanto, o sistema de análise confunde as anotações de SAL `_Pre_notnull_` e `_Post_z_` com o tipo ou o nome do parâmetro.  
  
 **Código-fonte:**  
  
```  
static void FormatWindowClassName(_Pre_notnull__Post_z_ PXSTR szBuffer)  
```  
  
 **Estratégia:** definição nula  
  
 A estratégia nessa situação é tratar as anotações de SAL como se elas não existissem. Para fazer isso, especifique uma dica cuja cadeia de caracteres de substituição seja nula. Consequentemente, o sistema de análise ignorará as anotações e o navegador do **Modo de Exibição de Classe** não as exibirá. (O Visual C++ inclui um arquivo de dica interno que oculta a anotação de SAL.)  
  
 **Arquivo de dica:**  
  
```  
#define _Pre_notnull_  
```  
  
### <a name="concealed-cc-language-elements"></a>Elementos ocultos da linguagem C/C++  
 Um motivo comum pelo qual o sistema de análise interpreta incorretamente o código-fonte é se uma macro oculta um token [punctuator](../cpp/punctuators-cpp.md) ou [keyword](../cpp/keywords-cpp.md) do C/C++. Ou seja, uma macro pode conter metade de um par de sinais de pontuação, como `<>`, `[]`, `{}` e `()`.  
  
 No código-fonte a seguir, a macro `START_NAMESPACE` oculta uma chave esquerda sem par (`{`).  
  
 **Código-fonte:**  
  
```  
#define START_NAMESPACE namespace MyProject {  
```  
  
 **Estratégia:** cópia direta  
  
 Se a semântica de uma macro for crítica para a experiência de navegação, crie uma dica que seja idêntica à macro. O sistema de análise resolverá a macro para a definição no arquivo de dica.  
  
 Observe que, se a macro no arquivo de origem contiver outras macros, essas macros serão interpretadas somente se já estiverem no conjunto de dicas efetivas.  
  
 **Arquivo de dica:**  
  
```  
#define START_NAMESPACE namespace MyProject {  
```  
  
### <a name="maps"></a>Mapas  
 Um mapa consiste em macros que designam um elemento inicial, um elemento final e zero ou mais elementos intermediários. O sistema de análise interpreta os mapas incorretamente porque cada macro de mapa oculta elementos da linguagem C/C++, e a sintaxe de uma instrução completa do C/C++ é distribuída entre várias macros separadas.  
  
 O código-fonte a seguir define as macros `BEGIN_CATEGORY_MAP`, `IMPLEMENTED_CATEGORY` e `END_CATEGORY_MAP`.  
  
 **Código-fonte:**  
  
```  
#define BEGIN_CATEGORY_MAP(x)\  
static const struct ATL::_ATL_CATMAP_ENTRY* GetCategoryMap() throw() {\  
static const struct ATL::_ATL_CATMAP_ENTRY pMap[] = {  
#define IMPLEMENTED_CATEGORY( catid ) { _ATL_CATMAP_ENTRY_IMPLEMENTED, &catid },  
#define END_CATEGORY_MAP()\  
   { _ATL_CATMAP_ENTRY_END, NULL } };\  
   return( pMap ); }  
```  
  
 **Estratégia:** identificar os elementos do mapa  
  
 Especifique dicas para os elementos iniciais, intermediários (se houver) e finais de um mapa. Use as cadeias de caracteres de substituição de mapa especial `@<`, `@=` e `@>`. Para obter mais informações, confira a seção `Syntax` neste tópico.  
  
 **Arquivo de dica:**  
  
```  
// Start of the map.  
#define BEGIN_CATEGORY_MAP(x) @<  
// Intermediate map element.  
#define IMPLEMENTED_CATEGORY( catid ) @=  
// Intermediate map element.  
#define REQUIRED_CATEGORY( catid ) @=  
// End of the map.  
#define END_CATEGORY_MAP() @>  
```  
  
### <a name="composite-macros"></a>Macros compostas  
 As macros compostas contêm um ou mais dos tipos de macro que confundem o sistema de análise.  
  
 O código-fonte a seguir contém a macro `START_NAMESPACE`, que especifica o início de um escopo de namespace, e a macro `BEGIN_CATEGORY_MAP`, que especifica o início de um mapa.  
  
 **Código-fonte:**  
  
```  
#define NSandMAP START_NAMESPACE BEGIN_CATEGORY_MAP  
```  
  
 **Estratégia:** cópia direta  
  
 Crie dicas para as macros `START_NAMESPACE` e `BEGIN_CATEGORY_MAP` e, em seguida, crie uma dica para a macro `NSandMAP` que seja a mesma mostrada anteriormente para o código-fonte. Como alternativa, se uma macro composta consiste somente em macros interruptivas e em espaço em branco, você pode definir uma dica cuja cadeia de caracteres de substituição é uma definição nula.  
  
 Nesse exemplo, suponha que `START_NAMESPACE` já tenha uma dica, conforme descrito neste tópico no subtítulo `Concealed C/C++ Language Elements`. Suponha que `BEGIN_CATEGORY_MAP` tenha uma dica, conforme descrito anteriormente em `Maps`.  
  
 **Arquivo de dica:**  
  
```  
#define NSandMAP START_NAMESPACE BEGIN_CATEGORY_MAP  
```  
  
### <a name="inconvenient-macros"></a>Macros inconvenientes  
 Algumas macros podem ser interpretadas pelo sistema de análise, mas o código-fonte é difícil de ser lido, pois a macro é longa ou complexa. Para fins de legibilidade, forneça uma dica que simplifique a exibição da macro.  
  
 **Código-fonte:**  
  
```  
#define STDMETHOD(methodName) HRESULT (STDMETHODCALLTYPE * methodName)  
```  
  
 **Estratégia:** simplificação  
  
 Crie uma dica que exibe uma definição de macro mais simples.  
  
 **Arquivo de dica:**  
  
```  
#define STDMETHOD(methodName) void* methodName  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir ilustra como as dicas são acumuladas com base nos arquivos de dica. Os arquivos de parada não são usados neste exemplo.  
  
 A ilustração a seguir mostra alguns dos diretórios físicos em um projeto do Visual C++. Os arquivos de dica estão nos diretórios `vcpackages`, `Debug`, `A1` e `A2`.  
  
### <a name="hint-file-directories"></a>Diretórios de arquivos de dica  
 ![Diretórios de arquivos de dicas comuns e específicos ao projeto](../ide/media/hintfile.png "HintFile")  
  
### <a name="directories-and-hint-file-contents"></a>Diretórios e conteúdo do arquivo de dica  
 A lista a seguir mostra os diretórios nesse projeto que contêm arquivos de dica e o conteúdo desses arquivos de dica. Apenas algumas das muitas dicas no arquivo de dica do diretório `vcpackages` são listadas.  
  
-   vcpackages  
  
    ```  
    // vcpackages (partial list)  
    #define _In_  
    #define _In_opt_  
    #define _In_z_  
    #define _In_opt_z_  
    #define _In_count_(size)  
    ```  
  
-   Depurar  
  
    ```  
    // Debug  
    #undef _In_  
    #define OBRACE {  
    #define CBRACE }  
    #define RAISE_EXCEPTION(x) throw (x)  
    #define START_NAMESPACE namespace MyProject {  
    #define END_NAMESPACE }  
    ```  
  
-   A1  
  
    ```  
    // A1  
    #define START_NAMESPACE namespace A1Namespace {  
    ```  
  
-   A2  
  
    ```  
    // A2  
    #undef OBRACE  
    #undef CBRACE  
    ```  
  
### <a name="effective-hints"></a>Dicas efetivas  
 A tabela a seguir lista as dicas efetivas para os arquivos de origem nesse projeto.  
  
-   Arquivo de origem: A1_A2_B.cpp  
  
-   Dicas efetivas:  
  
    ```  
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
  
 As observações a seguir se aplicam à lista anterior.  
  
-   As dicas efetivas pertencem aos diretórios `vcpackages`, `Debug`, `A1` e `A2`.  
  
-   A diretiva **#undef** no arquivo de dica `Debug` removeu a dica `#define _In_` do arquivo de dica do diretório `vcpackages`.  
  
-   O arquivo de dica no diretório `A1` redefine `START_NAMESPACE`.  
  
-   A dica `#undef` no diretório `A2` removeu as dicas para `OBRACE` e `CBRACE` no arquivo de dica do diretório `Debug`.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)    
 [Diretiva #define (C/C++)](../preprocessor/hash-define-directive-c-cpp.md)   
 [Diretiva #undef (C/C++)](../preprocessor/hash-undef-directive-c-cpp.md)   
 [Anotações de SAL](../c-runtime-library/sal-annotations.md)   
 [Mapas de Mensagens](../mfc/reference/message-maps-mfc.md)   
 [Macros de Mapa de Mensagens](../atl/reference/message-map-macros-atl.md)   
 [Macros de mapa de objeto](../atl/reference/object-map-macros.md)