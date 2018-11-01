---
title: Atributos de C++ para COM e .NET
ms.custom: index-page
ms.date: 10/02/2018
ms.topic: conceptual
helpviewer_keywords:
- attributes [C++/CLI], reference topics
ms.assetid: 613a3611-b3eb-4347-aa38-99b654600e1c
ms.openlocfilehash: bacfd4cb78c5bf65422fb4472a4563776041a87b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589274"
---
# <a name="c-attributes-for-com-and-net"></a>Atributos de C++ para COM e .NET

A Microsoft define um conjunto de atributos de C++ que simplificam o desenvolvimento de tempo de execução de linguagem comum do .NET Framework e de programação COM. Quando você inclui atributos nos arquivos de origem, o compilador trabalha com o provedor de DLLs para inserir código ou modificar o código nos arquivos de objeto gerado. Esses atributos ajudam na criação de arquivos. idl, interfaces, bibliotecas de tipos e outros elementos de COM. No ambiente de desenvolvimento integrado (IDE), os atributos têm suporte dos assistentes e pela janela de propriedades.

Embora atributos eliminam alguns da codificação detalhada necessária para escrever objetos COM, você precisa em um plano de fundo [COM fundamentals](/windows/desktop/com/the-component-object-model) usá-los melhor.

> [!NOTE]
> Se você estiver procurando por atributos padrão do C++, consulte [atributos](../../cpp/attributes.md).

## <a name="purpose-of-attributes"></a>Finalidade de atributos

Atributos de estendem o C++ em direções no momento, não é possíveis sem quebrar a estrutura clássica do idioma. Atributos permitem que provedores (DLLs separadas) para estender a funcionalidade de idioma dinamicamente. O objetivo principal de atributos é simplificar a criação de componentes COM, além de aumentar o nível de produtividade do desenvolvedor de componentes. Atributos podem ser aplicados a praticamente qualquer constructo de C++, como classes, membros de dados ou funções de membro. Este é um realce de benefícios fornecidos por essa nova tecnologia:

- Expõe uma convenção de chamada simple e familiar.

- Usa inserido código, que, ao contrário de macros, é reconhecido pelo depurador.

- Permite a fácil derivação das classes base sem os detalhes de implementação cansativo.

- Substitui a grande quantidade de código IDL necessária para um componente com alguns atributos concisos.

Por exemplo, para implementar um coletor de eventos simples para uma classe genérica do ATL, você pode aplicar a [event_receiver](event-receiver.md) atributo em uma classe específica como `CMyReceiver`. O `event_receiver` atributo, em seguida, é compilado pelo compilador Visual C++, que insere o código apropriado no arquivo de objeto.

```cpp
[event_receiver(com)]
class CMyReceiver
{
   void handler1(int i) { ... }
   void handler2(int i, float j) { ... }
}
```

Você pode configurar o `CMyReceiver` métodos `handler1` e `handler2` para manipular eventos (usando a função intrínseca [hook](../../cpp/hook.md)) de uma fonte de evento, você pode criar usando [event_source](event-source.md).

## <a name="basic-mechanics-of-attributes"></a>Mecânica básica de atributos

Há três maneiras para inserir atributos no seu projeto. Primeiro, você pode inseri-los manualmente no seu código-fonte. Em segundo lugar, você pode inseri-los usando a grade de propriedade de um objeto em seu projeto. Por fim, você pode inseri-los usando vários assistentes. Para obter mais informações sobre como usar o **propriedades** janela e vários assistentes, consulte [criando e gerenciando projetos do Visual C++](../../ide/creating-and-managing-visual-cpp-projects.md).

Como antes, quando o projeto é compilado, o compilador analisa cada arquivo de origem C++, produzir um arquivo de objeto. No entanto, quando o compilador encontra um atributo, ele é analisado e sintaticamente verificado. O compilador chama dinamicamente um provedor de atributo para inserir código ou fazer outras modificações em tempo de compilação. A implementação do provedor é diferente dependendo do tipo de atributo. Por exemplo, os atributos relacionados à ATL são implementados por Atlprov.dll.

A figura a seguir demonstra a relação entre o compilador e o provedor de atributo.

![Comunicação de atributos do componente](../media/vccompattrcomm.gif "vcCompAttrComm")

> [!NOTE]
> Uso do atributo não altera o conteúdo do arquivo de origem. É a única vez em que o código gerado do atributo é visível durante as sessões de depuração. Além disso, para cada arquivo de origem no projeto, você pode gerar um arquivo de texto que exibe os resultados da substituição de atributo. Para obter mais informações sobre esse procedimento, consulte [/Fx (mesclar código injetado)](../../build/reference/fx-merge-injected-code.md) e [depurando código injetado](/visualstudio/debugger/how-to-debug-injected-code).

Como a maioria das construções de C++, os atributos têm um conjunto de características que define seu uso adequado. Isso é conhecido como o contexto do atributo e é abordado na tabela de contexto de atributo para cada tópico de referência de atributo. Por exemplo, o [coclass](coclass.md) atributo só pode ser aplicado a uma classe existente ou estrutura, em vez de [cpp_quote](cpp-quote.md) atributo, que pode ser inserido em qualquer lugar dentro de um arquivo de origem do C++.

## <a name="building-an-attributed-program"></a>Compilando um programa atribuído

Depois de você colocar atributos do Visual C++ em seu código-fonte, convém fazer com que o compilador do Visual C++ para produzir um arquivo de biblioteca e. IDL do tipo para você. As seguinte opções de vinculador ajudam você a criar arquivos. tlb e. idl:

- [/IDLOUT](../../build/reference/idlout-name-midl-output-files.md)

- [/IGNOREIDL](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)

- [/ MIDL](../../build/reference/midl-specify-midl-command-line-options.md)

- [/TLBOUT](../../build/reference/tlbout-name-dot-tlb-file.md)

Alguns projetos contêm vários arquivos. idl independentes. Eles são usados para produzir dois ou mais arquivos. tlb e, opcionalmente, associá-las no bloco de recurso. Esse cenário não é suportado no Visual C++.

Além disso, o vinculador do Visual C++ produzirá todas as informações de atributo relacionados de IDL para um único arquivo MIDL. Não haverá nenhuma maneira de gerar duas bibliotecas de tipo de um único projeto.

## <a name="contexts"></a> Contextos de atributo

Atributos de C++ podem ser descritos usando quatro campos básicos: o destino podem ser aplicadas a (**aplica-se a**), se eles são repetidos ou não (**Repeatable**), o necessário a presença de outros atributos ( **Atributos necessários**) e incompatibilidades com outros atributos (**atributos inválidos**). Esses campos são listados em uma tabela que acompanha este artigo no tópico de referência do cada atributo. Cada um desses campos é descrita abaixo.

### <a name="applies-to"></a>Aplica-se a

Esse campo descreve os diferentes elementos de linguagem C++ que são destinos válidos para o atributo especificado. Por exemplo, se um atributo especifica "class" no **aplica-se a** campo, isso indica que o atributo só pode ser aplicado a uma classe C++ legal. Se o atributo é aplicado a uma função de membro de uma classe, isso resultaria em um erro de sintaxe.

Para obter mais informações, consulte [atributos por uso](attributes-by-usage.md).

### <a name="repeatable"></a>Repetível

Este campo indica se o atributo pode ser aplicado várias vezes para o mesmo destino. A maioria dos atributos não são repetidas.

### <a name="required-attributes"></a>Atributos obrigatórios

Esse campo lista outros atributos que precisam estar presentes (ou seja, aplicada para o mesmo destino) para o atributo especificado funcionar corretamente. É incomum para um atributo ter todas as entradas para esse campo.

### <a name="invalid-attributes"></a>Atributos inválidos

Esse campo lista outros atributos que são incompatíveis com o atributo especificado. É incomum para um atributo ter todas as entradas para esse campo.

## <a name="in-this-section"></a>Nesta seção

[Perguntas frequentes sobre programação de atributos](attribute-programming-faq.md)<br/>
[Atributos por grupo](attributes-by-group.md)<br/>
[Atributos por uso](attributes-by-usage.md)<br/>
[Referência alfabética de atributos](attributes-alphabetical-reference.md)