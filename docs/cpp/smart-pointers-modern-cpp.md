---
title: "Ponteiros inteligentes (C++ moderno) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 909ef870-904c-49b6-b8cd-e9d0b7dc9435
caps.latest.revision: 26
caps.handback.revision: 26
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ponteiros inteligentes (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na programação em C\+\+ moderno, a Biblioteca Padrão inclui *ponteiros inteligentes*, que são usados para garantir que os programas estejam livres de vazamentos de memória e de recursos e sejam protegidos contra exceções.  
  
## Uso de ponteiros inteligentes  
 Os ponteiros inteligentes são definidos no namespace `std` no arquivo de cabeçalho [\<memory\>](../standard-library/memory.md).  Eles são essenciais para a linguagem de programação [RAII](../cpp/objects-own-resources-raii.md) ou *Resource Acquisition Is Initialialization* \(aquisição de recurso é inicialização\).  O objetivo principal dessa linguagem é garantir que a aquisição de recursos ocorra ao mesmo tempo em que o objeto é inicializado, de forma que todos os recursos do objeto sejam criados e preparados em uma linha de código.  Em termos práticos, o princípio fundamental da linguagem RAII é fornecer a propriedade de qualquer recurso alocado a heap, por exemplo, memória alocada dinamicamente ou identificadores de objetos do sistema, a um objeto alocado em pilha cujo destruidor contenha o código para excluir ou liberar o recurso e também qualquer código de limpeza associado.  
  
 Na maioria dos casos, quando você inicializa um ponteiro bruto ou identificador de recursos para apontar para um recurso real, transforma o ponteiro em ponteiro inteligente imediatamente.  Em C\+\+ moderno, os ponteiros brutos são usados somente em pequenos blocos de código de escopo limitado, loops ou funções auxiliares onde o desempenho é essencial e não há possibilidade de confusão sobre a propriedade.  
  
 O exemplo a seguir compara uma declaração de ponteiro bruto a uma declaração de ponteiro inteligente.  
  
 [!code-cpp[smart_pointers_intro#1](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_1.cpp)]  
  
 Conforme mostrado no exemplo, um ponteiro inteligente é um modelo de classe que você declara na pilha e inicializa usando um ponteiro bruto que aponta para um objeto alocado a heap.  Depois que o ponteiro inteligente é inicializado, ele possui o ponteiro bruto.  Isso significa que o ponteiro inteligente é responsável pela exclusão da memória especificada pelo ponteiro bruto.  O destruidor do ponteiro inteligente contém a chamada para exclusão e, como o ponteiro inteligente é declarado na pilha, seu destruidor é chamado quando o ponteiro inteligente fica fora do escopo, mesmo se uma exceção for lançada posteriormente na pilha.  
  
 Acesse o ponteiro encapsulado usando os operadores de ponteiros familiares, `->` e `*`, que a classe do ponteiro inteligente sobrecarrega para retornar o ponteiro bruto encapsulado.  
  
 A linguagem de ponteiro inteligente C\+\+ é semelhante à criação de objeto em linguagens como C\#: você cria o objeto e permite que o sistema cuide de sua exclusão no momento certo.  A diferença é que nenhum coletor de lixo separado é executado em segundo plano; a memória é gerenciada com as regras de escopo C\+\+ padrão de modo que o ambiente em tempo de execução seja mais rápido e mais eficiente.  
  
> [!IMPORTANT]
>  Crie sempre ponteiros inteligentes em uma linha de código separada, nunca em uma lista de parâmetros, de forma que um vazamento sutil de recursos não ocorre devido a determinadas regras de alocação da lista de parâmetros.  
  
 O exemplo a seguir mostra como um tipo de ponteiro inteligente `unique_ptr` da Biblioteca de Modelos Padrão poderia ser usado para encapsular um ponteiro para um objeto grande.  
  
 [!code-cpp[smart_pointers_intro#2](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_2.cpp)]  
  
 O exemplo demonstra as etapas essenciais a seguir para o uso de ponteiros inteligentes.  
  
1.  Declare o ponteiro inteligente como uma variável automática \(local\). \(Não use a expressão `new` ou `malloc` no próprio ponteiro inteligente.\)  
  
2.  No parâmetro de tipo, especifique o tipo apontado do ponteiro encapsulado.  
  
3.  Passe um ponteiro bruto para um objeto `new` no construtor do ponteiro inteligente. \(Algumas funções do utilitário ou construtores de ponteiro inteligente fazem isso para você.\)  
  
4.  Use os operadores `->` e `*` sobrecarregados para acessar o objeto.  
  
5.  Deixe o ponteiro inteligente excluir o objeto.  
  
 Ponteiros inteligentes são criados para terem a maior eficiência possível em termos de memória e de desempenho.  Por exemplo, o único membro de dados em `unique_ptr` é o ponteiro encapsulado.  Isso significa que `unique_ptr` é exatamente do mesmo tamanho que o ponteiro, com quatro bytes ou com oito bytes.  O acesso ao ponteiro encapsulado usando os operadores \* e \-\> sobrecarregados pelo ponteiro inteligente não é significativamente mais lento que o acesso direto aos ponteiros brutos.  
  
 Os ponteiros inteligentes têm suas próprias funções de membro, que são acessadas usando a notação "dot".  Por exemplo, alguns ponteiros inteligentes STL têm uma função de membro de redefinição que libera a propriedade do ponteiro.  Isso é útil quando você deseja liberar a memória possuída pelo ponteiro inteligente antes que o ponteiro inteligente saia do escopo, como mostrado no exemplo a seguir.  
  
 [!code-cpp[smart_pointers_intro#3](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_3.cpp)]  
  
 Os ponteiros inteligentes geralmente oferecem uma maneira de acessar diretamente seu ponteiro bruto.  Os ponteiros inteligentes STL têm uma função membro `get` para essa finalidade e `CComPtr` tem um membro de classe `p` público.  Fornecendo acesso direto ao ponteiro subjacente, você pode usar o ponteiro inteligente para gerenciar a memória em seu próprio código e ainda passar o ponteiro bruto para o código que não oferece suporte a ponteiros inteligentes.  
  
 [!code-cpp[smart_pointers_intro#4](../cpp/codesnippet/CPP/smart-pointers-modern-cpp_4.cpp)]  
  
## Tipos de ponteiros inteligentes  
 A seção a seguir resume os diferentes tipos de ponteiros inteligentes que estão disponíveis no ambiente de programação do Windows e descreve quando usá\-los.  
  
 **Ponteiros Inteligentes da Biblioteca Padrão C\+\+**  
 Use esses ponteiros inteligentes como primeira opção para o encapsulamento de ponteiros para objetos C\+\+ antigos simples \(POCO\).  
  
-   `unique_ptr`    
    Permite exatamente um proprietário do ponteiro subjacente.  Use como a opção padrão para POCO, a menos que você tenha certeza de que precisa de um `shared_ptr`.  Pode ser movido para um novo proprietário, mas não copiado ou compartilhado.  Substitui `auto_ptr`, que será preterido.  Compare com `boost::scoped_ptr`.  `unique_ptr` é pequeno e eficiente; o tamanho é um ponteiro e oferece suporte a referências rvalue para a rápida inserção e recuperação das coleções STL.  Arquivo de cabeçalho: `<memory>`.  Para obter mais informações, consulte [Como criar e usar instâncias unique\_ptr](../cpp/how-to-create-and-use-unique-ptr-instances.md) e [Classe unique\_ptr](../standard-library/unique-ptr-class.md).  
  
-   `shared_ptr`    
    Ponteiro inteligente contado por referência.  Use quando quiser atribuir um ponteiro bruto a vários proprietários, por exemplo, ao retornar uma cópia de um ponteiro de um contêiner, porém mantendo o original.  O ponteiro bruto não será excluído até que todos os proprietários de `shared_ptr` tenham saído do escopo ou tenham desistido da propriedade.  O tamanho é de dois ponteiros; um para o objeto e um para o bloco de controle compartilhado que contém a contagem de referência.  Arquivo de cabeçalho: `<memory>`.  Para obter mais informações, consulte [Como criar e usar instâncias shared\_ptr](../cpp/how-to-create-and-use-shared-ptr-instances.md) e [Classe shared\_ptr](../standard-library/shared-ptr-class.md).  
  
-   `weak_ptr`    
    Ponteiro inteligente de casos especiais para uso em conjunto com `shared_ptr`.  Um `weak_ptr` fornece acesso a um objeto pertencente a uma ou mais instâncias de `shared_ptr`, mas não participa da contagem de referência.  Use quando você quiser observar um objeto, mas sem exigir que ele permaneça ativo.  Necessário em alguns casos para interromper referências circulares entre instâncias `shared_ptr`.  Arquivo de cabeçalho: `<memory>`.  Para obter mais informações, consulte [Como criar e usar instâncias weak\_ptr](../Topic/How%20to:%20Create%20and%20Use%20weak_ptr%20Instances.md) e [Classe weak\_ptr](../standard-library/weak-ptr-class.md).  
  
 **Ponteiros inteligentes para objetos COM \(programação clássica do Windows\)**  
 Ao trabalhar com objetos COM, coloque os ponteiros de interface em um tipo de ponteiro inteligente apropriado.  A Biblioteca de Modelos Ativos \(ATL\) define vários ponteiros inteligentes para várias finalidades.  Você também pode usar o tipo de ponteiro inteligente `_com_ptr_t`, que o compilador usa ao criar classes wrapper dos arquivos .tlb.  É a melhor opção quando você não quer incluir os arquivos de cabeçalho da ATL.  
  
 [Classe de CComPtr](../atl/reference/ccomptr-class.md)  
 Use isso a menos que você não possa usar a ATL.  Executa a contagem de referência usando os métodos `AddRef` e `Release`.  Para obter mais informações, consulte [Como criar e usar instâncias CComPtr e CComQIPtr](../Topic/How%20to:%20Create%20and%20Use%20CComPtr%20and%20CComQIPtr%20Instances.md).  
  
 [Classe de CComQIPtr](../atl/reference/ccomqiptr-class.md)  
 É semelhante a `CComPtr` mas também fornece a sintaxe simplificada para chamar `QueryInterface` em objetos COM.  Para obter mais informações, consulte [Como criar e usar instâncias CComPtr e CComQIPtr](../Topic/How%20to:%20Create%20and%20Use%20CComPtr%20and%20CComQIPtr%20Instances.md).  
  
 [Classe de CComHeapPtr](../atl/reference/ccomheapptr-class.md)  
 Ponteiro inteligente para objetos que usam `CoTaskMemFree` para liberar memória.  
  
 [Classe de CComGITPtr](../Topic/CComGITPtr%20Class.md)  
 Ponteiro inteligente para as interfaces que são obtidas da tabela de interface global \(GIT\).  
  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)  
 É semelhante a `CComQIPtr` em funcionalidade, mas não depende de cabeçalhos da ATL.  
  
 **Ponteiros inteligentes da ATL para objetos POCO**  
 Além de ponteiros inteligentes para objetos COM, a ATL também define ponteiros inteligentes e coleções de ponteiros inteligentes, para objetos C\+\+ antigos simples.  Na programação clássica do Windows, esses tipos são alternativas úteis para as coleções STL, especialmente quando a portabilidade de código não é necessária ou quando você não quer combinar os modelos de programação da STL e da ATL.  
  
 [Classe de CAutoPtr](../atl/reference/cautoptr-class.md)  
 Ponteiro inteligente que impõe a propriedade exclusiva transferindo a propriedade na cópia.  Comparável à classe `std::auto_ptr` preterida.  
  
 [Classe de CHeapPtr](../atl/reference/cheapptr-class.md)  
 Ponteiro inteligente para objetos alocados usando a função C [malloc](../c-runtime-library/reference/malloc.md).  
  
 [Classe de CAutoVectorPtr](../atl/reference/cautovectorptr-class.md)  
 Ponteiro inteligente para matrizes que são alocadas usando `new[]`.  
  
 [Classe de CAutoPtrArray](../atl/reference/cautoptrarray-class.md)  
 Classe que encapsula uma matriz de elementos `CAutoPtr`.  
  
 [Classe de CAutoPtrList](../atl/reference/cautoptrlist-class.md)  
 Classe que encapsula métodos para manipular uma lista de nós `CAutoPtr`.  
  
## Consulte também  
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)   
 [\(NOTINBUILD\)Overview: Memory Management in C\+\+](http://msdn.microsoft.com/pt-br/2201885d-3d91-4a6e-aaa6-7a554e0362a8)