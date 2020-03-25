---
title: Atributos C++ para COM e .NET
ms.custom: index-page
ms.date: 11/19/2018
ms.topic: conceptual
helpviewer_keywords:
- attributes [C++/CLI], reference topics
ms.assetid: 613a3611-b3eb-4347-aa38-99b654600e1c
ms.openlocfilehash: 734d82a30df3e143a6f47cb1b3eca2cd778830bd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214923"
---
# <a name="c-attributes-for-com-and-net"></a>Atributos C++ para COM e .NET

A Microsoft define um conjunto C++ de atributos que simplificam a programação COM e .NET Framework o desenvolvimento de Common Language Runtime. Quando você inclui atributos em seus arquivos de origem, o compilador funciona com DLLs de provedor para inserir código ou modificar o código nos arquivos de objeto gerados. Esses atributos auxiliam na criação de arquivos. idl, interfaces, bibliotecas de tipos e outros elementos COM. No ambiente de desenvolvimento integrado (IDE), os atributos são suportados pelos assistentes e pelo janela Propriedades.

Embora os atributos eliminem algumas das codificações detalhadas necessárias para gravar objetos COM, você precisa de um plano de fundo em [conceitos básicos com](/windows/win32/com/the-component-object-model) para melhor usá-los.

> [!NOTE]
> Se você estiver procurando atributos C++ padrão, consulte [atributos](../../cpp/attributes.md).

## <a name="purpose-of-attributes"></a>Finalidade de atributos

Os atributos C++ se estendem em direções que não são possíveis no momento sem quebrar a estrutura clássica do idioma. Os atributos permitem que os provedores (DLLs separadas) estendam a funcionalidade de linguagem dinamicamente. A meta principal dos atributos é simplificar a criação de componentes COM, além de aumentar o nível de produtividade do desenvolvedor de componentes. Os atributos podem ser aplicados a praticamente C++ qualquer construção, como classes, membros de dados ou funções de membro. Veja a seguir um realce dos benefícios fornecidos por essa nova tecnologia:

- Expõe uma Convenção de chamada simples e familiar.

- Usa o código inserido, que, ao contrário de macros, é reconhecido pelo depurador.

- Permite derivação fácil de classes base sem detalhes de implementação cansativos.

- Substitui a grande quantidade de código de IDL exigida por um componente com com alguns atributos concisos.

Por exemplo, para implementar um coletor de eventos simples para uma classe ATL genérica, você pode aplicar o atributo [event_receiver](event-receiver.md) a uma classe específica, como `CMyReceiver`. O atributo `event_receiver` é então compilado pelo compilador da C++ Microsoft, que insere o código adequado no arquivo de objeto.

```cpp
[event_receiver(com)]
class CMyReceiver
{
   void handler1(int i) { ... }
   void handler2(int i, float j) { ... }
}
```

Em seguida, você pode configurar os métodos de `CMyReceiver` `handler1` e `handler2` para manipular eventos (usando a função intrínseca [__hook](../../cpp/hook.md)) de uma origem de evento, que você pode criar usando [EVENT_SOURCE](event-source.md).

## <a name="basic-mechanics-of-attributes"></a>Mecânica básica de atributos

Há três maneiras de inserir atributos em seu projeto. Primeiro, você pode inseri-los manualmente em seu código-fonte. Em segundo lugar, você pode inseri-los usando a grade de propriedades de um objeto em seu projeto. Por fim, você pode inseri-los usando os vários assistentes. Para obter mais informações sobre como usar a janela **Propriedades** e os vários assistentes, consulte [projetos do C++Visual Studio- ](../../build/creating-and-managing-visual-cpp-projects.md).

Como antes, quando o projeto é compilado, o compilador analisa cada C++ arquivo de origem, produzindo um arquivo de objeto. No entanto, quando o compilador encontra um atributo, ele é analisado e verificado sintaticamente. Em seguida, o compilador chama dinamicamente um provedor de atributos para inserir código ou fazer outras modificações no momento da compilação. A implementação do provedor difere dependendo do tipo de atributo. Por exemplo, os atributos relacionados a ATL são implementados por Atlprov. dll.

A figura a seguir demonstra a relação entre o compilador e o provedor de atributos.

![Comunicação de atributo de componente](../media/vccompattrcomm.gif "Comunicação de atributo de componente")

> [!NOTE]
> O uso do atributo não altera o conteúdo do arquivo de origem. A única vez em que o código de atributo gerado é visível é durante as sessões de depuração. Além disso, para cada arquivo de origem no projeto, você pode gerar um arquivo de texto que exibe os resultados da substituição de atributo. Para obter mais informações sobre esse procedimento, consulte [/FX (mesclagem de código injetado)](../../build/reference/fx-merge-injected-code.md) e [depuração de código injetado](/visualstudio/debugger/how-to-debug-injected-code).

Como a C++ maioria das construções, os atributos têm um conjunto de características que definem seu uso adequado. Isso é chamado de contexto do atributo e é abordado na tabela de contexto de atributo para cada tópico de referência de atributo. Por exemplo, o atributo [coclass](coclass.md) só pode ser aplicado a uma classe ou estrutura existente, ao contrário do atributo [cpp_quote](cpp-quote.md) , que pode ser inserido em qualquer lugar dentro C++ de um arquivo de origem.

## <a name="building-an-attributed-program"></a>Compilando um programa atribuído

Depois de colocar atributos C++ visuais em seu código-fonte, talvez você queira que C++ o compilador da Microsoft produza uma biblioteca de tipos e um arquivo. idl para você. As opções do vinculador a seguir ajudam você a compilar arquivos. tlb e. idl:

- [/IDLOUT](../../build/reference/idlout-name-midl-output-files.md)

- [/IGNOREIDL](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)

- [/MIDL](../../build/reference/midl-specify-midl-command-line-options.md)

- [/TLBOUT](../../build/reference/tlbout-name-dot-tlb-file.md)

Alguns projetos contêm vários arquivos. idl independentes. Eles são usados para produzir dois ou mais arquivos. tlb e, opcionalmente, associá-los ao bloco de recursos. Atualmente, não há suporte para esse cenário C++no Visual.

Além disso, o vinculador Visual C++ produzirá todas as informações de atributo relacionadas a IDL para um único arquivo MIDL. Não haverá nenhuma maneira de gerar duas bibliotecas de tipos a partir de um único projeto.

## <a name="attribute-contexts"></a><a name="contexts"></a>Contextos de atributo

C++os atributos podem ser descritos usando quatro campos básicos: o destino ao qual eles podem ser aplicados (**aplica-se a**), se eles forem repetíveis ou não (**repetíveis**), a presença necessária de outros atributos (**atributos obrigatórios**) e incompatibilidade com outros atributos (**atributos inválidos**). Esses campos são listados em uma tabela que acompanha o tópico de referência de cada atributo. Cada um desses campos é descrito abaixo.

### <a name="applies-to"></a>Aplica-se A

Este campo descreve os diferentes C++ elementos de linguagem que são alvos legais para o atributo especificado. Por exemplo, se um atributo especificar "Class" no campo **aplica-se a** , isso indica que o atributo só pode ser aplicado a uma C++ classe legal. Se o atributo for aplicado a uma função de membro de uma classe, ocorrerá um erro de sintaxe.

Para obter mais informações, consulte [atributos por uso](attributes-by-usage.md).

### <a name="repeatable"></a>Repetível

Este campo informa se o atributo pode ser aplicado repetidamente ao mesmo destino. A maioria dos atributos não é repetível.

### <a name="required-attributes"></a>Atributos necessários.

Este campo lista outros atributos que precisam estar presentes (ou seja, aplicados ao mesmo destino) para que o atributo especificado funcione corretamente. Não é comum que um atributo tenha qualquer entrada para esse campo.

### <a name="invalid-attributes"></a>Atributos inválidos

Este campo lista outros atributos que são incompatíveis com o atributo especificado. Não é comum que um atributo tenha qualquer entrada para esse campo.

## <a name="in-this-section"></a>Nesta seção

[Perguntas frequentes sobre programação de atributos](attribute-programming-faq.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[Referência alfabética de atributos](attributes-alphabetical-reference.md)
