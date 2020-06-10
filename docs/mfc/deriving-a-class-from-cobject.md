---
title: Derivando uma classe de CObject
ms.date: 11/04/2016
helpviewer_keywords:
- DECLARE_DYNCREATE macro [MFC]
- DECLARE_SERIAL macro [MFC]
- macros [MFC], serialization
- serialization [MFC], macros
- DECLARE_DYNAMIC macro [MFC]
- derived classes [MFC], from CObject
- CObject class [MFC], deriving serializable classes
- CObject class [MFC], deriving from
ms.assetid: 5ea4ea41-08b5-4bd8-b247-c5de8c152a27
ms.openlocfilehash: f4c01538877d8517cf3394d9e0108ce3a9df2900
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621936"
---
# <a name="deriving-a-class-from-cobject"></a>Derivando uma classe de CObject

Este artigo descreve as etapas mínimas necessárias para derivar uma classe de [CObject](reference/cobject-class.md). Outros `CObject` artigos sobre a classe descrevem as etapas necessárias para aproveitar os `CObject` recursos específicos, como suporte à depuração de diagnóstico e serialização.

Nas discussões de `CObject` , os termos "arquivo de interface" e "arquivo de implementação" são usados com frequência. O arquivo de interface (geralmente chamado de arquivo de cabeçalho ou. Arquivo H) contém a declaração de classe e todas as outras informações necessárias para usar a classe. O arquivo de implementação (ou. Arquivo CPP) contém a definição de classe, bem como o código que implementa as funções de membro de classe. Por exemplo, para uma classe chamada `CPerson` , você normalmente criaria um arquivo de interface chamado Person. H e um arquivo de implementação chamado PERSON. CPP. No entanto, para algumas pequenas classes que não serão compartilhadas entre aplicativos, às vezes é mais fácil combinar a interface e a implementação em um único. Arquivo CPP.

Você pode escolher entre quatro níveis de funcionalidade ao derivar uma classe de `CObject` :

- Funcionalidade básica: não há suporte para informações de classe em tempo de execução ou serialização, mas inclui gerenciamento de memória de diagnóstico.

- Funcionalidade básica mais suporte para informações de classe em tempo de execução.

- Funcionalidade básica mais suporte para informações de classe em tempo de execução e criação dinâmica.

- Funcionalidade básica mais suporte para informações de classe em tempo de execução, criação dinâmica e serialização.

As classes criadas para reutilização (aquelas que servirão mais tarde como classes base) devem, pelo menos, incluir suporte à classe de tempo de execução e suporte de serialização, se qualquer necessidade de serialização futura for prevista.

Você escolhe o nível de funcionalidade usando macros de declaração e de implementação específicas na declaração e na implementação das classes das quais você deriva `CObject` .

A tabela a seguir mostra a relação entre as macros usadas para dar suporte à serialização e informações de tempo de execução.

### <a name="macros-used-for-serialization-and-run-time-information"></a>Macros usadas para serialização e informações de tempo de execução

|Macro usada|CObject::IsKindOf|CRuntimeClass::<br /><br /> CreateObject|Operador CArchive:: Operator>><br /><br /> Operador CArchive:: Operator<<|
|----------------|-----------------------|--------------------------------------|-------------------------------------------------------|
|`CObject`Funcionalidade básica|Não|Não|Não|
|`DECLARE_DYNAMIC`|Sim|Não|Não|
|`DECLARE_DYNCREATE`|Sim|Sim|Não|
|`DECLARE_SERIAL`|Sim|Sim|Sim|

#### <a name="to-use-basic-cobject-functionality"></a>Para usar a funcionalidade básica de CObject

1. Use a sintaxe C++ normal para derivar sua classe de `CObject` (ou de uma classe derivada de `CObject` ).

   O exemplo a seguir mostra o caso mais simples, a derivação de uma classe de `CObject` :

   [!code-cpp[NVC_MFCCObjectSample#1](codesnippet/cpp/deriving-a-class-from-cobject_1.h)]

Normalmente, no entanto, talvez você queira substituir algumas das `CObject` funções membro para lidar com as especificidades da sua nova classe. Por exemplo, normalmente você pode querer substituir a `Dump` função de `CObject` para fornecer saída de depuração para o conteúdo da sua classe. Para obter detalhes sobre como substituir `Dump` , consulte o artigo [objeto de depuração personalização](/previous-versions/visualstudio/visual-studio-2010/sc15kz85(v=vs.100)). Talvez você também queira substituir a `AssertValid` função do `CObject` para fornecer testes personalizados para validar a consistência dos membros de dados dos objetos de classe. Para obter uma descrição de como substituir `AssertValid` , consulte [MFC ASSERT_VALID e CObject:: AssertValid](reference/diagnostic-services.md#assert_valid).

O artigo [especificando níveis de funcionalidade](specifying-levels-of-functionality.md) descreve como especificar outros níveis de funcionalidade, incluindo informações de classe de tempo de execução, criação dinâmica de objeto e serialização.

## <a name="see-also"></a>Consulte também

[Usando CObject](using-cobject.md)
