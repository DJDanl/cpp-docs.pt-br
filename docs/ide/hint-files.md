---
title: Arquivos de dica | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 432b5fa5041a7997c9df0593dc511c29854387ab
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hint-files"></a>Arquivos de dica
Um *arquivo de dica* Ajuda do Visual Studio identificadores do Visual C++, como os nomes de funções e macros de interpretar do ambiente de desenvolvimento integrado (IDE). Quando você abre um projeto de Visual C++, o IDE *análise sistema* analisa o código em cada arquivo de origem no projeto e reúne informações sobre cada identificador. Em seguida, o IDE usa essas informações para dar suporte a recursos como o **exibição de classe** navegador e o **barra de navegação**.  
  
 O sistema de análise, que foi introduzido no Visual C++ 2010, entenda a sintaxe do C/C++, mas pode interpretar incorretamente uma instrução que contém uma macro. Se a macro faz com que o código-fonte seja sintaticamente incorreto como escrito pode ser interpretados incorretamente a instrução. A instrução pode se tornar sintaticamente correta quando o código-fonte é compilado e o pré-processador substitui o [identificador de macro](../preprocessor/hash-define-directive-c-cpp.md) com sua definição. O sistema de análise funciona sem a necessidade de compilar o projeto porque ele usa os arquivos de dica para interpretar as macros. Portanto, uma pesquisa de recursos, como **exibição de classe** está imediatamente disponível.  
  
 Um arquivo de dica contém usuário personalizável *dicas*, que tem a mesma sintaxe que as definições de macro do C/C++. Visual C++ inclui um arquivo de dica interna que é suficiente para a maioria dos projetos, mas você pode criar seus próprios arquivos de dica para melhorar a maneira como o Visual Studio trata de identificadores.  
  
> [!IMPORTANT]
>  Se você modificar ou adiciona um arquivo de dica, você deve excluir o arquivo. sdf e/ou VC.db arquivo da solução para que as alterações entrem em vigor.  
  
## <a name="scenario"></a>Cenário  
 Suponha que o código a seguir está em um arquivo de origem que você examinar com o **exibição de classe** navegador. O `STDMETHOD` macro declara um método chamado `myMethod` que pega um parâmetro e retorna um ponteiro para um **HRESULT**.  
  
```  
// Source code file.  
STDMETHOD(myMethod)(int parameter1);  
```  
  
 As seguintes definições de macro estão em um arquivo de cabeçalho separado.  
  
```  
// Header file.  
#define STDMETHOD(method) HRESULT (STDMETHODCALLTYPE * method)  
#define STDMETHODCALLTYPE __stdcall  
#define HRESULT void*  
```  
  
 O sistema de análise não é possível interpretar o código-fonte porque uma função chamada STDMETHOD parece ser declarado e declaração seja sintaticamente incorreta porque ela tem duas listas de parâmetros. O sistema de análise não abrir o arquivo de cabeçalho para descobrir as definições para o `STDMETHOD`, `STDMETHODCALLTYPE`, e `HRESULT` macros. Como o sistema de análise não pode interpretar o `STDMETHOD` macro, ele ignora toda a instrução e, em seguida, continua a análise.  
  
 O sistema de análise não usa arquivos de cabeçalho porque seu projeto pode depender de um ou mais arquivos de cabeçalho importantes. Se qualquer arquivo de cabeçalho for alterado, o sistema de análise talvez precise reexaminar todos os arquivos de cabeçalho em seu projeto, o que diminui o desempenho do IDE. Em vez disso, o sistema de análise usa dicas que especificam como tratar o `STDMETHOD`, `STDMETHODCALLTYPE`, e `HRESULT` macros.  
  
 Como você sabe que você precisa de uma dica? E se você precisar de uma dica, que tipo você deve criar? É um sinal de que é necessário, uma dica se o modo de exibição de um identificador em **exibição de classe** está inconsistente com o modo de exibição a **Editor**. Por exemplo, **exibição de classe** podem não exibir um membro de classe que você sabe que existe, ou o nome do membro está incorreto. Para obter mais informações sobre os tipos de dicas que resolvam problemas comuns, consulte a qual Macros exigem uma dica? seção mais adiante neste tópico.  
  
## <a name="architecture"></a>Arquitetura  
 Arquivos de dica pertencem aos diretórios físicos, não as pastas lógicas descritos nos **Gerenciador de soluções**. Você não precisa adicionar um arquivo de dica ao seu projeto para o arquivo de dica ter efeito. O sistema de análise usa arquivos de dica somente quando ele analisa os arquivos de origem.  
  
 Cada arquivo de dica é denominado **cpp.hint**. Portanto, vários diretórios podem conter um arquivo de dica mas arquivo somente uma dica pode ocorrer em um diretório específico.  
  
 Seu projeto pode ser afetado por zero ou mais arquivos de dica. Se não houver nenhum arquivo de dica, o sistema de análise usa técnicas de recuperação de erro para ignorar o código-fonte indecifráveis. Caso contrário, o sistema de análise usa a estratégia a seguir para encontrar e reunir dicas.  
  
### <a name="search-order"></a>Ordem de pesquisa  
 O sistema de análise procura diretórios para arquivos de dica na seguinte ordem.  
  
-   O diretório que contém o pacote de instalação do Visual C++ (**vcpackages**). Este diretório contém um arquivo de dica interno que descreve os símbolos nos arquivos de sistema usados com frequência, como **Windows. h**. Consequentemente, o seu projeto herda automaticamente a maioria das dicas que ele precisa.  
  
-   O caminho do diretório raiz de um arquivo de origem para o diretório que contém o arquivo de origem. Em um projeto típico do Visual C++, o diretório raiz contém o arquivo de solução ou projeto.  
  
     A exceção a essa regra é se um *arquivos* é o caminho para o arquivo de origem. Um arquivo de parada fornece controle adicional sobre a ordem de pesquisa e é qualquer arquivo chamado **cpp.stop**. Em vez de a partir do diretório raiz, o sistema de análise procura do diretório que contém os arquivos para o diretório que contém o arquivo de origem. Em um projeto típico, não é necessário um arquivo de parada.  
  
### <a name="hint-gathering"></a>Coleta de dica  
 Um arquivo de dica contém zero ou mais *dicas*. Uma dica está definida ou excluída, assim como uma macro de C/C++. Ou seja, o `#define` diretiva de pré-processador cria ou redefine uma dica e o `#undef` diretiva exclui uma dica.  
  
 O sistema de análise abre cada arquivo de dica na ordem de pesquisa descrito anteriormente, acumula dicas de cada arquivo em um conjunto de *dicas efetivas*e, em seguida, usa as Dicas eficazes para interpretar os identificadores em seu código.  
  
 O sistema de análise usa as seguintes regras para acumular dicas.  
  
-   Se a nova dica especifica um nome que já não está definido, a nova dica adiciona o nome para as dicas efetivas.  
  
-   Se a nova dica especifica um nome que já está definido, a nova dica redefinirá a dica existente.  
  
-   Se a nova dica é um `#undef` diretiva que especifica uma dica efetivada existente, a nova dica exclui a dica existente.  
  
 A primeira regra significa que efetivo dicas são herdadas dos arquivos de dica abertos anteriormente. As últimas duas regras significam que as dicas que ocorrem posteriormente na ordem de pesquisa podem substituir dicas que ocorreram anteriormente. Por exemplo, você pode substituir todas as dicas anteriores se você criar um arquivo de dica no diretório que contém um arquivo de origem.  
  
 Para uma descrição de como as dicas são coletadas, consulte o `Example` seção mais adiante neste tópico.  
  
### <a name="syntax"></a>Sintaxe  
 Dicas são criadas e excluídas com a mesma sintaxe que as diretivas de pré-processador que criam e excluem macros. Na verdade, o sistema de análise usa o pré-processador C/C++ para avaliar as dicas. Para obter mais informações sobre as diretivas de pré-processamento, consulte [#define (C/C++) de diretiva](../preprocessor/hash-define-directive-c-cpp.md) e [#undef diretiva (C/C++)](../preprocessor/hash-undef-directive-c-cpp.md).  
  
 Os elementos de sintaxe incomum só são o `@<`, `@=`, e `@>` cadeias de caracteres de substituição. São cadeias de caracteres de substituição específico de arquivo de dica que são usadas somente com *mapa* macros. Um mapa é um conjunto de macros que se relacionam dados, funções ou eventos com outros dados, funções ou manipuladores de eventos. Por exemplo, `MFC` usa mapas para criar [mapas de mensagem](../mfc/reference/message-maps-mfc.md), e `ATL` usa mapas para criar [mapas do objeto](../atl/reference/object-map-macros.md). As cadeias de caracteres de substituição específico do arquivo de dica indicam os elementos iniciais, intermediários e final de um mapa. Somente o nome de uma macro de mapa é significativo. Portanto, cada cadeia de caracteres de substituição intencionalmente oculta a implementação da macro.  
  
 Dicas de usam a sintaxe a seguir.  
  
|Sintaxe|Significado|  
|------------|-------------|  
|`#define`*nome dica* *cadeia de caracteres de substituição*<br /><br /> `#define`*nome dica* `(` *parâmetro*,... `)` *cadeia de caracteres de substituição*|Uma diretiva de pré-processador que define uma nova dica ou redefine uma dica existente. Após a diretiva de pré-processador substitui cada ocorrência de *nome dica* no código-fonte com *cadeia de caracteres de substituição*.<br /><br /> O segundo formulário de sintaxe define uma dica de função. Se ocorrer uma dica de função no código-fonte, o pré-processador primeiro substitui cada ocorrência de *parâmetro* na *cadeia de caracteres de substituição* com o argumento correspondente no código-fonte e, em seguida, substitui o *nome dica* com *cadeia de caracteres de substituição*.|  
|`@<`|Um determinado arquivo de dica *cadeia de caracteres de substituição* que indica o início de um conjunto de elementos do mapa.|  
|`@=`|Um determinado arquivo de dica *cadeia de caracteres de substituição* que indica um elemento do mapa intermediário. Um mapa pode ter vários elementos do mapa.|  
|`@>`|Um determinado arquivo de dica *cadeia de caracteres de substituição* que indica o final de um conjunto de elementos do mapa.|  
|`#undef`*nome de dica*|A diretiva de pré-processador que exclui uma dica existente. O nome da dica é fornecido pelo *nome dica* identificador.|  
|`//`*comentário*|Um comentário de linha única.|  
|`/*`*comentário*`*/`|Um comentário de várias linhas.|  
  
## <a name="what-macros-require-a-hint"></a>O que Macros exigem uma dica?  
 Certos tipos de macros podem interferir com o sistema de análise. Esta seção descreve os tipos de macros que podem causar um problema e o tipo de dica, que você pode criar para resolver o problema.  
  
### <a name="disruptive-macros"></a>Macros de interrupção  
 Algumas macros com que o sistema de análise interpretar incorretamente o código-fonte, mas podem ser ignoradas sem comprometer sua experiência de navegação. Por exemplo, a linguagem de anotação do código fonte ([SAL](../c-runtime-library/sal-annotations.md)) macros resolver para atributos de C++ para ajudarão-lo a localizar erros de programação. Se você quiser ignorar as anotações SAL como procurar o código, talvez queira criar um arquivo de dica que oculta a anotação.  
  
 No seguinte código-fonte, o parâmetro de tipo para o `FormatWindowClassName()` função é `PXSTR`, e o nome do parâmetro é `szBuffer`. No entanto, os erros de sistema de análise de `_Pre_notnull_` e `_Post_z_` anotações de SAL para o tipo de parâmetro ou o nome do parâmetro.  
  
 **Código-fonte:**  
  
```  
static void FormatWindowClassName(_Pre_notnull__Post_z_ PXSTR szBuffer)  
```  
  
 **Estratégia:** Null definição  
  
 A estratégia nessa situação é tratar as anotações de SAL como se não existirem. Para fazer isso, especifique uma dica cuja cadeia de caracteres de substituição é nula. Consequentemente, o sistema de análise ignora as anotações e o **exibição de classe** navegador não exibi-los. (Visual C++ inclui um arquivo de dica internas que oculta anotação SAL.)  
  
 **Arquivo de dica:**  
  
```  
#define _Pre_notnull_  
```  
  
### <a name="concealed-cc-language-elements"></a>Elementos de linguagem do C/C++ oculto  
 Um motivo comum pelo que o sistema de análise interpreta erroneamente código-fonte é se uma macro oculta um C/C++ [pontuador](../cpp/punctuators-cpp.md) ou [palavra-chave](../cpp/keywords-cpp.md) token. Ou seja, uma macro pode conter metade de um par de sinais de pontuação, como `<>`, `[]`, `{}`, e `()`.  
  
 No seguinte código-fonte, o `START_NAMESPACE` macro oculta um colchete esquerdo não emparelhado (`{`).  
  
 **Código-fonte:**  
  
```  
#define START_NAMESPACE namespace MyProject {  
```  
  
 **Estratégia:** direto de cópia  
  
 Se a semântica de uma macro é essencial para a experiência de navegação, crie uma dica que seja idêntica de macro. O sistema de análise resolve a macro para a definição no arquivo de dica.  
  
 Observe que, se a macro no arquivo de origem contém outras macros, as macros são interpretadas somente se eles já estão no conjunto de dicas efetivos.  
  
 **Arquivo de dica:**  
  
```  
#define START_NAMESPACE namespace MyProject {  
```  
  
### <a name="maps"></a>Mapas  
 Consiste em um mapa de macros que designa um elemento inicial, final e zero ou mais elementos intermediários. O sistema de análise interpreta erroneamente mapas porque cada macro mapa oculta os elementos de linguagem C/C++ e a sintaxe de uma instrução completa do C/C++ é distribuída entre várias macros separadas.  
  
 O código de origem a seguir define o `BEGIN_CATEGORY_MAP`, `IMPLEMENTED_CATEGORY`, e `END_CATEGORY_MAP` macros.  
  
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
  
 **Estratégia:** identificar elementos do mapa  
  
 Especificar dicas para o início, meio (se houver) e término elementos de um mapa. Use as cadeias de caracteres de substituição de mapa especial `@<`, `@=`, e `@>`. Para obter mais informações, consulte o `Syntax` neste tópico.  
  
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
 Macros compostas contêm um ou mais dos tipos de macro que confunda o sistema de análise.  
  
 O seguinte código-fonte contém o `START_NAMESPACE` macro, que especifica o início de um escopo de namespace, e o `BEGIN_CATEGORY_MAP` macro, que especifica o início de um mapa.  
  
 **Código-fonte:**  
  
```  
#define NSandMAP START_NAMESPACE BEGIN_CATEGORY_MAP  
```  
  
 **Estratégia:** direto de cópia  
  
 Criar dicas para o `START_NAMESPACE` e `BEGIN_CATEGORY_MAP` macros e, em seguida, crie uma dica para o `NSandMAP` macro é o mesmo mostrado anteriormente para o código-fonte. Como alternativa, se uma macro composta consiste somente macros interrupções e espaço em branco, você pode definir uma dica cuja cadeia de caracteres de substituição é uma definição de null.  
  
 Nesse exemplo, suponha que `START_NAMESPACE` já tem uma dica, conforme descrito neste tópico o `Concealed C/C++ Language Elements` subtítulo. E suponha `BEGIN_CATEGORY_MAP` tem uma dica, conforme descrito anteriormente na `Maps`.  
  
 **Arquivo de dica:**  
  
```  
#define NSandMAP START_NAMESPACE BEGIN_CATEGORY_MAP  
```  
  
### <a name="inconvenient-macros"></a>Macros inconvenientes  
 Algumas macros podem ser interpretadas pelo sistema de análise, mas o código-fonte é difícil de ler, pois a macro é longa ou complexa. Para fins de legibilidade, você pode fornecer uma dica que simplifica a exibição da macro.  
  
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
 O exemplo a seguir ilustra como as dicas são acumuladas de arquivos de dica. Parada de arquivos não são usados neste exemplo.  
  
 A ilustração a seguir mostra alguns dos diretórios físicos em um projeto do Visual C++. Arquivos de dica estão no `vcpackages`, `Debug`, `A1`, e `A2` diretórios.  
  
### <a name="hint-file-directories"></a>Diretórios de arquivos de dica  
 ![Comuns e projeto &#45; diretórios de arquivos de dica específica. ] (../ide/media/hintfile.png "HintFile")  
  
### <a name="directories-and-hint-file-contents"></a>Diretórios e o conteúdo do arquivo de dica  
 A lista a seguir mostra os diretórios neste projeto que contêm arquivos de dica e o conteúdo desses arquivos de dica. Apenas algumas das muitas dicas no `vcpackages` arquivo de dica de diretório são listados.  
  
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
  
### <a name="effective-hints"></a>Dicas de efetivas  
 A tabela a seguir lista as Dicas eficazes para os arquivos de origem neste projeto.  
  
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
  
 As observações a seguir se aplicam a lista anterior.  
  
-   As dicas efetivas são do `vcpackages`, `Debug`, `A1`, e `A2` diretórios.  
  
-   O **#undef** diretiva no `Debug` removido do arquivo de dica de `#define _In_` dica no `vcpackages` arquivo de dica de diretório.  
  
-   O arquivo de dica no `A1` redefine o diretório `START_NAMESPACE`.  
  
-   O `#undef` dica no `A2` as dicas para remover do diretório `OBRACE` e `CBRACE` no `Debug` arquivo de dica de diretório.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)    
 [#define diretiva (C/C++)](../preprocessor/hash-define-directive-c-cpp.md)   
 [#undef diretiva (C/C++)](../preprocessor/hash-undef-directive-c-cpp.md)   
 [Anotações de SAL](../c-runtime-library/sal-annotations.md)   
 [Mapas de mensagem](../mfc/reference/message-maps-mfc.md)   
 [Macros de mapa de mensagem](../atl/reference/message-map-macros-atl.md)   
 [Macros de mapa de objeto](../atl/reference/object-map-macros.md)