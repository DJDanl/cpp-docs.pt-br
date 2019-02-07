---
title: Ponteiros inteligentes (C++ moderno)
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: 909ef870-904c-49b6-b8cd-e9d0b7dc9435
ms.openlocfilehash: c976f9ec72929f2c8ff91fb9f9594d91c7457365
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220654"
---
# <a name="smart-pointers-modern-c"></a>Ponteiros inteligentes (C++ moderno)

Na programação do C++ moderna, a biblioteca padrão inclui *ponteiros inteligentes*, que são usados para ajudar a garantir que os programas estejam livres de memória e vazamentos de recursos e são protegidos contra exceções.

## <a name="uses-for-smart-pointers"></a>Uso de ponteiros inteligentes

Ponteiros inteligentes são definidos na namespace `std` no arquivo de cabeçalho [ \<memory >](../standard-library/memory.md). Eles são essenciais para a linguagem de programação [RAII](../cpp/objects-own-resources-raii.md) ou *Aquisição de Recurso é Inicialização*. O objetivo principal dessa linguagem é garantir que a aquisição de recursos ocorra ao mesmo tempo em que o objeto é inicializado, de forma que todos os recursos do objeto sejam criados e preparados em uma linha de código. Em termos práticos, o princípio fundamental da linguagem RAII é fornecer a propriedade de qualquer recurso alocado a heap, por exemplo, memória alocada dinamicamente ou identificadores de objetos do sistema, a um objeto alocado em pilha cujo destrutor contenha o código para excluir ou liberar o recurso e também qualquer código de limpeza associado.

Na maioria dos casos, quando você inicializa um ponteiro bruto ou identificador de recursos para apontar para um recurso real, transforma o ponteiro em ponteiro inteligente imediatamente. Em C++ moderno, os ponteiros brutos são usados somente em pequenos blocos de código de escopo limitado, loops ou funções auxiliares onde o desempenho é essencial e não há possibilidade de confusão sobre a propriedade.

O exemplo a seguir compara uma declaração de ponteiro bruto a uma declaração de ponteiro inteligente.

[!code-cpp[smart_pointers_intro#1](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_1.cpp)]

Conforme mostrado no exemplo, um ponteiro inteligente é um modelo de classe que você declara na pilha e inicializa usando um ponteiro bruto que aponta para um objeto alocado na heap. Depois que o ponteiro inteligente é inicializado, ele possui o ponteiro bruto. Isso significa que o ponteiro inteligente é responsável pela exclusão da memória especificada pelo ponteiro bruto. O destrutor do ponteiro inteligente contém a chamada para exclusão e, como o ponteiro inteligente é declarado na pilha, seu destrutor é chamado quando o ponteiro inteligente fica fora do escopo, mesmo se uma exceção for lançada posteriormente na pilha.

Acesse o ponteiro encapsulado usando os operadores de ponteiros familiares, `->` e `*`, que a classe do ponteiro inteligente sobrecarrega para retornar o ponteiro bruto encapsulado.

A linguagem de ponteiro inteligente C++ é semelhante à criação de objeto em linguagens como C#: você cria o objeto e permite que o sistema cuide de sua exclusão no momento certo. A diferença é que nenhum coletor de lixo separado é executado em segundo plano; a memória é gerenciada com as regras de escopo padrão do C++ para que o ambiente de tempo de execução seja mais rápido e mais eficiente.

> [!IMPORTANT]
>  Crie sempre ponteiros inteligentes em uma linha de código separada, nunca em uma lista de parâmetros, de forma que um vazamento sutil de recursos não ocorra devido a determinadas regras de alocação da lista de parâmetros.

O exemplo a seguir mostra como um tipo de ponteiro inteligente `unique_ptr` da biblioteca padrão do C++ pode ser usado para encapsular um ponteiro para um objeto grande.

[!code-cpp[smart_pointers_intro#2](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_2.cpp)]

O exemplo demonstra as etapas essenciais a seguir para o uso de ponteiros inteligentes.

1. Declare o ponteiro inteligente como uma variável automática (local). (Não use as expressões **new** ou `malloc` no próprio ponteiro inteligente.)

1. No parâmetro de tipo, especifique o tipo apontado do ponteiro encapsulado.

1. Passe um ponteiro bruto para um **novo** objeto no construtor de ponteiro inteligente. (Algumas funções do utilitário ou construtores de ponteiro inteligente fazem isso para você.)

1. Use os operadores `->` e `*` sobrecarregados para acessar o objeto.

1. Deixe o ponteiro inteligente excluir o objeto.

Ponteiros inteligentes são criados para terem a maior eficiência possível em termos de memória e de desempenho. Por exemplo, o único membro de dados em `unique_ptr` é o ponteiro encapsulado. Isso significa que `unique_ptr` é exatamente do mesmo tamanho que o ponteiro, com quatro bytes ou com oito bytes. O acesso ao ponteiro encapsulado usando os operadores * e -> sobrecarregados pelo ponteiro inteligente não é significativamente mais lento que o acesso direto aos ponteiros brutos.

Os ponteiros inteligentes têm suas próprias funções membro, que são acessadas usando a notação "ponto final". Por exemplo, alguns ponteiros inteligentes da biblioteca padrão do C++ têm uma função membro de redefinição que libera a propriedade do ponteiro. Isso é útil quando você deseja liberar a memória do ponteiro inteligente antes que o ponteiro inteligente saia do escopo, como mostrado no exemplo a seguir.

[!code-cpp[smart_pointers_intro#3](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_3.cpp)]

Os ponteiros inteligentes geralmente oferecem uma maneira de acessar diretamente seu ponteiro bruto. Ponteiros inteligentes da biblioteca padrão do C++ têm uma função membro `get` para essa finalidade, e `CComPtr` tem um membro de classe`p` público. Fornecendo acesso direto ao ponteiro subjacente, você pode usar o ponteiro inteligente para gerenciar a memória em seu próprio código e ainda passar o ponteiro bruto para o código que não oferece suporte a ponteiros inteligentes.

[!code-cpp[smart_pointers_intro#4](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_4.cpp)]

## <a name="kinds-of-smart-pointers"></a>Tipos de ponteiros inteligentes

A seção a seguir resume os diferentes tipos de ponteiros inteligentes que estão disponíveis no ambiente de programação do Windows e descreve quando usá-los.

### <a name="c-standard-library-smart-pointers"></a>Ponteiros Inteligentes da Biblioteca Padrão C++

Use esses ponteiros inteligentes como uma primeira opção para encapsular ponteiros para objetos C ++ simples (POCO).

- `unique_ptr`<br/>
   Permite exatamente um proprietário do ponteiro subjacente. Use como a opção padrão para POCO, a menos que você tenha certeza de que precisa de um `shared_ptr`. Pode ser movido para um novo proprietário, mas não copiado ou compartilhado. Substitui `auto_ptr`, que será preterido. Compare com `boost::scoped_ptr`. `unique_ptr` é pequeno e eficiente; o tamanho é um ponteiro e ele dá suporte a referências de rvalue para rápida inserção e recuperação das coleções de biblioteca padrão C++. Arquivo de cabeçalho: `<memory>`. Para obter mais informações, confira [Como: Criar e usar instâncias unique_ptr](../cpp/how-to-create-and-use-unique-ptr-instances.md) e [classe unique_ptr](../standard-library/unique-ptr-class.md)

- `shared_ptr`<br/>
   Ponteiro inteligente contado por referência. Use quando quiser atribuir um ponteiro bruto a vários proprietários, por exemplo, ao retornar uma cópia de um ponteiro de um contêiner, porém mantendo o original. O ponteiro bruto não será excluído até que todos os proprietários de `shared_ptr` tenham saído do escopo ou tenham desistido da propriedade. O tamanho é de dois ponteiros; um para o objeto e um para o bloco de controle compartilhado que contém a contagem de referência. Arquivo de cabeçalho: `<memory>`. Para obter mais informações, confira [Como: Criar e usar instâncias shared_ptr](../cpp/how-to-create-and-use-shared-ptr-instances.md) e [classe shared_ptr](../standard-library/shared-ptr-class.md).

- `weak_ptr`<br/>
    Ponteiro inteligente de casos especiais para uso em conjunto com `shared_ptr`. Um `weak_ptr` fornece acesso a um objeto pertencente a uma ou mais instâncias de `shared_ptr`, mas não participa da contagem de referência. Use quando você quiser observar um objeto, mas sem exigir que ele permaneça ativo. Necessário em alguns casos para interromper referências circulares entre instâncias `shared_ptr`. Arquivo de cabeçalho: `<memory>`. Para obter mais informações, confira [Como: Criar e usar instâncias weak_ptr](../cpp/how-to-create-and-use-weak-ptr-instances.md) e [classe weak_ptr](../standard-library/weak-ptr-class.md).

### <a name="smart-pointers-for-com-objects-classic-windows-programming"></a>Ponteiros inteligentes para objetos COM (programação clássica do Windows)

Ao trabalhar com objetos COM, coloque os ponteiros de interface em um tipo de ponteiro inteligente apropriado. A ATL (Active Template Library) define vários ponteiros inteligentes para várias finalidades. Você também pode usar o tipo de ponteiro inteligente `_com_ptr_t`, que o compilador usa ao criar classes wrapper dos arquivos .tlb. É a melhor opção quando você não quer incluir os arquivos de cabeçalho da ATL.

[Classe CComPtr](../atl/reference/ccomptr-class.md)<br/>
Use isso a menos que você não possa usar a ATL. Executa a contagem de referência usando os métodos `AddRef` e `Release`. Para obter mais informações, confira [Como: Criar e usar instâncias CComPtr e CComQIPtr](../cpp/how-to-create-and-use-ccomptr-and-ccomqiptr-instances.md).

[Classe CComQIPtr](../atl/reference/ccomqiptr-class.md)<br/>
É semelhante a `CComPtr` mas também fornece a sintaxe simplificada para chamar `QueryInterface` em objetos COM. Para obter mais informações, confira [Como: Criar e usar instâncias CComPtr e CComQIPtr](../cpp/how-to-create-and-use-ccomptr-and-ccomqiptr-instances.md).

[Classe CComHeapPtr](../atl/reference/ccomheapptr-class.md)<br/>
Ponteiro inteligente para objetos que usam `CoTaskMemFree` para liberar memória.

[Classe CComGITPtr](../atl/reference/ccomgitptr-class.md)<br/>
Ponteiro inteligente para as interfaces que são obtidas da tabela de interface global (GIT).

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)<br/>
É semelhante a `CComQIPtr` em funcionalidade, mas não depende de cabeçalhos da ATL.

### <a name="atl-smart-pointers-for-poco-objects"></a>Ponteiros inteligentes da ATL para objetos POCO

Além de ponteiros inteligentes para objetos COM, a ATL também define ponteiros inteligentes e coleções de ponteiros inteligentes, para objetos C++ simples. Na programação clássica do Windows, esses tipos são alternativas úteis para as coleções de biblioteca padrão C++, especialmente quando a portabilidade do código não é necessária ou quando você não deseja combinar os modelos de programação da Biblioteca Padrão do C++ e da ATL.

[Classe CAutoPtr](../atl/reference/cautoptr-class.md)<br/>
Ponteiro inteligente que impõe a propriedade exclusiva transferindo a propriedade na cópia. Comparável à classe `std::auto_ptr` preterida.

[Classe CHeapPtr](../atl/reference/cheapptr-class.md)<br/>
Ponteiro inteligente para objetos alocados usando o função [malloc](../c-runtime-library/reference/malloc.md) do C.

[Classe CAutoVectorPtr](../atl/reference/cautovectorptr-class.md)<br/>
Ponteiro inteligente para matrizes que são alocadas usando `new[]`.

[Classe CAutoPtrArray](../atl/reference/cautoptrarray-class.md)<br/>
Classe que encapsula uma matriz de elementos `CAutoPtr`.

[Classe CAutoPtrList](../atl/reference/cautoptrlist-class.md)<br/>
Classe que encapsula métodos para manipular uma lista de nós `CAutoPtr`.

## <a name="see-also"></a>Consulte também

[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
