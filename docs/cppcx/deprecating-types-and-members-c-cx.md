---
title: Reprovando tipos e membros (C++/CX)
ms.date: 12/30/2016
ms.assetid: b20b01c1-a439-4ff0-8cf3-d7280c492813
ms.openlocfilehash: 1e29f2ff73d6fb6fd499052d9f9255f8b1a659c7
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51325842"
---
# <a name="deprecating-types-and-members-ccx"></a>Reprovando tipos e membros (C++/CX)

No C + + c++ /CLI CX, substituição de membros e tipos de tempo de execução do Windows para produtores e consumidores usando o [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) atributo tem suporte. Se você consumir uma API para a qual esse atributo foi aplicado, você receberá uma mensagem de aviso de tempo de compilação indicando que a API foi substituída e recomendando também uma API alternativa para uso. Em seus próprios tipos e métodos públicos, você pode aplicar esse atributo e fornecer sua própria mensagem personalizada.

> [!CAUTION]
> O [preterido](/uwp/api/windows.foundation.metadata.deprecatedattribute) atributo é usado apenas com tipos de tempo de execução do Windows. Para classes e membros C++ padrão, use [__declspec(deprecated)](../cpp/deprecated-cpp.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como substituir suas próprias APIs públicas – por exemplo, em um componente do Tempo de Execução do Windows. O segundo parâmetro, do tipo [Windows:Foundation::Metadata::DeprecationType](/uwp/api/windows.foundation.metadata.deprecationtype) especifica se a API está sendo substituída ou removida. Há suporte somente para o valor DeprecationType::Deprecated no momento. O terceiro parâmetro no atributo especifica a [Windows::Foundation::Metadata::Platform](/uwp/api/windows.foundation.metadata.platformattribute) à qual o atributo se aplica.

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

| |
|-|
|Controle XAML|
|delegado|
|evento|
|campo enum|
|enum|
|struct|
|method|
|classe|
|interface|
|propriedade|
|campo struct|
|construtor parametrizado|

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)