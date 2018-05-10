---
title: Partial (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 71c0fc9739e7ef8e1e68c5678ce56fcec4a250c1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="partial--c-component-extensions"></a>parcial (Extensões de Componentes C++)
O `partial` palavra-chave permite que partes diferentes da mesma classe ref a ser criado de forma independente e em arquivos diferentes.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 (Esse recurso de idioma aplica-se somente para o Windows Runtime.)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Para uma classe ref que tem duas definições parciais, o `partial` palavra-chave é aplicada para a primeira ocorrência da definição e isso geralmente é feito pelo código gerado automaticamente, para que um codificador humano com muita frequência, não usa a palavra-chave. Para todas as definições parciais de subsequentes da classe, omita o `partial` modificador do *chave de classe* identificador de classe e a palavra-chave. Quando o compilador encontra uma classe ref definidas anteriormente e identificador de classe, mas não `partial` palavra-chave, ele combina todas as partes da definição de classe ref em uma definição internamente.  
  
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
 *chave de classe*  
 Uma palavra-chave que declara uma classe ou estrutura que é compatível com o tempo de execução do Windows. O `ref class`, `value class`, `ref struct`, ou `value struct`.  
  
 *identifier*  
 O nome do tipo definido.  
  
### <a name="remarks"></a>Comentários  
 Uma classe parcial oferece suporte a cenários em que você modificar uma parte de uma definição de classe em um arquivo e o software de geração de código automática — por exemplo, o designer XAML, modifica o código na mesma classe em outro arquivo. Usando uma classe parcial, você pode impedir que o gerador de código automática substitua o seu código. Em um projeto do Visual Studio, o modificador de `partial` é aplicado automaticamente ao arquivo gerado.  
  
 Conteúdo: Com duas exceções, uma definição de classe parcial poderá conter tudo que a definição de classe completa pode conter se a `partial` palavra-chave foi omitida. No entanto, você não pode especificar a acessibilidade de classe (por exemplo, `public partial class X { ... };`), ou um `declspec`.  
  
 Acessar especificadores usados em uma definição de classe parcial para *identificador* não afetam a acessibilidade padrão em uma definição de classe parcial ou completo para *identificador*. Definições embutidas de membros de dados estáticos são permitidas.  
  
 Declaração: Uma definição parcial de uma classe *identificador* apresenta somente o nome *identificador*, mas *identificador* não pode ser usado de forma que requer uma classe definição. O nome *identificador* não pode ser usado para saber o tamanho de *identificador*, ou usar uma base ou membro de *identificador* até depois que o compilador encontra a definição completa do *identificador*.  
  
 Número e ordenação: pode haver zero ou mais definições de classe parcial para *identificador*. Cada definição de classe parcial de *identificador* deve preceder lexicalmente a única definição completa de *identificador* (se houver uma definição completa; caso contrário, a classe não pode ser usada exceto como se avanço declarado), mas não é necessário preceder declarações de encaminhamento de *identificador*. Todas as chaves de classe devem corresponder.  
  
 Total de definição: no ponto da definição completa da classe *identificador*, o comportamento é o mesmo como se a definição de *identificador* tivesse declarado todas as classes base, membros, etc. na ordem em que foram encontrados e definidos nas classes parciais.  
  
 Modelos: Uma classe parcial não pode ser um modelo.  
  
 Genéricos: Uma classe parcial poderá ser um genérico se a definição completa pode ser genérica. Mas todas as classes parciais e completas devem ter exatamente os mesmos parâmetros genéricos, incluindo nomes de parâmetro formal.  
  
 Para obter mais informações sobre como usar o `partial` palavra-chave, consulte [Classes parciais (C + + CX)](http://go.microsoft.com/fwlink/p/?LinkId=249023).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 (Esse recurso de idioma não é aplicável para o Common Language Runtime.)  
  
## <a name="see-also"></a>Consulte também  
 [Classes parciais (C + + CX)](http://go.microsoft.com/fwlink/p/?LinkId=249023)