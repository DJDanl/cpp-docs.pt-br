---
title: Reprovando tipos e membros (C++/CX)
ms.date: 12/30/2016
ms.assetid: b20b01c1-a439-4ff0-8cf3-d7280c492813
ms.openlocfilehash: 6d61b00690cc087c3baced6d96d0b6c8d73b5850
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040321"
---
# <a name="deprecating-types-and-members-ccx"></a>Reprovando tipos e membros (C++/CX)

No C++/CX, há suporte para a substituição de tipos de Windows Runtime e membros para produtores e consumidores usando o atributo [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) . Se você consumir uma API para a qual esse atributo foi aplicado, você receberá uma mensagem de aviso de tempo de compilação indicando que a API foi substituída e recomendando também uma API alternativa para uso. Em seus próprios tipos e métodos públicos, você pode aplicar esse atributo e fornecer sua própria mensagem personalizada.

> [!CAUTION]
> O atributo [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) é para uso somente com Windows Runtime tipos. Para classes e membros C++ padrão, use [__declspec(deprecated)](../cpp/deprecated-cpp.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como substituir suas próprias APIs públicas – por exemplo, em um componente do Windows Runtime. O segundo parâmetro, do tipo [Windows:Foundation::Metadata::DeprecationType](/uwp/api/windows.foundation.metadata.deprecationtype) especifica se a API está sendo substituída ou removida. Há suporte somente para o valor DeprecationType::Deprecated no momento. O terceiro parâmetro no atributo especifica a [Windows::Foundation::Metadata::Platform](/uwp/api/windows.foundation.metadata.platformattribute) à qual o atributo se aplica.

```

namespace wfm = Windows::Foundation::Metadata;

public ref class Bicycle sealed
{

public:
    property double Speed;

    [wfm::Deprecated("Use the Speed property to compute the angular speed of the wheel", wfm::DeprecationType::Deprecate, 0x0)]
    double ComputeAngularVelocity();
};
```

## <a name="supported-targets"></a>Destinos com suporte

A tabela a seguir lista as construções às quais o atributo Deprecated pode ser aplicado:

:::row:::
   :::column span="":::
      classes
      delegá
      enumera
      campo de enumeração \
      circunstância
      interface
   :::column-end:::
   :::column span="":::
      forma
      Construtor com parâmetros \
      propriedade\
      struct
      campo de struct \
      Controle XAML
   :::column-end:::
:::row-end:::

## <a name="see-also"></a>Confira também

[Sistema de tipo](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
