---
title: parcial (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- partial_CPP
dev_langs:
- C++
helpviewer_keywords:
- partial
- C++/CX, partial
ms.assetid: 43adf1f5-10c5-44aa-a66f-7507e2bdabf8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ace57934c741d0a6e7b7ab6fbe5e482540a9bc48
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49327863"
---
# <a name="partial--ccli-and-ccx"></a>parcial (C + + c++ /CLI e c++ /CLI CX)

O **parcial** palavra-chave permite que partes diferentes da mesma classe ref a ser criado de forma independente e em arquivos diferentes.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Esse recurso de linguagem se aplica somente para o tempo de execução do Windows).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Para uma classe ref que tem duas definições parciais, o **parcial** palavra-chave é aplicada para a primeira ocorrência da definição, e isso normalmente é feito pelo código gerado automaticamente, para que um humano codificador não usa a palavra-chave com muita frequência. Para todas as definições parciais de subsequentes da classe, omita a **parcial** modificador da *chave de classe* identificador de classe e a palavra-chave. Quando o compilador encontra uma classe ref definido anteriormente e o identificador de classe, mas não **parcial** palavra-chave, ele combina todas as partes da definição de classe ref em uma definição internamente.

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

*chave de classe*<br/>
Uma palavra-chave que declara uma classe ou struct que é compatível com o tempo de execução do Windows. Qualquer um dos **classe ref**, **classe de valor**, **ref struct**, ou **valor&lt;1**.

*identifier*<br/>
O nome do tipo definido.

### <a name="remarks"></a>Comentários

Uma classe parcial oferece suporte a cenários em que você modificar uma parte de uma definição de classe em um arquivo e o software de geração de código automática — por exemplo, o designer XAML — modifica o código na mesma classe em outro arquivo. Usando uma classe parcial, você pode impedir que o gerador de código automático substituindo seu código. Em um projeto do Visual Studio, o **parcial** modificador é aplicado automaticamente ao arquivo gerado.

Conteúdo: Com duas exceções, uma definição de classe parcial pode conter qualquer coisa que a definição de classe completa pode conter se a **parcial** palavra-chave foi omitida. No entanto, você não pode especificar a acessibilidade de classe (por exemplo, `public partial class X { ... };`), ou um **declspec**.

Acessar especificadores usados em uma definição de classe parcial para *identificador* não afetam a acessibilidade padrão em uma definição subsequente de classe parcial ou completo para *identificador*. São permitidas definições embutidas de membros de dados estáticos.

Declaração: Uma definição parcial de uma classe *identificador* apresenta somente o nome *identificador*, mas *identificador* não pode ser usado de forma que requer uma classe definição. O nome *identificador* não pode ser usado para saber o tamanho da *identificador*, ou usar uma base ou membro da *identificador* até depois que o compilador encontra a definição completa do *identificador*.

Número e ordenação: pode haver zero ou mais definições de classe parcial para *identificador*. Cada definição de classe parcial da *identificador* deve preceder lexicalmente a única definição completa da *identificador* (se houver uma definição completa; caso contrário, a classe não pode ser usada, exceto como se declarados de encaminhamento), mas não precisa preceder declarações de encaminhamento da *identificador*. Todas as chaves de classe devem corresponder.

Total de definição: no ponto da definição completa da classe *identificador*, o comportamento é o mesmo como se a definição da *identificador* tivesse declarado todas as classes base, membros, etc. na ordem em que foram encontrados e definidos nas classes parciais.

Modelos: Uma classe parcial não pode ser um modelo.

Genéricos: Uma classe parcial pode ser um genérico se a definição completa pode ser genérica. Mas todas as classes parciais e completos devem ter exatamente os mesmos parâmetros genéricos, incluindo nomes de parâmetro formal.

Para obter mais informações sobre como usar o **parcial** palavra-chave, consulte [Classes parciais (C + + c++ /CLI CX)](http://go.microsoft.com/fwlink/p/?LinkId=249023).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Esse recurso de linguagem não é aplicável para o Common Language Runtime.)

## <a name="see-also"></a>Consulte também

[Classes parciais (C++ c++ /CX)](http://go.microsoft.com/fwlink/p/?LinkId=249023)