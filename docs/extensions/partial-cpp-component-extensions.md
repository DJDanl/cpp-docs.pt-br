---
title: partial (C++/CLI and C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- partial_CPP
helpviewer_keywords:
- partial
- C++/CX, partial
ms.assetid: 43adf1f5-10c5-44aa-a66f-7507e2bdabf8
ms.openlocfilehash: 37406060c3569c417c14bcc98561f8f52a7c6201
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "70311827"
---
# <a name="partial--ccli-and-ccx"></a>partial (C++/CLI and C++/CX)

A palavra-chave **partial** permite que partes diferentes da mesma classe ref sejam criadas de forma independente e em arquivos diferentes.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Esse recurso de linguagem se aplica somente ao Windows Runtime).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Para uma classe ref que tem duas definições parciais, a palavra-chave **partial** é aplicada à primeira ocorrência da definição, e isso normalmente é feito pelo código gerado automaticamente, para que um codificador humano não use a palavra-chave com muita frequência. Para todas as definições parciais subsequentes da classe, omita o modificador **parcial** da palavra-chave *class-key* e do identificador de classe. Quando o compilador encontrar uma classe ref e o identificador de classe definidos anteriormente, mas não a palavra-chave **partial**, ele combinará internamente todas as partes da definição da classe ref em uma definição.

### <a name="syntax"></a>Sintaxe

```cpp
partial class-key identifier {
   /* The first part of the partial class definition.
      This is typically auto-generated */
}
// ...
class-key identifier {
   /* The subsequent part(s) of the class definition. The same
      identifier is specified, but the "partial" keyword is omitted. */
}
```

### <a name="parameters"></a>Parâmetros

*class-key*<br/>
Uma palavra-chave que declara uma classe ou struct compatível com o Windows Runtime. **classe ref**, **classe value**, **struct ref** ou **struct value**.

*identifier*<br/>
O nome do tipo definido.

### <a name="remarks"></a>Comentários

Uma classe parcial é compatível com cenários nos quais você modifica uma parte da definição de uma classe em um arquivo, e o software de geração de código automático, por exemplo, modifica o código na mesma classe em outro arquivo. Usando uma classe parcial, você pode impedir que o gerador de código automático substitua seu código. Em um projeto do Visual Studio, o modificador **partial** é aplicado automaticamente ao arquivo gerado.

Conteúdo: Com duas exceções, uma definição de classe parcial poderá conter tudo que a definição de classe completa pode conter se a palavra-chave **partial** tiver sido omitida. No entanto, você não pode especificar a acessibilidade de classe (por exemplo, `public partial class X { ... };`) ou um **declspec**.

Os especificadores de acesso usados em uma definição de classe parcial para *identificador* não afetam a acessibilidade padrão em uma definição de classe parcial ou completa para *identificador*. As definições embutidas de membros de dados estáticos são permitidas.

Declaração: Uma definição parcial de um *identificador* de classe apresenta somente o *identificador* de nome, mas o *identificador* não pode ser usado de uma forma que exija uma definição de classe. O *identificador* do nome não pode ser usado para saber o tamanho do *identificador*, ou para usar uma base ou membro do *identificador* até que o compilador encontre a definição completa do *identificador*.

Número e ordenação: O *identificador* pode ter zero ou mais definições de classe parcial. Cada definição de classe parcial do *identificador* deve preceder lexicalmente a única definição completa do *identificador* (se houver uma definição completa; caso contrário, a classe não poderá ser usada, exceto se houver declaração de encaminhamento), mas não precisa preceder declarações de encaminhamento do *identificador*. Todas as class-keys devem corresponder.

Definição completa: No ponto da definição completa do *identifier* de classe, o comportamento será igual como se a definição de *identifier* tivesse declarado todas as classes base, membros etc. na ordem em que foram encontrados e definidos nas classes parciais.

Modelos: Uma classe parcial não pode ser um modelo.

Genéricos: Uma classe parcial pode ser genérica, se a definição completa puder ser genérica. Mas toda classe parcial e completa deve ter exatamente os mesmos parâmetros genéricos, incluindo nomes de parâmetro formais.

Saiba mais sobre como usar a palavra-chave **partial** em [Classes parciais (C++/CX)](https://go.microsoft.com/fwlink/p/?LinkId=249023).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Esse recurso de linguagem não se aplica ao Common Language Runtime.)

## <a name="see-also"></a>Consulte também

[Classes parciais (C++/CX)](https://go.microsoft.com/fwlink/p/?LinkId=249023)